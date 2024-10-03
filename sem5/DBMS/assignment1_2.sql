CREATE DATABASE "DBMS_lab"
    WITH
    OWNER = postgres
    ENCODING = 'UTF8'
    LOCALE_PROVIDER = 'libc'
    CONNECTION LIMIT = -1
    IS_TEMPLATE = False;



CREATE TABLE Employee (
    First_Name VARCHAR(15),
    Mid_Name CHAR(2),
    Last_Name VARCHAR(15),
    SSN_Number CHAR(9) PRIMARY KEY,
    Birthday DATE,
    Address VARCHAR(50),
    Sex CHAR(1),
    Salary NUMBER(7),
    Supervisor_SSN CHAR(9),
    Department_Number NUMBER(5)
);

CREATE TABLE Department (
    Department_Name VARCHAR(15),
    Department_Number NUMBER(5) PRIMARY KEY,
    ManagerSSN CHAR(9),
    ManageStartDate DATE
);

CREATE TABLE Project (
    Project_Name VARCHAR(15),
    Project_Number NUMBER(5) PRIMARY KEY,
    Location VARCHAR(15),
    Project_Location VARCHAR(15),
    Department_Number NUMBER(5)
);

-- Insert each row separately
INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number)
VALUES ('Doug', 'E', 'Gilbert', '554433221', TO_DATE('09-JUN-60', 'DD-MON-YY'), '11 S 59 E, Salt Lake City, UT', 'M', 80000, NULL, 3);

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number)
VALUES ('Joyce', 'A', 'PAN', '543216789', TO_DATE('07-FEB-78', 'DD-MON-YY'), '35 S 18 E, Salt Lake City, UT', 'F', 70000, NULL, 2);

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number)
VALUES ('Franklin', 'T', 'Wong', '333445555', TO_DATE('08-DEC-45', 'DD-MON-YY'), '638 Voss, Houston, TX', 'M', 40000, '554433221', 5);

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number)
VALUES ('Jennifer', 'S', 'Wallace', '987654321', TO_DATE('20-JUN-31', 'DD-MON-YY'), '291 Berry, Bellaire, TX', 'F', 43000, '554433221', 4);

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number)
VALUES ('John', 'B', 'Smith', '123456789', TO_DATE('09-JAN-55', 'DD-MON-YY'), '731 Fondren, Houston, TX', 'M', 30000, '333445555', 5);

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number)
VALUES ('Ramesh', 'K', 'Narayan', '666884444', TO_DATE('15-SEP-52', 'DD-MON-YY'), '975 Fire Oak, Humble, TX', 'M', 38000, '333445555', 5);

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number)
VALUES ('Joyce', 'A', 'English', '453453453', TO_DATE('31-JUL-62', 'DD-MON-YY'), '5631 Rice, Houston, TX', 'F', 25000, '333445555', 5);

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number)
VALUES ('James', 'E', 'Borg', '888665555', TO_DATE('10-NOV-27', 'DD-MON-YY'), '450 Stone, Houston, TX', 'M', 55000, '543216789', 1);

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number)
VALUES ('Alicia', 'J', 'Zelaya', '999887777', TO_DATE('19-JUL-58', 'DD-MON-YY'), '3321 Castle, Spring, TX', 'F', 25000, '987654321', 4);

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number)
VALUES ('Ahmad', 'V', 'Jabbar', '987987987', TO_DATE('29-MAR-59', 'DD-MON-YY'), '980 Dallas, Houston, TX', 'M', 25000, '987654321', 4);

-- Insert each row separately
INSERT INTO Department (Department_Name, Department_Number, ManagerSSN, ManageStartDate)
VALUES ('Manufacture', 1, '888665555', TO_DATE('19-JUN-71', 'DD-MON-YY'));

INSERT INTO Department (Department_Name, Department_Number, ManagerSSN, ManageStartDate)
VALUES ('Administration', 2, '543216789', TO_DATE('04-JAN-99', 'DD-MON-YY'));

INSERT INTO Department (Department_Name, Department_Number, ManagerSSN, ManageStartDate)
VALUES ('Headquarter', 3, '554433221', TO_DATE('22-SEP-55', 'DD-MON-YY'));

INSERT INTO Department (Department_Name, Department_Number, ManagerSSN, ManageStartDate)
VALUES ('Finance', 4, '987654321', TO_DATE('01-JAN-85', 'DD-MON-YY'));

INSERT INTO Department (Department_Name, Department_Number, ManagerSSN, ManageStartDate)
VALUES ('Research', 5, '333445555', TO_DATE('22-MAY-78', 'DD-MON-YY'));

-- Insert each row separately
INSERT INTO Project (Project_Name, Project_Number, Project_Location, Department_Number)
VALUES ('ProjectA', 3388, 'Houston', 1);

