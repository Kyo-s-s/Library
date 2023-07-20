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
  bundledCode: "#line 1 \"Data_structure/MaxFlow.hpp\"\ntemplate<class C> struct MaxFlow\
    \ {\n    vector<pair<int, int>> pos;\n    struct edge {\n        int to, rev;\n\
    \        C cap;\n    };\n    vector<vector<edge>> G;\n    edge &get_rev(edge &e)\
    \ { return G[e.to][e.rev]; }\n\n    MaxFlow(int n) : G(n) {}\n\n    int add_edge(int\
    \ from, int to, C cap) {\n        G[from].push_back({to, (int)G[to].size(), cap});\n\
    \        G[to].push_back({from, (int)G[from].size() - 1, 0});\n        pos.push_back({from,\
    \ (int)G[from].size() - 1});\n        return (int)pos.size() - 1;\n    }\n\n \
    \   C max_flow(int s, int t) {\n        return max_flow(s, t, numeric_limits<C>::max());\n\
    \    }\n    C max_flow(int s, int t, C flow_limit) {\n        vector<int> level(G.size()),\
    \ iter(G.size());\n        queue<int> que;\n\n        auto bfs = [&]() {\n   \
    \         fill(level.begin(), level.end(), -1);\n            level[s] = 0;\n \
    \           queue<int> ().swap(que);\n            que.push(s);\n            while\
    \ (!que.empty()) {\n                int v = que.front();\n                que.pop();\n\
    \                for (auto e : G[v]) {\n                    if (e.cap == 0 ||\
    \ level[e.to] >= 0) continue;\n                    level[e.to] = level[v] + 1;\n\
    \                    if (e.to == t) return;\n                    que.push(e.to);\n\
    \                }\n            }\n        };\n\n        auto dfs = [&](auto &&self,\
    \ int v, C up) {\n            if (v == s) return up;\n            C res = 0;\n\
    \            int level_v = level[v];\n            for (int &i = iter[v]; i < (int)G[v].size();\
    \ i++) {\n                edge &e = G[v][i];\n                if (level_v <= level[e.to]\
    \ || G[e.to][e.rev].cap == 0) continue;\n                C d = self(self, e.to,\
    \ min(up - res, G[e.to][e.rev].cap));\n                if (d <= 0) continue;\n\
    \                G[v][i].cap += d;\n                G[e.to][e.rev].cap -= d;\n\
    \                res += d;\n                if (res == up) return res;\n     \
    \       }\n            level[v] = G.size();\n            return res;\n       \
    \ };\n\n        C flow = 0;\n        while (flow < flow_limit) {\n           \
    \ bfs();\n            if (level[t] == -1) break;\n            fill(iter.begin(),\
    \ iter.end(), 0);\n            C f = dfs(dfs, t, flow_limit - flow);\n       \
    \     if (!f) break;\n            flow += f;\n        }\n        return flow;\n\
    \    }\n\n    C get_flow(int idx) {\n        return get_rev(G[pos[idx].first][pos[idx].second]).cap;\n\
    \    }\n\n    vector<bool> min_cut(int s) {\n        vector<bool> res(G.size());\n\
    \        queue<int> q;\n        q.push(s);\n        while (!q.empty()) {\n   \
    \         auto v = q.front();\n            q.pop();\n            res[v] = true;\n\
    \            for (auto &e : G[v]) {\n                if (e.cap > 0 && !res[e.to])\
    \ {\n                    res[e.to] = true;\n                    q.push(e.to);\n\
    \                }\n            }\n        }\n        return res;\n    }\n};\n"
  code: "template<class C> struct MaxFlow {\n    vector<pair<int, int>> pos;\n   \
    \ struct edge {\n        int to, rev;\n        C cap;\n    };\n    vector<vector<edge>>\
    \ G;\n    edge &get_rev(edge &e) { return G[e.to][e.rev]; }\n\n    MaxFlow(int\
    \ n) : G(n) {}\n\n    int add_edge(int from, int to, C cap) {\n        G[from].push_back({to,\
    \ (int)G[to].size(), cap});\n        G[to].push_back({from, (int)G[from].size()\
    \ - 1, 0});\n        pos.push_back({from, (int)G[from].size() - 1});\n       \
    \ return (int)pos.size() - 1;\n    }\n\n    C max_flow(int s, int t) {\n     \
    \   return max_flow(s, t, numeric_limits<C>::max());\n    }\n    C max_flow(int\
    \ s, int t, C flow_limit) {\n        vector<int> level(G.size()), iter(G.size());\n\
    \        queue<int> que;\n\n        auto bfs = [&]() {\n            fill(level.begin(),\
    \ level.end(), -1);\n            level[s] = 0;\n            queue<int> ().swap(que);\n\
    \            que.push(s);\n            while (!que.empty()) {\n              \
    \  int v = que.front();\n                que.pop();\n                for (auto\
    \ e : G[v]) {\n                    if (e.cap == 0 || level[e.to] >= 0) continue;\n\
    \                    level[e.to] = level[v] + 1;\n                    if (e.to\
    \ == t) return;\n                    que.push(e.to);\n                }\n    \
    \        }\n        };\n\n        auto dfs = [&](auto &&self, int v, C up) {\n\
    \            if (v == s) return up;\n            C res = 0;\n            int level_v\
    \ = level[v];\n            for (int &i = iter[v]; i < (int)G[v].size(); i++) {\n\
    \                edge &e = G[v][i];\n                if (level_v <= level[e.to]\
    \ || G[e.to][e.rev].cap == 0) continue;\n                C d = self(self, e.to,\
    \ min(up - res, G[e.to][e.rev].cap));\n                if (d <= 0) continue;\n\
    \                G[v][i].cap += d;\n                G[e.to][e.rev].cap -= d;\n\
    \                res += d;\n                if (res == up) return res;\n     \
    \       }\n            level[v] = G.size();\n            return res;\n       \
    \ };\n\n        C flow = 0;\n        while (flow < flow_limit) {\n           \
    \ bfs();\n            if (level[t] == -1) break;\n            fill(iter.begin(),\
    \ iter.end(), 0);\n            C f = dfs(dfs, t, flow_limit - flow);\n       \
    \     if (!f) break;\n            flow += f;\n        }\n        return flow;\n\
    \    }\n\n    C get_flow(int idx) {\n        return get_rev(G[pos[idx].first][pos[idx].second]).cap;\n\
    \    }\n\n    vector<bool> min_cut(int s) {\n        vector<bool> res(G.size());\n\
    \        queue<int> q;\n        q.push(s);\n        while (!q.empty()) {\n   \
    \         auto v = q.front();\n            q.pop();\n            res[v] = true;\n\
    \            for (auto &e : G[v]) {\n                if (e.cap > 0 && !res[e.to])\
    \ {\n                    res[e.to] = true;\n                    q.push(e.to);\n\
    \                }\n            }\n        }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_structure/MaxFlow.hpp
  requiredBy: []
  timestamp: '2023-07-20 13:44:33+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-Matching-on-Bipartite-Graph.test.cpp
documentation_of: Data_structure/MaxFlow.hpp
layout: document
title: MaxFlow
---

## コンストラクタ

```cpp
MaxFlow<C> mf(int N)
```

- $N$頂点のグラフを作成する．何も辺が存在しない．
- `C` は `long long` もしくは `int` であること．


## add_edge

```cpp
int add_edge(int from, int to, C cap)
```

- `from`から`to`へ容量`cap`の辺を追加する。
- 以降、追加した辺の本数を $M$ とする。
- 追加した辺の番号を返す。

##### 制約

- $0 \leq from, to < N$
- $0 \leq cap$

##### 計算量

- (ならし？) $O(1)$


## max_flow

```cpp
(1) C max_flow(int s, int t)
(2) C max_flow(int s, int t, C flow_limit)
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
C get_flow(int idx)
```

- `max_flow(s, t)` を呼んだ後に呼ぶことを想定。頂点 `from` から頂点 `to` へ流れた流量を返す。
- `idx` は追加された辺の番号である。

##### 制約

- $0 \leq from, to < N$

##### 計算量

- $O(1)$