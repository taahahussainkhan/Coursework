use classicmodels;
# 1.Write a Query that retrieves each employee’s extension with the phone which he use, using inner join.
 #desc Employees;

SELECT e.extension ,o.phone
FROM employees as e
INNER JOIN Offices as o
ON o.officecode = e.officecode;



#2.	Write SQL query that shows those customers names and address whose payment amount is more than 30000 using inner join.
SELECT c.customerName , c.addressLine1,c.addressLine2
FROM Customers as c
INNER JOIN payments as p
ON c.customerNumber = p.customerNumber
WHERE p.amount > 30000;



# 3.	Write an SQL query that retrieves Product code and Product names with the Ordered quantity less than 50.

SELECT p.productCode, p.productName,ord.quantityOrdered
FROM products AS p
JOIN orderdetails AS ord
ON p.productcode = ord.productcode
WHERE ord.quantityOrdered < 50;


# 4.   Write Inner Join SQL query that retrieves employee’s names with job titles whose offices located in Sydney.


SELECT e.firstname,e.lastname,e.jobTitle 
FROM Employees as e
JOIN offices AS o
ON e.officecode = o.officecode
WHERE o.city = 'Sydney';


# 5.Write an inner Join SQL query that retrieves customer’s names whose payment amount lies between 60000 and 70000.


SELECT c.customerName
FROM Customers as c
INNER JOIN payments as p
ON c.customerNumber = p.customerNumber
WHERE p.amount > 60000 AND p.amount < 70000;




# 6.Write SQL query that retrieves names of those employees whose offices located in cities having name starts with ‘S’;


SELECT e.firstname,e.lastname
FROM Employees as e
JOIN offices AS o
ON e.officecode = o.officecode
WHERE o.city LIKE 'S%';


#7.	Write a SQL query that retrieves the complete record of all the employees whose territory is Japan.



SELECT e.* 
FROM Employees as e
JOIN offices AS o
ON e.officecode = o.officecode
WHERE o.territory = 'Japan';



# 8.Write a query that retrieves the status and comments of customers with their name whose shipped date is in year 2003.


SELECT ord.status , ord.comments , c.customername
FROM Customers as c
JOIN orders as ord
ON ord.customernumber = c.customernumber
WHERE ord.shippedDate LIKE '2003%';



# 9.	Write a query that display text description of those products whose name contains “Harley

SELECT pl.textDescription 
FROM productLines AS pl
JOIN products as pr
ON pl.productline = pr.productline
WHERE pr.productName LIKE '%Harley%';



# 10.	Write SQL query to retrieve the order numbers of those customers 
# whose contact first name starts with A and the quantity ordered is greater than 50.


SELECT ord.orderNumber 
FROM orders as ord
JOIN customers as c
ON c.customerNumber  = ord.customerNumber
JOIN orderdetails as ord_d
ON ord_d.orderNumber  = ord.orderNumber
WHERE c.contactFirstName LIKE 'A%' AND ord_d.quantityOrdered > 50;






