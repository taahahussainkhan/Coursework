SET SQL_SAFE_UPDATES = 0;
DROP DATABASE IF EXISTS MANUFACTURER_COMPANY;
CREATE DATABASE MANUFACTURER_COMPANY;
USE MANUFACTURER_COMPANY;
CREATE TABLE Customer (
  customer_id			 VARCHAR(8) NOT NULL UNIQUE PRIMARY KEY,
  name VARCHAR(255) NOT NULL,
  contact_information VARCHAR(255) NOT NULL
);
CREATE TABLE Employee (
  employee_id VARCHAR(8) NOT NULL UNIQUE,
  name VARCHAR(15) NOT NULL,
  contact_information VARCHAR(255) NOT NULL,
  job_title VARCHAR(15)
);
CREATE TABLE Product_Category (
  category_id VARCHAR(8) NOT NULL UNIQUE,
  name VARCHAR(15) NOT NULL
);

CREATE TABLE Product (
  product_id VARCHAR(8) NOT NULL UNIQUE,
  name VARCHAR(15) NOT NULL,
  description VARCHAR(50),
  category_id VARCHAR(8) NOT NULL,
  manufacturer_id VARCHAR(8) NOT NULL
);

CREATE TABLE Transaction (
   transaction_id VARCHAR(8) NOT NULL UNIQUE PRIMARY KEY,
  date DATE NOT NULL,
  total_amount INT NOT NULL,
  customer_id VARCHAR(8) NOT NULL,
  employee_id VARCHAR(8) NOT NULL,
  CONSTRAINT fk_transaction_customer_id
    FOREIGN KEY (customer_id)
    REFERENCES Customer (customer_id)
    ON DELETE CASCADE,
  CONSTRAINT fk_transaction_employee_id
    FOREIGN KEY (employee_id)
    REFERENCES Employee (employee_id)
    ON DELETE CASCADE
);
CREATE TABLE Product_Transaction (
    quantity INT NOT NULL,
  transaction_id VARCHAR(8) NOT NULL,
  product_id VARCHAR(8) NOT NULL,
  CONSTRAINT fk_product_transaction_transaction_id
    FOREIGN KEY (transaction_id)
    REFERENCES Transaction (transaction_id)
    ON DELETE CASCADE,
  CONSTRAINT fk_product_transaction_product_id
    FOREIGN KEY (product_id)
    REFERENCES Product (product_id)
    ON DELETE CASCADE
);
CREATE TABLE Service (
  service_id VARCHAR(8) NOT NULL UNIQUE					PRIMARY KEY,
  name VARCHAR(15),
  description VARCHAR(50),
  cost INT,
  category_id VARCHAR(8) NOT NULL,
  provider_id VARCHAR(8) NOT NULL
);
CREATE TABLE Service_Transaction (
  transaction_id VARCHAR(8) NOT NULL,
  service_id VARCHAR(8) NOT NULL,
  CONSTRAINT fk_service_transaction_transaction_id
    FOREIGN KEY (transaction_id)
    REFERENCES Transaction (transaction_id)
    ON DELETE CASCADE,
  CONSTRAINT fk_service_transaction_service_id
    FOREIGN KEY (service_id)
    REFERENCES Service (service_id)
    ON DELETE CASCADE
);
CREATE TABLE Manufacturer (
  manufacturer_id VARCHAR(8) NOT NULL UNIQUE  PRIMARY KEY,
  name VARCHAR(15) NOT NULL
);
CREATE TABLE Supplier (
  supplier_id VARCHAR(8) NOT NULL UNIQUE,
  name VARCHAR(15),
  contact_information VARCHAR(255) NOT NULL
);
CREATE TABLE Service_Category (
  category_id VARCHAR(8) NOT NULL UNIQUE,
  name VARCHAR(15) NOT NULL
);

CREATE TABLE Provider (
  provider_id VARCHAR(8) NOT NULL UNIQUE    PRIMARY KEY,
  name VARCHAR(15) NOT NULL
);

