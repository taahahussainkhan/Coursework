#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	int number;
	int guess;
	int chance = 1;
	bool flag = 0;
	srand(time(0));
	number = rand() % 5;
	do
	{
		cout << "Enter an integer between 0 and 5 (you have two attempts) : ";
		cin >> guess;
		if (number == guess)
		{
			cout << "Correct!!!  " << endl;
			flag = 1;
		}
		if (number != guess)

		{

			if (chance<2)
			{
				cout << "Guess again!!!" << endl;
				chance++;
			}
			else
			{
				cout << "you lose, the correct digit is : " << number << endl;
				flag = 1;
			}
		}
	} while (!flag);
	return 0;
	system("pause");
}