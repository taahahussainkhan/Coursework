//Taaha Hussain Khan
//L1F21BSCS0917
//D12
#include <iostream>
using namespace std;
void fibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm = 0;
    cout << "Fibonacci Series: ";
    cout << t1 << " " << t2 << " ";
    while (nextTerm <= n) {
        nextTerm = t1 + t2;
        if (nextTerm <= n)
            cout << nextTerm << " ";
        t1 = t2;
        t2 = nextTerm;
    }
    cout << endl;
}
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    fibonacci(num);
    int nthTerm = fib(num-1);
    cout << "The " << num << "th term in the Fibonacci series is: " << nthTerm << endl;

    return 0;
}
