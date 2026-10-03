#!/usr/bin/env bash
#
# pass-setup.sh - set up GPG + pass from scratch.
#
#   * configures gpg-agent with pinentry-curses
#   * creates a new GPG key OR imports an existing private key OR reuses a key
#   * runs `pass init <fingerprint>`
#   * collects passwords via a temporary file (in RAM when possible), stores each
#     in `pass`, then securely wipes every temporary file
#   * optionally hardens a dotfiles repo (.gitignore + pre-commit hook) so that
#     passwords and private keys can never be committed
#   * optionally installs a fuzzel/Wayland integration:
#       - pinentry-fuzzel  (graphical passphrase prompt for gpg-agent)
#       - pass-type        (fuzzel launcher that types a password with wtype,
#                           restarting gpg-agent if it was killed)
#   * `--change-passphrase` changes your private key's passphrase
#
# This script itself contains no secrets and is safe to keep in your dotfiles.

set -euo pipefail
umask 077

# ----------------------------------------------------------------------------
# Config
# ----------------------------------------------------------------------------
export GNUPGHOME="${GNUPGHOME:-$HOME/.config/gnupg}"
STORE_DIR="${PASSWORD_STORE_DIR:-$HOME/.password-store}"
DOTFILES_DIR=""
OVERWRITE=0
FUZZEL="ask"            # ask | yes | no
BIN_DIR="$HOME/.local/bin"
CHANGE_PASS=0
WORK_DIR=""

usage() {
    cat <<EOF
Usage: ${0##*/} [options]

Options:
  --dotfiles DIR   Harden the git repo at DIR (.gitignore + pre-commit hook)
                   so secrets/keys/password-store can't be committed.
  --overwrite      Overwrite existing pass entries (default: skip them).
  --fuzzel         Install pinentry-fuzzel + pass-type launcher and use fuzzel
                   as gpg-agent's pinentry (Wayland). Default: ask if fuzzel exists.
  --no-fuzzel      Skip the fuzzel integration.
  --bin-dir DIR    Where to install pinentry-fuzzel and pass-type
                   (default: ~/.local/bin).
  --change-passphrase
                   Only change the passphrase of a private key, then exit.
  -h, --help       Show this help.

Password entry format (one per line, '#' lines are comments):
  email my_email_password
  github my_github_password
  codeberg my_codeberg_password
The first word is the entry name, the rest of the line is the password.

GNUPGHOME in use: $GNUPGHOME
EOF
}

while (($#)); do
    case "$1" in
        --dotfiles) DOTFILES_DIR="${2:-}"; [[ -n "$DOTFILES_DIR" ]] || { usage; exit 1; }; shift 2 ;;
        --overwrite) OVERWRITE=1; shift ;;
        --fuzzel) FUZZEL="yes"; shift ;;
        --no-fuzzel) FUZZEL="no"; shift ;;
        --bin-dir) BIN_DIR="${2:-}"; [[ -n "$BIN_DIR" ]] || { usage; exit 1; }; shift 2 ;;
        --change-passphrase) CHANGE_PASS=1; shift ;;
        -h | --help) usage; exit 0 ;;
        *) echo "Unknown option: $1" >&2; usage; exit 1 ;;
    esac
done

# ----------------------------------------------------------------------------
# Helpers
# ----------------------------------------------------------------------------
die() { echo "Error: $*" >&2; exit 1; }
info() { printf '\n==> %s\n' "$*"; }
ask_yn() { local a; read -rp "$1 [y/N] " a || true; [[ "${a:-}" =~ ^[Yy] ]]; }

# Overwrite then unlink a file.
secure_rm() {
    local f size
    for f in "$@"; do
        [[ -f "$f" ]] || continue
        if command -v shred >/dev/null 2>&1; then
            shred -u -n 3 -z -- "$f" 2>/dev/null || rm -f -- "$f"
        else
            size=$(wc -c <"$f" 2>/dev/null || echo 0)
            if ((size > 0)); then
                dd if=/dev/urandom of="$f" bs="$size" count=1 conv=notrunc status=none 2>/dev/null || true
            fi
            rm -f -- "$f"
        fi
    done
}

