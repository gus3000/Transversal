#include <experimental/random>
#include <opencv2/opencv.hpp>

#include "circle.hpp"

using cv::Mat;
using cv::Vec3b;
using std::vector;

void fillRandom(Mat &m)
{
  //std::srand(std::time(0));

  int nRows = m.rows;
  int nCols = m.cols * m.channels();

  uchar *p;
  for(int i=0; i<nRows; ++i)
    {
      p = m.ptr<uchar>(i);
      for(int j=0; j<nCols; ++j)
	{
	  p[j] = std::experimental::randint(0,255);
	}
    }
}

void addRandomCircles(int width, int height, int amount)
{
  for(int i=0; i<amount; ++i)
    {
      int r = std::experimental::randint(1,100);
      int x = std::experimental::randint(r,width-r);
      int y = std::experimental::randint(r,height-r);
      
      Circle::allCircles.push_back(Circle(x,y,r));
    }
}

void showCircles(int width, int height)
{
  Mat m = Mat::zeros(width,height, CV_8UC3);

  //fillRandom(m);
  
  int nRows = m.rows;
  int nCols = m.cols;

  Vec3b greenPixel(0,255,0);
  Vec3b redPixel(0,0,255);
  
  uchar *p;
  for(int i=0; i<nRows; ++i)
    {
      for(int j=0; j<nCols; ++j)
	{
	  float blobiness = Circle::inBlobFloGallin(j,i);
	  Vec3b green(0, blobiness * 255,0);
	  m.at<Vec3b>(i,j) = green;
	  if(blobiness * 255 < 10 && blobiness * 255 > 0)
	    m.at<Vec3b>(i,j) = redPixel;
	}
    }
  
  imshow("Coucou",m);
  imwrite("Coucou.bmp",m);
}

void initDirections()
{
  int nbCircles = Circle::allCircles.size();
  Circle::directions = vector<Point>(nbCircles);
  for(int i=0; i<nbCircles; ++i)
  {
      int xy = std::experimental::randint(1,100); //comme ça on évite d'avoir x=0 && y=0
      int x = xy % 10;
      int y = xy / 10;
      
      Point p(x/2,y/2);
      Circle::directions[i] = p;
    }
}

void move(int width, int height)
{
  int nbCircles = Circle::allCircles.size();
  for(int i=0; i<nbCircles; ++i)
    {
      Circle* c = &Circle::allCircles[i];
      Point* dir = &Circle::directions[i];
      c->x += dir->x;
      c->y += dir->y;

      if(c->x - c->radius < 0 || c->x + c->radius > width)
	dir->x = -dir->x;
      if(c->y - c->radius < 0 || c->y + c->radius > height)
	dir->y = -dir->y;
    }
}
