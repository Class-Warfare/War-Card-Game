/*
Author: Class Warfare
Course: COMP 220, Computer Programming II
Date: 09/25/14
Description: The Hand class header file.
*/

#ifndef __HAND_H_
#define __HAND_H_

#include "Card.h"

class Hand
{
public:
	void fillDeck();
	//Adds a full deck of cards to the hand
	void shuffle();
	//Mixes up the cards
	Card drawTop();
	Card drawBottom();
	//Returns the card from the top or bottom of the hand, removes that card
	void placeTop(Card);
	void placeBottom(Card);
	//Places the card on the top or bottom of the hand
	bool empty();
	//Returns true if the hand is empty, returns false otherwise
	int size();
	//Returns how many cards are in the hand
};

#endif
