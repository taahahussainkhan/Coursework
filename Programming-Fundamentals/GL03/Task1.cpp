#include<iostream>
using namespace std;
void getArrayElements(double*,int);
int calculateAverage(double*, int);
void displayInformation(double*, int, int);
int main()
{
	int sales;
	cout << "How many days of sales figures to process? ";
	cin >> sales;
	double* fig = NULL;
	fig = new double[sales];
	getArrayElements(fig,sales);

}
void getArrayElements(double* fig, int sales)
{
	fig = new double[sales];
	int day = 1,avg;
	cout << "Enter the sales figures below." << endl;
	for (int i = 0; i < sales; i++)
	{
		cout << "Day " << day<<" : ";
		cin >> fig[i];
		day++;
	}
	avg = calculateAverage(fig, sales);
	displayInformation(fig, sales, avg);
}
int calculateAverage(double* fig, int sales)
{
	double sum = 0;
	int avg = 0,count=0;
	for (int i = 0; i < sales; i++)
	{
		sum += *fig;
	}
	avg = (int)sum / sales;
	//cout << avg << endl;
	return avg;
}
void displayInformation(double* fig, int sales, int avg)
{
	int day1 = 1;
	for (int i = 0; i < sales; i++)
	{
		cout << "Day " << day1 << " sales:     $" << fig[i] << endl;
		day1++;
	}
	cout << "Average Sales:   $"<<avg << endl;
}