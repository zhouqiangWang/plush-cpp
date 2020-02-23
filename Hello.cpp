#include <iostream>
#include "bits/stdc++.h"

using namespace std;

int main() {
    cout<<"hello world !"<<endl;

    unordered_map<int, string> umap;
    umap[1] = "hello";
    umap[2] = "from";
    umap[3] = "outside";
    cout << umap.size() << endl;
    
    for(auto i : umap) {
        cout << i.first << " - " << i.second << endl;
    }

    auto begin = umap.begin();

    cout << begin->first << " - " << begin->second << endl;

    vector<vector<char> > board;
    vector<char> vec;
    vec.push_back('a');
    board.push_back(vec);
    cout << board[0][0] << endl;

    board[0][0] = 'b';

    cout << board[0][0] << endl;

    stack<int> st;
    st.push(10);
    cout << "--------- stack -----------" <<endl;
    cout << st.top() << ", empty = " << st.empty() << endl;

    return 0;
}