INSERT INTO Project (Project_Name, Project_Number, Project_Location, Department_Number)
VALUES ('ProjectB', 1945, 'Salt Lake City', 3);

INSERT INTO Project (Project_Name, Project_Number, Project_Location, Department_Number)
VALUES ('ProjectC', 6668, 'Houston', 5);

INSERT INTO Project (Project_Name, Project_Number, Project_Location, Department_Number)
VALUES ('ProjectD', 2423, 'Bellaire', 4);

INSERT INTO Project (Project_Name, Project_Number, Project_Location, Department_Number)
VALUES ('ProjectE', 7745, 'Sugarland', 5);

INSERT INTO Project (Project_Name, Project_Number, Project_Location, Department_Number)
VALUES ('ProjectF', 1552, 'Salt Lake City', 3);

INSERT INTO Project (Project_Name, Project_Number, Project_Location, Department_Number)
VALUES ('ProjectG', 1234, 'New York', 2);

INSERT INTO Project (Project_Name, Project_Number, Project_Location, Department_Number)
VALUES ('ProjectH', 3467, 'Stafford', 4);

INSERT INTO Project (Project_Name, Project_Number, Project_Location, Department_Number)
VALUES ('ProjectI', 4345, 'Chicago', 5);

INSERT INTO Project (Project_Name, Project_Number, Project_Location, Department_Number)
VALUES ('ProjectJ', 2212, 'San Francisco', 5);

-- Query to select all rows from Employee table
SELECT * FROM Employee;

-- Display Employee name along with his SSN and Supervisor SSN.
SELECT First_Name, Last_Name, SSN_Number, Supervisor_SSN FROM Employee;

-- Display the employee names whose bdate is ’29-MAR-1959’. 
SELECT First_Name, Last_Name FROM Employee WHERE Birthday = TO_DATE('29-MAR-59', 'DD-MON-YY');

-- Display salary of the employees without duplications.
SELECT DISTINCT Salary FROM Employee;

-- Display the MgrSSN, MgrStartDate of the manager of ‘Finance’ department. 
SELECT ManagerSSN, ManageStartDate FROM Department WHERE Department_Name = 'Finance';

-- Modify the department number of an employee having fname as ‘Joyce’ to 5
UPDATE Employee SET Department_Number = 5 WHERE First_Name = 'Joyce';

-- Alter Table department add column DepartmentPhoneNum of NUMBER data type and insert values into this column only.
ALTER TABLE Department ADD DepartmentPhoneNum NUMBER;
-- insert phone number for each department
UPDATE Department SET DepartmentPhoneNum = 123456789 WHERE Department_Name = 'Manufacture';
UPDATE Department SET DepartmentPhoneNum = 987654321 WHERE Department_Name = 'Administration';
UPDATE Department SET DepartmentPhoneNum = 987654321 WHERE Department_Name = 'Headquarter';
UPDATE Department SET DepartmentPhoneNum = 987654321 WHERE Department_Name = 'Finance';
UPDATE Department SET DepartmentPhoneNum = 987654321 WHERE Department_Name = 'Research';
-- add not null constraint to DepartmentPhoneNum
ALTER TABLE Department MODIFY DepartmentPhoneNum NUMBER NOT NULL;

-- Alter table orders department the size of DepartmentPhoneNum.
ALTER TABLE Department MODIFY DepartmentPhoneNum NUMBER(10);

--  Modify the field name DepartmentPhoneNum of departments table to PhNo.
ALTER TABLE Department RENAME COLUMN DepartmentPhoneNum TO PhNo;

-- Rename Table Department as DEPT. 
ALTER TABLE Department RENAME TO DEPT;

-- Alter Table department remove column DepartmentPhoneNum.
ALTER TABLE DEPT DROP COLUMN PhNo;

-- alter employee table add firstname and lastname not null constraints, primary key on SSN_Number, sex in M, F, m, f, salary default 800, supervisor ssn is a foreign key to SSN_Number - on delete set null, department number is a foreign key to department number of department table - on delete cascade
alter table Employee 
MODIFY (First_Name VARCHAR(15) NOT NULL);

ALTER TABLE Employee
MODIFY (Last_Name VARCHAR(15) NOT NULL);

ALTER TABLE Employee
MODIFY (SSN_Number CHAR(9) PRIMARY KEY);

alter table Employee add foreign key (supervisor_ssn) references Employee(ssn_number);

alter table Employee add foreign key (department_number) references Dept(department_number);

-- alter table dept add primary key on department number, not null on department name, manager ssn references ssn_number of employee table - on delete set null
alter table Dept 
MODIFY (Department_Number NUMBER(5) PRIMARY KEY);

alter table Dept
MODIFY (Department_Name VARCHAR(15) NOT NULL);

alter table Dept add foreign key (ManagerSSN) references Employee(SSN_Number) on delete set null;

