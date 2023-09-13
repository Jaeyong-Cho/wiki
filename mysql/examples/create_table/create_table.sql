-- Recreate database
DROP DATABASE menagerie;
CREATE DATABASE menagerie;

-- Select target database
USE menagerie;

-- Check tables of database
SHOW TABLES;

-- Create table
CREATE TABLE pet (name VARCHAR(20), owner VARCHAR(20), species VARCHAR(20), sex CHAR(1), birth DATE, death DATE);

-- Check your table
SHOW TABLES;

-- Check yout table layout
DESCRIBE pet;
