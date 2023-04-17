#include<iostream>
using namespace std;
int main()
{
	int array1[] = { 1,2,0xaabb25dd,4,5 };

	for (int i = 0; i < 20; i += 4)
	{
		__asm
		{
			mov ecx, i
			mov edx, [array1 + ecx]


			rol edx, 8
			xchg dh, dl
			ror edx, 16


			mov[array1 + ecx], edx

		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << array1[i] << endl;
	}
	return 0;
}