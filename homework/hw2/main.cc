
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
    {
        cout << "unable to load dictionary" << endl;
        exit(-1);
    }
}

WordLadder::~WordLadder()
{
    
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
        
        
        for(auto it_dic = dictionary.begin(); it_dic != dictionary.end(); ++it_dic)
        {
            
            tem_stack = stack_queue.front();
            curr_top = tem_stack.top();
            strcpy(startword, curr_top.c_str());


            counter = 0;
            curr_dic = *it_dic;
            
            strcpy(word_curr, curr_dic.c_str());
            
            int i = 0;
            while(word_curr[i] != '\0')
            {
                
                if(word_curr[i] != startword[i])
                    ++counter;
                ++i;
            }
            
          
            //haven't reach the end word
            if(counter == 1)
            {
                
                newstack = tem_stack;
                
                newstack.push(*it_dic);

                stack_queue.push(newstack);
                
                //stack_queue.pop();

                it_dic = dictionary.erase(it_dic);
                
                
                
                
                
                if(*it_dic == end)
                {
                 
                    ladder.push_back(*it_dic);
                    string tem_str;
                    while(!tem_stack.empty())
                    {
                        tem_str = tem_stack.top();
                        
                        ladder.push_back(tem_str);
                        tem_stack.pop();
                    }
                    
                    
                    
                     
                    goto here;
                 
                }
                
                
            }

        }
        stack_queue.pop();
        

    }//end of while


    here:
    for(int i = ladder.size() - 1; i > -1; --i)
        cout  << ladder.at(i) << " ";

        
    if(ladder.size() == 0)
    {
        cout << "There is no word ladder from \"" << start << "\" to \"" << end << "\".\n";
    }
    else
        cout << endl;
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



int main( int argc, char* argv[] )
{
    if ( argc != 4 )
    {
        cout << "Usage: wordladder <dictionary_file> <start_word> <end_word>\n";
        exit(-1);
    }
    
    string dic_name = argv[1];
    string start_word = argv[2];
    string end_word = argv[3];
    
    WordLadder w1(dic_name);
    w1.outputLadder(start_word, end_word);
    
    return 0;
}