#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int arr[5][5] = {}, pc[5][5] = {}, not[5][5], co = 0;

	int  curoot, ans;
	ifstream fin("data.txt");
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
		fin >> arr[i][j];
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
	cout << arr[i][j];
	
	cout << "\n\n Check whether a number is a perfect cube or not: \n";
	cout << " -----------------------------------------------------\n";
	for (int i = 0; !fin.eof(); i++)
	{
		for (int j = 0; !fin.eof(); j++)
		{
			curoot = round(pow(arr[i][j], 1.0 / 3.0));
			co++;
			if (curoot*curoot*curoot == arr[i][j])
			{
				pc[i][j] = arr[i][j];
			}
			else
			{
				not[i][j] = arr[i][j];
			}
		}
	}
	cout << "Perfect cubes are: \n";
	for (int i = 0; i<5; i++)
	{
		for (int j = 0; j<5; j++)
		{
			cout << pc[i][j] << " ";
		}
	}
	cout << "Non perfect cubes are: \n";
	for (int i = 0; i<5; i++)
	{
		for (int j = 0; j<5; j++)
		{
			cout << not[i][j] << " ";
		}
	}
}
