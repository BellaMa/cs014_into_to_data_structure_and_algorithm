/*
NAME: Chaoyun Ma
SID: 605275
DATE: 04/13/2015 
*/

#ifndef __WORDLADDER_H_
#define __MYLIST_H__

#include <iostream>
#include <string.h>
#include <queue>
#include <stack>
#include <list>
#include <vector>
using namespace std;

class WordLadder
{
    private:
       //stack<string> word_stack;
        //queue<stack> stack_queue;
        list<string> dictionary;
        vector<string> ladder;
    
    public:
        WordLadder(const string& listFile);
        ~WordLadder();
        
        void outputLadder(const string& start, const string& end);
        
    private:
        bool load_dic(const string& dic_name);
        //bool construct_ladder(const string& start, const string& end);
};



#endif