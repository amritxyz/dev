# vi /etc/wpa_supplicant/wpa_supplicant.conf

	$	vi /etc/wpa_supplicant/wpa_supplicant.conf

		ctrl_interface=/run/wpa_supplicant
		update_config=1


	$	wpa_passphrase SSID passphrase >> /etc/wpa_supplicant/wpa_supplicant-wlp2s0.conf

	$	wpa_supplicant -B -i interface -c /etc/wpa_supplicant/wpa_supplicant-wlp2s0.conf


	$	ln -s /etc/sv/wpa_supplicant /var/service/

	$	ln -s /etc/sv/dhcpcd /var/service/

# Additional commands

	## Check wpa_supplicant Status:

	$	pgrep wpa_supplicant

	## Review Logs:

	$	journalctl -u wpa_supplicant

	## Restart Services:

	$	sv restart wpa_supplicant

	$	sv restart dhcpcd
