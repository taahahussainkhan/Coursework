#include<iostream>
#include<fstream>
using namespace std;
void namef()
{
	char arr[20];
	cout << "Enter name: ";
	cin.getline(arr, 19);
	cout << arr<<endl;
}
int main()
{
	namef();
}