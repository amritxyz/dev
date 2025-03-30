# --------------------------------------------------------------------------- #

# Install
sudo pacman -S --needed mariadb
# mysql-workbench	# GUI frontend for MySQL

sudo mariadb-install-db --user=void --basedir=/usr --datadir=/var/lib/mysql

# Optional / autostart on boot
sudo systemctl enable mariadb
sudo systemctl start mariadb

# Login with user and password
#	$ sudo mysql -u root -p

# MySQL Create new user
#	CREATE DATABASE my_database;
# 	CREATE USER 'my_user'@'localhost' IDENTIFIED BY 'my_password';
# 	GRANT ALL PRIVILEGES ON my_database.* TO 'my_user'@'localhost';
# 	FLUSH PRIVILEGES;

# --------------------------------------------------------------------------- #

# Uninstall

# sudo systemctl stop mariadb
# sudo systemctl disable mariadb
# sudo rm -rf /var/cache/pacman/pkg/jemalloc* /var/cache/pacman/pkg/mariadb*
# sudo rm -rf /var/lib/mysql/

# --------------------------------------------------------------------------- #
