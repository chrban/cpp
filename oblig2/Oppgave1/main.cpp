#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include "animation_canvas.hpp"
#include "dot.hpp"
#include "fireworks.hpp"


int main(int argc, char **argv) {
  Fl_Window *window = new Fl_Window(1024,768);

  fireworks *f = new fireworks("eyyyyy",1024,768,20);

Fl::add_timeout((double)1/25, animation_canvas::timer,window);

  window->color(FL_BLACK);
  window->fullscreen();
  window->end();
  window->show(argc, argv);

  Fl::run();

  return 0;
}
