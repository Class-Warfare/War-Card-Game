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
	//Init the deck and player hands
	deck = Hand::fullDeck();
	player1 = Hand::Hand();
	player2 = Hand::Hand();
	
	introduction();
	
	do
	{
		while (!player1.empty() && !player2.empty())
		{
			battle();
		}
		
		winner();
	} while (playAgain());
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