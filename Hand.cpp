/*
Author: Class Warfare
Course: COMP 220, Computer Programming II
Date: 09/25/14
Description: The Hand class definitions.
*/

#include "Hand.h"
#include <vector>
#include <ctime>
#include <random>



Hand::Hand()
{
}

void Hand::fullDeck()
{
       const int DECK_NUMBER = 52;
       size = DECK_NUMBER;
       const int SUIT_TYPES = 4;
       const int CARD_DENOMINATIONS;
       Suit s = clubs;
       Value v = deuce;
       for (int i = 0; i < SUIT_TYPES; i++)
       {
              switch (i)
              {
                     case 0: s = clubs; break;
                     case 1: s = diamonds; break;
                     case 2: s = hearts; break;
                     case 3: s = spades; break;
              }
              for (int i = 0; i < CARD_DENOMINATIONS; i++)
              {
                     switch (i)
                     {
                           case 0: v = deuce; break;
                           case 1: v = trey; break;
                           case 2: v = four; break;
                           case 3: v = five; break;
                           case 4: v = six; break;
                           case 5: v = seven; break;
                           case 6: v = eight; break;
                           case 7: v = nine; break;
                           case 8: v = ten; break;
                           case 9: v = jack; break;
                           case 10: v = queen; break;
                           case 11: v = king; break;
                           case 12: v = ace; break;
                     }
                     Card c(v,s);
                     Hand.cards.push_back(c);
              }
       }
}
       
void Hand::shuffle()
{
       srand(time(NULL));
       int card1 = rand() % 52;
       int card2 = rand() % 52;
       int counter = 0;
       while (counter < 1000)
       {
              if (card1 != card2)
              {
                     Card c = cards[card1];
                     cards[card1] = cards[card2];
                     cards[card2] = c;
              }
       }
}


Card Hand::drawTop()
{
	Card drawnCard=cards.at(0);
	cards.erase(cards.begin());
	size--;
	return cards.at(0);
}
Card Hand::drawBottom()
{
}
void Hand::placeTop(Card c)
{
       vector <Card> newHand;
       newHand.push_back(c);
       for (int i = 0; i < cards.size(); i++)
              newHand.push_back(cards[i]);
       for (int i = 0; i < cards.size() + 1; i++)
       {
              if (i == cards.size())
                     cards.push_back(newHand[i]);
              cards[i] = newHand[i];
       }
}
       

void Hand::placeBottom(Card c)
{
       cards.push_back(c);
}

bool Hand::empty()
{
       return (size == 0);
}

int Hand::handSize()
{
       return size;
}