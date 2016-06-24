#ifndef DRAWER_HPP
#define DRAWER_HPP

void fillRandom(cv::Mat &m);
void addRandomCircles(int,int,int);
void showCircles(int,int,vector<Circle>&);
void initDirections();
std::map<int,vector<Circle>> circlesFromCSV(std::string filepath);
void updateObjects(int frame, std::map<int,vector<Circle>>& data, vector<Circle>& objects);
void move(int,int);

#endif
