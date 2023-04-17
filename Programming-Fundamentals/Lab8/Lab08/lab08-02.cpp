#include <iostream>
#include <fstream>
using namespace std;
void read(ifstream & in)
{
	in.open("data.txt");
	char a[100] = { '\0' };
	in.getline(a, 100);
	cout << a<<endl;
	if (!in)
	{
		cout << "not found";
	}
	else
	{

		int count = 0;
		for (int i = 0; a[i]!='\0'; i++)
		{
			if ((a[i] >= 'a'&&a[i] <= 'z') || (a[i] >= 'A'&&a[i] <= 'Z'))
			{
				count++;
			}
			if ((a[i] == ' ') || (a[i] == ',') || (a[i] == ';') || (a[i] == ':'))
			{
				continue;
			}
			else
			{
				continue;
			}


		}
		cout << "alphaptes are" << count;
	}

}
int main()
{
	ifstream in;
	read(in);
	system("pause");
}