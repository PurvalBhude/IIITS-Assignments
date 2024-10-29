create database lab5;

use lab5;
create table small_customers(
	id smallint,
	name varchar(10),
    age smallint,
    address varchar(15),
    salary int
);

create table small_customers2(
	id smallint,
    name varchar(10),
    age smallint,
    address varchar(15),
    salary int
);

create table orders (
	oid int,
    date datetime,
    customer_id smallint,
    amount int
);

-- uploaded through workbench

select * from orders;
select * from small_customers;

-- with select
SELECT * FROM small_customers
WHERE ID IN (SELECT ID FROM small_customers WHERE SALARY > 4500);

-- with insert
INSERT INTO small_customers2
SELECT * FROM small_customers
WHERE ID IN (SELECT ID FROM small_customers) ;

-- with update
UPDATE small_customers
SET SALARY = SALARY * 0.25
WHERE AGE IN (SELECT AGE FROM small_customers2 WHERE AGE >= 27);

-- with delete
DELETE FROM small_customers
WHERE AGE IN (SELECT AGE FROM small_customers2 WHERE AGE >= 27);

-- CArtesian PRoduct
SELECT ID, NAME, AMOUNT, DATE FROM small_customers, orders;
SELECT count(*) FROM small_customers, orders;
alter table orders change column oid id smallint;
Select small_customers.id,name,orders.id from small_customers, orders;

-- rename operation
Select small_customers.id as customer_id,name,orders.id as order_id from small_customers,orders;
Select s.id,name,o.id from small_customers as s, orders as o;

-- Test for empty relations
Select Name from small_customers WHERE NOT EXISTS (SELECT * FROM orders WHERE small_customers.id = orders.customer_id); 