// Chaoyun Ma
// 605275
// May 11
#ifndef LAB5_H
#define LAB_H
#include <cassert> 
#include <iostream> 
#include <fstream> 
#include <cstdlib> 
#include <string> 
#include <sstream> 
#include <map> 
#include <list> 
#include <math.h>
#include <algorithm>    // std::max
#include <vector>

using namespace std; 
#define nil 0


// #define Value int 
// restore for testing. 
template <typename Value>
class BST 
{
    public:
    class Node 
    { 
        // binary tree node 
        public:
            Node* left;
            Node* right;
            Value value;
            bool selected = false;
            
            Node(const Value v = Value())
            {
                value = v;
                left = nil;
                right = nil;
                selected = false;
            }
            
            Node()
            {
                value = Value();
                left = nil;
                right = nil;
                
            }
            
            Value& content() 
            {
                return value; 
            }
            
            bool isInternal() 
            {
                return left != nil && right != nil; 
            } 
            
            bool isExternal() 
            {
                return left != nil || right != nil; 
            } 
            
            bool isLeaf() 
            {
                return left == nil && right == nil; 
            }
            
            int height() 
            {
                // returns the height of the subtree rooted at this node
                // FILL IN 1
                
                if(isLeaf()) 
                    return 0;
                
                return max(left->height(), right->height()) + 1;
            }
            
            int size() 
            {
                // returns the size of the subtree rooted at this node,
                // FILL IN 2
                
                // if(isLeaf())
                //     return 1;   // leaf' size is 1
                    
                if(this == 0)
                    return 0;
                    
                int leftsize = left->size();
                int rightsize = right->size();
                
                return (leftsize + rightsize + 1);
                
            }
            
            
        
            // helper function
            bool search(Value x)
            {
                if(this->value == x)
                    return true;
                else if(this->value > x)
                {
                    if(left == 0)
                        return false; 
                    else
                        return left->search(x);
                }
                else if(this->value < x)
                {
                    if(right == 0)
                        return false;
                    else
                        return right->search(x);
                }   
                
                return false;
            }
        
        
            void pre()
            {
                //if(isLeaf())
                if(this == 0)
                {
                    //cout << value << " ";
                    return;
                }
                cout << this->value << " ";
                this->left->pre();
                this->right->pre();
            }
            
            
            void ino()
            {
                if(this == 0)
                {
                    //cout << value << " ";
                    return;
                }
                
                left->ino();
                cout << value << " ";
                right->ino();
            }
            
            
            void post()
            {
                if(this == 0)
                {
                    //cout << value << " ";
                    return;
                }
                
                left->post();
                right->post();
                cout << value << " ";
            }
        
            Value& find(int n) 
            {
                
                Node *tem = this;
                
                if (n > (size() - 1)) 
                {
                    cout << "error: out of range =.=" << endl;
                    return value;
                }
                else if (tem->left->size() == n) 
                {
                    return value;
                }
                else if (tem->left->size() > n) 
                {
                    return tem->left->find(n);
                }
                else 
                {
                    return tem->right->find(n - tem->left->size() - 1);
                }
            }
                    
            void minCover()
            {
                if(this == 0)
                    return;
                    
                if(isLeaf())
                    return;
                    
                if(!isLeaf())
                    selected = true;
    
                left->minCover();
                right->minCover();
            }
            
            
            void displayMinCover()
            {
                if(this == 0)
                    return;
                
                
                if(selected == true)
                    cout << value << " ";
                    
                left->displayMinCover();
                right->displayMinCover();
                
                
            }
            
            
           
            
            
            
    };  //end of Node class defination and function implement






      // const Node* nil; 
      // later nil will point to a sentinel node.
      // still in private part!!!
      Node* root; 
      int count;

    public:
        Node* treeRoot()
        {
            return root;
        }
        
        void vertSum(Node* n, int hd, std::map<int,int>& m)
        {
            if(n == 0)
                return;
            m[hd] += n->value;
            vertSum(n->left, hd - 1, m);
            vertSum(n->right, hd + 1, m);
        }
        void printVerticalOrder()
        {
            // map<int, vector<int>> m;
            map<int, int> m;
            int hd = 0;
            vertSum(root, hd, m);
            for(auto it=m.begin(); it!=m.end(); it++)
            {
                // int sum = 0;
                // for (int i=0; i< it->second.size(); ++i)
                // {
                //     sum += it->second[i];
                // }
                // cout << sum << " ";
                cout << it->second << " ";
            }
            
            cout  << endl; 
        }
        
        

        
        void findSumPath(Node* n,int sum, int* buffer)
        {
            if(n == 0)
            {
                cout << "0" << endl;
                return;
            }
            int times = 0;
            findPath(root, sum, buffer, buffer, &times);
            
            if(times == 0)
                cout << "0" << endl;

            
        }
        
