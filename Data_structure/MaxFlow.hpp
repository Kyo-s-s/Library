template<class C> struct MaxFlow {
    vector<pair<int, int>> pos;
    struct edge {
        int to, rev;
        C cap;
    };
    vector<vector<edge>> G;
    edge &get_rev(edge &e) { return G[e.to][e.rev]; }

    MaxFlow(int n) : G(n) {}

    int add_edge(int from, int to, C cap) {
        G[from].push_back({to, (int)G[to].size(), cap});
        G[to].push_back({from, (int)G[from].size() - 1, 0});
        pos.push_back({from, (int)G[from].size() - 1});
        return (int)pos.size() - 1;
    }

    C max_flow(int s, int t) {
        return max_flow(s, t, numeric_limits<C>::max());
    }
    C max_flow(int s, int t, C flow_limit) {
        vector<int> level(G.size()), iter(G.size());
        queue<int> que;

        auto bfs = [&]() {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            queue<int> ().swap(que);
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : G[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };

        auto dfs = [&](auto &&self, int v, C up) {
            if (v == s) return up;
            C res = 0;
            int level_v = level[v];
            for (int &i = iter[v]; i < (int)G[v].size(); i++) {
                edge &e = G[v][i];
                if (level_v <= level[e.to] || G[e.to][e.rev].cap == 0) continue;
                C d = self(self, e.to, min(up - res, G[e.to][e.rev].cap));
                if (d <= 0) continue;
                G[v][i].cap += d;
                G[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) return res;
            }
            level[v] = G.size();
            return res;
        };

        C flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            fill(iter.begin(), iter.end(), 0);
            C f = dfs(dfs, t, flow_limit - flow);
            if (!f) break;
            flow += f;
        }
        return flow;
    }

    C get_flow(int idx) {
        return get_rev(G[pos[idx].first][pos[idx].second]).cap;
    }

    vector<bool> min_cut(int s) {
        vector<bool> res(G.size());
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            res[v] = true;
            for (auto &e : G[v]) {
                if (e.cap > 0 && !res[e.to]) {
                    res[e.to] = true;
                    q.push(e.to);
                }
            }
        }
        return res;
    }
};
