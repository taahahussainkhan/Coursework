#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int count = 0,space=0;
	int sent = 0;
	char str[10000] = { '\0' };
	ifstream fin;
	fin.open("literature.txt");
	fin.getline(str, 9999);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ' ')
			space++;//words counter
		if ((str[i] >= 65) && (str[i] <= 90) || (str[i] >= 97) && (str[i] <= 122))
		count++;//alphabet counter
		if (str[i] == '.'||str[i]=='?')
			sent++;//Sentence counter
		
	}
	cout << "Number of sentences: " << sent << endl;
	cout <<"Number of alphabets: "<< count << endl;
	cout <<"Number of words: "<< ++space << endl;
	
}