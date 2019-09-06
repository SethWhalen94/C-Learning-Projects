#include <iostream>
#include "constants.h"
#include <random>
#include <ctime>
#include <stdio.h>

int random()
{

	std::mt19937 mersenne(static_cast<std::mt19937::result_type>(std::time(nullptr)));

	std::uniform_int_distribution<>numbers(1, 100);

	return numbers(mersenne);
}

int numberGuess(int guesses)
{
	int guess;
	while (true)
	{

		std::cout << "Guess #" << guesses << ": ";
		std::cin >> guess;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');

		}
		else
		{
			std::cin.ignore(32767, '\n');
			return guess;
		}

	}
}

bool numberCheck(int key)
{
	int count{ 1 };

	while (count <=7)
	{
		int guess = numberGuess(count);

		if (guess != key)
		{
			if (guess < key)
				std::cout << "The guess is too low \n";
			else
				std::cout << "The guess is too high \n";
			count++;
		}
		else if (guess == key)
			return 1;
		else
			std::cout << "\n \n \n There is an error in your code \n \n \n";
	}

	return 0;


}

char playAgain()
{

	while (true) // Loop until user enters a valid input
	{
		std::cout << "Would you like to play again ? y/n :";
		char choice;
		std::cin >> choice;
		std::cin.ignore(32767, '\n');  // clear (up to 32767) characters out of the buffer until a '\n' character is removed

		// Check whether the user entered meaningful input
		if (choice == 'y' || choice == 'n')
		{
			std::cout <<"\n \n \n";
			return choice; // return it to the caller
		}
		else // otherwise tell the user what went wrong
		{
			std::cout << "Oops, that input is invalid.  Please try again.\n";

		}
	}// and try again

}
int main()
{
	char choice = NULL;
	int key;
	int result;
	while (choice != 'n')
	{
		key = random();
		std::cout << "Let's play a game.  I'm thinking of a number between 1 and 100.  You have 7 tries to guess what it is. \n \n";
		std::cout << "The number is " << key << '\n';
		result = numberCheck(key);

		if (result == 1)
			std::cout << "Correct! You win! \n";
		else if (result == 0)
			std::cout << "Sorry, you lose.  The correct number was " << key << '\n';
		else
			std::cout << "\n \n \n There is an error in your code \n \n \n";

		choice = playAgain();

		


	}

	std::cout << "Thanks for playing.";
		return 0;
}