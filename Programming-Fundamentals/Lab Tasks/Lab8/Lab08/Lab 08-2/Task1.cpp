#include<iostream>
#include<fstream>
using namespace std;
void record_add(){
	ofstream output("records.txt", ios::app);
	int id, price;
	char title[100];
	cout << "ENTER BOOK ID:"; cin >> id;
	cin.ignore();
	cout << "ENTER BOOK NAME:"; cin.getline(title, 100);
	cout << "ENTER BOOK PRICE:"; cin >> price;
	cin.ignore();
	output << id << "\t" << title << "#\t" << price << endl;
	output.close();
}
void record_view(){
	ifstream read("records.txt");
	int check;
	int id;
	int price;
	cout << "ENTER ID TO SEARCH"; cin >> check;
	char array[100];
	while (read >> id){
		if (id == check){
			cout << "ID;" << check;
			read.getline(array, 100, '#');
			cout << "\nNAME;" << array << endl;
			read >> price;
			cout << "price:" << price << endl;
			read.close();
		}
		while (read.peek() != '\n')
			read.ignore();
	}
}
void record_delete(){

}
int main(){
	char option;
	int menu = 0;
	while (1){
		cout << "1.Add new record\n2.view particular record \n3. Delete particular record";
		cout << "\n-->"; cin >> menu;
		if (menu == 1)
		record_add();
		else if (menu == 2)
			record_view();
		else if (menu == 3)
			record_delete();
		cout << "Do you want to continue? (y/n) -->"; cin >> option;
		if (option == 'n')
		break;
		cin.ignore();
	}
	system("pause");
	return 0;
}