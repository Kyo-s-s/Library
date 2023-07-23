#include<bits/stdc++.h>
using namespace std;

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_I"

#include "../Data_structure/LazySegtree.hpp"

struct M {
    struct T {
        long long value, width;
        T(long long v) : T(v, 1) {}
        T(long long v, long long w) : value(v), width(w) {}
    };
    static T op(T a, T b) { return T(a.value + b.value, a.width + b.width); }
    static T e() { return T(0, 0); }
};

struct O {
    using T = long long;
    static T op(T f, T g) {
        return (f == e() ? g : f);
    }
    static T e() { return 1LL << 58; }
};

M::T fn(O::T f, M::T x) {
    if (f == O::e()) return x;
    return M::T(f * x.width, x.width);
}


int main() {
    int N, Q;
    cin >> N >> Q;
    vector<M::T> v(N, M::T(0, 1));
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
            cout << seg.prod(s, t + 1).value << endl;
        }
    }
}

