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
    return countOfNodes;
}


int bTREE::insert(string data, int time){
    queue<treeNode* >Q;
    treeNode* node = new treeNode;
    node->data = data;
    node->time = time;
    node->left = NULL;
    node->right = NULL;
    
    if (root == NULL){
        countOfNodes++;
        root = node;
    }
    while(!Q.empty()){
        treeNode* temp = Q.front();
        Q.pop();
        
        if (!temp->left){
            temp->left = node;
            break;
        }else {
            Q.push(temp->left);
        }if(!temp->right){
            temp->right = node;
            break;
        }else{
            Q.push(temp->right);
        }
        
    }
    return 0;
}

int bTREE::find(string someString){
    return find(root, someString);
}

string bTREE::locate(string x, string){
    string empty = " ";
    return locate(x, empty);
}

 bool operator ==(const bTREE& lhs, const bTREE& rhs){
     {
         if(lhs == rhs){
             return true;
         }else{
             return false;
         }
     }

bool operator !=(const bTREE& lhs, const bTREE& rhs){
    {
        if(lhs != rhs){
            return true;
        }else{
            return false;
        }
    }}

std::ostream& bTREE::operator <<(std::ostream& out, const bTREE& p){
}
