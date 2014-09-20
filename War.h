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

class War
{
public:
	void play();
	//Plays a game of war. Asks the user to press enter for each time,\
	or to press -1 to zip through the rest of the game.
private:
	void introduction();
	//Prints out an introduction/instructions to the user
	void getNames();
	//Gets names for the two players
	void battle();
	//Makes a comparison of one card from each player
	void war();
	//Puts 2/3 cards "facedown" and compares the next card from each player
	void winner();
	//Prints out a congratulatory message for the winner
};

#endif
