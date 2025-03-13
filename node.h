#ifndef NODE_H
#define NODE_H

class Node {
  int value;
  Node* left;
  Node* right;
 public:
  Node(int setValue);
  void setLeft(Node* setLeft);
  void setRight(Node* setRight);
  int getValue();
  Node* getLeft();
  Node* getRight();
  void print(int depth,int state);
  ~Node();
};



#endif
