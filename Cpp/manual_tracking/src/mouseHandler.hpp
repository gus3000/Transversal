#ifndef MOUSE_HANDLER_HPP
#define MOUSE_HANDLER_HPP

#include <iostream>
#include "opencv2/opencv.hpp"


using std::ostream;

class MouseHandler;
struct MouseHandleData
{
  MouseHandler* handler;
  int frame;
};


class MouseHandler
{
private:
  int x,y;
  int frame;
  int old;
  bool isClicking;
  
public:
  MouseHandler()
  {
    x=y=-1;
    old = -1;
    isClicking = false;
  }

  static void staticHandle(int event, int x, int y, int flags, void* data)
  {
    
    MouseHandleData* mdata = reinterpret_cast<MouseHandleData*>(data);
    mdata->handler->handle(event,x,y,flags,mdata->frame);
  }
  
  void handle(int event, int x, int y, int flags, int frame);
  
  operator bool() const
  {
    return isClicking;
  }
  friend ostream& operator<<(ostream&,MouseHandler);
};


#endif
