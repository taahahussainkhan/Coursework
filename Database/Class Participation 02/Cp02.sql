#1- Many employees can work in our company. We want to retrieve record of each employee.
SELECT * FROM Employee;

#2- Display the first name employees having salary greater than 40,000.
SELECT first_name FROM Employee
WHERE salary > '40000';

#3- Display the name of those employees who work as supervisor in the company.
#SELECT first_name , mid_name_initial, last_name
#FROM Employee e1, Employee e2
#WHERE e1.ssn = e2.super_ssn;


#4- Display the salary and department number of all female employees.
SELECT salary,dept_number FROM Employee
WHERE gender LIKE 'F';

#5- Display the first name of those employees whose salary between 40,000 and 50,000.

SELECT first_name FROM Employee
WHERE salary BETWEEN '40000' AND '50000';


#6- Display distinct first name of all the employees works for department, having dno = 5.

SELECT DISTINCT first_name FROM Employee
WHERE dept_number = 5;



#7- Sort the data of all employees in descending order on the basis of their salary

SELECT * FROM Employee
ORDER BY salary desc;

#8- User wants to start a new project of image processing in USA in department no 6
insert into project (project_number, project_name,      project_location, dept_number)
values              (4,              'Image Processing',        'USA',       6);


#9- Now user is facing difficulty while working on a project names Operating Systems in Jacksonville,
# he wants to change the location from Jacksonville to London
update project
set project_location = 'London'
where project_name = 'Operating Systems';


#10- User wants to stop the work on image processing project. So delete the record against this
# project from database.

delete from works_on
where emp_ssn = '999887777'
and project_number = 10;

#11- Show the names of all employees except who are working in department no. 7
SELECT first_name, last_name
FROM employee
WHERE dept_number <> 7;
