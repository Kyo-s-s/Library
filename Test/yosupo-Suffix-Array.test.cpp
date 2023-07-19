#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../String/SuffixArray.hpp"

int main() {

    string S; cin >> S;
    vector<int> sa = SuffixArray(S);
    for (int i = 1; i < sa.size(); i++) {
        cout << sa[i] << " \n"[i == sa.size() - 1];
    }

}
