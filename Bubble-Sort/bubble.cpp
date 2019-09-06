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
	int x{ 0 };

	int arr[100];

	srand((unsigned)time(0));

	for (int i = 0; i < 100; i++) {
		arr[i] = (rand() % 100) + 1;

	}

	const int size = std::size(arr);
	bool t (true);
	printArray(arr, size);

	std::cout << '\n' << '\n';
	for(int i = size; i > 0 ; i--)
	{
		for (int current_index = 0; current_index < i -1 ; current_index++)
		{
			if (arr[current_index] > arr[current_index + 1])
			{
				std::swap(arr[current_index], arr[current_index + 1]);
				t = false;
			}

		}
		if (t)
			break;
		else
			t = true;

	}
	printArray(arr, size);

	return 0;
}