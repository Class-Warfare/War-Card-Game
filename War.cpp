/*
Author: Class Warfare
Course: COMP 220, Computer Programming II
Date: 09/25/14
Description: The War class definitions.
*/

#include "War.h"
#include "Card.h"

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
	cout << "Welcome to the card game War. This is a one or two player game." << endl;
	cout << "Press Enter to take your turn, or input a letter to skip to the end." << endl << endl;
}

void War::getNames()
{
	cout << "Enter the name of player 1: ";
	getline(cin, nameP1);
	cout << endl << "Enter the name of player 2: ";
	getline(cin, nameP2);
	cout << endl;
}

void War::battle()
{
	Card p1Card = player1.drawTop();
	Card p2Card = player2.drawTop();
	
	cout << nameP1 << ": " << p1Card.name() << endl
		<< nameP2 << ": " << p2Card.name() << endl;
	
	int winner = 0;
	if (p1Card.getValue() == p2Card.getValue())
	{
		winner = war();
	}
	else if (p1Card.getValue() > p2Card.getValue()) winner = 1;
	else if (p2Card.getValue() > p1Card.getValue()) winner = 2;
	
	//Give the spoils to the winner
	if (winner == 1)
	{
		player1.placeBottom(p1Card);
		player1.placeBottom(p2Card);
		
		cout << nameP1;
	}
	else if (winner == 2)
	{
		player2.placeBottom(p1Card);
		player2.placeBottom(p2Card);
		
		cout << nameP2;
	}
	cout << " won this round." << endl;
}

int War::war()
{
	Hand warPile;
	Card p1Card, p2Card;
	int winner = 0;
	//If a player is out of cards, then the other player wins
	if (player1.empty())
	{
		winner = 2;
	}
	else if (player2.empty())
	{
		winner = 1;
	}
	else
	{
		do
		{
			cout << "WAR!!" << endl;
			
			//Put down three extra cards for each player
			for (int i = 0; i < 3; i++)
			{
				//Save one card for the comparison
				if (player1.size() > 1) warPile.placeBottom(player1.drawTop());
				if (player2.size() > 1) warPile.placeBottom(player2.drawTop());
			}
			
			//We'll compare the next two cards
			p1Card = player1.drawTop();
			p2Card = player2.drawTop();
			
			cout << nameP1 << ": " << p1Card.name() << endl
				<< nameP2 << ": " << p2Card.name() << endl;
		} while (p1Card.getValue() == p2Card.getValue());
		
		//Give the spoils to the winner
		if (p1Card.getValue() > p2Card.getValue())
		{
			for (int i = 0; i < warPile.size(); i++)
				player1.placeBottom(warPile.drawTop());
			player1.placeBottom(p1Card);
			player1.placeBottom(p2Card);
			
			winner = 1;
		}
		else if (p2Card.getValue() > p1Card.getValue())
		{
			for (int i = 0; i < warPile.size(); i++)
				player2.placeBottom(warPile.drawTop());
			player2.placeBottom(p1Card);
			player2.placeBottom(p2Card);
			
			winner = 2;
		}
	}
		
	return winner;
}

void War::winner()
{
	cout << "Congratulations, ";

	if (player1.empty())
	{
		cout << nameP2;
	}
	else //If player2.empty()
	{
		cout << nameP1;
	}

	cout << ", you have won the war!" << endl;
}

bool War::playAgain()
{
	char ans;
	cout << "Do you want to play again (y/n)?: ";
	cin >> ans;
	cin.sync();
	
	return (ans == 'Y' || ans == 'y');
}