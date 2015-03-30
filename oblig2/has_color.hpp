#ifndef CLASS_HAS_COLOR_H
#define CLASS_HAS_COLOR_H

#include <FL/Fl.H>

typedef unsigned int Color;
typedef unsigned char ColorPart;

class has_color{
  virtual void draw()=0;
  Color color_=FL_WHITE;
  ColorPart* red_;
  ColorPart* green_;
  ColorPart* blue_; 
public:
  // Initialize with a random color if true, otherwise white
  has_color(bool Random=true);
  // Initialize with a full color
  has_color(Color start);
  // Initialize with RGB-parts
  has_color(ColorPart red, ColorPart green, ColorPart blue);  
  
  // Make color darker
  void darken_color();
  
  // Make color lighter
  void lighten_color();

  // Return the approximate visibility of the color, from 0-1.
  float visibility();
  
  // Getters
  inline Color color(){ return color_; };
  inline ColorPart red(){ return *red_; } ;
  inline ColorPart green(){ return *green_; };  
  inline ColorPart blue(){ return *blue_; };
};

#endif
