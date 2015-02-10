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

#include "Player.h"
#include "Cards.h"

using namespace std;

 int NR_ACTIVEPLAYERS=0;
 int NR_PLAYERS=2;
 int NR_PICKED{0};
static const int STARTMONEY = 1000;
std::vector<Kort> Kortstokk;
std::vector<Spiller> SpillerVector;

void initDeck()
{
	for (int s = 0; s < 4; s++)
	{
		for(int r=0; r < 13;r++)
		{
			Kortstokk.push_back( Kort(s,r) );	
		}
	}
}

void shuffle()
{
	int x;

	for(int i = 0;i < 51;i++ )
	{
		x = rand() % 52;
		Kort temp;

		temp = Kortstokk.at(x);
		Kortstokk.at(x) = Kortstokk.at(i);
		Kortstokk.at(i) = temp;
	}
}

Kort getNewCard()
{
	 Kort out = Kortstokk[NR_PICKED++];
 	out.setPicked(true);
	return out;
}
void initPlayers()
{

	for(int i = 0; i < NR_PLAYERS; i++ )SpillerVector.push_back(  Spiller(NR_ACTIVEPLAYERS++ ,STARTMONEY) );
}

void dealCards()
{
	initDeck();
	for(int i =0; i< NR_ACTIVEPLAYERS;i++)
		for(int j=0;j<2;j++)SpillerVector[i].addCard(getNewCard());
}

//GAMEPLAY _________________________________________________________________________________________________________

void hit(Spiller* s)
{
	s -> addCard( getNewCard() );
}
void stand(Spiller* s)
{
	s -> setActive(false);
}
bool busted(Spiller* s)
{
	if(s -> getValue() > 21)
	{
		for(int i = 0; i < s -> hand.size();i++)
		{
			if(s -> hand[i].getValueOf() == 11 )//har ess
			{
				s -> hand[i].setRank(-1);
				return false;
			}

		}
	
		cout << "    _               _           _       " << endl;
		cout << "   | |             | |         | |      " << endl;
		cout << "   | |__  _   _ ___| |_ ___  __| |      " << endl;
		cout << "   | '_ \\| | | / __| __/ _ \\/ _` |      " << endl;
		cout << "   | |_) | |_| \\__ \\ ||  __/ (_| |_ _ _ " << endl;
		cout << "   |_.__/ \\__,_|___/\\__\\___|\\__,_(_|_|_)" << endl;
		cout << "\n  CardValue is: " << s -> getValue() << "\n"<< endl;
		s -> displayHand();
		s -> setBusted(true);
		s -> setActive(false);
		return true;
		 
	}
	return false;
}

void startGame()
{
	std::chrono::milliseconds timespan(1000);
	int action{0};
	system("clear");
	cout << "\n\n\n\n" << endl;

	cout << "             _    _ _____ _     _____ ________  ___ _____ " << endl;
	cout << "            | |  | |  ___| |   /  __ \\  _  |  \\/  ||  ___|" << endl;
	cout << "            | |  | | |__ | |   | /  \\/ | | | .  . || |__  " << endl;
	cout << "            | |/\\| |  __|| |   | |   | | | | |\\/| ||  __| " << endl;
	cout << "            \\  /\\  / |___| |___| \\__/\\ \\_/ / |  | || |___ " << endl;
	cout << "             \\/  \\/\\____/\\_____/\\____/\\___/\\_|  |_/\\____/ " << endl;
	std::this_thread::sleep_for(timespan);
	system("clear");

	cout << "\n\n\n\n" << endl;

	cout <<	"                              _____ _____  " << endl;
	cout <<	"                             |_   _|  _  | " << endl;
	cout <<	"                               | | | | | | " << endl;
	cout <<	"                               | | | | | | " << endl;
	cout <<	"                               | | \\ \\_/ / " << endl;
	cout <<	"                               \\_/  \\___/  " << endl;
	cout <<	"                                           " << endl;

	std::this_thread::sleep_for(timespan);
	system("clear");


	cout << "\n\n\n\n" << endl;

	cout <<	"			  ____  _               _____ _  __    _         _____ _  __" << endl;
	cout <<	"			 |  _ \\| |        /\\   / ____| |/ /   | |  /\\   / ____| |/ /"  << endl;
	cout <<	"			 | |_) | |       /  \\ | |    | ' /    | | /  \\ | |    | ' /  " << endl;
	cout <<	"			 |  _ <| |      / /\\ \\| |    |  < _   | |/ /\\ \\| |    |  <   " << endl;
	cout <<	"			 | |_) | |____ / ____ \\ |____| . \\ |__| / ____ \\ |____| . \\  " << endl;
	cout <<	"			 |____/|______/_/    \\_\\_____|_|\\_\\____/_/    \\_\\_____|_|\\_\\ " << endl;


	std::this_thread::sleep_for(timespan);
	cout << "\n\n\n\n                          Angi ant. Spillere: ";
	cin >> action;
	NR_PLAYERS = (action+1);
	system("clear");

	initPlayers();	
	initDeck();
	shuffle();
	dealCards();


}


