/*

#include <iostream>

//define the structure
struct Advertise
{
	int ads;
	int ads_clicked;
	double revenue_per_click;

};

//function to print advertisement data
void print_advertise(Advertise data)
{
	std::cout << "Number of advertisements: " << data.ads << '\n';
	std::cout << "Number of advertisements clicked: " << data.ads_clicked << '\n';
	std::cout << "Revenue from advertisements: " << data.revenue_per_click << '\n';
	std::cout << "Total Revenue: " << data.ads * data.ads_clicked/100 * data.revenue_per_click << '\n';

}

//takes user input and puts it into a structure, then returns the struct
Advertise ad_input()
{
	Advertise user_ads;

	std::cout << "Enter the # of ads: ";
	std::cin >> user_ads.ads;
	std::cout << '\n';

	std::cout << "Enter the # of ad clicked: ";
	std::cin >> user_ads.ads_clicked;
	std::cout << '\n';

	std::cout << "Enter the revenue per click: ";
	std::cin >> user_ads.revenue_per_click;
	std::cout << '\n';

	return user_ads;


}

int main()
{
	print_advertise(ad_input());

	return 0;
} */