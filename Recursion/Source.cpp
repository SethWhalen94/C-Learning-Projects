#include <iostream>
#include <vector>

void butterfly(int max, int stars=1)
{
	int spaces = (max - stars) * 2; // calculate amount of spaces
	if (stars > max)
		return;

	if (max >= stars)
	{
		for (int i = 0; i < stars; ++i)
			std::cout << '*';

		for (int i = spaces; i > 0; --i)
			std::cout << ' ';

		for (int i = 0; i < stars; ++i)
			std::cout << '*';

		std::cout << std::endl;
		butterfly(max, stars + 1);
	}
	if (max > stars)
	{
		for (int i = 0; i < stars; ++i)
			std::cout << '*';

		for (int i = spaces; i > 0; --i)
			std::cout << ' ';

		for (int i = 0; i < stars; ++i)
			std::cout << '*';

		std::cout << std::endl;
		return;
	}
}


int factorial(int n)
{
	if (n == 1 || n == 0)
		return 1;

	else
	{
		
		return n * factorial(n - 1);
	}

}

int numberSum(unsigned int num)
{
	if (num < 10)
		return num;
	else
		return num%10 + numberSum(num/10);


}

void convertToBinary(unsigned int num)
{
	if (num > 1)
		(convertToBinary(num/2));

	std::cout << num % 2;
	

}

int main()
{
	
	int num{ 0 };
	//std::cout << numberSum(93427);
	std::cout << "Enter an integer (Positive or Negative): ";
	std::cin >> num;
	std::cout << '\n';
	convertToBinary(num);

	return 0;
}