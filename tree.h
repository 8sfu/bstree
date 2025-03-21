#ifndef TREE_H
#define TREE_H
#include "node.h"

class Tree {
private:
  Node* m_root;
  Node* delFromTree(Node* node);
public:
  Tree(Node* root);
  Node* getRoot();
  void addNode(Node* node);
  bool hasVal(int value);
  void deleteVal(int value);
  void printTree();
  ~Tree();
};

#endif
