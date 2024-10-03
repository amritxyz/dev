#!/bin/sh

# Start Network Manager Service and Removing unnecessary stuffs
sudo rm -rf /var/service/NetworkManager
sudo rm -rf /var/service/dbus
sudo rm -rf /var/service/wpa_supplicant
sudo rm -rf /var/service/dhcpcd
sudo rm -rf /var/service/agetty-tty3
sudo rm -rf /var/service/agetty-tty4
sudo rm -rf /var/service/agetty-tty5
sudo rm -rf /var/service/agetty-tty6
sudo ln -s /etc/sv/NetworkManager/ /var/service/
sudo ln -s /etc/sv/dbus/ /var/service/

# Disabling Wifi_Powersave
sudo rm -rf /etc/NetworkManager/conf.d
sudo mkdir -p /etc/NetworkManager/conf.d
sudo touch /etc/NetworkManager/conf.d/wifi-powersave.conf
LOC="/etc/NetworkManager/conf.d/wifi-powersave.conf"
	echo -e "The following has been added to $LOC.\n"
	echo "[connection]\nwifi.powersave = 2" | sudo tee $LOC > /dev/null
	echo "The following has been added to $LOC."
	cat $LOC
	echo
	sleep 3
	echo "Restarting NetworkManager service..."
	# For Runit Systems
	sudo sv restart NetworkManager
