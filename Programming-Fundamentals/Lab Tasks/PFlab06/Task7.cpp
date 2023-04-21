#include<iostream>
using namespace std;
int main()
{
	int num1, num2, num3;
	int *ptr1, *ptr2, *ptr3;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;
	cout << "Enter third number: ";
	cin >> num3;
	ptr1 = &num1;
	ptr2 = &num2;
	ptr3 = &num3;
	if ((*ptr1 > *ptr2) && (*ptr1 > *ptr3))
	{
		cout << *ptr1 << " is largest!" << endl;
	}
	else if ((*ptr2 > *ptr1) && (*ptr2 > *ptr3))
	{
		cout << *ptr2 << " is largest!" << endl;
	}
	else if ((*ptr3 > *ptr1) && (*ptr3 > *ptr2))
	{
		cout << *ptr3 << " is largest!" << endl;
	}
	else
		cout << "They are equal!" << endl;

}