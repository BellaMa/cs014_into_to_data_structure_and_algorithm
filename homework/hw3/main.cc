#include "bst.h"
#include <iostream>

using namespace std;

int main()
{
    BST<char> bst;
    int i = bst.size();
    cout <<"size of an empty bst: " <<i << endl;
    
    char list[10] = {'a', 'z', 'g', 'd', 'c', 'b', 'x', 'e', 'i', 'f'};
    for(int i = 0; i < 10; i++)
    {
        bst.insert(list[i]);
    }
    
    cout << "inoder: ";
    bst.inorder();
    cout << endl;
    
    cout << "preorder: ";
    bst.preorder();
    cout << endl;
    
    cout << "postorder: ";
    bst.postorder();
    cout << endl;
    
    cout << "remove f and e" << endl;
    bst.remove('f');
    bst.remove('e');
    cout << "inorder: ";
    bst.inorder();
    cout << endl;
    
    cout << "bst[0] find the first item in inorder: ";
    char a = bst[0];
    cout << a << endl;
    
    cout << "the size of current BST: ";
    cout << bst.size() << endl;
    
    cout << "if BST is empty? should be 0" << endl;
    int j = bst.empty();
    cout << j << endl;
    
    cout << "if f exists?" << endl;
    cout << bst.search('f') << endl;
    
    cout << "if c exists?" << endl;
    cout << bst.search('c');
    cout << endl;
    
    return 0;
}