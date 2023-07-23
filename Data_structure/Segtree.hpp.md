---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-Point-Add-Range-Sum.test.cpp
    title: Test/yosupo-Point-Add-Range-Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Data_structure/Segtree.hpp\"\ntemplate<class M> struct Segtree\
    \ {\n  public:\n    using S = typename M::T;\n\n    Segtree() : Segtree(0) {}\n\
    \    Segtree(int n) : Segtree(vector<S> (n, M::e())) {}\n    Segtree(const vector<S>\
    \ &v) : n(int(v.size())) { \n        while((1 << log) < n) log++;\n        size\
    \ = 1 << log;\n        d = vector<S> (2 * size, M::e());\n        for(int i =\
    \ 0; i < n; i++) d[size + i] = v[i];\n        for(int i = size - 1; i >= 1; i--)\
    \ update(i);\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p\
    \ < n);\n        p += size;\n        d[p] = x;\n        for(int i = 1; i <= log;\
    \ i++) update(p >> i);\n    }\n\n    S get(int p) {\n        assert(0 <= p &&\
    \ p < n);\n        return d[p + size];\n    }\n\n    S prod(int l, int r) {\n\
    \        assert(0 <= l && l <= r && r <= n);\n        S sml = M::e(), smr = M::e();\n\
    \        l += size; r += size;\n        while(l < r) {\n            if(l & 1)\
    \ sml = M::op(sml, d[l++]);\n            if(r & 1) smr = M::op(d[--r], smr);\n\
    \            l >>= 1; r >>= 1;\n        }\n        return M::op(sml, smr);\n \
    \   }\n\n    S all_prod(){ return d[1]; }\n\n\n  private:\n    int n, size, log\
    \ = 0;\n    vector<S> d;\n    void update(int k){ d[k] = M::op(d[k * 2], d[k *\
    \ 2 + 1]); }\n\n};\n"
  code: "template<class M> struct Segtree {\n  public:\n    using S = typename M::T;\n\
    \n    Segtree() : Segtree(0) {}\n    Segtree(int n) : Segtree(vector<S> (n, M::e()))\
    \ {}\n    Segtree(const vector<S> &v) : n(int(v.size())) { \n        while((1\
    \ << log) < n) log++;\n        size = 1 << log;\n        d = vector<S> (2 * size,\
    \ M::e());\n        for(int i = 0; i < n; i++) d[size + i] = v[i];\n        for(int\
    \ i = size - 1; i >= 1; i--) update(i);\n    }\n\n    void set(int p, S x) {\n\
    \        assert(0 <= p && p < n);\n        p += size;\n        d[p] = x;\n   \
    \     for(int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S get(int p)\
    \ {\n        assert(0 <= p && p < n);\n        return d[p + size];\n    }\n\n\
    \    S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <= n);\n   \
    \     S sml = M::e(), smr = M::e();\n        l += size; r += size;\n        while(l\
    \ < r) {\n            if(l & 1) sml = M::op(sml, d[l++]);\n            if(r &\
    \ 1) smr = M::op(d[--r], smr);\n            l >>= 1; r >>= 1;\n        }\n   \
    \     return M::op(sml, smr);\n    }\n\n    S all_prod(){ return d[1]; }\n\n\n\
    \  private:\n    int n, size, log = 0;\n    vector<S> d;\n    void update(int\
    \ k){ d[k] = M::op(d[k * 2], d[k * 2 + 1]); }\n\n};"
  dependsOn: []
  isVerificationFile: false
  path: Data_structure/Segtree.hpp
  requiredBy: []
  timestamp: '2023-07-23 08:43:48+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-Point-Add-Range-Sum.test.cpp
documentation_of: Data_structure/Segtree.hpp
layout: document
title: Segtree
---

セグメント木 モノイドを渡す

## モノイド
集合 $S$ とその二項演算 $\cdot : S \times S \to S$ で、
- $\forall a, b, c \in S~~(a \cdot b) \cdot c = a \cdot (b \cdot c)$
- $\exist e \in S~~\mathrm{s.t.}~~\forall a \in S~~ e \cdot a = a \cdot e = a$

を満たすとき、$(S, \cdot, e)$ をモノイドという。

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