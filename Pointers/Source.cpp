#include <iostream>
#include <stdio.h>

struct Something
{
	int nX, nY, nZ;
};
Something* somethingPtr; // Something is probably 12 bytes

int main()
{
	char* chPtr; // chars are 1 byte
	int* iPtr; // ints are usually 4 bytes


	std::cout << sizeof(chPtr) << '\n'; // prints 4
	std::cout << sizeof(iPtr) << '\n'; // prints 4
	std::cout << sizeof(somethingPtr) << '\n'; // prints 4

	return 0;
}