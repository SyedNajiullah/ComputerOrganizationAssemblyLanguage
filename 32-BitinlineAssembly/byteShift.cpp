#include<iostream>
//PROGRAM THAT SHIFTS LEFT BYTE 0 AND BYTE NUMBER 3 OF EACH ELEMENT OF AN ARRAY
//AND SHIFTS RIGHT BYTE NUMBER 1 AND BYTE NUMBER 2
int main()
{
	unsigned arr[5] = { 12345, 21345, 32145, 43215, 54321 };
	std::cout << "---BEFORE ARRAY WAS---" << std::endl;
	for (int i = 0; i < 5; ++i)
		std::cout << i << ". " << arr[i] << std::endl;
	__asm
	{
		lea esi, [arr] // Address of arr to esi
			mov ecx, 5  // Size of array
		l1:
			mov al, [esi]  // byte number 0
			shl al, 1 // shifting left 
			mov [esi], al  //Storing 
			mov bl, [esi + 1] // byte number 1
			shr bl, 1 // shifting right 
			mov [esi + 1], bl  //Storing 
			mov dl, [esi + 2] // byte number 2
			shr dl, 1 // shifting right 
			mov [esi + 2], dl  //Storing 
			mov dh, [esi + 3] // byte number 3
			shl dh, 1 // shifting left 
			mov [esi + 3], dh  //Storing 

			add esi, 4  // For next index as every element is of 4 bytes
			loop l1
	}
	std::cout << "---AFTER ARRAY IS---" << std::endl;
	for (int i = 0; i < 5; ++i)
		std::cout << i << ". " << arr[i] << std::endl;
	return 0;
}

//THE TASK CAN ALSO BE ACHIVED BT BIT MASKING BUT USING 1 BYTE REGISTERS IS AN EASIER APPROACH