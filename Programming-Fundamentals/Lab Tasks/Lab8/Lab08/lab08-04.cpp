#include<iostream>
#include<fstream>
using namespace std;
void copyUpper(char[],int);

void copyUpper(char arr[], int size)
{
	ofstream out;
	out.open("second.txt");
	ifstream in;
	in.open("first.txt");
	for (int i = 0; !in.eof(); i++)
	{
		in >> arr[i];
		if (arr[i] >= 'a'&&arr[i] <= 'z')
		{
			arr[i] = arr[i] - 32;
			cout << arr[i];
		}
	}
	out << arr;
	
}
int main()
{
	char arr[100] = { '\0' };
	copyUpper(arr, 100);

}