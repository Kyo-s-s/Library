---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_structure/Tree.hpp
    title: Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"Test/yosupo-Tree-Diameter.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\
    \n\n#line 1 \"Data_structure/Tree.hpp\"\ntemplate<class T = int> struct Tree {\n\
    \    struct edge{ int to; T cost; };\n    vector<vector<edge>> G;\n    vector<vector<int>>\
    \ parent;\n    vector<int> unweighted_dist;\n    vector<T> weighted_dist;\n\n\
    \    Tree(int n) : G(n) {}\n\n    void add_edge(int u, int v) { add_edge(u, v,\
    \ T(1)); }\n    void add_edge(int u, int v, T w) {\n        G[u].push_back({v,\
    \ w});\n        G[v].push_back({u, w});\n    }\n\n    vector<T> calc_dist(int\
    \ root = 0) {\n        vector<T> dist(G.size(), -1); dist[root] = 0;\n       \
    \ queue<int> que; que.push(root);\n        while (!que.empty()) {\n          \
    \  int v = que.front(); que.pop();\n            for (auto e: G[v]) {\n       \
    \         if (dist[e.to] != -1) continue;\n                dist[e.to] = dist[v]\
    \ + e.cost;\n                que.push(e.to);\n            }\n        }\n     \
    \   return dist;\n    }\n\n    tuple<T, int, int> diameter() {\n        vector<T>\
    \ dist = calc_dist();\n        int v = max_element(dist.begin(), dist.end()) -\
    \ dist.begin();\n        dist = calc_dist(v);\n        int u = max_element(dist.begin(),\
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
    \    }\n\n    T dist(int u, int v) {\n        if (weighted_dist.size() == 0) lca_build();\n\
    \        return weighted_dist[u] + weighted_dist[v] - 2 * weighted_dist[lca(u,\
    \ v)];\n    }\n};\n#line 7 \"Test/yosupo-Tree-Diameter.test.cpp\"\n\nint main()\
    \ {\n\n    int N; cin >> N;\n    Tree<long long> tree(N);\n    for (int i = 0;\
    \ i < N - 1; i++) {\n        int a, b;\n        long long c; \n        cin >>\
    \ a >> b >> c;\n\n        tree.add_edge(a, b, c);\n    }\n\n    auto [dist, u,\
    \ v] = tree.diameter();\n    vector<int> path = tree.path(u, v);\n    cout <<\
    \ dist << \" \" << path.size() << endl;\n    for (int i = 0; i < path.size();\
    \ i++) {\n        cout << path[i] << \" \\n\"[i == path.size() - 1];\n    }\n\n\
    }\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\
    \n\n#include \"../Data_structure/Tree.hpp\"\n\nint main() {\n\n    int N; cin\
    \ >> N;\n    Tree<long long> tree(N);\n    for (int i = 0; i < N - 1; i++) {\n\
    \        int a, b;\n        long long c; \n        cin >> a >> b >> c;\n\n   \
    \     tree.add_edge(a, b, c);\n    }\n\n    auto [dist, u, v] = tree.diameter();\n\
    \    vector<int> path = tree.path(u, v);\n    cout << dist << \" \" << path.size()\
    \ << endl;\n    for (int i = 0; i < path.size(); i++) {\n        cout << path[i]\
    \ << \" \\n\"[i == path.size() - 1];\n    }\n\n}\n"
  dependsOn:
  - Data_structure/Tree.hpp
  isVerificationFile: true
  path: Test/yosupo-Tree-Diameter.test.cpp
  requiredBy: []
  timestamp: '2023-05-02 10:52:24+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-Tree-Diameter.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-Tree-Diameter.test.cpp
- /verify/Test/yosupo-Tree-Diameter.test.cpp.html
title: Test/yosupo-Tree-Diameter.test.cpp
---
