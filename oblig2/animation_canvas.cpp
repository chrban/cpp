#include "animation_canvas.hpp"
#include <iostream>
#include <FL/fl_draw.H>

int animation_canvas::fps = 25;

  animation_canvas::animation_canvas(const char *l, int w, int h) : Fl_Box::Fl_Box(1,1,w,h,l){}

  void animation_canvas::draw()
  {
      for( auto r : parts )
      {
      ++(*r);
      }
  }

  void animation_canvas::add(animated* part)
  {
    parts.push_back( part );
  }

   void animation_canvas::timer(void* canvas){

    Fl::repeat_timeout(0.1,timer,canvas);
    std::cout << "Timeout!" << std::endl;
    ((Fl_Window*)canvas)->redraw();
  }

  animation_canvas::~animation_canvas()
  {
      for( auto p : parts )
      {
        delete p;
      }
  }
