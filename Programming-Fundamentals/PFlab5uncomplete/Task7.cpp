#include<iostream>
using namespace std;
void prime()
{
	int num1, num2,i,	j,chk=0;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;
	for (int i = num1; i <= num2; i++)
	{
		for (j = 2; j<i; j++)
		{
			if (i%j == 0)
			{
				chk++;
				break;
			}
		}
		if (chk == 0 && i != 1)
			cout << i << endl;
		chk = 0;
	}
	cout << endl;
}
int main()
{
	prime();
}