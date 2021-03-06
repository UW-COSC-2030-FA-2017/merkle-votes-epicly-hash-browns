
#include "pMT.h"
#include <iostream>
#include <string>

pMT::pMT(int hashSelect)
/**
 * @brief 
 * @param hashSelect a number corresponding to the hashfunction to use for this pMT
 * @return 
 */
{
    bTREE newTree;
    selectedHash = hashSelect;
    
    switch(hashSelect){
        case 1: selectedHash = 1;
            break;
        case 2: selectedHash = 2;
            break;
        case 3: selectedHash = 3;
    }
}

pMT::~pMT()
/**
 * @brief destructor
 * @return nada
 */
{
    
}

int pMT::insert(string vote, int time)
/**
 * @brief insert a vote and time into a leaf node of tree
 * @param vote - a string
 * @param time - an int representing the time 
 * @return the number of operations needed to do the insert, -1 if out of memory
 */

{
    switch(selectedHash){
            
        case 1: myMerkle.insert(hash_1(vote), time);
            break;
        case 2: myMerkle.insert(hash_2(vote), time);
            break;
        case 3: myMerkle.insert(hash_3(vote), time);
            break;
    }
    
    return myMerkle.dataInserted();
}

int pMT::find(string vote, int time, int hashSelect)
/**
 * @brief given a vote, timestamp, and hash function, does this vote exist in the tree?
 * @param vote, a string
 * @param time, an int
 * @param hashSelect, an int corresponding to the hash functions _1, _2, and _3
 * @return 0 if not found, else number of opperations required to find the matching vote
 */
{
    int operation = 0;
    if (1 == (find(vote, time, selectedHash))){
        return operation++;
    }else{
        return operation;
    }
    
}

int pMT::findHash(string mhash)
/**
 * @brief does this hash exist in the tree?
 * @param mhash, a string to search for in the tree
 * @return 0 if not found, else number of opperations required to find the matching hash
 */
{
    if (myMerkle.find(mhash))
        return myMerkle.operationsF();
    else
        return 0;
}


string pMT::locateData(string vote)
/**
 * @brief Function takes a hash of Vote and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root. 
 * @param vote, the data to search for 
 * @return sequence of L's and R's comprising the movement to the leaf node; else return a dot '.'
 */
{
    string dataLocation = myMerkle.locate(vote);
	return dataLocation;
}

string pMT::locateHash(string mhash)
/**
 * @brief Function takes a hash and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root. 
 * @param mhash, the hash to search for 
 * @return sequence of L's and R's comprising the movement to the hash node, ; else return a dot '.'
 */
{
	string hashLocation = myMerkle.locate(mhash);
	return hashLocation;
}



string pMT::hash_1(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
        unsigned int h=0;
        const int len = key.length()/2+1;
        for (int i=0; i<len;){
            h=h*i+key[i];
            i+=2;
        }
    string t = to_string(h%33);
    
        return t;
}

string pMT::hash_2(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 * RSHash from http://www.partow.net/programming/hashfunctions/index.html
 */
{
    unsigned int a = 378551;
    unsigned int b = 63689;
    unsigned int hash = 0;
    
    for(size_t i = 0; i < key.length(); i++)
    {
        hash = hash * a + key[i];
        a = a * b;
    }
    
    return to_string(hash);
    
    
}
    
string pMT::hash_3(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
    unsigned int val = 0;
    for(int i = 0; i < key.length(); i++){
        val +=(unsigned int)(key[i]);
    }
        string p = to_string(val);
    return p;
}

bool operator ==(const pMT& lhs, const pMT& rhs)
/**
 * @brief Comparison between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if equal, false otherwise
 */
{
    if(lhs.myMerkle == rhs.myMerkle){
        return true;
    }else{
        return false;
    }
}

bool operator !=(const pMT& lhs, const pMT& rhs)
/**
 * @brief Comparison between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if not equal, false otherwise
 */
    {
        if(lhs.myMerkle != rhs.myMerkle){
            return true;
        }else{
            return false;
        }
    }

  
// Change to a print function
std::ostream& operator <<(std::ostream& out, const pMT& p)
/**
 * @brief Print out a tree
 * @param out
 * @param p
 * @return a tree to the screen
 */
{   cout << p.myMerkle;
    return out;
}


