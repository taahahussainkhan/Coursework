#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream f1;
	ofstream f2;
	char arr[100] = { '/0' };
	f1.open("data.txt");
	f2.open("New file.txt");
	if (!f1.eof())
	f1.getline(arr, 99);
	f2 << arr;
	f1.close();
	f2.close();
	return 0;
}