---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-static-range-frequency.test.cpp
    title: Test/yosupo-static-range-frequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Data_structure/MergeTree.hpp\"\ntemplate<typename T> \n\
    concept Monoid = requires {\n    typename T::T;\n    { T::op(std::declval<typename\
    \ T::T>(), std::declval<typename T::T>()) } -> std::same_as<typename T::T>;\n\
    \    { T::e() } -> std::same_as<typename T::T>;\n};\n\ntemplate<class T, Monoid\
    \ M>\nstruct MergeTree {\n    using S = typename M::T;\n  public:\n\n    MergeTree(int\
    \ n, std::function<T(int, int)> f) : n(n) {\n        while((1 << log) < n) log++;\n\
    \        size = 1 << log;\n        d = vector<T> (2 * size, T());\n        auto\
    \ init = [&](auto &&init, int l, int r, int k) -> void {\n            d[k] = f(l,\
    \ min(r, n));\n            if((int)d.size() <= 2 * k) return;\n            int\
    \ m = (l + r) / 2;\n            init(init, l, m, 2 * k);\n            init(init,\
    \ m, r, 2 * k + 1);\n        };\n        init(init, 0, size, 1);\n    }\n\n  \
    \  S prod(int l, int r, std::function<S(const T&)> g) {\n        assert(0 <= l\
    \ && l <= r && r <= n);\n        S sml = M::e(), smr = M::e();\n        l += size;\
    \ r += size;\n        while (l < r) {\n            if (l & 1) sml = M::op(sml,\
    \ g(d[l++]));\n            if (r & 1) smr = M::op(g(d[--r]), smr);\n         \
    \   l >>= 1; r >>= 1;\n        }\n        return M::op(sml, smr);\n    }\n\n \
    \ private:\n    int n, size, log = 0;\n    vector<T> d;\n};\n"
  code: "template<typename T> \nconcept Monoid = requires {\n    typename T::T;\n\
    \    { T::op(std::declval<typename T::T>(), std::declval<typename T::T>()) } ->\
    \ std::same_as<typename T::T>;\n    { T::e() } -> std::same_as<typename T::T>;\n\
    };\n\ntemplate<class T, Monoid M>\nstruct MergeTree {\n    using S = typename\
    \ M::T;\n  public:\n\n    MergeTree(int n, std::function<T(int, int)> f) : n(n)\
    \ {\n        while((1 << log) < n) log++;\n        size = 1 << log;\n        d\
    \ = vector<T> (2 * size, T());\n        auto init = [&](auto &&init, int l, int\
    \ r, int k) -> void {\n            d[k] = f(l, min(r, n));\n            if((int)d.size()\
    \ <= 2 * k) return;\n            int m = (l + r) / 2;\n            init(init,\
    \ l, m, 2 * k);\n            init(init, m, r, 2 * k + 1);\n        };\n      \
    \  init(init, 0, size, 1);\n    }\n\n    S prod(int l, int r, std::function<S(const\
    \ T&)> g) {\n        assert(0 <= l && l <= r && r <= n);\n        S sml = M::e(),\
    \ smr = M::e();\n        l += size; r += size;\n        while (l < r) {\n    \
    \        if (l & 1) sml = M::op(sml, g(d[l++]));\n            if (r & 1) smr =\
    \ M::op(g(d[--r]), smr);\n            l >>= 1; r >>= 1;\n        }\n        return\
    \ M::op(sml, smr);\n    }\n\n  private:\n    int n, size, log = 0;\n    vector<T>\
    \ d;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_structure/MergeTree.hpp
  requiredBy: []
  timestamp: '2024-02-04 01:47:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-static-range-frequency.test.cpp
documentation_of: Data_structure/MergeTree.hpp
layout: document
title: MergeTree
---


Merge Sort Tree を抽象化(?) したもの。

数列 $A = (A_1, A_2, \ldots, A_N)$ が与えられて、区間 $[l, r)$ に値 $x$ が出現する回数は何回か？みたいなクエリに答えることができる。

このクエリなら、
```cpp
using T = unordered_map<int, int>;
struct M = {
    using T = int;
    static T op(T a, T b) { return a + b; }
    static T e() { return 0; }
}
```

```cpp
auto f = [&A](int l, int r) {
    unordered_map<int, int> mp;
    for (int i = l; i < r; ++i) {
        mp[A[i]]++;
    }
    return mp;
}
```

として、 `MergeTree<T, M> seg(N, f)` とすればよい。二分木の各ノードでは、その区間に出現する値の種類とその出現回数を持っている。

クエリには、
```cpp
auto g = [&x](const T &t) {
    return t.count(x) ? t[x] : 0;
}
```
として、 `seg.prod(l, r, g)` とすればよい。

各ノードにその区間をソートした配列を持たせると、 Merge Sort Tree になる。
さらに改造することで、 https://atcoder.jp/contests/abc339/submissions/49978210 こういうのにこたえられるようになる。


## コンストラクタ
```cpp
MergeTree<T, M> seg(int N, function<T(int, int)> f)
```
- 要素数を `N` とし、`MergeTree` を構築する。 `f` は、区間 $[l, r)$ から状態 `T` への写像。
- `M` はモノイド。

## prod
```
M::T seg.prod(int l, int r, function<M::T(T)>)
```
- 区間 $[l, r)$ に `f` を作用させた結果を返す。

