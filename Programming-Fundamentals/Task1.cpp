#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream f1;
	f1.open("data1.txt");
	if (f1.is_open())
		cout << "File is opened\n";
	else
		cout << "File NOT found\n";
	f1.close();



}