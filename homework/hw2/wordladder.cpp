
#include "wordladder.h"
#include <iostream>
#include <string.h>
#include <queue>
#include <stack>
#include <list>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <cstring>
using namespace std;


WordLadder::WordLadder(const string& listFile)
{
    if(!load_dic(listFile))
        cout << "unable to load dictionary" << endl;
    exit(-1);
}

WordLadder::~WordLadder()
{
    //while(!word_stack.empty())
    //    stack_queue.pop();
    //while(!stack_queue.empty())
    //    stack_queue.pop();
    while(!dictionary.empty())
        dictionary.pop_back();
    while(!ladder.empty())
        ladder.pop_back();
}



void WordLadder::outputLadder(const string& start,const string& end)
{
    stack<string> word_stack;
    word_stack.push(start);
    queue<stack<string>> stack_queue;
    stack_queue.push(word_stack);
    
    stack<string> tem_stack;
    char startword[10];
    //strcpy(startword, start.c_str());
    char word_curr[10];
    string curr_dic, curr_top;
    int counter = 0;
    
    stack<string> newstack;
    
    
    
    while(!stack_queue.empty())
    {
        //cout << rounds++ << endl;
        //cout << stack_queue.size() << endl;
        //int size_que = 0;
        //cout << "stack_queue size: " << size_que << endl;
        
        //tem_stack = stack_queue.front();
        ////cout << "~~~~ 1 ~~~~" << endl;
        //curr_top = tem_stack.top();
        ////cout << "~~~~ 2 ~~~~" << endl;
        //strcpy(startword, curr_top.c_str());
        ////cout << "~~~~ 3 ~~~~" << endl;
        
        for(auto it_dic = dictionary.begin(); it_dic != dictionary.end(); ++it_dic)
        {
            
            tem_stack = stack_queue.front();
            //cout << "~~~~ 1 ~~~~" << endl;
            curr_top = tem_stack.top();
            //cout << "~~~~ 2 ~~~~" << endl;
            strcpy(startword, curr_top.c_str());
            //cout << "~~~~ 3 ~~~~" << endl;
            
            
            
            //cout << "--for-loop-- " << for_loop++ << endl;
            again:
            counter = 0;
            curr_dic = *it_dic;
            //cout << "curr_dic: " << curr_dic;
            strcpy(word_curr, curr_dic.c_str());
            
            int i = 0;
            while(word_curr[i] != '\0')
            {
                //cout << "----word_dif----" << word_dif++ << endl;
                
                if(word_curr[i] != startword[i])
                    ++counter;
                ++i;
            }
            
            //you are done!!!
            if(*it_dic == end)
            {
                //cout << "end word reached: " << *it_dic << endl;
                
                string tem_str;
                while(!tem_stack.empty())
                {
                    tem_str = tem_stack.top();
                    //cout << tem_str << " ";
                    ladder.push_back(tem_str);
                    tem_stack.pop();
                }
                
                if(counter == 1)
                    ladder.push_back(*it_dic);
                    
                goto here;
                
            }
            
            //haven't reach the end word
            if(counter == 1)
            {
                //++word_found;
                //cout << "find a word " << *it_dic <<endl;
                //size_newstack_0 = newstack.size(); //2
                newstack = tem_stack;
                //size_newstack_1 = newstack.size(); //1
                newstack.push(*it_dic);
                //size_newstack_2 = newstack.size(); //2
                //cout << "size newstack " << size_newstack_0 << " " << size_newstack_1 << " "
                //     << size_newstack_2 << " " << endl;
                     
                //size_que = stack_queue.size();
                //cout << "size_que: " << size_que << endl; 
                stack_queue.push(newstack);
                //size_que = stack_queue.size();
                //cout << "size_que: " << size_que << endl;
                stack_queue.pop();
                //size_que = stack_queue.size();
                //cout << "size_que: " << size_que << endl;
                //cout << "newstack size: " << newstack.size() << "    stack_queue size: " 
                //     << stack_queue.size() <<endl;
                it_dic = dictionary.erase(it_dic);
                goto again;
            }
            
            
        
        }
        
        //int size_que = stack_queue.size();
        //cout << "stack_queue size: " << size_que << " ";
        //stack_queue.pop();
        //size_que = stack_queue.size();
        //cout << size_que << endl;
        //cout << "~~~~~~~ stack_queue size: " << stack_queue.size() << endl;
        //cout << "in one while loop: " << stack_queue.size() << endl; 
        
    }


    here:
    //cout << endl << "end of program. found: " << word_found << endl;
    //cout << "dictionary size: " << dictionary.size() << endl;
    
    int wordcount = 1;
    for(auto it = ladder.begin(); it != ladder.end(); ++it)
        cout << wordcount++ << ": "  << *it << endl;
    
}



bool WordLadder::load_dic(const string& dic_name)
{
    ifstream infile(dic_name.c_str());
    string read_word;
        
    if(infile.is_open())
    {
        
        while(getline(infile, read_word))
        {
            dictionary.push_back(read_word);    
        }
    
        infile.close();
        return true;
    }
    
    return false;
}

