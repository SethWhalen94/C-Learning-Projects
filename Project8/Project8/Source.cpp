#include <iostream>
#include <string>

//Monster Type enumerator class
enum class Monst_type
{
	OGRE,
	DRAGON,
	ORC,
	GIANT_SPIDER,
	SLIME


};
struct Monster
{
	 Monst_type type;
	 std::string name;
	int health{ 0 };

};

//gets enum type name and returns a string of the name
std::string get_name(Monster monster)
{
	if (monster.type == Monst_type::OGRE)
		return "Ogre ";
	else if (monster.type == Monst_type::DRAGON)
		return "Dragon ";
	else if (monster.type == Monst_type::ORC)
		return "Orc ";
	else if (monster.type == Monst_type::GIANT_SPIDER)
		return "Giant Spider ";
	else if (monster.type == Monst_type::SLIME)
		return "Slime ";
	else
		 return "Random ";


}

//Prints out the contents of the 'Monster' struct
void printMonster(Monster new_monster)
{
	std::cout << "This " <<get_name(new_monster) << "is named " << new_monster.name << " and has " << new_monster.health << " health. \n \n";


}

int main()
{
	//Instantiating some monsters
	Monster torg = { Monst_type::OGRE, "Torg", 100 };
	Monster blurp = { Monst_type::SLIME, "Blurp", 50 };

	printMonster(torg);
	printMonster(blurp);

	return 0;
}