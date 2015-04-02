#include "rocket.hpp"
const int FARGENMIN = 43520867;

void rocket::operator++()
{
  if(fuse == 0)
  {
    for( auto d : dots )
    {
      ++(*d);
    }
  }
  else
  {
    --fuse;
  }

}

rocket::rocket(int _dotcount,int dotsize, int _fuse, int x, int y) : dotcount{_dotcount}, fuse{_fuse}
{
  for(int i=0; i< dotcount; i++)
  {
    dot *d = new dot(x,y,(dotsize/2), FARGENMIN );
    dots.push_back( d );

  }
}
   
  
  
rocket::~rocket()
{
  for( auto d : dots )
  {
    delete d;
  }

}


