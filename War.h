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
	//Makes a comparison of one card from each player
	static void war();
	//Puts 3 cards "facedown" for each player and compares the next card from each player
	static void winner();
	//Prints out a congratulatory message for the winner
	static string nameP1, nameP2;
};

#endif