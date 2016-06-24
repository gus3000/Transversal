#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <vector>
#include <opencv2/opencv.hpp>

using std::vector;
using cv::Point;

struct Circle
{
  static vector<Circle> allCircles;
  static vector<Point> directions;
  int x;
  int y;
  int radius;
  
  Circle(int x, int y, int radius) : x(x), y(y), radius(radius){}

  bool inCircle(int,int) const;
  bool onCircle(int,int) const;
  static bool inCircles(int,int);
  static bool inBlob(int,int);
  static float inBlobFloGallin(int,int,vector<Circle>& circles);
};
#endif
