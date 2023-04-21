#include<iostream>
using namespace std;
int main()
{
	int arr[3][3];
	cout << "Enter data in 2D array: ";
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
		cin >> arr[i][j];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		if (arr[i][j] % 2 == 0)
			cout << "Even: " << arr[i][j] << endl;
		else if (arr[i][j] % 2 != 0)
			cout << "Odd: " << arr[i][j] << endl;
	}
}