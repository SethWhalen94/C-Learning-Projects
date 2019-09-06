#include <iostream>
#include <iterator>
#include <stdio.h>
#include <string>


void printArray(int [], int);

int user_input()
{
	int num;
	do
	{
		std::cout << "Please enter an integer between 1 and 9: ";
		
		std::cin >> num;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');

		}
	} while (num < 1 || num > 9);
	return num;
}



int main()
{
	int arr[] = {4,6,7,3,8,2,1,9,5};
	int key{ user_input() };
	const int size = std::size(arr);
	printArray(arr, size);
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			std::cout << "the array element index is: " << i;
			break;
		}

	}

	std::cout << '\n';

	return 0;

}

void printArray(int arr[], int size)
{

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << '\n';

}
