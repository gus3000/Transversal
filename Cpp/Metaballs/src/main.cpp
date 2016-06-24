#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

#include <experimental/random>

#include <opencv2/opencv.hpp>

#include "circle.hpp"
#include "utils.hpp"
#include "drawer.hpp"


using cv::VideoCapture;
using cv::Mat;

using std::map;

int main(int argc, char *argv[])
{
  const int width = 500;
  const int height = 500;

  //addRandomCircles(width,height,10);
  // Circle::allCircles.push_back(Circle(30,30,20));
  // Circle::allCircles.push_back(Circle(450,50,40));
  // Circle::allCircles.push_back(Circle(30,450,10));

  //initDirections();

  //init video
  VideoCapture capture(argv[1]);
  if(!capture.isOpened())
    {
      std::cerr << "Error while opening video file." << std::endl;
      return -1;
    }

  vector<Circle> objects;

  Mat currentFrame;
  int frameIndex = 0;
  //init circles
  map<int,vector<Circle>> data = circlesFromCSV(argv[2]);
  
  while(cv::waitKey(16) == -1) //tant qu'on appuie sur rien
    {
      updateObjects(frameIndex,data,objects);
      capture >> currentFrame;
      //imshow("test",currentFrame);
      showCircles(width,height,objects);
      //move(width,height);
      
      ++frameIndex;
    }
  
  return 0;
}
