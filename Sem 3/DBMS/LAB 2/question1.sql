create database DB;
show databases;

USE DB;
create table Customer (
	Cust_ID varchar(5) NOT NULL,
    name varchar(30),
    city varchar(15),
    state varchar(15),
    pincode int(6),
    products varchar(40),
    price int(10)
    );

insert into Customer (Cust_ID, name, city, state,pincode,products,price)
values("C101","Alex William","Indore","Madhya Pradesh",452013,"chair",4000);

insert into Customer (Cust_ID, name, city, state,pincode,products,price)
values("C102","Alex William","Pune","Maharashtra",652016,"table",8000);

insert into Customer (Cust_ID, name, city, state,pincode,products,price)
values("C103","V.Iyer","Chennai","Tamil Nadu",752716,"table",8001);

insert into Customer (Cust_ID, name, city, state,pincode,products,price)
values("C104","L.Laxmi","Chennai","Tamil Nadu",752717,"doll",200);

insert into Customer (Cust_ID, name, city, state,pincode,products,price)
values("C105","Ravi Teja","Hyderabad","Telangana",252727,"doll",250);

insert into Customer (Cust_ID, name, city, state,pincode,products,price)
values("C106","Raj Kumar","Delhi","Delhi",151127,"cricket kit",5250);

insert into Customer (Cust_ID, name, city, state,pincode,products,price)
values("C107","Tuner Bond","Bhopal","Madhya Pradesh",451127,"football kit",3250);

insert into Customer (Cust_ID, name, city, state,pincode,products,price)
values("C108","Nikhil Yadav","Chennai","Tamil Nadu",751127,"football kit",6250);

insert into Customer (Cust_ID, name, city, state,pincode,products,price)
values("C109","John","Mumbai","Maharashtra",651127,"football kit",6255);

Select * from customer;
-- question 1
select distinct name from customer;
-- question 2
select name,city from customer;
-- question 3
select products from customer where products like 'd%';
-- question 4
select Cust_ID from customer where city like 'Chennai%';
-- question 5
select * from customer where Cust_ID in ('C108','C104');
-- question 6
select products from customer where price > 5000;
-- question 7
select Cust_ID from customer where city in ('Hyderbad','pune','Delhi');
-- question 8
select products from customer where price>2000 && price<5000;
-- question 9
select name,city,state from customer where state not in ('Tamil Nadu');
-- question 10
update customer set name='johney' where name='john';
select * from customer;