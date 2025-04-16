#!/bin/sh

cd /opt

JSQL_FILE="mysql-connector-j-9.3.0"
XAMPP_FILE="lampp"

# MySQL - Java Connector
if [ -d "$JSQL_FILE" ]; then
    echo "$JSQL_FILE already exists. Skipping creation."
else
    read -rp ":: Would you like to install Java-SQL Connector? [Y/n] " JSQL
    if [ "$JSQL" = "Y" ] || [ "$JSQL" = "y" ] || [ -z "$JSQL" ]; then
        cd /opt
        sudo wget https://dev.mysql.com/get/Downloads/Connector-J/mysql-connector-j-9.3.0.tar.gz
        sudo tar -xzf mysql-connector-j-9.3.0.tar.gz
        sudo rm -rf mysql-connector-j-9.3.0.tar.gz
    fi
fi

# Xampp
if [ -d "$XAMPP_FILE" ]; then
    echo "$XAMPP_FILE already exists. Skipping creation."
else
    read -rp ":: Would you like to install Xampp server? [Y/n] " XAMPP
    if [ "$XAMPP" = "Y" ] || [ "$XAMPP" = "y" ] || [ -z "$XAMPP" ]; then
        sudo pacman -Sy

        sudo pacman -S lib32-gcc-libs lib32-glibc libxcrypt-compat net-tools inetutils

        # Optional
        # sudo pacman -S lib32-libgcrypt

        # Post Installation
        cd /opt/
        # sudo wget https://sourceforge.net/projects/xampp/files/XAMPP%20Linux/8.2.12/xampp-linux-x64-8.2.12-0-installer.run
        sudo wget https://gitlab.com/amritxyz/xampp/-/raw/main/xampp-linux-x64-8.2.12-0-installer.run
        sudo chown $USER:$USER /opt/xampp-linux-x64-8.2.12-0-installer.run
        sudo chmod +x /opt/xampp-linux-x64-8.2.12-0-installer.run
        sudo /opt/xampp-linux-x64-8.2.12-0-installer.run
    fi
fi

# Path to the Java-DataBase-Connection Driver
# /opt/mysql-connector-j-9.3.0/src/legacy/java/com/mysql/jdbc
#
# In Java
# Class.forName("com.mysql.cj.jdbc.Driver");
