#include<iostream>
using namespace std;
int main()
{
	int sum = 0, number,remain;
	cout << "Enter a five digit number : ";
	cin >> number;
	while (number > 0)
	{
		remain = number%10;
		sum = sum + remain;
		number = number / 10;
		cout << remain << endl;
	}
	cout << sum;
	return 0;
	system("pause");
}