#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <ostream>
#include <vector>

using std::ostream;
using std::vector;

template <typename T>
class Node
{
private:
  Node<T>* father;
  int depth;
  T value;
  vector<Node<T>*> children;
  
public:
  Node(Node<T>& n, T t = T()) : father(&n), depth(n.depth + 1), value(t) {
    n.children.push_back(this);
  };
  Node(Node<T>* n, T t = T()) : father(n), depth(n == nullptr ? 0 : n->depth + 1), value(t) {
    if(n != nullptr)
      n->children.push_back(this);
  }

  
  template <typename T2>
  friend ostream& operator<<(ostream&,Node<T2>&);
};

template <typename T>
inline ostream& operator<<(ostream& o,Node<T>& n)
{
  o << "(" <<  n.depth << "," << n.value;
  int size;
  if((size = n.children.size()) > 0)
    {
      o << "|";
      for(int i=0; i<size; ++i)
	{
	  o << *(n.children[i]);
	}
    }
  return o << ")";
}


#endif
