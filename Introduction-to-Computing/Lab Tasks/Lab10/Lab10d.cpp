#include<iostream>
using namespace std;
int main()
{
	int sum = 0, number, remain;
	cout << "Enter a five digit number : ";
	cin >> number;
	do
	{
		remain = number % 10;
		sum = sum + remain;
		number = number / 10;
		cout << remain << endl;
	}while (number > 0);
	cout << sum;
	return 0;
	system("pause");
}