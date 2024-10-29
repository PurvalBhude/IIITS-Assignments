Create database business;
show databases;

use business;
create table employee (
	emp_no int NOT NULL,
    emp_name varchar(25), 
    doj date,
    ph_no varchar(10), 
    dept_name varchar(25), 
    designation varchar(25),
    salary int,
    gender char
    );
    
INSERT INTO employee (emp_no, emp_name, doj, ph_no, dept_name, designation, salary, gender) VALUES
(1234, 'Sarala', '2020-01-02', '9444123456', 'Sales', 'HR', 70000, 'F'),
(3452, 'Amogh', '2019-01-01', '9464123456', 'Sales', 'Sales manager', 72000, 'M'),
(4312, 'Qasim', '2019-04-01', '9444123423', 'Sales', 'Sales representative', 7000, 'M'),
(4112, 'Swathi', '2019-04-23', NULL, 'Sales', 'Typist', 3300, 'F'),
(6693, 'Manoj', '2019-03-01', '9444125357', 'HR', 'Marketing', 17000, 'M'),
(4345, 'Devi kumar', '2020-01-01', '9448563456', 'HR', 'HR', 70000, 'F'),
(5744, 'Hari dev', '2019-03-01', '9464893456', 'Marketing', 'Receptionist', 2000, 'M'),
(7899, 'William Jane', '2019-04-12', NULL, 'Marketing', 'Typist', 4000, 'F'),
(3451, 'Dennis', '2019-11-01', '8244125357', 'Marketing', 'Sales representative', 7000, 'M'),
(2399, 'Govind', '2019-03-01', '8346123423', 'Accounts', 'Typist', 4500, 'M'),
(4599, 'Dhanad', '2019-04-02', '8456123423', 'Accounts', 'Typist', 4000, 'M'),
(2399, 'Khurana', '2019-03-01', '9448903423', 'Accounts', 'CA', 14500, 'M'),
(4599, 'Suraj', '2019-04-02', '9426123423', 'Accounts', 'CA', 46000, 'M');

select * from employee;

-- question 3,4
INSERT INTO employee (emp_no, emp_name, doj, ph_no, dept_name, designation, salary, gender) VALUES
(5678, 'Advait', '2021-05-10', '9444126789', 'Sales', 'Sales manager', 75000, 'M'),
(6789, 'Yash', '2021-06-15', '9444127890', 'HR', 'HR', 72000, 'F'),
(7890, 'Vedant', '2021-07-20', '9444128901', 'Marketing', 'Sales representative', 68000, 'M'),
(8901, 'Peeyush', '2021-08-25', '9444129012', 'Accounts', 'CA', 80000, 'F'),
(9012, 'Purval', '2021-09-30', '9444120123', 'Marketing', 'Receptionist', 30000, 'M');

-- question 5
select emp_no,emp_name from employee where dept_name like "%s";

-- question 6
select emp_no,emp_name from employee where salary>2000 && salary<5000;

-- question 7
select * from employee where dept_name like "sales%";

-- question 8
update employee set salary=25000 where designation="Typist";
select * from employee;

-- question 9 (chaning phone number of empolyee name purval)
update employee set ph_no="7768961151" where emp_name="Purval";
select * from employee;

-- question 10 
update employee set salary=salary*1.15 where designation = "Receptionist";
select * from employee;

-- question 11
select * from employee where ph_no is null;

-- question 12
delete from employee where salary>7000;
select * from employee;

-- question 13
truncate table employee;
select * from employee;

-- question 14 
describe employee;