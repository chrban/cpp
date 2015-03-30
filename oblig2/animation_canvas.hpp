#ifndef CLASS_ANIMATION_CANVAS_H
#define CLASS_ANIMATION_CANVAS_H

#include <vector>
#include <FL/Fl_Box.H>
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

//Local includes
#include "dot.hpp"


class animation_canvas : public Fl_Box {
  
  // The animated parts
  std::vector<animated*> parts;
  
  // Frames pr. second (animation speed)
  static int fps;
  int x = 180;
  
 public:
  /** Initialize */
  animation_canvas(const char *l,int w, int h);
  
  /** Callback for a timeout (i.e. FLTK add_tmeout) */
  static void timer(void* canvas);
  
  /** Add an animated part to "parts" */
  void add(animated* part);
  
  /** Virtual destructor */
  virtual ~animation_canvas();
  
  
private:
  /** Overridden from Fl_Box */
  void draw () override;

  void increment ();
  
};


#endif
