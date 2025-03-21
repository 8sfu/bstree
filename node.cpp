#include <iostream>
#include <string>
#include "node.h"

using namespace std;

Node::Node(int value){
  m_value = value;
  m_parent = nullptr;
  m_left = nullptr;
  m_right = nullptr;
}

Node* Node::getLeft(){
  return m_left;
}

Node* Node::getRight(){
  return m_right;
}

Node* Node::getParent(){
  return m_parent;
}

int Node::getValue(){
  return m_value;
}

void Node::setLeft(Node* left){
    m_left = left;
    if(left != nullptr){
        left->setParent(this);
    }
}

void Node::setRight(Node* right){
    m_right = right;
    if(right != nullptr){
      right->setParent(this);
    }
}

void Node::setParent(Node* parent){
  m_parent = parent;
}

void Node::setValue(int value){
  m_value = value;
}

bool Node::hasBothChildren(){
  if(m_left != nullptr && m_right != nullptr){
    return true;
  }
  return false;
}

bool Node::hasLeftChild(){
  if(m_left != nullptr){
    return true;
  }
  return false;
}

bool Node::hasRightChild(){
  if(m_right != nullptr){
    return true;
  }
  return false;
}

bool Node::isLeftChild(){
  if(m_value < m_parent->getValue()){
    return true;
  }
  return false;
}
  
Node::~Node(){
    delete[] m_parent;
    delete[] m_left;
    delete[] m_right;
}
