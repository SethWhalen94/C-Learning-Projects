#include <iostream>
#include<functional>
#include <array>

int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);

/* Define a global funcion pointer called 'arithmeticFcn' */
typedef int (*arithmeticFcn)(int, int);

/* Structure that defines a operation and a function pointer */
struct  arithmeticStruc
{

	char op;
	arithmeticFcn fcn;

};

/* Global arithmetic structure array */
static const arithmeticStruc arithmeticArray[] = {
	{'+', add},
	{'-', subtract},
	{'*', multiply},
	{'/', divide}
};

int getInteger()
{
	int x;

	do {
		std::cout << "Enter an integer: ";
		std::cin >> x;
		std::cout << '\n';
	} while (!x);

	return x;
}

char getOperation()
{
	char op;

	do {
		std::cout << "Enter an operation (+, -, *, /): ";
		std::cin >> op;
		std::cout << '\n';

	} while (op != '+' && op != '-' && op != '*' && op != '/');

	return op;

}

int add(int a, int b)
{
	return a + b;
}

int subtract(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}

int divide(int a, int b)
{
	return a / b;
}

arithmeticFcn getArithmeticFunction(char op)
{
	for (const auto& arith : arithmeticArray) //Loop through global arithmetic structure array and compare operations
	{
		if (arith.op == op)
			return arith.fcn;

	}

	return add;				//default function to return
}

int main()
{
	int x{ getInteger() };
	int y{ getInteger() };
	char op{ getOperation() };

	arithmeticFcn fcnPtr =  getArithmeticFunction(op);

	arithmeticStruc stuff = { '+', add };

	std::cout << x << op << y << " = " << fcnPtr(x,y) << '\n';

	return 0;
}