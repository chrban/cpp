#ifndef Player
#define Player

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <thread>      
#include <chrono>      

#include "Cards.h"

class Spiller{

		int bet;
		int player_nr;
		int credit;
		int value; 		
		bool active;
		bool busted;
		
	public:
		Spiller( int pn, int c );
		void addCard(Kort k); 
		int getCard();   
		int getValue();
		std::vector<Kort> hand;
		std::vector<Kort> getHand();
		int getCredit();
		void setCredit(int i);
		int getPlayerNr();
		void initPlayers();
		void displayHand();
		void setBet(int i);
		int getBet();
		void setActive(bool b);
		bool getActive();
		void setBusted(bool b);
		bool getBusted();
		void emptyHand();


};

#endif