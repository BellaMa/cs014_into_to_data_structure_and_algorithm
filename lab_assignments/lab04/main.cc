#include "lab4.h"
#include <iostream>
using namespace std;

int main( int argc, char* argv[] ) 
{
    if ( argc != 2 ) {
        cout << "Usage: ./<executable_file> <sum> " << endl;
        exit(-1);
    }
    int max = strtol(argv[1], 0, 10 );
    
    Root rt;
    MyTree tree(rt);
    tree.make_a_tree(rt, max);
    cout << "pre_order" << endl;
    tree.pre_order(rt);
    
    cout << endl << endl << "post_order" << endl;
    tree.post_order(rt);
    
    cout << endl << endl << "sorted order" << endl;
    tree.sorted();
    return 0;
}