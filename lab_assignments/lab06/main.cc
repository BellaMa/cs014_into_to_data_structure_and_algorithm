// Chaoyun Ma
// 605275
// may 17, lab5

#include "selectionsort.h"
#include <iostream>
#include <utility>
#include <vector>
#include <map>
using namespace std;



int main()
{
    
    vector<int> test1 = {2, 4, 5, 1, 8, 9};
    cout << "pre: ";
    for(auto i = test1.begin(); i != test1.end(); ++i)
        cout << *i << " ";
    cout << endl ;
    selectionsort(test1);
    cout << "post: ";
    for(auto i = test1.begin(); i != test1.end(); ++i)
        cout << *i << " ";
    cout << endl ;
    cout << endl; 
    
    
    
    vector<pair<int, int>> test2 ;
    test2.push_back(make_pair(1,2));
    test2.push_back(make_pair(3,-1));
    test2.push_back(make_pair(-1,3));
    test2.push_back(make_pair(0,0));
    test2.push_back(make_pair(2,3));
    test2.push_back(make_pair(1,2));
    test2.push_back(make_pair(1,-2));
    test2.push_back(make_pair(8,10));
    cout << "pre: ";
    for(auto i = test2.begin(); i != test2.end(); ++i)
    {
        cout << "(" << i->first << ", " << i->second << ") ";
    }
    cout << endl;
    selectionsort(test2);
    cout << "post: ";
    for(auto i = test2.begin(); i != test2.end(); ++i)
    {
        cout << "(" << i->first << ", " << i->second << ") ";
    }
    cout << endl;
    
    
 
    cout << endl << "stability: " << endl;
    vector<int> test3 = {1, 1, 1, 1, 1};
    cout << "pre: ";
    for(auto i = test3.begin(); i != test3.end(); ++i)
        cout << *i << " ";
    cout << endl ;
    selectionsort(test3);
    cout << "post: ";
    for(auto i = test3.begin(); i != test3.end(); ++i)
        cout << *i << " ";
    cout << endl ;
 
    return 0;
}
