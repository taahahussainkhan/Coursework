#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<stdlib.h>
using namespace std;
void option(int,float**,int,int);
void s_row(int,float**, int,int);
void s_col(int,float**, int,int);
void s_diag(int,float**, int,int);
int main()
{
	ifstream fin;
	string filename;
	char opt;
	cout << "Enter the file name you want to enter: ";
	cin >> filename;
	int row,cols;
	fin.open(filename);
	fin >> row;
	fin>>cols;
	cout <<"Number of Rows : "<< row<<endl;
	cout <<"Number of Columns : "<< cols<<endl;
	float** mat = NULL;
	mat=new float*[row];

	for (int i = 0; i < row; i++)
	{
		mat[i] = new float[cols];
    }

	for (int i = 0; i < row;i++)
	{
	for (int j = 0;j < cols; j++)
	{
			fin >> mat[i][j];
	}
    }
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	Sleep(3000);
	option(opt,mat,row,cols);
}
void option(int opt,float** mat,int row,int cols)
{
	system("CLS");
    cout << "1.\t Press 1 for Row Wise Sum ."<<endl;
	cout << "2.\t Press 2 for Column Wise Sum ."<<endl;
	cout << "3.\t Press 3 for Diagonal Sum ."<<endl;
	cout << "4.\t Press 4 to exit ."<<endl;
	cin >> opt;
	if (opt == 1)
		s_row(opt,mat, row,cols);
	else if (opt == 2)
		s_col(opt,mat, row,cols);
	else if (opt ==3)
		s_diag(opt,mat, row,cols);
	else
	exit(0);
}
void s_row(int opt,float** mat, int row,int cols)
{
	float s_row = 0;
	int k = 1;
	cout<<endl;
	cout << "Finding Sum of each row:"<<endl;
	for (int i = 0; i < row; ++i) 
	{
		s_row = 0;
		for (int j = 0; j < cols; ++j)
		{
			s_row = s_row + mat[i][j];
		}
		cout << "Sum of the row " << k << " = " << s_row << endl;
		k++;
	}
	Sleep(3000);
	option(opt,mat,row,cols);
}
void s_col(int opt,float** mat, int row,int cols)
{
	int   k= 1;
	float s_col = 0;
	cout<<endl;
	cout << "Sum of each column:"<<endl;
	for (int i = 0; i < row; ++i) 
	{
		s_col = 0;
		for (int j = 0; j < cols; ++j)
		{
			s_col = s_col + mat[j][i];
		}
		cout << "Sum of the column " << k << " = " << s_col << endl;
		k++;
	}
	Sleep(3000);
	option(opt,mat,row,cols);
}
void s_diag(int opt,float** mat, int row,int cols)
{
	int k=0;
	float left = 0, right = 0;
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<cols; j++)
		{
			if (i == j)
			{
				left += mat[i][j];
				k++;
			}
			else if ((i + j) == row - 1)
			{
				right += mat[i][j];
				k++;
			}
			else
		    k =0;
		}
	}
	if(k>0)
	{
	cout << "Sum of Left Diagonal: " << left << endl;
	cout << "Sum of Right Diagonal: " << right << endl;
    }
    else
    cout<<"Diagonal Not Possible"<<endl;
    Sleep(3000);
	option(opt,mat,row,cols);
}
