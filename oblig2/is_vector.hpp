#ifndef CLASS_IS_VECTOR_H
#define CLASS_IS_VECTOR_H

#include <math.h>
const double TAU=M_PI*2;

class is_vector{
  
  double x_orig_;
  double y_orig_;
  double x_;
  double y_;
  
  double speed_= 0;
  double direction_= 0;

public: 
  // Initialize with given x- and y, assign speed and direction randomly.
  is_vector(double x, double y);
  
  // Getters
  inline double x(){return x_; };
  inline double y(){return y_; };
  inline double speed(){return speed_;};
  inline double direction(){return direction_;};
  
  // Increment the position, based on current position, speed and direction
  void increment_position();
  
  // Optional: Reset the position to its initial state
  void reset();
  
};


#endif