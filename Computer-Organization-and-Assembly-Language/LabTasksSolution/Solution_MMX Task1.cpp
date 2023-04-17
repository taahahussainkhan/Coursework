#include <iostream>
using namespace std;
int main()
{
	unsigned char v1[80], v2[80], v4[80], v3[8] = { 1,1,1,1,1,1,1,1 };
	__asm
	{
		movq mm2, [v3]              // Moving V2 data in MM2 for initialization
	}
	for (int i = 0; i < 80; i += 8)   // Iterating my loop with jumps of 8
	{                               // to move values in MM registers
		__asm
		{
			mov   ecx, i            // Storing my index value in ECX register
			movq[v1 + ecx], mm2
			movq[v2 + ecx], mm2    // Initializing every element with 1 
			movq  mm1, [v1 + ecx]   // Moving 8 byte data from Array to MM1
			paddb mm1, [v2 + ecx]             // Adding and Storing values in MM7
			movq[v4 + ecx], mm1
		}
	}
	__asm
	{
		emms                        // Clearing MM registers
	}

	for (int i = 0; i < 80; i++)
		cout << i + 1 << "\t" << (int)v4[i] << endl;


}