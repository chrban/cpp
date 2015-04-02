#include "has_color.hpp"
#include <FL/Enumerations.H>
#include <FL/fl_draw.H>

has_color::has_color(bool Random)
{
	if(Random == true ) 
	{
	color_ = fl_color_cube(rand() * (FL_NUM_RED - 1) / 255,
				  rand() * (FL_NUM_GREEN - 1) / 255,
	   			  rand() * (FL_NUM_BLUE - 1) / 255);

		fl_color(color_);
	}
	else
	{
		color_ = FL_WHITE;
		fl_color(color_);
	}
}


has_color::has_color(Color start)	
{
	color_ = start;
	fl_color(color_);
}

has_color::has_color(ColorPart red, ColorPart green, ColorPart blue): red_(&red), green_(&green), blue_(&blue)
{

	color_ = fl_rgb_color(red,green,blue);
	fl_color(color_);
}

void has_color::darken_color()
{
	color_ = fl_darker(color_);	
}

void has_color::lighten_color()
{
	color_ = fl_lighter(color_);
}

float has_color::visibility(){
	return 1;
}