# Wipe every file in the private work dir (incl. editor swap/backup files).
wipe_workdir() {
    [[ -n "$WORK_DIR" && -d "$WORK_DIR" ]] || return 0
    local f
    while IFS= read -r -d '' f; do
        secure_rm "$f"
    done < <(find "$WORK_DIR" -type f -print0 2>/dev/null)
    rm -rf -- "$WORK_DIR"
    WORK_DIR=""
}

cleanup() {
    set +e
    wipe_workdir
}
trap cleanup EXIT
trap 'echo; echo "Interrupted."; exit 130' INT TERM HUP

make_workdir() {
    local base
    for base in /dev/shm "${XDG_RUNTIME_DIR:-}" "${TMPDIR:-/tmp}"; do
        if [[ -n "$base" && -d "$base" && -w "$base" ]]; then
            WORK_DIR="$(mktemp -d "$base/pass-setup.XXXXXX")"
            case "$base" in
                /dev/shm | /run/user/*) ;;
                *) echo "Warning: temp dir is not RAM-backed ($base); files will be shredded, but this is weaker on SSD/CoW filesystems." >&2 ;;
            esac
            return 0
        fi
    done
    die "could not create a temporary directory"
}

# Print primary-key fingerprints of all secret keys, one per line.
list_fprs() {
    gpg --batch --with-colons --list-secret-keys 2>/dev/null |
        awk -F: '$1=="sec"{s=1;next} s&&$1=="fpr"{print $10;s=0}' || true
}

# Does this key have a usable (non-expired/revoked) encryption-capable key?
can_encrypt() {
    gpg --batch --with-colons --list-keys "$1" 2>/dev/null |
        awk -F: '($1=="pub"||$1=="sub") && $2!="e" && $2!="r" && $2!="i" && $2!="d" && $12 ~ /[eE]/ {f=1} END{exit !f}'
}

# ----------------------------------------------------------------------------
# Steps
# ----------------------------------------------------------------------------
check_deps() {
    local m=()
    command -v gpg >/dev/null 2>&1 || m+=("gnupg")
    command -v gpgconf >/dev/null 2>&1 || m+=("gnupg")
    command -v pass >/dev/null 2>&1 || m+=("pass")
    PINENTRY="$(command -v pinentry-curses || true)"
    [[ -n "$PINENTRY" ]] || m+=("pinentry-curses")
    if ((${#m[@]})); then
        echo "Missing: $(printf '%s\n' "${m[@]}" | sort -u | tr '\n' ' ')" >&2
        echo "Install e.g.:  Debian/Ubuntu: sudo apt install gnupg pass pinentry-curses" >&2
        echo "               Arch:          sudo pacman -S gnupg pass pinentry" >&2
        echo "               Fedora:        sudo dnf install gnupg2 pass pinentry" >&2
        exit 1
    fi
}

setup_agent() {
    info "Configuring gpg-agent (GNUPGHOME=$GNUPGHOME)"
    mkdir -p "$GNUPGHOME"
    chmod 700 "$GNUPGHOME"

    local conf="$GNUPGHOME/gpg-agent.conf" new
    new="pinentry-program $PINENTRY
enable-ssh-support

max-cache-ttl 3600
default-cache-ttl 3600
max-cache-ttl-ssh 3600
default-cache-ttl-ssh 3600
"
    if [[ -f "$conf" ]] && [[ "$(<"$conf")" != "${new%$'\n'}" ]]; then
        cp -p "$conf" "$conf.bak.$(date +%s)"
        echo "Existing gpg-agent.conf backed up."
    fi
    printf '%s' "$new" >"$conf"
    chmod 600 "$conf"

    if tty -s; then
        GPG_TTY="$(tty)"
        export GPG_TTY
    fi

    gpgconf --kill gpg-agent || true
    gpgconf --launch gpg-agent
    gpg-connect-agent updatestartuptty /bye >/dev/null 2>&1 || true
}

create_key() {
    local name email expiry uid before after
    read -rp "Real name: " name
    read -rp "Email: " email
    read -rp "Expiry (e.g. 2y, 0 = never) [2y]: " expiry
    expiry="${expiry:-2y}"
    [[ -n "$name" && -n "$email" ]] || die "name and email are required"
    uid="$name <$email>"

    before="$(list_fprs)"
    info "Generating key (you will be asked for a passphrase via pinentry)"
    gpg --quick-generate-key "$uid" default default "$expiry"
    after="$(list_fprs)"
    NEW_FPRS="$(comm -13 <(sort <<<"$before") <(sort <<<"$after") | grep -v '^$' || true)"
}

import_key() {
    local path before after
    read -rep "Path to private key file: " path
    path="${path/#\~/$HOME}"
    [[ -f "$path" ]] || die "private key not found: $path"

    before="$(list_fprs)"
    info "Importing key (you may be asked for its passphrase)"
    gpg --import "$path"
    after="$(list_fprs)"
    NEW_FPRS="$(comm -13 <(sort <<<"$before") <(sort <<<"$after") | grep -v '^$' || true)"

    if ask_yn "Securely delete the key file '$path' now?"; then
        secure_rm "$path"
        echo "Deleted."
    fi
}

select_key() {
    local fprs=() i choice
    mapfile -t fprs < <(list_fprs)
    ((${#fprs[@]})) || die "no secret keys found in $GNUPGHOME"

    if ((${#fprs[@]} == 1)); then
        KEY_FPR="${fprs[0]}"
        return
    fi

    echo
    for i in "${!fprs[@]}"; do
        echo "[$((i + 1))]"
        gpg --list-secret-keys --keyid-format LONG "${fprs[$i]}" | sed 's/^/    /'
    done
    read -rp "Select key number: " choice
    [[ "$choice" =~ ^[0-9]+$ ]] && ((choice >= 1 && choice <= ${#fprs[@]})) || die "invalid selection"
    KEY_FPR="${fprs[$((choice - 1))]}"
}

choose_key() {
    echo "How do you want to get your GPG key?"
    echo "  1) Create a new key"
    echo "  2) Import an existing private key file"
    echo "  3) Use a key already in my keyring"
    local c
    read -rp "Choice [1-3]: " c
    NEW_FPRS=""
    case "$c" in
        1) create_key ;;
        2) import_key ;;
        3) ;;
        *) die "invalid choice" ;;
    esac

    # Auto-detect: if exactly one new key appeared, use it; otherwise pick.
    if [[ -n "$NEW_FPRS" && "$(wc -l <<<"$NEW_FPRS")" -eq 1 ]]; then
        KEY_FPR="$NEW_FPRS"
    else
        select_key
    fi

    can_encrypt "$KEY_FPR" || die "key $KEY_FPR has no usable encryption subkey (expired/revoked/sign-only?)"

    # Imported keys are not trusted by default; pass/gpg would then refuse or prompt.
    printf '%s:6:\n' "$KEY_FPR" | gpg --batch --import-ownertrust >/dev/null 2>&1

    info "Using key"
    gpg --list-secret-keys --keyid-format LONG "$KEY_FPR"
}

backup_key() {
    ask_yn "Export a passphrase-protected backup of the private key (to store OFFLINE)?" || return 0
    local out
    read -rep "Backup path [$HOME/gpg-backup-${KEY_FPR: -16}.asc]: " out
    out="${out:-$HOME/gpg-backup-${KEY_FPR: -16}.asc}"
    out="${out/#\~/$HOME}"
    [[ ! -e "$out" ]] || die "refusing to overwrite $out"
    gpg --export-secret-keys --armor "$KEY_FPR" >"$out"
    chmod 600 "$out"
    echo "Written to $out (still protected by your key passphrase)."
    echo "Move it to offline storage and do NOT put it in your dotfiles."
    BACKUP_FILE="$out"
}

init_pass() {
    info "Initializing password store ($STORE_DIR)"
    if [[ -f "$STORE_DIR/.gpg-id" ]]; then
        local cur
        cur="$(<"$STORE_DIR/.gpg-id")"
        if [[ "$cur" == "$KEY_FPR" ]]; then
            echo "Store already initialized with this key."
            return
        fi
        echo "Store already uses a different key: $cur"
        ask_yn "Re-encrypt the store to $KEY_FPR? (needs the old key to decrypt)" || die "aborted"
    fi
    pass init "$KEY_FPR"
}

collect_and_store() {
    info "Collecting passwords"
    make_workdir
    local file="$WORK_DIR/passwords.txt"
    cat >"$file" <<'EOF'
# One entry per line:  <name> <password>
# Lines starting with '#' and blank lines are ignored.
# Names may include folders, e.g.  web/github
#
# email my_email_password
# github my_github_password
# codeberg my_codeberg_password

EOF

    local ed="${VISUAL:-${EDITOR:-}}" cmd=() base extra=()
    if [[ -z "$ed" ]]; then
        for ed in nano vim vi; do command -v "$ed" >/dev/null 2>&1 && break || ed=""; done
    fi
    [[ -n "$ed" ]] || die "no editor found; set \$EDITOR"
    read -ra cmd <<<"$ed"
    base="${cmd[0]##*/}"
    case "$base" in
        vi | vim | nvim) extra=(-n -i NONE -c 'set nobackup nowritebackup noundofile viminfo=') ;;
    esac

    echo "Opening ${cmd[0]} - enter passwords, save and quit."
    "${cmd[@]}" ${extra[@]+"${extra[@]}"} "$file"

    local line name pw stored=0 skipped=0
    while IFS= read -r -u 3 line || [[ -n "$line" ]]; do
        line="${line%$'\r'}"
        line="${line#"${line%%[![:space:]]*}"}"
        [[ -z "$line" || "$line" == \#* ]] && continue

        name="${line%%[[:space:]]*}"
        pw="${line#"$name"}"
        pw="${pw#"${pw%%[![:space:]]*}"}"

        if [[ -z "$pw" ]]; then
            echo "  !! skipping '$name': no password given"
            skipped=$((skipped + 1))
            continue
        fi
        if [[ "$name" == /* || "$name" == *..* ]]; then
            echo "  !! skipping '$name': invalid entry name"
            skipped=$((skipped + 1))
            continue
        fi
        if [[ -e "$STORE_DIR/$name.gpg" && $OVERWRITE -eq 0 ]]; then
            echo "  -- '$name' already exists (use --overwrite to replace)"
            skipped=$((skipped + 1))
            continue
        fi

        printf '%s\n' "$pw" | pass insert -m -f "$name" >/dev/null
        echo "  -> $name"
        stored=$((stored + 1))
    done 3<"$file"
    unset pw line

    # Wipe immediately; don't wait for exit.
    wipe_workdir
    echo "Stored: $stored   Skipped: $skipped   (temporary files securely wiped)"
}

change_passphrase() {
    command -v gpg >/dev/null 2>&1 || die "gpg not found"
    if tty -s; then GPG_TTY="$(tty)"; export GPG_TTY; fi
    select_key
    info "Changing passphrase for $KEY_FPR (old passphrase first, then the new one twice)"
    gpg --change-passphrase "$KEY_FPR"
    gpgconf --kill gpg-agent || true
    echo "Done. Your pass store does NOT need re-encrypting."
    echo "Old key backups still use the OLD passphrase - re-export them."
}

# Write a file (mode 755) and back up a different existing version.
install_script() {
    local dest="$1" content="$2"
    if [[ -f "$dest" && "$(<"$dest")" != "${content%$'\n'}" ]]; then
        cp -p "$dest" "$dest.bak.$(date +%s)"
        echo "Existing $(basename "$dest") backed up."
    fi
    printf '%s' "$content" >"$dest"
    chmod 755 "$dest"
}

install_fuzzel_integration() {
    case "$FUZZEL" in
        no) return 0 ;;
        ask)
            command -v fuzzel >/dev/null 2>&1 || return 0
            ask_yn "Install fuzzel integration (graphical pinentry + pass-type launcher)?" || return 0
            ;;
        yes)
            command -v fuzzel >/dev/null 2>&1 || echo "Warning: fuzzel is not installed yet; install it (and wtype) before using these." >&2
            ;;
    esac
    command -v wtype >/dev/null 2>&1 || echo "Warning: wtype not found; pass-type needs it to type passwords." >&2

    info "Installing fuzzel integration into $BIN_DIR"
    BIN_DIR="${BIN_DIR/#\~/$HOME}"
    mkdir -p "$BIN_DIR"

    local pin_script launcher
    pin_script=$(cat <<'PINENTRY_EOF'
#!/bin/bash
# pinentry using fuzzel (based on pinentry-dmenu)
# Protocol: https://gorbe.io/posts/gnupg/pinentry/documentation/

export XDG_RUNTIME_DIR="${XDG_RUNTIME_DIR:-/run/user/$(id -u)}"
if [ -z "$WAYLAND_DISPLAY" ]; then
    # fall back to the first wayland socket found
    sock=$(ls "$XDG_RUNTIME_DIR"/wayland-* 2>/dev/null | grep -v '\.lock$' | head -n1)
    export WAYLAND_DISPLAY="${sock##*/}"
fi

echo 'OK Pleased to meet you'
KEYNAME=""
while IFS= read -r line; do
    case $line in
        BYE*) echo OK; break ;;
        SETDESC*)
            KEYNAME=${line#*:%0A%22}
            KEYNAME=${KEYNAME%\%22\%0A*}
            echo OK ;;
        GETPIN*)
            PASS_INPUT=$(fuzzel --dmenu --password --prompt-only "GPG ${KEYNAME}: ")
            if [ $? -ne 0 ] || [ -z "$PASS_INPUT" ]; then
                echo "ERR 83886179 Operation cancelled"
            else
                PASS_INPUT=${PASS_INPUT//%/%25}   # protocol escaping
                echo "D ${PASS_INPUT}"
                echo "OK"
            fi
            unset PASS_INPUT ;;
        *) echo OK ;;
    esac
done
PINENTRY_EOF
)
    launcher=$(cat <<'LAUNCHER_EOF'
#!/bin/sh
# pass-type: pick a pass entry with fuzzel and type its first line with wtype.
# Starts gpg-agent if it was killed; notifies on failure.

export GNUPGHOME="${GNUPGHOME:-$HOME/.config/gnupg}"
STORE="${PASSWORD_STORE_DIR:-$HOME/.password-store}"

notify() {
    command -v notify-send >/dev/null 2>&1 && notify-send -u critical "pass-type" "$1"
}

# Freeze screen (if wl-present is running) and always unfreeze on exit
frozen=0
if pgrep -x wl-present >/dev/null; then
    wl-present freeze
    frozen=1
fi
unfreeze() {
    [ "$frozen" = 1 ] && wl-present unfreeze
    frozen=0
}
trap unfreeze EXIT

# Make sure gpg-agent is running; start it if it isn't
if ! gpg-connect-agent --no-autostart /bye >/dev/null 2>&1; then
    gpgconf --launch gpg-agent
    i=0
    while [ $i -lt 20 ]; do
        gpg-connect-agent --no-autostart /bye >/dev/null 2>&1 && break
        sleep 0.1
        i=$((i + 1))
    done
    if ! gpg-connect-agent --no-autostart /bye >/dev/null 2>&1; then
        notify "Could not start gpg-agent"
        exit 1
    fi
fi

[ -d "$STORE" ] || { notify "Password store not found: $STORE"; exit 1; }

name=$(find "$STORE" -name '*.gpg' -type f \
    | sed "s|^$STORE/||; s|\.gpg\$||" | sort \
    | fuzzel -w 50% -l 10 --no-mouse --dmenu --match-mode=exact --no-sort)

[ -n "$name" ] || exit 0

# Unfreeze before decrypting so the passphrase prompt isn't stuck behind a frozen screen
unfreeze

# Decrypt (the agent prompts via pinentry-fuzzel if the passphrase isn't cached)
if ! out=$(pass show "$name" 2>/dev/null); then
    notify "Could not decrypt '$name' (wrong or cancelled passphrase?)"
    exit 1
fi

# printf is a shell builtin, so the password never appears in a process's arguments
printf '%s\n' "$out" | head -n1 | tr -d '\n' | wtype -
unset out
LAUNCHER_EOF
)
    install_script "$BIN_DIR/pinentry-fuzzel" "$pin_script"
    install_script "$BIN_DIR/pass-type" "$launcher"
    echo "Installed: $BIN_DIR/pinentry-fuzzel"
    echo "Installed: $BIN_DIR/pass-type"

    # Switch gpg-agent from pinentry-curses to pinentry-fuzzel
    local conf="$GNUPGHOME/gpg-agent.conf"
    sed -i "s|^pinentry-program.*|pinentry-program $BIN_DIR/pinentry-fuzzel|" "$conf"
    gpgconf --kill gpg-agent || true
    gpgconf --launch gpg-agent
    echo "gpg-agent now uses pinentry-fuzzel."

    case ":$PATH:" in
        *":$BIN_DIR:"*) ;;
        *) echo "Note: $BIN_DIR is not in your PATH; add it, or bind pass-type by full path." ;;
    esac
    FUZZEL_DONE=1
}

