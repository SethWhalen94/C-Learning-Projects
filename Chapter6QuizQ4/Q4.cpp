#include <iostream>
#include<cstring>

void printString(const char* str)	//function that takes the pointer to the beginning of a C-style string
{									//const char* makes it so we cannot change the value at the memory location being pointed at

	while (*str != '\0')			//check to see if pointer is pointing at NULL character
	{
		std::cout << *str;
		++str;						//Increment memory address of pointer to next character
	}
}


int main()
{
	printString("Hello, World!");

	return 0;

}