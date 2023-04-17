#include<iostream>
using namespace std;
void print_numbers(int *v1);
int main()
{
	int *a=NULL;
	*a = 1;
	int v1;
	v1 = *a;
	
	print_numbers(&v1);
}
void print_numbers(int *v1)
{
	for (*v1 = 1; *v1 < 10; *v1++)
	{
		cout << *v1 << endl;
	}
}