Create database office;
use office;
show tables;

Create table department(

DepartmentId Varchar(15) NOT null,
DepartmentName varchar(15),
NoOfEmployee int(11)

);


Create table shift(

ShiftId Varchar(15) Not null,
ShiftName varchar(15),
EndTime Time,
StartTime Time,
Rate Double

);