#include<iostream>
using namespace std;
int calculator(int,int,char);
void sum(int,int);
void subtraction(int,int);
void multiplication(int,int);
void division(int,int);
int main()
{
	int num1, num2;
	char sym;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;
	cout << "Enter operator: ";
	cin >> sym;
	calculator(num1,num2, sym);
}
int calculator(int num1, int num2, char sym)
{
	if (sym == '+')
	{
		sum(num1, num2);
		return 1;
	}
	else if (sym == '-')
	{
		subtraction(num1, num2);
		return 1;
	}
	else if (sym == '*')
	{
		multiplication(num1, num2);
		return 1;
	}
	else if (sym == '/')
	{
		division(num1, num2);
		return 1;
	}
}
void sum(int num1, int num2)
{

	cout << num1 << " + " << num2 << " = " << num1 + num2;

}
void subtraction(int num1, int num2)
{

	cout << num1 << " - " << num2 << " = " << num1 - num2;

}
void multiplication(int num1, int num2)
{

	cout << num1 << " * " << num2 << " = " << num1 * num2;

}
void division(int num1, int num2)
{

	cout << num1 << " / " << num2 << " = " << num1 / num2;

}