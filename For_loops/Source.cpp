#include <iostream>


int sumTo(int value)
{
	int total;
	for (total = 0; value > 0; --value)
	{
		total += value;


	}

	return total;


}

int user_input()
{
	int num;
	do {
		std::cout << "Please enter an integer: ";
		std::cin >> num;

	} while (isdigit(num));

	std::cout << '\n';
	return num;
}

int main()
{
	std::cout << sumTo((user_input()));

	return 0;
}