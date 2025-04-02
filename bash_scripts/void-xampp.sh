#!/bin/sh

# Install Dependencies First
sudo xbps-install -Su void-repo-multilib
sudo xbps-install -S libgcc-32bit glibc-32bit
sudo xbps-install -S libxcrypt-compat
sudo xbps-install -S net-tools
sudo xbps-install -S inetutils

# Post Installation
cd /opt/
sudo wget https://sourceforge.net/projects/xampp/files/XAMPP%20Linux/8.2.12/xampp-linux-x64-8.2.12-0-installer.run
sudo chown $USER:$USER /opt/xampp-linux-x64-8.2.12-0-installer.run
sudo ./xampp-linux-x64-8.2.12-0-installer.run
