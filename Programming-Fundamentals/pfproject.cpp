#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
void enter_data(int*, int*, int*, int*, char*, int &);
void show_data(char, int, int*, int*, int*, int*, char*, int);
void choice(char, int, int*, int*, int*, int*, char*, int);
void option(char, int, int*, int*, int*, int*, char*, int);
void upd_roll(char, int, int* &, int*, int*, int*, char*, int);
void upd_marks_cs(char, int, int*, int* &, int*, int*, char*, int);
void upd_marks_cs_all(char, int, int*, int* &, int*, int*, char*, int);
void upd_marks_mh(char, int, int*, int*, int* &, int*, char*, int);
void upd_marks_mh_all(char, int, int*, int*, int*&, int*, char*, int);
void percent(int *, int*, int* &, char * &, int);
void sort(char, int, int*&, int*&, int*&, int*&, char*, int);
void del(char, int, int*&, int*&, int*&, int*&, char*, int);
int main()
{
	char c = 'Y';
	int opt = 0, size = 0;
	int *roll_no = NULL;
	roll_no = new int[1];
	int *marks_cs = NULL;
	marks_cs = new int[1];
	int *marks_mh = NULL;
	marks_mh = new int[1];
	int *perc = NULL;
	perc = new int[1];
	char *grade = NULL;
	grade = new char[1];
	cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t*************************************************" << endl;
	cout << "\t\t\t\t\t\tWelcome to Admin Panel" << endl;
	cout << "\t\t\t\t*************************************************" << endl;
	cout << endl;
	cout << endl;
	Sleep(700);
	system("CLS");
	enter_data(roll_no, marks_cs, marks_mh, perc, grade, size);
	choice(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);


}
void percent(int* marks_cs, int* marks_mh, int* &perc, char * &grade, int size)
{
	for (int i = 0; i < size; i++)
	{
		perc[i] = ((marks_cs[i] + marks_mh[i]) * 100) / 200;
		if (perc[i] >= 91 && perc[i] <= 100)
		{
			grade[i] = 'A';
		}
		else if (perc[i] >= 75 && perc[i] <= 90)
		{
			grade[i] = 'B';
		}
		else if (perc[i] >= 60 && perc[i] < 75)
		{
			grade[i] = 'C';
		}
		else if (perc[i] >= 50 && perc[i] < 60)
		{
			grade[i] = 'D';
		}
		else if (perc[i] < 50)
		{
			grade[i] = 'F';
		}
	}
}
void choice(char c, int opt, int*  roll_no, int*  marks_cs, int*  marks_mh, int* perc, char* grade, int size)
{
	cout << "Do you want to perform any operation on data . " << endl;
	cout << "Press Y/y for YES " << endl;
	cout << "Press N/n for NO ." << endl;
	cout << "Enter your choice : ";
	cin >> c;
	if (c == 'Y' || c == 'y')
	{
		system("CLS");
		option(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);
	}
	else if (c == 'N' || c == 'n')
	{
		system("CLS");
		show_data(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);
	}
	else
	{
		while (!(c == 'Y' || c == 'y' || c == 'N' || c == 'n'))
		{
			cout << "Invalid Character!" << endl;
			cout << "Enter Y/y to continue entering data of students and N/n to stop : ";
			cin >> c;
			if (c == 'Y' || c == 'y')
			{
				system("CLS");
				option(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);
			}
			else if (c == 'N' || c == 'n')
			{
				system("CLS");
				show_data(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);
			}
		}
	}
}
void option(char c, int opt, int*  roll_no, int*  marks_cs, int*  marks_mh, int* perc, char* grade, int size)
{
	cout << "1.    Press 1 to update Roll number of particular student ." << endl;
	cout << "2.    Press 2 to update marks of particular student for CS ." << endl;
	cout << "3.    Press 3 to update marks of CS for all students who are already enrolled ." << endl;
	cout << "4.    Press 4 to update marks of particular student for Mathematics ." << endl;
	cout << "5.    Press 5 to update marks of Mathematics for all students who are already enrolled ." << endl;
	cout << "6.    Press 6 to sort data on the basis of generated percentages ." << endl;
	cout << "7.    Press 7 to delete the record of particular student ." << endl;
	cout << "8.    Press 8 to display the record  ." << endl;
	cout << "9.    Press any key  to exit program ." << endl;
	cout << "Enter your option : ";
	cin >> opt;
	switch (opt)
	{
	case 1:
		upd_roll(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);
		break;
	case 2:
		upd_marks_cs(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);
		break;
	case 3:
		upd_marks_cs_all(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);
		break;
	case 4:
		upd_marks_mh(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);
		break;
	case 5:
		upd_marks_mh_all(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);
		break;
	case 6:
		sort(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);
		break;
	case 7:
		del(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);
		break;
	case 8:
		system("CLS");
		show_data(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);
		break;
	default:
		exit;
		break;
	}
}
void enter_data(int*  roll_no, int*  marks_cs, int*  marks_mh, int* perc, char* grade, int &size)
{
	char c = 'Y';
	int roll;
	cout << "Enter Roll Number and their data to enroll students! " << endl;
	int i = 0, k = 1, b = 1;
	while (b != 0)
	{
		cout << "Enter Roll number of Student " << k << " :";
		cin >> roll;
		for (int j = 0; j <= i; j++)
		{
			if (roll == roll_no[j])
			{
				cout << "Roll number already exists :" << endl;
				cout << "Re-Enter Roll number of Student " << k << " :";
				cin >> roll;
				j = -1;
			}
		}
		roll_no[i] = roll;
		cout << "Enter Marks of Computer Science of Student " << k << " within 100 :";
		cin >> marks_cs[i];
		while (marks_cs[i] > 100)
		{
			cout << "Re-Enter Marks of Computer Science of Student " << k << " within 100 :";
			cin >> marks_cs[i];
		}
		cout << "Enter Marks of Mathematics of Student " << k << " within 100 :";
		cin >> marks_mh[i];
		while (marks_mh[i] > 100)
		{
			cout << "Re-Enter Marks of Computer Science of Student " << k << " within 100 :";
			cin >> marks_mh[i];
		}


		cout << "Enter Y/y to continue entering data of students and N/n to stop : ";
		cin >> c;
		if (c == 'Y' || c == 'y')
		{
			b = 1;
		}
		else if (c == 'N' || c == 'n')
		{
			b = 0;
		}
		else
		{
			while (!(c == 'Y' || c == 'y' || c == 'N' || c == 'n'))
			{
				cout << "Invalid Character!" << endl;
				cout << "Enter Y/y to continue entering data of students and N/n to stop : ";
				cin >> c;
				if (c == 'Y' || c == 'y')
				{
					b = 1;
				}
				else if (c == 'N' || c == 'n')
				{
					b = 0;
				}
			}
		}
		k++;
		i++;
		size++;
		system("CLS");

	}
	percent(marks_cs, marks_mh, perc, grade, size);

}
void show_data(char c, int opt, int*  roll_no, int*  marks_cs, int*  marks_mh, int* perc, char* grade, int size)
{

	percent(marks_cs, marks_mh, perc, grade, size);
	int k = 1;
	for (int i = 0; i < size; i++)
	{
		cout << "Roll Number of student " << k << " is " << roll_no[i] << endl;
		cout << "Marks of Computer Science of student " << k << " is " << marks_cs[i] << endl;
		cout << "Marks of Mathematics of student " << k << " is " << marks_mh[i] << endl;
		cout << "Percentage of student " << k << " is " << perc[i] << endl;
		cout << "Grade of student " << k << " is " << grade[i] << endl;
		k++;
	}
	cout << endl;
	Sleep(5000);
	system("CLS");
	choice(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);

}
void upd_roll(char c, int opt, int* & roll_no, int*  marks_cs, int*  marks_mh, int* perc, char* grade, int size)
{
	system("CLS");
	int roll = 0, r1, c0 = 0, b;
	cout << "Enter roll number to update : ";
	cin >> roll;

	do
	{
		c0 = 0;
		for (int j = 0; j < size; j++)
		{
			if (roll != roll_no[j])
			{
				c0++;
			}

		}
		if (c0 == size)
		{
			cout << "Roll does not exist" << endl;
			cout << "Enter the  roll number again " << endl;
			cin >> roll;
		}
	} while (c0 == size);
	int i = 0;
	while (i < size)
	{
		if (roll == roll_no[i])
		{
			b = i;
			cout << "Enter new Roll Number : ";
			cin >> r1;

		}
		i++;
	}
	for (int i = 0; i < size; i++)
	{
		if (r1 == roll_no[i])
		{
			cout << "Roll number already exists : " << endl;
			cout << "Re-Enter roll number : ";
			cin >> r1;
			i = -1;
		}
	}
	roll_no[b] = r1;
	cout << endl;
	system("CLS");
	Sleep(300);
	choice(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);

}
void upd_marks_cs(char c, int opt, int*  roll_no, int* & marks_cs, int*  marks_mh, int* perc, char* grade, int size)
{
	int index = 0, cs = 0;
	system("CLS");
	int roll = 0, c0 = 0;
	cout << "Enter roll number whose marks of cs needs to be updated : ";
	cin >> roll;
	int i = 0;
	do
	{
		c0 = 0;
		for (int j = 0; j < size; j++)
		{
			if (roll != roll_no[j])
			{
				c0++;
			}

		}
		if (c0 == size)
		{
			cout << "Roll does not exist" << endl;
			cout << "Enter the  roll number again " << endl;
			cin >> roll;
		}
	} while (c0 == size);
	 i = 0;
	while (i < size)
	{
		if (roll == roll_no[i])
		{
			index = i;
			cout << "Enter updated marks of cs : ";
			cin >> cs;
			while (cs > 100)
			{
				cout << "Re-Enter Marks of Computer Science ";
				cin >> cs;
			}

		}
		i++;
	}
	marks_cs[index] = cs;
	percent(marks_cs, marks_mh, perc, grade, size);
	cout << endl;
	system("CLS");
	Sleep(300);
	choice(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);

}
void upd_marks_cs_all(char c, int opt, int*  roll_no, int* & marks_cs, int*  marks_mh, int* perc, char* grade, int size)
{
	int index = 0, cs = 0;
	system("CLS");
	cout << "Enter updated marks of cs : ";
	cin >> cs;
	while (cs > 100)
	{
		cout << "Re-Enter Marks of Computer Science ";
		cin >> cs;
	}
	for (int i = 0; i < size; i++)
	{
		marks_cs[i] = cs;
	}
	percent(marks_cs, marks_mh, perc, grade, size);
	//cout << "New Roll number is " << roll_no[b] << " marks in cs is " << marks_cs[b] << " marks in math is " << marks_mh[b] << " percentage is " << perc[b] << " grade is " << grade[b] << endl;
	cout << endl;
	system("CLS");
	Sleep(300);
	choice(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);

}
void upd_marks_mh(char c, int opt, int*  roll_no, int*  marks_cs, int* & marks_mh, int* perc, char* grade, int size)
{
	int index = 0, mh= 0;
	system("CLS");
	int roll = 0, c0 = 0;
	cout << "Enter roll number whose marks of mathematics needs to be updated : ";
	cin >> roll;
	int i = 0;
	do
	{
		c0 = 0;
		for (int j = 0; j < size; j++)
		{
			if (roll != roll_no[j])
			{
				c0++;
			}

		}
		if (c0 == size)
		{
			cout << "Roll does not exist" << endl;
			cout << "Enter the roll number again" << endl;
			cin >> roll;
		}
	} while (c0 == size);
	 i = 0;
	while (i < size)
	{
		if (roll == roll_no[i])
		{
			index = i;
			cout << "Enter updated marks of mathematics : ";
			cin >> mh;
			while (mh > 100)
			{
				cout << "Re-Enter Marks of Mathematics ";
				cin >> mh;
			}

		}
		i++;
	}
	marks_mh[index] = mh;
	percent(marks_cs, marks_mh, perc, grade, size);
	cout << endl;
	system("CLS");
	Sleep(300);
	choice(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);

}
void upd_marks_mh_all(char c, int opt, int*  roll_no, int*  marks_cs, int* & marks_mh, int* perc, char* grade, int size)
{
	int index = 0, mh = 0;
	system("CLS");
	cout << "Enter updated marks of math : ";
	cin >> mh;
	while (mh > 100)
	{
		cout << "Re-Enter Marks of Mathematics ";
		cin >> mh;
	}
	for (int i = 0; i < size; i++)
	{
		marks_mh[i] = mh;

	}
	percent(marks_cs, marks_mh, perc, grade, size);
	//cout << "New Roll number is " << roll_no[b] << " marks in cs is " << marks_cs[b] << " marks in math is " << marks_mh[b] << " percentage is " << perc[b] << " grade is " << grade[b] << endl;
	cout << endl;
	system("CLS");
	Sleep(300);

	choice(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);

}
void sort(char c, int opt, int*  &roll_no, int*  &marks_cs, int* & marks_mh, int* &perc, char* grade, int size)
{
	int temp = 0;
	percent(marks_cs, marks_mh, perc, grade, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (perc[i]>perc[j])
			{
				temp = perc[i];
				perc[i] = perc[j];
				perc[j] = temp;
				temp = roll_no[i];
				roll_no[i] = roll_no[j];
				roll_no[j] = temp;
				temp = marks_cs[i];
				marks_cs[i] = marks_cs[j];
				marks_cs[j] = temp;
				temp = marks_mh[i];
				marks_mh[i] = marks_mh[j];
				marks_mh[j] = temp;
			}

		}
	}
	cout << "Data Sorted !" << endl;
	Sleep(300);
	system("CLS");
	Sleep(300);

	choice(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);
}
void del(char c, int opt, int*  &roll_no, int*  &marks_cs, int* & marks_mh, int* &perc, char* grade, int size)
{
	system("CLS");
	int roll = 0,  c0 = 0;
	cout << "Enter roll number to Delete : ";
	cin >> roll;

	do
	{
		c0 = 0;
		for (int j = 0; j < size; j++)
		{
			if (roll != roll_no[j])
			{
				c0++;
			}

		}
		if (c0 == size)
		{
			cout << "Roll does not exist" << endl;
			cout << "Enter the  roll number again " << endl;
			cin >> roll;
		}
	} while (c0 == size);
	int i = 0;
	while (i < size)
	{
		if (roll == roll_no[i])
		{
			roll_no[i] = roll_no[i+1];
			marks_cs[i] = marks_cs[i + 1];
			marks_mh[i] = marks_mh[i + 1];
			size--;
		}
		i++;
	}
	cout << "Data Deleted !" << endl;
	Sleep(300);
	system("CLS");
	Sleep(300);

	choice(c, opt, roll_no, marks_cs, marks_mh, perc, grade, size);
}