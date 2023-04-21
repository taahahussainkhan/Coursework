#include<iostream>
using namespace std;
int main()
{
	int nmbr, r, rev = 0;
	int *num;
	cout << "Enter a number: ";
	cin >> nmbr;
	num = &nmbr;
	while (*num > 0) {
		r = *num % 10;
		rev = rev * 10 + r;
		*num = *num / 10;
	}
	cout << "Reverse of the number is: " << rev;
	cout << endl;
	return 0;
}