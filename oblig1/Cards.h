#ifndef Cards
#define Cards


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


class Kort{

	int rank;
	int suit;
	bool pick;
public:


	Kort();
	Kort(int r, int s);

	int getRank();

	void setPicked(bool b);
	bool getPicked();

	int getValueOf(); // tallverdi av kort
	void getDisplay();
	void getDisplayHand(std::vector<Kort> k);
	void shuffle();
	void setRank(int i);

};
 

#endif