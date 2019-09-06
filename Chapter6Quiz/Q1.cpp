#include <iostream>


enum ItemType
{
	HEALTHPOTIONS,
	TORCHES,
	ARROWS,
	MAX_ITEMS

};

int countTotalItems(int *arr)
{
	int totalItems{ 0 };

	for (int i = 0; i < MAX_ITEMS; ++i) 
		totalItems += arr[i];

	return totalItems;
}

int main()
{

	int items[MAX_ITEMS] = { 2, 5, 10 };		//{HEALTHPOTIONS, TORCHES, ARROWS}

	std::cout << "The Player Has " << countTotalItems(items) << " Items in Total.\n";

}