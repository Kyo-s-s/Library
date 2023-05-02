#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../Data_structure/Tree.hpp"

int main() {

    int N; cin >> N;
    Tree<long long> tree(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        long long c; 
        cin >> a >> b >> c;

        tree.add_edge(a, b, c);
    }

    auto [dist, u, v] = tree.diameter();
    vector<int> path = tree.path(u, v);
    cout << dist << " " << path.size() << endl;
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " \n"[i == path.size() - 1];
    }

}
