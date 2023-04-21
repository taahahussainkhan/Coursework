#include<iostream>
using namespace std;
int main()
{

	int n1;
	cout << "Enter a value: ";
	cin >> n1;
	int* ptr=&n1;
	cout << "Address of the  pointer to a variable is " << ptr << endl;



}