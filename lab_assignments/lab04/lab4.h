// Chaoyun Ma
// 605275
// May 1
#ifndef __LAB4_H__
#define __LAB4_H__

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


#include<algorithm>

typedef pair<int,int> Entry;
class priority_queue
{
    public:
        vector<Entry> entries;
        Entry& front() { return entries.back(); }
        void pop() { entries.pop_back(); }
        void push( Entry e )
        { 
            entries.push_back( e );
            for(int i = entries.size()-1; i != 0; --i ) 
            {
                if ( (entries[i].first + entries[i].second) < (entries[i-1].first + entries[i-1].second)  ) break;  // replace this comparison with code for comparing int pairs.
                swap(entries[i], entries[i-1]);
            }
        }
};

struct Node
{
    int l;
    int r;
    Node* le;
    Node* mid;
    Node* ri;
    Node(int m, int n) : l(m), r(n), le(0), mid(0), ri(0) {}
};

struct Root
{
    Node* left;
    Node* right;
    
    Root() : left(0), right(0) {}
};

class MyTree{
    
    public:
        priority_queue for_sorted_order;
        
        MyTree(Root& root)
        { }
        
        void make_a_tree(Root& root, int max)
        {
            
            root.left = new Node(2,1);
            root.right = new Node(3,1);
            
            Node* curr = root.left;
            making_tree(curr, max); // make the left subtree
            curr = root.right;
            making_tree(curr, max);
            
            
        }
        
        //recursivly make a subtree
        void making_tree(Node* curr, int max)
        {
            int m = curr->l;
            int n =curr->r;
            
            //left subtree
            if((3 * m - n) <= max)
            {   
                curr->le = new Node((2 * m - n), m);
                Entry tem((2 * m - n), m);
                for_sorted_order.push(tem);
                making_tree(curr->le, max);
            }
            
            //mid subtree
            if((3 * m + n) <= max)
            {
                curr->mid = new Node((2 * m + n), m);
                Entry tem((2 * m + n), m);
                for_sorted_order.push(tem);
                making_tree(curr->mid, max);
            }
            
            //right subtree
            if((m + 3 * n) <= max)
            {
                curr->ri = new Node((m + 2 * n), n);
                Entry tem((m + 2 * n), n);
                for_sorted_order.push(tem);
                making_tree(curr->ri, max);
            }

            return;
        }
        
        void print(Node* curr)
        {
            cout << curr->l << " " << curr->r << endl;
        }


        void pre_order(Root& root)
        {
            pre(root.left);
            pre(root.right);
        }
        void pre(Node* curr)
        {
            if(curr == 0)
                return;
            
            print(curr);
            pre(curr->le);
            pre(curr->mid);
            pre(curr->ri);
        }
        
        
        
        void post_order(Root& root)
        {
            post(root.left);
            post(root.right);
        }
        void post(Node* curr)
        {
            if(curr == 0)
                return;
            
            post(curr->le);
            post(curr->mid);
            post(curr->ri);
            print(curr);
        }
        
        void sorted()
        {
            
            while(!for_sorted_order.entries.empty())
            {
                
                Entry tem = for_sorted_order.front();
                cout << tem.first << " " << tem.second << endl;
                for_sorted_order.pop();
            }
        }
    
};
#endif