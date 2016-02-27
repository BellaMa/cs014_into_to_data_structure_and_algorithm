// chaoyun ma
// 605275
// assignment 7
#include "dfs.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector <vector <bool>> matrix;
    matrix.push_back({true, true, true});
    matrix.push_back({true, true, true});
    matrix.push_back({true, true, true});

    dfs(matrix);
    for (unsigned i = 0; i < matrix.size(); ++i){
        for (unsigned j = 0; j < matrix[i].size(); ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}