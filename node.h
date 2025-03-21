#ifndef NODE_H
#define NODE_H
#include <string>

using namespace std;

class Node {
  int m_value;
  Node* m_parent;
  Node* m_left;
  Node* m_right;
 public:
  Node(int value);
  
  //
  bool hasBothChildren();
  bool hasLeftChild();
  bool hasRightChild();
  bool isLeftChild();
  
  //GETTERS AND SETTERS
  int getValue();
  Node* getLeft();
  Node* getRight();
  Node* getParent();
  
  void setLeft(Node* left);
  void setRight(Node* right);
  void setParent(Node* parent);
  void setValue(int value);
  
  ~Node();
};

#endif
