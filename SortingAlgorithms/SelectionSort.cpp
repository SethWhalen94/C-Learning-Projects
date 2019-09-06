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


int main()
{

	int arr[100];

	srand((unsigned)time(0));

	for (int i = 0; i < 100; i++) {
		arr[i] = (rand() % 100) + 1;

	}

	const int size = std::size(arr);
	printArray(arr, size);
	std::cout << '\n' << '\n';

	for (int i = 0; i < size; i++)
	{
	
		
		for (int j = i + 1; j < size ; j++)
			if (arr[j] < arr[i])
			{
				std::swap(arr[i], arr[j]); //swap elements
			}

	}

	printArray(arr, size);
	
	return 0;
}