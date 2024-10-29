-- Name : Purval Madhukar Bhude
-- Roll no. S20230010193
-- Question 1

create database s20230010193_lab6;

USE s20230010193_lab6;
CREATE TABLE employee(
	emp_id int, 
    emp_name varchar(20), 
    emp_dept varchar(20),
	emp_age int, 
    place varchar(20), 
    income int, 
    doj date);
    
select * from employee;

-- Part 1
select emp_name,doj from employee where emp_dept = (select distinct emp_dept from employee where emp_name = 'Mark') and emp_name != 'Mark';

-- Part 2
select emp_id,emp_name from employee where income>(select avg(income) from employee) order by income desc;

-- Part 3
select emp_id,emp_name from employee where emp_dept in (select emp_dept from employee where emp_name like '%n%');

-- Part 4
select emp_id,emp_name,emp_dept from employee where place='India';

-- Part 5
SELECT MAX(income) as second_highest_income FROM employee WHERE income < (SELECT MAX(income) FROM employee);