// chaoyun ma
// 605275
// assignment 7
#ifndef DFS_H
#define DFS_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dfs( vector< vector< bool > >& adjacency, unsigned start = 0 )
{
    if(adjacency.size() == 0)
        return;
    
    static int recursionDepth = 0; // only gets initialized once per run. 
    ++recursionDepth; // incremented once per invocation.
    
    // body of the code goes here
    static map<unsigned, bool> visited;
    visited[start] = true;

    unsigned i = 0;
    while(i != adjacency[0].size())
    {
        if(adjacency[start][i])
        {
            if(visited[i] == false)
                dfs(adjacency,i);
        
            else
                adjacency[start][i] = false;
        }
        
        ++i;
    }
    
    
    --recursionDepth; // returns to value as of this invocation. 
    if ( recursionDepth == 0 ) 
    { 
        // This invocation was first, so ...
        visited.clear();
        // re-initialize visited before returning.
    }
    
}

#endif