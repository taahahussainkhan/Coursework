#include<iostream>
using namespace std;
int factorial(int*);
int main()
{
	int num;
	cout << "Enter a number : ";
	cin >> num;
	int* ptr = NULL;
	ptr = &num;
	cout << "Factorial of " << *ptr << " is : " << factorial(&num)<<endl;

}
int factorial(int* ptr)
{
	int fact=1;
	if (*ptr < 0)
		cout << "Error! Factorial of a negative number doesn't exist.";
	else
	{
		for (int i = 1; i <= *ptr; ++i) 
			fact *= i;
		
		}
		return fact;
}