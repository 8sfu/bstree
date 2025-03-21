#include <iostream>
#include "tree.h"

Tree::Tree(Node* root){
  m_root = root;
}

Node* Tree::getRoot(){
  return m_root;
}

void attachChild(Node* parent, Node* child){
  if(child != nullptr){
    if(child->getValue() < parent->getValue()){
      if(parent->getLeft() == nullptr){
	parent->setLeft(child);
	child->setParent(parent);
      }else{
	attachChild(parent->getLeft(),child);
      }
        }else{
      if(parent->getRight() == nullptr){
	parent->setRight(child);
	child->setParent(parent);
      }else{
	attachChild(parent->getRight(),child);
      }
    }
  }
}

void print(Node* node, string prev, bool isLeft){
  if(isLeft){
    if(node->getRight() != nullptr){
      print(node->getRight(),prev+" | ",false);
    }
    cout << prev << " L " << node->getValue() << endl;
    if(node->getLeft() != nullptr){
      print(node->getLeft(),prev+"   ",true);
    }
  }else{
    if(node->getRight() != nullptr){
      print(node->getRight(),prev+"   ",false);
    }
    cout << prev << " Γ " << node->getValue() << endl;
    if(node->getLeft() != nullptr){
      print(node->getLeft(),prev+" | ",true);
    } 
  }
}

Node* searchSubTree(Node* node, int value){
  if(node->getValue() == value){
    return node;
  }else{
    if(value < node->getValue()){
      if(node->getLeft() == nullptr){
	return nullptr;
      }
      return searchSubTree(node->getLeft(),value);
    }else{
      if(node->getRight() == nullptr){
	return nullptr;
      }
      return searchSubTree(node->getRight(),value);
    }
  }
}

Node* leftmostChildOf(Node* node){
  if(node->getLeft() == nullptr){
    return node;
  }else{
    return leftmostChildOf(node->getLeft());
  }
}

Node* successorOf(Node* node){
  if(node->getRight() == nullptr){
    //We don't need to worry about proper inorder traversal yet.
  }
  return leftmostChildOf(node->getRight());
}

Node* Tree::delFromTree(Node* node){
  if(node->hasBothChildren()){ //Node has both children
    node->setValue(successorOf(node)->getValue());
    m_root = delFromTree(successorOf(node));
    return m_root;
  }else if(node->hasLeftChild()){ //Node has one child (left)
    if(node->getParent() != nullptr){
      if(node->isLeftChild()){
	node->getParent()->setLeft(node->getLeft());
      }else{
	node->getParent()->setRight(node->getLeft());
      }
      return m_root;
    }
    return m_root->getLeft();
  }else if(node->hasRightChild()){ //Node has one child (right)
    if(node->getParent() != nullptr){
      if(node->isLeftChild()){
	node->getParent()->setLeft(node->getRight());
      }else{
	node->getParent()->setRight(node->getRight());
      }
      return m_root;
    }
    return m_root->getRight();
  }else{ //Node is a leaf
    if(node->getParent() != nullptr){
      if(node->isLeftChild()){
	node->getParent()->setLeft(nullptr);
      }else{
	node->getParent()->setRight(nullptr);
      }
      return m_root;
    }
    return nullptr;
  }
}

void Tree::addNode(Node* node){ 
  if(m_root == nullptr){
    m_root = node;
  }else{
    attachChild(m_root,node);
  }
}

bool Tree::hasVal(int value){
  if(searchSubTree(m_root,value) != nullptr){
    return true;
  }
  return false;
}

void Tree::deleteVal(int value){
  while(this->hasVal(value)){
    m_root = delFromTree(searchSubTree(m_root,value));
  }
}

void Tree::printTree(){
  cout << endl;
  if(m_root != nullptr){
    if(m_root->getRight() != nullptr){
      print(m_root->getRight(),"      ",false);
    }
    cout << " Root: " << m_root->getValue() << endl;
    if(m_root->getLeft() != nullptr){
      print(m_root->getLeft(),"      ",true);   
    }
  }else{
    cout << "The tree is empty." << endl;
  }
  cout << endl;
}

Tree::~Tree(){
  delete[] m_root;
}
