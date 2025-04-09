#!/bin/bash

sudo pacman -Sy
sudo pacman -S zed

rm -rf ~/.config/zed
mkdir -p ~/.config/zed

curl -o ~/.config/zed/keymap.json https://raw.githubusercontent.com/amritxyz/backups/main/zed/keymap.json
curl -o ~/.config/zed/settings.json https://raw.githubusercontent.com/amritxyz/backups/refs/heads/main/zed/settings.json
