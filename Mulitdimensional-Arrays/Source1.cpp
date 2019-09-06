#include <iostream>
#include <stdio.h>
#include <string>


int main()
{
	//declare 10x10 array
	const int rows = { 10 };
	const int cols = { 10 };
	int arr[rows][cols] = { 0 };

	//Calculate multiplication table
	for (int row = 0; row < rows; ++row)
		for (int col = 0; col < cols; ++col)
			arr[row][col] = row * col;

	//Print the table
	for (int row = 1; row < rows; ++row)
	{
		for (int col = 1; col < cols; ++col)
			std::cout << arr[row][col] << '\t';

		std::cout << '\n';
	}

	return 0;

}