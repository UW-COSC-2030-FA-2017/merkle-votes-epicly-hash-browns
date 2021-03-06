#pragma once

#include "bTREE.h"
#include <string>
using namespace std;
class pMT
{
private:
    int selectedHash;
    bTREE myMerkle;
    
    string hash_1(string);
    string hash_2(string);
    string hash_3(string);
    
public:
    pMT(int);
    ~pMT();
    
    
    int insert(string, int);

	int find(string vote, int time, int hashSelect);
    
   
    int findHash(string);
    
    string locateData(string data);
	string locateHash(string data);
    
    friend bool operator==(const pMT& lhs, const pMT& rhs);
    
    friend bool operator!=(const pMT& lhs, const pMT& rhs);
    
    friend pMT operator^(const pMT& lhs, const pMT& rhs);
    friend std::ostream& operator<<(std::ostream& out, const pMT& p);
    
};

