#include<iostream>
using namespace std;
int print_table(int);
int main()
{
	int num = 0;
	cout << "Enter a number for table: ";
	cin >> num;
	print_table(6);
}
int print_table(int num)
{
	for (int i = 1; i <= 6; i++)
		cout <<num<<" * "<<i<<" = "<< num*i<<endl;
	return num;
}