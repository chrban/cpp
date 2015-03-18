#include "Player.h"


Spiller::Spiller( int pn, int c ) : player_nr{pn}, credit{c} , value{0}, bet{0}, active{true}, busted{false}{}


int Spiller::getPlayerNr(){return player_nr;}
int Spiller::getCredit(){return credit;}

void Spiller::setCredit(int i)
{
	credit += i;
}
void Spiller::addCard(Kort k)
{
	hand.push_back(k);
}

std::vector<Kort> Spiller::getHand()
{
	return hand;
}
void Spiller::displayHand() 
{	
	std::chrono::milliseconds timespan(300);
	
	for(int i = 0; i < hand.size();i++)
	{
		std::this_thread::sleep_for(timespan);
		hand[i].getDisplay();
		std::cout << " " ;
	}
	std::cout << std::endl;
}


int Spiller::getValue() 
{	
	int tmp{0};

	for(int i = 0; i < hand.size() ;i++)
	{
		tmp += hand[i].getValueOf();
	}
	return tmp;
}
void Spiller::setBet(int i)
{
	bet = i;
}
int Spiller::getBet()
{
	return bet;
}
void Spiller::setActive(bool b)
{
	active = b;
}

bool Spiller::getActive()
{
	return active;
}

void Spiller::setBusted(bool b)
{
	busted = b;
}

bool Spiller::getBusted()
{
	return busted;
}
void Spiller::emptyHand()
{
	hand.clear();
}



