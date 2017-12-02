#pragma once
#ifndef _BTREE_H_
#define _BTREE_H_
#include <string>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class bTREE
{
    
protected:
        struct treeNode{
        string data;
        int time;
        bool issaLeaf;
        string hash;
        treeNode* left;
        treeNode* right;
    };
    
    queue<treeNode*> Qhelp;

private:
    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need
    int countOfNodes;
    int operations;
    treeNode* root;
    treeNode* left;
    treeNode* right;
    
    string locate(string, const treeNode*, string &move);

public:
    bTREE();
    ~bTREE();
    
    int dataInserted();
    int numberOfNodes();
<<<<<<< HEAD
<<<<<<< HEAD
    
    int operationsF();

    bool postOrderTraverse(treeNode *& subtree, string hash, bool & found);
    
=======

    bool postOrderTraverse(treeNode *& subtree, string hash, bool & found);
   
>>>>>>> 43dd654919b60dca6065cbbbac60c1d50804a3e0
=======

    bool postOrderTraverse(treeNode *& subtree, string hash, bool & found);
   
>>>>>>> 43dd654919b60dca6065cbbbac60c1d50804a3e0
    int insert(string, int);

	
    
    int find(string);
    
    string locate(string);
	string locateBranch(string);
    
    static void postorder( std::vector< short > & traversal,
                          const treeNode * subtree );
    
    friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    friend std::ostream& operator<<(std::ostream& out, const bTREE& p);
    
};
#endif
