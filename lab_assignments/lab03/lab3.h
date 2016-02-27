/*
NAME: Chaoyun Ma
SID: 605275
DATE: 04/13/2015 
*/

#ifndef __LAB3_H__
#define __LAB3_H__
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class TwoStackFixed 
{
    private:
        T* arr = 0;
        
        T* tail1 = 0;
        T* tail2 = 0;
        
        T* top1 = 0;
        T* top2 = 0;
        
        //curr points to the pos in which it store the newest value
        T* curr1 = 0;
        T* curr2 = 0;
        
        int sz = 0;
        
    public:
        TwoStackFixed(int size, int maxtop )
        {
            
            if(size <= 0)
            {
                 cout << "error: size needs to be larger than 0" << endl;
                 exit(-1);
            }
            if(maxtop < 0)
            {
                cout << "error: max needs to be larger than 0" << endl;
                exit(-1);
            }
            if(maxtop > size)
            {
                cout << "error: max cannot be larger than size" << endl;
                exit(-1);
            }
            
            arr = new T[size];
            sz = size;
            
            tail1 = arr;
            tail2 = arr + size - 1;
            
            top1 = arr + maxtop - 1;
            top2 = top1 + 1;
            
            curr1 = 0;
            curr2 = 0;
            
        }
        ~TwoStackFixed()
        {
            delete[] arr;
        }
        
        
        
        void pushStack1(T value)
        {
            if(isFullStack1())
            {
                cout << "stack 1 is full already" << endl;
                return;
            }
            if(isEmptyStack1())
            {
                curr1 = tail1;
                *curr1 = value;
                
                //cout << "pushStack1~" << endl;
                return;
            }   
            ++curr1;
            *curr1 = value;
            
            //cout << "pushStack1~" << endl;
            
        }
        
        void pushStack2(T value)
        {
            if(isFullStack2())
            {
                cout << "stack 2 is full already" << endl;
                return;
            }
            if(isEmptyStack2())
            {
                curr2 = tail2;
                *curr2 = value;
                
                //cout << "pushStack2~" << endl;
                return;
            } 
            --curr2;
            *curr2 = value;
            
            //cout << "pushStack2~" << endl;
        }
        

        T popStack1()
        {
            if(isEmptyStack1())
            {
                cout << "error: stack 1 is empty" << endl;
                exit(-1);
            }
            
            T* tem = curr1;
            if(curr1 == tail1) //goint to be empty
                curr1 = 0;
            else
                --curr1;
            return *tem;
            
        }
        
        T popStack2()
        {
            if(isEmptyStack2())
            {
                cout << "error: stack 2 is empty" << endl;
                exit(-1);
            }
            T* tem = curr2;
            if(curr2 == tail2) //going to be empty
                curr2 = 0;
            else 
                ++curr2;
            return *tem;
        }
        
        
        void printStack1()
        {
            cout << "print first stack, unallocate pos will be whitespace" << endl;
            
            if(isEmptyStack1())
            {
                for(T* tem = tail1; tem != top2; ++tem)
                {
                    cout << " " << endl;
                }
            }
            else
            {
                T* tem;
                for(tem = curr1 + 1; tem != top2; ++tem)
                {
                    cout << " " << endl;
                }
                for(tem = curr1; tem > tail1; --tem)
                {
                    cout << *tem << endl;
                }
                cout << *tem << endl;
            }
        }
        
        
        void printStack2()
        {
            cout << "print second stack, unallocate pos will be whitespace" << endl;

            if(isEmptyStack2())
            {
                for(T* tem = tail2; tem != top1; --tem)
                    cout << " " << endl;
            }
            else
            {
                T* tem;
                for(tem = curr2 - 1; tem != top1; --tem)
                {
                    cout << " " << endl;
                }
                for(tem = curr2; tem < tail2; ++tem)
                    cout << *tem << endl;
                cout << *tem << endl;
            }
                
        }
        
        
        bool isFullStack1()
        {
            if(curr1 == top1)
                return true;
            
            return false;
        }
        
        bool isFullStack2()
        {
            if(curr2 == top2)
                return true;
            
            return false;
        }
        
        bool isEmptyStack1()
        {
            if(curr1 == 0)
                return true;
                
            return false;
        }
  
        bool isEmptyStack2()
        {   
            if(curr2 == 0)
                return true;
                
            return false;
        }
        
        
       
};




