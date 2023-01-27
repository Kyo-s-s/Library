#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../Data_structure/CumulativeSum.hpp"

int main() {

    int N, Q; cin >> N >> Q;
    vector<long long> A(N);
    for (auto &a : A) cin >> a;

    CumulativeSum<long long> cum(A);

    while (Q--) {
        int l, r; cin >> l >> r;
        cout << cum.sum(l, r) << endl;
    }

}