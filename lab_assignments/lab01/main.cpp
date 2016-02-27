#include <iostream>
#include <list>
#include<string>
using namespace std;


template<typename T>
void mergeSortList(list<T> &list1, list<T> &list2)
{
    typename list<T>::iterator i;
    typename list<T>::iterator j ;
    
    T a,b;
    i = list1.begin();
    j = list2.begin();
    while(i != list1.end())
    {
        a = *i;
        b = *j;
        if((j != list2.end()) && (a > b))
        {
            list1.insert(i, b);
            ++j;
            ++i;
        }
        else
            ++i;
        
    }
    while(j != list2.end())
        list1.push_back(*j++);

}

template<typename T>
void rotate(list<T> &list_0, unsigned n)
{
    list<T> list_tem = list_0;
    list_0.clear();
    typename list<T>::iterator it;
    int i = n;
    if(n < list_tem.size())
    {
        for(it = list_tem.begin(); it != list_tem.end(); ++it)
        {
            if(i != 0)
                --i;
            else
                list_0.push_back(*it);    
        }
        for(it = list_tem.begin(); it != list_tem.end(); ++it)
        {
            if(i < n)
            {
                ++i;
                list_0.push_back(*it);
            }
        }
    }
}


template <typename T>
void mergeList(list<T> &list1, list<T> list2)
{
    typename list<T>::iterator i;
    typename list<T>::iterator j;
    /*list<int>::iterator i;
    list<int>::iterator j;
    list<int> list_new;*/
    
    i = list1.begin();
    j = list2.begin();
    
   while(i != list1.end())
    {
        ++i;
        if(j != list2.end())
        {
            list1.insert(i,*j);
            ++j;
        }
    }
    
    while(j != list2.end())
    {
        list1.push_back(*j++);
    }
    

}

int main()
{
    list<int> list1, list2, list1_1, list2_2;
    int in;
    cout << "input list1, end with -1" << endl;
    cin >> in;
    while(in != -1)
    {
        list1.push_back(in);
        cin >> in;
    }
    cout << "input list2, end with -1" << endl;
    cin >> in;
    while(in != -1)
    {
        list2.push_back(in);
        cin >> in;
    }
    list1_1 = list1;
    list2_2 = list2;
    
    mergeList(list1, list2);
    cout << "mergeList"<<endl;
    list<int>::iterator it;
    for(it = list1.begin(); it != list1.end(); ++it)
    cout << *it << " ";
    cout << endl << endl;
    
    
    mergeSortList(list1_1, list2_2);
    cout << "mergeSortList"<< endl;
    for(it = list1_1.begin(); it != list1_1.end(); ++it)
    cout << *it << " ";
    cout << endl << endl;
    
    
    rotate(list1_1, 3);
    cout << "mergeSortList rotate by 3"<< endl;
    for(it = list1_1.begin(); it != list1_1.end(); ++it)
    cout << *it << " ";
    cout << endl;
    return 0;
}