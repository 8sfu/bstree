/* A Binary Search Tree written mostly by Aman Tesfu

   main.cpp contains the general program logic
   node.cpp and .h create, control, and define node objects
   tree.cpp and .h allow for manipulation of those nodes in
   a basic binary tree structure.
   
      
   I produced all code in this project with the exception of
   three function prototypes, which were named by ChatGPT
   after GPT was prompted to generate function prototypes.
   ChatGPT was used, in effect, to assist with English and
   communication- not programming. See the following prompts.

   'What are some traits of a communicative C++ function
   prototype?'

   'Create a prototype for a free function where 'Node*
   parent' and 'Node* child' are respectively passed in.'

   'Create a prototype for a function that returns a Node*
   to the leftmost child of a 'Node* node', which is passed
   in.'

   'And a void prototype to delete a Node from a tree with
   said Node, 'Node* node' passed in.'
   
   
*/ 

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include "node.h"
#include "tree.h"

using namespace std;

bool cmp(char* input, const char* checkAgainst){ //simplify input to cstring comparison
  if(!strcasecmp(input,checkAgainst)){
    return true;
  }
  return false;
}

int getIntput(){ //Bugfix for infinite loops created by char inputs where int was expected
  int intput;
  cin >> intput; cin.ignore();
  while(cin.fail()){ //Repeatedly asks for int input until a valid one is given
    cout << "That is not an int. Please input an int." << endl;
    cin.clear();
    cin.ignore(1024,'\n');
    cin >> intput; cin.ignore();
  }
  return intput;
}

int numFromChar(char* input){
  int i = 0;
  double num = 0.0;
  while(input[i] != '\0'){
    num += ((int)input[i]-48)*pow(10.0,-1*i); 
    i++;
  }
  return num*pow(10,i-1);
}

int main(){
  char* input = new char[200];
  int intput;
  Tree* tree = new Tree(nullptr);

  cout << "Welcome to Binary Search Tree. This program currently lacks comments or";
  cout << " compatibility with file input." << endl;
  
  while(true){
    cout << "Would you like to add, search, delete, or print nodes to the tree or quit?";
    cout << "(add) or (search) or (delete) or (print) or (quit)" << endl;
    cin.getline(input,20);
    
    if(cmp(input,"add")){
      cout << "Enter a list of space separated numbers to add to the tree." << endl;
      cin.getline(input,200);
      char* token;
      int i = 0;
      
      token = strtok(input," ");
      while(token != NULL){
	intput = numFromChar(token);
	if(intput > 0 && intput < 1000){
	  tree->addNode(new Node(intput));
	}
	i++;
	token = strtok(NULL," ");
      }
    }else if(cmp(input,"search")){
      cout << "What number would you like to search for?" << endl;
      cout << "Enter numbers one at a time." << endl;
      intput = getIntput();
      if(tree->hasVal(intput)){
	cout << intput << " is in the tree." << endl;
      }else{
	cout << intput << " is not in the tree." << endl;
      }
    }else if(cmp(input,"delete")){
      cout << "What number would you like to delete?" << endl;
      cout << "Enter numbers one at a time." << endl;
      intput = getIntput();
      if(tree->hasVal(intput)){
	tree->deleteVal(intput);
	cout << intput << " has been deleted." << endl;
      }else{
	cout << intput << " is not in the tree." << endl;
      }
    }else if(cmp(input,"print")){
      tree->printTree();
    }else if(cmp(input,"quit")){
      return 0;
    }
  }
  cout << "program complete." << endl;
  return 0;
}
