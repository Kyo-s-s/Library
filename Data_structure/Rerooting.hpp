template<typename T> 
concept Monoid = requires {
    typename T::T;
    { T::op(std::declval<typename T::T>(), std::declval<typename T::T>()) } -> std::same_as<typename T::T>;
    { T::e() } -> std::same_as<typename T::T>;
};

template<Monoid M> struct Rerooting {
  public:
    using E = typename M::T;
    Rerooting(int N) : N(N) {
        G.resize(N);
    }

    int add_edge(int from, int to) {
        assert(edge_count < N - 1);
        G[from].push_back(edge{to, edge_count});
        G[to].push_back(edge{from, edge_count});
        return edge_count++;
    }

    template<class V>
    vector<V> solve(function<E(V, int)> put_edge, function<V(E, int)> put_node) {
        return solve<V>(put_edge, put_node, put_node);
    }

    template<class V> 
    vector<V> solve(
        function<E(V, int)> put_edge, 
        function<V(E, int)> put_node,
        function<V(E, int)> solve_node
    ) {
        vector<vector<V>> dp(N);
        for (int i = 0; i < N; i++) dp[i].resize(G[i].size());
        auto dfs = [&](auto dfs, int now, int par) -> V {
            int deg = (int)G[now].size();
            E res = M::e();
            for (int i = 0; i < deg; i++) {
                auto [to, id] = G[now][i];
                if (to == par) continue;
                dp[now][i] = dfs(dfs, to, now);
                res = M::op(res, put_edge(dp[now][i], id));
            }
            return put_node(res, now);
        };
        dfs(dfs, 0, -1);
        vector<V> ans(N);
        auto reroot = [&](auto reroot, int now, int par, const optional<V> &v) -> void {
            int deg = (int)G[now].size();
            if (v.has_value()) {
                for (int i = 0; i < deg; i++) if (G[now][i].to == par) {
                    dp[now][i] = v.value();
                }
            }
            vector<E> L(deg + 1, M::e()), R(deg + 1, M::e());
            for (int i = 0; i < deg; i++) {
                L[i + 1] = M::op(L[i], put_edge(dp[now][i], G[now][i].id));
            }
            for (int i = deg - 1; i >= 0; i--) {
                R[i] = M::op(R[i + 1], put_edge(dp[now][i], G[now][i].id));
            }

            ans[now] = solve_node(L[deg], now);
            for (int i = 0; i < deg; i++) {
                int u = G[now][i].to;
                if (u == par) continue;
                reroot(reroot, u, now, put_node(M::op(L[i], R[i + 1]), now));
            }
        };
        reroot(reroot, 0, -1, nullopt);
        return ans;
    }

  private:
    int N;
    int edge_count = 0;
    struct edge {
        int to, id;
    };
    vector<vector<edge>> G;
};
