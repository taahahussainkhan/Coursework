#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void alpha_count(ifstream &fin);
int main()
{
	ifstream fin("out.txt");
	alpha_count(fin);
	
}
void alpha_count(ifstream &fin)
{
	char str[10000];
	int alpha = 0, i = 0;
	while (!fin.eof())
	{
		fin >> str[i];
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			alpha++;
		}

		i++;
	}
	cout << "Count: " << alpha << endl;
}