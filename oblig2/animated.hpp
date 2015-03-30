#ifndef CLASS_ANIMATED_H
#define CLASS_ANIMATED_H

class animated {

protected:
  int t;
 public:
  
  /** Do all the changes in an animated object, as time progress */ 
  virtual void operator++() = 0; 
  
  /** Optional: Reset to initial state **/
  virtual void reset() {};
 
  /** Optional: Determine if the animated object is "done" and can be deleted */
  virtual bool animation_finished() { return false; };
  
  /** Virtual destructor */
  virtual ~animated() {};
};

#endif
