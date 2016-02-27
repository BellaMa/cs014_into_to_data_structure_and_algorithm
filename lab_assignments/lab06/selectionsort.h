// Chaoyun Ma
// 605275
// may 17, lab5

#ifndef _LAB5__H_
#define _LAB5__H_

#include <iostream>
#include <utility>
using namespace std;


template<typename L>
void selectionsort(L &l)
{
    int counter = 0;

    for(auto it = l.begin(); it != l.end(); )
    {
        auto tem_min = it;
        // cout << "it: " << *it << " tem_min: " << *tem_min; 
        for(auto tem_it = it; tem_it != l.end(); ++tem_it)
        {
            if(*tem_min > *tem_it)
                tem_min = tem_it;
        }
        if(tem_min != it)
        {
            swap(*tem_min, *it);
            ++counter;
        }
        
        ++it;
        

    }

    cout << "0 copies and " << (counter * 3) << " moves" << endl;
};

#endif