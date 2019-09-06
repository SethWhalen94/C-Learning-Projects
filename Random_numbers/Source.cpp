#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

void random()
{

	std::mt19937 mersenne(static_cast<std::mt19937::result_type>(std::time(nullptr)));

	std::uniform_int_distribution<> die(1, 52);

	for (int count = 1; count < 49; count++)
	{

		std::cout << die(mersenne) << "\t";

		if (count % 6 == 0)
			std::cout << '\n';


	}
}


int main()
{
	/*
	int min = 1;
	int max = 6;
	std::srand(1);
	static const double fraction = 1.0 / (RAND_MAX + 1.0);
	for (int i = 0; i < 10; i++)
	{
		std::cout << ((max - min + 1) * (std::rand() * fraction)) << '\n';
		std::cout << min + static_cast<int> ((max - min + 1) * (std::rand() * fraction)) << '\n';
	} 
	*/

	random();

	return 0;


}