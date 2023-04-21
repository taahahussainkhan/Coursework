#include<iostream>
#include<fstream>
using namespace std;
void thef();
int main()
{
	ifstream fin("data.txt");
	char arr[1000];
	int i = 0,the=0;
	fin.getline(arr, 999);
	int size = strlen(arr);
	//cout << arr;
	while (i<size)
	{
		if ((arr[i] == 't' || arr[i] == 'T') && (arr[i + 1] == 'h' || arr[i + 1] == 'H') && (arr[i + 2] == 'e' || arr[i + 2] == 'E') && (arr[i + 3] == ' '))
			the++;
		i++;
	}
	cout << the << endl;
}