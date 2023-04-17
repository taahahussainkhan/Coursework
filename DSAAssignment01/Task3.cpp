//Taaha Hussain Khan
//L1F21BSCS0917
//D12
#include<iostream>
using namespace std;
template <class type>
class Stack {
protected:
    int top;
    int maximumSize;
    type* arr;
public:

    Stack() {
        maximumSize = 30;
        top = -1;
        arr = new type[maximumSize];
    }

    Stack(int s) {
        maximumSize = s;
        top = -1;
        arr = new type[s];
    }

    virtual bool isEmpty() = 0;
    virtual void push(type value) = 0;
    virtual type pop() = 0;
    virtual void display() = 0;
};

template <class type>
class myStack : public Stack<type> {
public:
    myStack() : Stack<type>() {

    }

    myStack(int s) : Stack<type>(s) {
        this->push(25);
        this->push(27);
        this->push(30);
    }

    virtual bool isEmpty() {
        return this->top == -1;
    }

    virtual void push(type value) {
        if (this->top == this->maximumSize - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        this->top++;
        this->arr[this->top] = value;
    }

    virtual type pop() {
        if (this->top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        type temp = this->arr[this->top];
        this->top--;
        return temp;
    }

    virtual void display() {
        cout << "Stack: " << endl;
        for (int i = 0; i <= this->top; i++) {
            cout << this->arr[i] << endl;
        }
    }
};

int main() {
    myStack<int> obj(10);
    obj.push(90);
    obj.push(88);
    obj.push(100);
    for (int i = 0; i < 10; i++) {
        if (obj.pop() == 27) {
            break;
        }
    }
    obj.display();
    return 0;
}
