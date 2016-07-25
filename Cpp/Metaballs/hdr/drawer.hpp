#ifndef DRAWER_HPP
#define DRAWER_HPP

void fillRandom(cv::Mat &m);
void addRandomCircles(int,int,int);
void showCircles(int,int,vector<Circle>&,cv::Mat&);
void initDirections();
std::map<int,std::map<int,Circle>> circlesFromCSV(std::string filepath);
void updateObjects(int frame, std::map<int,std::map<int,Circle>>& data, vector<Circle>& objects);
void move(int,int);

#endif
