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
    \    { T::e() } -> std::same_as<typename T::T>;\n};\n\ntemplate<class T>\nstruct\
    \ MergeTree {\n  public:\n\n    MergeTree(int n, std::function<T(int, int)> f)\
    \ : n(n) {\n        while((1 << log) < n) log++;\n        size = 1 << log;\n \
    \       d = vector<T> (2 * size, T());\n        auto init = [&](auto &&init, int\
    \ l, int r, int k) -> void {\n            d[k] = f(l, min(r, n));\n          \
    \  if((int)d.size() <= 2 * k) return;\n            int m = (l + r) / 2;\n    \
    \        init(init, l, m, 2 * k);\n            init(init, m, r, 2 * k + 1);\n\
    \        };\n        init(init, 0, size, 1);\n    }\n\n    void apply(int l, int\
    \ r, std::function<void(T&)> g) {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        l += size; r += size;\n        while (l < r) {\n            if (l & 1)\
    \ g(d[l++]);\n            if (r & 1) g(d[--r]);\n            l >>= 1; r >>= 1;\n\
    \        }\n    }\n\n    template<Monoid M> M::T get(int i, std::function<typename\
    \ M::T(T&)> g) {\n        assert(0 <= i && i < n);\n        typename M::T res\
    \ = M::e();\n        i += size;\n        while (i > 0) {\n            res = M::op(res,\
    \ g(d[i]));\n            i >>= 1;\n        }\n        return res;\n    }\n\n \
    \   template<Monoid M> M::T prod(int l, int r, std::function<typename M::T(const\
    \ T&)> g) {\n        assert(0 <= l && l <= r && r <= n);\n        typename M::T\
    \ sml = M::e(), smr = M::e();\n        l += size; r += size;\n        while (l\
    \ < r) {\n            if (l & 1) sml = M::op(sml, g(d[l++]));\n            if\
    \ (r & 1) smr = M::op(g(d[--r]), smr);\n            l >>= 1; r >>= 1;\n      \
    \  }\n        return M::op(sml, smr);\n    }\n\n  private:\n    int n, size, log\
    \ = 0;\n    vector<T> d;\n};\n"
  code: "template<typename T> \nconcept Monoid = requires {\n    typename T::T;\n\
    \    { T::op(std::declval<typename T::T>(), std::declval<typename T::T>()) } ->\
    \ std::same_as<typename T::T>;\n    { T::e() } -> std::same_as<typename T::T>;\n\
    };\n\ntemplate<class T>\nstruct MergeTree {\n  public:\n\n    MergeTree(int n,\
    \ std::function<T(int, int)> f) : n(n) {\n        while((1 << log) < n) log++;\n\
    \        size = 1 << log;\n        d = vector<T> (2 * size, T());\n        auto\
    \ init = [&](auto &&init, int l, int r, int k) -> void {\n            d[k] = f(l,\
    \ min(r, n));\n            if((int)d.size() <= 2 * k) return;\n            int\
    \ m = (l + r) / 2;\n            init(init, l, m, 2 * k);\n            init(init,\
    \ m, r, 2 * k + 1);\n        };\n        init(init, 0, size, 1);\n    }\n\n  \
    \  void apply(int l, int r, std::function<void(T&)> g) {\n        assert(0 <=\
    \ l && l <= r && r <= n);\n        l += size; r += size;\n        while (l < r)\
    \ {\n            if (l & 1) g(d[l++]);\n            if (r & 1) g(d[--r]);\n  \
    \          l >>= 1; r >>= 1;\n        }\n    }\n\n    template<Monoid M> M::T\
    \ get(int i, std::function<typename M::T(T&)> g) {\n        assert(0 <= i && i\
    \ < n);\n        typename M::T res = M::e();\n        i += size;\n        while\
    \ (i > 0) {\n            res = M::op(res, g(d[i]));\n            i >>= 1;\n  \
    \      }\n        return res;\n    }\n\n    template<Monoid M> M::T prod(int l,\
    \ int r, std::function<typename M::T(const T&)> g) {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        typename M::T sml = M::e(), smr = M::e();\n    \
    \    l += size; r += size;\n        while (l < r) {\n            if (l & 1) sml\
    \ = M::op(sml, g(d[l++]));\n            if (r & 1) smr = M::op(g(d[--r]), smr);\n\
    \            l >>= 1; r >>= 1;\n        }\n        return M::op(sml, smr);\n \
    \   }\n\n  private:\n    int n, size, log = 0;\n    vector<T> d;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_structure/MergeTree.hpp
  requiredBy: []
  timestamp: '2024-02-25 02:01:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-static-range-frequency.test.cpp
documentation_of: Data_structure/MergeTree.hpp
layout: document
title: MergeTree
---


Merge Sort Tree を抽象化(?) したもの。

数列 $A = (A_1, A_2, \ldots, A_N)$ に対し、区間 $[i2^k, (i+1)2^k)~(i, k は整数)$ に `T` 型の値を持つようなデータ構造。

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

として、 `MergeTree<T> seg(N, f)` とすればよい。二分木の各ノードでは、その区間に出現する値の種類とその出現回数を持っている。

クエリには、
```cpp
auto g = [&x](const T &t) {
    return t.count(x) ? t[x] : 0;
}
```
として、 `seg.prod<M>(l, r, g)` とすればよい。

各ノードにその区間をソートした配列を持たせると、 Merge Sort Tree になる。
さらに改造することで、 https://atcoder.jp/contests/abc339/submissions/49978210 こういうのにこたえられるようになる。


以下、使用例

- https://atcoder.jp/contests/abc342/tasks/abc342_g
  - 削除可能priority_queueを乗せる
  - 提出: https://atcoder.jp/contests/abc342/submissions/50619937


## コンストラクタ
```cpp
MergeTree<T, M> seg(int N, function<T(int, int)> f)
```
- 要素数を `N` とし、`MergeTree` を構築する。 `f` は、区間 $[l, r)$ から状態 `T` への写像。
- `M` はモノイド。

## prod
```
M::T seg.prod(int l, int r, function<M::T(T)> f)
```
- 区間 $[l, r)$ に `f` を作用させた結果を返す。
  - ?

## apply
```cpp
void seg.apply(int l, int r, function<void(&T)> g)
```
- 遅延セグ木でapplyされる表面のみに、 `g` を作用させる。遅延評価などは行われない。

## get
```cpp
M::T seg.get(int i, function<M::T(&T)> g)
```
- `i` 番目を含む、管理している区間すべてを `g` で移したのち、 `M` の総和を取る。


