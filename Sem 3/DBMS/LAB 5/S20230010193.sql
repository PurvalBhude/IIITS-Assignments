create database S20230010193_lab5;

use S20230010193_lab5;

Create table customer (
	customer_name char(20),
    customer_street char(30),
    customer_city char(30),
    PRIMARY KEY(customer_name)
);

Create table branch (
	branch_name char(15),
    branch_city char(30),
    assets numeric(16,2),
    PRIMARY KEY(branch_name)
);

Create table account (
	account_number char(15),
    branch_name char (15),
    balance numeric(12,2),
    PRIMARY KEY(account_number),
    FOREIGN KEY (branch_name)
	REFERENCES branch(branch_name)
);

Create table depositor(
	customer_name char(20),
    account_number char(10),
    PRIMARY KEY(customer_name,account_number),
    FOREIGN KEY (customer_name) REFERENCES customer(customer_name),
    FOREIGN KEY (account_number) REFERENCES account(account_number)
);

Create table loan(
	loan_number varchar(6),
    branch_name char(15),
    amount int,
    PRIMARY KEY(loan_number),
    FOREIGN KEY (branch_name) REFERENCES branch(branch_name)
);

Create table borrower(
	customer_name char(20),
    loan_number varchar(6),
    PRIMARY KEY(customer_name,loan_number),
    FOREIGN KEY (customer_name) REFERENCES customer(customer_name),
    FOREIGN KEY (loan_number) REFERENCES loan(loan_number)
);


select * from customer;
select * from branch;
select * from account;
select * from depositor;
select * from loan;
select * from borrower;

-- updated the data through workbench

-- Question 1
select * from customer;

-- Question 2
select borrower.customer_name
from borrower
join depositor on depositor.customer_name = borrower.customer_name;

-- Question 3
SELECT DISTINCT b.customer_name
FROM borrower b
LEFT JOIN depositor d ON b.customer_name = d.customer_name
WHERE d.customer_name IS NULL;

-- Question 4
select distinct a.branch_name 
from branch a
join branch b
where a.assets>b.assets && b.branch_city like "Brooklyn";

-- Question 5
SELECT branch_name
FROM branch
WHERE assets > SOME (SELECT assets FROM branch WHERE branch_city = 'Brooklyn');

-- Question 6 
SELECT branch_name
FROM (
    SELECT branch.branch_name, AVG(account.balance) AS avg_balance
    FROM branch
    JOIN account ON account.branch_name = branch.branch_name
    GROUP BY branch.branch_name
) AS branch_avg
ORDER BY avg_balance DESC;


-- Question 7
SELECT DISTINCT customer_name
FROM customer C
WHERE EXISTS (
    SELECT 1
    FROM depositor D
    WHERE D.customer_name = C.customer_name
)
AND EXISTS (
    SELECT 1
    FROM borrower B
    WHERE B.customer_name = C.customer_name
);

-- Question 8
SELECT *
FROM loan
NATURAL JOIN borrower;

-- Question 9
SELECT *
FROM loan
INNER JOIN borrower ON loan.loan_number = borrower.loan_number;


-- Question 10
SELECT *
FROM loan
NATURAL RIGHT JOIN borrower;

-- Question 11 
SELECT *
FROM loan
RIGHT OUTER JOIN borrower ON loan.loan_number = borrower.loan_number;

-- Question 12
SELECT *
FROM loan
NATURAL LEFT JOIN borrower;

-- Question 13
SELECT *
FROM loan
LEFT OUTER JOIN borrower ON loan.loan_number = borrower.loan_number;

-- Question 14
SELECT *
FROM loan
FULL OUTER JOIN borrower ON loan.loan_number = borrower.loan_number;
