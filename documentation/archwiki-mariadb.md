wiki.archlinux.org
MariaDB - ArchWiki
16–20 minutes

MariaDB is a reliable, high performance and full-featured database server which aims to be an 'always Free, backward compatible, drop-in' replacement of MySQL. Since 2013 MariaDB is Arch Linux's default implementation of MySQL.[1]
Installation

MariaDB is the default implementation of MySQL in Arch Linux, provided with the mariadb package.

Tip:

    If the database (in /var/lib/mysql) resides on a Btrfs file system, you should consider disabling Copy-on-Write for the directory before creating any database.
    If the database resides on a ZFS file system, you should consult ZFS#Databases before creating any database.

Install mariadb, and run the following command before starting the mariadb.service:

# mariadb-install-db --user=mysql --basedir=/usr --datadir=/var/lib/mysql

Tip: If you use something different from /var/lib/mysql for your data dir, you need to set datadir=YOUR_DATADIR under section [mariadb] of your /etc/my.cnf.d/server.cnf.

Now mariadb.service can be started and/or enabled.

Note: Before continuing, it is recommended to improve the initial security of MariaDB installation.

To simplify administration, you might want to install a front-end.
Configuration

By default both root user and the user running the server can administer the database.

To administer the server, run mariadb as the user running the server:

[mysql]$ mariadb

Or as root:

# mariadb

Add user

Creating a new user takes two steps: create the user; grant privileges. In the below example, the user monty with some_pass as password is being created, then granted full permissions to the database mydb:

# mariadb -u root -p

MariaDB> CREATE USER 'monty'@'localhost' IDENTIFIED BY 'some_pass';
MariaDB> GRANT ALL PRIVILEGES ON mydb.* TO 'monty'@'localhost';
MariaDB> quit

Configuration files

MariaDB configuration options are read from the following files in the given order (according to mysqld --help --verbose | head -10 output):

/etc/my.cnf /etc/my.cnf.d/ ~/.my.cnf

Create a configuration file in /etc/my.cnf.d/ with a .cnf extension to ensure that upgrades preserve your configuration.

Depending on the scope of the changes you want to make (system-wide, user-only...), use the corresponding file. See this entry of the Knowledge Base for more information.
Enable auto-completion

Note: Enabling this feature can make the client initialization longer.

The MariaDB client completion feature is disabled by default. To enable it system-wide edit /etc/my.cnf.d/client.cnf, and add auto-rehash under client-mariadb. Note that this must not be placed under mysqld. Completion will be enabled next time you run the MariaDB client.
Using UTF8MB4

Warning: Before changing the character set be sure to create a backup first.

Note:

    The mariadb package already uses utf8mb4 as charset and utf8mb4_unicode_ci as collation. Users using the default (character) settings may want to skip this section.
    UTF8MB4 is recommended over UTF-8 since it allows full Unicode support [2] [3].

Append the following values to the main configuration file located at /etc/my.cnf.d/my.cnf:

[client]
default-character-set = utf8mb4

[mariadb]
collation_server = utf8mb4_unicode_ci
character_set_server = utf8mb4

[mariadb-client]
default-character-set = utf8mb4

Restart mariadb.service to apply the changes. Changing the character set does not change existing table formats, only newly created tables, and the protocol interaction that fetches data.

See #Maintenance to optimize and check the database health.
Using a tmpfs for tmpdir

The directory used by MariaDB for storing temporary files is named tmpdir. For example, it is used to perform disk based large sorts, as well as for internal and explicit temporary tables.

Create the directory with appropriate permissions:

# mkdir -pv /var/lib/mysqltmp
# chown mysql:mysql /var/lib/mysqltmp

Add the following tmpfs mount to your /etc/fstab file:

tmpfs   /var/lib/mysqltmp   tmpfs   rw,gid=mysql,uid=mysql,size=100M,mode=0750,noatime   0 0

Add to your /etc/my.cnf.d/server.cnf file under the mysqld group:

