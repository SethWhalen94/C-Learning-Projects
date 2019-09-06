#include <iostream>
#include <stdio.h>



void print_array(int* ptr)
{
	
	std::cout << ptr[0] << '\n';
	std::cout << *ptr << '\n';

	*ptr = 0;
	std::cout << ptr[0] << '\n';
	ptr[0] = 1;
	std::cout << ptr[0] << '\n';

}


int main()
{
	int array[] = { 9, 7, 5, 3, 1 };
	const int size = std::size(array);

	//std::cout << *array << '\n';			// Dereference the array pointer, points to the first element

	//char name[] = "Seth";					// Charater array

	//std::cout << *name;					//Dereference pointer to first character


	const int arrayLength = 7;
	char name[arrayLength] = "Seth";
	int numVowels(0);
	for (char* ptr = name; ptr < name + arrayLength; ++ptr)
	{
		switch (*ptr)
		{
		case 'A':
		case 'a':
		case 'E':
		case 'e':
		case 'I':
		case 'i':
		case 'O':
		case 'o':
		case 'U':
		case 'u':
			++numVowels;
		}
	}

	std::cout << name << " has " << numVowels << " vowels.\n";

	return 0;
	

}