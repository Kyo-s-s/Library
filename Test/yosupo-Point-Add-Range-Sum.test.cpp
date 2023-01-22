#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../Data_structure/Segtree.hpp"

struct Monoid {
    using T = long long;
    static T op(T a, T b) {
        return a + b;
    }
    static T e() {
        return 0;
    }
};

int main() {
    
    int N, Q; cin >> N >> Q;
    vector<long long> A(N);
    for (auto &a : A) cin >> a;
    Segtree<Monoid> seg(A);


    while (Q--) {
        int t; cin >> t;
        if (t == 0) {
            int p; cin >> p;
            long long x; cin >> x;
            seg.set(p, seg.get(p) + x);
        } else {
            int l, r; cin >> l >> r;
            cout << seg.prod(l, r) << endl;
        }
    }
}
