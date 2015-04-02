#ifndef CLASS_BLINKINGOT_H
#define CLASS_BLINKINGOT_H 
#include "dot.hpp"
// #include "is_vector.hpp"
// #include "has_color.hpp"
// #include "animated.hpp"
#include "BlinkingDotFactory.hpp"

class blinkingDot : public dot{
  
public:
 
  blinkingDot(float _x,float _y,float _r);  

  void operator++() override;
  
};




#endif