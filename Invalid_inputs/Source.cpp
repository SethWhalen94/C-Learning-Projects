#include <iostream>
#include <cstdio>
#include <cstdlib>


double getDouble()
{

	while (true)
	{
		double input;
		std::cout << "please enter a double value: ";
		std::cin >> input;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');

		}
		else
		{
			std::cin.ignore(32767, '\n');
			return input;
		}
	}


}
char getOperator()
{
	while (true) // Loop until user enters a valid input
	{
		std::cout << "Enter one of the following: +, -, *, or /: ";
		char op;
		std::cin >> op;
		std::cin.ignore(32767, '\n');  // clear (up to 32767) characters out of the buffer until a '\n' character is removed

		// Check whether the user entered meaningful input
		if (op == '+' || op == '-' || op == '*' || op == '/')
			return op; // return it to the caller
		else // otherwise tell the user what went wrong
			std::cout << "Oops, that input is invalid.  Please try again.\n";
	} // and try again
}

void printResult(double x, double y, char op)
{
	if (op == '+')
	{
		std::cout << x << op << y << " = " << x + y << '\n';

	}
	else if (op == '-')
	{
		std::cout << x << op << y << " = " << x - y << '\n';

	}
	else if (op == '*')
	{
		std::cout << x << op << y << " = " << x * y << '\n';

	}
	else if (op == '/')
	{
		std::cout << x << op << y << " = " << x / y << '\n';

	}
	else
		std::cout << "This message should not print... You have an error in your code \n";


}

void invalidCheck()
{
	std::string hello = "Hello, world!";
	int index;

	do
	{
		std::cout << "Enter an index: ";
		std::cin >> index;

		//handle case where user entered a non-integer
		if (std::cin.fail())
		{
			std::cin.clear(); // reset any error flags
			std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer
			index = -1; // ensure index has an invalid value so the loop doesn't terminate
			continue; // this continue may seem extraneous, but it explicitly signals an intent to terminate this loop iteration
		}

	} while (index < 0 || index >= hello.size()); // handle case where user entered an out of range integer

	std::cout << "Letter #" << index << " is " << hello[index] << std::endl;
}

int main()
{
	double x = getDouble();
	char op = getOperator();
	double y = getDouble();

	printResult(x, y, op);

	return 0;

}