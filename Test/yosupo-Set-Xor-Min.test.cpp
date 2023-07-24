#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "../Data_structure/BinaryTrie.hpp"

int main() {

    int Q; cin >> Q;
    BinaryTrie<30> trie;

    while (Q--) {
        int t; cin >> t;
        if (t == 0) {
            long long x; cin >> x;
            if (!trie.find(x)) {
                trie.insert(x);
            }
        }
        if (t == 1) {
            long long x; cin >> x;
            trie.erase(x);
        }
        if (t == 2) {
            long long x; cin >> x;
            cout << trie.min_element(x) << endl;
        }
    }

}