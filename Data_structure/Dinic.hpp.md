---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-Matching-on-Bipartite-Graph.test.cpp
    title: Test/yosupo-Matching-on-Bipartite-Graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Data_structure/Dinic.hpp\"\ntemplate<class Cap> struct Dinic\
    \ {\n  public:\n    Dinic(int n) : n(n), g(n) {}\n\n    int add_edge(int from,\
    \ int to, Cap cap) {\n        int m = (int)edges.size();\n        edges.push_back({from,\
    \ (int)g[from].size()});\n        int from_id = (int)g[from].size();\n       \
    \ int to_id = (int)g[to].size();\n        if (from == to) to_id++;\n        g[from].push_back(dinic_edge{to,\
    \ to_id, cap});\n        g[to].push_back(dinic_edge{from, from_id, 0});\n    \
    \    return m;\n    }\n\n    void change_edge(int i, Cap new_cap, Cap new_flow)\
    \ {\n        auto& e = g[edges[i].first][edges[i].second];\n        auto& re =\
    \ g[e.to][e.rev];\n        e.cap = new_cap - new_flow;\n        re.cap = new_flow;\n\
    \    }\n\n    Cap flow(int s, int t) {\n        return flow(s, t, std::numeric_limits<Cap>::max());\n\
    \    }\n\n    Cap flow(int s, int t, Cap flow_limit) {\n        std::vector<int>\
    \ level(n), iter(n);\n        simple_queue<int> que;\n\n        auto bfs = [&]()\
    \ {\n            std::fill(level.begin(), level.end(), -1);\n            level[s]\
    \ = 0;\n            que.clear();\n            que.push(s);\n            while\
    \ (!que.empty()) {\n                int v = que.pop_front();\n               \
    \ for (auto e : g[v]) {\n                    if (e.cap > 0 && level[e.to] == -1)\
    \ {\n                        level[e.to] = level[v] + 1;\n                   \
    \     if (e.to == t) return;\n                        que.push(e.to);\n      \
    \              }\n                }\n            }\n        };\n\n        auto\
    \ dfs = [&](auto dfs, int v, Cap limit) -> Cap {\n            if (v == s) return\
    \ limit;\n            Cap res = 0;\n            int level_v = level[v];\n    \
    \        for (int& i = iter[v]; i < int(g[v].size()); i++) {\n               \
    \ dinic_edge& e = g[v][i];\n                if (level_v <= level[e.to] || g[e.to][e.rev].cap\
    \ == 0) continue;\n                Cap d = dfs(dfs, e.to, std::min(limit - res,\
    \ g[e.to][e.rev].cap));\n                if (d <= 0) continue;\n             \
    \   g[v][i].cap += d;\n                g[e.to][e.rev].cap -= d;\n            \
    \    res += d;\n                if (res == limit) return res;\n            }\n\
    \            level[v] = n;\n            return res;\n        };\n\n        Cap\
    \ flow = 0;\n        while (flow < flow_limit) {\n            bfs();\n       \
    \     if (level[t] == -1) break;\n            std::fill(iter.begin(), iter.end(),\
    \ 0);\n            Cap f = dfs(dfs, t, flow_limit - flow);\n            if (!f)\
    \ break;\n            flow += f;\n        }\n        return flow;\n    }\n\n \
    \   Cap get_flow(int i) {\n        auto _e = g[edges[i].first][edges[i].second];\n\
    \        auto _re = g[_e.to][_e.rev];\n        return _re.cap;\n    } \n\n   \
    \ std::vector<bool> min_cut(int s) {\n        std::vector<bool> visited(n);\n\
    \        simple_queue<int> que;\n        que.push(s);\n        while (!que.empty())\
    \ {\n            int p = que.pop_front();\n            visited[p] = true;\n  \
    \          for (auto e : g[p]) {\n                if (e.cap && !visited[e.to])\
    \ {\n                    visited[e.to] = true;\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n        return visited;\n    }\n\
    \n  private: \n    int n;\n    struct dinic_edge {\n        int to, rev;\n   \
    \     Cap cap;\n    };\n    template<class T> struct simple_queue {\n        std::vector<T>\
    \ data;\n        int pos = 0;\n        void clear() {\n            data.clear();\n\
    \            pos = 0;\n        }\n        void push(T val) {\n            data.emplace_back(val);\n\
    \        }\n        T pop_front() {\n            return data[pos++];\n       \
    \ }\n        bool empty() {\n            return pos == (int)data.size();\n   \
    \     }\n    };\n    std::vector<std::pair<int, int>> edges;\n    std::vector<std::vector<dinic_edge>>\
    \ g;\n};\n"
  code: "template<class Cap> struct Dinic {\n  public:\n    Dinic(int n) : n(n), g(n)\
    \ {}\n\n    int add_edge(int from, int to, Cap cap) {\n        int m = (int)edges.size();\n\
    \        edges.push_back({from, (int)g[from].size()});\n        int from_id =\
    \ (int)g[from].size();\n        int to_id = (int)g[to].size();\n        if (from\
    \ == to) to_id++;\n        g[from].push_back(dinic_edge{to, to_id, cap});\n  \
    \      g[to].push_back(dinic_edge{from, from_id, 0});\n        return m;\n   \
    \ }\n\n    void change_edge(int i, Cap new_cap, Cap new_flow) {\n        auto&\
    \ e = g[edges[i].first][edges[i].second];\n        auto& re = g[e.to][e.rev];\n\
    \        e.cap = new_cap - new_flow;\n        re.cap = new_flow;\n    }\n\n  \
    \  Cap flow(int s, int t) {\n        return flow(s, t, std::numeric_limits<Cap>::max());\n\
    \    }\n\n    Cap flow(int s, int t, Cap flow_limit) {\n        std::vector<int>\
    \ level(n), iter(n);\n        simple_queue<int> que;\n\n        auto bfs = [&]()\
    \ {\n            std::fill(level.begin(), level.end(), -1);\n            level[s]\
    \ = 0;\n            que.clear();\n            que.push(s);\n            while\
    \ (!que.empty()) {\n                int v = que.pop_front();\n               \
    \ for (auto e : g[v]) {\n                    if (e.cap > 0 && level[e.to] == -1)\
    \ {\n                        level[e.to] = level[v] + 1;\n                   \
    \     if (e.to == t) return;\n                        que.push(e.to);\n      \
    \              }\n                }\n            }\n        };\n\n        auto\
    \ dfs = [&](auto dfs, int v, Cap limit) -> Cap {\n            if (v == s) return\
    \ limit;\n            Cap res = 0;\n            int level_v = level[v];\n    \
    \        for (int& i = iter[v]; i < int(g[v].size()); i++) {\n               \
    \ dinic_edge& e = g[v][i];\n                if (level_v <= level[e.to] || g[e.to][e.rev].cap\
    \ == 0) continue;\n                Cap d = dfs(dfs, e.to, std::min(limit - res,\
    \ g[e.to][e.rev].cap));\n                if (d <= 0) continue;\n             \
    \   g[v][i].cap += d;\n                g[e.to][e.rev].cap -= d;\n            \
    \    res += d;\n                if (res == limit) return res;\n            }\n\
    \            level[v] = n;\n            return res;\n        };\n\n        Cap\
    \ flow = 0;\n        while (flow < flow_limit) {\n            bfs();\n       \
    \     if (level[t] == -1) break;\n            std::fill(iter.begin(), iter.end(),\
    \ 0);\n            Cap f = dfs(dfs, t, flow_limit - flow);\n            if (!f)\
    \ break;\n            flow += f;\n        }\n        return flow;\n    }\n\n \
    \   Cap get_flow(int i) {\n        auto _e = g[edges[i].first][edges[i].second];\n\
    \        auto _re = g[_e.to][_e.rev];\n        return _re.cap;\n    } \n\n   \
    \ std::vector<bool> min_cut(int s) {\n        std::vector<bool> visited(n);\n\
    \        simple_queue<int> que;\n        que.push(s);\n        while (!que.empty())\
    \ {\n            int p = que.pop_front();\n            visited[p] = true;\n  \
    \          for (auto e : g[p]) {\n                if (e.cap && !visited[e.to])\
    \ {\n                    visited[e.to] = true;\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n        return visited;\n    }\n\
    \n  private: \n    int n;\n    struct dinic_edge {\n        int to, rev;\n   \
    \     Cap cap;\n    };\n    template<class T> struct simple_queue {\n        std::vector<T>\
    \ data;\n        int pos = 0;\n        void clear() {\n            data.clear();\n\
    \            pos = 0;\n        }\n        void push(T val) {\n            data.emplace_back(val);\n\
    \        }\n        T pop_front() {\n            return data[pos++];\n       \
    \ }\n        bool empty() {\n            return pos == (int)data.size();\n   \
    \     }\n    };\n    std::vector<std::pair<int, int>> edges;\n    std::vector<std::vector<dinic_edge>>\
    \ g;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_structure/Dinic.hpp
  requiredBy: []
  timestamp: '2023-09-16 04:04:22+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-Matching-on-Bipartite-Graph.test.cpp
