---
title: DynamicSegtree
documentation_of: ./DynamicSegtree.hpp
---

動的セグメント木 モノイドを渡す

## コンストラクタ
```cpp
(1) DynamicSegtree<Monoid> seg()
(2) DynamicSegtree<Monoid> seg(long long N)
```
- (1): 上限が `LONG_LONG_MAX / 2` の、初期値がすべて`M::e()`のセグメント木を作る。この場合、以降`N = LONG_LONG_MAX / 2`とする。
- (2): 上限が `N` の、初期値がすべて`M::e()`のセグメント木を作る

##### 計算量
- $O(1)$


## set
```cpp
void seg.set(long long p, Monoid::T x)
```
``a[p]`に`x`を代入する。

##### 制約
- $0 \leq p < \text{limit}$

##### 計算量
- $O(\log N)$


## get
```cpp
Monoid::T seg.get(long long p)
```
`a[p]`の値を取得する。

##### 制約
- $0 \leq p < N$

##### 計算量
- $O(\log N)$


## prod
```cpp
Monoid::T seg.prod(long long l, long long r)
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
`Monoid::op(a[0], ..., a[N-1])`を返す。

##### 計算量
- $O(\log N)$



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