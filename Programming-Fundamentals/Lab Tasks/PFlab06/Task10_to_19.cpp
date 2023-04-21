#include<iostream>
using namespace std;
int main()
{
	int arr[10] = { 10, 20, 30, 40, 90, 70, 80, 60, 0 };
	int* ptr = &arr[4];
	cout << ++ptr << endl;
	cout << ptr++ << endl;
    cout << *ptr++ << endl;
    cout << *++ptr << endl;
	cout << *++ptr << " "<< ++*ptr << endl;
	cout << --ptr << endl;
	cout << ptr-- << endl;
	cout << *ptr-- << endl;
	cout << *--ptr << endl;
	cout << *--ptr << " " << --*ptr << endl;
}