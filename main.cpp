#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

int main(){
  Node* first = new Node(0);

  Node* left = new Node(1);
  first->setLeft(left);
  Node* leftleft = new Node(3);
  left->setLeft(leftleft);
  Node* leftleftleft = new Node(7);
  leftleft->setLeft(leftleftleft);
  Node* leftleftright = new Node(8);
  leftleft->setRight(leftleftright);
  Node* leftright = new Node(4);
  left->setRight(leftright);

  Node* right = new Node(2);
  first->setRight(right);
  Node* rightleft = new Node(5);
  right->setLeft(rightleft);
  Node* rightright = new Node(6);
  right->setRight(rightright);
  
  first->print(0,0);
  return 0;
}
