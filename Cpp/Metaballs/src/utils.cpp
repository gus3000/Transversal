#include "utils.hpp"

#include <fstream>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::ifstream;

/*
vector<Coord> csvToArray(string filepath)
{
  cout << "csvToArray(" << filepath << ")" << endl;

  vector<vector<int>> lines;
  ifstream infile(filepath, ifstream::in);
  if(!infile.is_open())
    {
      std::cerr << "ABORT ! ABORT !" << endl;
      exit(-1);
    }
  
  int frame,x,y;
  char comma;
  while(infile >> frame >> comma >> x >> comma >> y)
    {
      //cout << frame << "," << x << "," << y << std::endl;
      
    }
  
  return lines;
} //*/
