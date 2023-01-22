---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-UnionFind.test.cpp
    title: Test/yosupo-UnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Data_structure/UnionFind.hpp\"\nstruct UnionFind {\n   \
    \ int n, cnt;\n    vector<int> parent;\n    UnionFind() : n(0), cnt(0) {}\n  \
    \  UnionFind(int n) : n(n), cnt(n), parent(n, -1) {}\n\n    int merge(int a, int\
    \ b) {\n        assert(0 <= a && a < n && 0 <= b && b < n);\n        int x = leader(a),\
    \ y = leader(b);\n        if (x == y) return x;\n        if (-parent[x] < -parent[y])\
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
    \         result.end());\n        return result;\n    }\n};\n"
  code: "struct UnionFind {\n    int n, cnt;\n    vector<int> parent;\n    UnionFind()\
    \ : n(0), cnt(0) {}\n    UnionFind(int n) : n(n), cnt(n), parent(n, -1) {}\n\n\
    \    int merge(int a, int b) {\n        assert(0 <= a && a < n && 0 <= b && b\
    \ < n);\n        int x = leader(a), y = leader(b);\n        if (x == y) return\
    \ x;\n        if (-parent[x] < -parent[y]) swap(x, y);\n        parent[x] += parent[y];\n\
    \        parent[y] = x;\n        cnt--;\n        return x;\n    } \n\n    int\
    \ leader(int a) {\n        assert(0 <= a && a < n);\n        if (parent[a] < 0)\
    \ return a;\n        return parent[a] = leader(parent[a]);\n    }\n\n    bool\
    \ same(int a, int b) {\n        assert(0 <= a && a < n && 0 <= b && b < n);\n\
    \        return leader(a) == leader(b);\n    }\n\n    int size(int a) {\n    \
    \    assert(0 <= a && a < n);\n        return -parent[leader(a)];\n    }\n\n \
    \   int count() { return cnt; }\n\n    vector<vector<int>> groups() {\n      \
    \  vector<int> leader_buf(n), group_size(n);\n        for (int i = 0; i < n; i++)\
    \ {\n            leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        vector<vector<int>> result(n);\n        for (int i = 0; i\
    \ < n; i++) {\n            result[i].reserve(group_size[i]);\n        }\n    \
    \    for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            remove_if(result.begin(), result.end(),\n\
    \                      [&](const vector<int> &v) { return v.empty(); }),\n   \
    \         result.end());\n        return result;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_structure/UnionFind.hpp
  requiredBy: []
  timestamp: '2023-01-22 13:42:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-UnionFind.test.cpp
documentation_of: Data_structure/UnionFind.hpp
layout: document
title: UnionFind
---

## コンストラクタ
```cpp
UnionFind uf(int N);
```

- $N$ 頂点の UnionFind を構築する

## merge
```cpp
int uf.merge(int a, int b);
```

- $a$ と $b$ を結合する
- 結合後の根が返る 

##### 制約

- $0 \leq x, y < N$

##### 計算量

- ならし $O(\alpha(N))$


## leader
```cpp
int uf.leader(a)
```

- $a$ の根を返す

##### 制約

- $0 \leq a < N$

##### 計算量

- ならし $O(\alpha(N))$


## same
```cpp
bool uf.same(int a, int b);
```

##### 制約

- $0 \leq a, b < N$

##### 計算量

- ならし $O(\alpha(N))$


## size
```cpp
int uf.size(int a);
```

- $a$ が属するグループのサイズを返す

##### 制約

- $0 \leq a < N$

##### 計算量

- ならし $O(\alpha(N))$


## count
```cpp
int uf.count();
```

- グループの数を返す

##### 計算量

- $O(1)$


## groups
```cpp
vector<vector<int>> uf.groups();
```

- グループごとに分けた vector を返す

##### 計算量

- $O(N)$
