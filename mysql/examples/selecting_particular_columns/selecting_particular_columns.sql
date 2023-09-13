-- Recreate database
DROP DATABASE menagerie;
CREATE DATABASE menagerie;

-- Select target database
USE menagerie;

-- Create table
CREATE TABLE pet (name VARCHAR(20), owner VARCHAR(20), species VARCHAR(20), sec CHAR(1), birth DATE);

-- Load datas
LOAD DATA LOCAL INFILE '../pet.txt' INTO TABLE pet FIELDS TERMINATED BY ' ';
SELECT * FROM pet;

-- Select particular columns
SELECT name, birth FROM pet;

-- Select unique output
SELECT DISTINCT owner FROM pet;

-- Select with where
SELECT name, species, birth FROM pet WHERE species = 'dog' OR species = 'cat';
