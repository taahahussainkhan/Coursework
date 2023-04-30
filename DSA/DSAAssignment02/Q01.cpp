//Taaha Hussain Khan
//L1F21BSCS0917
//D12
#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
};
class LinkedList {
public:
    LinkedList() {
        head = nullptr;
    }
    ~LinkedList() {
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }
    void insertAtBeginning(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    void deleteMiddle() {
        if (head == nullptr) {
            return;
        }
        Node* slowPtr = head;
        Node* fastPtr = head;
        Node* prev = nullptr;
        while (fastPtr != nullptr && fastPtr->next != nullptr) {
            fastPtr = fastPtr->next->next;
            prev = slowPtr;
            slowPtr = slowPtr->next;
        }
        if (fastPtr == nullptr) { 
            prev->next = slowPtr->next;
            delete slowPtr;
        } else { 
            Node* next = slowPtr->next;
            slowPtr->data = next->data;
            slowPtr->next = next->next;
            delete next;
        }
    }
    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
private:
    Node* head;
};
int main() {
    LinkedList list;
    int n=0;
    cout << "Number of inputs: ";
    cin >> n;
    for (int i=0 ; i < n ; i++)
    {
        int num;
        cout << "Enter value " << i <<" : ";
        cin >> num;
        list.insertAtBeginning(num);
    }
    cout << "Original list: ";
    list.print();
    list.deleteMiddle();
    cout << "Updated list: ";
    list.print();
    return 0;
}
