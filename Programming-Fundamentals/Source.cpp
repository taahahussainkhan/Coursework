#include <iostream>  
using namespace std;
int main()
{
	int arr[3][3];
	int a[3] = {0};
	int t = 0;
	cout << "-------This is your 3 by 3 matrix------\n" ;
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter ("<<i+1<< ") row : \n";
		for (int j = 0; j < 3; j++)
		{
			cin>> arr[i][j];
		}
	}
	for (int i = 0; i < 3;i++)
	{
		a[i]=arr[0][i];
	}
	for (int i = 0; i < 3;i++)
	{
		for (int j = i; j < 3;j++)
		{
			if (a[i]>a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		arr[0][i] = a[i];
	}
	
	

	for (int i = 0; i < 3; i++)
	{
		a[i] = arr[1][i];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++)
		{
			if (a[i]>a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		arr[1][i] = a[i];
	}
	


	for (int i = 0; i < 3; i++)
	{
		a[i] = arr[2][i];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++)
		{
			if (a[i]>a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		arr[2][i] = a[i];
	}
	cout << "Your matrix is sorted row by row: \n";
	for (int i = 0; i < 3;i++)
	{
		for (int j= 0; j < 3;j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}



	system("pause");
	return 0;
}