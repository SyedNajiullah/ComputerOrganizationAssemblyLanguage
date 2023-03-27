#include<iostream>

int main(void)
{
	unsigned char arr[8] = { 2, 1, 3, 4, 1, 6, 7, 6 };
	unsigned char result[8] = { 0 };
	unsigned char arrayOfZeros[8] = { 0 };
	unsigned char arrayOfOnes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
	unsigned int sum = 0;
	_asm
	{
		xor esi, esi
			mov ecx, 10
		l1:
			movq mm0, [arr + esi]  //  8 elements
			movq mm1, [arrayOfOnes + esi] // array having all ones
			movq mm2, [arrayOfZeros + esi] // array having all ones
			pand mm1, mm0 // OOD numbers will have 1 stored in mm1 register
			pcmpeqb mm2, mm1  // EVEN numbers will have 0xFF stored in mm2 registers
			pand mm2, mm0 // 0xFF will be replaced with EVEN numbers from arr
			movq[result], mm2 // Result will be stored in result array 
			loop l1
			emms

	}
	for (int i = 0; i < 8; i++)
		sum = sum + result[i];  //Linear sum
	std::cout << "-----------------" << std::endl;
	std::cout << " EVEN SUM IS : " << sum << std::endl;
	std::cout << "-----------------" << std::endl;
	return 0;
}