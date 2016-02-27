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
    cout << "stability: " << endl;
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