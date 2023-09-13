-- Recreate database
DROP DATABASE menagerie;
CREATE DATABASE menagerie;

-- Select target database
USE menagerie;

-- Create table
CREATE TABLE pet (name VARCHAR(20), owner VARCHAR(20), species VARCHAR(20), sec CHAR(1), birth DATE);

-- Load data
LOAD DATA LOCAL INFILE '../pet.txt' INTO TABLE pet FIELDS TERMINATED BY ' ';
SELECT * FROM pet;

-- Select row from table with =
SELECT * FROM pet WHERE name = 'Bowser';

-- Select row from table with >=
SELECT * FROM pet WHERE birth >= '1998-1-1';

-- Select row from table with AND
SELECT * FROM pet WHERE species = 'dog' AND sex = 'f';

-- Select row from table with OR
SELECT * FROM pet WHERE species = 'snake' OR species = 'bird';

-- Select row from table with ()
SELECT * FROM pet WHERE (species = 'cat' AND sex = 'm') OR (species = 'dog' AND sex = 'f');

