///////////////
// Jeremy Reynolds
// Final Project
//
//

#include "bTREE.h"
#include <queue>


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE(){
    root == NULL;
    int height = 0;
    countOfNodes = 0;
}

bTREE::~bTREE(){
    delete (root);
}

int bTREE::dataInserted(){
    return dataInserted();
}

int bTREE::numberOfNodes(){
    int c = 0;
    return c;
}

void bTREE::postorder( std::vector< short > & traversal,
                       const treeNode * subtree )
{
    if( subtree != NULL )
    {
        postorder( traversal, subtree->left );
        postorder( traversal, subtree->right );
        traversal.push_back(subtree->entry);
    }
}


int bTREE::insert(string data, int time){

    treeNode* node = new treeNode;
    node->data = data;
    node->time = time;
    node->left = NULL;
    node->right = NULL;
    
    if (root == NULL){
        countOfNodes++;
        root = node;
    }
    
        treeNode* temp = Qhelp.front();
        if (!temp->left){
            temp->left = node;
            Qhelp.push(node);
          
        }else{
            temp->right = node;
            Qhelp.push(node);
            Qhelp.pop();
}
    return countOfNodes;
}

int bTREE::find(string someString){
    return find(someString);
}

string bTREE::locate(string x, string){
    string empty = " ";
    return locate(x, empty);
}

 bool operator ==(const bTREE& lhs, const bTREE& rhs){
         if(lhs == rhs){
             return true;
         }else{
             return false;
         }
     }

bool operator !=(const bTREE& lhs, const bTREE& rhs){
        if(lhs != rhs){
            return true;
        }else{
            return false;
        }
    }

std::ostream& operator <<(std::ostream& out, const bTREE& p){
}
