#include "circle.hpp"
#include <limits>

vector<Circle> Circle::allCircles;
vector<Point> Circle::directions;

bool Circle::inCircle(int x,int y) const
{
  int dx = x - this->x;
  int dy = y - this->y;

  return (dx*dx) + (dy*dy) <= this->radius * this->radius;
}

bool Circle::onCircle(int x,int y) const
{
  int dx = x - this->x;
  int dy = y - this->y;

  int diff = (dx*dx) + (dy*dy) - this->radius * this->radius;
  return diff > 0 && diff < 2*this->radius;
}

bool Circle::inCircles(int x, int y)
{
  float max = 0;
  for(auto const& circle: Circle::allCircles)
    {
      int dx = x - circle.x;
      int dy = y - circle.y;
      if(dx == 0 && dy == 0)
	return true;
      
      float frac = (circle.radius * circle.radius) / ((dx*dx) + (dy*dy));
      if(frac > max)
	max = frac;
    }
  return max >= 1;
}

bool Circle::inBlob(int x, int y)
{
  float sum = 0;
  for(auto const& circle: Circle::allCircles)
    {
      int dx = x - circle.x;
      int dy = y - circle.y;
      if(dx == 0 && dy == 0)
	//return true;
	return std::numeric_limits<float>::max();
      
      float frac = (circle.radius * circle.radius) / ((dx*dx) + (dy*dy));
      sum += frac;
    }
  //if(sum > 1) 
  //std::cout << sum << "\t";
  return sum >= 0.01;
  //return sum;
}

float Circle::inBlobFloGallin(int x, int y)
{
  float sum = 0;
  for(auto const& circle: Circle::allCircles)
    {
      int dx = x - circle.x;
      int dy = y - circle.y;
      //std::cout << circle.x << "," << circle.y << std::endl;

      int dist = ((dx*dx) + (dy*dy));
      int radiusSquared = circle.radius * circle.radius;

      float frac = (float)dist / (float)radiusSquared;

      float total = (1-frac) * (1-frac) * (1-frac);
      if(total < 0)
	total = 0;
      sum += total;
      //std::cout << dist << "," << total << "\t";

    }
  sum -= 0.5;
  if(sum > 1)
    return 1;
  if(sum < 0)
    return 0;
  return sum;
}