void score(Spiller* s)
{
	int action{0};

	cout << "______________________________________________________________________________\n\n" << endl;

	if(s -> getValue()==21) // BLACKJACK
	{
		cout << "Du har Blackjack!" << endl;
		stand(s);
	}
	else if(s -> getValue()>21)
	{
		busted(s);
	}

	if( s-> getBusted() || not (s -> getActive() ) )
		stand(s);
	else{
		// HIT OR RUN?
		cout << "\nPlayer nr."<<s -> getPlayerNr() << ",  your cardValue is: " <<  s -> getValue()<< 
		"                         Money at stake: $"<<s->getBet()<< endl;
		cout << "\n\n" << endl;
		s -> displayHand();
		cout << "\n\n Hit or Stand?   (1 = HIT, 2 = STAND) ";
		cin >> action;
		if(action==1)
			hit(s);
		else if(action==2)
			stand(s);
		}
}


void dealerLogic(Spiller* s)
{

	int val = s -> getValue();
	cout << "\n______________________________________________________________________________\n\n" << endl;

		std::chrono::milliseconds timespan(1500);

	if(val == 21 ) // BLACKJACK
	{
		std::this_thread::sleep_for(timespan);
		cout << "Dealer har BLACKJACK !\n\n" << endl;
		stand(s);
	}
	else if(val > 21 )
	{
		std::this_thread::sleep_for(timespan);
		cout << "Dealer er busted!" << endl;
		busted(s);
	}
	else if(val < 17)
	{	
		std::this_thread::sleep_for(timespan+timespan);
		cout << "Dealer hitter!\n\n" << endl;
		hit(s);
	}
	else
	{	
		std::this_thread::sleep_for(timespan);
		cout << "Dealer velger å stå på: " << val << "\n\n" <<endl;
		stand(s);
	}
	std::this_thread::sleep_for(timespan);

	if( s-> getBusted() || not (s -> getActive() ) )
		stand(s);
	else{
		cout << "Dealer has:  " <<  s -> getValue()<< endl;
		cout << "\n\n" << endl;
		s -> displayHand();
		cout << "\n\n(Dealer tenker..) ";
		std::chrono::milliseconds timespan(2000);
		std::this_thread::sleep_for(timespan);
		}

}



void runDealer()
{
	Spiller* s = &SpillerVector[0];

	
	cout << "Dealer has:  " <<  s -> getValue()<< endl;
	s -> displayHand();
	while(s->getActive())
	{
		dealerLogic(s);
	}
}


