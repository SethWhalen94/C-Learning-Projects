#include <iostream>
#include <sstream>
#include <cstdlib>

int main(int argc, char* argv[])
{
	std::cout << "There are " << argc << " arguments:" << std::endl;

	for (int count = 0; count < argc; ++count)
	{
		std::cout << count << ": " << argv[count] << std::endl;

	}

	std::stringstream convert(argv[1]); //sets up stringstream variable called "convert" to extract argv[1] value

	double myint;
	if (!(convert >> myint)) //check if conversion of argv[1] to integer worked
		myint = 0;

	std::cout << "Got integer: " << myint << std::endl;
	std::cout << argv[1];

	return 0;

}