harden_dotfiles() {
    [[ -n "$DOTFILES_DIR" ]] || return 0
    info "Hardening dotfiles repo: $DOTFILES_DIR"
    DOTFILES_DIR="${DOTFILES_DIR/#\~/$HOME}"
    [[ -d "$DOTFILES_DIR" ]] || die "not a directory: $DOTFILES_DIR"

    local gi="$DOTFILES_DIR/.gitignore" pat
    touch "$gi"
    local patterns=(
        '# --- secrets: added by pass-setup.sh ---'
        '.password-store/'
        'password-store/'
        'private-keys-v1.d/'
        'secring.gpg'
        'trustdb.gpg'
        'random_seed'
        '*.key'
        '*.pem'
        '*secret*.asc'
        '*private*.asc'
        'gpg-backup-*.asc'
        'passwords.txt'
        'passwords.tmp'
    )
    for pat in "${patterns[@]}"; do
        grep -qxF -- "$pat" "$gi" || printf '%s\n' "$pat" >>"$gi"
    done
    echo ".gitignore updated."

    if [[ -d "$DOTFILES_DIR/.git" ]]; then
        local hook="$DOTFILES_DIR/.git/hooks/pre-commit"
        if [[ -e "$hook" ]]; then
            echo "A pre-commit hook already exists; not touching it."
        else
            cat >"$hook" <<'HOOK'
#!/usr/bin/env bash
# Blocks commits containing private keys or password-store data.
if git diff --cached --name-only | grep -Eq '(^|/)(\.password-store|password-store|private-keys-v1\.d)(/|$)'; then
    echo "pre-commit: refusing to commit password-store / GPG private key data." >&2
    exit 1
fi
if git diff --cached -U0 | grep -Eq -- '-----BEGIN (PGP (PRIVATE|SECRET) KEY BLOCK|(RSA |EC |OPENSSH |DSA )?PRIVATE KEY)-----'; then
    echo "pre-commit: staged changes contain a private key block. Aborting." >&2
    exit 1
fi
exit 0
HOOK
            chmod +x "$hook"
            echo "Installed pre-commit hook."
        fi
    else
        echo "No .git directory found; only .gitignore was updated."
    fi
}

# ----------------------------------------------------------------------------
# Main
# ----------------------------------------------------------------------------
[[ -t 0 && -t 1 ]] || die "run this script from an interactive terminal"

BACKUP_FILE=""
KEY_FPR=""
NEW_FPRS=""
FUZZEL_DONE=0

if ((CHANGE_PASS)); then
    change_passphrase
    exit 0
fi

check_deps
setup_agent
choose_key
backup_key
init_pass
collect_and_store
install_fuzzel_integration
harden_dotfiles

info "Password store"
pass

cat <<EOF

Done.

Add these to your shell rc (they're not secret, fine for dotfiles):
  export GNUPGHOME="$GNUPGHOME"
  export GPG_TTY=\$(tty)
  export SSH_AUTH_SOCK="\$(gpgconf --list-dirs agent-ssh-socket)"   # gpg-agent SSH support

Use it:  pass show email   |   pass -c github   |   pass insert name
EOF

if ((FUZZEL_DONE)); then
    cat <<EOF

Fuzzel launcher: bind a key to  $BIN_DIR/pass-type  in your compositor config.
If no passphrase prompt appears from a keybinding, export your session env:
  dbus-update-activation-environment --systemd WAYLAND_DISPLAY XDG_RUNTIME_DIR
EOF
fi
