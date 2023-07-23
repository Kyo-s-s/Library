#include<bits/stdc++.h>
using namespace std;

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_H"

#include "../Data_structure/LazySegtree.hpp"

struct M {
    using T = long long;
    static T op(T a, T b) { return min(a, b); }
    static T e() { return 1LL << 58; }
};

struct O {
    using T = long long;
    static T op(T f, T g) {
        return f + g;
    }
    static T e() { return 0; }
};

M::T fn(O::T f, M::T x) {
    return f + x;
}


int main() {
    int N, Q;
    cin >> N >> Q;
    vector<M::T> v(N);
    LazySegtree<M, O, fn> seg(v);

    while(Q--){
        int u;
        cin >> u;
        if(u == 0){
            int s, t, x;
            cin >> s >> t >> x;
            seg.apply(s, t + 1, x);
        }else{
            int s, t;
            cin >> s >> t;
            cout << seg.prod(s, t + 1) << endl;
        }
    }
}

