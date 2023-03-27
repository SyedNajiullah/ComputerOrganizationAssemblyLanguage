#include<iostream>
//PROGRAM TO ADD ELEMENTS OF CHAR ARRAY IN ASSEMBLY USING MMX REGISTERS 
int main(void)
{

	unsigned char arr[80] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2 };
	unsigned char crr[40] = "\0";
	unsigned int sum = 0;
	__asm
	{

		xor ecx, ecx
			xor esi, esi
			xor edi, edi
			mov ecx, 5  // every iterations covers 16 byte of data
		l1:
		movq mm0, [arr + esi]
			add esi, 8  // for next index
			movq mm1, [arr + esi]
			paddb mm0, mm1  // add instruction
			movq[crr + edi], mm0
			add esi, 8  // next 8 bytes
			add edi, 8
			loop l1
			emms // destuctor of mmx registers
	}
	for (int i = 0; i < 40; i++)
		sum = sum + crr[i];
	std::cout << "Sum of elements of array is -->" << sum << std::endl;
	return 0;
}