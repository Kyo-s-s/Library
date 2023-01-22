#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../Data_structure/Tree.hpp"

int main() {

    int N, Q; cin >> N >> Q;
    Tree tree(N);
    for (int i = 1; i < N; i++) {
        int p; cin >> p;
        tree.add_edge(i, p);
    }

    while (Q--) {
        int u, v; cin >> u >> v;
        cout << tree.lca(u, v) << endl;
    }

}