-- create table dept_locations with department_number and department_location , where department number is a foreign key to department number of department table - on delete cascade
CREATE TABLE Dept_Locations (
    Department_Number NUMBER(5),
    Department_Location VARCHAR(15),
    FOREIGN KEY (Department_Number) REFERENCES Dept(Department_Number) ON DELETE CASCADE
);

-- alter table project add not null to project name, primary key to project number, department number references department number of department table - on delete cascade
alter table Project
MODIFY (Project_Name VARCHAR(15) NOT NULL);

alter table Project
MODIFY (Project_Number NUMBER(5) PRIMARY KEY);

alter table Project add foreign key (department_number) references Dept(department_number) on delete cascade;

-- create table works_on with employee ssn, project number, hours, where employee ssn is a foreign key to ssn number of employee table - on delete cascade, project number is a foreign key to project number of project table - on delete cascade
CREATE TABLE Works_On (
    Employee_SSN CHAR(9),
    Project_Number INT(5),
    Hours decimal(3,1),
    FOREIGN KEY (Employee_SSN) REFERENCES Employee(SSN_Number) ON DELETE CASCADE,
    FOREIGN KEY (Project_Number) REFERENCES Project(Project_Number) ON DELETE CASCADE
);

-- create table dependent with columns: employee references ssn number of employee table - on delete cascade, dependent name varchar(15), primary keys are employee and dependent name, sex - char(1) in M, F, m, f, Birthday as date, relationship varchar(8)
CREATE TABLE Dependent (
    Employee CHAR(9),
    Dependent_Name VARCHAR(15),
    Sex CHAR(1) CHECK (Sex IN ('M', 'F', 'm', 'f')),
    Birthday DATE,
    Relationship VARCHAR(8),
    FOREIGN KEY (Employee) REFERENCES Employee(SSN_Number) ON DELETE CASCADE,
    PRIMARY KEY (Employee, Dependent_Name),
);

insert into dept_locations values (1, 'Houston');
insert into dept_locations values (1, 'Chicago');
insert into dept_locations values (2, 'New York'); 
insert into dept_locations values (2, 'San Francisco'); 
insert into dept_locations values (3, 'Salt Lake City'); 
insert into dept_locations values (4, 'Bellaire');  
insert into dept_locations values (4, 'Stafford'); 
insert into dept_locations values (5, 'Sugarland'); 
insert into dept_locations values (5, 'Houston');

INSERT INTO Works_On (Employee_SSN, Project_Number, Hours) VALUES ('123456789', 3388, 32.5);
INSERT INTO Works_On (Employee_SSN, Project_Number, Hours) VALUES ('123456789', 1945, 7.5);
INSERT INTO Works_On (Employee_SSN, Project_Number, Hours) VALUES ('666884444', 3388, 40.0);
INSERT INTO Works_On (Employee_SSN, Project_Number, Hours) VALUES ('453453453', 7745, 20.0);
INSERT INTO Works_On (Employee_SSN, Project_Number, Hours) VALUES ('453453453', 2212, 20.0);
INSERT INTO Works_On (Employee_SSN, Project_Number, Hours) VALUES ('333445555', 7745, 10.0);
INSERT INTO Works_On (Employee_SSN, Project_Number, Hours) VALUES ('333445555', 6688, 10.0);
INSERT INTO Works_On (Employee_SSN, Project_Number, Hours) VALUES ('333445555', 4345, 35.0);
INSERT INTO Works_On (Employee_SSN, Project_Number, Hours) VALUES ('333445555', 2212, 28.5);
INSERT INTO Works_On (Employee_SSN, Project_Number, Hours) VALUES ('999887777', 1234, 11.5);
INSERT INTO Works_On (Employee_SSN, Project_Number, Hours) VALUES ('999887777', 1234, 13.0);
INSERT INTO Works_On (Employee_SSN, Project_Number, Hours) VALUES ('543216789', 2212, 17.0);
INSERT INTO Works_On (Employee_SSN, Project_Number, Hours) VALUES ('554433221', 1945, 21.5);

-- modify project_number where it is 6668 to 6688
UPDATE Works_On SET Project_Number = 6688 WHERE Project_Number = 6668;

