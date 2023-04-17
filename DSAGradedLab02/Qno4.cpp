//Taaha Hussain Khan
//L1F21BSCS0917
//D12
#include <iostream>
#include <string>
using namespace std;
class Stack {
private:
    char* data; 
    int top; 
    int size; 
public:

    Stack(int max_size) {
        size = max_size;
        data = new char[size];
        top = -1; 
    }
    ~Stack() {
        delete[] data;
    }
    bool isEmpty() { 
        return (top == -1);
    }
    bool isFull() { 
        return (top == size-1);
    }
    void push(char value) { 
        if (isFull()) {
            cout << "Stack overflow." << endl;
            return;
        }
        top++;
        data[top] = value;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow." << endl;
            return;
        }
        top--;
    }
    char peek() { 
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return '\0';
        }
        return data[top];
    }
};

string removeDuplicates(string str) {
    Stack st(str.length());
    for (char ch : str) {
        if (!st.isEmpty() && st.peek() == ch) {
            st.pop();
        }
        else {
            st.push(ch);
        }
    }
    string result = "";
    while (!st.isEmpty()) {
        result = st.peek() + result;
        st.pop();
    }
    return result;
}

int main() {
    string str = "abbzyzt";
    cout << "Original string: " << str << endl;
    str = removeDuplicates(str);
    cout << "String after removing pairs of duplicates: " << str << endl;
    return 0;
}
