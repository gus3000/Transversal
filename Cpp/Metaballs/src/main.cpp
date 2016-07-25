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

#define MAX_OBJECTS 9

int main(int argc, char *argv[])
{
  const int width = 500;
  const int height = 500;

  //addRandomCircles(width,height,10);
  // Circle::allCircles.push_back(Circle(30,30,20));
  // Circle::allCircles.push_back(Circle(450,50,40));
  // Circle::allCircles.push_back(Circle(30,450,10));

  //initDirections();
  if(argc < 3)
    {
      std::cout << "usage : "<< argv[0] << " video.avi circles.csv [visualization]" << std::endl;
      return 0;
    }
  
  //init video
  VideoCapture capture(argv[1]);
  if(!capture.isOpened())
    {
      std::cerr << "Error while opening video file." << std::endl;
      return -1;
    }

  vector<Circle> objects;
  for(int i=0; i<MAX_OBJECTS; ++i)
    objects.push_back(Circle(-100,-100,20));

  Mat currentFrame;
  int frameIndex = 0;
  //init circles
  map<int,map<int,Circle>> data = circlesFromCSV(argv[2]);

  bool visualization = argc>3;
  std::cout << "Starting " << (visualization ? "with" : "without") << " viz" << std::endl;
  
  while(cv::waitKey(16) == -1) //tant qu'on appuie sur rien
    {
      updateObjects(frameIndex,data,objects);
      capture >> currentFrame;
      //imshow("test",currentFrame);
      if(visualization)
	showCircles(width,height,objects,currentFrame);
      else
	{
	  
	}
      //move(width,height);

      std::cout << frameIndex << std::endl;
      ++frameIndex;
      //frameIndex = 560;
    }
  
  return 0;
}
