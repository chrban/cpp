 #include "dot.hpp"
// #include "is_vector.hpp"

#include <vector>
#include <FL/Fl_Box.H>
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>


   void dot::draw()
   {
    fl_color(color()); 
    fl_pie(x(),y(),r,r,0,360);

	}	



dot::dot(float _x,float _y,float _r) : is_vector(_x,_y), r{_r}, has_color(true) 
{	

}

dot::dot(float _x,float _y,float _r, Color c) : is_vector(_x,_y), has_color(c)
{

}




void dot::operator++()
{
	
	++t;
	if(t < 20)
	{
		draw();
		if(t%8==0)
			darken_color();

	}
	increment_position();



}

void dot::reset(){}
dot::~dot(){}