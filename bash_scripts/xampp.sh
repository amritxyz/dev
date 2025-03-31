#!/bin/sh

# Install Dependencies First
sudo pacman -S lib32-gcc-libs lib32-glibc lib32-libgcrypt
sudo pacman -S libxcrypt-compat
sudo pacman -S net-tools
sudo pacman -S inetutils

# Post Installation
cd /opt/
sudo wget https://sourceforge.net/projects/xampp/files/XAMPP%20Linux/8.2.12/xampp-linux-x64-8.2.12-0-installer.run
sudo chown $USER:$USER /opt/xampp-linux-x64-8.2.12-0-installer.run
sudo /opt/xampp-linux-x64-8.2.12-0-installer.run
