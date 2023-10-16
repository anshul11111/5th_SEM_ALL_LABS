-- Task 1: Logon to Oracle using your User Name.
--use conn or connect 
-- Task 2: See list of tables.
SELECT table_name FROM user_tables;

-- Task 3: View the user name from dual.
SELECT USER FROM DUAL;

-- Task 4: Create the "Students" table
CREATE TABLE Students (
    "Roll No" NUMBER(6),
    Name VARCHAR2(15),
    City VARCHAR2(12),
    Pincode VARCHAR2(8),
    Age NUMBER(2)
);

-- Task 5: Display the structure of table
DESC Students;

-- Task 6: Insert data into the "Students" table
INSERT INTO Students ("Roll No", Name, City, Pincode, Age)
VALUES
(1, 'Amit', 'Delhi', '214213', 21),
(2, 'Kumar', 'Bombay', '25', NULL),
(3, 'Kshitij', 'Madras', '110101', 16),
(4, 'Puneet', 'Calcutta', '18', NULL),
(5, 'Rohit', 'Delhi', '502207', 19),
(6, 'Karnal', 'Dehradun', '28', NULL),
(7, 'Shweta', 'Dehradun', '98102', 23),
(8, 'Mohit', 'Bombay', '12434', 22),
(9, 'Pankaj', 'Bombay', '17', NULL),
(10, 'Parul', 'Delhi', '76312', 24),
(11, 'Rohit', 'Baroda', '12131', 29);

-- Task 7: Write queries for various outputs
-- Show all records
SELECT * FROM Students;

-- Show names of all students living in Delhi
SELECT Name FROM Students WHERE City = 'Delhi';

-- Show record of all student whose name starts with “A”
SELECT * FROM Students WHERE Name LIKE 'A%';

-- Show record of all student whose second alphabet of name is “a”
SELECT * FROM Students WHERE SUBSTR(Name, 2, 1) = 'a';

-- Show record of all student whose name ends with “it”
SELECT * FROM Students WHERE Name LIKE '%it';

-- Show record of all student whose name contains “t”
SELECT * FROM Students WHERE Name LIKE '%t%';

-- Show record of all student whose name contains “t” but not in the end
SELECT * FROM Students WHERE Name LIKE '%t%' AND Name NOT LIKE '%t';

-- Show records of all students having age greater than 25 & living in Dehradun
SELECT * FROM Students WHERE Age > 25 AND City = 'Dehradun';

-- Show the list of all cities (names of cities should not be repeated)
SELECT DISTINCT City FROM Students;

-- Show the names students alphabetically in ascending order
SELECT Name FROM Students ORDER BY Name;

-- Show the records of those students who are either less than 20 years old or they are living in Bombay
SELECT * FROM Students WHERE Age < 20 OR City = 'Bombay';

-- Show records of all those students who are not living in Dehradun
SELECT * FROM Students WHERE City != 'Dehradun';

-- Display all names in uppercase
SELECT UPPER(Name) FROM Students;

-- Display all cities in lowercase
SELECT LOWER(City) FROM Students;

-- Display name in lowercase, cities in uppercase
SELECT LOWER(Name), UPPER(City) FROM Students;

-- Show all records in uppercase
SELECT UPPER("Roll No"), UPPER(Name), UPPER(City), UPPER(Pincode), UPPER(Age) FROM Students;

-- Display those records which do not have pin code
SELECT * FROM Students WHERE Pincode IS NULL;

-- Task 8: Insert additional data into the "Students" table
INSERT INTO Students ("Roll No", Name, City, Pincode, Age)
VALUES
(12, 'Gaurav', 'Rampur', '312125', NULL),
(NULL, 'Manish', NULL, '314136', NULL),
(14, 'Aviral', NULL, '319143', 29),
(15, 'Gwaliar', '313149', NULL, 25);

-- Task 9: Write queries for various updates
-- (i) Assign Roll No. “13” to Manish
UPDATE Students SET "Roll No" = 13 WHERE Name = 'Manish';

-- (ii) Assign the name “Abhijeet” to Roll No. 15
UPDATE Students SET Name = 'Abhijeet' WHERE "Roll No" = 15;

-- (iii) Set the cities of Roll No. 13 & 14 to “Meerut”
UPDATE Students SET City = 'Meerut' WHERE "Roll No" IN (13, 14);

-- (iv) Increase all age by 3 years
UPDATE Students SET Age = Age + 3;

-- (v) Set the age of all students living in Meerut to “25”
UPDATE Students SET Age = 25 WHERE City = 'Meerut';

-- Task 10: Add a new column named “Balance”, type number to the Students table
ALTER TABLE Students ADD (Balance NUMBER);

-- Task 11: Set the balance of all students to Rs. 20,000/-
UPDATE Students SET Balance = 20000;

-- Task 12: Increase the balance by Rs. 500/- for all Bombay & Delhi students
UPDATE Students SET Balance = Balance + 500 WHERE City IN ('Bombay', 'Delhi');

-- Task 13: Show the total balance amount of all students
SELECT SUM(Balance) FROM Students;

-- Task 14: Show the maximum balance
SELECT MAX(Balance) FROM Students;

-- Task 15: Increase the size of “balance” column to 10
ALTER TABLE Students MODIFY (Balance NUMBER(10));

-- Task 16: Reduce the size of city to “10”
ALTER TABLE Students MODIFY (City VARCHAR2(10));

-- Task 17: Create a new table “student2” as a copy of Students with all rows from Students table
CREATE TABLE student2 AS SELECT * FROM Students;

-- Task 18: Show the records & structure of student2 table
SELECT * FROM student2;
DESC student2;

-- Task 19: Delete the records of those students from “student2” table who are greater or equal to 25 years
DELETE FROM student2 WHERE Age >= 25;

-- Task 20: Show all records of student2 table
SELECT * FROM student2;

-- Task 21: Change the name of student2 to “Newstudent”
ALTER TABLE student2 RENAME TO Newstudent;

-- Task 22: Delete all records from “Newstudent” using truncate. Do not use delete.
TRUNCATE TABLE Newstudent;

-- Task 22(a): See the records of “Newstudent”
SELECT * FROM Newstudent;

-- Task 22(b): Rollback and see records again
ROLLBACK;
SELECT * FROM Newstudent;

-- Task 23: Drop the “Newstudent” table
DROP TABLE Newstudent;

-- Task 24: Again create the “Newstudent” table similar to Students table but this time without any records, copy only the structure
CREATE TABLE Newstudent AS SELECT * FROM Students WHERE 1=0;

-- Task 25: Create a new table named “MCA” with only 
--three columns RollNo, Name & balance from “Students” table
-- along with its data and Show the records and structure of “MCA” table
CREATE TABLE MCA AS SELECT "Roll No", Name, Balance FROM Students;

SELECT * FROM MCA;
DESC MCA;
