-- Name: Purval Madhukar Bhude
-- Roll No. S20230010193
-- Lab 4 (Exercise 1)

Create database lab4;
show databases;
-- drop table employee

use lab4;
CREATE TABLE employee (
    emp_id INT AUTO_INCREMENT PRIMARY KEY,
    emp_name VARCHAR(100),
    emp_dept VARCHAR(50),
    emp_age INT,
    place VARCHAR(100),
    income DECIMAL(10, 2),
    doj date
) AUTO_INCREMENT = 2505;

select * from employee;

-- Question 1
SELECT COUNT(emp_name) FROM employee;

-- Question 2
select emp_dept,max(income) from employee group by emp_dept;
select max(income) from employee;

-- Question 3
select * from employee where income>=100000 && income<=500000 && income!=120000;

-- Question 4 
select count(income>100000) from employee;

-- Question 5 
select * from employee order by income;

-- Question 6
select emp_dept,count(emp_id),max(income) from employee group by emp_dept;

-- Question 7
select place,count(emp_id) from employee group by place;

-- Question 8
select place,count(emp_id) from employee group by place order by count(emp_id); 

-- Question 9
select place,count(emp_id) from employee group by place having count(emp_id)>1 order by count(emp_id);  

-- Question 10
select place,count(emp_id) from employee group by place having count(emp_id)>1&& place not like "California" order by count(emp_id);

