#include "TintedDotFactory.hpp"
#include <FL/Fl.H>

dot* TintedDotFactory::createDot(float x,float y,float r ) 
{	

	colorFarge = FL_BLUE;
	dot* d = new dot(x,y,r, colorFarge);
	return d;

}