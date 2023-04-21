#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char data[100];
	ifstream fin;
	ofstream fout("lengths.txt");
	int len = 0,len1=0;
	int space = 0;
	fin.open("userdata.txt");
	while (!fin.eof())
	{
		int i = 0, space = 0;;
		while (!fin.eof())
		{
			int i = 0;
			fin.getline(data, 100);
			if (data[i] == ' ')
				space++;
			cout << space << endl;
			cout << data << endl;
			len = strlen(data);
			cout << len << endl;
			fout << len << endl;
			i++;
		}
	}
		/*if (data[i] == ' ')
		{
			len = strlen(data);
			cout << len << endl;
		}
		if (data[i] != ' ')
		{
			len1 = strlen(data);
			cout << len1 << endl;
			data[i] = '/0';
		}
		i++;
	}*/
}