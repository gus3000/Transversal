#include <iostream>
#include <string>

#include "opencv2/opencv.hpp"
#include "mouseHandler.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stoi;

using cv::VideoCapture;
using cv::Mat;
using cv::waitKey;
using cv::setMouseCallback;
using cv::namedWindow;


void printUsage(string exename)
{
  cout << "Usage : " << exename << " mediafile [fps]" << endl;
}

//*
void handleMouseOld(int event, int x, int y, int flags, void* data)
{
  static bool holding = false;
  
  if(event == cv::EVENT_LBUTTONDOWN)
    {
      holding = true;
    }
  else if(event == cv::EVENT_LBUTTONUP)
    {
      holding = false;
    }

  if(holding)
    {
      cout << x << "," << y << endl;
    }
} //*/

int main(int argc, char *argv[])
{
  if(argc == 1)
    {
      cout << "You must give a readable file name in argument." << endl;
      printUsage(argv[0]);
      return 0;
    }

  string fileName = argv[1];
  int fps = 30; //default value
  VideoCapture video(fileName);
  if(!video.isOpened())
    {
      cerr << "Error : Cannot open video file. Exiting..." << endl;
      return -1;
    }

  namedWindow("frame",1);
  MouseHandler handler;
  MouseHandleData mdata;
  mdata.handler = &handler;
  setMouseCallback("frame", MouseHandler::staticHandle, &mdata);
  
  
  fps = (int) video.get(CV_CAP_PROP_FPS);
  //cout << "fps : " << fps << endl;
  int toWait = 1000.0/fps;
  
  float nbFrames = video.get(CV_CAP_PROP_FRAME_COUNT);

  for(int i=0; i<nbFrames; ++i)
  {
      Mat frame;
      video >> frame;
      imshow("frame",frame);
      mdata.frame = i;
      if(handler)
	cout << handler << endl;
      waitKey(toWait);
    }
  
  return 0;
}
