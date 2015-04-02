#ifndef CLASS_NORMALDOTFACTORY_H
#define CLASS_NORMALDOTFACTORY_H
#include "AbstractDotFactory.hpp"

class NormalDotFactory : public AbstractDotFactory{

public:
	dot* createDot(float x,float y,float r);
	typedef unsigned int Color;
	Color colorFarge;

};

#endif
