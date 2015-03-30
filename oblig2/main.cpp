#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include "animation_canvas.hpp"



int main(int argc, char **argv) {
  //opretter vindu
  Fl_Window *window = new Fl_Window(340,180);

  //legger til bx

  animation_canvas *box = new animation_canvas("pikk",40,40);

   Fl::add_timeout(0.1, animation_canvas::timer, window);


  // Fl::add_timeout(0.1, , window);

//Fl::add_timeout(interval,myCallback, window);


//box dettings
  // box->box(FL_UP_BOX);
  // box->labelfont(FL_BOLD+FL_ITALIC);
  // box->labelsize(60);
  // box->labeltype(FL_SHADOW_LABEL);

//skal ikke legge til fler, derfior -> end
  window->end();

  //vis vindu, enter fltk loop. 
  window->show(argc, argv);
  return Fl::run();
}
