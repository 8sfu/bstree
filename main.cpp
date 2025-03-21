#include <iostream>
#include <string>
#include "node.h"
#include "tree.h"

using namespace std;

int main(){
    
    Tree* tree = new Tree(nullptr);
    
  int treeSize = 30;
  srand(time(NULL));
  
  for(int i = 0; i < treeSize; i++){
    if(i != treeSize){
      tree->addNode(new Node(rand()%treeSize));
    }
  }
  
    tree->printTree();
    
    int intput = 4;

    if(tree->hasVal(intput)){
        cout << intput << " is in the tree." << endl;
        tree->deleteVal(intput);
    }else{
    cout << intput << " is not in the tree." << endl;
    }
  
    tree->printTree();
  
    cout << "program complete." << endl;
    return 0;
}
