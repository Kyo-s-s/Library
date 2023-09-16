template<class Cap> struct Dinic {
  public:
    Dinic(int n) : n(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        int m = (int)edges.size();
        edges.push_back({from, (int)g[from].size()});
        int from_id = (int)g[from].size();
        int to_id = (int)g[to].size();
        if (from == to) to_id++;
        g[from].push_back(dinic_edge{to, to_id, cap});
        g[to].push_back(dinic_edge{from, from_id, 0});
        return m;
    }

    void change_edge(int i, Cap new_cap, Cap new_flow) {
        auto& e = g[edges[i].first][edges[i].second];
        auto& re = g[e.to][e.rev];
        e.cap = new_cap - new_flow;
        re.cap = new_flow;
    }

    Cap flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }

    Cap flow(int s, int t, Cap flow_limit) {
        std::vector<int> level(n), iter(n);
        simple_queue<int> que;

        auto bfs = [&]() {
            std::fill(level.begin(), level.end(), -1);
            level[s] = 0;
            que.clear();
            que.push(s);
            while (!que.empty()) {
                int v = que.pop_front();
                for (auto e : g[v]) {
                    if (e.cap > 0 && level[e.to] == -1) {
                        level[e.to] = level[v] + 1;
                        if (e.to == t) return;
                        que.push(e.to);
                    }
                }
            }
        };

        auto dfs = [&](auto dfs, int v, Cap limit) -> Cap {
            if (v == s) return limit;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                dinic_edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d = dfs(dfs, e.to, std::min(limit - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == limit) return res;
            }
            level[v] = n;
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            Cap f = dfs(dfs, t, flow_limit - flow);
            if (!f) break;
            flow += f;
        }
        return flow;
    }

    Cap get_flow(int i) {
        auto _e = g[edges[i].first][edges[i].second];
        auto _re = g[_e.to][_e.rev];
        return _re.cap;
    } 

    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(n);
        simple_queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.pop_front();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }

  private: 
    int n;
    struct dinic_edge {
        int to, rev;
        Cap cap;
    };
    template<class T> struct simple_queue {
        std::vector<T> data;
        int pos = 0;
        void clear() {
            data.clear();
            pos = 0;
        }
        void push(T val) {
            data.emplace_back(val);
        }
        T pop_front() {
            return data[pos++];
        }
        bool empty() {
            return pos == (int)data.size();
        }
    };
    std::vector<std::pair<int, int>> edges;
    std::vector<std::vector<dinic_edge>> g;
};
