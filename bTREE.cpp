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

bool bTREE::postOrderTraverse(treeNode * & subtree, string hash, bool &found)
{
    if (subtree != NULL)
    {
        postOrderTraverse(subtree->left, hash, found);
        postOrderTraverse(subtree->right, hash, found);
        if (subtree->data.compare(s) == 0)
        {
            counterFind++;
            found = true;
        }
        
    }
    
    return found;
}

int bTREE::find(string someString){
    return find(someString);
}

string bTREE::locate(string data){
    string move = "";
    return locate(data, root, move);
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
