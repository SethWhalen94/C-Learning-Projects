#include <iostream>
#include <string>
#include <cstdlib>

struct Numbers
{
	int num1;
	int num2;
	char op;


};


Numbers user_int()
{
	Numbers numbers;

	std::cout << "Please enter a number: ";
	std::cin >> numbers.num1;
	std::cout << " \n Enter another number: ";
	std::cin >> numbers.num2;

	std::cout << "Enter an operation: +, -, *, /, or % : ";
	std::cin>> numbers.op;

	return numbers;

}

void print_operation(Numbers data)
{

	std::cout << data.num1 << " " << data.op << " " << data.num2 << " = " << data.num1 + data.num2;

}
void compute(Numbers data)
{

	switch (data.op)
	{
	case '+':
		print_operation(data);
		break;

	case '-':
		print_operation(data);
		break;

	case '*':
		print_operation(data);
		break;

	case '/':
		print_operation(data);
		break;

	case '%':
		print_operation(data);
		break;

	default:
		std::cout << "An error occured \n \n";
		break;

	}


}



int main()
{
	
	compute(user_int());


	return 0;
}