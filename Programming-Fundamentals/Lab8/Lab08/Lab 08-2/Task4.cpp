#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void copyupper(ifstream &fin, ofstream &fout);
int main()
{
	ifstream fin("FIRST.txt");
	ofstream fout("SECOND.txt");
	copyupper(fin, fout);
}
void copyupper(ifstream &fin, ofstream &fout)
{
	string str;
	int i = 0;

	while (!fin.eof())
	{
		fin >> str[i];

		if ((str[i] >= 'a'&&str[i] <= 'z'))
			str[i] = str[i] - 32;
		if (str[i] == ' ')
			fout << ' ';
		fout << str[i];
	}
}