/*
Author: Class Warfare
Course: COMP 220, Computer Programming II
Date: 09/25/14
Description: The War class definitions.
*/

#include "War.h"

string War::nameP1;
string War::nameP2;
Hand War::deck;
Hand War::player1;
Hand War::player2;

War::War() {/*intentionally empty*/}

void War::play()
{
	introduction();
	
	do
	{
		//Init the deck and player hands
		deck = Hand::fullDeck();
		deck.shuffle();
		player1 = Hand::Hand();
		player2 = Hand::Hand();
		
		//Deal the cards out to the players
		//A full deck has an even number of cards
		while (!deck.empty())
		{
			player1.placeBottom(deck.drawTop());
			player2.placeBottom(deck.drawTop());
		}
		
		//Compare the cards until one player runs out of cards
		while (!player1.empty() && !player2.empty())
		{
			battle();
		}
		
		//Print a message for the winner
		winner();
	} while (playAgain()); //Play again if the user asks
}

void War::introduction()
{
	
}

void War::getNames()
{
	
}

void War::battle()
{
	
}

void War::war()
{
	
}

void War::winner()
{
	
}

bool War::playAgain()
{
	char ans;
	cout << "Do you want to play again (y/n)?: ";
	cin >> ans;
	cin.sync();
	
	return (ans == 'Y' || ans == 'y');
}