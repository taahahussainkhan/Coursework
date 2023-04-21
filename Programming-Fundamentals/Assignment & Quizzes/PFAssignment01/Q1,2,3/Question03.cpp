#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	string key,line;
	int offset;
	ifstream fin;
	fin.open("words.txt");
	while (!fin.eof())
	{
		getline(fin, line);
		//cout << line << endl;
	}
	cout << "Enter the word you want to search: ";
	cin >> key;
	if (fin.is_open())
	{
	
		if (key == line)
			cout << "Word Found" << endl;
		else
			cout << "Word NOT Found" << endl;
	}
	else
		cout << "File not found!" << endl;

}