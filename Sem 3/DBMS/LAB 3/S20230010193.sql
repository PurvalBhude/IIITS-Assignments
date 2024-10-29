show databases;

use business;
create table products(
	ProductID int,
    CustomerID int,
    ProductName varchar(20),
    Availability varchar(20),
    Price int
);

create table customers(
	CustomerID int,
    Dateofbirth date,
    Gender varchar(5),
    CustomerName varchar(30),
    City varchar(20),
    Country varchar(10)
);

INSERT INTO customers (CustomerID, Dateofbirth, Gender, CustomerName, City, Country)
VALUES 
(12, '1996-11-10', 'm', 'Monk', 'Hyderabad', 'India'),
(15, '1972-08-10', 'f', 'Mars', 'Goa', 'India'),
(20, '1966-03-29', 'f', 'Johny', 'Paris', 'France'),
(25, '1944-03-10', 'm', 'Mans', 'Hamburg', 'Germany'),
(125, '1999-12-10', 'm', 'Maggie', 'Delhi', 'India'),
(150, '1991-12-10', 'f', 'Don', 'Oslo', 'Norway'),
(200, '1968-11-29', 'f', 'lambie', 'Paris','france'),
(1000, '1989-10-10', 'm', 'John', 'Delhi', 'India'),
(1100, '1979-01-10', 'f', 'Kens', 'Berlin', 'Germany'),
(1105, '1989-10-10', 'm', 'Manish', 'Delhi', 'India'),
(1106, '1979-01-10', 'm', 'Kensive', 'Berlin', 'Germany'),
(1205, '1998-11-10', 'm', 'Monk', 'Delhi', 'India'),
(1259, '1999-12-10', 'f', 'Maggie', 'Delhi', 'India'),
(1507, '1992-08-10', 'f', 'Mars', 'Oslo', 'Norway'),
(2004, '1966-03-10', 'm', 'Johny', 'Paris', 'France'),
(2505, '1960-03-10', 'f', 'Kelvin', 'Hamburg', 'Germany');

select * from customers;

insert into products(ProductID,CustomerID,ProductName,Availability,Price)
values
(1,1000,"pen","yes",100),
(2,1100,"toy","no",10),
(3,2505,"pencil","yes",30),
(4,150,"duck","yes",50),
(6,1105,"hat","yes",10),
(7,200,"pot","no",90),
(9,2505,"chalk","no",10);

select * from products;

-- Question 1
ALTER TABLE customers ADD PRIMARY KEY (CustomerID);
desc customers;

-- Question 2
alter table products add foreign key (CustomerID) references customers(CustomerID);
desc products;
-- Question 3
alter table products modify column Availability varchar(10) NOT NULL default "yes";
desc products;

-- Question 4
select * from customers where CustomerName like "%or%";

-- Question 5
insert into products(ProductID,CustomerID,ProductName,Availability,Price)
values (10,2505,"pencil","yes",10);
select * from products;

-- Question 6 
select * from customers where Country like "Germany" && City like "Berlin";

-- Question 7 
select * from customers where Country not like "Germany";

-- Question 8
select * from customers where City like "a%";

-- Question 9
select * from customers where City like "a%b";

-- Question 10
select * from customers where City not like "a%";

-- Question 11 
select * from customers where City like "a%" || City like "c%" || City like "s%";

-- Question 12 
SELECT * FROM customers WHERE City LIKE 'a%' || 
						city like "b%" ||
						city like "c%" ||
						city like "d%" ||
						city like "e%" ||
						city like "f%";

-- Question 13 
select * from customers where Country not like "Norway" && Country not like "France";

-- Question 14
SELECT * FROM products WHERE ProductName BETWEEN 'Hat' AND 'Pen';

-- Question 15
select * from products where price>=50 && price<=100;

-- Question 16
SELECT * FROM information_schema.TABLE_CONSTRAINTS;
alter table products drop foreign key products_ibfk_1;
alter table customers drop primary key;
desc products;
desc customers;	

-- Question 17
delete from customers where Country like "Brazil" and City like "Victoria";

-- Question 18
select * from products where price=50;

-- Question 19
select * from customers where City not like "Delhi" and City not like "Hamburg";

-- Question 20
select * from customers where Dateofbirth <="2003-01-01";