CREATE TABLE Business_unit (
  business_unit_id VARCHAR(8) NOT NULL UNIQUE,
  name VARCHAR(15) NOT NULL
);
CREATE TABLE Supplier_product (

        supplier_id 	VARCHAR(8) 		NOT NULL 	UNIQUE,        
		product_id		VARCHAR(8)		NOT NULL  	UNIQUE,
        
		CONSTRAINT fk_product_id
		FOREIGN KEY (product_id)
		REFERENCES Product(product_id)
		ON DELETE CASCADE,
        
        
        CONSTRAINT fk_supplier_id
		FOREIGN KEY (supplier_id)
		REFERENCES Supplier (supplier_id)
		ON DELETE CASCADE
	);
CREATE TABLE Region (
  region_id VARCHAR(8) NOT NULL UNIQUE   PRIMARY KEY,
  name VARCHAR(15) NOT NULL
);

CREATE TABLE Supplier_Region_Business_Unit (
  supplier_id 		VARCHAR(8)		 NOT NULL         PRIMARY KEY,
  region_id VARCHAR(8) NOT NULL,
  business_unit_id VARCHAR(8) NOT NULL,
  CONSTRAINT fk_supplier_region_business_unit_supplier_id
    FOREIGN KEY (supplier_id)
    REFERENCES Supplier (supplier_id)
    ON DELETE CASCADE,
  CONSTRAINT fk_supplier_region_business_unit_region_id
    FOREIGN KEY (region_id)
    REFERENCES Region (region_id)
    ON DELETE CASCADE,
  CONSTRAINT fk_supplier_region_business_unit_business_unit_id
    FOREIGN KEY (business_unit_id)
    REFERENCES Business_unit (business_unit_id)
    ON DELETE CASCADE
);


#1- Create a new table called “Order_Item” with columns “order_item_id” (primary key) and “quantity”.

CREATE TABLE Order_Item (
  order_item_id INT PRIMARY KEY,
  quantity DOUBLE NOT NULL
);

#2- Modify the table “Order_Item” by adding the columns “transaction_id” (foreign key
#referencing Transaction.transaction_id), “product_id” (foreign key referencing
#Product.product_id), “service_id” (foreign key referencing Sevice.service_id).
#ALTER TABLE Order_Item


ALTER TABLE Order_Item
ADD 	transaction_id	 	int,
ADD 	product_id			int,
ADD		service_id			int,
ADD		FOREIGN KEY(transaction_id)
REFERENCES	Transaction(transaction_id)
ON DELETE CASCADE
ON UPDATE CASCADE,
ADD		FOREIGN KEY(product_id)
REFERENCES	Product(product_id)
ON DELETE CASCADE
ON UPDATE CASCADE,
ADD FOREIGN KEY(service_id)
REFERENCES Service(service_id);


#3- Add a new column called “unit_price” to the Products table.

ALTER TABLE Product
ADD unit_price DOUBLE;


#4- Create a new table called “Product_Review” with columns “review_id” (primary key),
#“product_id” (foreign key referencing Product.product_id), “customer_id” (foreign key
#referencing Customer.customer_id), “rating” and “review_text”.

CREATE TABLE Product_Review (
review_id INT PRIMARY KEY,
product_id INT,
customer_id INT,
rating int,
review_text varchar(50),

FOREIGN KEY (product_id) REFERENCES Product(product_id) ON UPDATE CASCADE ON DELETE CASCADE,
FOREIGN KEY (customer_id) references Customer(customer_id) ON UPDATE CASCADE ON DELETE CASCADE
);

#5- Rename the “Supplier_Product” table to “Product_Supplier”.

ALTER TABLE Supplier_Product
RENAME TO Product_Supplier;


#6- Change the data type of the “date” column in Transaction table from DATE to DATETIME.

ALTER TABLE Transaction
MODIFY COLUMN date DATETIME NOT NULL;

