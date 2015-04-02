#include "NormalDotFactory.hpp"
#include <FL/Fl.H>

dot* NormalDotFactory::createDot(float x,float y,float r) 
{
	
	colorFarge = FL_RED;
	dot* d = new dot(x,y,r, colorFarge);
	return d;

}


