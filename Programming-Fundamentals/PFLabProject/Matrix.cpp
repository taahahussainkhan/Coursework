#include<iostream>//started 10-06-2022
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;
void k_input();
void f_input();
void output_f(int row);
void sorted_output(int** data, int, int);
void file_output_f(int,string);
void file_sorted_output(int** data, int, int,string);
void sum(int**, int, int);//1
void prod(int** , int , int );//2
void row_vise_avg(int**, int, int);//3
void col_vise_avg(int**, int, int);//4
void whole_avg(int**, int, int);//5
void row_sort(int**, int, int);//6
void column_sort(int**, int, int);//7
void add_two_matrix(int**, int, int);//8
void sub_two_matrix(int**, int, int);//9
void transpose(int**, int, int);//10
int main()
{
	char main;
	Sleep(30);
	cout << "\n\n\n\n\t\t\t\t\t-------------------------------------" << endl;
	Sleep(1000);
	cout << "\t\t\t\t\tM a t r i x    M a n i p u l a t o r" << endl;
	Sleep(1000);
	cout << "\t\t\t\t\t-------------------------------------" << endl;
	Sleep(1000);
	system("CLS");
	cout << "Select one of the following:" << endl;
	cout << "Press M/m to Enter matrix manually." << endl;
	cout << "Press F/f to take input from file." << endl;
	while (1)
	{
		cin >> main;
		if (main == 'M' || main == 'm')
			k_input();
		else if (main == 'F' || main == 'f')
			f_input();
		else
		{
			cout << "Wrong Input!!"<<endl;
			cout << "Enter again: ";
			continue;
		}
	}
	
}
void k_input()//For keyboard input
{
	int row = 0, col = 0;
	cout << "Enter number of rows: ";
	cin >> row;
	cout << "Enter number of columns: ";
	cin >> col;
	int** data = NULL;
	data = new int*[row];
	for (int i = 0; i < row; i++)//2D dynamic array allocation
		data[i] = new int[col];
	cout << "Enter values in matrix: ";
	for (int i = 0; i < row; i++)//Taking input from user in matrix
	{
		for (int j = 0; j < col; j++)
			cin >> data[i][j];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout<< data[i][j]<<" ";
		cout << endl;
	}
	char opt;
int option;
	while (1)
	{
		cout << "Enter Y/y to perform operation or N/n to exit! " << endl;
		cin >> opt;
		if (opt == 'Y' || opt == 'y')
		{
			cout << "------------------------" << endl;
			cout << "Select any option: " << endl;
			cout << "1. Sum of Matrix (sum of all values)" << endl;
			cout << "2. Product of Matrix(product of all values)" << endl;
			cout << "3. Row - wise Average" << endl;
			cout << "4. Column - wise Average" << endl;
			cout << "5. Average or whole Matrix" << endl;
			cout << "6. Row - wise sorting of Matrix" << endl;
			cout << "7. Column - wise sorting of Matrix" << endl;
			cout << "8. Addition of two Matrices" << endl;
			cout << "9. Subtraction of two Matrices" << endl;
			cout << "10. Matrix transpose" << endl;
			cout << "Enter any other key to exit! " << endl;
			cin >> option;
			if (option == 1)
				sum(data, row, col);
			else if (option == 2)
				prod(data, row, col);
			else if (option == 3)
				row_vise_avg(data, row, col);
			else if (option == 4)
				col_vise_avg(data, row, col);
			else if (option == 5)
				whole_avg(data, row, col);
			else if (option == 6)
				row_sort(data, row, col);
			else if (option == 7)
				column_sort(data, row, col);
			else if (option == 8)
				add_two_matrix(data, row, col);
			else if (option == 9)
				sub_two_matrix(data, row, col);
			else if (option == 10)
				transpose(data, row, col);
			else
			{
				cout << "**********PROGRAM ENDED**********\n\n\t\tTHANK YOU!" << endl;
				exit(0);
			}
		}
		else
			exit(0);
		
	}
}
void f_input()
{
	int row = 0, col = 0;
	string filename;
	cout << "Enter the name of file you want to open(with .txt extension): ";
	while (1)
	{
		cin >> filename;
		ifstream fin(filename);
		if (fin.is_open())
		{
			cout << "File Found!\n\n" << endl;
			cout << "Enter number of rows: ";
			cin >> row;
			cout << "Enter number of columns: ";
			cin >> col;
			int** data = NULL;
			data = new int*[row];
			for (int i = 0; i < row; i++)//2D dynamic array allocation
				data[i] = new int[col];
			cout << "Values in matrix are: " << endl;
			for (int i = 0; i < row; i++)//Taking input from file in matrix
			{
				for (int j = 0; j < col; j++)
					fin >> data[i][j];
			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
					cout << data[i][j] << " ";
				cout << endl;
			}
			char opt;
			int option;
			while (1)
			{
				cout << "Enter Y/y to perform operation or N/n to exit! " << endl;
				cin >> opt;
				if (opt == 'Y' || opt == 'y')
				{
					system("CLS");
					cout << "------------------------" << endl;
					cout << "Select any option: " << endl;
					cout << "1. Sum of Matrix (sum of all values)" << endl;
					cout << "2. Product of Matrix(product of all values)" << endl;
					cout << "3. Row - wise Average" << endl;
					cout << "4. Column - wise Average" << endl;
					cout << "5. Average or whole Matrix" << endl;
					cout << "6. Row - wise sorting of Matrix" << endl;
					cout << "7. Column - wise sorting of Matrix" << endl;
					cout << "8. Addition of two Matrices" << endl;
					cout << "9. Subtraction of two Matrices" << endl;
					cout << "10. Matrix transpose" << endl;
					cout << "Enter any other key to exit! " << endl;
					cin >> option;
					if (option == 1)
						sum(data, row, col);
					else if (option == 2)
						prod(data, row, col);
					else if (option == 3)
						row_vise_avg(data, row, col);
					else if (option == 4)
						col_vise_avg(data, row, col);
					else if (option == 5)
						whole_avg(data, row, col);
					else if (option == 6)
						row_sort(data, row, col);
					else if (option == 7)
						column_sort(data, row, col);
					else if (option == 8)
						add_two_matrix(data, row, col);
					else if (option == 9)
						sub_two_matrix(data, row, col);
					else if (option == 10)
						transpose(data, row, col);
					else
					{
						system("CLS");
						cout << "\n\n\n\n\t\t\t\t\t----------------------------" << endl;
						Sleep(1000);
						cout << "\t\t\t\t\tP r o g r a m    E n d e d" << endl;
						Sleep(1000);
						cout << "\t\t\t\t\t----------------------------" << endl;
						Sleep(1000);
						cout << "\n\n\t\tTHANK YOU!" << endl;
						exit(0);
					}
				}
				else
				{
					system("CLS");
					cout << "\n\n\n\n\t\t\t\t\t----------------------------" << endl;
					Sleep(1000);
					cout << "\t\t\t\t\tP r o g r a m    E n d e d" << endl;
					Sleep(1000);
					cout << "\t\t\t\t\t----------------------------" << endl;
					Sleep(1000);
					cout << "\n\n\t\tTHANK YOU!" << endl;
					exit(0);
				}
			}
		}
		else
		{
			cout << "File Not found!"<<endl;
			cout << "Enter again: ";
			continue;
		}
	}
}
void sum(int** data, int row, int col)//Qno1
{
	system("CLS");
	ofstream fout;
	char out;
	string f_name;
	int sum = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			sum += data[i][j];
		cout << "----------S u m----------" << endl << endl << endl;
			cout << "Where do you want to show the output?" << endl;
			cout << "Press C/c to show on console." << endl;
			cout << "Press F/f to show on file." << endl;
			cin >> out;
			if (out == 'F' || out == 'f')
			{
				cout << "Enter the filename where you want to show the output: ";
				cin >> f_name;
				fout.open(f_name);
			}
			if (out == 'C' || out == 'c')
			{
				cout << "Sum is: " << sum << endl;;
			}
			else if (out == 'F' || out == 'f')
			{
				fout << "Sum is: " << sum << endl;
			}
		

}
void prod(int** data, int row, int col)//Qno2
{
	system("CLS");
	cout << "----------P r o d u c t----------" << endl << endl << endl;
	string f_name;
	ofstream fout;
	char out;
	long long int prod = 1;
	for (int i = 0; i < row; i++)
	for (int j = 0; j < col; j++)
		prod =data[i][j]*prod;
	cout << "Where do you want to show the output?" << endl;
	cout << "Press C/c to show on console." << endl;
	cout << "Press F/f to show on file." << endl;
	cin >> out;
	if (out == 'F' || out == 'f')
	{
		cout << "Enter the filename where you want to show the output: ";
		cin >> f_name;
		fout.open(f_name);
	}
		if (out == 'C' || out == 'c')
		{
			cout << "Product is: " << prod << endl;;
		}
		else if (out == 'F' || out == 'f')
		{
			
			fout << "Product is: " <<prod << endl;
		}
	

}
void row_vise_avg(int** matrix, int row, int col)//3
{
	int sum = 0;
	system("CLS");
	string f_name;
	ofstream fout;
	char out;
	float average;
	cout << "----------R o w    v i s e    A v e r a g e----------" << endl << endl << endl;
	cout << "Where do you want to show the output?" << endl;
	cout << "Press C/c to show on console." << endl;
	cout << "Press F/f to show on file." << endl;
	cin >> out;
	if (out == 'F' || out == 'f')
	{
		cout << "Enter the filename where you want to show the output: ";
		cin >> f_name;
		fout.open(f_name);
	}
	for (int i = 0; i < row; i++)
	{
		sum = 0;
		for (int j = 0; j < col; j++)
		{
			sum += matrix[i][j];
		}
		average = (float)sum / col;

		//	cout << "The average of row " << i + 1 << " is " << average << " " << endl;

		if (out == 'C' || out == 'c')
		{
			cout << "The average of row " << i + 1 << " is " << average << endl;
		}
		else if (out == 'F' || out == 'f')
		{
			
			fout << "The average of row " << i + 1 << " is " << average  << endl;
			
		}

	}
}
void col_vise_avg(int** data, int row, int col)//4
{
	system("CLS");
	string f_name;
	ofstream fout;
	char out;
	float average;
	int sum = 0;
	cout << "----------C o l u m n    v i s e    A v e r a g e----------" << endl << endl << endl;
	cout << "Where do you want to show the output?" << endl;
	cout << "Press C/c to show on console." << endl;
	cout << "Press F/f to show on file." << endl;
	cin >> out;
	if (out == 'F' || out == 'f')
	{
		cout << "Enter the filename where you want to show the output: ";
		cin >> f_name;
		fout.open(f_name);
	}
	for (int i = 0; i < col; i++)
	{
		sum = 0;
		for (int j = 0; j < row; j++)
		{
			sum += data[j][i];
		}
		average = (float)sum / col;

		if (out == 'C' || out == 'c')
		{
			cout << "The average of column " << i + 1 << " is " << average << endl;
		}
		else if (out == 'F' || out == 'f')
		{

			fout << "The average of column " << i + 1 << " is " << average << endl;
		}

	}
}
void whole_avg(int** data, int row, int col)//Qno5
{
	system("CLS");
	string f_name;
	char out;
	ofstream fout;
	float average;
	int sum = 0;
	cout << "----------W h o l e     A v e r a g e----------" << endl << endl << endl;
	cout << "Where do you want to show the output?" << endl;
	cout << "Press C/c to show on console." << endl;
	cout << "Press F/f to show on file." << endl;
	cin >> out;
	if (out == 'F' || out == 'f')
	{
		cout << "Enter the filename where you want to show the output: ";
		cin >> f_name;
		fout.open(f_name);
	}
	for (int i = 0; i<row; i++)
	for (int j = 0; j<col; j++)
	{
		sum = sum + data[i][j];
	}
	average = (float)sum / (float)(row*col);
		if (out == 'C' || out == 'c')
		{
			cout << "------------------------------" << endl;
			cout << "Average of the whole matrix is: " << average << endl;
		}
		else if (out == 'F' || out == 'f')
		{
	
			//fout << "------------------------------" << endl;
			fout << "Average of the whole matrix is: " << average << endl;
		}
	
}
void row_sort(int** data, int row, int col)//Qno 6
{
	system("CLS");
	string f_name;
	ofstream fout;
	char out;
	int temp = 0;
	cout << "----------R o w    v i s e    S o r t----------" << endl << endl << endl;
	cout << "Where do you want to show the output?" << endl;
	cout << "Press C/c to show on console." << endl;
	cout << "Press F/f to show on file." << endl;
	cin >> out;
	if (out == 'F' || out == 'f')
	{
		cout << "Enter the filename where you want to show the output: ";
		cin >> f_name;
		fout.open(f_name);
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int k = 0; k < col - j - 1; k++)
			{
				if (data[i][k] > data[i][k + 1])
				{
					 temp = data[i][k];
					data[i][k] = data[i][k + 1];
					data[i][k + 1] = temp;
				}
			}
		}
	}
		if (out == 'C' || out == 'c')
		{
			cout << "------------------------------" << endl;
			cout << "----------Row wise sorted matrix : " << endl;
			sorted_output(data, row, col);
		}

		else if (out == 'F' || out == 'f')
		{
			fout << "----------Row wise sorted matrix : " << endl;
			file_sorted_output(data, row, col,f_name);
		}
	
	

}
void column_sort(int** data, int row, int col)//Qno 7
{
	system("CLS");
	string f_name;
	ofstream fout;
	char out;
	int temp = 0;
	cout << "----------C o l u m n    v i s e    S o r t i n g----------" << endl << endl << endl;
	cout << "Where do you want to show the output?" << endl;
	cout << "Press C/c to show on console." << endl;
	cout << "Press F/f to show on file." << endl;
	cin >> out;
	if (out == 'F' || out == 'f')
	{
		cout << "Enter the filename where you want to show the output: ";
		cin >> f_name;
		fout.open(f_name);
	}
	for (int x = 0; x < col; x++)
	{
		for (int s = 0; s < row; s++)
		{
			for (int c = s; c < row; c++)
			{
				if (data[s][x]>data[c][x])
				{
					int t = data[s][x];
					data[s][x] = data[c][x];
					data[c][x] = t;
				}
			}
		}
	}
	if (out == 'C' || out == 'c')
	{
		cout << "------------------------------" << endl;
		cout << "----------Column wise sorted matrix : " << endl;
		sorted_output(data, row, col);
	}

	else if (out == 'F' || out == 'f')
	{
		fout << "----------Column wise sorted matrix : " << endl;
		file_sorted_output(data, row, col, f_name);
	}


}
void add_two_matrix(int** data, int row, int col)//Qno8
{
	system("CLS");
	int** data1 = NULL;
	data1 = new int*[row];
	for (int i = 0; i < row; i++)//2D dynamic array allocation
		data1[i] = new int[col];
	int** sum = NULL;
	sum = new int*[row];
	for (int i = 0; i < row; i++)//2D dynamic array allocation
		sum[i] = new int[col];
	char choose;
	string f_name;
	cout << "----------A d d i t i o n----------" << endl << endl << endl;
	cout << "Choose from where you want to take another matrix for addition: " << endl;
	cout << "Press F/f to take input from file." << endl;
	cout << "Press M/m to take input from keyboard." << endl;
	cin >> choose;
	if (choose == 'F' || choose == 'f')
	{
		cout << "Enter the name of file you want to open(with .txt extension): ";
		while (1){
			cin >> f_name;
			ifstream fin1(f_name);
			if (fin1.is_open())
			{
				
					cout << "File Found" << endl;
					for (int i = 0; i < row; i++)//Taking input from file in matrix
					{
						for (int j = 0; j < col; j++)
							fin1 >> data1[i][j];
					}
					cout << "------------------------------" << endl;
					cout << "First matrix is: " << endl;
					for (int i = 0; i < row; i++)
					{
						for (int j = 0; j < col; j++)
							cout << data[i][j] << " ";
						cout << endl;
					}
					Sleep(1000);
					cout << "------------------------------" << endl;
					cout << "Second matrix is: " << endl;
					for (int i = 0; i < row; i++)
					{
						for (int j = 0; j < col; j++)
							cout << data1[i][j]<<" ";
						cout << endl;
					}
					Sleep(1000);
					for (int i = 0; i < row; i++)//adding both matrices
					{
						for (int j = 0; j < col; j++)
							sum[i][j] = data[i][j] + data1[i][j];
						
					}
					cout << "------------------------------" << endl;
					cout << "Addition of these two matrices is: " << endl;
					sorted_output(sum, row, col);
					break;
			
			}
			else
			{
				cout << "File Not found!";
				cout << "Enter again: ";
				continue;
			}
		}
	
	}	
	else if (choose == 'M' || choose == 'm')
	{
		cout << "Enter values in second matrix: " << endl;
		for (int i = 0; i < row; i++)//Taking input from user in matrix
		{
			for (int j = 0; j < col; j++)
				cin >> data1[i][j];
		}
		cout << "------------------------------" << endl;
		cout << "First matrix is: " << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				cout << data[i][j] << " ";
			cout << endl;
		}
		cout << "------------------------------" << endl;
		cout << "Second matrix is: " << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				cout << data1[i][j] << " ";
			cout << endl;
		}
		
		for (int i = 0; i < row; i++)//adding both matrices
		{
			for (int j = 0; j < col; j++)
				sum[i][j] = data[i][j] + data1[i][j];

		}
		cout << "------------------------------" << endl;
		cout << "Sum of these two matrices is: " << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				cout << sum[i][j] << " ";
			cout << endl;
		}

	}
	
}
void sub_two_matrix(int** data, int row, int col)//Qno 9
{
	system("CLS");
	char choose;
	string f_name;
	int** data1 = NULL;
	data1 = new int*[row];
	for (int i = 0; i < row; i++)//2D dynamic array allocation
		data1[i] = new int[col];
	int** sub = NULL;
	sub = new int*[row];
	for (int i = 0; i < row; i++)//2D dynamic array allocation
		sub[i] = new int[col];
	cout << "----------S u b t r a c t i o n----------" << endl << endl << endl;
	cout << "Choose from where you want to take another matrix for addition: " << endl;
	cout << "Press F/f to take input from file." << endl;
	cout << "Press M/m to take input from keyboard." << endl;
	cin >> choose;
	if (choose == 'F' || choose == 'f')
	{
		bool flag = 0;
		cout << "Enter the name of file you want to open(with .txt extension): ";
		
		while (1){
			cin >> f_name;
			ifstream fin1(f_name);
			if (fin1.is_open())
			{
				
					cout << "File Found" << endl;
					for (int i = 0; i < row; i++)//Taking input from file in matrix
					{
						for (int j = 0; j < col; j++)
							fin1 >> data1[i][j];
					}
					cout << "------------------------------" << endl;
					cout << "First matrix is : " << endl;
					for (int i = 0; i < row; i++)
					{
						for (int j = 0; j < col; j++)
						{
							cout << data[i][j] << " ";
							
						}
						cout << endl;
					}
					Sleep(1000);
					cout << "------------------------------" << endl;
					cout << "Second matrix is : " << endl;
					for (int i = 0; i < row; i++)
					{
						for (int j = 0; j < col; j++)
						{
							cout << data1[i][j] << " ";
							
						}
						cout << endl;
					}
					for (int i = 0; i < row; i++)
					{
						for (int j = 0; j < col; j++)
							sub[i][j] = data[i][j] - data1[i][j];
						
					}
					Sleep(1000);
					cout << "------------------------------" << endl;
					cout << "Subtraction matrix of these two matrices is: " << endl;
					sorted_output(sub, row, col);
					break;
			}
			else
			{
				cout << "File Not found!"<<endl;
				cout << "Enter again: ";
				continue;
			}
		}

	}
	else if (choose == 'M' || choose == 'm')
	{
		cout << "Enter values in second matrix: " << endl;
		for (int i = 0; i < row; i++)//Taking input from user in matrix
		{
			for (int j = 0; j < col; j++)
				cin >> data1[i][j];
		}
		cout << "------------------------------" << endl;
		cout << "First matrix is: " << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				cout << data[i][j] << " ";
			cout << endl;
		}
		cout << "------------------------------" << endl;
		cout << "Second matrix is: " << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				cout << data1[i][j] << " ";
			cout << endl;
		}

		for (int i = 0; i < row; i++)//subtracting both matrices
		{
			for (int j = 0; j < col; j++)
				sub[i][j] = data[i][j] - data1[i][j];

		}
		cout << "------------------------------" << endl;
		cout << "Subtraction of these two matrices is: " << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				cout << sub[i][j] << " ";
			cout << endl;
		}


	}
}
void transpose(int** data, int row, int col)//Qno 10
{
	system("CLS");
	string fi_name;
	ofstream fout;
	char out;
	int transpose[100][100];
	cout << "----------T r a n s p o s e----------" << endl << endl << endl;
	cout << "Where do you want to show the output?" << endl;
	cout << "Press C/c to show on console." << endl;
	cout << "Press F/f to show on file." << endl;
	cin >> out;
	if (out == 'F' || out == 'f')
	{
		cout << "Enter the filename where you want to show the output: ";
		cin >> fi_name;
		fout.open(fi_name);
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			transpose[j][i] = data[i][j];
		}
	}
	
	//Printing the transpose

	if (out == 'C' || out == 'c')
	{
		cout << "The Matrix is: " << endl;
		for (int i = 0; i<row; ++i)
		{
			for (int j = 0; j <col; ++j)
			{
				cout << data[i][j] << " ";
			}
			cout << endl;
		}
		cout << "------------------------------" << endl;
		cout << "The transpose of the matrix is:" << endl;
		for (int i = 0; i<col; ++i)
		{
			for (int j = 0; j <row; ++j)
			{
				cout << transpose[i][j] << " ";
			}
			cout << endl;
		}

	}
	else if (out == 'F' || out == 'f')
	{
		fout << "The transpose of the matrix is:" << endl;
		for (int i = 0; i<col; ++i) {
			for (int j = 0; j<row; ++j)
				fout << data[i][j] << " ";
			fout << endl;
		}


	}
	
}
void output_f(int row)
{
	cout << row;
}
void sorted_output(int** data, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << data[i][j] << " ";
		cout << endl;
	}
}
void file_output_f(int row,string f_name)
{
	ofstream fout;
	fout.open(f_name);
	fout << row;
}
void file_sorted_output(int** data, int row, int col,string f_name)
{
	ofstream fout;
	fout.open(f_name);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			fout << data[i][j] << " ";
		fout << endl;
	}
}


	
	
