#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream fin("sentence.txt");
	ofstream fout("word.txt");
	char data[10];
	cout << 1;
	while (fin.eof() == 0)
	{
		cout << 2;
		fin.getline(data, 9, ' ');
		fout << data << endl;
	}
	cout << 3;
	cout << endl;
	getchar();
	return 0;
}