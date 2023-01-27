---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-Static-Range-Sum.test.cpp
    title: Test/yosupo-Static-Range-Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Data_structure/CumulativeSum.hpp\"\ntemplate<class T> struct\
    \ CumulativeSum {\n    int n;\n    vector<T> data; \n    bool builded = false;\n\
    \    CumulativeSum(int n) : n(n), data(n + 1) {}\n    CumulativeSum(const vector<T>\
    \ &v) : n(v.size()), data(n + 1) {\n        for (int i = 0; i < n; i++) {\n  \
    \          data[i + 1] = v[i];\n        }\n    }\n\n    void build() {\n     \
    \   for (int i = 0; i < n; i++) {\n            data[i + 1] += data[i];\n     \
    \   }\n        builded = true;\n    }\n\n    T sum(int r) {\n        if (!builded)\
    \ build();\n        assert(0 <= r && r <= n);\n        return data[r];\n    }\n\
    \n    T sum(int l, int r) {\n        assert(0 <= l && l <= r && r <= n);\n   \
    \     return sum(r) - sum(l);\n    }\n\n};\n"
  code: "template<class T> struct CumulativeSum {\n    int n;\n    vector<T> data;\
    \ \n    bool builded = false;\n    CumulativeSum(int n) : n(n), data(n + 1) {}\n\
    \    CumulativeSum(const vector<T> &v) : n(v.size()), data(n + 1) {\n        for\
    \ (int i = 0; i < n; i++) {\n            data[i + 1] = v[i];\n        }\n    }\n\
    \n    void build() {\n        for (int i = 0; i < n; i++) {\n            data[i\
    \ + 1] += data[i];\n        }\n        builded = true;\n    }\n\n    T sum(int\
    \ r) {\n        if (!builded) build();\n        assert(0 <= r && r <= n);\n  \
    \      return data[r];\n    }\n\n    T sum(int l, int r) {\n        assert(0 <=\
    \ l && l <= r && r <= n);\n        return sum(r) - sum(l);\n    }\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_structure/CumulativeSum.hpp
  requiredBy: []
  timestamp: '2023-01-27 17:37:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-Static-Range-Sum.test.cpp
documentation_of: Data_structure/CumulativeSum.hpp
layout: document
title: CumulativeSum
---

累積和

## コンストラクタ
```cpp
CumulativeSum<T> cum(vector<T> v)
```
- `v`の内容で初期化

##### 計算量
- $O(N)$

## sum
```cpp
(1) T cum.sum(int r)
(2) T cum.sum(int l, int r)
```
- (1): `a[0] + ... + a[r-1]`を返す
- (2): `a[l] + ... + a[r-1]`を返す

##### 制約
- (1): $0 \leq r \leq N$
- (2): $0 \leq l \leq r \leq N$

##### 計算量
- $O(1)$

