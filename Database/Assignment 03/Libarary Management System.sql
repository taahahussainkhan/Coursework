DROP DATABASE Library_Management_System;
CREATE DATABASE Library_Management_System;
USE Library_Management_System;
-- Tables 
CREATE TABLE Authors(
author_id 			varchar(8)					NOT NULL 				PRIMARY KEY,
author_name			varchar(20)					NOT NULL,
author_bio			varchar(200)
);
CREATE TABLE Categories(
category_id 			varchar(8)					NOT NULL 				PRIMARY KEY,
category_name			varchar(20)					NOT NULL,
category_description	varchar(200)
);
CREATE TABLE Books(
book_id 			varchar(8)					NOT NULL 				PRIMARY KEY,
book_title			varchar(60)					NOT NULL,
book_cost			int							NOT NULL,
author_id			varchar(8)					NOT NULL,
category_id			varchar(8)					NOT NULL,
FOREIGN KEY	(author_id)
REFERENCES	Authors(author_id),
FOREIGN KEY	(category_id)
REFERENCES	Categories(category_id)
);

CREATE TABLE Book_Authors(
book_id 			varchar(8)			NOT NULL,
author_id			varchar(8)			NOT NULL,
FOREIGN KEY (book_id)
REFERENCES	Books(book_id),
FOREIGN KEY (author_id)
REFERENCES	Authors(author_id)
);

CREATE TABLE Book_Copies(
copy_id				varchar(8)			NOT NULL,
copy_number			int					NOT NULL,
availability_status		varchar(20),
book_id				varchar(8),
FOREIGN KEY	(book_id)
REFERENCES	Books(book_id)
);

CREATE TABLE Borrowers(
borrower_id			varchar(8)			NOT NULL 		PRIMARY KEY,
borrower_email		varchar(55)				NOT NULL,
borrower_address	varchar(50),
first_name			varchar(30),
last_name			varchar(30)
);

CREATE TABLE Book_Borrowed(
borrow_id			varchar(8)			NOT NULL 		PRIMARY KEY,
borrow_date			date	,
return_date			date,
late_fees			int,
book_id				varchar(8),
borrower_id			varchar(8),
FOREIGN KEY	(book_id)
REFERENCES	Books(book_id),
FOREIGN KEY	(borrower_id)
REFERENCES	Borrowers(borrower_id)
);

CREATE TABLE Reviews(
review_id			varchar(8)			NOT NULL 		PRIMARY KEY,
rating				char				NOT NULL,
review_comment		varchar(150),
review_date			date				NOT NULL,
book_id				varchar(8),
borrower_id			varchar(8),
FOREIGN KEY	(book_id)
REFERENCES	Books(book_id),
FOREIGN KEY	(borrower_id)
REFERENCES	Borrowers(borrower_id)
);


# INSERTIONS


INSERT INTO Authors (author_id, author_name, author_bio) VALUES
('1', 'John Doe', 'John Doe is a writer.'),
('2', 'Jane Smith', 'Jane Smith is a journalist.'),
('3', 'Mark Johnson', 'Mark Johnson is a poet.'),
('4', 'Samantha Lee', 'Samantha Lee is a novelist.'),
('5', 'David Brown', 'David Brown is a playwright.'),
('6', 'Emily Davis', 'Emily Davis is a screenwriter.'),
('7', 'Michael Wilson', 'Michael Wilson is a biographer.'),
('8', 'Sarah Jones', 'Sarah Jones is a historian.'),
('9', 'Robert Green', 'Robert Green is a philosopher.'),
('10', 'Laura White', 'Laura White is an essayist.');

INSERT INTO Categories (category_id, category_name, category_description) VALUES
('1', 'Fiction', 'Fiction books.'),
('2', 'Non-fiction', 'Non-fiction books.'),
('3', 'Biography', 'Biography books.'),
('4', 'History', 'History books.'),
('5', 'Science', 'Science books.'),
('6', 'Poetry', 'Poetry books.'),
('7', 'Drama', 'Drama books.'),
('8', 'Comedy', 'Comedy books.'),
('9', 'Horror', 'Horror books.'),
('10', 'Mystery', 'Mystery books.');

