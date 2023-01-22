---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Data_structure/UnionFind.hpp
    title: UnionFind
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"Test/yosupo-UnionFind.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#line 1 \"Data_structure/UnionFind.hpp\"\nstruct UnionFind {\n    int n, cnt;\n\
    \    vector<int> parent;\n    UnionFind() : n(0), cnt(0) {}\n    UnionFind(int\
    \ n) : n(n), cnt(n), parent(n, -1) {}\n\n    int merge(int a, int b) {\n     \
    \   assert(0 <= a && a < n && 0 <= b && b < n);\n        int x = leader(a), y\
    \ = leader(b);\n        if (x == y) return x;\n        if (-parent[x] < -parent[y])\
    \ swap(x, y);\n        parent[x] += parent[y];\n        parent[y] = x;\n     \
    \   cnt--;\n        return x;\n    } \n\n    int leader(int a) {\n        assert(0\
    \ <= a && a < n);\n        if (parent[a] < 0) return a;\n        return parent[a]\
    \ = leader(parent[a]);\n    }\n\n    bool same(int a, int b) {\n        assert(0\
    \ <= a && a < n && 0 <= b && b < n);\n        return leader(a) == leader(b);\n\
    \    }\n\n    int size(int a) {\n        assert(0 <= a && a < n);\n        return\
    \ -parent[leader(a)];\n    }\n\n    int count() { return cnt; }\n\n    vector<vector<int>>\
    \ groups() {\n        vector<int> leader_buf(n), group_size(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        vector<vector<int>> result(n);\n        for (int i = 0; i\
    \ < n; i++) {\n            result[i].reserve(group_size[i]);\n        }\n    \
    \    for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            remove_if(result.begin(), result.end(),\n\
    \                      [&](const vector<int> &v) { return v.empty(); }),\n   \
    \         result.end());\n        return result;\n    }\n};\n#line 7 \"Test/yosupo-UnionFind.cpp\"\
    \n\nint main() {\n\n    int N, Q;\n    cin >> N >> Q;\n    UnionFind uf(N);\n\n\
    \    while (Q--) {\n        int t, u, v;\n        cin >> t >> u >> v;\n      \
    \  if (t == 0) {\n            uf.merge(u, v);\n        } else {\n            cout\
    \ << (uf.same(u, v) ? 1 : 0) << endl;\n        }\n    }\n\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#include \"../Data_structure/UnionFind.hpp\"\n\nint main() {\n\n    int N,\
    \ Q;\n    cin >> N >> Q;\n    UnionFind uf(N);\n\n    while (Q--) {\n        int\
    \ t, u, v;\n        cin >> t >> u >> v;\n        if (t == 0) {\n            uf.merge(u,\
    \ v);\n        } else {\n            cout << (uf.same(u, v) ? 1 : 0) << endl;\n\
    \        }\n    }\n\n}"
  dependsOn:
  - Data_structure/UnionFind.hpp
  isVerificationFile: false
  path: Test/yosupo-UnionFind.cpp
  requiredBy: []
  timestamp: '2023-01-22 13:53:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Test/yosupo-UnionFind.cpp
layout: document
redirect_from:
- /library/Test/yosupo-UnionFind.cpp
- /library/Test/yosupo-UnionFind.cpp.html
title: Test/yosupo-UnionFind.cpp
---
