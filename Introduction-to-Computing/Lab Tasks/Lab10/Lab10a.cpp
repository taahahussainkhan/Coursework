#include<iostream>
using namespace std;
int main()
{
	int number;
	cout << "Enter any number : ";
	
	for (cin >> number; number >= 1; number--)
	{
		cout << number << endl;
	}
	system("pause");
	return 0;
}