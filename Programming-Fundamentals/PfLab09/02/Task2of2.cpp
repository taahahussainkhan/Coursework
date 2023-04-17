#include <iostream>
#include <fstream>
using namespace std;
void readf(int*, int*, int*, int&, int&, int&);
void read1f(int*, int*, int*, int&, int&, int&);
void bestsellingf(int*, int*, int, int);
void most_selling(int*, int*, int, int);
void max_prod(int*, int*, int, int);
void foc_prod(int*, int*, int*, int*, int, int);
int main()
{
	int  selection = 0,size1 = 0, size2 = 0, size3 = 0, size4 = 0, size5 = 0, size6 = 0;
	int* id1 = new int[size1];
	int* stock1 = new int[size2];
	int* sales1 = new int[size3];
	int* id2 = new int[size4];
	int* stock2 = new int[size5];
	int* sales2 = new int[size6];
	readf(id1, stock1, sales1, size1, size2, size3);
	read1f(id2, stock2, sales2, size4, size5, size6);
	cout << "Press 1 to display bestselling item from each category." << endl;
	cout << "Press 2 to display most selling category." << endl;
	cout << "Press 3 to display the category having maximum product." << endl;
	cout << "Press 4 to identify the product that needs to be focused." << endl;
	while (1)
	{
		cin >> selection;
		if (selection == 1)
		{
			cout << "From Category # 1" << endl;
			bestsellingf(id1, sales1, size1, size3);
			cout << "From Category # 2" << endl;
			bestsellingf(id2, sales2, size4, size6);
		}
		else if (selection == 2)
		{
			most_selling(sales1, sales2, size3, size6);
		}
		else if (selection == 3)
		{
			max_prod(stock1, stock2, size2, size4);
		}
		else if (selection == 4)
		{
			foc_prod(id1, id2, sales1, sales2, size3, size6);
		}
	}
	delete[] id1, stock1, sales1, id2, stock2, sales2;
	return 0;
}
void readf(int* id, int* stock, int* sales, int& size1, int& size2, int& size3)
{
	size1 = 0;
	char arr[1000] = "\0";
	ifstream fin;
	fin.open("Category1.txt");//
	if (!fin.is_open())
		cout << "File not found!" << endl;
	else
	{
		fin.getline(arr, 999);
		for (int i = 0; !fin.eof(); i++)
		{
			fin >> id[i];
			fin >> stock[i];
			fin >> sales[i];
			size1++;
		}
		fin.close();
	}
	size2 = size1;
	size3 = size1;
}
void read1f(int* id, int* stock, int* sales, int& size1, int& size2, int& size3)
{
	size1 = 0;
	char arr[1000] = "\0";
	ifstream fin;
	fin.open("Category2.txt");
	if (!fin.is_open())
		cout << "File not found!" << endl;
	else
	{
		fin.getline(arr, 999);

		for (int i = 0; !fin.eof(); i++)
		{
			fin >> id[i];
			fin >> stock[i];
			fin >> sales[i];
			size1++;
		}
		fin.close();
	}
	size2 = size1;
	size3 = size1;
}
void bestsellingf(int* id, int* sales, int size1, int size3)
{
	int x = sales[0];
	int y = 0;
	for (int i = 0; i < size3; i++)
	{
		if (sales[i] > x)
		{
			x = sales[i];
			y = i;
		}
	}
	cout<< id[y] << " had most sales of about " << sales[y] << endl;
}
void most_selling(int* sales1, int* sales2, int size3, int size6)
{
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < size3; i++)
		sum1 = sum1 + sales1[i];
	for (int i = 0; i < size6; i++)
		sum2 = sum2 + sales2[i];
	if (sum1 > sum2)
	cout << "Category 1 had more sales" << endl;
	else if (sum1 < sum2)
	cout << "Category 2 had more sales" << endl;
	else
	cout << "Both categories had equal sales." << endl;
}
void max_prod(int* stock1, int* stock2, int size2, int size4)
{
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < size2; i++)
		sum1 = sum1 + stock1[i];
	for (int i = 0; i < size4; i++)
		sum2 = sum2 + stock2[i];
	if (sum1 > sum2)
		cout << "Category 1 has more products." << endl;
	else if (sum1 < sum2)
		cout << "Category 2 has more products." << endl;
	else
		cout << "Both categories had equal number of products." << endl;
}
void foc_prod(int *id1, int *id2, int* sales1, int* sales2, int size3, int size6)
{
	int sale1 = sales1[0], sale2 = sales2[0];
	int y1 = 0, y2 = 0;
	for (int i = 0; i < size3; i++)
	{
		if (sales1[i] < sale1)
		{
			sale1 = sales1[i];
			y1 = i;
		}
	}
	for (int i = 0; i < size6; i++)
	{
		if (sales2[i] < sale2)
		{
			sale2 = sales2[i];
			y2 = i;
		}
	}
	if (sale1 > sale2)
	cout << id2[y2] << " item from category 2 needs to be worked on " << endl;
	else if (sale2 > sale1)
		cout << id2[y2] << " item from category 1 needs to be worked on " << endl;
	else
		cout <<id1[y1] << " and " << id2[y2] << " both need to be worked on from category 1 and 2 respectively. " << endl;
}