#include "mouseHandler.hpp"

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

void MouseHandler::handle(int event, int x, int y, int flags, int frame)
{
  //cout << "handling";
  if(event == cv::EVENT_LBUTTONDOWN)
    {
      isClicking = true;
    }
  else if(event == cv::EVENT_LBUTTONUP)
    {
      isClicking = false;
    }
  
  if(isClicking)
    {
      this->frame = frame;
      this->x = x;
      this->y = y;      
    }
}


ostream& operator<<(ostream& o, MouseHandler m)
{
  o << m.frame << "," << m.x << "," << m.y;
  return o;
}
