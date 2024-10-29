CREATE DATABASE S20230010193_lab8;
USE S20230010193_lab8;

CREATE TABLE item (
    itemid INT,
    iDesc VARCHAR(10),
    quantity INT,
    price INT,
    category VARCHAR(20)
);

INSERT INTO item VALUES (1, 'ponds', 10, 100, 'Cosmetics');
INSERT INTO item VALUES (2, 'plants', 90, 100, 'Garden');
INSERT INTO item VALUES (3, 'perfume', 5, 500, 'Cosmetics');
INSERT INTO item VALUES (4, 'kb', 10, 10, 'Toys');
INSERT INTO item VALUES (5, 'train', 80, 60, 'Toys');
INSERT INTO item VALUES (6, 'knife', 10, 100, 'Kitchen');

CREATE TABLE sales (
    sid INT,
    itemid INT,
    qtysold INT,
    price INT,
    total VARCHAR(20) DEFAULT '0'
);

INSERT INTO sales (sid, itemid, qtysold, price) VALUES (1, 2, 5, 500);

CREATE TABLE employees_audit (
    id INT AUTO_INCREMENT PRIMARY KEY,
    employeeNumber INT NOT NULL,
    lastname VARCHAR(50) NOT NULL,
    changedat DATETIME DEFAULT NULL,
    action VARCHAR(50) DEFAULT NULL
);

CREATE TABLE WorkCenters (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    capacity INT NOT NULL
);

DROP TABLE IF EXISTS WorkCenterStats;
CREATE TABLE WorkCenterStats (
    totalCapacity INT NOT NULL
);

DROP TABLE IF EXISTS members;
CREATE TABLE members (
    id INT AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(255),
    birthDate DATE,
    PRIMARY KEY (id)
);

DROP TABLE IF EXISTS reminders;
CREATE TABLE reminders (
    id INT AUTO_INCREMENT,
    memberId INT,
    message VARCHAR(255) NOT NULL,
    PRIMARY KEY (id, memberId)
);

DROP TABLE IF EXISTS Salaries;
CREATE TABLE Salaries (
    employeeNumber INT PRIMARY KEY,
    validFrom DATE NOT NULL,
    amount DEC(12,2) NOT NULL DEFAULT 0
);

INSERT INTO Salaries (employeeNumber, validFrom, amount) VALUES
(1002, '2000-01-01', 50000),
(1056, '2000-01-01', 60000),
(1076, '2000-01-01', 70000);

DROP TABLE IF EXISTS SalaryArchives;
CREATE TABLE SalaryArchives (
    id INT AUTO_INCREMENT PRIMARY KEY,
    employeeNumber INT,
    amount DEC(12,2) NOT NULL DEFAULT 0,
    deletedAt TIMESTAMP DEFAULT NOW()
);


DROP TABLE IF EXISTS Salaries;
CREATE TABLE Salaries (
    employeeNumber INT PRIMARY KEY,
    salary DECIMAL(10,2) NOT NULL DEFAULT 0
);

INSERT INTO Salaries (employeeNumber, salary) VALUES
(1002, 5000),
(1056, 7000),
(1076, 8000);

DROP TABLE IF EXISTS SalaryBudgets;
CREATE TABLE SalaryBudgets (
    total DECIMAL(15,2) NOT NULL
);

INSERT INTO SalaryBudgets (total)
SELECT SUM(salary)
FROM Salaries;

SELECT * FROM SalaryBudgets;

-- Question 1
DELIMITER $$

CREATE TRIGGER update_total_capacity_before_insert
BEFORE INSERT ON WorkCenters
FOR EACH ROW
BEGIN
    UPDATE WorkCenterStats
    SET totalCapacity = totalCapacity + NEW.capacity;
END$$

DELIMITER ;

-- Question 2
DELIMITER $$

CREATE TRIGGER insert_reminder_if_birthdate_null
AFTER INSERT ON members
FOR EACH ROW
BEGIN
    IF NEW.birthDate IS NULL THEN
        INSERT INTO reminders (memberId, message)
        VALUES (NEW.id, 'Please update your birth date');
    END IF;
END$$

DELIMITER ;

-- Question 3
DELIMITER $$

CREATE TRIGGER archive_salary_before_delete
BEFORE DELETE ON Salaries
FOR EACH ROW
BEGIN
    INSERT INTO SalaryArchives (employeeNumber, amount, deletedAt)
    VALUES (OLD.employeeNumber, OLD.salary, NOW());
END$$

DELIMITER ;


-- Question 4
DELIMITER $$

CREATE TRIGGER update_salary_budget_after_delete
AFTER DELETE ON Salaries
FOR EACH ROW
BEGIN
    UPDATE SalaryBudgets
    SET total = (SELECT SUM(salary) FROM Salaries);
END$$

DELIMITER ;
