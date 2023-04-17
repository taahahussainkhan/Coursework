#include<iostream>
#include<Windows.h>
using namespace std;
int main()
{
	int   f = 0, select, temp = 0, temp4 = 0, stop1, flag = 1, roll1 = 0, size1 = 50, index = 0, g = 0, x;
	bool  all = true;
	char all1, temp3 = 0, chax, grades[100] = { 0 };
	int roll[100] = { 44, 28, 29, 30, 50, 43, 7, 8, 21, 10, 41, 12,
		1, 14, 15, 16, 25, 26, 37, 48, 19, 31, 32, 33, 34, 13, 2, 3, 40, 20, 9, 22, 23, 24,
		27, 35, 46, 17, 38, 39, 42,
		11, 4, 6, 45, 47, 18, 49, 5, 36 };
	int	 clas[100] = { 6, 7, 4, 3, 7, 1, 9, 8, 7, 8, 7, 3, 6, 7, 4, 3, 7, 1, 9, 8, 7, 3, 6, 7,
		4, 3, 7, 4, 3, 7, 1, 9, 8, 7, 7, 1, 9, 8, 3, 6, 7, 4, 3, 7, 1, 9, 7, 3, 6, 3, };
	float temp1 = 0, temp2 = 0, mid[100] = { 44.6, 36.5, 31.5, 43.5, 20.6, 21.5, 25.5, 41, 36.5, 39, 25.5, 42.5, 13.5,
		25.5, 29, 45, 29.5, 30.5, 34.5, 12, 24.5, 35.5, 36, 42.5, 41, 43.5,
		46.5, 45.5, 49.5, 20.5, 10.5, 48.5, 36.5, 37.5, 20.5, 21, 25.5, 29.5, 46.5, 36.5, 36.5, 20.5, 21, 25.5, 48.5,
		36.5, 35.5, 44.5, 20.5, 21.5 };
	float finals[100] = { 80.5, 90.5, 96.5, 52, 78.5, 63.5, 10.5, 25, 78.5, 86.5,
		25.5, 28.5, 78.5, 56.5, 98, 48, 56.5,
		23.5, 95.5, 84.5, 12.5, 82.5, 83.5, 69.5, 76.5, 99, 59, 63.5, 57.5, 66.5, 98.5, 99.5,
		96.5, 96.5, 83.5, 78.5, 93.5, 63.5, 65.5, 42.5, 89.5, 86.5, 88.5, 90.5, 37, 45.5, 85, 74.5, 71.5, 96.5 };
	system("color 08");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t --";
	Sleep(50);
	cout << "--";
	Sleep(50);
	cout << "--";
	Sleep(50);
	cout << "--";
	Sleep(50);
	cout << "--";
	Sleep(50);
	cout << "--";
	Sleep(50);
	cout << "--";
	Sleep(50);
	cout << "--";
	Sleep(50);
	cout << "--";
	Sleep(50);
	cout << "--";
	Sleep(50);
	cout << "--";
	Sleep(50);
	cout << "-\n";
	Sleep(50);
	cout << "\t\t\t\t\t\t| ";
	cout << "T";
	Sleep(50);
	cout << " ";
	Sleep(50);
	cout << "A";
	Sleep(50);
	cout << " ";
	Sleep(50);
	cout << "A";
	Sleep(50);
	cout << " ";
	Sleep(50);
	cout << "H";
	Sleep(50);
	cout << " ";
	Sleep(50);
	cout << "A";
	Sleep(50);
	cout << "  ";
	Sleep(50);
	cout << "&";
	Sleep(50);
	cout << "  ";
	Sleep(50);
	cout << "N";
	Sleep(50);
	cout << " ";
	Sleep(50);
	cout << "O";
	Sleep(50);
	cout << " ";
	Sleep(50);
	cout << "M";
	Sleep(50);
	cout << " ";
	Sleep(50);
	cout << "I";
	Sleep(50);
	cout << " |";
	Sleep(50);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t --";
	cout << "--";
	Sleep(50);
	cout << "--";
	Sleep(50);
	cout << "--";
	Sleep(50);
	cout << "--";
	Sleep(50);
	cout << "--";
	Sleep(50);
	cout << "--";
	Sleep(50);
	cout << "--";
	Sleep(50);
	cout << "--";
	Sleep(50);
	cout << "--";
	Sleep(50);
	cout << "--";
	Sleep(50);
	cout << "-\n";
	system("color 06");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t        ------------------\n";
	cout << "\t\t\t\t\t\t| ITC LAB PROJECT |";
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t------------------\n\n\n\n\n\n\n\n\n\n\n\n";
	Sleep(500);
	system("color 03");
	cout << "\t\t|Roll Number|\t|Midterm Marks|\t|Final Marks|\t  |Class|\t |Grades|\n";
	while (g < 50)
	{
		if (finals[g] >= 86)
			grades[g] = 'A';
		else if (finals[g] >= 73 && finals[g] <= 85)
			grades[g] = 'B';
		else if (finals[g] >= 60 && finals[g] <= 72)
			grades[g] = 'C';
		else if (finals[g] >= 50 && finals[g] <= 59)
			grades[g] = 'D';
		else if (finals[g] < 50)
			grades[g] = 'F';
		g++;
	}
	for (int f = 0; f < 50; f++)
	{
		cout << "\t\t-----------\t-----------\t-----------\t-----------\t-----------\n";
		cout << "\t\t    " << roll[f] << "\t\t   " << mid[f] << "\t\t   " << finals[f] << "\t\t    " << clas[f] << " \t\t    " << grades[f] << endl;
	}
	Sleep(2000);
	system("color F5");
	while (all)
	{
		cout << "1. Sort and display all the records roll number wise in ascending order\n\n";
		cout << "2.Sort and display all the records roll number wise in descending order.\n\n";
		cout << "3.Sort and display all records in ascending order based on marks in Midterm.\n\n";
		cout << "4.Sort and display all records in descending order based on marks in Midterm.\n\n";
		cout << "5.Sort and display all records in ascending order based on marks in Final.\n\n";
		cout << "6.Sort and display all records in descending order based on marks in Final.\n\n";
		cout << "7.Sort and display all records in ascending order based on Grade.\n\n";
		cout << "8.Sort and display all records in descending order based on Grade.\n\n";
		cout << "9.Add a new entry of a student.\n\n";
		cout << "10.Delete a student record based on his roll number.\n\n";
		cout << "11.Display record of all the students greater than X marks in final exam(in descending order with respect to marks obtained in final exam).The value of X will be entered by the user.\n\n";
		cout << "12.Display record of all the students greater than X marks in final exam(in ascending order with respect to marks obtained in final exam).The value of X will be entered by the user.\n\n";
		cout << "13.Display record of all the students less than or equal to X marks in final exam(in descending order with respect to marks obtained in final exam).The value of X will be entered by the user.\n\n";
		cout << "14.Display record of all the students less than or equal to X marks in final exam(in ascending order with respect to marks obtained in final exam).The value of X will be entered by the user.\n\n";
		cout << "15.Display record of all the students greater than X grade(in descending order with respect to grade).The value of X(character) will be entered by the user.\n\n";
		cout << "16.Display record of all the students greater than X grade(in ascending order with respect to grade).The value of X(character) will be entered by the user.\n\n";
		cout << "17.Display record of all the students less than or equal to X grade(in descending order with respect to grade).The value of X(character) will be entered by the user.\n\n";
		cout << "18.Display record of all the students less than or equal to X grade(in ascending order with respect to grade).The value of X(character) will be entered by the user.\n\n";
		cin >> select;
		if (select >= 1 && select <= 18)
		{
			if (select == 1)//1. Sort and display all the records roll number wise in ascending order
			{
				system("color 03");
				cout << "----------------";
				cout << "Sorted and displayed all the records roll number wise in ascending order----------------\n" << endl;
				cout << "\t\tRoll Number\tMidterm Marks\tFinal Marks\t  Class\t         Grades\n";
				for (int f = 0; f < size1; f++)
				{
					for (int ii = 0; ii < size1; ii++)
					{
						for (int jj = ii + 1; jj<size1; jj++)
						{
							if (roll[ii]>roll[jj])
							{
								temp = roll[ii];
								roll[ii] = roll[jj];
								roll[jj] = temp;
								temp1 = mid[ii];
								mid[ii] = mid[jj];
								mid[jj] = temp1;
								temp2 = finals[ii];
								finals[ii] = finals[jj];
								finals[jj] = temp2;
								temp3 = grades[ii];
								grades[ii] = grades[jj];
								grades[jj] = temp3;
								temp4 = clas[ii];
								clas[ii] = clas[jj];
								clas[jj] = temp4;


							}
						}
					}
					cout << "\t\t-----------\t-----------\t-----------\t-----------\t-----------\n";
					cout << "\t\t    " << roll[f] << "\t\t   " << mid[f] << "\t\t   " << finals[f] << "\t\t    " << clas[f] << " \t\t    " << grades[f] << endl;
				}

			}
			else if (select == 2)//2.Sort and display all the records roll number wise in descending order
			{
				system("color 03");
				cout << "----------------";
				cout << "Sorted and displayed all the records roll number wise in descending order----------------\n" << endl;
				cout << "\t\tRoll Number\tMidterm Marks\tFinal Marks\t  Class\t         Grades\n";
				for (int f = 0; f < size1; f++)
				{
					for (int ii = 0; ii < size1; ii++)
					{
						for (int jj = ii + 1; jj < size1; jj++)
						{
							if (roll[ii] < roll[jj])
							{
								temp = roll[ii];
								roll[ii] = roll[jj];
								roll[jj] = temp;
								temp1 = mid[ii];
								mid[ii] = mid[jj];
								mid[jj] = temp1;
								temp2 = finals[ii];
								finals[ii] = finals[jj];
								finals[jj] = temp2;
								temp3 = grades[ii];
								grades[ii] = grades[jj];
								grades[jj] = temp3;
								temp4 = clas[ii];
								clas[ii] = clas[jj];
								clas[jj] = temp4;


							}
						}
					}
					cout << "\t\t-----------\t-----------\t-----------\t-----------\t-----------\n";
					cout << "\t\t    " << roll[f] << "\t\t   " << mid[f] << "\t\t   " << finals[f] << "\t\t    " << clas[f] << " \t\t    " << grades[f] << endl;
				}
			}
			else if (select == 3)//3.Sort and display all records in ascending order based on marks in Midterm.
			{
				system("color 03");
				cout << "----------------";
				cout << "Sorted and displayed all records in ascending order based on marks in Midterm.----------------\n" << endl;
				cout << "\t\tRoll Number\tMidterm Marks\tFinal Marks\t  Class\t         Grades\n";
				for (int f = 0; f < size1; f++)
				{
					for (int ii = 0; ii < size1; ii++)
					{
						for (int jj = ii + 1; jj<size1; jj++)
						{
							if (mid[ii]>mid[jj])
							{
								temp = roll[ii];
								roll[ii] = roll[jj];
								roll[jj] = temp;
								temp1 = mid[ii];
								mid[ii] = mid[jj];
								mid[jj] = temp1;
								temp2 = finals[ii];
								finals[ii] = finals[jj];
								finals[jj] = temp2;
								temp3 = grades[ii];
								grades[ii] = grades[jj];
								grades[jj] = temp3;
								temp4 = clas[ii];
								clas[ii] = clas[jj];
								clas[jj] = temp4;


							}
						}
					}
					cout << "\t\t-----------\t-----------\t-----------\t-----------\t-----------\n";
					cout << "\t\t    " << roll[f] << "\t\t   " << mid[f] << "\t\t   " << finals[f] << "\t\t    " << clas[f] << " \t\t    " << grades[f] << endl;
				}
			}
			else if (select == 4)//2.Sort and display all the records roll number wise in descending order
			{
				system("color 03");
				cout << "----------------";
				cout << "Sorted and displayed all records in descending order based on marks in Midterm.----------------\n" << endl;
				cout << "\t\tRoll Number\tMidterm Marks\tFinal Marks\t  Class\t         Grades\n";
				for (int f = 0; f < size1; f++)
				{
					for (int ii = 0; ii < size1; ii++)
					{
						for (int jj = ii + 1; jj < size1; jj++)
						{
							if (mid[ii] < mid[jj])
							{
								temp = roll[ii];
								roll[ii] = roll[jj];
								roll[jj] = temp;
								temp1 = mid[ii];
								mid[ii] = mid[jj];
								mid[jj] = temp1;
								temp2 = finals[ii];
								finals[ii] = finals[jj];
								finals[jj] = temp2;
								temp3 = grades[ii];
								grades[ii] = grades[jj];
								grades[jj] = temp3;
								temp4 = clas[ii];
								clas[ii] = clas[jj];
								clas[jj] = temp4;


							}
						}
					}
					cout << "\t\t-----------\t-----------\t-----------\t-----------\t-----------\n";
					cout << "\t\t    " << roll[f] << "\t\t   " << mid[f] << "\t\t   " << finals[f] << "\t\t    " << clas[f] << " \t\t    " << grades[f] << endl;
				}
			}
			else if (select == 5)//5.Sort and display all records in ascending order based on marks in Final.
			{
				system("color 03");
				cout << "----------------";
				cout << "Sorted and displayed all records in ascending order based on marks in Finals.----------------\n" << endl;
				cout << "\t\tRoll Number\tMidterm Marks\tFinal Marks\t  Class\t         Grades\n";
				for (int f = 0; f < size1; f++)
				{
					for (int ii = 0; ii < size1; ii++)
					{
						for (int jj = ii + 1; jj<size1; jj++)
						{
							if (finals[ii]>finals[jj])
							{
								temp = roll[ii];
								roll[ii] = roll[jj];
								roll[jj] = temp;
								temp1 = mid[ii];
								mid[ii] = mid[jj];
								mid[jj] = temp1;
								temp2 = finals[ii];
								finals[ii] = finals[jj];
								finals[jj] = temp2;
								temp3 = grades[ii];
								grades[ii] = grades[jj];
								grades[jj] = temp3;
								temp4 = clas[ii];
								clas[ii] = clas[jj];
								clas[jj] = temp4;


							}
						}
					}
					cout << "\t\t-----------\t-----------\t-----------\t-----------\t-----------\n";
					cout << "\t\t    " << roll[f] << "\t\t   " << mid[f] << "\t\t   " << finals[f] << "\t\t    " << clas[f] << " \t\t    " << grades[f] << endl;
				}

			}
			else if (select == 6)//6.Sort and display all records in descending order based on marks in Final.
			{
				system("color 03");
				cout << "----------------";
				cout << "Sorted and displayed all records in descending order based on marks in Finals.----------------\n" << endl;
				cout << "\t\tRoll Number\tMidterm Marks\tFinal Marks\t  Class\t         Grades\n";
				for (int f = 0; f < size1; f++)
				{
					for (int ii = 0; ii < size1; ii++)
					{
						for (int jj = ii + 1; jj < size1; jj++)
						{
							if (finals[ii] < finals[jj])
							{
								temp = roll[ii];
								roll[ii] = roll[jj];
								roll[jj] = temp;
								temp1 = mid[ii];
								mid[ii] = mid[jj];
								mid[jj] = temp1;
								temp2 = finals[ii];
								finals[ii] = finals[jj];
								finals[jj] = temp2;
								temp3 = grades[ii];
								grades[ii] = grades[jj];
								grades[jj] = temp3;
								temp4 = clas[ii];
								clas[ii] = clas[jj];
								clas[jj] = temp4;


							}
						}
					}
					cout << "\t\t-----------\t-----------\t-----------\t-----------\t-----------\n";
					cout << "\t\t    " << roll[f] << "\t\t   " << mid[f] << "\t\t   " << finals[f] << "\t\t    " << clas[f] << " \t\t    " << grades[f] << endl;
				}
			}
			else if (select == 7)//7.Sort and display all records in ascending order based on Grade.
			{
				system("color 03");
				cout << "----------------";
				cout << "Sorted and displayed all records in ascending order based on Grades.----------------\n" << endl;
				cout << "\t\tRoll Number\tMidterm Marks\tFinal Marks\t  Class\t         Grades\n";
				for (int f = 0; f < size1; f++)
				{
					for (int ii = 0; ii < size1; ii++)
					{
						for (int jj = ii + 1; jj<size1; jj++)
						{
							if (grades[ii]>grades[jj])
							{
								temp = roll[ii];
								roll[ii] = roll[jj];
								roll[jj] = temp;
								temp1 = mid[ii];
								mid[ii] = mid[jj];
								mid[jj] = temp1;
								temp2 = finals[ii];
								finals[ii] = finals[jj];
								finals[jj] = temp2;
								temp3 = grades[ii];
								grades[ii] = grades[jj];
								grades[jj] = temp3;
								temp4 = clas[ii];
								clas[ii] = clas[jj];
								clas[jj] = temp4;


							}
						}
					}
					cout << "\t\t-----------\t-----------\t-----------\t-----------\t-----------\n";
					cout << "\t\t    " << roll[f] << "\t\t   " << mid[f] << "\t\t   " << finals[f] << "\t\t    " << clas[f] << " \t\t    " << grades[f] << endl;
				}

			}
			else if (select == 8)//8.Sort and display all records in descending order based on Grade.
			{
				system("color 03");
				cout << "----------------";
				cout << "Sorted and displayed all records in descending order based on Grades.----------------\n" << endl;
				cout << "\t\tRoll Number\tMidterm Marks\tFinal Marks\t  Class\t         Grades\n";
				for (int f = 0; f < size1; f++)
				{
					for (int ii = 0; ii < size1; ii++)
					{
						for (int jj = ii + 1; jj < size1; jj++)
						{
							if (grades[ii] < grades[jj])
							{
								temp = roll[ii];
								roll[ii] = roll[jj];
								roll[jj] = temp;
								temp1 = mid[ii];
								mid[ii] = mid[jj];
								mid[jj] = temp1;
								temp2 = finals[ii];
								finals[ii] = finals[jj];
								finals[jj] = temp2;
								temp3 = grades[ii];
								grades[ii] = grades[jj];
								grades[jj] = temp3;
								temp4 = clas[ii];
								clas[ii] = clas[jj];
								clas[jj] = temp4;


							}
						}
					}
					cout << "\t\t-----------\t-----------\t-----------\t-----------\t-----------\n";
					cout << "\t\t    " << roll[f] << "\t\t   " << mid[f] << "\t\t   " << finals[f] << "\t\t    " << clas[f] << " \t\t    " << grades[f] << endl;
				}
			}
			else if (select == 9)//9.Add a new entry of a student.
			{
				system("color 03");
				cout << "Enter roll number(must be unique) :";
				cin >> roll1;
				for (f = 0; f < size1 && flag == 1; f++)
				if (roll1 == roll[f])
					flag = 0;
				while (flag != 1)
				{
					flag = 1;
					cout << "Invalid roll number" << endl;
					cout << "Input roll number again \nRoll number must be unique";
					cin >> roll1;
					for (int i = 0; i < size1 && flag == 1; i++)
					if (roll1 == roll[i])
						flag = 0;
				}
				roll[size1] = roll1;
				cout << "Input Mids Marks  :  ";
				cin >> mid[size1];
				while (mid[size1] < 0 || mid[size1]>50)
				{
					cout << "Invalid input\n";
					if (mid[size1] < 0)
						cout << "Marks must not be negative\n";
					else if (mid[size1] > 50)
						cout << "Marks must be out of 50\n";
					cout << "Input Mids Marks again  :  ";
					cin >> mid[size1];
				}
				cout << "Input Final Marks   :  ";
				cin >> finals[size1];
				while (finals[size1] < 0 || finals[size1]>100)
				{
					cout << "Invalid input\n";
					if (finals[size1] < 0)
						cout << "Marks must not be negative\n";
					else if (finals[size1] > 50)
						cout << "Marks must be out of 100\n";
					cout << "Input Final Marks again  :  ";
					cin >> finals[size1];
				}
				cout << "Input class  :  ";
				cin >> clas[size1];
				while (clas[size1] < 0 || clas[size1]>10)
				{
					cout << "Invalid input\n";
					if (clas[size1] < 0)
						cout << "Class can not be negative\n";
					else if (clas[size1] > 10)
						cout << "Class can not be greater than 10\n";
					cout << "Input class again  :  ";
					cin >> clas[size1];
				}
				for (int f = 0; f <= size1; f++){
					if (finals[f] >= 86)
						grades[size1] = 'A';
					else if (finals[f] >= 73 && finals[f] <= 85)
						grades[size1] = 'B';
					else if (finals[f] >= 60 && finals[f] <= 72)
						grades[size1] = 'C';
					else if (finals[f] >= 50 && finals[f] <= 59)
						grades[size1] = 'D';
					else if (finals[f] < 50)
						grades[size1] = 'F';
				}

				cout << "Record Successfully added" << endl;
				Sleep(2000);
				for (int f = 0; f < (size1 + 1); f++)
				{
					for (int ii = 0; ii <50; ii++)
					{
						for (int jj = ii + 1; jj<(size1 + 1); jj++)
						{
							if (roll[ii]>roll[jj])
							{
								temp = roll[ii];
								roll[ii] = roll[jj];
								roll[jj] = temp;
								temp1 = mid[ii];
								mid[ii] = mid[jj];
								mid[jj] = temp1;
								temp2 = finals[ii];
								finals[ii] = finals[jj];
								finals[jj] = temp2;
								temp3 = grades[ii];
								grades[ii] = grades[jj];
								grades[jj] = temp3;
								temp4 = clas[ii];
								clas[ii] = clas[jj];
								clas[jj] = temp4;
							}
						}
					}
					cout << "\t\t-----------\t-----------\t-----------\t-----------\t-----------\n";
					cout << "\t\t    " << roll[f] << "\t\t   " << mid[f] << "\t\t   " << finals[f] << "\t\t    " << clas[f] << " \t\t    " << grades[f] << endl;

				}size1++;

			}
			else if (select == 10)
			{
				system("color 03");
				flag = 0;
				cout << "\nInput roll number ";
				cin >> roll1;
				while ((flag != 1))
				{
					for (int f = 0; f < size1 && flag == 0; f++)
					if (roll1 == roll[f])
					{
						flag = 1;
						index = f;
					}
					if (flag == 0)
					{
						cout << "\nInvalid input";
						cout << "\nRoll number does not exist";
						cout << "\nInput roll number again";
						cin >> roll1;
					}
				}
				for (int f = index; f < size1; f++)
				{
					roll[f] = roll[f + 1];
					mid[f] = mid[f + 1];
					finals[f] = finals[f + 1];
					clas[f] = clas[f + 1];
					grades[f] = grades[f + 1];
				}
				cout << endl;
				cout << "Record Successfully deleted" << endl;
				Sleep(2000);
				for (int f = 0; f < size1; f++)
				{
					for (int ii = 0; ii < size1; ii++)
					{
						for (int jj = ii + 1; jj<size1; jj++)
						{
							if (roll[ii]>roll[jj])
							{
								temp = roll[ii];
								roll[ii] = roll[jj];
								roll[jj] = temp;
								temp1 = mid[ii];
								mid[ii] = mid[jj];
								mid[jj] = temp1;
								temp2 = finals[ii];
								finals[ii] = finals[jj];
								finals[jj] = temp2;
								temp3 = grades[ii];
								grades[ii] = grades[jj];
								grades[jj] = temp3;
								temp4 = clas[ii];
								clas[ii] = clas[jj];
								clas[jj] = temp4;
							}
						}
					}
					cout << "\t\t-----------\t-----------\t-----------\t-----------\t-----------\n";
					cout << "\t\t    " << roll[f] << "\t\t   " << mid[f] << "\t\t   " << finals[f] << "\t\t    " << clas[f] << " \t\t    " << grades[f] << endl;
				}

				size1--;
			}
			else if (select == 11)//11.Display record of all the students greater than X marks in 
			{	                 //final exam (in descending order with respect to marks obtained in final exam). The value of X will be entered by the user.
				system("color 03");
				cout << "ENTER THE VALUE OF 'X' : ";
				cin >> x;
				cout << "--------------";
				cout << "Displaying record in descending order of all the students greater than " << x << " marks in Finals.--------------\n" << endl;
				cout << "\t\tRoll Number\tMidterm Marks\tFinal Marks\t  Class\t         Grades\n";
				for (int f = 0; f < size1; f++)
				{
					for (int ii = 0; ii < size1; ii++)
					{
						for (int jj = ii + 1; jj < size1; jj++)
						{
							if (finals[ii] < finals[jj])
							{
								temp = roll[ii];
								roll[ii] = roll[jj];
								roll[jj] = temp;
								temp1 = mid[ii];
								mid[ii] = mid[jj];
								mid[jj] = temp1;
								temp2 = finals[ii];
								finals[ii] = finals[jj];
								finals[jj] = temp2;
								temp3 = grades[ii];
								grades[ii] = grades[jj];
								grades[jj] = temp3;
								temp4 = clas[ii];
								clas[ii] = clas[jj];
								clas[jj] = temp4;
							}
						}
					}
					if (finals[f] > x)
					{
						cout << "\t\t-----------\t-----------\t-----------\t-----------\t-----------\n";
						cout << "\t\t    " << roll[f] << "\t\t   " << mid[f] << "\t\t   " << finals[f] << "\t\t    " << clas[f] << " \t\t    " << grades[f] << endl;
					}
				}
			}
			else if (select == 12)//12.	Display record of all the students greater than X marks in final exam
			{	                 //(in ascending order with respect to marks obtained in final exam). The value of X will be entered by the user.  
				system("color 03");
				cout << "ENTER THE VALUE OF 'X' : ";
				cin >> x;
				cout << "--------------";
				cout << "Displaying record in ascending order of all the students greater than " << x << " marks in Finals.--------------\n" << endl;
				cout << "\t\tRoll Number\tMidterm Marks\tFinal Marks\t  Class\t         Grades\n";
				for (int f = 0; f < size1; f++)
				{
					for (int ii = 0; ii < size1; ii++)
					{
						for (int jj = ii + 1; jj < size1; jj++)
						{
							if (finals[ii]>finals[jj])
							{
								temp = roll[ii];
								roll[ii] = roll[jj];
								roll[jj] = temp;
								temp1 = mid[ii];
								mid[ii] = mid[jj];
								mid[jj] = temp1;
								temp2 = finals[ii];
								finals[ii] = finals[jj];
								finals[jj] = temp2;
								temp3 = grades[ii];
								grades[ii] = grades[jj];
								grades[jj] = temp3;
								temp4 = clas[ii];
								clas[ii] = clas[jj];
								clas[jj] = temp4;
							}
						}
					}
					if (finals[f] > x)
					{
						cout << "\t\t-----------\t-----------\t-----------\t-----------\t-----------\n";
						cout << "\t\t    " << roll[f] << "\t\t   " << mid[f] << "\t\t   " << finals[f] << "\t\t    " << clas[f] << " \t\t    " << grades[f] << endl;
					}
				}
			}
			else if (select == 13)//13.Display record of all the students less than or equal to X marks in final exam
			{	                 //(in descending order with respect to marks obtained in final exam). The value of X will be entered by the user.  
				system("color 03");
				cout << "ENTER THE VALUE OF 'X' : ";
				cin >> x;
				cout << "--------------";
				cout << "Displaying record in descending order of all the students less than or equal to" << x << " marks in Finals.--------------\n" << endl;
				cout << "\t\tRoll Number\tMidterm Marks\tFinal Marks\t  Class\t         Grades\n";
				for (int f = 0; f < size1; f++)
				{
					for (int ii = 0; ii < size1; ii++)
					{
						for (int jj = ii + 1; jj < size1; jj++)
						{
							if (finals[ii] < finals[jj])
							{
								temp = roll[ii];
								roll[ii] = roll[jj];
								roll[jj] = temp;
								temp1 = mid[ii];
								mid[ii] = mid[jj];
								mid[jj] = temp1;
								temp2 = finals[ii];
								finals[ii] = finals[jj];
								finals[jj] = temp2;
								temp3 = grades[ii];
								grades[ii] = grades[jj];
								grades[jj] = temp3;
								temp4 = clas[ii];
								clas[ii] = clas[jj];
								clas[jj] = temp4;
							}
						}
					}
					if (finals[f] < x)
					{
						cout << "\t\t-----------\t-----------\t-----------\t-----------\t-----------\n";
						cout << "\t\t    " << roll[f] << "\t\t   " << mid[f] << "\t\t   " << finals[f] << "\t\t    " << clas[f] << " \t\t    " << grades[f] << endl;
					}
				}
			}
			else if (select == 14)//14.	Display record of all the students less than or equal to X marks in final exam
			{	                 //(in ascending order with respect to marks obtained in final exam). The value of X will be entered by the user.  
				system("color 03");
				cout << "ENTER THE VALUE OF 'X' : ";
				cin >> x;
				cout << "--------------";
				cout << "Displaying record in ascending order of all the students less than or equal to" << x << " marks in Finals.--------------\n" << endl;
				cout << "\t\tRoll Number\tMidterm Marks\tFinal Marks\t  Class\t         Grades\n";
				for (int f = 0; f < size1; f++)
				{
					for (int ii = 0; ii < size1; ii++)
					{
						for (int jj = ii + 1; jj < size1; jj++)
						{
							if (finals[ii]>finals[jj])
							{
								temp = roll[ii];
								roll[ii] = roll[jj];
								roll[jj] = temp;
								temp1 = mid[ii];
								mid[ii] = mid[jj];
								mid[jj] = temp1;
								temp2 = finals[ii];
								finals[ii] = finals[jj];
								finals[jj] = temp2;
								temp3 = grades[ii];
								grades[ii] = grades[jj];
								grades[jj] = temp3;
								temp4 = clas[ii];
								clas[ii] = clas[jj];
								clas[jj] = temp4;
							}
						}
					}
					if (finals[f] < x)
					{
						cout << "\t\t-----------\t-----------\t-----------\t-----------\t-----------\n";
						cout << "\t\t    " << roll[f] << "\t\t   " << mid[f] << "\t\t   " << finals[f] << "\t\t    " << clas[f] << " \t\t    " << grades[f] << endl;
					}
				}
			}
			else if (select == 15)//15.	Display record of all the students greater than X grade 
			{	                 //(in descending order with respect to grade). The value of X (character) will be entered by the user
				system("color 03");
				cout << "ENTER THE VALUE OF 'X' : ";
				cin >> chax;
				if ((chax == 'A') || (chax == 'B') || (chax == 'C') || (chax == 'D') || (chax == 'E') || (chax == 'F'))
				{
					cout << "--------------";
					cout << "Displaying record in descending order of all the students greater than " << chax << " Grade.--------------\n" << endl;
					cout << "\t\tRoll Number\tMidterm Marks\tFinal Marks\t  Class\t         Grades\n";
					for (int f = 0; f < size1; f++)
					{
						for (int ii = 0; ii < size1; ii++)
						{
							for (int jj = ii + 1; jj < size1; jj++)
							{
								if (grades[ii] > grades[jj])
								{
									temp = roll[ii];
									roll[ii] = roll[jj];
									roll[jj] = temp;
									temp1 = mid[ii];
									mid[ii] = mid[jj];
									mid[jj] = temp1;
									temp2 = finals[ii];
									finals[ii] = finals[jj];
									finals[jj] = temp2;
									temp3 = grades[ii];
									grades[ii] = grades[jj];
									grades[jj] = temp3;
									temp4 = clas[ii];
									clas[ii] = clas[jj];
									clas[jj] = temp4;
								}
							}
						}

						if (grades[f] < chax)
						{
							cout << "\t\t-----------\t-----------\t-----------\t-----------\t-----------\n";
							cout << "\t\t    " << roll[f] << "\t\t   " << mid[f] << "\t\t   " << finals[f] << "\t\t    " << clas[f] << " \t\t    " << grades[f] << endl;
						}
					}
				}
				else
				{
					cout << "Wrong Entry...!!!!\n\n\n";
					Sleep(2000);
					continue;
				}
			}
			else if (select == 16)//16.	Display record of all the students greater than X grade 
			{                        //(in ascending order with respect to grade). The value of X (character) will be entered by the user.  
				system("color 03");
				chax = 0;
				cout << "ENTER THE VALUE OF 'X' : ";
				cin >> chax;
				if ((chax == 'A') || (chax == 'B') || (chax == 'C') || (chax == 'D') || (chax == 'E') || (chax == 'F'))
				{
					cout << "--------------";
					cout << "Displaying record in ascending order of all the students greater than " << chax << " Grade.--------------\n" << endl;
					cout << "\t\tRoll Number\tMidterm Marks\tFinal Marks\t  Class\t         Grades\n";
					for (int f = 0; f < size1; f++)
					{
						for (int ii = 0; ii < size1; ii++)
						{
							for (int jj = ii + 1; jj < size1; jj++)
							{
								if (grades[ii] < grades[jj])
								{
									temp = roll[ii];
									roll[ii] = roll[jj];
									roll[jj] = temp;
									temp1 = mid[ii];
									mid[ii] = mid[jj];
									mid[jj] = temp1;
									temp2 = finals[ii];
									finals[ii] = finals[jj];
									finals[jj] = temp2;
									temp3 = grades[ii];
									grades[ii] = grades[jj];
									grades[jj] = temp3;
									temp4 = clas[ii];
									clas[ii] = clas[jj];
									clas[jj] = temp4;
								}
							}
						}
						if (grades[f] < chax)
						{
							cout << "\t\t-----------\t-----------\t-----------\t-----------\t-----------\n";
							cout << "\t\t    " << roll[f] << "\t\t   " << mid[f] << "\t\t   " << finals[f] << "\t\t    " << clas[f] << " \t\t    " << grades[f] << endl;
						}
					}
				}
				else
				{
					cout << "Wrong Entry...!!!!\n\n\n";
					Sleep(2000);
					continue;
				}


			}
			else if (select == 17)//17.	Display record of all the students less than or equal to X grade 
			{	                 //(in descending order with respect to grade). The value of X (character) will be entered by the user.   
				system("color 03");
				cout << "ENTER THE VALUE OF 'X' : ";
				cin >> chax;
				if ((chax == 'A') || (chax == 'B') || (chax == 'C') || (chax == 'D') || (chax == 'E') || (chax == 'F'))
				{
					cout << "--------------";
					cout << "Displaying record in descending order of all the students less than or equal to " << chax << " Grade.--------------\n" << endl;
					cout << "\t\tRoll Number\tMidterm Marks\tFinal Marks\t  Class\t         Grades\n";
					for (int f = 0; f < size1; f++)
					{
						for (int ii = 0; ii < size1; ii++)
						{
							for (int jj = ii + 1; jj < size1; jj++)
							{
								if (grades[ii] > grades[jj])
								{
									temp = roll[ii];
									roll[ii] = roll[jj];
									roll[jj] = temp;
									temp1 = mid[ii];
									mid[ii] = mid[jj];
									mid[jj] = temp1;
									temp2 = finals[ii];
									finals[ii] = finals[jj];
									finals[jj] = temp2;
									temp3 = grades[ii];
									grades[ii] = grades[jj];
									grades[jj] = temp3;
									temp4 = clas[ii];
									clas[ii] = clas[jj];
									clas[jj] = temp4;
								}
							}
						}

						if (grades[f] >= chax)
						{
							cout << "\t\t-----------\t-----------\t-----------\t-----------\t-----------\n";
							cout << "\t\t    " << roll[f] << "\t\t   " << mid[f] << "\t\t   " << finals[f] << "\t\t    " << clas[f] << " \t\t    " << grades[f] << endl;
						}
					}
				}
				else
				{
					cout << "Wrong Entry...!!!!\n\n\n";
					Sleep(2000);
					continue;
				}

			}
			else if (select == 18)//18.	Display record of all the students less than or equal to X grade 
			{	                 //(in ascending order with respect to grade). The value of X (character) will be entered by the user. 
				system("color 03");
				cout << "ENTER THE VALUE OF 'X' : ";
				cin >> chax;
				if ((chax == 'A') || (chax == 'B') || (chax == 'C')  || (chax == 'D') || (chax == 'E')  || (chax == 'F') )
				{
					cout << "--------------";
					cout << "Displaying record in descending order of all the students less than or equal to " << chax << " Grade.--------------\n" << endl;
					cout << "\t\tRoll Number\tMidterm Marks\tFinal Marks\t  Class\t         Grades\n";
					for (int f = 0; f < size1; f++)
					{
						for (int ii = 0; ii < size1; ii++)
						{
							for (int jj = ii + 1; jj < size1; jj++)
							{
								if (grades[ii] < grades[jj])
								{
									temp = roll[ii];
									roll[ii] = roll[jj];
									roll[jj] = temp;
									temp1 = mid[ii];
									mid[ii] = mid[jj];
									mid[jj] = temp1;
									temp2 = finals[ii];
									finals[ii] = finals[jj];
									finals[jj] = temp2;
									temp3 = grades[ii];
									grades[ii] = grades[jj];
									grades[jj] = temp3;
									temp4 = clas[ii];
									clas[ii] = clas[jj];
									clas[jj] = temp4;
								}
							}
						}
						if (grades[f] >= chax)
						{
							cout << "\t\t-----------\t-----------\t-----------\t-----------\t-----------\n";
							cout << "\t\t    " << roll[f] << "\t\t   " << mid[f] << "\t\t   " << finals[f] << "\t\t    " << clas[f] << " \t\t    " << grades[f] << endl;
						}
					}
				}
				else
				{
					cout << "Wrong Entry...!!!!\n\n\n";
					Sleep(2000);
					continue;
				}
			}

		}//else if ends
		cout << "Enter T to try again..!!";
		cin >> all1;
		if (all1 == 't' || all1 == 'T')
		{
			all = true;
		}
		else if (all1 != 't' || all1 != 'T')
		{
			all = false;
			system("color 08");
			cout << "THANK YOU...!!!!!\n";
		}
	}//while loop ends

	system("pause");
	return 0;
}