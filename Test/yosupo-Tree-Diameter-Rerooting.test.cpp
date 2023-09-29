#include<bits/stdc++.h>
using namespace std;

#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include<Data_structure/Rerooting.hpp>

struct M {
    using T = long long;
    static T op(T a, T b) {
        return max(a, b);
    }
    static T e() { return 0; }
};

int main() {

    int N; cin >> N;
    Rerooting<M> tree(N);
    vector<long long> W(N - 1);
    struct edge {
        int to;
        long long cost;
    };
    vector<vector<edge>> G(N);

    for (int i = 0; i < N - 1; i++) {
        int s, t;
        long long w;
        cin >> s >> t >> w;
        int id = tree.add_edge(s, t);
        W[id] = w;

        G[s].push_back(edge{t, w});
        G[t].push_back(edge{s, w});
    }

    using E = typename M::T;
    using V = long long;

    auto put_edge = [&](V v, int id) -> E {
        return v + W[id];
    };
    auto put_node = [&](E e, int v) -> V {
        return e;
    };
    auto dist = tree.solve<V>(put_edge, put_node);

    long long max_dist = *max_element(dist.begin(), dist.end());
    int start = [&]() -> int {
        for (int i = 0; i < N; i++) {
            if (dist[i] == max_dist) return i;
        }
        assert(false);
    }();

    vector<long long> ans;
    ans.push_back(start);
    long long sum = 0;

    auto dfs = [&](auto dfs, int now, int par) -> void {
        if (sum == max_dist) {
            cout << max_dist << " " << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] << (i + 1 == ans.size() ? "\n" : " ");
            }
            exit(0);
        }

        for (auto [to, cost] : G[now]) {
            if (to == par) continue;
            ans.push_back(to);
            sum += cost;
            dfs(dfs, to, now);
            ans.pop_back();
            sum -= cost;
        }
    };
    dfs(dfs, start, -1);

}
