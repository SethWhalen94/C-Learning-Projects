#include <iostream>


int user_input()
{
	int x{ 0 };
	std::cout << "Enter an integer between 0 and 255: ";

	std::cin >> x;
	std::cout << '\n';

	return x;
}


int power(int num, int pow)
{
	if (num >= pow)

	{
			std::cout << "1";
			num = num - pow;
			
	}
	else
	{
		std::cout << "0";

	}

	return num;
	

}
void print_binary(int num)
{

	//check if num has 256 bit
	/*if (num >= 256)
	{
		std::cout << "1 ";
		num = num - 255;
	}
	else
	{
		std::cout << "0 ";

	} */

	//check if num has 128 bit
	if (num < 256 && num >= 128)
	{
		std::cout << "1";
		num = num - 128;
	}
	else
	{
		std::cout << "0";

	}
	//check if num has 64 bit
	if (num < 128 && num >= 64)
	{

		std::cout << "1";
		num = num - 64;
	}
	else
	{
		std::cout << "0";

	}

	//check if num has 32 bit
	if (num < 64 && num >= 32)
	{

		std::cout << "1";
		num = num - 32;
	}
	else
	{
		std::cout << "0";

	}
	//check if num has 16 bit
	if (num < 32 && num >= 16)
	{

		std::cout << "1 ";
		num = num - 16;
	}
	else
	{
		std::cout << "0 ";

	}
	//check if num has 8 bit
	if (num < 16 && num >= 8)
	{

		std::cout << "1";
		num = num - 8;
	}
	else
	{
		std::cout << "0";

	}

	//check if num has 4 bit
	if (num < 8 && num >= 4)
	{

		std::cout << "1";
		num = num - 4;
	}
	else
	{
		std::cout << "0";

	}

	//check if num has 2 bit
	if (num < 4 && num >= 2)
	{

		std::cout << "1";
		num = num - 2;
	}
	else
	{
		std::cout << "0";

	}
	//check if num has 1 bit
	if ( num < 2 && num >= 1)
	{

		std::cout << "1";
		num = num - 1;
	}
	else
	{
		std::cout << "0";

	}

}

int main()

{
	int x{ user_input() };

	x = power(x, 128);
	x = power(x, 64);
	x = power(x, 32);
	x = power(x, 16);
	std::cout << " ";
	x = power(x, 8);
	x = power(x, 4);
	x = power(x, 2);
	x = power(x, 1);

	//print_binary(x);

	return 0;


}