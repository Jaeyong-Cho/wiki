# Mysql loading data info table
## Run
```sh
mysql --result-format=table < ./loading_data.sql
```

## Code
```sql
-- Recreate database
DROP DATABASE IF EXISTS menagerie;
CREATE DATABASE menagerie;

-- Select target database
USE menagerie;

-- Create table
CREATE TABLE pet (name VARCHAR(20), owner VARCHAR(20), species VARCHAR(20), sex CHAR(1), birth DATE, death DATE);

-- Select database
USE menagerie;

-- Load data from txt file
LOAD DATA LOCAL INFILE '../pet.txt' INTO TABLE pet FIELDS TERMINATED BY ' ';

-- Insert data into table
INSERT INTO pet VALUES('Puffball','Diane','hamster','f','1999-03-30',NULL);

-- Check result
SELECT * FROM pet;
+----------+--------+---------+------+------------+------------+
| name     | owner  | species | sex  | birth      | death      |
+----------+--------+---------+------+------------+------------+
| Fluffy   | Harold | cat     | f    | 1993-02-04 | 0000-00-00 |
| Claws    | Gwen   | cat     | m    | 1994-03-17 | 0000-00-00 |
| Buffy    | Harold | dog     | f    | 1989-05-13 | 0000-00-00 |
| Fang     | Benny  | dog     | m    | 1990-08-27 | 0000-00-00 |
| Bowser   | Diane  | dog     | m    | 1979-08-31 | 1995-07-29 |
| Chirpy   | Gwen   | bird    | f    | 1998-09-11 | 0000-00-00 |
| Whistler | Gwen   | bird    | N    | 1997-12-09 | 0000-00-00 |
| Slim     | Benny  | snake   | m    | 1996-04-29 | 0000-00-00 |
| Puffball | Diane  | hamster | f    | 1999-03-30 | 0000-00-00 |
| Puffball | Diane  | hamster | f    | 1999-03-30 | NULL       |
+----------+--------+---------+------+------------+------------+
```
