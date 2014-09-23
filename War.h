/*
Author: Class Warfare
Course: COMP 220, Computer Programming II
Date: 09/25/14
Description: The War class header file.
*/

#ifndef __WAR_H_
#define __WAR_H_

#include "Hand.h"
#include <iostream>
#include <string>

using namespace std;

class War
{
public:
	static void play();
	//Plays a game of war. Asks the user to press enter for each time,\
	or to press -1 to zip through the rest of the game.
private:
	War();
	//Default constructor
	static void introduction();
	//Prints out an introduction/instructions to the user
	static void getNames();
	//Gets names for the two players from the user and stores them in nameP1 and nameP2
	static void battle();
	//Precondition: Each player has at least one card in his hand.
	//Postcondition: A comparison is made between the players' first cards. If the cards
	// have the same value, a war is declared.
	static int war();
	//Puts 3 cards "facedown" for each player and compares the next card from each player.
	// Returns 1 if player one is the winner and 2 if player two is the winner.
	static void winner();
	//Prints out a congratulatory message for the winner
	static bool playAgain();
	//Asks the user if he wants to play again. Returns true if the user wants to play again.
	static string nameP1, nameP2;
	static Hand deck, player1, player2;
};

#endif