tmpdir      = /var/lib/mysqltmp

Stop mariadb.service, mount /var/lib/mysqltmp/ and start mariadb.service.
Time zone tables

Although time zone tables are created during the installation, they are not automatically populated. They need to be populated if you are planning on using CONVERT_TZ() in SQL queries.

To populate the time zone tables with all the time zones:

$ mariadb-tzinfo-to-sql /usr/share/zoneinfo | mariadb -u root -p mysql

Optionally, you may populate the table with specific time zone files:

$ mariadb-tzinfo-to-sql timezone_file timezone_name | mariadb -u root -p mysql

Security
Improve initial security

The mariadb-secure-installation command will interactively guide you through a number of recommended security measures, such as removing anonymous accounts and removing the test database:

# mariadb-secure-installation

Warning: After running this, please note that TCP port 3306 will still be open, but refusing connections with an error message. To prevent MySQL from listening on an external interface, see the #Listen only on the loopback address and #Enable access locally only via Unix sockets sections.
Listen only on the loopback address

By default, MariaDB will listen on the 0.0.0.0 address, which includes all network interfaces. In order to restrict MariaDB to listen only to the loopback address, add the following line in /etc/my.cnf.d/server.cnf:

[mariadb]
bind-address = localhost

This will bind to both 127.0.0.1 and ::1, and enable MariaDB to receive connections both in IPv4 and IPv6.
Enable access locally only via Unix sockets

By default, MariaDB is accessible via both Unix sockets and the network. If MariaDB is only needed for the localhost, you can improve security by not listening on TCP port 3306, and only listening on Unix sockets instead. To do this, add the following line in /etc/my.cnf.d/server.cnf:

[mariadb]
skip-networking

You will still be able to log in locally as before, but only using Unix sockets.
Grant remote access

Warning: This is not considered as best practice and may cause security issues. Consider using Secure Shell, VNC or VPN, if you want to maintain the MariaDB server from another host inside/outside your network.

To allow remote access to the MariaDB server, ensure that MariaDB has networking enabled and is listening on the appropriate interface.

Grant any MariaDB user remote access (example for root):

# mariadb -u root -p

Check current users with remote access privileged:

SELECT User, Host FROM mysql.user WHERE Host <> 'localhost';

Now grant remote access for your user (here root):

GRANT ALL PRIVILEGES ON *.* TO 'root'@'192.168.1.%' IDENTIFIED BY 'my_optional_remote_password' WITH GRANT OPTION;

You can change the '%' wildcard to a specific host if you like. The password can be different from user's main password.
Configure access to home directories

For security reasons, the systemd service file contains ProtectHome=true, which prevents MariaDB from accessing files under the /home, /root and /run/user hierarchies. The datadir has to be in an accessible location and owned by the mysql user and group.

You can modify this behavior by creating a supplementary service file as described here.
Maintenance
Upgrade databases on major releases

Upon a major version release of mariadb (for example mariadb-10.3.10-1 to mariadb-10.9.4-1), it is wise to upgrade the system database to make new server features available:

# mariadb-upgrade -u root -p

To upgrade from 10.3.x to 10.9.x:

    perform a clean shutdown of the 10.3.x server
    upgrade the package
    run mariadb-upgrade (from the new package version) against the new running daemon

If the (new) daemon is not starting, see #Unable to run mariadb-upgrade because MariaDB cannot start.
Checking, optimizing and repairing databases

mariadb-clients ships with mariadb-check which can be used to check, repair, and optimize tables within databases from the shell. See mariadb-check(1) for more. Several command tasks are shown:

To check all tables in all databases:

$ mariadb-check --all-databases -u root -p -c

To analyze all tables in all databases:

$ mariadb-check --all-databases -u root -p -a

To repair all tables in all databases:

$ mariadb-check --all-databases -u root -p -r

To optimize all tables in all databases:

$ mariadb-check --all-databases -u root -p -o

Backup