-- insert into dependent table, employee ssn is 123456789, dependent name is Alice, sex is F, Birthday is 05-Apr-76, relationship is daughter
INSERT INTO Dependent (Employee, Dependent_Name, Sex, Birthday, Relationship) VALUES ('333445555', 'Alice', 'F', TO_DATE('05-APR-76', 'DD-MON-YY'), 'Daughter');
INSERT INTO Dependent (Employee, Dependent_Name, Sex, Birthday, Relationship) VALUES ('333445555', 'Theodore', 'M', TO_DATE('25-OCT-73', 'DD-MON-YY'), 'Son');
INSERT INTO Dependent (Employee, Dependent_Name, Sex, Birthday, Relationship) VALUES ('333445555', 'Joy', 'F', TO_DATE('03-MAY-48', 'DD-MON-YY'), 'Spouse');
INSERT INTO Dependent (Employee, Dependent_Name, Sex, Birthday, Relationship) VALUES ('987654321', 'Abner', 'M', TO_DATE('29-FEB-32', 'DD-MON-YY'), 'Spouse');
INSERT INTO Dependent (Employee, Dependent_Name, Sex, Birthday, Relationship) VALUES ('123456789', 'Alice', 'F', TO_DATE('31-DEC-78', 'DD-MON-YY'), 'Daughter');
INSERT INTO Dependent (Employee, Dependent_Name, Sex, Birthday, Relationship) VALUES ('123456789', 'Elizabeth', 'F', TO_DATE('05-MAY-57', 'DD-MON-YY'), 'Spouse');

--Execute the following Query on the DB to display and discuss the integrity constraints 
-- violated by any of the following operations 
-- 1) Insert ('Robert', 'F', 'Scott', '943775543', '21-JUN-42', '2365 Newcastle Rd, Bellaire, TX', 
-- M, 58000, '888665555', 1 ) into EMPLOYEE. 
-- 2) Insert ( '677678989', null, '40.0' ) into WORKS_ON. 
-- 3) Insert ( '453453453', 'John', M, '12-DEC-60', 'SPOUSE' ) into DEPENDENT 
-- 4) Delete the WORKS_ON tuples with ESSN= '333445555'. 
-- 5) Modify the MGRSSN and MGRSTARTDATE of the DEPARTMENT tuple with 
-- DNUMBER=5 to '123456789' and '01-OCT-88', respectively. 

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number)
VALUES ('Robert', 'F', 'Scott', '943775543', TO_DATE('21-JUN-42', 'DD-MON-YY'), '2365 Newcastle Rd, Bellaire, TX', 'M', 58000, '888665555', 1);

INSERT INTO Works_On (Employee_SSN, Project_Number, Hours) VALUES ('677678989', NULL, '40.0');

INSERT INTO Dependent (Employee, Dependent_Name, Sex, Birthday, Relationship) VALUES ('453453453', 'John', 'M', TO_DATE('12-DEC-60', 'DD-MON-YY'), 'SPOUSE');

DELETE FROM Works_On WHERE Employee_SSN = '333445555';

UPDATE Department SET ManagerSSN = '123456789', ManageStartDate = TO_DATE('01-OCT-88', 'DD-MON-YY') WHERE Department_Number = 5;

-- Drop Foreign key defined on SuperSSN and add it using Alter table command.
ALTER TABLE Employee
DROP FOREIGN KEY Supervisor_ssn;

ALTER TABLE Employee
ADD FOREIGN KEY (Supervisor_SSN) REFERENCES Employee(SSN_Number) 
ON DELETE SET NULL;

--Add Unique constraint to the Project name attribute and not null to sex of employee. 
ALTER TABLE Project
MODIFY Project_name UNIQUE;

ALTER TABLE Employee
MODIFY Sex NOT NULL;

-- new address type
create type addressType as OBJECT (
    door_no number(3),
    street varchar(50),
    city varchar(20),
    state varchar(20),
    continent varchar(20)
);

SELECT first_name, last_name,
       TREAT(address AS AddressType).door_no AS door_no,
       TREAT(address AS AddressType).street AS street,
       TREAT(address AS AddressType).city AS city,
       TREAT(address AS AddressType).state AS state,
       TREAT(address AS AddressType).continent AS continent
FROM employee;



ALTER TABLE Employee
MODIFY Salary REAL;


-- Exercise 3
create table Physician (
    employeeid number(5) primary key,
    name varchar(50),
    position varchar(20),
    ssn number(9) unique
);

create table Department (
    departmentid number(5) primary key,
    name varchar (20),
    head number(9) references Physician(employeeid)
);

create table Works_With (
    physician number(5) references Physician(employeeid),
    department number(5) references Department(departmentid),
    primaryaffiliation char(1) check (primaryaffiliation in ('Y', 'N')),
    primary key (physician, department)
);

create table Procedure (
    code number(5) primary key,
    name varchar(20),
    cost decimal(8, 2)
)

create table patient (
    ssn number(9) primary key,
    name varchar(50),
    address varchar(100),
    phone number(10),
    insuranceid number(7),
    pcp number(9) references Physician(employeeid)
)

create table nurse (
    employeeid number(5) primary key,
    name varchar(50),
    position varchar(20),
    registered char(1) check (registered in ('Y', 'N')),
    ssn number(9) unique
)

create table appointment (
    appointmentid number(3) unique,
    patientid number(9) references patient(ssn),
    prepnurse number(6) references nurse(employeeid),
    physician number(6) references physician(employeeid),
    appointmentdate date,
    start_time timestamp,
    end_time timestamp,
    examinationroom number(3),
)

