/*
NAME: Chaoyun Ma
SID: 605275
DATE: 04/26/2015 
*/
#include "lab3.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

void printHanoi(int n, char A, char B, char C)
{
    if(n > 0)
    {
        printHanoi(n - 1, A, C, B);
        cout << "Moved " << n << " from peg " << A << " to peg " << C << endl;
        printHanoi(n - 1, B, A, C);
    }
}

template<typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C)
{
    //print(n, 'A', 'B', 'C');
    if(n > 0)
    {
        showTowerStates(n - 1, A, C, B);
        T tem = A.top();
        A.pop();
        C.push(tem);
        showTowerStates(n - 1, B, A, C);
    }
   
}



int main()
{


/* problem 1 */

    cout << "input the size of stack1 for TwoStackFixed" << endl;
    int size;
    cin >> size;
    
    cout << "input the max size for first stack " << endl;
    int max;
    cin >> max;
    TwoStackFixed<string> stack1(size,max);
    cout << "the max size for second stack is " << size-max << endl;
    
    cout << "input data to first 1, ending with -1" << endl;
    string in;
    cin >> in;
    while(in != "-1")
    {
        stack1.pushStack1(in);
        cin >> in;
    }
    
    cout << "input data to second 2, ending with -1" << endl;
    cin >> in;
    while(in != "-1")
    {
        stack1.pushStack2(in);
        cin >> in;
    }

    stack1.printStack1();
    stack1.printStack2();

    
    cout << "popStack1: (until reach the bottom)" << endl;
    
    while(!stack1.isEmptyStack1())
    {
        cout << stack1.popStack1() << endl;
    }
    stack1.printStack1();
    cout << "popStack2: (until reach the bottom)" << endl;
    
    while(!stack1.isEmptyStack2())
    {
        cout << stack1.popStack2() << endl;
    }
    stack1.printStack2();
    


/* problem 2 */
        
    
    cout << endl << "input the size for TwoStackOptimal" << endl;
    cin >> size;
    TwoStackOptimal<string> stack2(size);
    
    cout << "input data to first stack, ending with -1" << endl;
    cin >> in;
    while(in != "-1")
    {
        stack2.pushFlexStack1(in);
        cin >> in;
    }
    
    cout << "input data to second stack, ending with -1" << endl;
    cin >> in;
    while(in != "-1")
    {
        stack2.pushFlexStack2(in);
        cin >> in;
    }
    
    stack2.printFlexStack1();
    stack2.printFlexStack2();
    
    cout << "popFlexStack1:  (until reach the bottom)" << endl;
    while(!stack2.isEmptyStack1())
    {
        cout << stack2.popFlexStack1() << endl;
    }
    
    cout << "popFlexStack2:  (until reach the bottom)" << endl;
    while(!stack2.isEmptyStack2())
    {
        cout << stack2.popFlexStack2() << endl;
    }
    
    stack2.printFlexStack1();
    stack2.printFlexStack2();
  

/* problem 3 */
    cout << endl << "input the max number for Tower of Hanoi" << endl;
    int n;
    cin >> n;
    
    stack<int> A;
    stack<int> B;
    stack<int> C;
    
    cout << "stack A contains: " << endl;
    for(int i = n; i > 0; --i)
    {   
        cout << n - i + 1 << " " << endl;
        A.push(i);
    }
    cout << endl << "the following shows the steps to solve Hanoi puzzle" << endl;
    showTowerStates(n, A, B, C);
    printHanoi(n, 'A', 'B', 'C');
    cout << endl << "stack C contains: " << endl;
    while(C.size() > 0)
    {
        cout << C.top() << endl;
        C.pop();
    }

    
    return 0;
}