// chaoyun ma
// 605275
// assignment 4

#include "mymap.h"
#include <iostream>
using namespace std;
int main() 
{
    mymap<string,int> ml;
    ml["January"] = 31;
    ml["February"] = 28;
    ml["March"] = 31;
    ml["April"] = 30;
    ml["May"] = 31;
    ml["June"] = 30;
    ml["July"] = 31;
    ml["August"] = 31;
    ml["September"] = 30;
    ml["October"] = 31;
    ml["November"] = 30;
    ml["December"] = 31;
    cout << ml.find("April")->second << endl; 
    cout << ml.find("Yam")->second << endl; 
    cout << ml["May"] << endl;
    cout << (ml.find("Yam") == ml.end()? "miss" : "hit") << endl;
    cout << ml["Yam"] << endl;
    cout << (ml.find("Yam") == ml.end()? "miss" : "hit") << endl; 
    
}