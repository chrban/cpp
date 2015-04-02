#ifndef CLASS_BLINKINGDOTFACTORY_H
#define CLASS_BLINKINGDOTFACTORY_H
#include "AbstractDotFactory.hpp"
#include "blinkingDot.hpp"



class BlinkingDotFactory : public AbstractDotFactory{

public:
	dot* createDot(float x,float y,float r);


};


#endif

