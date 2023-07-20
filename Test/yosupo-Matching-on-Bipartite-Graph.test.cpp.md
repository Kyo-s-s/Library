---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_structure/MaxFlow.hpp
    title: MaxFlow
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"Test/yosupo-Matching-on-Bipartite-Graph.test.cpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\
    \n\n#line 1 \"Data_structure/MaxFlow.hpp\"\ntemplate<class C> struct MaxFlow {\n\
    \    vector<pair<int, int>> pos;\n    struct edge {\n        int to, rev;\n  \
    \      C cap;\n    };\n    vector<vector<edge>> G;\n    edge &get_rev(edge &e)\
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
    \                }\n            }\n        }\n        return res;\n    }\n};\n\
    #line 7 \"Test/yosupo-Matching-on-Bipartite-Graph.test.cpp\"\n\nint main() {\n\
    \    \n    int L, R, M;\n    cin >> L >> R >> M;    \n\n    MaxFlow<long long>\
    \ graph(L + R + 2);\n    int s = L + R, t = L + R + 1;\n\n    vector<int> idxs(M),\
    \ A(M), B(M);\n\n    for (int i = 0; i < M; i++) {\n        int a, b;\n      \
    \  cin >> a >> b;\n        int idx = graph.add_edge(a, L + b, 1);\n        idxs[i]\
    \ = idx;\n        A[i] = a;\n        B[i] = b;\n    }\n\n    for (int i = 0; i\
    \ < L; i++) {\n        graph.add_edge(s, i, 1);\n    }\n    for (int i = 0; i\
    \ < R; i++) {\n        graph.add_edge(L + i, t, 1);\n    }\n\n    int ans = graph.max_flow(s,\
    \ t);\n    cout << ans << \"\\n\";\n    for (int i = 0; i < M; i++) {\n      \
    \  int e = graph.get_flow(idxs[i]);\n        if (e == 1) {\n            cout <<\
    \ A[i] << \" \" << B[i] << \"\\n\";\n        }\n    }\n\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\
    \n\n#include \"../Data_structure/MaxFlow.hpp\"\n\nint main() {\n    \n    int\
    \ L, R, M;\n    cin >> L >> R >> M;    \n\n    MaxFlow<long long> graph(L + R\
    \ + 2);\n    int s = L + R, t = L + R + 1;\n\n    vector<int> idxs(M), A(M), B(M);\n\
    \n    for (int i = 0; i < M; i++) {\n        int a, b;\n        cin >> a >> b;\n\
    \        int idx = graph.add_edge(a, L + b, 1);\n        idxs[i] = idx;\n    \
    \    A[i] = a;\n        B[i] = b;\n    }\n\n    for (int i = 0; i < L; i++) {\n\
    \        graph.add_edge(s, i, 1);\n    }\n    for (int i = 0; i < R; i++) {\n\
    \        graph.add_edge(L + i, t, 1);\n    }\n\n    int ans = graph.max_flow(s,\
    \ t);\n    cout << ans << \"\\n\";\n    for (int i = 0; i < M; i++) {\n      \
    \  int e = graph.get_flow(idxs[i]);\n        if (e == 1) {\n            cout <<\
    \ A[i] << \" \" << B[i] << \"\\n\";\n        }\n    }\n\n}"
  dependsOn:
  - Data_structure/MaxFlow.hpp
  isVerificationFile: true
  path: Test/yosupo-Matching-on-Bipartite-Graph.test.cpp
  requiredBy: []
  timestamp: '2023-07-20 13:44:33+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-Matching-on-Bipartite-Graph.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-Matching-on-Bipartite-Graph.test.cpp
- /verify/Test/yosupo-Matching-on-Bipartite-Graph.test.cpp.html
title: Test/yosupo-Matching-on-Bipartite-Graph.test.cpp
---
