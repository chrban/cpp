#include "BlinkingDotFactory.hpp"
#include "blinkingDot.hpp"



dot* BlinkingDotFactory::createDot(float x,float y,float r) 
{
	dot* d = new blinkingDot(x,y,r);
	return d;

}