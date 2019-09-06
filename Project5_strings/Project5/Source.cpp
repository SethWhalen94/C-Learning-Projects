#include <iostream>
#include <stdio.h>
#include <string>

extern int g_x; // forward declaration for g_x -- g_x can be used beyond this point in this file
const int x{ 10 };
int main()
	{

	std::cout << "Please enter your name: ";
	std::string name;
	std::getline(std::cin, name);

	std::cout << '\n' << "Enter you age: ";
	int age{ 0 };
	std::cin >> age;

	std::cin.ignore(32767, '\n'); // ignore up to 32767 characters until a \n is removed
	float age_math = static_cast<double>(age) / name.length();

	std::cout << "You've lived " << age_math << " years for each letter in your name.\n";

		return 0;
	}