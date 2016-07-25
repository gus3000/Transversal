#include <iostream>

#include "node.hpp"

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char *argv[])
{
  //*
  Node<int> n(nullptr,3);
  Node<int> n2(n),n3(n),n4(n2);
  cout << n << endl;
  cout << n2 << endl << n3 << endl << n4 << endl;
  //*/
  return 0;
}
