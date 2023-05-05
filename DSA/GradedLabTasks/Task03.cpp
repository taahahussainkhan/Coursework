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
void removeDuplicates(Node* head)
{
	Node* current = head;
	Node* next_next;
	if (current == NULL)
		return;
	while (current->next != NULL) {
		if (current->data == current->next->data) {
			next_next = current->next->next;
			free(current->next);
			current->next = next_next;
		}
		else 
		{
			current = current->next;
		}
	}
}
void insert(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void printList(Node* node)
{
	while (node != NULL) {
		cout << " " << node->data;
		node = node->next;
	}
}
int main()
{
	Node* head = NULL;
    int n ,num ;
    cout << "Enter the number of nodes:" ;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << "Enter value " << i << " : " ; 
        cin >> num ;
    insert(&head, num);
    }
	cout << "Original Linked list :" << endl;
	printList(head);
	removeDuplicates(head);
    cout << endl ;
	cout << "Linked List without duplicates :" << endl;
	printList(head);
}
