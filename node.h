#ifndef NODE_H
#define NODE_H
#include <string>

using namespace std;

class Node {
  int value;
  Node* left;
  Node* right;
 public:
  Node(int setValue);
  bool isLeaf();
  void setLeft(Node* setLeft);
  void setRight(Node* setRight);
  int getValue();
  Node* getLeft();
  Node* getRight();
  Node* getLeftMost();
  Node* getSuccessor();

  void addNode(Node* addNode);
  Node* searchNode(int check, bool print);
  void deleteNode(int check);
  void print(int depth);
  void printNotString(int depth, int state);
  void printNice(string prev, int isLeft);
  ~Node();
};



#endif
