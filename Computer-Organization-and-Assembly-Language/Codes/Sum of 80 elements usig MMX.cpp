#include <iostream>
unsigned char v1[80], sum[8], final_sum = 0;
void main(void) {

	std::cout << "Sum of 80 elements (1's) of a c++ array using MMX (Inline Assmbly) is: \t";

	for (int i = 0; i < 80; i++)  //Initializing every element with 1 (as per requirements).
	{
		v1[i] = 1;
	}

	for (int i = 0; i < 80; i = i + 8)
	{
		__asm
		{
				mov eax, i
				movq mm0, [v1 + eax]
				paddb mm7, mm0
		}
	}

	__asm movq [sum], mm7
	
	for (int i = 0; i < 8; i++)
	{
		final_sum += sum[i];//Summing the final sum serially
	}

	
	std::cout << (int)final_sum << std::endl; //Typecasting, from unsigned char to int. And displaying it on console.

	system("pause");
}