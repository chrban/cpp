#include <iostream>
#include "MixedDotFactory.hpp"
#include <FL/Fl.H>

	MixedDotFactory::MixedDotFactory(int t)
	{
		teller = t;

	}

dot* MixedDotFactory::createDot(float x,float y,float r)
{
	dot *d;	
	BlinkingDotFactory bd;
	NormalDotFactory nd;
	
	teller = teller%600;
    switch(teller++){            
       case 0 ... 199:
            d = nd.createDot(x,y,r);
			return d;
            break;
       case 200 ... 399:
            d = bd.createDot(x,y,r);
			return d;
            break;
       case 400 ... 599:
       		AbstractDotFactory *p = new TintedDotFactory<Fl_Color>(FL_BLUE);
            d = p->createDot(x,y,r);
            delete p;
			return d;
            break;
    }
}

 