-- Insert required data into each relation (min. FIVE) under exercise 3
INSERT INTO Physician (employeeid, name, position, ssn) VALUES (1, 'Dr. John Doe', 'Cardiologist', 123456789);
INSERT INTO Physician (employeeid, name, position, ssn) VALUES (2, 'Dr. Jane Doe', 'Neurologist', 987654321);
INSERT INTO Physician (employeeid, name, position, ssn) VALUES (3, 'Dr. John Smith', 'Orthopedic', 123123123);
INSERT INTO Physician (employeeid, name, position, ssn) VALUES (4, 'Dr. Jane Smith', 'Pediatrician', 987987987);
INSERT INTO Physician (employeeid, name, position, ssn) VALUES (5, 'Dr. Michael Jackson', 'ENT Specialist', 111111111);

INSERT INTO Department (departmentid, name, head) VALUES (1, 'Cardiology', 1);
INSERT INTO Department (departmentid, name, head) VALUES (2, 'Neurology', 2);
INSERT INTO Department (departmentid, name, head) VALUES (3, 'Orthopedic', 3);
INSERT INTO Department (departmentid, name, head) VALUES (4, 'Pediatrics', 4);
INSERT INTO Department (departmentid, name, head) VALUES (5, 'ENT Specialization', 5);

INSERT INTO Works_With (physician, department, primaryaffiliation) VALUES (1, 1, 'Y');
INSERT INTO Works_With (physician, department, primaryaffiliation) VALUES (2, 2, 'Y');
INSERT INTO Works_With (physician, department, primaryaffiliation) VALUES (3, 3, 'Y');
INSERT INTO Works_With (physician, department, primaryaffiliation) VALUES (4, 4, 'Y');
INSERT INTO Works_With (physician, department, primaryaffiliation) VALUES (5, 5, 'Y');

INSERT INTO Procedure (code, name, cost) VALUES (1, 'Heart Surgery', 10000.00);
INSERT INTO Procedure (code, name, cost) VALUES (2, 'Brain Surgery', 20000.00);
INSERT INTO Procedure (code, name, cost) VALUES (3, 'Knee Surgery', 30000.00);
INSERT INTO Procedure (code, name, cost) VALUES (4, 'Pediatric Surgery', 40000.00);
INSERT INTO Procedure (code, name, cost) VALUES (5, 'Skin Surgery', 50000.00);

INSERT INTO patient (ssn, name, address, phone, insuranceid, pcp) VALUES (121212121, 'Alice', '1234 Wonderland', 1234567890, 1234561, 1);
INSERT INTO patient (ssn, name, address, phone, insuranceid, pcp) VALUES (343434343, 'Bob', '5678 Wonderland', 1234567890, 1234562, 2);
INSERT INTO patient (ssn, name, address, phone, insuranceid, pcp) VALUES (565656565, 'Charlie', '91011 Wonderland', 1234567890, 1234563, 3);
INSERT INTO patient (ssn, name, address, phone, insuranceid, pcp) VALUES (787878787, 'David', '121314 Wonderland', 1234567890, 1234564, 4);
INSERT INTO patient (ssn, name, address, phone, insuranceid, pcp) VALUES (909090909, 'Eve', '151617 Wonderland', 1234567890, 1234565, 5);

INSERT INTO nurse (employeeid, name, position, registered, ssn) VALUES (1, 'Nurse Fiona', 'Registered Nurse', 'Y', 999999999);
INSERT INTO nurse (employeeid, name, position, registered, ssn) VALUES (2, 'Nurse Grey', 'Registered Nurse', 'Y', 888888888);
INSERT INTO nurse (employeeid, name, position, registered, ssn) VALUES (3, 'Nurse Harry', 'Registered Nurse', 'Y', 777777777);
INSERT INTO nurse (employeeid, name, position, registered, ssn) VALUES (4, 'Nurse Immanuel', 'Registered Nurse', 'Y', 666666666);
INSERT INTO nurse (employeeid, name, position, registered, ssn) VALUES (5, 'Nurse Jenny', 'Registered Nurse', 'Y', 555555555);

