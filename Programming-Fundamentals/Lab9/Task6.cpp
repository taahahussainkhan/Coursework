#include<iostream>
using namespace std;
void sort_three(int* ptr1, int* ptr2, int* ptr3);
int main()
{
	int num1, num2, num3;
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
	sort_three(&num1, &num2, &num3);
	
}
void sort_three(int* ptr1, int* ptr2, int* ptr3)
{
	int smallest, biggest, middle;
	cout << "Numbers are:\n\n";
	if ((*ptr1 < *ptr2) && (*ptr1 < *ptr3))
	{
		smallest = *ptr1;
		if (*ptr2 > *ptr3)
		{
			biggest = *ptr2;
			middle = *ptr3;
		}
	}
	if ((*ptr1 < *ptr2) && (*ptr3 << *ptr1))
	{
		smallest = *ptr1;
		if (*ptr2 < *ptr3)
		{
			middle = *ptr2;
			biggest = *ptr3;
		}
	}
	if ((*ptr1 > *ptr2) && (*ptr3 > *ptr1))
	{
		middle = *ptr1;
		if (*ptr2 < *ptr3)
		{
			smallest = *ptr2;
			biggest = *ptr3;
		}
	}
	if ((*ptr1 < *ptr2) && (*ptr3 < *ptr1))
	{
		middle = *ptr1;
		if (*ptr2 > *ptr3)
		{
			biggest = *ptr2;
			smallest = *ptr3;
		}
	}
	if ((*ptr1 > *ptr2) && (*ptr1 > *ptr3))
	{
		biggest = *ptr1;
		if (*ptr3 > *ptr2)
		{
			middle = *ptr3;
			smallest = *ptr2;
		}
	}

	if ((*ptr1 > *ptr2) && (*ptr1 > *ptr3))
	{
		biggest = *ptr1;
		if (*ptr2 > *ptr3)
		{
			middle = *ptr2;
			smallest = *ptr3;
		}
	}
	cout << smallest << "\n" << middle << "\n" << biggest << endl;
}
