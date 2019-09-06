#include <iostream>
#include <iterator>

namespace Animals
{
	enum Animals
	{
		chicken, //0
		dog,	 //1
		cat,	 //2
		elephant,//3
		duck,	 //4
		snake,	 //5
		MAX_ANIMALS // 6

	};
}


int main()
{
	int animal_arr[Animals::MAX_ANIMALS] = {2, 4, 4, 4, 2, 0};

	std::cout << "An Elephant has " << animal_arr[Animals::elephant] << " legs \n";

	return 0;


}