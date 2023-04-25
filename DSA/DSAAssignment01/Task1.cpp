//Taaha Hussain Khan
//L1F21BSCS0917
//D12
#include<iostream>                 
using namespace std;
void BinarySearch(int*,int,int);
int main()
{
	cout << "Enter size of your array : ";
	int size;
	cin >> size;
	int* arr = new int[size];
	cout << "Enter values : \n";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	cout << "Array : ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	cout << endl;
	cout << "Sorted Array : ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Key: ";
	int key;
	cin >> key;
	BinarySearch(arr, size, key);
}
void BinarySearch(int* arr, int size, int key)
{
	int start = 0;
	int check = 0;
	int end = size;
	int mid = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] == key)
		{
			check = 0;
			cout << endl;
			cout << key << " found at " << mid;
			if (mid == 1)
				cout << "st" << " index" << endl;
			else if (mid == 2)
				cout << "nd" << " index" << endl;
			else if (mid == 3)
				cout << "rd" << " index" << endl;
			else
				cout << "th" << " index" << endl;
			break;
		}
		else if (arr[mid] < key)
		{
			check++;
			start = mid + 1;
		}
		else
		{
			check++;
			end = mid - 1;
		}
	}
	if (check > 0)
	{
		cout << "Key not found!" << endl;
	}
}