#include <iostream>
#include "MixedDotFactory.hpp"


	MixedDotFactory::MixedDotFactory(int t)
	{
		teller = t;

	}

dot* MixedDotFactory::createDot(float x,float y,float r)
{
	// AbstractDotFactory *p = new TintedDotFactory();
	// dot* d = new dot(x,y,r);
	// AbstractDotFactory *p = new NormalDotFactory();
	
	dot *d;

	TintedDotFactory td;
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
            d = td.createDot(x,y,r);
			return d;
            break;
    }
    

}


	// AbstractDotFactory *p = new NormalDotFactory();
	// AbstractDotFactory *p = new BlinkingDotFactory();
	// AbstractDotFactory *p = new TintedDotFactory();
