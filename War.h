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
	//Plays a game of war. Asks the user to press enter for each time,
	// or enter a letter to zip through the rest of the game. Nobody wins
	// if a game continues for more than MAX_ROUNDS (presumed to be an infinite game).
private:
	War();
	//Default constructor
	static void introduction();
	//Prints out an introduction and tells the user how to play.
	static void getNames();
	//Gets names for the two players from the user and stores them in nameP1 and nameP2.
	static void battle();
	//Precondition: Each player has at least one card in his hand.
	//Postcondition: A comparison is made between the players' first cards. If the cards
	// have the same value, a war is declared.
	static int war();
	//Puts 3 cards "facedown" for each player and compares the next card from each player.
	// Returns 1 if player one is the winner and 2 if player two is the winner.
	static void winner();
	//Precondition: One of the players has run out of cards or rounds is greater than MAX_ROUNDS.
	//Postcondition: Prints out a congratulatory message for the winner.
	static bool playAgain();
	//Asks the user if he wants to play again. Returns true if the user wants to play again.
	static void checkForSkip();
	//Precondition: New information has been displayed for the user to see.
	//Postcondition: Changes skipToEnd to reflect whether the user wants to skip to the end
	// of the game or just move to the next stage.
	static string nameP1, nameP2;
	static Hand player1, player2;
	static bool skipToEnd;
	static int rounds;
	static const int MAX_ROUNDS;
};

#endif