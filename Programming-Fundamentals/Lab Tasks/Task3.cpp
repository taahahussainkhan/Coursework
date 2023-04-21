#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream f1;
	f1.open("data.txt");
	char arr[100] = { '\0' };
	int count = 0;
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] != ' ')
		{
			f1 >> arr[i];
			count++;
		}
		if (f1.eof())
			break;
	}
	cout <<"Count: "<< count<<endl;
	f1.close();




}