INSERT INTO Books (book_id, book_title, book_cost, author_id, category_id)
VALUES ('1', 'The Great Gatsby', 20, '1', '1'),
       ('2', 'To Kill a Mockingbird', 15, '2', '2'),
       ('3', 'Pride and Prejudice', 18, '3', '3'),
       ('4', 'The Catcher in the Rye', 12, '4', '4'),
       ('5', '1984', 25, '5', '5'),
       ('6', 'Animal Farm', 10, '5', '5'),
       ('7', 'The Hobbit', 22, '6', '6'),
       ('8', 'The Lord of the Rings: The Fellowship of the Ring', 30, '6', '6'),
       ('9', 'The Lord of the Rings: The Two Towers', 30, '6', '6'),
       ('10','The Lord of the Rings: The Return of the King', 30, '6', '6');

INSERT INTO Book_Copies (copy_id, copy_number, availability_status, book_id)
VALUES ('1', 1, 'available', '1'),
       ('2', 2, 'not available', '2'),
       ('3', 3, 'available', '3'),
       ('4', 4, 'not available', '4'),
       ('5', 5, 'available', '5'),
       ('6', 6, 'not available', '6'),
       ('7', 7, 'available', '7'),
       ('8', 8, 'not available', '8'),
       ('9', 9, 'available', '9'),
       ('10', 10, 'not available', '10');


INSERT INTO Borrowers (borrower_id, borrower_email, borrower_address, first_name, last_name)
VALUES ('1', 'johndoe@example.com', '123 Main St', 'John', 'Doe'),
       ('2', 'janedoe@example.com', '456 Elm St', 'Jane', 'Doe'),
       ('3', 'bobsmith@example.com', '789 Oak St', 'Bob', 'Smith'),
       ('4', 'sarahjones@example.com', '1010 Cedar St', 'Sarah', 'Jones'),
       ('5', 'mikebrown@example.com', '1111 Pine St', 'Mike', 'Brown'),
       ('6', 'jessicajohnson@example.com', '2222 Maple St', 'Jessica', 'Johnson'),
       ('7', 'jimmyjohns@example.com', '111 Pine St', 'Jimmy', 'Johns'),
       ('8', 'jennyjenkins@example.com', '222 Elm St', 'Jenny', 'Jenkins'),
       ('9', 'davidsmith@example.com','333 Oak St','David','Smith'),
       ('10','josephsmith@example.com','1234 Maple St','Joseph','Smith');

INSERT INTO Book_Borrowed (borrow_id, borrow_date, return_date, late_fees, book_id, borrower_id)
VALUES ('B0001', '2023-06-05', '2023-06-07', 2000, '1', '1'),
       ('B0002', '2023-06-05', '2023-06-08', 0, '2', '2'),
       ('B0003', '2023-06-05', '2023-06-09', 3000, '3', '3'),
       ('B0004', '2023-06-05', '2023-06-10', 5200, '4', '4'),
       ('B0005', '2023-06-05', '2023-06-11', 0, '5', '5'),
       ('B0006', '2023-06-05', '2023-06-12', 1100, '6', '6'),
       ('B0007', '2023-06-05', '2023-06-13', 2100, '7', '7'),
       ('B0008', '2023-06-05', '2023-06-14', 0, '8', '8'),
       ('B0009', '2023-05-05', '2023-06-06', 4000, '9', '9'),
       ('B0010', '2023-06-03', '2023-06-09', 2500, '10', '10');
INSERT INTO Reviews (review_id, rating, review_comment, review_date, book_id, borrower_id)
VALUES
('R0001', '5', 'This book was amazing! I could not put it down.', '2023-06-01', '1', '1'),
('R0002', '4', 'This book was good, but not great. I would recommend it to fans of the genre.', '2023-06-02', '2', '2'),
('R0003', '3', 'This book was okay. I did not love it, but I did not hate it either.', '2023-06-03', '3', '3'),
('R0004', '2', 'This book was a disappointment. I expected more from the author.', '2023-06-04', '4', '4'),
('R0005', '1', 'This book was terrible! I could not finish it.', '2023-06-05', '5', '5'),
('R0006', '5', 'This book was a masterpiece! I will never forget it.', '2023-06-06', '6', '6'),
('R0007', '4', 'This book was a great read! I highly recommend it.', '2023-06-07', '7', '7'),
('R0008', '3', 'This book was okay. I did not love it, but I did not hate it either.', '2023-06-08', '8', '8'),
('R0009', '2', 'This book was a disappointment. I expected more from the author.', '2023-06-09', '9', '9');



# QUERIES
#---------------------------------------------------1
SELECT book_id, book_title, author_id, author_name
FROM Books
INNER JOIN Authors
ON Books.author_id = Authors.author_id;










