#include<iostream>
using namespace std;
int calcMul(int);
int calcMul1(int);
int calcSum(int, int);

int main()
{
	int num1, num2,m,m1,s;
	cout << "Enter a: ";
	cin >> num1;
	cout << "Enter b: ";
	cin >> num2;
	m=calcMul(num1);
	m1 = calcMul1(num2);
	s = calcSum(m, m1);
	cout <<"Result is: "<< s<<endl;
}
int calcMul(int num1)
{
	num1 = num1*num1;

	return num1;
}
int calcMul1(int num2)
{
	num2 = num2*num2;
	return num2;
}
int calcSum(int num1, int num2)
{
	int sum = num1 + num2;
	return sum;

}