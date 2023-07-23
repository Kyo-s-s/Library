---
title: LazySegtree
documentation_of: //Data_structure/LazySegtree.cpp
---

モノイド$(S, +, e)$と、それに対する作用素モノイド$(F, \circ, id)$ であり、
- $\forall a \in S ~~ id(a) = a$
- $\forall a, b \in S, \forall f \in F ~~ f(a + b) = f(a) + f(b)$
- $\forall a \in S, \forall f, g \in F ~~ f(g(a)) = (f \circ g)(a)$
を乗せる。

$a_0, a_1, \ldots, a_{N-1} \in S$ について、
- $a_l + \cdots + a_{r-1}$ を返す(prod)
- $a_l + \cdots + a_{r-1}$ に $f$ を作用させる(apply)
がともに $O(\log N)$ でできる。

たとえば区間加算区間最小取得なら、
```cpp
struct M {
    using T = long long;
    static T op(T a, T b) { return min(a, b); }
    static T e() { return INF; }
};
struct O {
    using T = long long;
    static T op(T a, T b) { return a + b; }
    static T e() { return 0; }
};
M::T fn(O::T f, M::T x) { return x + f; }
```
とする。

ACLと、
- `S` -> `M::T`
- `op` -> `M::op`
- `e` -> `M::e`
- `F` -> `O::T`
- `mapping` -> `fn`
- `composition` -> `O::op`
- `id` -> `O::e`

と対応している。

## コンストラクタ
```cpp
(1) LazySegtree<M, O, fn> seg(int N)
(2) LazySegtree<M, O, fn> seg(vector<M::T> v)
```
- (1) 長さ`N`ですべて`M::e()`の数列で初期化
- (2) `v`の内容で初期化

##### 計算量
- $O(N)$

## set
```cpp
void seg.set(int p, M::T x)
```
`a[p]`に`x`を代入する。

##### 制約
- $0 \leq p < N$

##### 計算量
- $O(\log N)$

## get
```cpp
M::T seg.get(int p)
```
`a[p]`の値を取得する。

##### 制約
- $0 \leq p < N$

##### 計算量
- $O(\log N)$

## prod
```cpp
M::T seg.prod(int l, int r)
```
`a[l],...,a[r-1]`の和を返す。

##### 制約
- $0 \leq l \leq r \leq N$

##### 計算量
- $O(\log N)$


## all_prod
```cpp
M::T seg.all_prod()
```
`a[0],...,a[N-1]`の和を返す。

##### 計算量
- $O(1)$

## apply
```cpp
(1) void seg.prod(int p, O::T f)
(2) void seg.prod(int l, int r, O::T f)
```
- (1) `a[p]`に`f`を作用させる
- (2) `a[l],...,a[r-1]`に`f`を作用させる

##### 制約
- (1) $0 \leq p < N$
- (2) $0 \leq l \leq r \leq N$

##### 計算量
- $O(\log N)$

