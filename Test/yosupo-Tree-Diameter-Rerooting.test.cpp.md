---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_structure/Rerooting.hpp
    title: Rerooting
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
  bundledCode: "#line 1 \"Test/yosupo-Tree-Diameter-Rerooting.test.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\
    \n\n#include<Data_structure/Rerooting.hpp>\n\nstruct M {\n    using T = long long;\n\
    \    static T op(T a, T b) {\n        return max(a, b);\n    }\n    static T e()\
    \ { return 0; }\n};\n\nint main() {\n\n    int N; cin >> N;\n    Rerooting<M>\
    \ tree(N);\n    vector<long long> W(N - 1);\n    struct edge {\n        int to;\n\
    \        long long cost;\n    };\n    vector<vector<edge>> G(N);\n\n    for (int\
    \ i = 0; i < N - 1; i++) {\n        int s, t;\n        long long w;\n        cin\
    \ >> s >> t >> w;\n        int id = tree.add_edge(s, t);\n        W[id] = w;\n\
    \n        G[s].push_back(edge{t, w});\n        G[t].push_back(edge{s, w});\n \
    \   }\n\n    using E = typename M::T;\n    using V = long long;\n\n    auto put_edge\
    \ = [&](V v, int id) -> E {\n        return v + W[id];\n    };\n    auto put_node\
    \ = [&](E e, int v) -> V {\n        return e;\n    };\n    auto dist = tree.solve<V>(put_edge,\
    \ put_node);\n\n    long long max_dist = *max_element(dist.begin(), dist.end());\n\
    \    int start = [&]() -> int {\n        for (int i = 0; i < N; i++) {\n     \
    \       if (dist[i] == max_dist) return i;\n        }\n        assert(false);\n\
    \    }();\n\n    vector<long long> ans;\n    ans.push_back(start);\n    long long\
    \ sum = 0;\n\n    auto dfs = [&](auto dfs, int now, int par) -> void {\n     \
    \   if (sum == max_dist) {\n            cout << max_dist << \" \" << ans.size()\
    \ << endl;\n            for (int i = 0; i < ans.size(); i++) {\n             \
    \   cout << ans[i] << (i + 1 == ans.size() ? \"\\n\" : \" \");\n            }\n\
    \            exit(0);\n        }\n\n        for (auto [to, cost] : G[now]) {\n\
    \            if (to == par) continue;\n            ans.push_back(to);\n      \
    \      sum += cost;\n            dfs(dfs, to, now);\n            ans.pop_back();\n\
    \            sum -= cost;\n        }\n    };\n    dfs(dfs, start, -1);\n\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\
    \n\n#include<Data_structure/Rerooting.hpp>\n\nstruct M {\n    using T = long long;\n\
    \    static T op(T a, T b) {\n        return max(a, b);\n    }\n    static T e()\
    \ { return 0; }\n};\n\nint main() {\n\n    int N; cin >> N;\n    Rerooting<M>\
    \ tree(N);\n    vector<long long> W(N - 1);\n    struct edge {\n        int to;\n\
    \        long long cost;\n    };\n    vector<vector<edge>> G(N);\n\n    for (int\
    \ i = 0; i < N - 1; i++) {\n        int s, t;\n        long long w;\n        cin\
    \ >> s >> t >> w;\n        int id = tree.add_edge(s, t);\n        W[id] = w;\n\
    \n        G[s].push_back(edge{t, w});\n        G[t].push_back(edge{s, w});\n \
    \   }\n\n    using E = typename M::T;\n    using V = long long;\n\n    auto put_edge\
    \ = [&](V v, int id) -> E {\n        return v + W[id];\n    };\n    auto put_node\
    \ = [&](E e, int v) -> V {\n        return e;\n    };\n    auto dist = tree.solve<V>(put_edge,\
    \ put_node);\n\n    long long max_dist = *max_element(dist.begin(), dist.end());\n\
    \    int start = [&]() -> int {\n        for (int i = 0; i < N; i++) {\n     \
    \       if (dist[i] == max_dist) return i;\n        }\n        assert(false);\n\
    \    }();\n\n    vector<long long> ans;\n    ans.push_back(start);\n    long long\
    \ sum = 0;\n\n    auto dfs = [&](auto dfs, int now, int par) -> void {\n     \
    \   if (sum == max_dist) {\n            cout << max_dist << \" \" << ans.size()\
    \ << endl;\n            for (int i = 0; i < ans.size(); i++) {\n             \
    \   cout << ans[i] << (i + 1 == ans.size() ? \"\\n\" : \" \");\n            }\n\
    \            exit(0);\n        }\n\n        for (auto [to, cost] : G[now]) {\n\
    \            if (to == par) continue;\n            ans.push_back(to);\n      \
    \      sum += cost;\n            dfs(dfs, to, now);\n            ans.pop_back();\n\
    \            sum -= cost;\n        }\n    };\n    dfs(dfs, start, -1);\n\n}\n"
  dependsOn:
  - Data_structure/Rerooting.hpp
  isVerificationFile: true
  path: Test/yosupo-Tree-Diameter-Rerooting.test.cpp
  requiredBy: []
  timestamp: '2023-09-29 05:46:42+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-Tree-Diameter-Rerooting.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-Tree-Diameter-Rerooting.test.cpp
- /verify/Test/yosupo-Tree-Diameter-Rerooting.test.cpp.html
title: Test/yosupo-Tree-Diameter-Rerooting.test.cpp
---
