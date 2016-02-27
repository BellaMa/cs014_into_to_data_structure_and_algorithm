// chaoyun ma
// 605275
// assignment 6

#include "bucket.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;

int main()
{
    srand(time(NULL));
    vector<unsigned> test;
    for(int i = 0; i < 100; ++i)
    {
        
        int tem = rand() % 100 + 1;
        test.push_back(tem);
    }
    
    
    for(unsigned i = 0; i < test.size(); ++i)
    {
        cout << test.at(i) << " ";
        if((i != 0) && ((i % 10) == 0))
            cout << endl;
    }
    cout << endl;
    
    // use buck sort
    bucketsort(test, 10);
    cout << endl << "after sorting: " << endl;
    for(unsigned i = 0; i < test.size(); ++i)
    {
        cout << test.at(i) << " ";
        if((i != 0) && ((i % 10) == 0))
            cout << endl;
    }
    cout << endl;
    
    return 0;
}