#include "is_vector.hpp"
#include <iostream>




is_vector::is_vector(double x, double y) : x_{x}, y_{y} 
{
  direction_ = fmod( rand(),TAU );
  speed_ = (double)((rand() %16 )+9);
} 



void is_vector::increment_position(){
  x_ = x_ + speed_*cos(direction_);
  y_ = y_ + speed_*sin(direction_);
}

void reset();


