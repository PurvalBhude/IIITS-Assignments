-- Exercise 
-- Question 1
DELIMITER $$

CREATE FUNCTION get_customer_level(balance DECIMAL(10, 2))
RETURNS VARCHAR(10)
DETERMINISTIC
BEGIN
    RETURN CASE 
        WHEN balance >= 900 THEN 'PLATINUM'
        WHEN balance >= 700 THEN 'GOLD'
        ELSE 'SILVER'
    END;
END $$

DELIMITER ;

-- Question 2
DELIMITER $$

CREATE FUNCTION calculate_experience(emp_doj DATE) 
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE experience INT;
    SET experience = TIMESTAMPDIFF(YEAR, emp_doj, CURDATE());
    RETURN experience;
END $$

DELIMITER ;

-- Question 3
DELIMITER $$

CREATE FUNCTION count_high_value_borrowers()
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE borrower_count INT;
    SELECT COUNT(*) INTO borrower_count 
    FROM loans 
    WHERE loan_amount > 1000;
    RETURN borrower_count;
END $$

DELIMITER ;

-- Question 4
DELIMITER $$

CREATE FUNCTION get_highest_balance_customer()
RETURNS VARCHAR(100)
DETERMINISTIC
BEGIN
    DECLARE customer_name VARCHAR(100);
    SELECT customer_name INTO customer_name
    FROM customers
    ORDER BY balance DESC
    LIMIT 1;
    RETURN customer_name;
END $$

DELIMITER ;


-- Exercise 

use S20230010193_lab9;
CREATE TABLE employee (
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(50) NOT NULL
);

DELIMITER $$
CREATE PROCEDURE emp_insert(
    IN id INT,
    IN name VARCHAR(50)
)
BEGIN
    DECLARE EXIT HANDLER FOR 1048
    BEGIN
        SELECT "Trying to populate a non-null column with null value" AS error_message;
    END;
    INSERT INTO employee (emp_id, emp_name) VALUES (id, name);
    SELECT * FROM employee WHERE emp_id = id;
END $$
DELIMITER ;

CALL emp_insert(193, 'Purval');
CALL emp_insert(147, 'shyam');
select * from employee;