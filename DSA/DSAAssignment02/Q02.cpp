//Taaha Hussain Khan
//L1F21BSCS0917
//D12
#include <iostream>
#include <string>
using namespace std;
struct Node
{
    string name;
    int id;
    int year_of_joining;
    Node *next;
};
class LinkedList
{
private:
    Node *head;
public:
    LinkedList()
    {
        head = NULL;
    }
    void addEmployee(string name, int id, int year_of_joining)
    {
        Node *newNode = new Node();
        newNode->name = name;
        newNode->id = id;
        newNode->year_of_joining = year_of_joining;
        newNode->next = head;
        head = newNode;
    }
  void removeDuplicates()
    {
        Node *current = head;
        while (current != NULL)
        {
            Node *runner = current;
            while (runner->next != NULL)
            {
                if (current->id == runner->next->id)
                {
                    Node *duplicate = runner->next;
                    runner->next = runner->next->next;
                    delete duplicate;
                }
                else
                {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }
    void sort()
    {
        Node *current = head;
        Node *runner = NULL;
        while (current != NULL)
        {
            runner = current->next;
            while (runner != NULL)
            {
                if (current->year_of_joining > runner->year_of_joining)
                {
                    string temp_name = current->name;
                    int temp_id = current->id;
                    int temp_year_of_joining = current->year_of_joining;
                    current->name = runner->name;
                    current->id = runner->id;
                    current->year_of_joining = runner->year_of_joining;
                    runner->name = temp_name;
                    runner->id = temp_id;
                    runner->year_of_joining = temp_year_of_joining;
                }
                runner = runner->next;
            }
            current = current->next;
        }
    }
    void display()
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << "Name: " << current->name << endl;
            cout << "ID: " << current->id << endl;
            cout << "Year of joining: " << current->year_of_joining << endl;
            cout << endl;
            current = current->next;
        }
    }
};
int main()
{
    LinkedList list;
    int choice;
    char opt;
    do{
    cout << "1. Insert a new Employee. " << endl;
    cout << "2. Find and remove duplicate employee record. " << endl;
    cout << "3. Sort the linked list with respect to the year of joining" << endl;
    cout << "4. Display the employee records" << endl;
    cin >> choice ;
    if (choice == 1)
    {
        string name;
        int id, year, n, i = 0;
        cout << "Number of Employee :";
        cin >> n;
        while (i < n)
        {
            cout << "Name: ";
            cin >> name;
            cout << "ID: ";
            cin >> id;
            cout << "Year of Joining: ";
            cin >> year;
            list.addEmployee(name, id, year);
            i++;
        }
    }
    else if( choice == 2)
       { list.removeDuplicates();
       cout << "Value Removed Successfully !" << endl;
       list.display();
       }
    else if( choice == 3)    
        {
            list.sort();
            cout << "List sorted successfully! "<<endl;
                    }
    else if( choice == 4){  
        list.display();
    }
    cout << "Y/y OR N/n" << endl;
    cin >> opt;
    if (opt == 'y' || opt == 'Y')
        continue;
    else
        break;
    }while(true);
    return 0;
}
