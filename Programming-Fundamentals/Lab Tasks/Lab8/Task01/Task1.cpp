#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//void compare_f(ifstream &f1, ifstream &f2);
int main()
{
	ifstream f1("file1.txt");
	ifstream f2("file2.txt");
	string str1[1000], str2[1000], same[1000], same1[1000];
	int i = 0;
	while (!f1.eof() && !f2.eof())
	{
		f1 >> str1[i];
		f2 >> str2[i];
		cout << str1[i] << endl;
		cout << str2[i] << endl;
		for (int j = i; (!f2.eof()&&!f1.eof()); j++)
		{
			if (str1[i] == str2[j])
			{
				cout << "Same!" << i << endl;
				same[i] = str1[i];
			}
			else if (str2[i] == str1[j])
			{
				same1[i] = str2[i];
				cout << "Same1!" << i << endl;
			}
		}
		i++;
	}
	cout << same << endl;
	cout << same1 << endl;

}
/*void compare_f(ifstream &f1, ifstream &f2)
{
	f1.open("file1.txt");
	f2.open("file2.txt");
	string str1[1000], str2[1000];
	int i = 0;
	while (!f1.eof() && !f2.eof())
	{
		f1 >> str1[i];
		f2 >> str2[i];
		cout << str1[i] << endl;
		cout << str2[i] << endl;
		i++;
	}
}*/