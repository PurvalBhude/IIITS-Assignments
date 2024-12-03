create database S20230010193_lab11;

use S20230010193_lab11;

create table classroom
(building varchar(15),
room_number varchar(7),
capacity numeric(4,0),
primary key (building, room_number)
);
create table department
(dept_name varchar(20),
building varchar(15),
budget numeric(12,2) check (budget > 0),
primary key (dept_name)
);
create table course
(course_id varchar(8),
title varchar(50),
dept_name varchar(20),
credits numeric(2,0) check (credits > 0),
primary key (course_id),
foreign key (dept_name) references department (dept_name)
on delete set null
);
create table instructor
(ID varchar(5),
name varchar(20) not null,
dept_name varchar(20),
salary numeric(8,2) check (salary > 29000),
primary key (ID),
foreign key (dept_name) references department (dept_name)
on delete set null
);
create table section
(course_id varchar(8),
sec_id varchar(8),
semester varchar(6)
check (semester in ('Fall', 'Winter', 'Spring', 'Summer')),
year numeric(4,0) check (year > 1701 and year < 2100), building varchar(15),
room_number varchar(7),
time_slot_id varchar(4),
primary key (course_id, sec_id, semester, year),
foreign key (course_id) references course (course_id)
on delete cascade,
foreign key (building, room_number) references classroom (building, room_number)
on delete set null
);
create table teaches
(ID varchar(5),
course_id varchar(8),
sec_id varchar(8),
semester varchar(6),

year numeric(4,0),
primary key (ID, course_id, sec_id, semester, year),
foreign key (course_id, sec_id, semester, year) references section (course_id, sec_id, semester, year)
on delete cascade,
foreign key (ID) references instructor (ID)
on delete cascade
);
create table student
(ID varchar(5),
name varchar(20) not null,
dept_name varchar(20),
tot_cred numeric(3,0) check (tot_cred >= 0),
primary key (ID),
foreign key (dept_name) references department (dept_name)
on delete set null
);
create table takes
(ID varchar(5),
course_id varchar(8),
sec_id varchar(8),
semester varchar(6),
year numeric(4,0),
grade varchar(2),
primary key (ID, course_id, sec_id, semester, year),
foreign key (course_id, sec_id, semester, year) references section (course_id, sec_id, semester, year)
on delete cascade,
foreign key (ID) references student (ID)
on delete cascade
);
create table advisor
(s_ID varchar(5),
i_ID varchar(5),
primary key (s_ID),
foreign key (i_ID) references instructor (ID)
on delete set null,
foreign key (s_ID) references student (ID)
on delete cascade
);
create table time_slot
(time_slot_id varchar(4),
day varchar(1),
start_hr numeric(2) check (start_hr >= 0 and start_hr < 24),
start_min numeric(2) check (start_min >= 0 and start_min < 60),
end_hr numeric(2) check (end_hr >= 0 and end_hr < 24),
end_min numeric(2) check (end_min >= 0 and end_min < 60),
primary key (time_slot_id, day, start_hr, start_min)
);
create table prereq
(course_id varchar(8),

prereq_id varchar(8),
primary key (course_id, prereq_id),
foreign key (course_id) references course (course_id)
on delete cascade,
foreign key (prereq_id) references course (course_id)
);

INSERT INTO classroom VALUES ('Packard', '101', '500');
INSERT INTO classroom VALUES ('Painter', '514', '10');
INSERT INTO classroom VALUES ('Taylor', '3128', '70');
INSERT INTO classroom VALUES ('Watson', '100', '30');
INSERT INTO classroom VALUES ('Watson', '120', '50');

INSERT INTO department VALUES ('Biology', 'Watson', '90000');
INSERT INTO department VALUES ('Comp. Sci.', 'Taylor', '100000');
INSERT INTO department VALUES ('Elec. Eng.', 'Taylor', '85000');
INSERT INTO department VALUES ('Finance', 'Painter', '120000');
INSERT INTO department VALUES ('History', 'Painter', '50000');
INSERT INTO department VALUES ('Music', 'Packard', '80000');
INSERT INTO department VALUES ('Physics', 'Watson', '70000');