There are various tools and strategies to back up your databases.

If you are using the default InnoDB storage engine, a suggested way of backing up all your bases online while provisioning for point-in-time recovery (also known as "roll-forward", when you need to restore an old backup and replay the changes that happened since that backup) is to execute the following command:

$ mariadb-dump --single-transaction --flush-logs --events --routines --master-data=2 --all-databases -u root -p > all_databases.sql

This will prompt for MariaDB's root user's password, which was defined during database #Configuration.

Specifying the password on the command line is strongly discouraged, as it exposes it to discovery by other users through the use of ps aux or other techniques. Instead, the aforementioned command will prompt for the specified user's password, concealing it away.
Compression

As SQL tables can get pretty large, it is recommended to pipe the output of the aforementioned command in a compression utility like xz(1):

$ mariadb-dump --single-transaction --flush-logs --events --routines --master-data=2 --all-databases -u root -p | xz -z > all_databases.sql.xz

Decompressing the backup thus created and reloading it in the server is achieved by doing:

$ xzcat all_databases.sql.xz | mariadb -u root -p

This will recreate and repopulate all the databases previously backed up (see this or this).
Non-interactive

If you want to setup non-interactive backup script for use in cron jobs or systemd timers, see option files and this illustration for mariadb-dump.

Basically you should add the following section to the relevant configuration file:

[mariadb-dump]
user=mysqluser
password=secret

Mentioning a user here is optional, but doing so will free you from having to mention it on the command line. If you want to set this for all tools, including mariadb-client, use the [client] group.
Example script

The database can be dumped to a file for easy backup. The following shell script will do this for you, creating a db_backup.xz file in the same directory as the script, containing your database dump:

#!/bin/sh

THISDIR=$(dirname $(readlink -f "$0"))

mariadb-dump --single-transaction --flush-logs --events --routines --master-data=2 --all-databases \
 | xz -z > $THISDIR/db_backup.xz
echo 'purge master logs before date_sub(now(), interval 7 day);' | mariadb

See also the official mariadb-dump page in the MariaDB manuals.
Holland Backup

A python-based software package named Holland Backup allows to automate all of the backup work. It supports direct mysqldump, LVM snapshots to tar files (mysqllvm), LVM snapshots with mysqldump (mysqldump-lvm), and xtrabackup methods to extract the data. The Holland framework supports a multitude of options and is highly configurable to address almost any backup situation.

