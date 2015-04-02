#include "fireworks2.hpp"
#include "rocket2.hpp"
#include "NormalDotFactory.hpp"
#include "BlinkingDotFactory.hpp"
#include "TintedDotFactory.hpp"
#include "MixedDotFactory.hpp"
#include <FL/Fl.H>

fireworks::fireworks(const char* title,int w, int h, int _rocketcount) : animation_canvas::animation_canvas(title,w,h), rocketcount{_rocketcount}
{
	
	// AbstractDotFactory *p = new NormalDotFactory();
	// AbstractDotFactory *p = new BlinkingDotFactory();
	// AbstractDotFactory *p = new TintedDotFactory<Fl_Color>(FL_RED);
	 AbstractDotFactory *p = new MixedDotFactory(0);

	for (int i = 0; i < rocketcount; i++)
	{
		int x = rand()%(w-100)+50;
		int y = rand()%(h-100)+50;
		int f = rand()% 200;
		rocket * r= new rocket(200, 5, f, x, y, p );
		add(r);
	}

	delete p;
}



fireworks::~fireworks()
{
	
}

