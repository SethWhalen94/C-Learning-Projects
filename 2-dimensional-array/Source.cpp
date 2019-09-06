#include <iostream>

/*Function that allows you to set an element value in flattened array as if it were a 2-dimesional array*/
int getSingleIndex(int row, int col, int numberOfColumnsInArray)
{
	return (row * numberOfColumnsInArray) + col;
}


int main()
{
	int** array = new int* [10];				//dynamically allocate an array of 10 int pointers - these are the rows
	for (int count = 0; count < 10; ++count)
		array[count] = new int[5];				//these are the columns of our 2-dimensional array

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			array[i][j] = 1;
			std::cout << array[i][j] << ' ';
		}

		std::cout << '\n';
	}

	//std::cout << array[9][4];

	/*Delete the dynamically allocated array*/
	for (int count = 0; count < 10; ++count)
		delete[] array[count];						 //Delete each row (one dimensional arrays)
	delete[] array;									 // this needs to be done last

	/*Flattened 2 dimensional array into 1-dimensional array*/

	int* arrayFlat = new int[50];					 // a 10x5 array flattened into a single array

	
	for (int k = 0; k < 50; ++k)					// Set all elements in flattened array to 0
	{
		arrayFlat[k] = 0;
		std::cout << arrayFlat[k] << ' ';
		if (k%5 == 0 && k!=0)
			std::cout << '\n';
	}

	arrayFlat[getSingleIndex(9, 4, 5)] = 3;			// set array[9,4] to 3 using our flattened array
	arrayFlat[getSingleIndex(0, 0, 5)] = 30;

	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';

	for (int k = 0; k < 50; ++k)					// Set all elements in flattened array to 0
	{
		std::cout << arrayFlat[k] << ' ';
		//if (k % 4 == 0 && k != 0)
			//std::cout << '\n';
	}


	return 0;

}