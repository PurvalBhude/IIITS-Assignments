-- Name: Purval Madhukar Bhude
-- Roll No. S20230010193
-- Assignment 7


create database S20230010193_lab7;

USE s20230010193_lab7;
CREATE TABLE Customer (
    customer_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(255) NOT NULL,
    city VARCHAR(100)
);

-- Inserting dummy data into the Customer table
INSERT INTO Customer (name, city) VALUES 
('John Doe', 'New York'),
('Jane Smith', 'Los Angeles'),
('Mike Johnson', 'Chicago'),
('Emily Davis', 'Houston'),
('David Wilson', 'Phoenix');



CREATE TABLE Account (
    account_number INT PRIMARY KEY AUTO_INCREMENT,
    customer_id INT,
    balance DECIMAL(10, 2),
    FOREIGN KEY (customer_id) REFERENCES Customer(customer_id)
);

-- Inserting dummy data into the Account table
INSERT INTO Account (customer_id, balance) VALUES
(1, 5000.00),
(2, 10000.50),
(3, 750.00),
(4, 8500.00),
(5, 1200.00);

CREATE TABLE Loan (
    loan_id INT PRIMARY KEY AUTO_INCREMENT,
    customer_id INT,
    amount DECIMAL(10, 2),
    FOREIGN KEY (customer_id) REFERENCES Customer(customer_id)
);

-- Inserting dummy data into the Loan table
INSERT INTO Loan (customer_id, amount) VALUES
(1, 20000.00),
(3, 15000.00),
(5, 5000.00);

-- Question 1
DELIMITER $$
CREATE PROCEDURE InsertIntoCustomer(
    IN in_name VARCHAR(255),
    IN in_city VARCHAR(100)
)
BEGIN
    INSERT INTO Customer (name, city) VALUES (in_name, in_city);
END$$
DELIMITER ;

-- Question 2
DROP PROCEDURE IF EXISTS InsertIntoCustomer;

-- Question 3
DELIMITER $$
CREATE PROCEDURE CalculateSumAndMultiplication(
    IN num1 INT,
    IN num2 INT,
    OUT sum_result INT,
    OUT multiplication_result INT
)
BEGIN
    SET sum_result = num1 + num2;
    SET multiplication_result = num1 * num2;
END$$
DELIMITER ;


-- Question 4
DELIMITER $$
CREATE PROCEDURE CalculateSquareRoot(
    IN number FLOAT,
    OUT sqrt_result FLOAT
)
BEGIN
    SET sqrt_result = SQRT(number);
END$$
DELIMITER ;

-- Test the procedure
SET @sqrt_result = 0;
CALL CalculateSquareRoot(16, @sqrt_result);
SELECT @sqrt_result AS SquareRoot;


-- Question 5
DELIMITER $$
CREATE PROCEDURE CountCharacters(
    IN input_string VARCHAR(255),
    OUT char_count INT
)
BEGIN
    SET char_count = LENGTH(input_string);
END$$
DELIMITER ;

-- Test the procedure
SET @char_count = 0;
CALL CountCharacters('Hello World', @char_count);
SELECT @char_count AS CharacterCount;



-- Question 6
DELIMITER $$
CREATE PROCEDURE CalculateFactorial(
    IN number INT,
    OUT factorial_result BIGINT
)
BEGIN
    DECLARE i INT DEFAULT 1;
    DECLARE fact BIGINT DEFAULT 1;
    
    WHILE i <= number DO
        SET fact = fact * i;
        SET i = i + 1;
    END WHILE;
    
    SET factorial_result = fact;
END$$
DELIMITER ;


-- Question 7
DELIMITER $$
CREATE PROCEDURE UpdateCustomerName(
    IN old_name VARCHAR(255),
    IN new_name VARCHAR(255)
)
BEGIN
    UPDATE Customer
    SET name = new_name
    WHERE name = old_name;
END$$
DELIMITER ;


-- Question 8
DELIMITER $$
CREATE PROCEDURE CheckLoanStatus(
    IN customer_id INT,
    OUT has_loan VARCHAR(3)
)
BEGIN
    IF EXISTS (SELECT 1 FROM Loan WHERE customer_id = customer_id) THEN
        SET has_loan = 'Yes';
    ELSE
        SET has_loan = 'No';
    END IF;
END$$
DELIMITER ;


-- Question 9
DELIMITER $$
CREATE PROCEDURE DisplayOrInsertCustomer(
    IN in_customer_id INT,
    IN in_name VARCHAR(255),
    IN in_city VARCHAR(100)
)
BEGIN
    DECLARE customer_exists INT;
    
    SELECT COUNT(*) INTO customer_exists FROM Customer WHERE customer_id = in_customer_id;
    
    IF customer_exists > 0 THEN
        SELECT city FROM Customer WHERE customer_id = in_customer_id;
    ELSE
        INSERT INTO Customer (customer_id, name, city) VALUES (in_customer_id, in_name, in_city);
        SELECT 'New customer inserted' AS Message;
    END IF;
END$$
DELIMITER ;

-- Question 10
DELIMITER $$
CREATE PROCEDURE AccountsAboveBalance(
    IN balance_limit DECIMAL(10, 2)
)
BEGIN
    SELECT account_number
    FROM Account
    WHERE balance > balance_limit;
END$$
DELIMITER ;