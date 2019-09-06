#include <iostream>
#include <stdio.h>

int main()
{

	int value = 5;
	int* ptr = &value; //Initialize pointer with address of 'value' variable

	std::cout << "Address of value is " << &value << '\n';
	std::cout << "pointer points to address " << ptr << '\n';
	std::cout << "value is " << value << '\n';
	std::cout << "De-referenced pointer is " << *ptr << '\n';


	return 0;
}