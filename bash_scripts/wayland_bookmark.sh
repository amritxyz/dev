#!/bin/bash

# sudo pacman wofi xclip

# Path to your bookmarks file
BOOKMARK_FILE="$HOME/.local/share/snippets"

# Read bookmarks, exclude comments, and present them in wofi
URL=$(grep -v '^#' "$BOOKMARK_FILE" | wofi --dmenu --lines 20 --prompt 'Select URL:')

# Check if a URL was selected
if [ -n "$URL" ]; then
    # Copy the URL to the clipboard
    echo "$URL" | xclip -selection clipboard
    # Optionally, you can use swaymsg to open the URL in the default browser
    # swaymsg exec "xdg-open $URL"
fi

# chmod +x /path/to/your/script.sh
# bindsym Mod1+o exec /path/to/your/script.sh

# Alternative Approach Using 'wl-clipboard'

#!/bin/bash

#	# Path to your bookmarks file
#	BOOKMARK_FILE="$HOME/.local/share/snippets"
#
#	# Read bookmarks, exclude comments, and present them in wofi
#	URL=$(grep -v '^#' "$BOOKMARK_FILE" | wofi --dmenu --lines 20 --prompt 'Select URL:')
#
#	# Check if a URL was selected
#	if [ -n "$URL" ]; then
#	    # Copy the URL to the clipboard
#	    echo "$URL" | wl-copy
#	    # Optionally, you can use swaymsg to open the URL in the default browser
#	    swaymsg exec "xdg-open $URL"
#	fi
