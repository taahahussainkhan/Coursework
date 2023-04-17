#include<iostream>
using namespace std;
void swap(int* num1, int* num2);
int main()
{
	int num1, num2;
	int* ptr1 = NULL;
	int* ptr2 = NULL;
	ptr1 = &num1;
	ptr2 = &num2;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;
	swap(&num1, &num2);
}
void swap(int* ptr1, int* ptr2)
{
	
	int* temp = NULL;
	cout << "Before swap:" << endl;
	cout << "First Number: " << *ptr1 << endl;
	cout << "Second Number: " << *ptr2 << endl;
	temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
	cout << "After swap:" << endl;
	cout << "First Number: " << *ptr1 << endl;
	cout << "Second Number: " << *ptr2 << endl;
}