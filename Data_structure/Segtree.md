---
title: Segtree
documentation_of: ./Segtree.hpp
---

セグメント木 モノイドを渡す

## モノイド
例えば加法モノイドなら、次のように書く。
```cpp
struct Add_M {
    using T = long long;
    static T e() { return 0; }
    static T op(T x, T y) { return x + y; }
};
```
`T`はモノイドの型名。`e()`は単位元、`op(T x, T y)`は二項演算を返すようにする。

## コンストラクタ
```cpp
(1) Segtree<Monoid> seg(int N)
(2) Segtree<Monoid> seg(vector<Monoid::T> v)
```
- (1): 長さ`N`ですべて`Monoid::e()`の数列で初期化
- (2): `v`の内容で初期化


##### 計算量
- $O(N)$


## set
```cpp
void seg.set(int p, Monoid::T x)
```
`a[p]`に`x`を代入する。

##### 制約
- $0 \leq p < N$

##### 計算量
- $O(\log N)$

## get
```cpp
Monoid::T seg.get(int p)
```
`a[p]`の値を取得する。

##### 制約
- $0 \leq p < N$

##### 計算量
- $O(1)$

## prod
```cpp
Monoid::T seg.prod(int l, int r)
```
`Monoid::op(a[l], ..., a[r-1])`を返す。$l = r$の時は`Monoid::e()`が返る。

##### 制約
- $0 \leq l \leq r \leq N$

##### 計算量
- $O(\log N)$

## all_prod
```cpp
Monoid::T seg.all_prod()
```
`Monoid::op(a[0], ..., a[n-1])`を返す。

##### 計算量
- $O(1)$

TODO: セグ木上の二分探索

## 使いそうなモノイド
### 加法モノイド(区間和取得)
```cpp
struct Add_M {    
    using T = long long;
    static T e() { return 0; }
    static T op(T x, T y) { return x + y; }
};
```
### 最大モノイド(区間最大取得)
```cpp
struct Max_M {    
    using T = long long;
    static T e() { return -INF; }
    static T op(T x, T y) { return max(x, y); }
};
```
### 最小モノイド(区間最小取得)
```cpp
struct Min_M {    
    using T = long long;
    static T e() { return INF; }
    static T op(T x, T y) { return min(x, y); }
};
```
### テンプレート
```cpp
struct Monoid {
    using T = T;
    static T e() { return e; }
    static T op(T x, T y) { return op(x, y); }
}
```