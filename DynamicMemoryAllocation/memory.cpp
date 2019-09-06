#include <iostream>
#include <iterator> // for std::size
#include <cstdlib> 
#include <ctime>
#include <algorithm>
#include <string>
void printArray(std::string arr[], int size)
{
	std::cout << "Here is your sorted list:" << '\n';
	for (int i = 0; i < size; i++)
	{

		std::cout << "Name #" << i+1 << ": " << arr[i] << '\n';
	}
	std::cout << '\n';

}

int user_input()
{
	int length;

	std::cout << "How many names would you like to enter? ";
	std::cin >> length;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');

	}
	else
	{
		std::cin.ignore(32767, '\n');
		return length;
	}
}

int main()
{

	int size = user_input();

	std::string *arr = new std::string[size]; // Dynamically allocate memory for char array

	for (int i = 0; i < size; i++)
	{

		std::cout << "Enter name #" << i+1 << ": ";
		std::getline(std::cin, arr[i]);
		std::cin.ignore(32767, '\n'); // ignore up to 32767 characters until a \n is removed


	}

	for (int i = 0; i < size; i++)
	{

		for (int j = i + 1; j < size; j++)
			if (arr[j] < arr[i])
			{
				std::swap(arr[i], arr[j]); //swap elements
			}

	}

	printArray(arr, size);

	return 0;
}