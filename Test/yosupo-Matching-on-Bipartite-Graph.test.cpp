#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../Data_structure/MaxFlow.hpp"

int main() {
    
    int L, R, M;
    cin >> L >> R >> M;    

    MaxFlow<long long> graph(L + R + 2);
    int s = L + R, t = L + R + 1;

    vector<int> idxs(M), A(M), B(M);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        int idx = graph.add_edge(a, L + b, 1);
        idxs[i] = idx;
        A[i] = a;
        B[i] = b;
    }

    for (int i = 0; i < L; i++) {
        graph.add_edge(s, i, 1);
    }
    for (int i = 0; i < R; i++) {
        graph.add_edge(L + i, t, 1);
    }

    int ans = graph.max_flow(s, t);
    cout << ans << "\n";
    for (int i = 0; i < M; i++) {
        int e = graph.get_flow(idxs[i]);
        if (e == 1) {
            cout << A[i] << " " << B[i] << "\n";
        }
    }

}