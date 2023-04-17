#include<iostream>
using namespace std;
void smallest(int* ptr1, int* ptr2, int* ptr3);
void largest(int* ptr1, int* ptr2, int* ptr3);
int main()
{
	int num1, num2, num3;
	char choice;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num3;
	cout << "Enter third number: ";
	cin >> num2;
	int* ptr1 = NULL;
	int* ptr2 = NULL;
	int* ptr3 = NULL;
	ptr1 = &num1;
	ptr2 = &num2;
	ptr3 = &num3;
	cout << "Enter: \n's' for smallest.\n'l' for largest.\n";
	cin >> choice;
	if (choice == 's')
		smallest(&num1, &num2, &num3);
	else if (choice == 'l')
		largest(&num1, &num2, &num3);
}
void smallest(int* ptr1, int* ptr2, int* ptr3)
{
	cout << "Numbers are:\n\n";
	cout << *ptr1 << " " << *ptr2 << " " << *ptr3 << endl << endl;
	if (*ptr1 < *ptr2&&*ptr1 < *ptr3)
		cout << *ptr1 << " is smallest!\n";
	if (*ptr2 < *ptr1&&*ptr2 < *ptr3)
		cout << *ptr2 << " is smallest!\n";
	if (*ptr3 < *ptr1&&*ptr3 < *ptr2)
		cout << *ptr3 << " is smallest!\n";
}
void largest(int* ptr1, int* ptr2, int* ptr3)
{
	cout << "Numbers are:\n\n";
	cout << *ptr1 << " " << *ptr2 << " " << *ptr3 << endl << endl;
	if (*ptr1 > *ptr2&&*ptr1 > *ptr3)
		cout << *ptr1 << " is largest!\n";
	if (*ptr2 > *ptr1&&*ptr2 > *ptr3)
		cout << *ptr2 << " is largest!\n";
	if (*ptr3 > *ptr1&&*ptr3 > *ptr2)
		cout << *ptr3 << " is largest!\n";
}