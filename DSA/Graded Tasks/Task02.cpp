//Taaha Hussain Khan
//L1F21BSCS0917
//D12
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void insertAtTail(Node *&head, int data);
void display(Node *head);
Node *reverse(Node *&head);
Node *reverseRecursive(Node *&head);
int main()
{
    Node *head = NULL;
    int num, n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        /* code */
         cout << "Enter data for node "<< i <<" : ";
        cin >> num;
        insertAtTail(head, num);
    }
    cout << "Original Linked List : " << endl;
    display(head);
    Node *newhead = reverseRecursive(head);
    cout << "Reversed Linked List : " << endl;
    display(newhead);
    return 0;
}
void insertAtTail(Node *&head, int data)
{
    Node *n = new Node(data);
    if (head == NULL)
    {
        head = n;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
Node *reverse(Node *&head)
{
    Node *prevptr = NULL;
    Node *currptr = head;
    Node *nextptr;
    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}
Node *reverseRecursive(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}