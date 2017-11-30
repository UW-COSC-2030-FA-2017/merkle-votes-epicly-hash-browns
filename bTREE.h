#pragma once

#include <string>
using namespace std;

class bTREE
{
protected:
        struct treeNode{
        string data;
        int time;
        bool issaLeaf;
        treeNode* left;
        treeNode* right;
        
    };
    
private:
    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need
    int countOfNodes;
    treeNode* root;
    treeNode* left;
    treeNode* right;

public:
    bTREE();
    ~bTREE();
    
    int dataInserted();
    int numberOfNodes();
    
    int insert(string, int);
    
    int find(string);
    
    string locate(string, string);
    
    
    friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    friend std::ostream& operator<<(std::ostream& out, const bTREE& p);
    
};

