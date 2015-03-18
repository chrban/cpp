#include "Cards.h"

std::string suites[]{"♤", "♡", "♢", "♧"};
std::string ranks[]{"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

Kort::Kort(){}
Kort::Kort(int s, int r) : suit{s}, rank{r} {}

void Kort::getDisplay()
{
	
	std::cout << "[ " << suites[suit] << " " << ranks[rank] << " ]";

}

int Kort::getRank()
{
	return rank;
}
int Kort::getValueOf() 
{

	int value = (rank+1) %13;

	if(value >= 11 || value == 0 )value = 10;// konge gir verdi = 0, bilde gir <= 11
	else if(value == 1 )value=11;  // Ess 
	else if(value == -1)value=-1; // ess som er endre til 1

	return value;
}
void Kort::setPicked(bool b)
{
	pick = b;
}
bool Kort::getPicked()
{
	return pick;
}
void Kort::setRank(int i)
{
	rank = i;
}


