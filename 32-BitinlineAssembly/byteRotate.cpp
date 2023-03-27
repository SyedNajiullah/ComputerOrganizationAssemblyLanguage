#include<iostream>
//PROGRAM THAT SWAPS BYTE 0 AND BYTE NUMBER 3 OF EACH ELEMENT OF AN ARRAY
//AND SWAPS BITS IF BYTE 1 AND 2
int main()
{
	unsigned arr[5] = {12345, 21345, 32145, 43215, 54321};
	std::cout << "---BEFORE ARRAY WAS---" << std::endl;
	for (int i = 0; i < 5; ++i)
		std::cout << i << ". " << arr[i] << std::endl;
	__asm
	{
		lea esi, [arr] // Address of arr to esi
		mov ecx, 5  // Size of array
	l1:
		mov al, [esi]  // byte number 0
		mov bl, [esi + 1] // byte number 1
		ror bl, 4   // Shifting nibbles
		mov [esi + 1], bl  // Storing on byte number 1
		mov dl, [esi + 2] // byte number 2
		ror dl, 4  // Shifting nibbles 
		mov [esi + 2], dl  // Storing on byte number 2
		mov dh, [esi + 3] // byte number 3
		mov [esi + 3], al     // Storing byte number 0
		mov [esi], dh   //Storing byte number 3
		add esi, 4  // For next index as every element is of 4 bytes
		loop l1
	}
	std::cout << "---AFTER ARRAY IS---" << std::endl;
	for (int i = 0; i < 5; ++i)
		std::cout << i << ". " << arr[i] << std::endl;
	return 0;
}

//THE TASK CAN ALSO BE ACHIVED BT BIT MASKING BUT USING 1 BYTE REGISTERS IS AN EASIER APPROACH