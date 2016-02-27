// chaoyun ma
// 605275
// assignment 4

#ifndef _MYMAP__H_
#define _MYMAP__H_

#include <iostream>
#include <set>

using namespace std;

template<typename Key, typename T >
class map_pair {
    public:
    const Key first;
    mutable T second;
    map_pair(Key s, T t) : first(s), second(t) {}
};

template<typename Key, typename T >
struct classcomp {
    typedef map_pair<const Key, T> Pair;
    bool operator() (const Pair& lhs, const Pair& rhs) const {
        return lhs.first < rhs.first;
    }
};


template<typename Key, typename T>
class mymap
{
    public:
        typedef map_pair<const Key, T> Pair;
        typedef set<Pair, classcomp<const Key, T>> PairSet;

        
        PairSet theSet;
        
        mymap()
        { }
        
       
        mymap(const mymap & newmap)
        {
            theSet = newmap.theSet;
        }
        
        
        mymap& operator= (const mymap& newmap)
        {
            
            theSet = newmap.theSet;
            return *this;
        }
        
        ~mymap()
        { }
        
        pair<typename PairSet::iterator, bool> insert(Pair p)
        {
            return theSet.insert(p);
        }
        
        T& operator[] (const Key x)
        {
            pair<typename PairSet::iterator, bool> i = insert(Pair(x,T()));
            return i.first->second;
        }
        
        typename PairSet::iterator find(const Key& x) const
        {
            return theSet.find(Pair(x,T()));
        }
        
        typename PairSet::iterator end()
        {
            return theSet.end();
        }
        
};


#endif