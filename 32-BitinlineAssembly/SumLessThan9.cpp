#include<iostream>
// Create array of 5 elements input from user and find sum of numbers less than 9.
int main()
{
	unsigned int arr[5] = { 2, 2, 3, 4, 10 };
	unsigned int Sum = 0;
	__asm
	{
		lea esi, [arr]  // address of arr
			xor ebx, ebx  // clearing ebx value
			mov ecx, 5  // to control number of iterations
		l1:

		mov eax, [esi]  // first number in an array 
			cmp eax, 9
			ja  No_Sum
			add ebx, [esi]
		No_Sum :
			   add esi, 4
			   loop l1

			   mov[Sum], ebx
	}

	std::cout << "Sum is -->" << Sum << std::endl;
	return 0;
}