#include "bTREE.h"


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
}

bTREE::~bTREE()
{
}

int bTREE::dataInserted()
{
    return -1;
}

int bTREE::numberOfNodes()
{
    return -1;
}

int bTREE::insert(string data, int time) //changed from 'int' to 'bool'
{
    return -1;
}

int bTREE::find(string) //changed from 'int' to 'bool'
{
    return -1;
}

string bTREE::locate(string)
{
    return "";
}

bool operator==(const bTREE& lhs, const bTREE& rhs)
{
    return true;
}

bool operator !=(const bTREE& lhs, const bTREE& rhs)
{
    return true;
}

std::ostream& operator <<(std::ostream& out, const bTREE& p)
{
    return out;
}
