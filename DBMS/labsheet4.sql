-- Task 1: Check the current user
SELECT USER FROM DUAL;

-- Task 2: See a list of all tables
SELECT table_name FROM user_tables;

-- Task 3: Create the "Car" table
CREATE TABLE Car (
    ModelNo NUMBER PRIMARY KEY,
    ModelName VARCHAR2(50) UNIQUE,
    Company VARCHAR2(50) NOT NULL,
    EngineCapacity NUMBER CHECK (EngineCapacity > 1000),
    Color VARCHAR2(20),
    Doors NUMBER CHECK (Doors > 1),
    Weight NUMBER CHECK (Weight > 1000),
    TopSpeed NUMBER CHECK (TopSpeed < 500),
    RPM NUMBER CHECK (RPM > 5000),
    CostPrice NUMBER,
    SalePrice NUMBER
);

-- Task 4: Display the structure of the "Car" table
DESC Car;

-- Task 5: Populate the "Car" table with relevant data
-- Insert data into the "Car" table
INSERT INTO Car (ModelNo, ModelName, Company, EngineCapacity, Color, Doors, Weight, TopSpeed, RPM, CostPrice, SalePrice)
VALUES
(1, 'Model1', 'Maruti Suzuki', 1500, 'White', 4, 1200, 160, 6000, 50000, 55000),
(2, 'Model2', 'Hyundai', 1800, 'Red', 4, 1300, 170, 5500, 60000, 65000),
(3, 'Model3', 'Honda', 2200, 'Black', 4, 1400, 180, 5800, 70000, 75000),
(4, 'Model4', 'Maruti Suzuki', 1600, 'Blue', 4, 1250, 155, 5900, 52000, 58000),
(5, 'Model5', 'Toyota', 2000, 'Silver', 4, 1350, 175, 5600, 65000, 70000),
(6, 'Model6', 'Hyundai', 1900, 'Red', 4, 1320, 170, 5400, 61000, 67000);

-- Task 6: Queries for various outputs
-- Show all records
SELECT * FROM Car;

-- Show names of all the cars of Maruti
SELECT ModelName FROM Car WHERE Company = 'Maruti Suzuki';

-- Show records of all Cars whose engine is more than 2000 CC
SELECT * FROM Car WHERE EngineCapacity > 2000;

-- Show records of all cars of white color
SELECT * FROM Car WHERE Color = 'White';

-- Show records of all vehicles which are costing more than 4 Lacs
SELECT * FROM Car WHERE CostPrice > 400000;

-- Show the cost price, sale price, and profit on all cars
SELECT ModelName, CostPrice, SalePrice, (SalePrice - CostPrice) AS Profit FROM Car;

-- Show the names of all cars alphabetically
SELECT ModelName FROM Car ORDER BY ModelName;

-- Task 7: Create the "Vehicle" table from the "Car" table structure
CREATE TABLE Vehicle AS
SELECT 
    TopSpeed,
    Doors,
    CostPrice,
    ModelName,
    Company,
    RPM,
    EngineCapacity,
    Color,
    ModelNo,
    Weight,
    SalePrice
FROM Car
WHERE 1 = 0; -- This ensures no records are copied, only columns

-- Task 8: Display the structure of the "Vehicle" table
DESC Vehicle;

-- Task 9: Now populate the "Vehicle" table with all the records of the "Car" table, 
-- but the records should be inserted in random order this time (not in the same order as the "Car" Table). 
-- (Like 11, 4, 5, 1, 7, 3, 2, 9th record, etc.). 
-- Do not write new Insert queries; rather, copy records from the "Car" table in a random order.


-- Task 10: Re-write queries from Task 6 on the "Vehicle" table and notice the output.
-- You can reuse the same queries from Task 6 but replace the table name with "Vehicle."
-- Show all records
SELECT * FROM Vehicle;

-- Show names of all the cars of Maruti
SELECT ModelName FROM Vehicle WHERE Company = 'Maruti Suzuki';

-- Show records of all Cars whose engine is more than 2000 CC
SELECT * FROM Vehicle WHERE EngineCapacity > 2000;

-- Show records of all cars of white color
SELECT * FROM Vehicle WHERE Color = 'White';

-- Show records of all vehicles which are costing more than 4 Lacs
SELECT * FROM Vehicle WHERE CostPrice > 400000;

-- Show the cost price, sale price, and profit on all cars
SELECT ModelName, CostPrice, SalePrice, (SalePrice - CostPrice) AS Profit FROM Vehicle;

-- Show the names of all cars alphabetically
SELECT ModelName FROM Vehicle ORDER BY ModelName;
