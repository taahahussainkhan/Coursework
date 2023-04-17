#include <iostream>
using namespace std;
int main()
{
	unsigned char v1[80], v3[8] = { 1,1,1,1,1,1,1,1 }, v4[8] = { 1,2,1,2,1,2,1,2 };
	__asm
	{
		pxor mm7, mm7
		pxor mm6, mm6
		pxor mm5, mm5
	}

	for (int i = 0; i < 80; i += 8)
	{
		__asm
		{
			mov   ecx, i
			movq mm3, [v4]
			movq[v1 + ecx], mm3
			movq  mm0, [v1 + ecx]
			movq mm1, [v3]
			movq mm4, [v3]
			pand  mm1, mm0
			pcmpeqb mm4, mm1
			pcmpeqb mm1, mm7
			pand mm0, mm1
			paddb mm6, mm0

			movq  mm0, [v1 + ecx]
			pand mm0, mm4
			paddb mm5, mm0
		}
	}
	__asm
	{
		movq[v3], mm6
	}
	unsigned char even = 0, odd = 0;
	for (int i = 0; i < 8; i++)
		even += v3[i];
	__asm
	{
		movq[v3], mm5
	}
	for (int i = 0; i < 8; i++)
		odd += v3[i];
	__asm
	{
		emms
	}
	cout << "Sum of even is : " << (int)even << endl;
	cout << "Sum of odd is : " << (int)odd << endl;


}