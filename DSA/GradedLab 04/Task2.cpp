#include<iostream>
using namespace std;
class Node{
public:
	int data;
	Node* nextPtr;
	Node* prevPtr;
	Node(int data){
		this->data = data;
		nextPtr = NULL;
		prevPtr = NULL;
	}
};
void insertAtHead(Node* &head, int data){
	Node* n = new Node(data);
	n->nextPtr = head;
	if (head != NULL){
		head->prevPtr = n;
	}
	head = n;
}
void insertAtTail(Node* &head, int data){
	if (head == NULL){
		insertAtHead(head, data);
		return;
	}
	Node* n = new Node(data);
	Node* temp = head;
	while (temp->nextPtr != NULL){
		temp = temp->nextPtr;
	}
	temp->nextPtr = n;
	n->prevPtr = temp;

}

void display(Node* head){
	Node* temp = head;
	cout << "\n\tNULL -> ";
	while (temp != NULL){
		cout << temp->data << " -> ";
		temp = temp->nextPtr;
	}
	cout << "NULL\n" << endl;
}
void reverseList(Node* &head) {
	if (head != NULL) {
		Node* prevNode = head;
		Node* temp = head;
		Node* curNode = head->nextPtr;
		prevNode->nextPtr = NULL;
		prevNode->prevPtr = NULL;

		while (curNode != NULL) { 
			temp = curNode->nextPtr;
			curNode->nextPtr = prevNode;
			prevNode->prevPtr = curNode;
			prevNode = curNode;
			curNode = temp;
		}
		head = prevNode;
	}
}

int main(){

	Node* head = NULL;
	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtTail(head, 4);
	display(head);
	cout << "Reversed Doubly Linked List: " << endl;
	reverseList(head);
	display(head);
	return 0;
}