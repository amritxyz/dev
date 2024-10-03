#!/bin/sh

# Path to the pacman.conf file
PACMAN_CONF="/etc/pacman.conf"

# Check if the pacman.conf file exists
if [[ ! -f "$PACMAN_CONF" ]]; then
  echo "Error: $PACMAN_CONF does not exist."
  exit 1
fi

# Remove the comment from the ParallelDownloads line
sed -i.bak '/^#.*ParallelDownloads/s/^#\s*//' "$PACMAN_CONF"

# Inform the user
if grep -q "^ParallelDownloads" "$PACMAN_CONF"; then
  echo "Removed comment from the ParallelDownloads line in $PACMAN_CONF."
else
  echo "No comment found for ParallelDownloads in $PACMAN_CONF."
fi
