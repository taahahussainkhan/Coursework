//Taaha Hussain Khan
//L1F21BSCS0917
//D12
#include <iostream>
using namespace std;
// Recursive function 
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    int result = gcd(a, b);

    cout << "GCD of " << a << " and " << b << " is: " << result << endl;

    return 0;
}
