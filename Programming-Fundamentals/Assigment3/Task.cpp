#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void option(float**, int, int);
void s_row(float**, int, int);
void s_column(float**, int, int);
void s_diag(float**, int, int);
int main()
{
	bool flag;
	ifstream fin;
	string filename;
	cout << "Enter the file name you want to enter (with .txt extension): ";
	while (1){
		
		cin >> filename;
		fin.open(filename);
		if (fin.is_open())
		{
			flag = 1;
			break;
		}
		else
		{
			cout << "FIlE NOT FOUND!" << endl;
			cout << "Enter again!" << endl;
			continue;
		}
	}
	if (flag == 1){
		int row, col;
		fin >> row;
		fin >> col;
		cout << "Number of Rows : " << row << endl;
		cout << "Number of Columns : " << col << endl;
		float** matrix = NULL;
		matrix = new float*[row];
		for (int i = 0; i < row; i++)
		{
			matrix[i] = new float[col];
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				fin >> matrix[i][j];
			}
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		option(matrix, row, col);
	}
}
void option(float** matrix, int row, int col)
{
	char opt;
	while (1){
		cout << "1.\t Press R/r for Row Wise Sum ." << endl;
		cout << "2.\t Press C/c for Column Wise Sum ." << endl;
		cout << "3.\t Press D/d for Diagonal Sum ." << endl;
		cout << "4.\t Press E/e to exit ." << endl;
		cin >> opt;
		if (opt == 'R'||opt=='r')
			s_row(matrix, row, col);
		else if (opt == 'C'||opt=='c')
			s_column(matrix, row, col);
		else if (opt == 'D' || opt == 'd')
			s_diag(matrix, row, col);
		else if (opt == 'E' || opt == 'e')
			break;
		else
		{
			cout << "Wrong Input!" << endl;
			cout << "Choose Again!" << endl;
			continue;
		}
	}
}
void s_row(float** matrix, int row, int col)
{
	float s_row = 0;
	int k = 1;
	cout << endl;
	cout << "Finding Sum of each row:" << endl;
	for (int i = 0; i < row; ++i)
	{
		s_row = 0;
		for (int j = 0; j < col; ++j)
		{
			s_row = s_row + matrix[i][j];
		}
		cout << "Sum of the row " << k << " = " << s_row << endl;
		k++;
	}
}
void s_column(float** matrix, int row, int col)
{
	int   k = 1;
	float s_col = 0;
	cout << endl;
	cout << "Sum of each column:" << endl;
	for (int i = 0; i < row; ++i)
	{
		s_col = 0;
		for (int j = 0; j < col; ++j)
		{
			s_col = s_col + matrix[j][i];
		}
		cout << "Sum of the column " << k << " = " << s_col << endl;
		k++;
	}
	
}
void s_diag( float** matrix, int row, int col)
{
	int check = 0;
	float left_sum = 0, right_sum = 0;
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
		{
			if (i == j)
			{
				left_sum += matrix[i][j];
				check++;
			}
			else if ((i + j) == row - 1)
			{
				right_sum += matrix[i][j];
				check++;
			}
			else
				check = 0;
		}
	}
	if (check>0)
	{
		cout << "Sum of Left Diagonal: " << left_sum << endl;
		cout << "Sum of Right Diagonal: " << right_sum << endl;
	}
	else
		cout << "Diagonal Sum Not Possible!" << endl;
	
}