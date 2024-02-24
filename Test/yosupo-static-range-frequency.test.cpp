#include<bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include<Data_structure/MergeTree.hpp>

using T = unordered_map<int, int>;

struct M {
    using T = int;
    static T op(T a, T b) { return a + b; }
    static T e() { return 0; }
};

int main() {

    int N, Q; cin >> N >> Q;
    vector<int> A(N);
    for (auto &a : A) cin >> a;

    auto f = [&](int l, int r) -> T {
        unordered_map<int, int> mp;
        for (int i = l; i < r; i++) mp[A[i]]++;
        return mp;
    };

    MergeTree<T> mt(N, f);

    while (Q--) {
        int l, r; cin >> l >> r;
        int x; cin >> x;

        cout << mt.prod<M>(l, r, [&](const T &t) -> M::T {
            return t.count(x) ? t.at(x) : 0;
        }) << "\n";
    }

}
