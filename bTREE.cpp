///////////////
// Jeremy Reynolds
// Final Project
//
//

#include "bTREE.h"
#include <queue>


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE(){
    root = NULL;
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

int bTREE::operationsF(){
    return operations;
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

bool bTREE::postOrderTraverse(treeNode * & subtree, string hash, bool &exists)
{
    if (subtree != NULL)
    {
        postOrderTraverse(subtree->left, hash, exists);
        postOrderTraverse(subtree->right, hash, exists);
        if (subtree->data.compare(hash) == 0)
        {
            exists = true;
            operations++;
        }
        
    }
    
    return exists;
}

int bTREE::find(string someString){
    
    bool exists = false;
    operations++;
    return postOrderTraverse(root, someString, exists);
}

string bTREE::locate(string data){
    string move = "";
	bool exists = false;
	postOrderTraverse(root, data, exists);
	if (move.compare("") == 0)
	{
		return ".";
	}
	else
	{
		string move2 = move;
		int j = 0;
		for (int i = move.length(); i > 0; i--)
		{
			move2.at(j) = move.at(i - 1);
			j++;
		}

		return move2;
	}

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

