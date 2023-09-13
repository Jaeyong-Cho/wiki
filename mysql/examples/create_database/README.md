# Mysql create database 
## Run 
```sh
mysql --result-format=table < ./create_database.sql
```

## Script 
```sql
-- Remove database
DROP DATABASE IF EXISTS menagerie;

-- Create new database
CREATE DATABASE menagerie; 

-- Set menagerie to current database
USE menagerie;

-- Check your database 
SHOW databases
+--------------------+
| Database           |
+--------------------+
| information_schema |
| menagerie          |
| mysql              |
| performance_schema |
+--------------------+
```

## Connect to specific database
```sh
mysql -h host -u user -p menagerie
```

