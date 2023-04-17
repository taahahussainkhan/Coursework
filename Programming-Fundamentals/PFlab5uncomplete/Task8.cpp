#include<iostream>
#include<fstream>
using namespace std;
int read();
int check(int arr[],int);
int main()
{
	int arr[30];
	read();
	check(arr,2);
}
int read()
{
	int arr[30];
	ifstream fin;
	fin.open("data.txt");
	for (int i = 0;!fin.eof(); i++)
	{
		fin >> arr[i];
		//cout << arr[i] << " ";
	}
	fin.close();
	return arr[30];
}
int check(int arr[],int)
{
	cout << arr[2];
	return 1;
}