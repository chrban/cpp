#ifndef CLASS_TINTEDDOTFACTORY_H
#define CLASS_TINTEDDOTFACTORY_H
#include "AbstractDotFactory.hpp"



template <typename colorType>
class TintedDotFactory : public AbstractDotFactory{
colorType farge;

public:
	TintedDotFactory(colorType ct){farge = ct;}


	dot* createDot(float x,float y,float r){
		dot* d = new dot(x,y,r, farge);
		return d;
	}

};

#endif