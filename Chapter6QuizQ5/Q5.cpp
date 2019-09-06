#include <iostream>
#include<array>
#include<random>
#include<ctime>
#include "Q5-Functions.h"


int main()
{

	std::array<Card, 52> deck;						 //declare deck of cards array with type Card

	using index_t = std::array<Card, 52>::size_type; //create a type called 'index_t' which is the size type of the array 'deck'
	index_t card = 0;								// change index of deck array to the size of Struct memory space, call it 'card'

	std::array<Card, 52>::size_type card2 = 0;

	//std::cout << sizeof(index_t) << '\n';

	for(int suit = 0; suit < MAX_SUITS; suit++)
		for (int rank = 0; rank < MAX_RANK; rank++)
		{

			deck[card2].suit = static_cast<CardSuit>(suit);
			deck[card2].rank = static_cast<CardRank>(rank);
			++card2;

		}

	//printDeck(deck);
	shuffleDeck(deck);
	std::cout << '\n';
	printDeck(deck);
	std::cout << &deck << '\n';
	bool result = playBlackjack(deck);

	if (result)
		std::cout << "You Won!";
	else
		std::cout << "You Lost";


	return 0;

}

void shuffleDeck(std::array<Card, 52> & deck)
{

	std::mt19937 mersenne(static_cast<std::mt19937::result_type>(std::time(nullptr)));	//
	std::uniform_int_distribution<> shuffle(0, 51);										//

	using index_t = std::array<Card, 52>::size_type; //create a type called 'index_t' which is the size type of the array 'deck'
	index_t card = 0;								// change index of deck array to the size of Struct memory space, call it 'card'

	for (card = 0; card < 52; card++)
	{
		swapCard(deck[card], deck[shuffle(mersenne)]);

	}


}

/*Function to print a Card as "RankSuit"*/
void printCard(const Card &card)
{
	switch (card.rank)
	{
	case(ACE):		std::cout << 'A'; break;
	case(TWO):		std::cout << '2'; break;
	case(THREE):	std::cout << '3'; break;
	case(FOUR):		std::cout << '4'; break;
	case(FIVE):		std::cout << '5'; break;
	case(SIX):		std::cout << '6'; break;
	case(SEVEN):	std::cout << '7'; break;
	case(EIGHT):	std::cout << '8'; break;
	case(NINE):		std::cout << '9'; break;
	case(TEN):		std::cout << 'T'; break;
	case(JACK):		std::cout << 'J'; break;
	case(QUEEN):	std::cout << 'Q'; break;
	case(KING):		std::cout << 'K'; break;
	default:		std::cout << "!!!!!!!! THIS IS AN ERROR !!!!!"; break;
	}

	switch (card.suit)
	{
	case(CLUBS):		std::cout << 'C'; break;
	case(DIAMONDS):		std::cout << 'D'; break;
	case(HEARTS):		std::cout << 'H'; break;
	case(SPADES):		std::cout << 'S'; break;
	default:			std::cout << "!!!!!!!! THIS IS AN ERROR !!!!!"; break;
	}
}

void printDeck(const std::array<Card, 52> &deck)
{
	for (const auto& card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}

	std::cout << '\n';
}


void swapCard(Card& card1, Card& card2)
{
	Card temp = card1;
	card1 = card2;
	card2 = temp;

}

/*returns the vale of a card*/
int getCardValue(const Card &card)
{
	switch (card.rank)
	{
	case(ACE):		return 11;
	case(TWO):		return 2;
	case(THREE):	return 3;
	case(FOUR):		return 4;
	case(FIVE):		return 5;
	case(SIX):		return 6;
	case(SEVEN):	return 7;
	case(EIGHT):	return 8;
	case(NINE):		return 9;
	default:		return 10;
	}

	return 0;
}

bool playBlackjack(std::array<Card, 52> deck)
{

	 Card *cardPtr = &deck[0];

	 int user{ 0 };
	 int dealer{ 0 };
	 char choice{ 0 };

	 dealer += getCardValue(*cardPtr++);
	 //cardPtr++;
	 user = getCardValue(*cardPtr++);
	 user += getCardValue(*cardPtr++);	//Give player the second and third cards of the deck
	 //cardPtr++;
	 std::cout << "The dealer is showing: " << dealer << '\n';
	 while (choice != 's' && user < 21)
	 {
		 std::cout << "Your current score is " << user << '\n';
		 std::cout << "Hit or Stay? (Enter h or s): ";
		 std::cin >> choice;
		 while (choice != 'h' && choice != 's')
		 {
			 std::cout << "Please enter either 'h' or 's'" << '\n';
			 std::cin >> choice;
		 }
		 std::cout << '\n';
		 if (choice == 'h')
		 {
			 user += getCardValue(*cardPtr);
			 cardPtr++;
			 std::cout << "Your score is now " << user << '\n';
		 }
		 else if (choice != 's')
			 std::cin.ignore(32767, '\n');		//Clear cin
	 }

	 if (user > 21)
		return false;
	 else
	 {
		 dealer += getCardValue(*cardPtr);
		 cardPtr++;
		 /*Loop to check if dealer has a score less than 17 and less than 21*/
		 while (dealer < 17 && dealer < 21)
		 {
			 if (dealer > user)				//Check if Dealer has beaten the User
				 break;
			 dealer += getCardValue(*cardPtr);
			 cardPtr++;
		 }
		 std::cout << "Your score: " << user << "  Dealer score: " << dealer << '\n';

		 /*Check who won the game*/
		 if (user > 21)
			 return false;

		 else if (user < dealer && dealer <= 21)
			 return false;

		 else
			 return true;
	 }
}