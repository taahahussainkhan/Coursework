#include<iostream>
using namespace std;
int main(){
	int sum = 0, number, remain;
	cout << "Enter a five digit number : ";
	
	for (cin >> number; number > 0; number = number / 10)
	{

		remain = number % 10;
		sum = sum + remain;
		
		cout << remain << endl;
	}
	cout << sum << endl;
	
	system("pause");
	return 0;

}