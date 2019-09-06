#include <iostream>
#include "Constants.h"
#include "functions.h"
//void print_result(char, double, double);
//char get_operator();

double user_input()
{
	double x{ 0 };

	std::cout << "Enter a height: "; 
	std::cin >> x;
	std::cout << '\n';

	return x;

}

int user_input_secs()
{
	int x{ 0 };

	std::cout << "Enter a time (in seconds): ";
	std::cin >> x;
	std::cout << '\n';

	return x;

}


int main()
{
	double height{ user_input() };
	int i{ 0 };

	do
	{
		height = calculate_height(height, i);
		i++;

	} while (height > 0.0);

	return 0;
}

double calculate_height(double height, int seconds)
{

	double new_height{ height - constants::my_gravity * (seconds *seconds) / 2 };

	print_height(new_height, seconds);
	
	return new_height;
}

void print_height(double height, int seconds)
{

	if (height >= 0)
	{

		std::cout << "At " << seconds << " seconds the ball is at height " << height << '\n';
	}
	else
	{

		std::cout << "At " << seconds << " seconds the ball is at the ground \n";
	}


}

/*
void print_result(char operation,double x,double y)
{
	if (operation == '+')
	{
		std::cout << x << operation << y << " = " << x + y;
	}

	else if (operation == '-')
	{
		std::cout << x << operation << y << " = " << x - y;
	}

	else if (operation == '*')
	{
		std::cout << x << operation << y << " = " << x * y;
	}

	else
	{
		std::cout << x << operation << y << " = " << x / y;
	}

}

*/

/*
char get_operator()
{
	char op;
	std::cout << "Enter one of the following: +, -, *, / \n";

	std::cout << "Enter choice here: ";
	std::cin >> op;
	return op;
}
*/