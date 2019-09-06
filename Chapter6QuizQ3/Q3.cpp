#include <iostream>


void swapValues(int* ptr1, int* ptr2)	//use pointers to change values in main
{
	int val1 = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = val1;
}

void swap(int &a, int &b)				//pass values by reference
{
	int temp = a;
	a = b;
	b = temp;
}


int main()
{
	int x = 5;
	int y = 10;
	int* ptr1 = &x;
	int* ptr2 = &y;

	std::cout << "The value of x is " << x << '\n';
	std::cout << "The value of y is " << y << '\n';

	swap(x, y);
	//swapValues(ptr1, ptr2);
	std::cout << "The value of x is now " << x << '\n';
	std::cout << "The value of y is now " << y << '\n';




}