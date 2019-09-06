#include <iostream>
#include <string>
int main()
{

	const std::string names[] = { "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg","Holly" };

	std::cout << "Enter a name: ";
	std::string name;
	std::getline(std::cin, name);
	bool name_found = false;
	for (const auto &element : names)
	{
		if (name == element)
		{
			name_found = true;
			break;
		}
	}

	if (name_found)
		std::cout << '\n' << name << " was found";
	else
	{
		std::cout << '\n' << name << " was not found";
	}

	return 0;

}