#7- Set the default value of the “rating” column in Product_Review table to 0.alter
	
ALTER TABLE Product_Review
ALTER COLUMN rating SET DEFAULT 0;

#8- Insert a new record into the Employee table with employee_id = 456, name = “Jane Doe”,
# contact_information = “456 Elm St, Anytown, USA”, and job_title = “Sales Manager”.

INSERT INTO Employee (employee_id , name ,contact_information, job_title)
VALUES				('456', 'Jane Doe' , '456 Elm St, Anytown, USA' , 'Sales Manager');
#SELECT * FROM Employee;

#9- Update the “unit_price” of all products in the Electronics category to increase by 10%.


UPDATE Product
SET unit_price = unit_price * 1.1
WHERE category_id = 'Electronics';



#10- Delete all reviews have “rating” less than 3.

DELETE FROM Product_Review
WHERE rating < 3;


#11- Delete all the products with a “unit_price” less than $5.

DELETE FROM Product
WHERE unit_price < 5;

#12- Update the “total_amount” of all transactions by adding 5% discount for customers with a “customer_id” of 3.

UPDATE Transaction
SET total_amount = total_amount * 0.95  
WHERE customer_id = 3;

#13 -Delete all rows from “Service_Transaction” table where the “service_id” is not in the House Keeping or Maintenance categories.

DELETE FROM Service_Transaction
WHERE service_id NOT IN (
  SELECT service_id
  FROM Service
  WHERE category_id IN ('House Keeping', 'Maintenance')
);

#14- Retrieve the names and total transaction amounts for all the transactions in the month of January.
  
 ALTER TABLE Transaction
 ADD name varchar(30);
SELECT name, SUM(total_amount) AS total_transaction_amount
FROM transaction
WHERE date like 'January%'
GROUP BY name;

  
#15- Retrieve the names and transaction dates of all transactions between January 1, 2022 and March 31, 2022  

SELECT name, SUM(total_amount) AS total_transaction_amount
FROM transaction
WHERE date BETWEEN 'January 1,2022' AND 'March 31, 2022'
GROUP BY name;  
  
#16- Retrieve the names and descriptions of all products that have been reviewed by customers
# with a rating of 3 or higher.

SELECT
  name,
  description
FROM Product
JOIN Product_Review
ON Product.product_id = Product_Review.product_id
WHERE rating >= 3;


#17- Add a new column “in_stock” (BOOLEAN) to the product table.

ALTER TABLE Product
ADD in_stock BOOlEAN;

#18- Retrieve all data of service provided by ABC Services.

SELECT *
FROM Service
WHERE provider_id = 'ABC Services';

#19- Retrieve the information of the products that have not been sold in the past month and
# currently in stock.

SELECT * FROM product
WHERE NOT EXISTS (
    SELECT
      *
    FROM transaction
    WHERE
      product_id = product.product_id
      AND date > CURRENT_DATE - INTERVAL 1 MONTH
  )
  AND in_stock = 1;

#20- Retrieve the names and costs of all the services that have been provided by provides in the
# “House Keeping” and Electronics categories.

SELECT name, cost FROM service
WHERE
  category_id IN ('House Keeping', 'Electronics');


#21- Retrieve the names and job titles of all employees who were hired in 2022.

ALTER TABLE Employee
ADD hire_date DATE;
SELECT name, job_title FROM Employee
WHERE hire_date LIKE '%2022' ;

#22- Retrieve the names and job titles of all those employees who worked on transactions
# involving products in the Home Goods Category order by names.

#23- Retrieve distinct customer id and customer name who have made transactions in April 2022
# order by customer id.

#24- Retrieve the names and contact information of all the suppliers who supply products that
# are currently out of stock.

#25- Retrieve the information of all products and services that cost more than $500.

#26- Drop the “Product_Review” table from the database
DROP TABLE Product_Review;

SET SQL_SAFE_UPDATES = 1;