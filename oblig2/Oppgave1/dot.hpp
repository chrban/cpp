#ifndef CLASS_DOT_H
#define CLASS_DOT_H

//Local includes
#include "is_vector.hpp"
#include "has_color.hpp"
#include "animated.hpp"

class dot : public animated, public is_vector, public has_color{
  
  // Radius
  double r;
  
public:
  /**  Don't change anything, just draw the dot */
  void draw() override;
  
  /** Initialize the dot.  */
  dot(float _x,float _y,float _r);  
  
  /** Initialize the dot with a starting color */
  dot(float _x,float _y,float _r, Color c);  
  
  /** Virtual destructor. */
  ~dot() override;
  
  /** The "inverse of draw()", i.e. overwrite the dot with black.*/
  void clear();
  
  /** Make any and all changes to the internal state of the dot as it changes
      with time. This is where the new position, new color etc. gets calculated.
      
      @note This function will in turn call "draw" when the  needed.   */  
  void operator++() override;
  
  /** Optional: Reset the dot, to it's initial state. */
  void reset() override;
};

#endif
