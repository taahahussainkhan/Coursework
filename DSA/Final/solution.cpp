#include <iostream>
#include <unordered_map>
using namespace std;
void insert_reservation(unordered_map<string, int> &reservations);
void delete_reservation(unordered_map<string, int> &reservations);
void show_reservation(unordered_map<string, int> &reservations);
int main()
{
    unordered_map<string, int> reservations;
    int choice;
    do
    {
        cout << "\nEnter your choice: \n";
        cout << "1.\tMake a new reservation." << endl;
        cout << "2.\tDelete a reservation." << endl;
        cout << "3.\tShow all reservations." << endl;
        cout << "4.\tExit"<<endl;
        cin >> choice;
        if (choice == 1)
        {
            insert_reservation(reservations);
        }
        else if (choice == 2)
        {
            delete_reservation(reservations);
        }
        else if (choice == 3)
        {
            show_reservation(reservations);
        }
        else if (choice == 4)
        {
            cout << "Exiting..." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    } while (choice != 4);
}
void insert_reservation(unordered_map<string, int> &reservations)
{
    string guestName;
    int reservationNumber;
    cout << "Enter guest name: ";
    cin >> guestName;
    cout << "Enter reservation number: ";
    cin >> reservationNumber;
    if (reservations.find(guestName) == reservations.end()) 
    {
        reservations.insert(make_pair(guestName, reservationNumber));
        cout << "Reservation made." << endl;
    }
    else
    {                     
        cout << "Reservation already exists." << endl;
    }
}
void delete_reservation(unordered_map<string,int> &reservations)
{
    string guestName;
    int reservationNumber;
    cout << "Enter guest name to delete: ";
    cin >> guestName;
    auto it = reservations.find(guestName);
    if(it != reservations.end())
    {
        cout << "Reservation "<<it->second<< " deleted." << endl;
        reservations.erase(it);
    }
    else
    {
        cout << "Reservation does not exist." << endl;
    }
}
void show_reservation(unordered_map<string, int> &reservations)
{
    cout << "Number of reservations: " << reservations.size() << endl;
    cout << "Reservations: " << endl;
    for (auto it = reservations.begin(); it != reservations.end(); it++)
    {
        cout << "Guest name: " << it->first << endl;
        cout << "Reservation number: " << it->second << endl;
    }
}