The main hollandAUR and holland-commonAUR packages provide the core framework; one of the sub-packages (holland-mysqldumpAUR, holland-mysqllvmAUR and/or holland-xtrabackupAUR must be installed for full operation. Example configurations for each method are in the /usr/share/doc/holland/examples/ directory and can be copied to /etc/holland/backupsets/, as well as using the holland mk-config command to generate a base configuration for a named provider.
Troubleshooting
Unable to run mariadb-upgrade because MariaDB cannot start

Try run MariaDB in a standalone:

# mariadbd-safe --datadir=/var/lib/mysql/

And then run:

# mariadb-upgrade -u root -p

Reset the root password

    Stop mariadb.service.
    Start the MariaDB server with safety features:

    # mariadbd-safe --skip-grant-tables --skip-networking &

    Connect to it:

    # mariadb -u root

    Change root password:

    MariaDB [mysql]> FLUSH PRIVILEGES;
    MariaDB [mysql]> ALTER USER 'root'@'localhost' IDENTIFIED BY 'new_password';
    MariaDB [mysql]> exit

    Kill running mariadbd* processes:

    # kill $(cat /var/lib/mysql/$HOSTNAME.pid)

    Start mariadb.service.

Check and repair all tables

Check and auto repair all tables in all databases, see more:

# mariadb-check -A --auto-repair -u root -p

Optimize all tables

Forcefully optimize all tables, automatically fixing table errors that may come up.

# mariadb-check -A --auto-repair -f -o -u root -p

OS error 22 when running on ZFS

If using MySQL databases on ZFS, the error InnoDB: Operating system error number 22 in a file operation may occur.

A workaround is to disable aio_writes in /etc/my.cnf.d/my.cnf:

/etc/my.cnf.d/my.cnf

[mariadb]
innodb_use_native_aio = 0

Cannot login through CLI, but phpmyadmin works well

This may happen if you are using a long (>80) password. mariadb CLI cannot handle that many characters in readline mode. So, if you are planning to use the recommended password input mode:

$ mariadb -u user -p

Password:

Consider changing the password to smaller one.

Note: You still can log in by specifying the password as an argument to mariadb command.

Warning: This behavior is considered dangerous, because your password might leak, for example, to the logs. Use it only in case of emergency and do not forget to change password right afterwards.

$ mariadb -u user -p"some-very-strong-password"

MariaDB binary logs are taking up huge disk space

This article or section is out of date.

By default, mariadbd creates binary log files at /var/lib/mysql/mysql-bin.XXXXXX with the numbers ascending. These logs are useful for replication master server or data recovery, but these binary logs can easily eat up large amounts of disk space. If you do not plan to use replication or data recovery features, you may disable binary logging by commenting out these lines in /etc/my.cnf.d/my.cnf then restart:

#log-bin=mysql-bin
#binlog_format=mixed

Or, if you want to keep these logs but keep their size in check and old logs deleted, you can set these limits then restart:

log-bin=mysql-bin
expire_logs_days = 10
max_binlog_size  = 100M

Alternatively, there exists a MariaDB command to manually purge logs older than a specific one. For example, you may see a file named mysql-bin.000023 and want to delete every log older than it. As long as the log-bin=mysql-bin setting is in effect, you would run:

# mariadb -u root -p"PASSWORD" -e "PURGE BINARY LOGS TO 'mysql-bin.000023;"

Warning: Using any of these methods may decrease the chances of successful data recovery when trying to repair database tables (i.e. on database corruption).
OpenRC fails to start MariaDB

To use MariaDB with OpenRC you need to add the following lines to the [mariadb] section in the MySQL configuration file, located at /etc/my.cnf.d/my.cnf.

user = mysql
basedir = /usr
datadir = /var/lib/mysql
pid-file = /run/mysqld/mysql.pid

You should now be able to start MariaDB using:

# rc-service mysql start

Changed limits warning on max_open_files/table_open_cache

Increase the number of file descriptors by creating a systemd drop-in, e.g.:

/etc/systemd/system/mariadb.service.d/limit_nofile.conf

[Service]
LimitNOFILE=8192

10.4 to 10.5 upgrade crash: "InnoDB: Upgrade after a crash is not supported. The redo log was created with MariaDB 10.4.x"

Before MariaDB 10.5, redo log was unnecessarily split into multiple files.[4]

Do NOT ever remove the old binary logs /var/lib/mysql/ib_logfile* out of the way.

To resolve this, install MariaDB 10.4. Start it and let it undergo a clean shutdown. After that happens you can upgrade to 10.5 again. Same applies if another version of MariaDB was specified.
Table 'mysql.xxx' does not exist in engine

Symptom: When running mariadb-upgrade or mariadb-check, it return one or more error like these:

Table 'mysql.xxx' does not exist in engine

Where "xxx" usually is the system table inside the mysql database.

Steps to fix this,

    Create backup directory outside of MariaDB ${DATADIR}</nowiki>, for example in $HOME/mariadb_backup.
    Copy the offending files from ${DATADIR}/mysql/xxx.{frm,ibd}</nowiki> to backup directory. The xxx.ibd may not exist.
    Drop the tables with DROP TABLE mysql.xxx on the mariadb prompt.
    Run the mariadb-check. On success, the file xxx.frm and xxx.ibd should be created again.
    Re-run mariadb-upgrade if necessary. You may need the --force option.

See also

    MariaDB Official Website
    MariaDB knowledge Base
    MySQL Performance Tuning Scripts and Know-How

