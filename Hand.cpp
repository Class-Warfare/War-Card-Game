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
	srand(time(0) + size());
	//Select a new random location for each card
	for (int i = 0; i < size(); i++)
	{
		int newIndex = rand()%size();
		cards.insert(cards.begin() + newIndex, cards.at(i));
		cards.erase(cards.begin() + i);
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
	//Insert the card at the beginning of the deck
	cards.insert(cards.begin(), c);
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