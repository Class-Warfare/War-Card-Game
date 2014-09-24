/*
Author: Class Warfare
Course: COMP 220, Computer Programming II
Date: 09/25/14
Description: The Hand class definitions.
*/

#include "Hand.h"
#include <ctime>
#include <cstdlib>



Hand::Hand()
{
}

Hand Hand::fullDeck()
{
	//Create a Hand with a full deck of cards
	Hand deck;

	const int NUM_SUITS = 4;
	const int NUM_FACES = 13;
	Suit suit[NUM_SUITS] = {clubs, diamonds, hearts, spades};
	Value face[NUM_FACES] = {ace, deuce, trey, four, five, six, seven, eight, nine, ten, jack, queen, king};

	for (int i = 0; i < NUM_SUITS; i++)
	{
		for (int j = 0; j < NUM_FACES; j++)
		{
			deck.placeBottom(Card(face[j], suit[i]));
		}
	}

	return deck;
}

void Hand::shuffle()
{
	srand(time(NULL));
	int counter = 0;
	while (counter < 1000)
	{
		int card1 = rand() % cards.size();
		int card2 = rand() % cards.size();
		if (card1 != card2)
		{
			Card c = cards[card1];
			cards[card1] = cards[card2];
			cards[card2] = c;
		}

		counter++;
	}
}


Card Hand::drawTop()
{
	Card drawnCard=cards.at(0);
	cards.erase(cards.begin());
	return drawnCard;
}

Card Hand::drawBottom()
{
	//Remove and return the last card
	Card card = cards.back();
	cards.erase(cards.end());
	return card;
}

void Hand::placeTop(Card c)
{
<<<<<<< HEAD
	//Insert the card at the beginning of the deck
	cards.insert(cards.begin(), c);
=======
    //Insert the card at the beginning of the deck
	cards.insert(cards.begin(), card);
>>>>>>> origin/master
}

void Hand::placeBottom(Card c)
{
	cards.push_back(c);
}

bool Hand::empty()
{
	return cards.empty();
}

int Hand::size()
{
	return cards.size();
}