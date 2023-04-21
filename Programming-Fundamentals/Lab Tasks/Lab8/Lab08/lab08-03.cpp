#include<iostream>
#include<fstream>
using namespace std;
void read(ifstream & in)
{
	in.open("data.txt");
	char arr[100] = {'\0'};
	int word = 0;
	in.getline(arr, 100);
	for (int i = 0; i < 100; i++)
	{
		if ((arr[i] == 't' || arr[i] == 'T') && (arr[i + 1] == 'h' || arr[i + 1] == 'H') && (arr[i + 2] == 'e' || arr[i + 2] == 'E') && (arr[i + 3] == ' '))
		{
			word++;
		}
	}
	cout << "Total count of words are:"<<word<<endl;

}
int main()
{
	ifstream in;
	read(in);
	system("pause");
}