INSERT INTO appointment (appointmentid, patientid, prepnurse, physician, appointmentdate, start_time, end_time, examinationroom) VALUES (1, 121212121, 1, 1, TO_DATE('01-JAN-21', 'DD-MON-YY'), TO_TIMESTAMP('01-JAN-21 10:00:00', 'DD-MON-YY HH24:MI:SS'), TO_TIMESTAMP('01-JAN-21 11:00:00', 'DD-MON-YY HH24:MI:SS'), 021);
INSERT INTO appointment (appointmentid, patientid, prepnurse, physician, appointmentdate, start_time, end_time, examinationroom) VALUES (2, 343434343, 2, 2, TO_DATE('02-JAN-21', 'DD-MON-YY'), TO_TIMESTAMP('02-JAN-21 10:00:00', 'DD-MON-YY HH24:MI:SS'), TO_TIMESTAMP('02-JAN-21 11:00:00', 'DD-MON-YY HH24:MI:SS'), 022);
INSERT INTO appointment (appointmentid, patientid, prepnurse, physician, appointmentdate, start_time, end_time, examinationroom) VALUES (3, 565656565, 3, 3, TO_DATE('03-JAN-21', 'DD-MON-YY'), TO_TIMESTAMP('03-JAN-21 10:00:00', 'DD-MON-YY HH24:MI:SS'), TO_TIMESTAMP('03-JAN-21 11:00:00', 'DD-MON-YY HH24:MI:SS'), 023);
INSERT INTO appointment (appointmentid, patientid, prepnurse, physician, appointmentdate, start_time, end_time, examinationroom) VALUES (4, 787878787, 4, 4, TO_DATE('04-JAN-21', 'DD-MON-YY'), TO_TIMESTAMP('04-JAN-21 10:00:00', 'DD-MON-YY HH24:MI:SS'), TO_TIMESTAMP('04-JAN-21 11:00:00', 'DD-MON-YY HH24:MI:SS'), 024);
INSERT INTO appointment (appointmentid, patientid, prepnurse, physician, appointmentdate, start_time, end_time, examinationroom) VALUES (5, 909090909, 5, 5, TO_DATE('05-JAN-21', 'DD-MON-YY'), TO_TIMESTAMP('05-JAN-21 10:00:00', 'DD-MON-YY HH24:MI:SS'), TO_TIMESTAMP('05-JAN-21 11:00:00', 'DD-MON-YY HH24:MI:SS'), 025);



select * from Physician;

insert into PROCEDURE (code, name, cost) values (6, 'Physiotherapy', 6000.00);
insert into PROCEDURE (code, name, cost) values (7, 'Gastric Surgery', 7000.00);
insert into PROCEDURE (code, name, cost) values (8, 'Gastric problem', 7000.39);

select name, cost from Procedure where name IN ('Physiotherapy', 'Gastric problem');

select name from physician where employeeid in (
    select physician from works_with where primaryaffiliation = 'N'
);

insert into physician (employeeid, name, position, ssn) values (6, 'Dr. Emerald Green', 'Psychotherapist', 1234512345);

select * from physician where name like 'Dr. E%';

-- 5)	Write a SQL query to find the details of the patients whose appointment time is greater than 12.30 PM for a corresponding date.


INSERT INTO appointment (appointmentid, patientid, prepnurse, physician, appointmentdate, start_time, end_time, examinationroom) VALUES (6, 787878787, 4, 4, TO_DATE('14-JAN-21', 'DD-MON-YY'), TO_TIMESTAMP('14-JAN-21 12:40:00', 'DD-MON-YY HH24:MI:SS'), TO_TIMESTAMP('04-JAN-21 13:00:00', 'DD-MON-YY HH24:MI:SS'), 026);
INSERT INTO appointment (appointmentid, patientid, prepnurse, physician, appointmentdate, start_time, end_time, examinationroom) VALUES (7, 909090909, 5, 5, TO_DATE('15-JAN-21', 'DD-MON-YY'), TO_TIMESTAMP('15-JAN-21 13:00:00', 'DD-MON-YY HH24:MI:SS'), TO_TIMESTAMP('05-JAN-21 14:00:00', 'DD-MON-YY HH24:MI:SS'), 027);
INSERT INTO appointment (appointmentid, patientid, prepnurse, physician, appointmentdate, start_time, end_time, examinationroom) VALUES (8, 121212121, 4, 4, TO_DATE('14-JAN-21', 'DD-MON-YY'), TO_TIMESTAMP('14-JAN-21 13:40:00', 'DD-MON-YY HH24:MI:SS'), TO_TIMESTAMP('04-JAN-21 14:00:00', 'DD-MON-YY HH24:MI:SS'), 026);


select * from appointment where start_time > TO_TIMESTAMP('01-JAN-21 12:30:00', 'DD-MON-YY HH24:MI:SS');

--Assignment 2

select first_name, mid_name, last_name, salary from employee where salary > 25000;

select first_name, mid_name, last_name, salary from employee where salary between 30000 and 70000;

select first_name, mid_name, last_name, supervisor_ssn from employee where supervisor_ssn is null;

-- 4)	Display the bdate of all employee s in the format ‘DDthMonthYYYY’.
SELECT TO_CHAR(bdate, 'DDthMonthYYYY') AS formatted_bdate
FROM employee;

--  Display the employee names whose bdate is on or before 1978. 
SELECT first_name, last_name FROM employee WHERE bdate <= TO_DATE('31-DEC-78', 'DD-MON-YY');

