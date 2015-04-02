#ifndef CLASS_TINTEDDOTFACTORY_H
#define CLASS_TINTEDDOTFACTORY_H
#include "AbstractDotFactory.hpp"


class TintedDotFactory : public AbstractDotFactory{

public:
	dot* createDot(float x,float y,float r);
	typedef unsigned int Color;
	Color colorFarge;

};

#endif