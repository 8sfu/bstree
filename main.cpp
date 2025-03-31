/* A Binary Search Tree written mostly by Aman Tesfu

   main.cpp contains the general program logic
   node.cpp and .h create, control, and define node objects
   tree.cpp and .h allow for manipulation of those nodes in
   a basic binary tree structure.
   f.txt is a list of numbers from 1 to 999 that can be
   randomly added to a tree for people who don't like to
   manually input thousands of numbers.
   
   I produced all code in this project with the exception of
   three function prototypes, which were named by ChatGPT
   after GPT was prompted to generate function prototypes.
   ChatGPT was used, in effect, to assist with English and
   communication- not programming. See the following prompts.
   Note that I wrote all code in those functions independently.
   
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
#include <vector>
#include <fstream>
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

vector<int>* getInputVec(){
  int intput; //intput keeps track of new values to be added to the tree
  vector<int>* inputVec = new vector<int>(); //inputvec holds all values
  cout << "Enter a list of space separated numbers." << endl;
  while(cin.peek() != '\n'){
    if(cin.peek() == ' '){
      cin.ignore();
      cin.clear();
    }else{
      intput = getIntput();
      if(intput >= 0 && intput < 1000){
        inputVec->push_back(intput);
      }else{
        cout << intput << " is not a valid input." << endl;
      }
    }
  }
  cin.clear();
  cin.ignore(1024,'\n');
  return inputVec;
}

vector<int>* getFileVec(){
  int intput; //intput keeps track of the total number of values to add to the tree
  vector<int>* fileVec = new vector<int>(); //filevec stores all values
  fstream f;
  f.open("f.txt",fstream::in);
  cout << "How many numbers would you like to pull from the file?" << endl;
  intput = getIntput();
  int fullArr[1000];
  for(int i = 0; i < 999; i++){
    f >> fullArr[i];
  }
  for(int i = 0; i < intput; i++){
    fileVec->push_back(fullArr[rand()%999]);
  }
  return fileVec;
}


int main(){
  srand(time(NULL));
  char* input = new char[20]; //Cstring and int input vars
  int intput;
  Tree* tree = new Tree(nullptr); //Initialize new tree with no root

  cout << "Welcome to Binary Search Tree.";
  
  while(true){ 
    cout << "Would you like to add, search, delete, or print nodes to the tree or restart or quit? ";
    cout << "(add) or (search) or (delete) or (print) or (restart) or (quit)" << endl;
    cin.getline(input,20);
    
    if(cmp(input,"add")){
      cout << "Would you like to add numbers manually or from a file? ";
      cout << "(manual) or (file)" << endl;
      cin.getline(input,20);
      
      vector<int>* numbers; //use vectors of numbers pulled from a file or manual input
      if(cmp(input,"manual")){
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
      }else if(cmp(input,"file")){
	numbers = getFileVec();
        for(int i = 0; i < numbers->size(); ++i){ //add values to the tree
	  tree->addNode(new Node((*numbers)[i]));
        }
      }
    }else if(cmp(input,"search")){ //search for nodes in tree
      cout << "What number would you like to search for?" << endl;
      cout << "Enter numbers one at a time." << endl;
      intput = getIntput();
      if(tree->hasVal(intput)){
	cout << intput << " is in the tree." << endl;
      }else{
	cout << intput << " is not in the tree." << endl;
      }
    }else if(cmp(input,"delete")){ //delete nodes from tree
      cout << "What number would you like to delete?" << endl;
      cout << "Enter numbers one at a time." << endl;
      intput = getIntput();
      if(tree->hasVal(intput)){
	tree->deleteVal(intput);
	cout << intput << " has been deleted." << endl;
      }else{
	cout << intput << " is not in the tree." << endl;
      }
    }else if(cmp(input,"print")){ //print tree
      tree->printTree();
    }else if(cmp(input,"restart")){ //wipe tree
      tree->wipe();
    }else if(cmp(input,"quit")){ //quit program
      return 0;
    }
  }
  return 0;
}
