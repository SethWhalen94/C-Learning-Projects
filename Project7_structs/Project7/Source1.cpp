#include <iostream>

//define fraction struct
struct fraction {

	int numerator;
	int denominator;
};

//user inputs fraction values
fraction user_fraction()
{

	fraction frac;

	std::cout << "Please enter the numerator: ";
	std::cin >> frac.numerator;
	std::cout << "\n Please enter the denominator: ";
	std::cin >> frac.denominator;

	return frac;

}

//fractions are multiplied and float value is returned
void multiply_fractions(fraction frac1, fraction frac2)
{
	std::cout << static_cast<float>(frac1.numerator*frac2.numerator) / (frac1.denominator*frac2.denominator) << '\n';
	

}

void print_fraction(fraction frac)
{
	std::cout << frac.numerator << "/" << frac.denominator;


}

int main()
{
	fraction user_frac1 = user_fraction();
	fraction user_frac2 = user_fraction();

	print_fraction(user_frac1);
	std::cout << " * ";
	print_fraction(user_frac2);
	std::cout << " = ";
	multiply_fractions(user_frac1, user_frac2);

	return 0;
}