--Display the employee names having ‘salt lake’ in their address. 
SELECT first_name, last_name FROM employee WHERE address LIKE '%Salt Lake%';

--Display the department name that starts with ’M’.
SELECT department_name FROM department WHERE department_name LIKE 'M%';

--Display the department names’ that ends with ‘E’.
SELECT department_name FROM department WHERE department_name LIKE '%E';

--Display the names of all the employees having supervisor with any of the following SSN 554433221, 333445555. 
SELECT first_name, last_name FROM employee WHERE supervisor_ssn IN ('554433221', '333445555');

--Display all the department names in upper case and lower case.
SELECT UPPER(department_name) AS department_name_upper, LOWER(department_name) AS department_name_lower FROM department;

-- Display the first four characters and last four of the department names using SUBSTR
SELECT 
    SUBSTR(department_name, 1, 4) AS first_four, 
    SUBSTR(department_name, -4) AS last_four 
FROM department;

-- Display the substring of the Address (starting from 5th position to 11 th position) of all employees. 
SELECT SUBSTR(address, 5, 11) AS address_substring FROM employee;

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number) 
VALUES 
('Doug', 'E', 'Gilbert', '554433221', TO_DATE('09-JUN-60', 'DD-MON-YY'), '11 S 59 E, Salt Lake City, UT', 'M', 80000, NULL, 3);

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number) 
VALUES 
('Joyce', 'A', 'PAN', '543216789', TO_DATE('07-FEB-78', 'DD-MON-YY'), '35 S 18 E, Salt Lake City, UT', 'F', 70000, NULL, 2);

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number) 
VALUES 
('Franklin', 'T', 'Wong', '333445555', TO_DATE('08-DEC-45', 'DD-MON-YY'), '638 Voss, Houston, TX', 'M', 40000, '554433221', 5);

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number) 
VALUES 
('Jennifer', 'S', 'Wallace', '987654321', TO_DATE('20-JUN-31', 'DD-MON-YY'), '291 Berry, Bellaire, TX', 'F', 43000, '554433221', 4);

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number) 
VALUES 
('John', 'B', 'Smith', '123456789', TO_DATE('09-JAN-55', 'DD-MON-YY'), '731 Fondren, Houston, TX', 'M', 30000, '333445555', 5);

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number) 
VALUES 
('Ramesh', 'K', 'Narayan', '666884444', TO_DATE('15-SEP-52', 'DD-MON-YY'), '975 Fire Oak, Humble, TX', 'M', 38000, '333445555', 5);

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number) 
VALUES 
('Joyce', 'A', 'English', '453453453', TO_DATE('31-JUL-62', 'DD-MON-YY'), '5631 Rice, Houston, TX', 'F', 25000, '333445555', 5);

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number) 
VALUES 
('James', 'E', 'Borg', '888665555', TO_DATE('10-NOV-27', 'DD-MON-YY'), '450 Stone, Houston, TX', 'M', 55000, '543216789', 1);

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number) 
VALUES 
('Alicia', 'J', 'Zelaya', '999887777', TO_DATE('19-JUL-58', 'DD-MON-YY'), '3321 Castle, Spring, TX', 'F', 25000, '987654321', 4);

INSERT INTO Employee (First_Name, Mid_Name, Last_Name, SSN_Number, Birthday, Address, Sex, Salary, Supervisor_SSN, Department_Number) 
VALUES 
('Ahmad', 'V', 'Jabbar', '987987987', TO_DATE('29-MAR-59', 'DD-MON-YY'), '980 Dallas, Houston, TX', 'M', 25000, '987654321', 4);

-- Display the Mgrstartdate on adding three months to it. 
SELECT ADD_MONTHS(ManageStartDate, 3) AS MgrStartDate FROM Department;

--Display the age of all the employees rounded to two digits.
SELECT 
    First_Name,
    Last_Name,
    Birthday,
    ROUND(
        (SYSDATE - TO_DATE(TO_CHAR(Birthday, 'DD-MON-YYYY'), 'DD-MON-YYYY')) / 365.25,
        2
    ) AS Age
FROM 
    Employee

-- Find the last day and next day of the month in which each manager has joined. 
SELECT 
    Department_Name,
    ManageStartDate,
    LAST_DAY(ManageStartDate) AS Last_Day,
    NEXT_DAY(ManageStartDate, 'SUNDAY') AS Next_Day
FROM
    Department;


-- For the relational schema given as part of Assessment – 1, write the SQL queries using Group 
-- Functions to get the following information. 
-- 1) How many different departments are there in the ‘employee’ table. 
-- 2) For each department display the minimum and maximum employee salaries. 
-- 3) Print the average annual salary. 
-- 4) Count the number of employees over 30 age. 
-- 5) Print the Department name and average salary of each department. 
-- 6) Display the department name which contains more than 30 employees. 
-- 7) Calculate the average salary of employees by department and age 
-- 8) Count separately the number of employees in the finance and research department. 
-- 9) List out the employees based on their seniority. 
-- 10) List out the employees who works in ‘manufacture’ department group by first name.
-- Use group in all the queries

