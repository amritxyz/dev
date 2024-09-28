# Note: you have to add this script to your bashrc/zshrc therwise it is useless

go() {
    if [ -z "$1" ]; then
        echo "Usage: findcd <folder_name>"
        return 1
    fi

    folder=$(find ~/.local/ -type d -name "$1" 2>/dev/null | head -n 1)

    if [ -n "$folder" ]; then
        echo "Changing directory to: $folder"
        cd "$folder" || return
    else
        echo "Folder not found."
    fi
}
