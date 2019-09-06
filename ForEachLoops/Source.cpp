/*
			SYNTAX
================================
for (element_declaration : array)
	statement;
===============================
*/

#include <iostream>

int main()
{

	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (int num : arr)				 //num will be a copy of the current array element 
		std::cout << num + 1 << ' ';

	for (auto &element : arr)		 //The ampersand makes element a reference to the actual array element, preventing a copy from being made
									 //Use 'const' if you need to make array elements read-only
		std::cout << element + 1 << ' ';

	return 0;

}