-- 1) How many different departments are there in the ‘employee’ table.
SELECT COUNT(DISTINCT Department_Number) AS Department_Count FROM Employee;

-- 2) For each department display the minimum and maximum employee salaries.
SELECT 
    Department_Number,
    MIN(Salary) AS Min_Salary,
    MAX(Salary) AS Max_Salary
FROM

    Employee

GROUP BY Department_Number;

-- 3) Print the average annual salary.
SELECT AVG(Salary) AS Avg_Salary FROM Employee;

-- 4) Count the number of employees over 30 age.
SELECT COUNT(*) AS Over_30_Employees FROM Employee WHERE EXTRACT(YEAR FROM SYSDATE) - EXTRACT(YEAR FROM Birthday) > 30;

-- 5) Print the Department name and average salary of each department.
SELECT 
    Department.Department_Name,
    AVG(Employee.Salary) AS Avg_Salary
FROM
    Employee

JOIN Department ON Employee.Department_Number = Department.Department_Number

GROUP BY Department.Department_Name;

-- 6) Display the department name which contains more than 30 employees.
SELECT 
    Department.Department_Name

FROM
    Employee

JOIN Department ON Employee.Department_Number = Department.Department_Number

GROUP BY Department.Department_Name

HAVING COUNT(*) > 30;

-- 7) Calculate the average salary of employees by department and age
SELECT 
    d.Department_Name,
    FLOOR((e.Birthday - SYSDATE) / 365.25) AS Age,
    ROUND(AVG(e.Salary), 2) AS Average_Salary
FROM 
    Employee e
JOIN 
    Dept d ON e.Department_Number = d.Department_Number
GROUP BY 
    d.Department_Name,
    FLOOR((e.Birthday-SYSDATE) / 365.25)
ORDER BY 
    d.Department_Name,
    Age;

-- 8) Count separately the number of employees in the finance and research department.
SELECT 
    Department.Department_Name,
    COUNT(*) AS Employee_Count
FROM
    Employee

JOIN Department ON Employee.Department_Number = Department.Department_Number

WHERE Department.Department_Name IN ('Finance', 'Research')

GROUP BY Department.Department_Name;

-- 9) List out the employees based on their seniority.
SELECT 
    First_Name,
    Last_Name,
    Salary,
    RANK() OVER (ORDER BY Salary DESC) AS Seniority
FROM
    Employee;

-- 10) List out the employees who works in ‘manufacture’ department group by first name.
SELECT 
    First_Name,
    COUNT(*) AS Employee_Count
FROM
    Employee

JOIN Department ON Employee.Department_Number = Department.Department_Number
    
    WHERE Department.Department_Name = 'Manufacture'    

GROUP BY First_Name;



-- 1) find the employee who is getting highest salary in the department research
SELECT FName, LName FROM Employee JOIN Department ON Employee.Department_Number = Department.Department_Number 
WHERE Department.Department_Name = "Research" AND Salary = MAX(Salary)


-- 2)
SELECT FName, LName FROM Employee where salary = MIN(salary) group by department

-- 3) 
SELECT FName, LName FROM Employee 
WHERE Salary > AVG( 
    SELECT Employee.Salary from Employee JOIN Dept ON Employee.Department_Number = Department.Department_Number WHERE Dept.Dept_Number = 2
);


select count(first_name) from employee join dept on employee.department_number = dept.department_number 
    group by dept.department_number;

--5)	Find out the department name having highest employee strength 
SELECT Department_Name FROM Department WHERE Department_Number = (SELECT Department_Number FROM Employee GROUP BY Department_Number ORDER BY COUNT(*) DESC LIMIT 1);

--8)	Create a view to display the employee details who is working in Finance department. 
CREATE VIEW Finance_Employees AS SELECT * FROM Employee WHERE Department_Number = (SELECT Department_Number FROM Department WHERE Department_Name = 'Finance');
-- open the created view
SELECT * FROM Finance_Employees;

--9) Create a logical table to store employee details who is getting salary more than 10000. 
CREATE VIEW High_Salary_Employees AS SELECT * FROM Employee WHERE Salary > 10000;

--10) 10) Create a table to store the employees details based on the department no
CREATE VIEW Department_Employees AS SELECT * FROM Employee ORDER BY Department_Number;

--10)	Retrieve the names of the employees who have 2 or more dependents
SELECT First_Name, Last_Name FROM Employee WHERE SSN_Number IN (SELECT SSN_Number FROM Dependent GROUP BY SSN_Number HAVING COUNT(*) >= 2);