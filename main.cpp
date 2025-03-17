#include <iostream>
#include <string>
#include "node.h"

using namespace std;

/*void delNode(Node* node){
  cout << node->getValue() << endl;
  if(node->isLeaf()){
    node = nullptr;
    cout << "isleaf" << endl;
  }else if(node->getRight() == nullptr){
    node = node->getLeft();
    cout << "hasleft" << endl;
    node->printNice("   ",2);
  }else if(node->getLeft() == nullptr){
    node = node->getRight();
    cout << "hasright" << endl;
    
    cout << node->getValue() << endl;
    node->printNice("   ",2);
  }else{

  }
  }*/

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
  
  /*  int treeSize = 100;
  srand(time(NULL));
  
  Node* root = new Node(treeSize/2);
  
  for(int i = 0; i < treeSize; i++){
    if(i != treeSize){
      root->addNode(new Node(rand()%treeSize));
    }
    }*/
  
  cout << endl << endl;
  root->printNice("   ",2);
  cout << endl << endl;

  int check = 4;

  if(root->searchNode(check,true) != nullptr
     && root->searchNode(check,false)->getSuccessor() != nullptr){
    cout << "inorder successor of " << check << " is " 
	 << root->searchNode(check,false)->getSuccessor()->getValue() << endl;
  }

  int i = 20;
  while(root->searchNode(check,false) != nullptr && i){
    root->searchNode(check,false)->deleteNode();
    root->printNice("   ",2);
    i--;
  }
  
  return 0;
}
