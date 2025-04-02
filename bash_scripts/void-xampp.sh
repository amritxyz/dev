#!/bin/sh

# Install Dependencies First
sudo xbps-install -Su libgcc-32bit glibc-32bit
sudo xbps-install -Su libxcrypt-compat
sudo xbps-install -Su net-tools
sudo xbps-install -Su inetutils

# Post Installation
cd /opt/
sudo wget https://sourceforge.net/projects/xampp/files/XAMPP%20Linux/8.2.12/xampp-linux-x64-8.2.12-0-installer.run
sudo chown $USER:$USER /opt/xampp-linux-x64-8.2.12-0-installer.run
sudo ./xampp-linux-x64-8.2.12-0-installer.run
