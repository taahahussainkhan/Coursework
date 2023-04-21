#include<iostream>
using namespace std;
int readf();
int readf1();
int powerf(int,int);
int displayf(int );
int main()
{
	int l,h,b;
	h=readf();
	b = readf1();
	l=powerf(h,b );
	displayf(l);
}
int readf()
{
	int n = 0;
	cout << "Enter a number: ";
	cin >> n;
	
	return n;
}
int readf1()
{
	int p = 0;
	cout << "Enter power: ";
	cin >> p;
	return p;
}
int powerf(int n, int p)
{
	int result = 1;
	while (p != 0) {
		result *= n;
		--p;
	}
	return result;
}
int displayf(int result)
{
	cout <<"Result is: "<< result << endl;
	return result;
}