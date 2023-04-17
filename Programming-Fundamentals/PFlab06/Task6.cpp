#include<iostream>
using namespace std;
void display(int *a);
int main()
{
	int n;
	cout << "Enter a number: ";
	cin >> n;
	display(&n);
	return 0;
}
void display(int *a)
{
	cout << *a << endl;
}