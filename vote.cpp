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
    ifstream myfile ("test1.txt");
    if (myfile.is_open())
    {
        while ( myfile >> data >> time)
        {
            istringstream buffer(time);
            int time_val = 0;
            buffer >> time_val;
            cout << comparison.insert(data, time_val) << endl;
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    
    cout << comparison << endl;
    
    pMT comparison2(1);
    string data1, time1;
    ifstream myfile2 ("test1.txt");
    if (myfile2.is_open())
    {
        while ( myfile2 >> data1 >> time1)
        {
            istringstream buffer(time1);
            int time_val = 0;
            buffer >> time_val;
            cout << comparison2.insert(data1, time_val) << endl;
        }
        myfile2.close();
    }
    else cout << "Unable to open file";
    
    
    cout << comparison2 << endl;
    
    
    cout << (comparison ^ comparison2) << endl;
    
    return 0;
}
