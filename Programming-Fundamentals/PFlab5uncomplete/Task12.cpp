#include<iostream>
using namespace std;
char readf()
{
	char sent[30] = { '\0' };
	cout << "Enter a sentence: ";
	cin.getline(sent, 29);
	//cout << sent<<endl;
	return 'a';
}
char checkf(char sent[])
{
	int count = 0;
	char key = '\0';
	cout << "Enter an alphabet to search: ";
	cin >> key;
	cout << sent << endl<<"ok";
	for (int i = 0; sent[i] != '\0';i++)
	if (key == sent[i])
		count++;
	cout << "Total occurences: " << count<<endl;
	return count;
}
int main()
{
	char sent[30];
	for (int i = 0; sent[i] != '\0';i++)
	sent[i]=readf();
	checkf(sent);
}