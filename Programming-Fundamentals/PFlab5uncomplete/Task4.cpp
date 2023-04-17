#include<iostream>
using namespace std;
int find_Mul(int,int);

int main()
{
	int num1, num2, m ;
	cout << "Enter a: ";
	cin >> num1;
	cout << "Enter b: ";
	cin >> num2;
	m = find_Mul(num1,num2);
	cout << "Result is: " << m << endl;
}
int find_Mul(int num1,int num2)
{
	int prod = 3*(num1*num2);
	return prod;
}