        void findPath(Node* curr, int sum, int buffer[], int* tem, int* times)
        {
            if(curr == 0)
            {
                if(buffer == tem)
                    return;
                    
                int tem_sum = 0;
                for(int *i = buffer; i != tem; ++i)
                {
                    tem_sum += *i;
                }
                
                if(sum == tem_sum)
                {
                    ++(*times);
                    for(int *i = buffer; i != tem; ++i)
                    {
                        cout << *i << " ";
                    }
                    
                    cout << endl;
                }
                
                --tem;
                return;
            }
            
            findPath(curr->left, sum, buffer, tem, times);
            *tem = curr->value;
            ++tem;
            findPath(curr->right, sum, buffer, tem, times);
            
        }
        
        
        
        void minCover()
        {
            if(root == 0)
                return ;
                
            root->minCover();
        }
        void displayMinCover()
        {
            minCover();
            
            if(root == 0)
                return;
            root->displayMinCover();
            cout << endl;
        }
    
    
        int size() 
        {
            // size of overall tree
            // FILL IN 3
            
            if(root == 0)       // if it is an empty tree
                return 0;
            
            return root->size();         
            
        }
        
        bool empty() 
        { return size() == 0; }   // implicit parameter is root
        
        void print_node(const Node* n)
        {
            //print the nose's value
            // FILL IN 4
            
            cout << n->value;
            
        }
        
        bool search(Value x)
        {
            //search for a Value in the BST and return true iff it was found
            // FILL IN 5
            
            if(root == nil)
                return false;
            
            return root->search(x);
            
        }
        
        void preorder() const
        {
            //traverse and print the tree one Value per line in preorder
            // FILL IN 6
            
            root->pre();
        }
        
        
        void postorder() const
        {
            //traverse and print the tree one Value per line in postorder
            // FILL IN 7
            
            root->post();
        }
        
        void inorder() const
        {
            //traverse and print the tree one Value per line in inorder
            // FILL IN 8
            
            root->ino();
        }
        
        Value& operator[] (int n)
        {
            //return referwnce to the value field of the n-th Node
            // FILL IN 9
            
            if(size() < n)
                exit(-1);
            
            
             
            return root->find(n);
            
        }
        
        // BST()   //constructor for BST
        //  : count(0), root(nil) 
        // {}
        
        BST()
        {
            count = 0;
            root = nil;
        }
        
        
        void insert(Value X) 
        { root = insert( X, root ); }
        
        Node* insert(Value X, Node* T) 
        {
            // The normal binary-tree insertion procedure ... 
            if(T == nil)
            {
                T = new Node(X); // the only place that T gets updated.
            } 
            else if(X < T->value) 
            {
                T->left = insert(X, T->left);
            } 
            else if(X > T->value) 
            {
                T->right = insert(X, T->right); 
                
            } else 
            {
                T->value = X; 
            }
        
            // later, rebalancing code will be installed here    
            
            return T;
        }
        
        
        void remove(Value X) 
        { root = remove( X, root ); }
        
        Node* remove(Value X, Node*& T) 
        {
            // The normal binary-tree removal procedure ... 
            // Weiss’s code is faster but way more intricate. 
            if( T!=nil)
            {
                if ( X > T->value ) 
                {
                    T->right = remove( X, T->right );
                } 
                else if ( X < T->value )
                { 
                    T->left = remove( X, T->left );
                } 
                else    // X == T->value
                {
                    if ( T->right != nil ) 
                    {
            
                        Node* x = T->right;
                        while ( x->left != nil ) 
                            x = x->left;
                        T->value = x->value; // successor’s value 
                        T->right = remove( T->value, T->right );
                    } 
                    else if ( T->left != nil ) 
                    {
                        Node* x = T->left;
                        while ( x->right != nil ) 
                            x = x->right;
                        T->value = x->value; // predecessor’s value
                        T->left = remove( T->value, T->left );
                    } 
                    else // *T is external
                    {
                        delete T;
                        T = nil;   // the only updating of T
                    }
                }
            }
 
            // later, rebalancing code will be installed here
        
            return T; 
            
        }
        
        
        
        void okay( ) 
        { 
            okay(root); 
            
        } 
        
        void okay(Node* T) 
        {
            // diagnostic code can be installed here
            return; 
            
        }
};  // BST


#endif
