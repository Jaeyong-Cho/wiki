-- Recreate database
DROP DATABASE menagerie;
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
