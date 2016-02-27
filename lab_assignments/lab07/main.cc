// chaoyun ma
// 605275
// lab 7

#include <iostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include <string>
#include <vector>
#include <ctime>


using namespace std;
int main()
{
    vector<string> words;
    ifstream inf("words.txt", ios::in);
    string temp;
    while(getline(inf,temp)) {
       words.push_back(temp);
    }
    
    ofstream result;
    result.open("data.txt", ios::trunc);
    // cout << words.size()<< endl;
    
    clock_t t1, t2, t3, t4;
    
    set<string> tree;
    set<string>::iterator it_tree;
    unordered_set<string> hash;
    unordered_set<string>::iterator it_hash;
    
    for(int n = 5000; n <= 50000; n += 5000)
    {
        // t1 is the whole time for inserting elements to a tree
        t1 = clock();
        for(int i = 0; i < n; ++i) {
            tree.insert(words[i]);
        }
        t1 = clock() - t1;
        
        // t2 is the whole time for inserting elements to a hash table
        t2 = clock();
        for(int i = 0; i < n; ++i) {
            hash.insert(words[i]);
        }
        t2 = clock() - t2;
        
        // t3 is the time to find all those elements in a tree
        int x = 0;
        t3 = clock();
        while(x < n)
        {   
            it_tree = tree.find(words[x]);
            ++x;
        }
        t3 = clock() - t3;
        
        // t4 is the time to find all those elemtns in a hash table
        x = 0;
        t4 = clock();
        while(x < n)
        {
            it_hash = hash.find(words[x]);
            ++x;
        }
        t4 = clock() - t4;
        
        result << n
               << " " << 1000*((float)t1)/CLOCKS_PER_SEC
               << " " << 1000*((float)t2)/CLOCKS_PER_SEC
               << " " << 1000*(((float)t3)/CLOCKS_PER_SEC)/n
               << " " << 1000*(((float)t4)/CLOCKS_PER_SEC)/n
               << endl;
               
               
        // cout   << n
        //       << " " << 1000*((float)t1)/CLOCKS_PER_SEC
        //       << " " << 1000*((float)t2)/CLOCKS_PER_SEC 
        //       << endl;
    }
    
    result.close();
    return 0;
}