---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_structure/Dinic.hpp
    title: Dinic
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
    \n\n#line 1 \"Data_structure/Dinic.hpp\"\ntemplate<class Cap> struct Dinic {\n\
    \  public:\n    Dinic(int n) : n(n), g(n) {}\n\n    int add_edge(int from, int\
    \ to, Cap cap) {\n        int m = (int)edges.size();\n        edges.push_back({from,\
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
    \ g;\n};\n#line 7 \"Test/yosupo-Matching-on-Bipartite-Graph.test.cpp\"\n\nint\
    \ main() {\n    \n    int L, R, M;\n    cin >> L >> R >> M;    \n\n    Dinic<long\
    \ long> dinic(L + R + 2);\n    int s = L + R, t = L + R + 1;\n\n    vector<int>\
    \ idxs(M), A(M), B(M);\n\n    for (int i = 0; i < M; i++) {\n        int a, b;\n\
    \        cin >> a >> b;\n        int idx = dinic.add_edge(a, L + b, 1);\n    \
    \    idxs[i] = idx;\n        A[i] = a;\n        B[i] = b;\n    }\n\n    for (int\
    \ i = 0; i < L; i++) {\n        dinic.add_edge(s, i, 1);\n    }\n    for (int\
    \ i = 0; i < R; i++) {\n        dinic.add_edge(L + i, t, 1);\n    }\n\n    int\
    \ ans = dinic.flow(s, t);\n    cout << ans << \"\\n\";\n    for (int i = 0; i\
    \ < M; i++) {\n        int e = dinic.get_flow(idxs[i]);\n        if (e == 1) {\n\
    \            cout << A[i] << \" \" << B[i] << \"\\n\";\n        }\n    }\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\
    \n\n#include \"../Data_structure/Dinic.hpp\"\n\nint main() {\n    \n    int L,\
    \ R, M;\n    cin >> L >> R >> M;    \n\n    Dinic<long long> dinic(L + R + 2);\n\
    \    int s = L + R, t = L + R + 1;\n\n    vector<int> idxs(M), A(M), B(M);\n\n\
    \    for (int i = 0; i < M; i++) {\n        int a, b;\n        cin >> a >> b;\n\
    \        int idx = dinic.add_edge(a, L + b, 1);\n        idxs[i] = idx;\n    \
    \    A[i] = a;\n        B[i] = b;\n    }\n\n    for (int i = 0; i < L; i++) {\n\
    \        dinic.add_edge(s, i, 1);\n    }\n    for (int i = 0; i < R; i++) {\n\
    \        dinic.add_edge(L + i, t, 1);\n    }\n\n    int ans = dinic.flow(s, t);\n\
    \    cout << ans << \"\\n\";\n    for (int i = 0; i < M; i++) {\n        int e\
    \ = dinic.get_flow(idxs[i]);\n        if (e == 1) {\n            cout << A[i]\
    \ << \" \" << B[i] << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - Data_structure/Dinic.hpp
  isVerificationFile: true
  path: Test/yosupo-Matching-on-Bipartite-Graph.test.cpp
  requiredBy: []
  timestamp: '2023-09-16 04:04:22+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-Matching-on-Bipartite-Graph.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-Matching-on-Bipartite-Graph.test.cpp
- /verify/Test/yosupo-Matching-on-Bipartite-Graph.test.cpp.html
title: Test/yosupo-Matching-on-Bipartite-Graph.test.cpp
---
