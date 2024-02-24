---
title: MergeTree
documentation_of: ./MergeTree.hpp
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



