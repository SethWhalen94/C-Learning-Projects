#include <iostream>
#include <iterator> // for std::size
#include <cstdlib> 
#include <ctime>
#include <algorithm>
void printArray(int arr[], int size)
{

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << '\n';

}


int user_input()
{
	int length;
	std::cout << "How many names would you like to enter? ";
	std::cin >> length;

	return length;

}

int main()
{

	int length = user

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