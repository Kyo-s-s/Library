#include<bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

// #include "../String/Zalgorithm.hpp"

int main() {

    string S;
    cin >> S;
    vector<int> Z = Zalgorithm(S);
    for(int i = 0; i < (int)(Z.size()); i++) {
        cout << Z[i] << " ";
    }
    cout << endl;

}
