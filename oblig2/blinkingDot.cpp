#include "blinkingDot.hpp"

#include <vector>
#include <FL/Fl_Box.H>
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>



 blinkingDot::blinkingDot(float _x,float _y,float _r) : dot( _x ,_y, _r ) // legge tol fargevalg
 {
 	t = 0;
 }

  void blinkingDot::operator++()
  {
	++t;
	if(t%2==0 && t < 20)
	{
		draw();

	}
	increment_position();

 

  }
 