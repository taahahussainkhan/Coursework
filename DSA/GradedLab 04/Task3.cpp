#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	 Node *next;
	 Node *prev;
	 Node(int data)
	 {
		 this->data = data;
		 next = NULL;
		 prev = NULL;
	 }
};
void inserAtHead(Node* &head, int data)
{
	Node* newNode = new Node(data);
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = head;

	if (head != NULL)
	{
		head->prev = newNode;
	}
	head = newNode;
}
void sort(Node* head)
{
	Node* temp1 = head;
	while (temp1 != NULL)
	{
		Node* temp2 = temp1 -> next;
		while (temp2 != NULL)
		{
			if (temp1->data > temp2->data)
			{
				int temp = temp1->data;
				temp1->data = temp2->data;
				temp2->data = temp;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}
void DeleteNode(Node* &head, Node* todelete)
{
	if (head == NULL || todelete == NULL)
	{
		return;
	}

	if (head == todelete)
	{
		head = todelete->next;
	}
	if (todelete->next != NULL)
	{
		todelete->next->prev = todelete->prev;
	}
	if (todelete->prev != NULL)
	{
		todelete->prev->next = todelete->next;
	}
	free(todelete);
}
void removeDuplicates(Node* &head)
{
	if (head == NULL || head->next == NULL)
	{
		return;
	}
	Node* temp1 = head;
	Node* temp2 = head;
	for (temp1 = head; temp1 != NULL; temp1 = temp1->next)
	{
		temp2 = temp1->next;
		while (temp2 != NULL)
		{
			if (temp1->data == temp2->data)
			{
				 Node* curr = temp2->next;
				DeleteNode(head, temp2);
				temp2 = curr;
			}
			else
			{
				temp2 = temp2->next;
			}
		}
	}
}
void display(Node* head){
	Node* temp = head;
	cout << "\n\tNULL -> ";
	while (temp != NULL){
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL\n" << endl;
}
int main()
{
	Node* head = NULL;
	cout << "Original Linked List: " << endl ;
	inserAtHead(head, 10);
	inserAtHead(head, 13);
	inserAtHead(head, 11);
	inserAtHead(head, 10);
	inserAtHead(head, 13);
	inserAtHead(head, 18);
	inserAtHead(head, 10);
	display(head);
	sort(head);
	cout << "Sorted Linked List: " << endl;
	display(head);
	removeDuplicates(head);   
	cout << "After removing duplicate values: " << endl;
	display(head);
	return 0;
}