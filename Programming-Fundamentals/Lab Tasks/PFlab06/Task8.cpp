#include <iostream>
using namespace std;
int main() {
	int factorial = 1,  n;
	cout << "Enter a positive integer: ";
	cin >> n;
	int *ptr = &n;
	if (*ptr < 0)
		cout << "Error! Factorial of a negative number doesn't exist.";
	else {
		for (int i = 1; i <= *ptr; ++i) {
			factorial *= i;
		}
		int *f = &factorial;
		cout << "Factorial of " << *ptr <<" is "<< " = " << *f;
	}
	cout << endl;
	return 0;
}