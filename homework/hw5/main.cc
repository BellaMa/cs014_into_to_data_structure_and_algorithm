// choayun ma
// 605275
// may 13, 2015

#include "priorityqueue.h"
#include <iostream>
#include <map>
using namespace std;
int main()
{
    priority_queue<float,int> pri;
    priority_queue<float,int> pri_tem;
    pri.insert(pair<float,int>(30.0,1));
    pri.insert(pair<float,int>(10.0,2));
    pri.insert(pair<float,int>(1.0,3));
    
    
    
    cout << "priority_queue is the following:  <Priority, Item>" << endl;
    for(auto it  = pri.begin(); it != pri.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    
    cout << endl << "Item& front() with get: (the highest priority item)" << pri.front() << endl;
    
    cout << endl << "after pop(), new priority_queue is: <Priority, Item>" << endl;
    pri.pop();
    for(auto it  = pri.begin(); it != pri.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    
    cout << endl << "push(4, 0.5), new priority_queue is: <Priority, Item>" << endl;
    pri.push(4, 0.5);
    for(auto it  = pri.begin(); it != pri.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    
    cout << endl << "copy constructor" << endl;
    priority_queue<float,int> copy_tem(pri);
    for(auto it  = copy_tem.begin(); it != copy_tem.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    
    cout << endl << "assignment operator =" << endl;
    pri_tem = pri;
    for(auto it  = pri_tem.begin(); it != pri_tem.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    
    return 0;
 }