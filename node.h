#ifndef NODE_H
#define NODE_H
#include <string>

using namespace std;

class Node {
  int value;
  Node* parent;
  Node* left;
  Node* right;
 public:
  Node(int setValue);
  bool isLeaf();
  bool hasLeftChild();
  bool hasRightChild();
  bool isRoot();
  bool isLeftChild();
  bool hasBothChildren();
  void setLeft(Node* setLeft);
  void setRight(Node* setRight);
  void setParent(Node* setParent);
  int getValue();
  void setValue(int value);
  Node* getLeft();
  Node* getRight();
  Node* getParent();
  Node* getLeftMost();
  Node* getSuccessor();

  void addNode(Node* addNode);
  void deleteNode();
  Node* searchNode(int check, bool print);
  void deleteNode(int check);
  void print(int depth);
  void printNotString(int depth, int state);
  void printNice(string prev, int isLeft);
  ~Node();
};



#endif
