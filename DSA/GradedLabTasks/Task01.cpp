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
Node *nthNodeFromEnd(Node *head, int n);
void display(Node *head);
void insertAtTail(Node *&head, int data);
int main()
{
    Node *head = NULL;
    int key, n, node;
    cout << "Enter the number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> key;
        insertAtTail(head, key);
    }
    cout << "Linked List : " << endl;
    display(head);

    cout << "Enter the value of n: ";
    cin >> node;
    cout << "N: " << node << endl;
    if (node <= n)
    {
        Node *result = nthNodeFromEnd(head, node);
        cout << "Output : "<< result->data << endl;
    }
    else
    cout << "Nothing there! " << endl ;
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
Node *nthNodeFromEnd(Node *head, int n)
{
    Node *s = head, *fast = head;
    int count = 0;

    while (fast != NULL)
    {
        fast = fast->next;
        count++;
        if (count > n)
        {
            s = s->next;
        }
    }
    return s;
}