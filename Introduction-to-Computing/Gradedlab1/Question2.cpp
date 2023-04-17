#include<iostream>
using namespace std;
int main()
{
	int Fuel, Rent, Bills, Total;
	cout << "Enter expense of fuel: " ;
	cin >> Fuel;
	cout << "Enter your rent:  " ;
	cin >> Rent;
	cout << "Enter your bills: ";
	cin >> Bills;
	cout << "___________________" << endl;
	cout << "Fuel       " << Fuel << endl;
	cout << "Rent       " << Rent << endl;
	cout << "Bills      " << Bills << endl;
	cout << "___________________" << endl;
	Total = Fuel + Rent + Bills;
	cout << "Total      " << Total << endl;
	return 0;
}