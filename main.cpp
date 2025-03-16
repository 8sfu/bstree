#include <iostream>
#include <string>
#include "node.h"
#include "bstree.h"

using namespace std;

void delTree(Node* root,int check){
  if(root->getValue() == check){
    if(root->isLeaf()){
      root = nullptr;
    }else if(root->getRight() == nullptr){
      root = root->getLeft();
    }else if(root->getLeft() == nullptr){
      root = root->getRight();
    }else{
      Node* newRoot = root->getSuccessor();
      newRoot->setLeft(root->getLeft());
      newRoot->setRight(root->getRight());
      root = newRoot;
    }
  }else{
    if(root->searchNode(check,false)){
      cout << "Need 3 case deletion still." << endl;
    }
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

  int check = 6;

  root->searchNode(check,true);
  
  cout << "inorder successor of " << check << " is " 
       << root->searchNode(check,false)->getSuccessor()->getValue() << endl;
  
  delTree(root,check);

  root->printNice("   ",2);
  
  return 0;
}
