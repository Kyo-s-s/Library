---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-Lowest-Common-Ancestor.test.cpp
    title: Test/yosupo-Lowest-Common-Ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-Tree-Diameter.test.cpp
    title: Test/yosupo-Tree-Diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Data_structure/Tree.hpp\"\ntemplate<class T = int> struct\
    \ Tree {\n    struct edge{ int to; T cost; };\n    vector<vector<edge>> G;\n \
    \   vector<vector<int>> parent;\n    vector<int> unweighted_dist;\n    vector<T>\
    \ weighted_dist;\n\n    Tree(int n) : G(n) {}\n\n    void add_edge(int u, int\
    \ v) { add_edge(u, v, T(1)); }\n    void add_edge(int u, int v, T w) {\n     \
    \   G[u].push_back({v, w});\n        G[v].push_back({u, w});\n    }\n\n    vector<T>\
    \ calc_dist(int root = 0) {\n        vector<T> dist(G.size(), -1); dist[root]\
    \ = 0;\n        queue<int> que; que.push(root);\n        while (!que.empty())\
    \ {\n            int v = que.front(); que.pop();\n            for (auto e: G[v])\
    \ {\n                if (dist[e.to] != -1) continue;\n                dist[e.to]\
    \ = dist[v] + e.cost;\n                que.push(e.to);\n            }\n      \
    \  }\n        return dist;\n    }\n\n    tuple<T, int, int> diameter() {\n   \
    \     vector<T> dist = calc_dist();\n        int v = max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\n        dist = calc_dist(v);\n        int u = max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\n        return { dist[u], u, v };\n    }\n\n  \
    \  vector<int> path(int u, int v) {\n        vector<T> dist = calc_dist(u);\n\
    \        vector<int> path;\n        while (v != u) {\n            path.push_back(v);\n\
    \            for (auto e: G[v]) {\n                if (dist[e.to] == dist[v] -\
    \ e.cost) {\n                    v = e.to;\n                    break;\n     \
    \           }\n            }\n        }\n        path.push_back(u);\n        reverse(path.begin(),\
    \ path.end());\n        return path;\n    }\n\n    void lca_build(int root = 0)\
    \ {\n        int V = G.size();\n        int K = 1;\n        while ((1 << K) <\
    \ V) K++;\n        parent.assign(K, vector<int>(V, -1));\n        unweighted_dist.assign(V,\
    \ -1);\n\n        auto unweighted_dfs = [this](auto&& self, int v, int p, int\
    \ d) -> void {\n            parent[0][v] = p;\n            unweighted_dist[v]\
    \ = d;\n            for (auto e: G[v]) {\n                if (e.to == p) continue;\n\
    \                self(self, e.to, v, d + 1);\n            }\n        };\n\n  \
    \      unweighted_dfs(unweighted_dfs, root, -1, 0);\n        for (int k = 0; k\
    \ + 1 < K; k++) {\n            for (int v = 0; v < V; v++) {\n               \
    \ if (parent[k][v] < 0) parent[k + 1][v] = -1;\n                else parent[k\
    \ + 1][v] = parent[k][parent[k][v]];\n            }\n        }\n\n        weighted_dist.assign(V,\
    \ -1); weighted_dist[root] = 0;\n        queue<int> que; que.push(root);\n   \
    \     while (!que.empty()) {\n            int v = que.front(); que.pop();\n  \
    \          for (auto e: G[v]) {\n                if (weighted_dist[e.to] == -1\
    \ || weighted_dist[e.to] > weighted_dist[v] + e.cost) {\n                    weighted_dist[e.to]\
    \ = weighted_dist[v] + e.cost;\n                    que.push(e.to);\n        \
    \        }\n            }\n        }\n    }\n\n    int lca(int u, int v) {\n \
    \       if (parent.size() == 0) lca_build();\n        if (unweighted_dist[u] <\
    \ unweighted_dist[v]) swap(u, v);\n        int K = parent.size();\n        for\
    \ (int k = 0; k < K; k++) {\n            if ((unweighted_dist[u] - unweighted_dist[v])\
    \ >> k & 1) {\n                u = parent[k][u];\n            }\n        }\n \
    \       if (u == v) return u;\n        for (int k = K - 1; k >= 0; k--) {\n  \
    \          if (parent[k][u] != parent[k][v]) {\n                u = parent[k][u];\n\
    \                v = parent[k][v];\n            }\n        }\n        return parent[0][u];\n\
    \    }\n\n    int prev(int u, int k) {\n        if (parent.size() == 0) lca_build();\n\
    \        int K = parent.size();\n        for (int i = 0; i < K; i++) {\n     \
    \       if ((k >> i) & 1) {\n                u = parent[i][u];\n            }\n\
    \        }\n        return u;\n    }\n\n    T dist(int u, int v) {\n        if\
    \ (weighted_dist.size() == 0) lca_build();\n        return weighted_dist[u] +\
    \ weighted_dist[v] - 2 * weighted_dist[lca(u, v)];\n    }\n};\n"
  code: "template<class T = int> struct Tree {\n    struct edge{ int to; T cost; };\n\
    \    vector<vector<edge>> G;\n    vector<vector<int>> parent;\n    vector<int>\
    \ unweighted_dist;\n    vector<T> weighted_dist;\n\n    Tree(int n) : G(n) {}\n\
    \n    void add_edge(int u, int v) { add_edge(u, v, T(1)); }\n    void add_edge(int\
    \ u, int v, T w) {\n        G[u].push_back({v, w});\n        G[v].push_back({u,\
    \ w});\n    }\n\n    vector<T> calc_dist(int root = 0) {\n        vector<T> dist(G.size(),\
    \ -1); dist[root] = 0;\n        queue<int> que; que.push(root);\n        while\
    \ (!que.empty()) {\n            int v = que.front(); que.pop();\n            for\
    \ (auto e: G[v]) {\n                if (dist[e.to] != -1) continue;\n        \
    \        dist[e.to] = dist[v] + e.cost;\n                que.push(e.to);\n   \
    \         }\n        }\n        return dist;\n    }\n\n    tuple<T, int, int>\
    \ diameter() {\n        vector<T> dist = calc_dist();\n        int v = max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\n        dist = calc_dist(v);\n        int u = max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\n        return { dist[u], u, v };\n    }\n\n  \
    \  vector<int> path(int u, int v) {\n        vector<T> dist = calc_dist(u);\n\
    \        vector<int> path;\n        while (v != u) {\n            path.push_back(v);\n\
    \            for (auto e: G[v]) {\n                if (dist[e.to] == dist[v] -\
    \ e.cost) {\n                    v = e.to;\n                    break;\n     \
    \           }\n            }\n        }\n        path.push_back(u);\n        reverse(path.begin(),\
    \ path.end());\n        return path;\n    }\n\n    void lca_build(int root = 0)\
    \ {\n        int V = G.size();\n        int K = 1;\n        while ((1 << K) <\
    \ V) K++;\n        parent.assign(K, vector<int>(V, -1));\n        unweighted_dist.assign(V,\
    \ -1);\n\n        auto unweighted_dfs = [this](auto&& self, int v, int p, int\
    \ d) -> void {\n            parent[0][v] = p;\n            unweighted_dist[v]\
    \ = d;\n            for (auto e: G[v]) {\n                if (e.to == p) continue;\n\
    \                self(self, e.to, v, d + 1);\n            }\n        };\n\n  \
    \      unweighted_dfs(unweighted_dfs, root, -1, 0);\n        for (int k = 0; k\
    \ + 1 < K; k++) {\n            for (int v = 0; v < V; v++) {\n               \
    \ if (parent[k][v] < 0) parent[k + 1][v] = -1;\n                else parent[k\
    \ + 1][v] = parent[k][parent[k][v]];\n            }\n        }\n\n        weighted_dist.assign(V,\
    \ -1); weighted_dist[root] = 0;\n        queue<int> que; que.push(root);\n   \
    \     while (!que.empty()) {\n            int v = que.front(); que.pop();\n  \
    \          for (auto e: G[v]) {\n                if (weighted_dist[e.to] == -1\
    \ || weighted_dist[e.to] > weighted_dist[v] + e.cost) {\n                    weighted_dist[e.to]\
    \ = weighted_dist[v] + e.cost;\n                    que.push(e.to);\n        \
    \        }\n            }\n        }\n    }\n\n    int lca(int u, int v) {\n \
    \       if (parent.size() == 0) lca_build();\n        if (unweighted_dist[u] <\
    \ unweighted_dist[v]) swap(u, v);\n        int K = parent.size();\n        for\
    \ (int k = 0; k < K; k++) {\n            if ((unweighted_dist[u] - unweighted_dist[v])\
    \ >> k & 1) {\n                u = parent[k][u];\n            }\n        }\n \
    \       if (u == v) return u;\n        for (int k = K - 1; k >= 0; k--) {\n  \
    \          if (parent[k][u] != parent[k][v]) {\n                u = parent[k][u];\n\
    \                v = parent[k][v];\n            }\n        }\n        return parent[0][u];\n\
    \    }\n\n    int prev(int u, int k) {\n        if (parent.size() == 0) lca_build();\n\
    \        int K = parent.size();\n        for (int i = 0; i < K; i++) {\n     \
    \       if ((k >> i) & 1) {\n                u = parent[i][u];\n            }\n\
    \        }\n        return u;\n    }\n\n    T dist(int u, int v) {\n        if\
    \ (weighted_dist.size() == 0) lca_build();\n        return weighted_dist[u] +\
    \ weighted_dist[v] - 2 * weighted_dist[lca(u, v)];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_structure/Tree.hpp
  requiredBy: []
  timestamp: '2023-06-03 01:23:23+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-Tree-Diameter.test.cpp
  - Test/yosupo-Lowest-Common-Ancestor.test.cpp
