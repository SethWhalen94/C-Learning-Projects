#include<iostream>
#include<array>

int main()
{
	std::array<float, 5> array1 = { 1.1f, 2.1f, 3.1f, 4.1f, 5.1f };
	int array2[5] = { 1,2,3,4,5 };
	const int size1 = std::size(array1);
	const int size2 = std::size(array2);

	for (int i = 0; i < size1; ++i)
		std::cout << array1[i] << " ";

	std::cout << " \n \n \n";

	for (float i = 0; i < size1; ++i)
		std::cout << array1[i] << " ";

	std::cout << " \n \n \n";

	for (int i = 0; i < size1; ++i)
		std::cout << array2[i] << " ";

	std::cout << " \n \n \n";

	for (int i = 0; i < size1; ++i)
		std::cout << array2[i] << " ";


}