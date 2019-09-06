#include <iostream>
#include <stdio.h>
#include <string>

enum class ItemType
{
	TORCH,
	SWORD,
	SHOVEL,
	HANDS
};

std::string getItemName(ItemType);


int main()
{
	ItemType  item = ItemType::SWORD;
	

	
	 std::cout << "You have equipped... " << getItemName(item) << "! \n";
	

	return 0;

}

std::string getItemName(ItemType item)
{
	if (item == ItemType::TORCH)
		return std::string("Torch");
	if (item == ItemType::SWORD)
		return std::string("Sword");
	if (item == ItemType::SHOVEL)
		return std::string("Shovel");
	if (item == ItemType::HANDS)
		return std::string("Hands");

	return std::string("???");

}