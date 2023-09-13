# Loading local data is disabled
- local data loading capability is disabled

## Enabling local data loading capability
### On the server side
- local_infile system variable control LOCAL capability
- Start mysqld with local_infile enabled
```sh
# in /etc/mysql/mysql.conf.d/mysqld.cnf add following line
local_infile = 1
```

### On the client side
- Run mysql like thid
```sh
mysql --local_infile=1
```
- Or add following line to ~/.my.cnf
```cnf
local_infile = 1
```
