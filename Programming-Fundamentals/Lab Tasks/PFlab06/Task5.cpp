#include<iostream>
using namespace std;
int main()
{
	int n;
	cout << "Enter a number : ";
	cin >> n;
	cout << *(&n) << endl;
	return 0;
}