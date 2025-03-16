#include <iostream>
#include <string>
#include "node.h"

using namespace std;

int main(){
  int treeSize = 89;
  srand(time(NULL));

  Node* first = new Node(treeSize*3);
  
  for(int i = 1; i < treeSize; i++){
    if(i != treeSize / 2){
      first->addNode(new Node(rand() % treeSize*6));
    }
  }
  
  cout << endl << endl;
  string prev("   ");
  first->printNice(prev,2);
  cout << endl << endl;
  
  return 0;
}
