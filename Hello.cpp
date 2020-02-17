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

    return 0;
}