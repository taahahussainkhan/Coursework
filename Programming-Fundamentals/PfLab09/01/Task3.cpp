#include<iostream>
using namespace std;
int sum(int*, int*);
int main()
{
	int num1, num2;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;
	int* ptr1 = NULL;
	int* ptr2 = NULL;
	ptr1 = &num1;
	ptr2 = &num2;
	cout << sum(&num1, &num2)<<endl;
}
int sum(int* ptr1, int* ptr2)
{
	int summ = *ptr1 + *ptr2;
	cout << "Sum is: \n";
	return summ;
}