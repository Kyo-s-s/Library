#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../Data_structure/DynamicSegtree.hpp"

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
    
    DynamicSegtree<Monoid> seg;
    int N, Q; cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        long long a; cin >> a;
        seg.set(i, a);
    }

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
