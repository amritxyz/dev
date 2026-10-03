#!/bin/sh

export GNUPGHOME="${GNUPGHOME:-$HOME/.config/gnupg}"
STORE="${PASSWORD_STORE_DIR:-$HOME/.password-store}"

notify() {
    command -v notify-send >/dev/null 2>&1 && notify-send -u critical "pass-type" "$1"
}

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

unfreeze

if ! out=$(pass show "$name" 2>/dev/null); then
    notify "Could not decrypt '$name'"
    exit 1
fi

printf '%s\n' "$out" | head -n1 | tr -d '\n' | wtype -
unset out
