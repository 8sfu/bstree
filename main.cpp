#include <iostream>
#include <string>
#include "node.h"
#include "bstree.h"

using namespace std;

void delNode(Node* node){
  cout << node->getValue() << endl;
    if(node->isLeaf()){
      node = nullptr;
      cout << "isleaf" << endl;
    }else if(node->getRight() == nullptr){
      node = node->getLeft();
      cout << "hasleft" << endl;
    }else if(node->getLeft() == nullptr){
      node = node->getRight();
      cout << "hasright" << endl;
      cout << node->getValue() << endl;
      node->printNice("   ",2);
    }else{
      int value = node->getSuccessor()->getValue();
      node->getSuccessor() = nullptr;
      Node* successor = new Node(value);
      successor->setLeft(node->getLeft());
      successor->setRight(node->getRight());
      node = successor;
      
      successor->printNice("   ",2);
    }
}

int main(){
  Node* root = new Node(4);

  Node* left = new Node(2);
  root->setLeft(left);
  Node* leftleft = new Node(1);
  left->setLeft(leftleft);
  Node* leftright = new Node(3);
  left->setRight(leftright);
  Node* right = new Node(6);
  root->setRight(right);
  Node* rightleft = new Node(5);
  right->setLeft(rightleft);
  Node* rightright = new Node(7);
  right->setRight(rightright);
  
  /*int treeSize = 1000;
  srand(time(NULL));

  Node* root = new Node(treeSize/2);
  
  for(int i = 0; i < treeSize; i++){
  if(i != treeSize){
  root->addNode(new Node(rand()%treeSize));
  }
  }*/
  


  
  cout << endl << endl;
  string prev("   ");
  root->printNice(prev,2);
  cout << endl << endl;

  int check = 4;

  root->searchNode(check,true);
  
  cout << "inorder successor of " << check << " is " 
       << root->searchNode(check,false)->getSuccessor()->getValue() << endl;
  
  
  if(root->searchNode(check,false) != nullptr){
    cout << "needtodel" << endl;
    delNode(root->searchNode(check,false));
  }

  
  
  return 0;
}
