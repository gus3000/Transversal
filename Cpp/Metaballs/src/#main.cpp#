#include <iostream>
#include <cstdlib>
#include <vector>

#include <experimental/random>

#include <opencv2/opencv.hpp>

#include "circle.hpp"
#include "drawer.hpp"

int main(int argc, char *argv[])
{
  const int width = 500;
  const int height = 500;

  addRandomCircles(width,height,10);
  // Circle::allCircles.push_back(Circle(30,30,20));
  // Circle::allCircles.push_back(Circle(450,50,40));
  // Circle::allCircles.push_back(Circle(30,450,10));

  initDirections();
  
  while(cv::waitKey(16) == -1) //tant qu'on appuie sur rien
    {
      showCircles(width,height);
      move(width,height);
    }
  
  return 0;
}
