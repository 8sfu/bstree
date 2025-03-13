#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Node::Node(int setValue){
  value = setValue;
  left = nullptr;
  right = nullptr;
}

void Node::setLeft(Node* setLeft){
  left = setLeft;
}

void Node::setRight(Node* setRight){
  right = setRight;
}

int Node::getValue(){
  return value;
}

Node* Node::getLeft(){
  return left;
}

Node* Node::getRight(){
  return right;
}



void Node::print(int depth,int state){
  if(left != nullptr){
    left->print(depth+1,1);
  }
  for(int i = 0; i < depth-1; i++){
    cout << "     ";
  }
  if(state == 1){
    cout << "Γ--- ";
  }else if(state == 2){
    cout << "L--- ";
  }
  cout << value << endl;
  if(right != nullptr){
    right->print(depth+1,2);
  }
}

Node::~Node(){
  delete[] left;
  delete[] right;
}