INSERT INTO instructor VALUES ('10101', 'Srinivasan', 'Comp. Sci.', '65000');
INSERT INTO instructor VALUES ('12121', 'Wu', 'Finance', '90000');
INSERT INTO instructor VALUES ('15151', 'Mozart', 'Music', '40000');
INSERT INTO instructor VALUES ('22222', 'Einstein', 'Physics', '95000');
INSERT INTO instructor VALUES ('32343', 'El Said', 'History', '60000');
INSERT INTO instructor VALUES ('33456', 'Gold', 'Physics', '87000');
INSERT INTO instructor VALUES ('45565', 'Katz', 'Comp. Sci.', '75000');
INSERT INTO instructor VALUES ('58583', 'Califieri', 'History', '62000');
INSERT INTO instructor VALUES ('76543', 'Singh', 'Finance', '80000');
INSERT INTO instructor VALUES ('76766', 'Crick', 'Biology', '72000');
INSERT INTO instructor VALUES ('83821', 'Brandt', 'Comp. Sci.', '92000');
INSERT INTO instructor VALUES ('98345', 'Kim', 'Elec. Eng.', '80000');


INSERT INTO course VALUES ('BIO-101', 'Intro. to Biology', 'Biology', '4');
INSERT INTO course VALUES ('BIO-301', 'Genetics', 'Biology', '4');
INSERT INTO course VALUES ('BIO-399', 'Computational Biology', 'Biology', '3');
INSERT INTO course VALUES ('CS-101', 'Intro. to Computer Science', 'Comp. Sci.', '4');
INSERT INTO course VALUES ('CS-190', 'Game Design', 'Comp. Sci.', '4');
INSERT INTO course VALUES ('CS-315', 'Robotics', 'Comp. Sci.', '3');
INSERT INTO course VALUES ('CS-319', 'Image Processing', 'Comp. Sci.', '3');
INSERT INTO course VALUES ('CS-347', 'Database System Concepts', 'Comp. Sci.', '3');
INSERT INTO course VALUES ('EE-181', 'Intro. to Digital Systems', 'Elec. Eng.', '3');
INSERT INTO course VALUES ('FIN-201', 'Investment Banking', 'Finance', '3');
INSERT INTO course VALUES ('HIS-351', 'World History', 'History', '3');
INSERT INTO course VALUES ('MU-199', 'Music Video Production', 'Music', '3');
INSERT INTO course VALUES ('PHY-101', 'Physical Principles', 'Physics', '4');



