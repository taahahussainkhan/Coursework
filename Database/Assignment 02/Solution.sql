DROP DATABASE MANUFACTURER_COMPANY;
CREATE DATABASE MANUFACTURER_COMPANY;
USE MANUFACTURER_COMPANY;
CREATE TABLE Customer (
	customer_id        			  	varchar(8)       UNIQUE       PRIMARY KEY,
	name			  			    varchar(15)      NOT NULL,
	contact_information    		    varchar(15)		 NOT NULL
);
CREATE TABLE Employee (
	employee_id 					varchar(8)      UNIQUE      PRIMARY KEY,
    name							varchar(15)		NOT NULL,
    contact_information   			varchar(15)		NOT NULL,
    job_title 						varchar(8)
 );
 CREATE TABLE Product_Category (
	category_id 						varchar(8)		UNIQUE		PRIMARY KEY,
    name								varchar(15)
);
 CREATE TABLE Product(
	product_id 						varchar(8)		UNIQUE		PRIMARY KEY,
    name							varchar(15)		NOT NULL,
    description						varchar(50)				,
    FOREIGN KEY(category_id)
    REFERENCES Product_Category(category_id),
	FOREIGN KEY(manufacturer_id)
    REFERENCES Manufacturer(manufacturer_id)
    );
CREATE TABLE Transaction (
	transaction_id 						varchar(8)		UNIQUE		PRIMARY KEY,
    date								date			,
    total_amount						int				NOT NULL,
	FOREIGN KEY(customer_id)
    REFERENCES Customer(customer_id),
	FOREIGN KEY(employee_id)
    REFERENCES Employee(employee_id)
    );
CREATE TABLE Product_Transaction (
	quantity							int				NOT NULL,
	FOREIGN KEY(transaction_id)
    REFERENCES Transaction(transaction_id),
	FOREIGN KEY(product_id)
    REFERENCES Product(product_id) 
);
CREATE TABLE Service_Transaction (
	FOREIGN KEY(transaction_id)
    REFERENCES Transaction(transaction_id),
	FOREIGN KEY(service_id)
    REFERENCES Service(service_id) 
);

CREATE TABLE Manufacturer(
	manufacturer_id 						varchar(8)		UNIQUE		PRIMARY KEY,
    name									varchar(15)
);
CREATE TABLE Supplier (
	supplier_id 						varchar(8)		UNIQUE		PRIMARY KEY,
	name								varchar(15),
	contact_information    		     	varchar(15)		 NOT NULL
    );
CREATE TABLE Supplier_product(
	FOREIGN KEY(transaction_id)
    REFERENCES Transaction(transaction_id),
	FOREIGN KEY(product_id)
    REFERENCES Product(product_id) 
);
CREATE TABLE Service (
	service_id 						varchar(8)		UNIQUE		PRIMARY KEY,
	name							varchar(15),
	description						varchar(50)				,
	cost							int,
	FOREIGN KEY(category_id)
    REFERENCES Service_Category(category_id),
	FOREIGN KEY(provider_id)
    REFERENCES Provider(provider_id) 
    );
CREATE TABLE Service_Category (
	category_id 					varchar(8)		UNIQUE		PRIMARY KEY,
    name							varchar(15)
    );
CREATE TABLE Provider (
	provider_id 					varchar(8)		UNIQUE		PRIMARY KEY,
    name							varchar(15)
    );
    