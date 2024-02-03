---
title: MergeTree
documentation_of: ./MergeTree.hpp
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