insert into section values ('BIO-101', '1', 'Summer',
'2009', 'Painter', '514', 'B'); insert into section values ('BIO-301', '1', 'Summer',
'2010', 'Painter', '514', 'A'); insert into section values ('CS-101', '1', 'Fall', '2009',
'Packard', '101', 'H'); insert into section values ('CS-101', '1', 'Spring', '2010',
'Packard', '101', 'F'); insert into section values ('CS-190', '1', 'Spring', '2009',
'Taylor', '3128', 'E'); insert into section values ('CS-190', '2', 'Spring', '2009',
'Taylor', '3128', 'A'); insert into section values ('CS-315', '1', 'Spring', '2010',
'Watson', '120', 'D'); insert into section values ('CS-319', '1', 'Spring', '2010',
'Watson', '100', 'B'); insert into section values ('CS-319', '2', 'Spring', '2010',
'Taylor', '3128', 'C'); insert into section values ('CS-347', '1', 'Fall', '2009', 'Taylor',

'3128', 'A'); insert into section values ('EE-181', '1', 'Spring', '2009', 'Taylor',
'3128', 'C'); insert into section values ('FIN-201', '1', 'Spring', '2010', 'Packard',
'101', 'B');
insert into section values ('HIS-351', '1', 'Spring', '2010', 'Painter', '514', 'C');
insert into section values ('MU-199', '1', 'Spring', '2010', 'Packard', '101', 'D');
insert into section values ('PHY-101', '1', 'Fall', '2009', 'Watson', '100', 'A');
insert into teaches values ('10101', 'CS-101', '1', 'Fall', '2009'); insert into
teaches values ('10101', 'CS-315', '1', 'Spring', '2010'); insert into teaches
values ('10101', 'CS-347', '1', 'Fall', '2009'); insert into teaches values
('12121', 'FIN-201', '1', 'Spring', '2010'); insert into teaches values ('15151',
'MU-199', '1', 'Spring', '2010'); insert into teaches values ('22222', 'PHY-101',
'1', 'Fall', '2009'); insert into teaches values ('32343', 'HIS-351', '1', 'Spring',
'2010'); insert into teaches values ('45565', 'CS-101', '1', 'Spring', '2010');
insert into teaches values ('45565', 'CS-319', '1', 'Spring', '2010'); insert into
teaches values ('76766', 'BIO-101', '1', 'Summer', '2009'); insert into teaches
values ('76766', 'BIO-301', '1', 'Summer', '2010'); insert into teaches values
('83821', 'CS-190', '1', 'Spring', '2009'); insert into teaches values ('83821',
'CS-190', '2', 'Spring', '2009'); insert into teaches values ('83821', 'CS-319',
'2', 'Spring', '2010'); insert into teaches values ('98345', 'EE-181', '1', 'Spring',
'2009'); insert into student values ('00128', 'Zhang', 'Comp. Sci.', '102'); insert
into student values ('12345', 'Shankar', 'Comp. Sci.', '32'); insert into student
values ('19991', 'Brandt', 'History', '80'); insert into student values ('23121',
'Chavez', 'Finance', '110'); insert into student values ('44553', 'Peltier',
'Physics', '56'); insert into student values ('45678', 'Levy', 'Physics', '46');
insert into student values ('54321', 'Williams', 'Comp. Sci.', '54');
insert into student values ('55739', 'Sanchez', 'Music', '38');
insert into student values ('70557', 'Snow', 'Physics', '0');
insert into student values ('76543', 'Brown', 'Comp. Sci.', '58'); insert
into student values ('76653', 'Aoi', 'Elec. Eng.', '60'); insert into student
values ('98765', 'Bourikas', 'Elec. Eng.', '98'); insert into student values
('98988', 'Tanaka', 'Biology', '120'); insert into takes values ('00128',
'CS-101', '1', 'Fall', '2009', 'A'); insert into takes values ('00128',
'CS-347', '1', 'Fall', '2009', 'A-'); insert into takes values ('12345',
'CS-101', '1', 'Fall', '2009', 'C'); insert into takes values ('12345',
'CS-190', '2', 'Spring', '2009', 'A'); insert into takes values ('12345',
'CS-315', '1', 'Spring', '2010', 'A'); insert into takes values ('12345',
'CS-347', '1', 'Fall', '2009', 'A'); insert into takes values ('19991',
'HIS-351', '1', 'Spring', '2010', 'B'); insert into takes values ('23121',
'FIN-201', '1', 'Spring', '2010', 'C+'); insert into takes values ('44553',
'PHY-101', '1', 'Fall', '2009', 'B-'); insert into takes values ('45678',
'CS-101', '1', 'Fall', '2009', 'F'); insert into takes values ('45678',
'CS-101', '1', 'Spring', '2010', 'B+'); insert into takes values ('45678',
'CS-319', '1', 'Spring', '2010', 'B'); insert into takes values ('54321',
'CS-101', '1', 'Fall', '2009', 'A-'); insert into takes values ('54321',
'CS-190', '2', 'Spring', '2009', 'B+'); insert into takes values ('55739',
'MU-199', '1', 'Spring', '2010', 'A-'); insert into takes values ('76543',
'CS-101', '1', 'Fall', '2009', 'A'); insert into takes values ('76543',
'CS-319', '2', 'Spring', '2010', 'A'); insert into takes values ('76653',
'EE-181', '1', 'Spring', '2009', 'C'); insert into takes values ('98765',
'CS-101', '1', 'Fall', '2009', 'C-'); insert into takes values ('98765',
'CS-315', '1', 'Spring', '2010', 'B'); insert into takes values ('98988',
'BIO-101', '1', 'Summer', '2009', 'A'); insert into takes values ('98988',
'BIO-301', '1', 'Summer', '2010', null); insert into advisor values
('00128', '45565');

