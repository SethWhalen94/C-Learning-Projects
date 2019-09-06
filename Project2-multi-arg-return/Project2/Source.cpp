#include <iostream>
#include <tuple>
#include <string>

std::tuple<int, int> user_input()
{
	int x{ 0 };
	int y{ 0 };
	std::cout << "Enter an integer: ";
	std::cin >> x;
	std::cout << '\n' << "Enter a larger integer: ";
	std::cin >> y;
	std::cout << '\n';

	return std::make_tuple(x, y);


}

int main()
{
	int x, y = 0;
	std::tie(x, y) = user_input();

	if (x > y)
	{
		int temp = x;
		std::cout << "Swapping values \n";
		x = y;
		y = temp;

	}



std::cout << "The smaller value is " << x << "\n The larger value is  " << y << '\n';

return 0;
}

