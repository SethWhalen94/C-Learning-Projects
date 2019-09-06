#pragma once
#include<array>

enum CardRank {

	TWO ,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE,
	MAX_RANK
};

enum CardSuit {

	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES,
	MAX_SUITS

};

struct Card
{
	CardRank rank;
	CardSuit suit;

};

/*Funcion Prototypes*/
void printDeck(const std::array<Card, 52> & deck);
void printCard(const Card&);
void shuffleDeck(std::array<Card, 52> & deck);
void swapCard(Card&, Card&);
int getCardValue(const Card&);
bool playBlackjack(std::array<Card, 52>);