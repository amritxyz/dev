sudo rm -rf /var/service/NetworkManager
sudo rm -rf /var/service/dbus
sudo rm -rf /var/service/wpa_supplicant
sudo rm -rf /var/service/dhcpcd
sudo ln -s /etc/sv/NetworkManager/ /var/service/
sudo ln -s /etc/sv/dbus/ /var/service/
