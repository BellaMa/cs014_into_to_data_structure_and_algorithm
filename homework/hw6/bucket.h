// chaoyun ma
// 605275
// assignment 6

#ifndef _BUCKET__H_
#define _BUCKET__H_

#include <vector>
#include <iostream>
using namespace std;

void InsertionSort( vector<unsigned> &num)
{
     int i, j, key;
     int numLength = num.size() ;
     for(j = 1; j < numLength; j++)    // Start with 1 (not 0)
    {
           key = num[j];
           for(i = j - 1; (i >= 0) && (num[i] > key); i--)   // Smaller values move up
          {
                 num[i+1] = num[i];
          }
         num[i+1] = key;    //Put key into its proper location
     }
     return;
}

void bucketsort( vector<unsigned>& vctr2Bsrtd, int loadfactor = 20 )
{
    int vec_size = vctr2Bsrtd.size()/loadfactor;
    if(vec_size == 0)
        vec_size = 1;
    
    vector<vector<unsigned> > bucket(vec_size);
    
    // find the max value
    int max = vctr2Bsrtd.at(0);
    for(unsigned i = 0; i < vctr2Bsrtd.size(); ++i)
    {
        if(max < vctr2Bsrtd.at(i))
            max = vctr2Bsrtd.at(i);
    }
    
    // put each element into according bucket
    // there are vec_size buckets
    int factor = max / vec_size;
    for(unsigned i = 0; i < vctr2Bsrtd.size(); ++i)
    {
        int index  = vctr2Bsrtd.at(i) / factor;
        if(index >= vec_size)
            index = vec_size -1;
            
        bucket.at(index).push_back(vctr2Bsrtd.at(i));
    }
    
    
    
    // using insertion sort 
    // Ascending Order
    for(unsigned i = 0; i < vec_size; ++i)
    {
        InsertionSort(bucket.at(i));
    }
    
    // put it back togather
    int index = 0;
    for(unsigned i = 0; i < vec_size; ++i)
    {
        for(unsigned j = 0; j < bucket.at(i).size(); ++j)
            vctr2Bsrtd.at(index++) = bucket.at(i).at(j);
    }


    /*// just for testing
    cout << "size of income vector:     " << vctr2Bsrtd.size() << endl
         << "size of the bucket vector:     " << bucket.size() << endl;
    for(int i = 0; i < bucket.size(); ++i)
    {
        cout << "size of the bucket.at(" << i << "):    " << bucket.at(i).size() << endl;
    }*/
  
    
}



#endif