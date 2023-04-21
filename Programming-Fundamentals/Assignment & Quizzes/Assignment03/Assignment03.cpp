#include<iostream>
#include<fstream>
#include<string>
using namespace std;
float** dyn_array_creation(ifstream&, float**, int&, int*&);
void input(ifstream& fin, float**, int);
void display(float**, int, int*);
void option(float**, int, int*);
void sum_row( float**, int, int*);
void sum_col( float**, int, int*);
void sum_diag( float**, int, int*);
int main()
{
	string filename;
	cout << "Enter the file name you want to enter: ";
	cin >> filename;
	ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "File Not Found!" << endl;
	}
	float** matrix = new float*[1];
	int* col = new int[1];
	int row = 0;
	matrix = dyn_array_creation(fin, matrix, row, col);
	ifstream fin1(filename);
	input(fin1, matrix, row);
	display(matrix, row, col);
}
float** dyn_array_creation(ifstream& fin, float** matrix, int& row, int*& col)
{
	float temp = 0;
	int s = 0;
	int num = 0;
	fin >> row;
	matrix = new float*[row];
	col = new int[row];
	while (s < row)
	{
		fin >> temp;
		num = temp;
		num++;
		col[s++] = num - 1;
		for (int i = 0; i < num - 1; i++)
		{
			fin >> temp;
		}
	}

	for (int i = 0; i < row; i++)
	{
		matrix[i] = new float[col[i]];
	}
	fin.close();

	return matrix;
}
void input(ifstream& fin, float** matrix, int rows)
{
	float m = 0;
	float t = 0;
	fin >> m;
	for (int i = 0; i < rows; i++)
	{
		fin >> m;
		t = m;
		for (int j = 0; j < t; j++)
		{
			fin >> m;
			matrix[i][j] = m;
		}
	}
}
void display(float** matrix, int rows, int* cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols[i]; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	option(matrix, rows, cols);
}
void option( float** matrix, int rows, int* cols)
{
	char opt;
	while (1){
		cout << "Press R/r for Row Wise Sum ." << endl;
		cout << "Press C/c for Column Wise Sum ." << endl;
		cout << "Press D/d for Diagonal Sum ." << endl;
		cout << "Press any other key to exit ." << endl;
		cin >> opt;
		if (opt == 'R'||opt=='r')
			sum_row( matrix, rows, cols);
		else if (opt =='C'||opt=='c')
			sum_col( matrix, rows, cols);
		else if (opt == 'D' || opt == 'd')
			sum_diag(matrix, rows, cols);
		else
			break;
	}
}
void sum_row( float** matrix, int rows, int* cols)
{
	float sum_row = 0;
	int row_count = 1;
	cout << endl;
	cout << "Sum of each row is:" << endl;
	for (int i = 0; i < rows; i++)
	{
		sum_row = 0;
		for (int j = 0; j < cols[i]; j++)
		{
			sum_row = sum_row + matrix[i][j];
		}
		cout << "Sum of the row " << row_count << " = " << sum_row << endl;
		row_count++;
	}
}
void sum_col(float** matrix, int rows, int* cols)
{
	int   col_count = 1, t = cols[0];
	float sum_col = 0;
	for (int i = 0; i < cols[i]; i++)
	{
		if (cols[i] > t)
			t= cols[i];
	}

	cout << endl;
	cout << "Sum of each column:" << endl;
	for (int i = 0; i < t; i++)
	{
		sum_col = 0;
		for (int j = 0; j < rows; j++)
		{
			if (matrix[j][i] > -999999 && matrix[j][i] < 999999)
			{
				sum_col = sum_col + matrix[j][i];
			}
		}
		cout << "Sum of the column " << col_count << " is  = " << sum_col << endl;
		col_count++;
	}
	
}
void sum_diag(float** matrix, int rows, int* cols)
{
	bool flag = 1;
	int  diagonal = 0;
	float left = 0, right = 0;
	for (int i = 0; i<rows; i++)
	{
		if (cols[i] >= i + 1)
			diagonal++;
	}

	if (diagonal != rows)
	{
		cout << "Diagonal Not Possible" << endl;
		flag = 1;
	}
	else
	{
		for (int i = 0; i < rows; i++)
		{
			left += matrix[i][i];
			right += matrix[rows - 1][rows - 1];
		}
	}
	if (flag != 1)
	{
		cout << " Sum of left diagonal = " << left << endl;
		cout << "Sum of Right Diagonal: " << right << endl;
	}
	cout << endl;
	
}