insert into advisor values ('12345', '10101');
insert into advisor values ('23121', '76543');
insert into advisor values ('44553', '22222'); insert
into advisor values ('45678', '22222'); insert into
advisor values ('76543', '45565'); insert into advisor
values ('76653', '98345'); insert into advisor values
('98765', '98345'); insert into advisor values
('98988', '76766'); insert into time_slot values ('A',
'M', '8', '0', '8', '50');
insert into time_slot values ('A', 'W', '8', '0', '8', '50');
insert into time_slot values ('A', 'F', '8', '0', '8', '50');
insert into time_slot values ('B', 'M', '9', '0', '9', '50');
insert into time_slot values ('B', 'W', '9', '0', '9', '50');
insert into time_slot values ('B', 'F', '9', '0', '9', '50');
insert into time_slot values ('C', 'M', '11', '0', '11', '50');
insert into time_slot values ('C', 'W', '11', '0', '11', '50');
insert into time_slot values ('C', 'F', '11', '0', '11', '50');
insert into time_slot values ('D', 'M', '13', '0', '13', '50');
insert into time_slot values ('D', 'W', '13', '0', '13', '50');
insert into time_slot values ('D', 'F', '13', '0', '13', '50');
insert into time_slot values ('E', 'T', '10', '30', '11', '45 ');
insert into time_slot values ('E', 'R', '10', '30', '11', '45 ');
insert into time_slot values ('F', 'T', '14', '30', '15', '45 ');
insert into time_slot values ('F', 'R', '14', '30', '15', '45 ');
insert into time_slot values ('G', 'M', '16', '0', '16', '50');
insert into time_slot values ('G', 'W', '16', '0', '16', '50');
insert into time_slot values ('G', 'F', '16', '0', '16', '50');
insert into time_slot values ('H', 'W', '10', '0', '12', '30');
insert into prereq values ('BIO-301', 'BIO-101');
insert into prereq values ('BIO-399', 'BIO-101');
insert into prereq values ('CS-190', 'CS-101');
insert into prereq values ('CS-315', 'CS-101');
insert into prereq values ('CS-319', 'CS-101');
insert into prereq values ('CS-347', 'CS-101');
insert into prereq values ('EE-181', 'PHY-101');



-- Question 1
-- Part A
SELECT title FROM course WHERE dept_name = 'Comp. Sci.' AND credits = 3;


-- Part b
SELECT DISTINCT takes.ID
FROM takes
JOIN teaches ON takes.course_id = teaches.course_id AND takes.sec_id = teaches.sec_id AND takes.semester = teaches.semester AND takes.year = teaches.year
JOIN instructor ON teaches.ID = instructor.ID
WHERE instructor.name = 'Einstein';

-- Part c
SELECT MAX(salary) AS highest_salary
FROM instructor;

-- Part d
SELECT name, salary
FROM instructor
WHERE salary = (SELECT MAX(salary) FROM instructor);

-- Part e
SELECT section.course_id, section.sec_id, COUNT(takes.ID) AS enrollment
FROM section
LEFT JOIN takes ON section.course_id = takes.course_id AND section.sec_id = takes.sec_id AND section.semester = takes.semester AND section.year = takes.year
WHERE section.semester = 'Autumn' AND section.year = 2009
GROUP BY section.course_id, section.sec_id;

-- Part f 
SELECT MAX(enrollment) AS max_enrollment
FROM (
    SELECT COUNT(takes.ID) AS enrollment
    FROM section
    LEFT JOIN takes ON section.course_id = takes.course_id AND section.sec_id = takes.sec_id AND section.semester = takes.semester AND section.year = takes.year
    WHERE section.semester = 'Autumn' AND section.year = 2009
    GROUP BY section.course_id, section.sec_id
) AS subquery;


-- Part g
WITH SectionEnrollment AS (
    SELECT section.course_id, section.sec_id, COUNT(takes.ID) AS enrollment
    FROM section
    LEFT JOIN takes ON section.course_id = takes.course_id AND section.sec_id = takes.sec_id AND section.semester = takes.semester AND section.year = takes.year
    WHERE section.semester = 'Autumn' AND section.year = 2009
    GROUP BY section.course_id, section.sec_id
)
SELECT course_id, sec_id
FROM SectionEnrollment
WHERE enrollment = (SELECT MAX(enrollment) FROM SectionEnrollment);

                          
                          
-- Question 2
-- Part a
UPDATE instructor
SET salary = salary * 1.10
WHERE dept_name = 'Comp. Sci.';

-- Part b
DELETE FROM course
WHERE course_id NOT IN (SELECT DISTINCT course_id FROM section);

