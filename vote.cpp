#include <stdio.h>
#include "pMT.h"
#include "bTREE.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
    pMT comparison(1);
    string data, time;
    ifstream issaFile ("test1.txt");
    if (issaFile.is_open())
    {
        while ( issaFile >> data >> time)
        {
            istringstream buffer(time);
            int time_val = 0;
            buffer >> time_val;
            cout << comparison.insert(data, time_val) << endl;
        }
        issaFile.close();
    }
    else cout << "Cannot open the file";
    
    cout << comparison << endl;
    
    pMT comparison2(1);
    string data1, time1;
    ifstream issaFile2 ("test1.txt");
    if (issaFile2.is_open())
    {
        while ( issaFile2 >> data1 >> time1)
        {
            istringstream buffer(time1);
            int time_val = 0;
            buffer >> time_val;
            cout << comparison2.insert(data1, time_val) << endl;
        }
        issaFile2.close();
    }
    else cout << "Cannot open the file";
    
    
    cout << comparison2 << endl;
    
    
    cout << (comparison ^ comparison2) << endl;
    
    return 0;
}
