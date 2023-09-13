# root user has no  privileges
- Check root grant
```sql
SHOW GRANT FOR 'root'@'localhost'
-- USAGE mean there is no privileges
```
- Stop mysqld `sudo service mysql stop`
- Restart mysqld with --skip-grant-tables
    - Add `skip-grant-tables` in `/etc/mysql/mysql.conf.d/mysqld.cnf`
    - Start mysqld `sudo service mysql start`
- Strat mysql and issue the following commands
```sql
UPDATE mysql.user SET Grant_priv='Y', Super_priv='Y' WHERE User='root';
FLUSH PRIVILEGES;
GRANT ALL ON *.* TO 'root'@'localhost';
```
- Reset `/etc/mysql/mysql.conf.d/mysqld.cnf` and restart
