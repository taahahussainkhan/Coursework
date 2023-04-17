#include<iostream>
using namespace std;
int calcMul(int arr1[],int);
int calcSum(int arr2[], int);
int main()
{
	int arr1[10],arr2[10] ,m, s,i=0;
	cout << "Enter a: ";
	for (i = 0; i < 10; i++)
		cin >> arr1[i];
	cout << "Enter b: ";
	for (i = 0; i < 10; i++)
		cin >> arr2[i];
	m = calcMul(arr1,10);
	s = calcSum(arr2,10);
	cout << "Result is: " << m << endl;
	cout << "Result is: " << s << endl;
}
int calcMul(int arr1[],int)
{
	int sum=0;
	for (int i = 0; i < 10; i++)
 sum = sum + arr1[i];

	return sum;
}
int calcSum(int arr2[],int)
{
	int sum1=0;
	for (int i = 0; i < 10; i++)
	 sum1= sum1 + arr2[i];
	return sum1;

}