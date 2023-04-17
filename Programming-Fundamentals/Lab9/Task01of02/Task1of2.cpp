#include <iostream>
#include <fstream>
using namespace std;
void read_f1(int*, int*, int&, int&);
void read_f2(int*, int*, int&, int&);
void sort_f1(int*, int*, int, int);
void sort_f2(int*, int*, int, int);
int close_f1(int);
int close_f2(int);
void adj_f1(int*, int*, int, int);
void adj_f2(int*, int*, int, int);
int main()
{
	int size1 = 0, size2 = 0, size3 = 0, size4 = 0, selection = 0;
	int* reg1 = NULL; 
	reg1=new int[size1];
	int* marks1 = NULL;
	marks1= new int[size2];
	int* reg2 = NULL;
	reg2= new int[size3];
	int* marks2 = NULL;
	marks2= new int[size4];
	read_f1(reg1, marks1, size1, size2);
	read_f2(reg2, marks2, size3, size4);
	cout << "Press 1 to sort the record on the basis of registration number." << endl;
	cout << "Press 2 to identify those section who we need to close." << endl;
	cout << "Press 3 to identify those section in which we adjust the students of those section which we need to close." << endl;
	while (1)
	{
		cout << " ";
		cin >> selection;
		if (selection == 1)
		{
			sort_f1(reg1, marks1, size1, size2);
			sort_f2(reg2, marks2, size3, size4);
			cout << "Files updated successfuly!" << endl;
		}
		else if (selection == 2)
		{
			int k = 0, l = 0;
			k = close_f1(size1);
			l = close_f2(size3);
			if (k == 0 && l == 0)
				cout << " No section needed to be closed! " << endl;
		}
		else if (selection == 3)
		{
			adj_f1(reg1, marks1, size1, size3);
			adj_f2(reg2, marks2, size3, size1);
		}
	}
}
void read_f1(int * reg, int * marks, int & size1, int & size2)
{
	size1 = 0, size2 = 0;
	char arr[1000] = { '\0' };
	int garbage = 0;
	ifstream fin;
	fin.open("PF1.txt");
	if (!fin.is_open())
		cout << "Error!" << endl;
	else
	{
		fin.getline(arr, 999);
		for (int i = 0; fin >> garbage; i++)
		{
			fin >> reg[i];
			fin >> marks[i];
			size1++;
		}
		fin.close();
	}
}
void read_f2(int * reg, int * marks, int & size1, int & size2)
{
	size1 = 0, size2 = 0;
	char arr[1000] = { '\0' };
	int garbage = 0;
	ifstream fin;
	fin.open("PF2.txt");
	if (!fin.is_open())
		cout << "File not found!" << endl;
	else
	{
		fin.getline(arr, 999);
		for (int i = 0; fin >> garbage; i++)
		{
			fin >> reg[i];
			fin >> marks[i];
			size1++;
		}
		fin.close();
	}
	size2 = size1;
}
void sort_f1(int* reg, int* marks, int size1, int size2)
{
	for (int i = 0; i < size1; i++)
	{
		for (int j = i + 1; j < size1; j++)
		{
			if (reg[i] > reg[j])
			{
				int temp = reg[i];
				reg[i] = reg[j];
				reg[j] = temp;
				temp = marks[i];
				marks[i] = marks[j];
				marks[j] = temp;
			}
		}
	}
	ofstream fout;
	fout.open("PF1.txt");
	fout << "RECORDS   REG      MARKS" << endl;
	for (int i = 0; i < size1; i++)
	{
		fout << i + 1 << "        " << reg[i] << "       " << marks[i] << endl;
	}
	fout.close();
}

void sort_f2(int* reg, int* marks, int size1, int size2)
{
	for (int i = 0; i < size1; i++)
	{
		for (int j = i + 1; j < size1; j++)
		{
			if (reg[i] > reg[j])
			{
				int temp = reg[i];
				reg[i] = reg[j];
				reg[j] = temp;

				temp = marks[i];
				marks[i] = marks[j];
				marks[j] = temp;

			}
		}
	}

	ofstream fout;
	fout.open("PF2.txt");
	fout << "RECORDS   REG      MARKS" << endl;
	for (int i = 0; i < size1; i++)
	{
		fout << i + 1 << "        " << reg[i] << "       " << marks[i] << endl;
	}
	fout.close();
}

int close_f1(int size1)
{
	int k = 0;
	if (size1< 5)
	{
		cout << "PF1 needs to be closed!" << endl;
		k++;
	}

	return k;
}

int close_f2(int size1)
{
	int k = 0;
	if (size1 < 5)
	{
		cout << "PF2 needs to be closed! " << endl;
		k++;
	}

	return k;
}

void adj_f1(int* reg, int* marks, int size1, int size3)
{
	if (size1 < 5)
	{
		ofstream fout;
		ofstream fout1;
		fout.open("PF2.txt", ios::app);
		for (int i = 0; i < size1; i++)
			fout << ++size3 << "        " << reg[i] << "       " << marks[i] << endl;
		fout.close();
		fout1.open("PF1.txt");
		fout.close();
		cout << "PF1's data has been shifted to PF2 and section PF1 has been deleted successfuly." << endl;
	}
}

void adj_f2(int* reg, int* marks, int size3, int size1)
{
	if (size3 < 5)
	{
		ofstream fout;
		fout.open("PF1.txt", ios::app);
		for (int i = 0; i < size3; i++)
			fout << ++size1 << "        " << reg[i] << "       " << marks[i] << endl;
		fout.close();
		ofstream fout1;
		fout1.open("PF2.txt");
		fout.close();
		cout << "PF2's data has been shifted to PF1 and section PF2 has been deleted successfuly." << endl;
	}
}