// Chaoyun Ma
// 605275
// May 11
#include "lab5.h"
#include <iostream>

using namespace std;

int main()
{
    BST<int> bst;
    
    int list[10] = {1, 2, 3, 4, 5, 6, 7};
    for(int i = 0; i < 7; i++)
    {
        bst.insert(list[i]);
    }
    
    cout << "inoder: ";
    bst.inorder();
    cout << endl;
    cout << "postoder: ";
    bst.postorder();
    cout << endl;
    cout << "preoder: ";
    bst.preorder();
    cout << endl;
    
    cout << "part 1" << endl;
    bst.displayMinCover();
    cout << endl;

    
    int buffer[252];
    cout << "part 2 (sum is 6)" << endl;
    bst.findSumPath(bst.treeRoot() ,6, buffer);
    cout << endl;
    
    cout << "part 3" << endl;
    bst.printVerticalOrder();
    
    return 0;
}