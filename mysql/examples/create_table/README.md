# Mysql create table

## Run
```sh
mysql --result-format=table < ./create_table.sql
```

## Code
```sql
-- Recreate database
DROP DATABASE IF EXISTS menagerie;
CREATE DATABASE menagerie;

-- Select target database
USE menagerie;

-- Check tables of database
SHOW TABLES;
Empty set (0.00 sec)

-- Create table
CREATE TABLE pet (name VARCHAR(20), owner VARCHAR(20), species VARCHAR(20), sec CHAR(1), birth DATE);

-- Check your table
SHOW TABLES;
+---------------------+
| Tables_in_menagerie |
+---------------------+
| pet                 |
+---------------------+

-- Check yout table layout
DESCRIBE pet;
+---------+-------------+------+-----+---------+-------+
| Field   | Type        | Null | Key | Default | Extra |
+---------+-------------+------+-----+---------+-------+
| name    | varchar(20) | YES  |     | NULL    |       |
| owner   | varchar(20) | YES  |     | NULL    |       |
| species | varchar(20) | YES  |     | NULL    |       |
| sex     | char(1)     | YES  |     | NULL    |       |
| birth   | date        | YES  |     | NULL    |       |
| death   | date        | YES  |     | NULL    |       |
+---------+-------------+------+-----+---------+-------+
```
