//Taaha Hussain Khan
//L1F21BSCS0917
//D12
#include <iostream>
using namespace std;
class CircularQueue {
private:
    int front;
    int rear;
    int size;
    int* queue;
public:
    CircularQueue(int size) {
        this->front = -1;
        this->rear = -1;
        this->size = size;
        this->queue = new int[size];
    }
    ~CircularQueue() {
        delete[] queue;
    }
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }
    bool isFull() {
        return ((rear+1) % size == front);
    }
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full." << endl;
            return;
        }
        else if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear+1) % size;
        }
        queue[rear] = value;
    }
    void printPairs() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Pairs of adjacent elements in the queue: ";
        for (int i = front; i != rear; i = (i+1) % size) {
            cout << "(" << queue[i] << ", " << queue[(i+1) % size] << ") ";
        }
        cout << "(" << queue[rear] << ", " << queue[front] << ")" << endl;
    }
};

// main function
int main() {
    CircularQueue queue(5);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.printPairs();

    return 0;
}
