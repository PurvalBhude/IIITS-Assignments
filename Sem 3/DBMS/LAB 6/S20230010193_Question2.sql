-- Name : Purval Madhukar Bhude
-- Roll no. S20230010193
-- Question 2

USE s20230010193_lab6;

CREATE TABLE Sailors (
    sid INTEGER PRIMARY KEY,
    sname VARCHAR(100),
    rating INTEGER,
    age REAL
);

CREATE TABLE Boats (
    bid INTEGER PRIMARY KEY,
    bname VARCHAR(100),
    color VARCHAR(50)
);

CREATE TABLE Reserves (
    sid INTEGER,
    bid INTEGER,
    day DATE,
    FOREIGN KEY (sid) REFERENCES Sailors(sid),
    FOREIGN KEY (bid) REFERENCES Boats(bid)
);

INSERT INTO Sailors (sid, sname, rating, age) VALUES (22, 'Dustin', 7, 45);
INSERT INTO Sailors (sid, sname, rating, age) VALUES (29, 'Brutus', 1, 33);
INSERT INTO Sailors (sid, sname, rating, age) VALUES (31, 'Lubber', 8, 55.5);
INSERT INTO Sailors (sid, sname, rating, age) VALUES (32, 'Andy', 8, 25.5);
INSERT INTO Sailors (sid, sname, rating, age) VALUES (58, 'Rusty', 10, 35);
INSERT INTO Sailors (sid, sname, rating, age) VALUES (64, 'Horatio', 7, 35);
INSERT INTO Sailors (sid, sname, rating, age) VALUES (71, 'Zorba', 10, 16);
INSERT INTO Sailors (sid, sname, rating, age) VALUES (74, 'Horatio', 9, 40);
INSERT INTO Sailors (sid, sname, rating, age) VALUES (85, 'Art', 3, 25.5);
INSERT INTO Sailors (sid, sname, rating, age) VALUES (95, 'Bob', 3, 63.5);

INSERT INTO Boats (bid, bname, color) VALUES (101, 'Interlake', 'blue');
INSERT INTO Boats (bid, bname, color) VALUES (102, 'Interlake', 'red');
INSERT INTO Boats (bid, bname, color) VALUES (103, 'Clipper', 'green');
INSERT INTO Boats (bid, bname, color) VALUES (104, 'Marine', 'red');

INSERT INTO Reserves (sid, bid, day) VALUES (22, 101, '1998-10-10');
INSERT INTO Reserves (sid, bid, day) VALUES (22, 102, '1998-10-10');
INSERT INTO Reserves (sid, bid, day) VALUES (22, 103, '1998-10-08');
INSERT INTO Reserves (sid, bid, day) VALUES (22, 104, '1998-10-07');
INSERT INTO Reserves (sid, bid, day) VALUES (31, 102, '1998-11-10');
INSERT INTO Reserves (sid, bid, day) VALUES (31, 103, '1998-11-06');
INSERT INTO Reserves (sid, bid, day) VALUES (31, 104, '1998-11-12');
INSERT INTO Reserves (sid, bid, day) VALUES (64, 101, '1998-09-05');
INSERT INTO Reserves (sid, bid, day) VALUES (64, 102, '1998-09-08');
INSERT INTO Reserves (sid, bid, day) VALUES (74, 103, '1998-09-08');

-- Part 1
SELECT *
FROM Sailors
WHERE sid IN (
    SELECT sid
    FROM Reserves
    WHERE bid = 101
);


-- Part 2
select Boats.bname from reserves
join sailors on sailors.sid = reserves.sid
join boats on boats.bid = reserves.bid
where sailors.sname="Bob";
-- nested
select bid,bname from boats 
where bid in (select bid from reserves where sid in (select sid from sailors where sname="Bob"));

-- Part 3
select distinct sailors.sname,sailor.sid from reserves
join sailors on sailors.sid = reserves.sid
join boats on boats.bid = reserves.bid
where boats.color='red'
order by sailors.age;
-- nested
select distinct sname,sid from sailors 
where sid in (select sid from Reserves where bid in (select bid from Boats where color="red"));

-- Part 4
select distinct sailors.sname,sailors.sid from sailors
join reserves on sailors.sid=reserves.sid;
-- nested
select distinct sid,sname from sailors
where sid in (select sid from reserves);

-- Part 5
select distinct sid,sname from sailors 
where sid in (select a.sid from reserves a,reserves b where a.bid!=b.bid and a.day=b.day and a.sid=b.sid);

-- Part 6
select distinct sid from sailors 
where sid in (select sid from reserves where bid in (select bid from boats where color="green" or color="red"));

-- Part 7
select distinct sid,sname,age from sailors 
where age=(select min(age) from sailors);

-- Part 8
select count(distinct sname) from sailors;

-- Part 9
select distinct rating,avg(age) from sailors group by rating order by rating;

-- Part 10
select rating,avg(age) as avg_age from sailors group by rating having count(sid) >= 2;