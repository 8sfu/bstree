#include <iostream>
#include <string>
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

void Node::setValue(int setValue){
  value = setValue;
}

Node* Node::getLeft(){
  return left;
}

Node* Node::getRight(){
  return right;
}

bool Node::isLeaf(){
  if(left == nullptr && right == nullptr){
    return true;
  }
  return false;
}

Node* Node::getLeftMost(){
  if(left == nullptr){
    return this;
  }else{
    return left->getLeftMost();
  }
}

Node* Node::getSuccessor(){
  Node* successor = nullptr;
  if(right == nullptr){
    return nullptr;
  }
  successor = right->getLeftMost();
  return successor;
}


void Node::addNode(Node* addNode){
  if(addNode->getValue() < value){
    if(left == nullptr){
      left = addNode;
    }else{ 
      left->addNode(addNode);
    }
  }else if(addNode->getValue() >= value){
    if(right == nullptr){
      right = addNode;
    }else{
    right->addNode(addNode);
    }
  }
}

Node* Node::searchNode(int check, bool print){
  if(value == check){
    if(print){
      cout << check << " is in this tree." << endl;
    }
    return this;
  }else if(value > check){
    if(left != nullptr){
      return left->searchNode(check,print);
    }else{
      if(print){
	cout << check << " is not in the tree." << endl;
      }
      return nullptr;
    }
  }else{
    if(right != nullptr){
      return right->searchNode(check,print);
    }else{
      if(print){
	cout << check << " is not in the tree." << endl;
      }
      return nullptr;
    }
  }
}

void Node::print(int depth){
  if(left != nullptr){
    left->print(depth+1);
  }for(int i = 0; i < depth; i++){
    cout << "   ";
  }
  cout << value << endl;
  if(right != nullptr){
    right->print(depth+1);
  }
}

void Node::printNotString(int depth,int state){
  if(left != nullptr){
    left->printNotString(depth+1,1);
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
    right->printNotString(depth+1,2);
  }
}

void Node::printNice(string prev, int isLeft){
  if(isLeft == 0){
    if(right != nullptr){
      right->printNice(prev + "|  ",1);
    }
    cout << prev << " L " << value << endl;
    if(left != nullptr){
      left->printNice(prev + "   ",0);
    }
  }
  else if(isLeft == 1){
    if(right != nullptr){
      right->printNice(prev + "   ",1);
    }
    cout << prev << " Γ " << value << endl;
    if(left != nullptr){
      left->printNice(prev + "|  ",0);
    }
  }
  if(isLeft == 2){
    if(right != nullptr){
      right->printNice(prev,1);
    }
    cout << prev << value << endl;
    if(left != nullptr){
      left->printNice(prev,0);
    }
  }
}
  
Node::~Node(){
  delete[] left;
  delete[] right;
}
