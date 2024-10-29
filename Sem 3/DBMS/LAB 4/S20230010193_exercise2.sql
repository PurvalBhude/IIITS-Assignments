-- Name: Purval Madhukar Bhude
-- Roll No. S20230010193
-- Lab 4 (Exercise 2)

use lab4;

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
-- Question 1 (loaded CSV)

-- Question 2
SELECT customer.customer_name, loan.loan_number, loan.amount 
FROM customer
JOIN borrower ON customer.customer_name = borrower.customer_name
JOIN loan ON borrower.loan_number = loan.loan_number;

-- Question 3
select customer.customer_name, loan.loan_number, loan.amount 
from customer
join borrower on customer.customer_name = borrower.customer_name
join loan on borrower.loan_number = loan.loan_number
where loan.branch_name not like "Perryridge";

-- Question 4
select *
from branch 
where assets>ANY(select assets from branch where branch_city like "Brooklyn");

-- Question 5
select borrower.customer_name
from loan
join borrower on borrower.loan_number = loan.loan_number
where loan.branch_name like "Perryridge"
order by borrower.customer_name;

-- Question 6
select * from loan order by amount desc, loan_number asc;

-- Question 7
select avg(balance) from account;

-- Question 8
select count(customer_name) from customer;

-- Question 9
select sum(amount) from loan;

-- Question 10
select avg(balance) from account where branch_name like "Perryridge";

-- Question 11
select branch_name,avg(balance) from account group by branch_name;

-- Question 12
select branch_name,avg(balance) from account where balance>1200 group by branch_name; 

-- Question 13
select account.branch_name,count(depositor.customer_name)
from depositor
join account on account.account_number = depositor.account_number
group by account.branch_name;

-- Question 14
SELECT depositor.customer_name, AVG(account.balance) AS average_balance
FROM customer
JOIN depositor ON customer.customer_name = depositor.customer_name
JOIN account ON depositor.account_number = account.account_number
WHERE customer.customer_city = 'Harrison'
GROUP BY depositor.customer_name
HAVING COUNT(depositor.account_number) >= 3;
