template<class T = int> struct Tree {
    struct edge{ int to; T cost; };
    vector<vector<edge>> G;
    vector<vector<int>> parent;
    vector<int> unweighted_dist;
    vector<T> weighted_dist;

    Tree(int n) : G(n) {}

    void add_edge(int u, int v) { add_edge(u, v, T(1)); }
    void add_edge(int u, int v, T w) {
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    vector<T> calc_dist(int root = 0) {
        vector<T> dist(G.size(), -1); dist[root] = 0;
        queue<int> que; que.push(root);
        while (!que.empty()) {
            int v = que.front(); que.pop();
            for (auto e: G[v]) {
                if (dist[e.to] != -1) continue;
                dist[e.to] = dist[v] + e.cost;
                que.push(e.to);
            }
        }
        return dist;
    }

    tuple<T, int, int> diameter() {
        vector<T> dist = calc_dist();
        int v = max_element(dist.begin(), dist.end()) - dist.begin();
        dist = calc_dist(v);
        int u = max_element(dist.begin(), dist.end()) - dist.begin();
        return { dist[u], u, v };
    }

    vector<int> path(int u, int v) {
        vector<T> dist = calc_dist(u);
        vector<int> path;
        while (v != u) {
            path.push_back(v);
            for (auto e: G[v]) {
                if (dist[e.to] == dist[v] - e.cost) {
                    v = e.to;
                    break;
                }
            }
        }
        path.push_back(u);
        reverse(path.begin(), path.end());
        return path;
    }

    void lca_build(int root = 0) {
        int V = G.size();
        int K = 1;
        while ((1 << K) < V) K++;
        parent.assign(K, vector<int>(V, -1));
        unweighted_dist.assign(V, -1);

        auto unweighted_dfs = [this](auto&& self, int v, int p, int d) -> void {
            parent[0][v] = p;
            unweighted_dist[v] = d;
            for (auto e: G[v]) {
                if (e.to == p) continue;
                self(self, e.to, v, d + 1);
            }
        };

        unweighted_dfs(unweighted_dfs, root, -1, 0);
        for (int k = 0; k + 1 < K; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0) parent[k + 1][v] = -1;
                else parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }

        weighted_dist.assign(V, -1); weighted_dist[root] = 0;
        queue<int> que; que.push(root);
        while (!que.empty()) {
            int v = que.front(); que.pop();
            for (auto e: G[v]) {
                if (weighted_dist[e.to] == -1 || weighted_dist[e.to] > weighted_dist[v] + e.cost) {
                    weighted_dist[e.to] = weighted_dist[v] + e.cost;
                    que.push(e.to);
                }
            }
        }
    }

    int lca(int u, int v) {
        if (parent.size() == 0) lca_build();
        if (unweighted_dist[u] < unweighted_dist[v]) swap(u, v);
        int K = parent.size();
        for (int k = 0; k < K; k++) {
            if ((unweighted_dist[u] - unweighted_dist[v]) >> k & 1) {
                u = parent[k][u];
            }
        }
        if (u == v) return u;
        for (int k = K - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    int prev(int u, int k) {
        if (parent.size() == 0) lca_build();
        int K = parent.size();
        for (int i = 0; i < K; i++) {
            if ((k >> i) & 1) {
                u = parent[i][u];
            }
        }
        return u;
    }

    T dist(int u, int v) {
        if (weighted_dist.size() == 0) lca_build();
        return weighted_dist[u] + weighted_dist[v] - 2 * weighted_dist[lca(u, v)];
    }
};