template<typename T>
class TwoStackOptimal
{
    private:
        T* arr = 0;
        
        T* tail1 = 0;
        T* tail2 = 0;
        
        //T* top1 = 0;
        //T* top2 = 0;
        
        //curr points to the pos in which it store the newest value
        //current top
        T* curr1 = 0;
        T* curr2 = 0;
        
        int sz = 0;
    
    public:
        TwoStackOptimal(int size)
        {
            if(size <= 0)
            {
                 cout << "error: size needs to be larger than 0" << endl;
                 exit(-1);
            }
            
            arr = new T[size];
            
            tail1 = arr;
            tail2 = arr + size - 1;
            
            sz = size;
        }
        ~TwoStackOptimal()
        {
            delete[] arr;
        }
        
        bool isFullStack1()
        {
            if(curr1 == tail2)
                return true;
            
            if(curr2 == tail1) //stack 2 take up the whole arr
                return true;
                
            if(curr1 == (curr2 - 1))
                return true;
                
            return false;
        }
        
        bool isFullStack2()
        {
            if(curr2 == tail1)
                return true;
            
            if(curr1 == tail2)  //stack 1 take up the whole arr
                return true; 
                
            if(curr2 == (curr1 + 1))
                return true;
                
            return false;
        }
        
        bool isEmptyStack1()
        {
            if(curr1 == 0)
                return true;
            
            return false;
        }
    
        bool isEmptyStack2()
        {
            if(curr2 == 0)
                return true;
            return false;
        }
        
        void pushFlexStack1(T value)
        {
            if(isFullStack1())
            {
                cout << "stack 2 is full" << endl;
                return;
            }
            if(isEmptyStack1())
            {
                curr1 = tail1;
                *curr1 = value;
                return;
            }
            
            ++curr1;
            *curr1 = value;
            return;
            
        }
        
        
        void pushFlexStack2(T value)
        {
            if(isFullStack2())
            {
                cout << "stack 2 is full" << endl;
                return;
            }
            if(isEmptyStack2())
            {
                curr2 = tail2;
                *curr2 = value;
                return;
            }
            
            --curr2;
            *curr2 = value;
            return;
        }
        
        
        T popFlexStack1()
        {
            if(isEmptyStack1())
            {
                cout << "error: stack 1 is empty" << endl;
                exit(-1);
            }
            
            T* tem = curr1;
            if(curr1 == tail1)
                curr1 = 0;
            else
                --curr1;
            return *tem;
        }
        
        T popFlexStack2()
        {
            if(isEmptyStack2())
            {
                cout << "error: stack 2 is empty" << endl;
                exit(-1);
            }
            
            T* tem = curr2;
            if(curr2 == tail2)
                curr2 = 0;
            else
                ++curr2;
            return *tem;
        }
        
        void printFlexStack1()
        {
            cout << "print first stack now~" << endl;
            if(isEmptyStack1())
            {
                cout << "stack1 is empty" << endl;
                return;
            }
            T* tem;
            for(tem = curr1; tem != tail1; --tem)
                cout << *tem << endl;
            cout << *tem << endl;
        }
        
        void printFlexStack2()
        {
            cout << "print first stack now~" << endl;

            if(isEmptyStack2())
            {
                cout << "stack2 is empty" << endl;
                return;
            }
            T* tem;
            for(tem = curr2; tem != tail2; ++tem)
                cout << *tem << endl;
            cout << *tem << endl;
        }
};




#endif