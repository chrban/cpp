#include "animation_canvas.hpp"
#include <iostream>
#include <FL/fl_draw.H>



  animation_canvas::animation_canvas(const char *l, int w, int h) : Fl_Box::Fl_Box(1,1,w,h,l){}

  void animation_canvas::draw(){

    

    fl_color(FL_GREEN); //Sette penselfarge
    fl_pie(120,70,30,30,0,180); //Tegne



    //LAGE EN DOTT
    fl_color(FL_RED); //Sette penselfarge
    fl_pie(160,10,10,10,0,360); //Tegne


    //LAGE EN DOTT
    fl_color(FL_BLUE); //Sette penselfarge
    fl_pie(x++,100,30,30,0,360); //Tegne

  }

   void animation_canvas::timer(void* canvas){

    Fl::repeat_timeout(0.1,timer,canvas);
    std::cout << "Timeout!" << std::endl;
    ((Fl_Window*)canvas)->redraw();
  }

  animation_canvas::~animation_canvas(){}
