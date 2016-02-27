//Name: Hao Gai
//SID: 606362
//Date: 5/26/2015

#include <iostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include <string>
#include <vector>
#include <ctime>

using namespace std;
int main() {
    vector<string> words;
    ifstream infile("words.txt", ios::in);
    string temp;
    while(getline(infile,temp)) {
       words.push_back(temp);
    }
    ofstream datafile;
    datafile.open("data.txt", ios::trunc);
    clock_t t1, t2, t3, t4;
    set<string> tree;
    unordered_set<string> hash;
    for (int N = 5000; N <= 50000; N+=5000) {
        cout << "n=" << N;
        datafile << N;
        t1 = clock();
        for(int i = 0; i < N; ++i) {
            tree.insert(words[i]);
        }
        t1 = clock() - t1;
        t2 = clock();
        for(int i = 0; i < N; ++i) {
            hash.insert(words[i]);
        }
        t2 = clock() - t2;
        t3 = clock();
        for(int i = 0; i < N; ++i) {
            tree.find(words[i]);
        }
        t3 = clock() - t3;
        t4 = clock();
        for(int i = 0; i < N; ++i) {
            hash.find(words[i]);
        }
        t4 = clock() - t4;
        cout << " tree-insert-time " << ((float)t1)/CLOCKS_PER_SEC << "s";
        cout << " hash-insert-time " << ((float)t2)/CLOCKS_PER_SEC << "s";
        cout << " tree-query-time " << (((float)t3)/CLOCKS_PER_SEC)/N << "s";
        cout << " hash-query-time " << (((float)t4)/CLOCKS_PER_SEC)/N << "s";
        cout << endl;
        datafile << " " << 1000*((float)t1)/CLOCKS_PER_SEC;
        datafile << " " << 1000*((float)t2)/CLOCKS_PER_SEC;
        datafile << " " << 1000*(((float)t3)/CLOCKS_PER_SEC)/N;
        datafile << " " << 1000*(((float)t4)/CLOCKS_PER_SEC)/N;
        datafile << endl;
    }
    datafile.close();
}