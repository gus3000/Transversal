#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <vector>
#include <opencv2/opencv.hpp>

using std::vector;
using cv::Point;

struct Circle
{  
public:  
  static vector<Circle> allCircles;
  static vector<Point> directions;
  int x;
  int y;
  int radius;
  int nbFramesStill;
  
  Circle(int x, int y, int radius) : x(x), y(y), radius(radius), nbFramesStill(10){}

  bool inCircle(int,int) const;
  bool onCircle(int,int) const;
  bool hasStayedStill() const { return nbFramesStill >= 60; }
  void updatePosition(int nx, int ny)
  {
    if(nx != x || ny != y)
      {
	nbFramesStill = 0;
      }
    x = nx;
    y = ny;
  }
  void updatePosition(Circle& c)
  {
    updatePosition(c.x,c.y);
  }

  void updateTimeStill() { nbFramesStill++; }
  static bool inCircles(int,int);
  static bool inBlob(int,int);
  static float inBlobFloGallin(int,int,vector<Circle>&,bool);
};
std::ostream& operator<<(std::ostream& o,const Circle& c);

#endif
