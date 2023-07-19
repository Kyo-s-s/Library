#include<bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "../String/SuffixArray.hpp"

#include "../String/LCPArray.hpp"

int main() {

    string S;
    cin >> S;

    vector<int> lcp = LCPArray(S, SuffixArray(S));

    long long ans = (long long)S.size() * (long long)(S.size() + 1) / 2;
    for (int v : lcp) {
        ans -= v;
    }

    cout << ans << endl;

}
