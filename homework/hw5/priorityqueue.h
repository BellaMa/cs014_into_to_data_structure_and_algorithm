// choayun ma
// 605275
// may 13, 2015

#ifndef _PRIORITYQUEUE__H_
#define _PRIORITYQUEUE__H_
#include <iostream>
#include <map>
using namespace std;

template<typename Priority, typename Item>
class priority_queue:public multimap<Priority,Item>
{
    public:
        
        priority_queue()
        {}
        
        priority_queue(const priority_queue<Priority, Item>& rhs)
        {
            *this = rhs;
        }
        
        Item& front()
        {
            if(this->empty())
            {
                cout << "empty queue" << endl;
            
                exit(-1);
            }
        
            // tem_it is the highest priority iterator
            typename multimap<Priority, Item>::iterator it, tem_it;
            tem_it = this->begin();
            for( it  = this->begin(); it != this->end(); ++it)
            {
                if(it->first > tem_it->first)
                    tem_it = it;
            }
            
            return tem_it->second;
        }
        
        void pop()
        {
            if(this->empty())
            {
                // cout << "empty queue" << endl;
                return;
            }
        
            // tem_it is the highest priority iterator
            typename multimap<Priority, Item>::iterator it, tem_it;
            tem_it = this->begin();
            for( it  = this->begin(); it != this->end(); ++it)
            {
                if(it->first > tem_it->first)
                    tem_it = it;
            }
            this->erase(tem_it);
        }
        
        void push(Item x, Priority p)
        {
            this->insert(pair<Priority, Item>(p,x));
        }
        
        priority_queue& operator= (const priority_queue<Priority, Item>& rhs)
        {
            if(this != &rhs)
            {
                // typename multimap<Priority, Item>::iterator it;
                for(auto it = rhs.begin(); it != rhs.end(); ++it)
                {
                    this->insert(pair<Priority, Item>(it->first, it->second));
                }
            }
            
            return *this;
        }
};


#endif