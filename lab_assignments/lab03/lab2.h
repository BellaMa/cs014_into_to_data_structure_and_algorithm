/*
NAME: Chaoyun Ma
SID: 605275
DATE: 04/13/2015 
*/

#ifndef __LAB2_H__
#define __LAB2_H__
#include <iostream>
#include <forward_list>
using namespace std;

template<typename T>
struct Node {
    T data;    //type is T
    Node<T> *next;
    Node(T data): data(data), next(0) {}

};

template<typename T>
class List {
    private:
    Node<T> *tail;
    Node<T> *head;
    
    public:
    List() {
        head = 0;
        tail = 0;
    }
    
    ~List(){
        while(head != 0)
        {   
            pop_front();
        }
    }
    
    
    void push_back(T value) { //type is T
            Node<T>* tem = new Node<T>(value);
            if(tail == 0)
            {
                head = tem;
                tail = tem;
                return ;
            }
            tail->next = tem;
            tail = tem;
    }
    
    void pop_front(){
        if(head == 0)
            return ;
        
        Node<T> *tem = head;
        head = head->next;
        delete tem;
        if(head == 0)
            tail = head;
    }
    
    void display() {
        if(head == 0)
             return ;
        
        Node<T> *tem = 0; 
        for(tem = head; tem->next != 0;tem = tem->next)
        {
             cout <<tem->data << " ";
        }
        cout << tem->data;
    }
    
    void elementSwap( int pos){
        if(head == 0)
            return;
            
        if(head->next == 0)
            return;
        
        Node<T> * tem = head;
        int i = 0;
        while(i < (pos - 1))
        {
            ++i;
            tem = tem->next;
        }
        
        Node<T> * tem_pos = tem->next;
        tem->next = tem_pos->next;
        tem_pos->next = tem->next->next;
        tem->next->next = tem_pos;
        
        if(tem_pos->next == 0)
            tail = tem_pos;
        
    }
    
        
};



#endif