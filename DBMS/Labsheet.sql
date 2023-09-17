-- 1. Logon to Oracle by user name given to you.

-- (Assuming you've already logged in)

-- 2. See list of tables by using “Tab / user_tables / cat” tables.
SELECT * FROM Tab;
SELECT * FROM user_tables
SELECT * FROM cat;

-- 3. View the user name
SELECT user FROM dual;

-- 4. View today’s date.
SELECT sysdate from dual;

-- 5. Clear screen.
clear screen

-- 6. See the list of all environment variables.
SHOW PARAMETERS;

-- 7. Perform some mathematical operations by using dual. (Addition, multiplication etc.)
SELECT 5 + 3 AS Addition, 5 * 3 AS Multiplication FROM dual;

-- 8. Create a table “Student” with following attributes:
CREATE TABLE Student(    
    Rollno NUMBER,
    Name VARCHAR2(10),
    City VARCHAR2(10)
);

-- 9. Display the structure of the table
DESC Student;

-- 10. See the records of the table
SELECT * FROM Student;

-- 11. Insert the following data into the table
INSERT INTO Student (Rollno, Name, City)
VALUES (1, 'Amit', 'Dehradun');

INSERT INTO Student (Rollno, Name, City)
VALUES (2, 'Kapil', 'Meerut');

INSERT INTO Student (Rollno, Name, City)
VALUES (3, NULL, 'Dehradun');

INSERT INTO Student (Rollno, Name, City)
VALUES (4, 'Amit', NULL);

INSERT INTO Student (Rollno, Name, City)
VALUES (5, NULL, 'Delhi');

-- Commit the data
COMMIT;

-- 12. See the records of the table
SELECT * FROM Student;

-- 13. Add a new column named “Email”, type varchar2(15)
ALTER TABLE Student ADD Email VARCHAR2(15);

-- 14. See the records of the table
SELECT * FROM Student;

-- 15. Display the structure of the table
DESC Student;

-- 16. Set the email of all records to 'btech@gmail.com'
UPDATE Student SET Email = 'btech@gmail.com';

-- 17. See the records of the table
SELECT * FROM Student;

-- 18. Rollback the email data
ROLLBACK;

-- 19. See the records of the table
SELECT * FROM Student;

-- 20. Display the structure of the table
DESC Student;


-- 21. Set the email of ‘Amit’ to ‘abc@xyz’
UPDATE Student SET Email = 'abc@xyz' WHERE Name = 'Amit';

-- 22. See the records of the table
SELECT * FROM Student;

-- 23. Complete all the blank records of your own and add 5 More records (Total = 10)   
update student set name ='sam' where city ='Dehradun';
update student set email ='abc@xsy' where name='Amit';
update student set name ='sam' where city ='Delhi';
--adding 5 more using this single query
update into student values ('&name','&')

-- Commit data
COMMIT;

-- 24. Clear the screen
clear screen
-- (This is typically done in your command-line interface)

-- 25. See all records
SELECT * FROM Student;

-- 26. Set linesize 20
SET LINESIZE 20;

-- 27. Again see all records
SELECT * FROM Student;

-- 28. See the structure of the table (is it same as displayed in question no. 20?)
DESC Student;

-- 29. Let linesize 500
SET LINESIZE 500;

-- 30. Again see all records
SELECT * FROM Student;

-- 31. Set pagesize 7
SET PAGESIZE 7;

-- 32. Again see all records
SELECT * FROM Student;

-- 33. Set pagesize 200
SET PAGESIZE 200;

-- 34. Again see all records
SELECT * FROM Student;

-- 35. Set heading off
SET HEADING OFF;

-- 36. Again see all records (if not displayed, press enter, see records once more)
SELECT * FROM Student;

-- 37. Set heading on
SET HEADING ON;

-- 38. Again see all records
SELECT * FROM Student;

-- 39. Set pause on
SET PAUSE ON;

-- 40. Again see all records (if not displayed, press enter, see records once more)
SELECT * FROM Student;
-- 41. Remove the name column
ALTER TABLE Student DROP COLUMN Name;

-- 42. Display the structure
DESC Student;

-- 43. See the records
SELECT * FROM Student;

-- 44. Make a duplicate copy of Student table with the name “Duplicate”
CREATE TABLE Duplicate AS SELECT * FROM Student;

-- 46. Truncate the “Student” table
TRUNCATE TABLE Student;

-- 47. Rollback and see the records
ROLLBACK;

-- 48. Drop the STUDENT table
DROP TABLE Student;

-- 49. See the records of dropped table
SELECT * FROM Student;

-- 50. Rollback and again see the records of dropped table
Rollback;

-- 51. See the list of all tables (Is your table present?)
SELECT table_name FROM user_tables;

-- 52. Show user name
SELECT user FROM dual;

-- 53. Disconnect.
DISC