documentation_of: Data_structure/Dinic.hpp
layout: document
title: Dinic
---

## コンストラクタ

```cpp
Dinic<Cap> dinic(int N)
```

- $N$頂点のグラフを作成する．何も辺が存在しない．
- `Cap` は `long long` もしくは `int` であること．


## add_edge

```cpp
int add_edge(int from, int to, Cap cap)
```

- `from`から`to`へ容量`cap`の辺を追加する。
- 以降、追加した辺の本数を $M$ とする。
- 追加した辺の番号を返す。

##### 制約

- $0 \leq from, to < N$
- $0 \leq cap$

##### 計算量

- (ならし？) $O(1)$


## flow

```cpp
(1) Cap flow(int s, int t)
(2) Cap flow(int s, int t, Cap flow_limit)
```

- (1): `s` から `t` まで、上限なしの最大流を求める。
- (2): `s` から `t` まで、流量の上限を `flow_limit` とした最大流を求める。

##### 制約

- $0 \leq s, t < N$
- $s \neq t$
- (2): $0 \leq flow\_limit$

##### 計算量

- $O(\min(N^{\frac{2}{3}}M, M^{\frac{3}{2}}))$ (辺の容量がすべて $1$ の場合)
- $O(N^2M)$


## min_cut

```cpp
vector<bool> min_cut(int s)
```

- `max_flow(s, t)` を呼んだ後に呼ぶことを想定。頂点 $s$ から到達可能な頂点を `true` とした `vector` を返す。

##### 制約

- $0 \leq s < N$

##### 計算量

- $O(N + M)$


## get_flow

```cpp
Cap get_flow(int idx)
```

- `max_flow(s, t)` を呼んだ後に呼ぶことを想定。頂点 `from` から頂点 `to` へ流れた流量を返す。
- `idx` は追加された辺の番号である。

##### 制約

- $0 \leq from, to < N$

##### 計算量

- $O(1)$

## change_edge

```cpp
void change_edge(int idx, Cap new_cap, Cap new_flow)
```

- `idx` 番目の辺の容量を `new_cap` に変更し、流量を `new_flow` に変更する。

##### 制約

- $0 \leq idx < M$

##### 計算量

- $O(1)$
