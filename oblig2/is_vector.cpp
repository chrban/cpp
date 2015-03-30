#include "is_vector.hpp"
#include <iostream>
is_vector::is_vector(double x, double y) : x_{x}, y_{y}, direction_{2}, speed_{2}{} 

  double x_orig_;
  double y_orig_;
  double x_;
  double y_;
  double speed_= 5;
  double direction_;

void increment_position(){


	x_ = x_ + speed_ * cos(direction_);
	y_ = y_ + speed_ * sin(direction_);
	std::cout << "Inkrementerer!" << std::endl;

  // double x_orig_;
  // double y_orig_;
  // double x_;
  // double y_;  
  // double speed_= 0;
  // double direction_= 0;


}

void reset();


//is_vector::~is_vector(){}
//is_vector::is_vector(double x, double y) : x_{x}, y_{y}, direction_{rand%360}, speed_{2}{}  konst