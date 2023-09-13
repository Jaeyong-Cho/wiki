-- Recreate database
DROP DATABASE IF EXISTS menagerie;
CREATE DATABASE menagerie;

-- Select target database
USE menagerie;

-- Create table
CREATE TABLE pet (name VARCHAR(20), owner VARCHAR(20), species VARCHAR(20), sec CHAR(1), birth DATE);
LOAD DATA LOCAL INFILE '../pet.txt' INTO TABLE pet FIELDS TERMINATED BY ' ';

-- Retrieves everything from a table
SELECT * FROM pet;

-- Reload data from file
DELETE FROM pet;
LOAD DATA LOCAL INFILE 'pet.txt' INTO TABLE pet FIELDS TERMINATED BY ' ';
SELECT * FROM pet;

-- Fix record
UPDATE pet SET birth = '1989-08-31' WHERE name = 'Bowser';
SELECT * FROM pet;