documentation_of: Data_structure/Tree.hpp
layout: document
title: Tree
---

## コンストラクタ

```cpp
(1) Tree tree(int N);
(2) Tree<T> tree(int N);
```

- (1): $N$頂点の重みなし木を作る
- (2): $N$頂点の型`T`の重み付き木を作る



##  add_edge

```cpp
(1) void tree.add_edge(int u, int v)
(2) void tree.add_edge(int u, int v, T w)
```

- (1): $u, v$に重み$1$(=重みなし)の辺を追加する
- (2): $u, v$に重み$w$の辺を追加する

##### 制約

- $0 \leq u, v < N,~u \neq v$

##### 計算量

- $O(1)$



## calc_dist

```cpp
vector<T> tree.calc_dist(int root = 0)
```

- `root`から各頂点の距離が入った配列を返す。`dist[i]` = `root`から$i$までの距離 である。

##### 制約

- $0 \leq root < N$

##### 計算量

- $O(N)$



## diameter

```cpp
tuple<T, int, int> tree.diameter()
```

- 与えられた木の直径、端の2頂点を返す。第1引数が直径、第2, 3引数が端の頂点

##### 計算量

- $O(N)$


## path
```cpp
vector<int> tree.path(int u, int v)
```

- 頂点 $u$ から $v$ までのパスを1つ返す。

##### 制約

- $0 \leq u, v < N$

##### 計算量

- $O(N)$


## lca_build

```cpp
void tree.lca_build(int root = 0)
```

- 根を`root`として、LCAの構築を行う。

##### 制約

- $0 \leq root < N$

##### 計算量

- $O(N \log N)$



## lca

```cpp
int tree.lca(int u, int v)
```

- 頂点$u, v$のLCAを求める。`lca_build`が行われていなかった場合、`root = 0`として`lca_build`が行われる。

##### 制約

- $0 \leq u, v < N$

##### 計算量

- $O(\log N)$



## dist

```cpp
T tree.dist(int u, int v)
```

- 頂点$u, v$間の距離を求める。`lca_build`が行われていなかった場合、`root = 0`として`lca_build`が行われる。

##### 制約

- $0 \leq u, v < N$

##### 計算量

- $O(\log N)$

## prev

```cpp
int tree.prev(int u, int k)
```

- 頂点 $u$ から $k$ 個、根に向かって進んだ時の頂点を返す。存在しない場合、 $-1$ が帰る。
- 下位 $K$ bit を見ているため、それを超える値が $k$ に来ると壊れそう

##### 制約

- $0 \leq u < N$

##### 計算量

- $O(\log k)$
