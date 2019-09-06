#include <iostream>

struct Student				//Student structure
{
	std::string name;		//std::string because name is more than 1 character
	int grade{ 0 };
};

int numStudents()
{
	std::cout << "How many students do you wish to enter: ";
	int length{ 0 };
	std::cin >> length;
	std::cin.ignore(32767, '\n');
	return length;
}

//Function to sort students from highest to lowest grade
void sortNames(Student* students, int size)
{

	for (int i = 0; i < size; ++i)
	{

		for (int j = i + 1; j < size; ++j)
		{
			if (students[j].grade > students[i].grade)
				std::swap(students[i], students[j]);
		}

	}

}

int main()
{
	const int size = numStudents();			//Get number of students from user
	Student* students = new Student[size];	//Dynamicallly allocate array of Student structs
																	
	for (int i = 0; i < size; ++i)			//For loop gets the user to input each student's name and grade
	{
		std::cout << "Please enter student #" << i+1 << "'s name:";
		std::cin >> students[i].name;
		std::cout << '\n';
		std::cin.ignore(32767, '\n');
		std::cout << "Please enter " << students[i].name << "'s grade:";
		std::cin >> students[i].grade;
		std::cout << '\n';
		std::cin.ignore(32767, '\n');
	}

	sortNames(students, size);

	for (int i = 0; i < size; ++i)	//For loop prints out sorted array of names and grades
	{
		std::cout << students[i].name << " got a score of " << students[i].grade;
		std::cout << '\n';

	}

	delete[] students;	//deallocate memory
}