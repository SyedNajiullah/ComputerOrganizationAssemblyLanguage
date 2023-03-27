#include<iostream>

int main(void)
{
	unsigned char arr[8] = { 2, 1, 3, 4, 1, 6, 7, 8 };
	unsigned char arrayOfOnes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
	unsigned char arrayOfZeros[8] = { 0 };
	unsigned int sum = 0;
	_asm
	{
		xor esi, esi
			mov ecx, 10
		label:
			movq mm0, [arr + esi]  // first 8 elements
			movq mm1, [arrayOfOnes + esi] // array having all ones
			movq mm2, [arrayOfOnes + esi] // array having all ones
			movq mm3, [arrayOfZeros + esi] // array having all zeros 
			pand mm1, mm0 // ODD numbers will have 1 stored in mm1 register
			pcmpeqb mm2, mm1  // ODD numbers will have 0xFF stored in mm2 registers
			pand mm2, mm0 // 0xFF will be replaced with odd numbers from arr
			movq[arrayOfZeros], mm2 // Result will be stored in arrayOfZeros 
			loop label
			emms

	}
	for (int i = 0; i < 8; i++) 
		sum = sum + arrayOfZeros[i];  //Linear sum
	std::cout << "----------------" << std::endl;
	std::cout << " OOD SUM IS : " << sum << std::endl;
	std::cout << "----------------" << std::endl;
	return 0;
}