#ifndef CLASS_MIXEDDOTFACTORY_H
#define CLASS_MIXEDDOTFACTORY_H

#include "AbstractDotFactory.hpp"
#include "NormalDotFactory.hpp"
#include "BlinkingDotFactory.hpp"
#include "TintedDotFactory.hpp"

class MixedDotFactory : public AbstractDotFactory{

int teller;
public:
	MixedDotFactory(int t);
	
	dot* createDot(float x,float y,float r);
	 


};

#endif

