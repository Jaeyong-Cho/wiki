# Mysql

## Troubleshoot
### root user permission denied?
- Stop mysqld `sudo service mysql stop`
- Restart mysqld with --skip-grant-tables
    - Add `skip-grant-tables` in `/etc/mysql/mysql.conf.d/mysqld.cnf`
    - Start mysqld `sudo service mysql start`
- Strat mysql and issue the following commands
- `UPDATE mysql.user SET Grant_priv='Y', Super_priv='Y' WHERE User='root';`
- `FLUSH PRIVILEGES;`
- `GRANT ALL ON *.* TO 'root'@'localhost';`
- Reset `/etc/mysql/mysql.conf.d/mysqld.cnf` and restart
