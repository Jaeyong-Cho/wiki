# Selecting particular rows
## Run
```sh
mysql --result-format=table < ./selecting_particular_rows.sql
```

## Script
```sql
-- Recreate database
DROP DATABASE IF EXISTS menagerie;
CREATE DATABASE menagerie;

-- Select target database
USE menagerie;

-- Create table
CREATE TABLE pet (name VARCHAR(20), owner VARCHAR(20), species VARCHAR(20), sec CHAR(1), birth DATE);

-- Load data
LOAD DATA LOCAL INFILE './pet.txt' INTO TABLE pet FIELDS TERMINATED BY ' ';
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
+----------+--------+---------+------+------------+------------+

-- Select row from table with =
SELECT * FROM pet WHERE name = 'Bowser';
+--------+-------+---------+------+------------+------------+
| name   | owner | species | sex  | birth      | death      |
+--------+-------+---------+------+------------+------------+
| Bowser | Diane | dog     | m    | 1979-08-31 | 1995-07-29 |
+--------+-------+---------+------+------------+------------+

-- Select row from table with >=
SELECT * FROM pet WHERE birth >= '1998-1-1';
+----------+-------+---------+------+------------+------------+
| name     | owner | species | sex  | birth      | death      |
+----------+-------+---------+------+------------+------------+
| Chirpy   | Gwen  | bird    | f    | 1998-09-11 | 0000-00-00 |
| Puffball | Diane | hamster | f    | 1999-03-30 | 0000-00-00 |
+----------+-------+---------+------+------------+------------+

-- Select row from table with AND
SELECT * FROM pet WHERE species = 'dog' AND sex = 'f';
+-------+--------+---------+------+------------+------------+
| name  | owner  | species | sex  | birth      | death      |
+-------+--------+---------+------+------------+------------+
| Buffy | Harold | dog     | f    | 1989-05-13 | 0000-00-00 |
+-------+--------+---------+------+------------+------------+

-- Select row from table with OR
SELECT * FROM pet WHERE species = 'snake' OR species = 'bird';
+----------+-------+---------+------+------------+------------+
| name     | owner | species | sex  | birth      | death      |
+----------+-------+---------+------+------------+------------+
| Chirpy   | Gwen  | bird    | f    | 1998-09-11 | 0000-00-00 |
| Whistler | Gwen  | bird    | N    | 1997-12-09 | 0000-00-00 |
| Slim     | Benny | snake   | m    | 1996-04-29 | 0000-00-00 |
+----------+-------+---------+------+------------+------------+

-- Select row from table with ()
SELECT * FROM pet WHERE (species = 'cat' AND sex = 'm') OR (species = 'dog' AND sex = 'f');
+-------+--------+---------+------+------------+------------+
| name  | owner  | species | sex  | birth      | death      |
+-------+--------+---------+------+------------+------------+
| Claws | Gwen   | cat     | m    | 1994-03-17 | 0000-00-00 |
| Buffy | Harold | dog     | f    | 1989-05-13 | 0000-00-00 |
+-------+--------+---------+------+------------+------------+
```