void showDealerCards()
{
	cout << "Dealer has: "<< endl;
	SpillerVector[0].hand[0].getDisplay();
	cout << "[ -  - ]" << endl;
}
void bestHand()
{
	Spiller* d = &SpillerVector[0]; // dealerpeker

	if( d-> getBusted())
	{
		cout << "\n\nDealer is BUSTED" << endl;
	
	for(int i=1; i < NR_ACTIVEPLAYERS;i++)
	{
		Spiller* s = &SpillerVector[i];

		if( !(s->getBusted() ) )
		{// alle som ikker er busta vinner 1:1 sin bet
			int win = s-> getBet() * 2;
			s->setCredit( win );
			cout << "Utbetalt $"<<win<<"  til spiller " << s-> getPlayerNr() << endl; 
			//get:money
		}
		else
		{
			int loose = s-> getBet() *-1;
			s->setCredit( loose );
			cout << "Fjernet $"<<loose<<"  fra spiller " << s-> getPlayerNr() << " sin konto (BUSTED))"<< endl; 
		}
	}

		
	}
	else
	{
		int dealerScore = d->getValue();


		for(int i=1; i < NR_ACTIVEPLAYERS;i++)
		{
			Spiller* s = &SpillerVector[i];

			if(s->getValue() > dealerScore )
			{
				if(s->getValue()==21)
				{
					int win = s-> getBet() * 2.5;
					s->setCredit( win );
					cout << "Utbetalt $"<<win<<"  til spiller " << s-> getPlayerNr() <<" ( BLACKJACK! =D )"<< endl; 
				}
					int win = s-> getBet() * 2;
					s->setCredit( win );
					cout << "Utbetalt $"<<win<<"  til spiller " << s-> getPlayerNr()  <<" (Slo dealer)"<< endl; 

				
			}
			else if(s->getValue()==dealerScore)
			{
					cout << "Utbetalt $0 til spiller " << s-> getPlayerNr()  <<" (PUSH )"<< endl; 
			}
			else//dealer slo deg
			{

			int loose = s-> getBet() *-1;
			s->setCredit( loose );
			cout << "Fjernet $"<<loose<<"  fra spiller " << s-> getPlayerNr() << " sin konto (Dealer slo deg)"<< endl; 

			}
			if(s->getBusted() )
			{
			int loose = s-> getBet() *-1;
			s->setCredit( loose );
			cout << "Fjernet $"<<loose<<"  fra spiller " << s-> getPlayerNr() << " sin konto (BUSTED))"<< endl; 
			}
		}
	}

}

void collectCards()
{
	for(int i =0; i < NR_ACTIVEPLAYERS; i++)
	{
		Spiller* s = &SpillerVector[i];
		s-> emptyHand();
		s-> setActive(true);
		s-> setBusted(false);
	}
	Kortstokk.clear();
}



void run()
{
	for(int i =0; i < NR_ACTIVEPLAYERS; i++)
	{
		cout << "\n\n\n";


		Spiller* s = &SpillerVector[i];
			if(i==0)//dealer
			{
				//
			}

			else
			{
				cout << "______________________________________________________________________________\n\n" << endl;
				int action{0};
			 	cout << "Player nr."<< s -> getPlayerNr() << ",  you have $ = " << s -> getCredit() <<endl;
			 	cout << "\nPlace your bet: ";
			 	cin >> action;
			 	if(action > s->getCredit())
			 	{
			 		cout << "Bet is bigger than your credit.\nPlace your bet: "; cin >> action;
			 	}
			 	if(action > s->getCredit())
			 	{

			 	}
			 	s -> setBet(action);
			 	

		 		score(s);

			 	while(  s -> getActive()  )
			 	{
			 		score(s);	
			 	}
			}
		
	}
	runDealer(); 
	bestHand();
	while(SpillerVector[1].getCredit() > 0)  // Spiller 1..
	{
		std::chrono::milliseconds timespan(2000);
		std::this_thread::sleep_for(timespan);
		cout << "  ...Starting" << endl;
		cout << "       _   _  _______   _______       " << endl;
		cout << "      | \\ | ||  ___\\ \\ / /_   _|      " << endl;
		cout << "      |  \\| || |__  \\ V /  | |        " << endl;
		cout << "      | . ` ||  __| /   \\  | |        " << endl;
		cout << "      | |\\  || |___/ /^\\ \\ | |        " << endl;
		cout << "      \\_| \\_/\\____/\\/   \\/ \\_/        " << endl;
		cout << "                                      " << endl;
		cout << "                                      " << endl;
		cout << "      ______ _____ _   _ _   _______  " << endl;
		cout << "      | ___ \\  _  | | | | \\ | |  _  \\ " << endl;
		cout << "      | |_/ / | | | | | |  \\| | | | | " << endl;
		cout << "      |    /| | | | | | | . ` | | | | " << endl;
		cout << "      | |\\ \\\\ \\_/ / |_| | |\\  | |/ /  " << endl;
		cout << "      \\_| \\_|\\___/ \\___/\\_| \\_/___/   " << endl;
       	system("clear");
		


		collectCards();

		initDeck();
		shuffle();
		dealCards();
		run();

	}
	cout << "Du er tom for penger! Takk for spillet! " << endl;
}






int main(){
	srand(time(NULL));//random seed

	startGame();
	run();

	

}