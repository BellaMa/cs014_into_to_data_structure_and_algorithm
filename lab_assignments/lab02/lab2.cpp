/*
NAME: Chaoyun Ma
SID: 605275
DATE: April 20, 2015
*/

#include <iostream>
#include <forward_list>
#include "lab2.h"
#include <vector>
using namespace std;



bool isPrime(int i)
{
    if(i == 1 || i == 2)
        return true;
    

    for(int x = 2; x <= (1 + (i / 2)); ++x)
    {
        if((i % x) == 0)
        {
            return false;
        }
    }
    
    return true;
}


int primeCount(forward_list<int> list)
{
    if(list.empty())
        return 0;
    
    int tem = list.front();
    if(isPrime(tem))
    {
        list.pop_front();
        return primeCount(list) + 1;
    }
    
    list.pop_front();
    return primeCount(list);
}

template<typename T>
void listCopy(forward_list<T> L, forward_list<T>& P ) 
{
    L.reverse();
    P.reverse();
    for(auto it = L.begin(); it != L.end(); ++it)
    {
        P.push_front(*it);
    }
    
    P.reverse();
}


template<typename T>
void printLots (forward_list<T> L, forward_list<int> P) 
{
    vector<int> pos;
    for(auto it_max = P.begin(); it_max != L.end(); ++it_max)
    {
        pos.push_back(*it_max);
    }
    
    int len = pos.size();
    
    
    int size = 0;
    for(auto it = L.begin(); it != P.end(); ++it)
    {
        ++size;
    }
   
    if(size < pos.at(len - 1))
    {
        cout << "size: " << size << " " << pos.at(len - 1) << endl;
        cout << "T.T" << endl; 
        return;
    }
    
    P.sort();
    for(auto it_P = P.begin(); it_P != P.end(); ++it_P)
    {
        int i = *it_P;
        int counter = 0;
        auto it_L = L.begin();
        while(counter < i)
        {
            ++counter;
            ++it_L;
        }
        cout << *it_L << " ";
    }
    
    cout << endl;
    
    
    
}




int main(){
    forward_list<int> list = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    
    cout << "problem 1" << endl;
    cout << "list is { " ;
    for(auto it = list.begin(); it != list.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "}" << endl << primeCount(list) << "   prime numbers?  should be 4." << endl;

    forward_list<int> list_3_1 = {1, 2, 3, 4, 5};
    forward_list<int> list_3_2 = {11, 12, 13, 14, 15, 16};
   
    
    cout << endl << "problem 2" << endl;
    cout << "list is { " ;
    List<int> list_2;
    for(int i = 0; i < 5; ++i)
    {
        list_2.push_back(10*i);
    }
    list_2.display();
    cout << "} " << endl;
    
    cout << "swap at 2: " << endl;
    list_2.elementSwap(2);
    cout << "new list is { ";
    list_2.display();
    cout << "}" ;
    cout << endl;


    
    cout << endl << "problem 3" << endl;
    cout << "list L: ";
    for(auto it = list_3_1.begin(); it != list_3_1.end(); ++it)
    {
        cout << * it << " ";
    }
    cout << endl << "list P: ";
    for(auto it = list_3_2.begin(); it != list_3_2.end(); ++it)
    {
        cout << * it << " ";
    }
    cout << endl << "list P + inverse L: " << endl;
    
    listCopy(list_3_1, list_3_2);
    for(auto it = list_3_2.begin(); it != list_3_2.end(); ++it)
    {
        cout << * it << " ";
    }
    cout << endl;
    
    cout << endl << "problem 4:" << endl;
    forward_list<int> list_4_1 = {1, 2, 3, 4, 5, 6, 7, 8};
    forward_list<int> list_4_pos = {0, 3, 2};
    cout << "list L: ";
    for(auto it = list_4_1.begin(); it != list_4_1.end(); ++it)
    {
        cout << * it << " ";
    }
    cout << endl << "list P: ";
    for(auto it = list_4_pos.begin(); it != list_4_pos.end(); ++it)
    {
        cout << * it << " ";
    }
    cout << endl << "at L, element specified at P: " << endl; 
    list_4_pos.sort();
    printLots(list_4_1, list_4_pos);

    return 0;
}
