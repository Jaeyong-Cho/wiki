-- Recreate database
DROP DATABASE IF EXISTS menagerie;
CREATE DATABASE menagerie;

-- Select target database
USE menagerie;

-- Create table
CREATE TABLE pet (name VARCHAR(20), owner VARCHAR(20), species VARCHAR(20), sec CHAR(1), birth DATE);

-- Load datas
LOAD DATA LOCAL INFILE '../pet.txt' INTO TABLE pet FIELDS TERMINATED BY ' ';
SELECT * FROM pet;

-- Select with ascending order
SELECT name, birth FROM pet ORDER BY birth;

-- Select with descending order
SELECT name, birth FROM pet ORDER BY birth DESC;

-- Select with sort by species in ascending order and then by birth in descending order
SELECT name, species, birth FROM pet ORDER BY species, birth DESC;
