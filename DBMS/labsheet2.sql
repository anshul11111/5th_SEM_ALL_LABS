-- Task 1: Logon to Oracle using the provided username.
--you are expected to do it yourself (use conn)
-- Task 2: See the list of tables by using "Tab."
SELECT * FROM Tab;
-- Task 3: View the username to ensure it's your login name.
SElECT USER FROM DUAL;
-- Task 4: Create the "Employee" table
CREATE TABLE Employee (
    EmpCode NUMBER,
    Name VARCHAR2(6),
    Salary NUMBER
);

-- Task 5: Display the structure of the table
DESC Employee;

-- Task 6: See the records of the table
SELECT * FROM Employee;

-- Task 7: Insert data into the table
INSERT INTO Employee (EmpCode, Name, Salary)
VALUES
(101, 'Amit', 30000),
(201, 'Kapil', 22000),
(301, 'Rohit', 45000),
(401, 'Amit', 27000),
(401, 'Amit', 27000);

-- Task 8: See the records of the table
SELECT * FROM Employee;

-- Task 9: Try to add a new record
INSERT INTO Employee (EmpCode, Name, Salary)
VALUES (901, 'Bhattacharya', 33000);

-- Task 10: See the structure of the table and note the size of the "Name" column
DESC Employee;

-- Task 11: Increase the size of the "Name" column to 25
ALTER TABLE Employee MODIFY Name VARCHAR2(25);

-- Task 12: See the structure of the table again
DESC Employee;

-- Task 13: See the records of the table
SELECT * FROM Employee;

-- Task 14: Try to add the above record again
INSERT INTO Employee (EmpCode, Name, Salary)
VALUES (901, 'Bhattacharya', 33000);

-- Task 15: See the records of the table
SELECT * FROM Employee;

-- Task 16: Reduce the size of the "Name" column to 5
ALTER TABLE Employee MODIFY Name VARCHAR2(5);

-- Task 17: Commit the data and see all records
COMMIT;
SELECT * FROM Employee;

-- Task 18: Execute SQL queries and note the results
-- a)
 SELECT Name FROM Employee;
-- b)
 SELECT Name, Name, Name, Name FROM Employee;
-- c)
 SELECT Name, EmpCode FROM Employee ORDER BY Salary;
-- d)
 SELECT Name, Salary, Salary + 500, Salary - 50000 FROM Employee;
-- e)
 SELECT SUM(Salary) FROM Employee;
-- f)
 SELECT MIN(Salary) FROM Employee;
-- g)
 SELECT MAX(Salary) FROM Employee;

-- Task 19: Display name, actual salary, and 50% increased salary of all employees
SELECT Name, Salary, Salary * 1.5 AS IncreasedSalary FROM Employee;

-- Task 20: Make a copy of "Employee" table as "NewEmp" table with all records
CREATE TABLE NewEmp AS SELECT * FROM Employee;

-- Task 21: See the records of "NewEmp" table
SELECT * FROM NewEmp;

-- Task 22: Make a copy of "Employee" table as "Emp2" table with no records
CREATE TABLE Emp2 AS SELECT * FROM Employee WHERE 1 = 0;

-- Task 23: See the records of all 3 tables (Employee, NewEmp, and Emp2)
SELECT * FROM Employee;
SELECT * FROM NewEmp;
SELECT * FROM Emp2;

-- Task 24: See the structure of all 3 tables
DESC Employee;
DESC NewEmp;
DESC Emp2;

-- Task 25: Create a new table "MyTable" from "Employee" table with only "Name" and "Salary" columns
CREATE TABLE MyTable AS SELECT Name, Salary FROM Employee;

-- Task 26: See the records of "Employee" Table and "MyTable"
SELECT * FROM Employee;
SELECT * FROM MyTable;

-- Task 27: See the list of all tables
SELECT table_name FROM user_tables;

-- Task 28: Commit your data
COMMIT;

-- Task 29: Drop the columns "Name" and "EmpCode" from "NewEmp" table
ALTER TABLE NewEmp DROP COLUMN Name;
ALTER TABLE NewEmp DROP COLUMN EmpCode;

-- Task 30: See the records of "NewEmp" Table
SELECT * FROM NewEmp;

-- Task 31: Truncate the "MyTable" table
TRUNCATE TABLE MyTable;

-- Task 32: See the records of "MyTable" table
SELECT * FROM MyTable;

-- Task 33: Rollback
ROLLBACK;

-- Task 34: Again see the records of "MyTable" table
SELECT * FROM MyTable;

-- Task 35: Drop the "MyTable" table
DROP TABLE MyTable;

-- Task 36: See the records of "MyTable" table
SELECT * FROM MyTable;

-- Task 37: Rollback
ROLLBACK;

-- Task 38: Again see the records of "MyTable" table
SELECT * FROM MyTable;

-- Task 39: See the list of all tables in our login
SELECT table_name FROM user_tables;

-- Task 40: Commit the data
COMMIT;
