/*
NAME: Chaoyun Ma
SID: 605275
DATE: 04/13/2015 
*/

#ifndef __MYLIST_H__
#define __MYLIST_H__
#include <iostream>
#include <string.h>
using namespace std;

struct Node
{
    char value;
    Node *next;
    Node *pred;
    Node(char value): value(value), next(0), pred(0) {}
};

class MyList
{
    private:
        Node *head;
        unsigned length;
        
    public:
        MyList();
        MyList(const MyList& str);
        MyList(const string& str);
        MyList(const char* str);
        ~MyList();
        
        void push_front(char value);
        void push_back(char value);
        void pop_front();
        void pop_back();
        void swap(int i, int j);
        void insert_at_pos(int i, char value);
        void reverse();
        
        int size() const;
        void print() const;
        int find(char value) const;
        int find(MyList& query_str) const;
        
        MyList& operator=(const MyList& str);
        char& operator[](const int i);
        MyList& operator+(const MyList& str);
        
        
        

};





#endif