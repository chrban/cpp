#include "fireworks.hpp"
#include "rocket.hpp"


fireworks::fireworks(const char* title,int w, int h, int _rocketcount) : animation_canvas::animation_canvas(title,w,h), rocketcount{_rocketcount}
{
	//srand(time(NULL));

	for (int i = 0; i < rocketcount; i++)
	{
		int x = rand()%(w-100)+50;
		int y = rand()%(h-100)+50;
		int f = rand()% 200;
		rocket * r= new rocket(200, 10, f, x, y );
		add(r);
	}
}



fireworks::~fireworks()
{
	
}


//rocket(int _dotcount,int dotsize, int _fuse, int x, int y);