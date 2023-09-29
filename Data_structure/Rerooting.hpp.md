---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/yosupo-Tree-Diameter-Rerooting.test.cpp
    title: Test/yosupo-Tree-Diameter-Rerooting.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Data_structure/Rerooting.hpp\"\ntemplate<typename T> \n\
    concept Monoid = requires {\n    typename T::T;\n    { T::op(std::declval<typename\
    \ T::T>(), std::declval<typename T::T>()) } -> std::same_as<typename T::T>;\n\
    \    { T::e() } -> std::same_as<typename T::T>;\n};\n\ntemplate<Monoid M> struct\
    \ Rerooting {\n  public:\n    using E = typename M::T;\n    Rerooting(int N) :\
    \ N(N) {\n        G.resize(N);\n    }\n\n    int add_edge(int from, int to) {\n\
    \        assert(edge_count < N - 1);\n        G[from].push_back(edge{to, edge_count});\n\
    \        G[to].push_back(edge{from, edge_count});\n        return edge_count++;\n\
    \    }\n\n    template<class V>\n    vector<V> solve(function<E(V, int)> put_edge,\
    \ function<V(E, int)> put_node) {\n        return solve<V>(put_edge, put_node,\
    \ put_node);\n    }\n\n    template<class V> \n    vector<V> solve(\n        function<E(V,\
    \ int)> put_edge, \n        function<V(E, int)> put_node,\n        function<V(E,\
    \ int)> solve_node\n    ) {\n        vector<vector<V>> dp(N);\n        for (int\
    \ i = 0; i < N; i++) dp[i].resize(G[i].size());\n        auto dfs = [&](auto dfs,\
    \ int now, int par) -> V {\n            int deg = (int)G[now].size();\n      \
    \      E res = M::e();\n            for (int i = 0; i < deg; i++) {\n        \
    \        auto [to, id] = G[now][i];\n                if (to == par) continue;\n\
    \                dp[now][i] = dfs(dfs, to, now);\n                res = M::op(res,\
    \ put_edge(dp[now][i], id));\n            }\n            return put_node(res,\
    \ now);\n        };\n        dfs(dfs, 0, -1);\n        vector<V> ans(N);\n   \
    \     auto reroot = [&](auto reroot, int now, int par, const optional<V> &v) ->\
    \ void {\n            int deg = (int)G[now].size();\n            if (v.has_value())\
    \ {\n                for (int i = 0; i < deg; i++) if (G[now][i].to == par) {\n\
    \                    dp[now][i] = v.value();\n                }\n            }\n\
    \            vector<E> L(deg + 1, M::e()), R(deg + 1, M::e());\n            for\
    \ (int i = 0; i < deg; i++) {\n                L[i + 1] = M::op(L[i], put_edge(dp[now][i],\
    \ G[now][i].id));\n            }\n            for (int i = deg - 1; i >= 0; i--)\
    \ {\n                R[i] = M::op(R[i + 1], put_edge(dp[now][i], G[now][i].id));\n\
    \            }\n\n            ans[now] = solve_node(L[deg], now);\n          \
    \  for (int i = 0; i < deg; i++) {\n                int u = G[now][i].to;\n  \
    \              if (u == par) continue;\n                reroot(reroot, u, now,\
    \ put_node(M::op(L[i], R[i + 1]), now));\n            }\n        };\n        reroot(reroot,\
    \ 0, -1, nullopt);\n        return ans;\n    }\n\n  private:\n    int N;\n   \
    \ int edge_count = 0;\n    struct edge {\n        int to, id;\n    };\n    vector<vector<edge>>\
    \ G;\n};\n"
  code: "template<typename T> \nconcept Monoid = requires {\n    typename T::T;\n\
    \    { T::op(std::declval<typename T::T>(), std::declval<typename T::T>()) } ->\
    \ std::same_as<typename T::T>;\n    { T::e() } -> std::same_as<typename T::T>;\n\
    };\n\ntemplate<Monoid M> struct Rerooting {\n  public:\n    using E = typename\
    \ M::T;\n    Rerooting(int N) : N(N) {\n        G.resize(N);\n    }\n\n    int\
    \ add_edge(int from, int to) {\n        assert(edge_count < N - 1);\n        G[from].push_back(edge{to,\
    \ edge_count});\n        G[to].push_back(edge{from, edge_count});\n        return\
    \ edge_count++;\n    }\n\n    template<class V>\n    vector<V> solve(function<E(V,\
    \ int)> put_edge, function<V(E, int)> put_node) {\n        return solve<V>(put_edge,\
    \ put_node, put_node);\n    }\n\n    template<class V> \n    vector<V> solve(\n\
    \        function<E(V, int)> put_edge, \n        function<V(E, int)> put_node,\n\
    \        function<V(E, int)> solve_node\n    ) {\n        vector<vector<V>> dp(N);\n\
    \        for (int i = 0; i < N; i++) dp[i].resize(G[i].size());\n        auto\
    \ dfs = [&](auto dfs, int now, int par) -> V {\n            int deg = (int)G[now].size();\n\
    \            E res = M::e();\n            for (int i = 0; i < deg; i++) {\n  \
    \              auto [to, id] = G[now][i];\n                if (to == par) continue;\n\
    \                dp[now][i] = dfs(dfs, to, now);\n                res = M::op(res,\
    \ put_edge(dp[now][i], id));\n            }\n            return put_node(res,\
    \ now);\n        };\n        dfs(dfs, 0, -1);\n        vector<V> ans(N);\n   \
    \     auto reroot = [&](auto reroot, int now, int par, const optional<V> &v) ->\
    \ void {\n            int deg = (int)G[now].size();\n            if (v.has_value())\
    \ {\n                for (int i = 0; i < deg; i++) if (G[now][i].to == par) {\n\
    \                    dp[now][i] = v.value();\n                }\n            }\n\
    \            vector<E> L(deg + 1, M::e()), R(deg + 1, M::e());\n            for\
    \ (int i = 0; i < deg; i++) {\n                L[i + 1] = M::op(L[i], put_edge(dp[now][i],\
    \ G[now][i].id));\n            }\n            for (int i = deg - 1; i >= 0; i--)\
    \ {\n                R[i] = M::op(R[i + 1], put_edge(dp[now][i], G[now][i].id));\n\
    \            }\n\n            ans[now] = solve_node(L[deg], now);\n          \
    \  for (int i = 0; i < deg; i++) {\n                int u = G[now][i].to;\n  \
    \              if (u == par) continue;\n                reroot(reroot, u, now,\
    \ put_node(M::op(L[i], R[i + 1]), now));\n            }\n        };\n        reroot(reroot,\
    \ 0, -1, nullopt);\n        return ans;\n    }\n\n  private:\n    int N;\n   \
    \ int edge_count = 0;\n    struct edge {\n        int to, id;\n    };\n    vector<vector<edge>>\
    \ G;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_structure/Rerooting.hpp
  requiredBy: []
  timestamp: '2023-09-29 05:46:42+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/yosupo-Tree-Diameter-Rerooting.test.cpp
documentation_of: Data_structure/Rerooting.hpp
layout: document
title: Rerooting
---

全方位木DP
