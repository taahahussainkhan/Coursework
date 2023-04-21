#include<iostream>
using namespace std;
int main()
{
	int arr[3][5] = {};
	cout << "Enter values in aaray: ";
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 5; j++)
		cin >> arr[i][j];
	cout << "------------------------" << endl;
	cout << "Before Reverse: " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << "------------------------" << endl;
	cout << "After Reverse: " << endl;
	for (int i = 2; i >= 0; i--)
	{
		for (int j = 4; j >= 0; j--)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}