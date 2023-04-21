#include<iostream>
using namespace std;
void del_array(int*, int, int*, int);
void input(int, int);
void merge_arrays(int*, int, int*, int);
void sort_array(int*, int, char);
int main()
{
	int size1 = 0, size2 = 0;
	cout << "Enter size of array 1.." << endl;
	cin >> size1;
	cout << "Enter size of array 2.." << endl;
	cin >> size2;
	input(size1, size2);

}
void input(int size1, int size2)
{
	int size3 = 0;
	int* arr1 = NULL;
	arr1 = new int[size1];
	int* arr2 = NULL;
	arr2 = new int[size2];
	size3 = size1 + size2;
	cout << "enter data in array 1.." << endl;
	for (int i = 0; i < size1; i++)
	{
		cin >> arr1[i];
	}
	cout << endl;
	cout << "enter data in array 2.." << endl;
	for (int i = 0; i < size2; i++)
	{
		cin >> arr2[i];
	}
	cout << "array 1" << endl;
	for (int i = 0; i < size1; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;
	cout << "array 2" << endl;
	for (int i = 0; i < size2; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
	merge_arrays(arr1, size1, arr2, size3);
	del_array(arr1, size1, arr2, size2);
}
void merge_arrays(int* arr1, int size1, int* arr2, int size3)
{
	char seq;
	int* arr3 = NULL;
	arr3 = new int[size3];
	cout << "array 3" << endl;
	int j = 0;
	for (int i = 0; i < size3; i++)
	{

		if (i < size1)
		{
			arr3[i] = arr1[i];
		}
		else
		{
			arr3[i] = arr2[j];
			j++;
		}


	}
	for (int i = 0; i < size3; i++)
	{
		cout << arr3[i] << " ";
	}
	cout << endl;
	cout << "Press \n";
	cout << "'a' for ascending order.\n'd' for descending order." << endl;
	cin >> seq;
	sort_array(arr3, size3, seq);
}
void sort_array(int* arr3, int size3, char seq)
{
	int temp = 0;
	if (seq == 'a')
	{
		for (int i = 0; i<size3; i++)
		{
			for (int j = i; j<size3; j++)
			{
				if (arr3[i]>arr3[j])
				{
					temp = arr3[i];
					arr3[i] = arr3[j];
					arr3[j] = temp;
				}

			}
			cout << arr3[i] << " ";
		}
	}
	else if (seq == 'd')
	{
		for (int i = 0; i<size3; i++)
		{
			for (int j = i; j<size3; j++)
			{
				if (arr3[i]<arr3[j])
				{
					temp = arr3[i];
					arr3[i] = arr3[j];
					arr3[j] = temp;
				}

			}
			cout << arr3[i] << " ";
		}
	}
	
	else
	{
		cout << "Wrong input!" << endl;
	}
}
void del_array(int* arr1, int size1, int* arr2, int size2)
{
	delete[] arr1,
	delete[] arr2;
	cout << "\n\nAfter deletion:\n\n";
	cout << endl;
	cout << "array 1" << endl;
	for (int i = 0; i < size1; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;
	cout << "array 2" << endl;
	for (int i = 0; i < size2; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
}
