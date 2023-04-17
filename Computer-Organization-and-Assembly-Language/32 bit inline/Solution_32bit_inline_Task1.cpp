#include<iostream>
using namespace std;
int main()
{

	/*
		Task - 1
		Write a program in C++ that declares and initializes an integer array of 5 elements.The program then swaps
		the least and most significant bytes and the nibbles of the second byte of each element of the array using
		inline assembly language programming.
		*/
		int a[] = { 2,9,30,59,3 };

	for (int i = 0; i < 5; i++)
	{

		__asm
		{
			mov eax, i
			shl eax, 2
			mov edx, [a + eax];
			rol edx, 8;
			xchg dh, dl;
			ror edx, 8;
			ror dh, 4;

			mov[a + eax], edx
		}

	}
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << "\t";
	}


	return 0;
}