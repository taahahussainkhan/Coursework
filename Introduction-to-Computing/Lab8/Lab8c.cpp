#include<iostream>
using namespace std;
int main()
{
	int x;
	cout << "Enter a value: " << endl;
	cin >> x;
	cout << "Value before post-incrementing\nx=" << x << endl;
	cout << "Value after post-incrementing\nx=" << x++ << endl;
	system("pause");
	return 0;
}