-- Part c
INSERT INTO instructor (ID, name, dept_name, salary)
SELECT s.ID, s.name, s.dept_name, 10000
FROM student s
WHERE s.tot_cred > 100;


-- Question 3
SELECT dept_name
FROM department
WHERE LOWER(dept_name) LIKE '%sci%';

-- Question 4 
-- Part a
SELECT i.ID, i.name, COUNT(t.course_id) AS num_sections
FROM instructor i
LEFT OUTER JOIN teaches t
    ON i.ID = t.ID
GROUP BY i.ID, i.name;

-- Part b
SELECT i.ID, i.name, 
       (SELECT COUNT(*)
        FROM teaches t
        WHERE t.ID = i.ID) AS num_sections
FROM instructor i;

-- Part c
SELECT s.course_id, s.sec_id, s.semester, s.year, 
       COALESCE(i.name, '—') AS instructor_name
FROM section s
LEFT JOIN teaches t ON s.course_id = t.course_id AND s.sec_id = t.sec_id AND s.semester = t.semester AND s.year = t.year
LEFT JOIN instructor i ON t.ID = i.ID
WHERE s.semester = 'Spring' AND s.year = 2010;

-- Part d
SELECT d.dept_name, COUNT(i.ID) AS num_instructors
FROM department d
LEFT JOIN instructor i ON d.dept_name = i.dept_name
GROUP BY d.dept_name;


-- Question 5 
-- Part a
SELECT student.*, takes.*
FROM student
LEFT JOIN takes ON student.ID = takes.ID;

-- Part b
SELECT student.*, takes.*
FROM student
LEFT JOIN takes ON student.ID = takes.ID
UNION
SELECT student.*, takes.*
FROM student
RIGHT JOIN takes ON student.ID = takes.ID;



-- Question 6 
DELIMITER //
CREATE TRIGGER CheckLoanLimit
BEFORE INSERT ON BankCustomers
FOR EACH ROW
BEGIN
    IF NEW.loan > 1000000 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Loan amount exceeds 10 lakhs';
    END IF;
END; //
DELIMITER ;


-- Question 7 
DELIMITER //
CREATE PROCEDURE HandleDuplicateKey()
BEGIN
    DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
        ROLLBACK;
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Duplicate key error';
    END;
    -- Count the number of majors (assuming a condition for being a major)
    SELECT COUNT(*) AS num_majors
    FROM BankCustomers
    WHERE age >= 18;
END; //
DELIMITER ;

-- Question 8 
-- trigger 1
CREATE TRIGGER UpdateTotalAssets
AFTER DELETE ON account
FOR EACH ROW
BEGIN
    UPDATE branch
    SET total_assets = total_assets - OLD.balance
    WHERE branch.branch_name = OLD.branch_name;
END;


-- Trigger 2
CREATE TRIGGER UpdateDepositor
AFTER DELETE ON account
FOR EACH ROW
BEGIN
    DELETE FROM depositor WHERE account_number = OLD.account_number;
END;



-- Question 9
CREATE TABLE EmployeePosition (
    Emp_id VARCHAR(5) PRIMARY KEY,
    Emp_name VARCHAR(50),
    Position VARCHAR(20)
);


CREATE OR REPLACE FUNCTION assign_position(emp_id IN VARCHAR, emp_name IN VARCHAR, experience IN NUMBER) 
RETURNS VOID IS
BEGIN
    -- Declare a variable to store the position
    DECLARE position VARCHAR(20);
    
    -- Assign the position based on the experience
    IF experience > 25 THEN
        position := 'Senior Executive';
    ELSIF experience > 10 THEN
        position := 'Executive';
    ELSIF experience > 5 THEN
        position := 'Senior Analyst';
    ELSE
        position := 'Analyst';
    END IF;

    -- Insert the employee's position into the EmployeePosition table
    INSERT INTO EmployeePosition (Emp_id, Emp_name, Position)
    VALUES (emp_id, emp_name, position);
    
    COMMIT;
END;
/


-- Question 10 

CREATE OR REPLACE TRIGGER after_employee_insert
AFTER INSERT ON Employee
FOR EACH ROW
BEGIN
    -- Call the function to assign position after an employee is inserted
    -- Use :NEW to reference the new row's values
    assign_position(:NEW.Emp_id, :NEW.Emp_name, :NEW.experience);
END;
/

  
