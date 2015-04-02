#ifndef CLASS_ABSTRACTDOTFACTORY_H
#define CLASS_ABSTRACTDOTFACTORY_H
#include "dot.hpp"

class AbstractDotFactory{

 public:
  
 virtual dot* createDot(float x,float y,float r)=0;

};


#endif