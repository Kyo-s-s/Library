---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/aoj-DSL-2-H.test.cpp
    title: Test/aoj-DSL-2-H.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/aoj-DSL-2-I.test.cpp
    title: Test/aoj-DSL-2-I.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Data_structure/LazySegtree.hpp\"\ntemplate <class M, class\
    \ O, auto fn> struct LazySegtree {\n    using S = typename M::T;\n    using F\
    \ = typename O::T;\n    static_assert(is_convertible_v<decltype(fn), std::function<S(F,\
    \ S)>>);\n\n  public:\n    LazySegtree() : LazySegtree(0) {}\n    LazySegtree(int\
    \ n) : LazySegtree(std::vector<S>(n, M::e())) {}\n    LazySegtree(const std::vector<S>&\
    \ v) : n(int(v.size())) {\n        while ((1 << log) < n) log++;\n        size\
    \ = 1 << log;\n        d = vector<S>(2 * size, M::e());\n        lz = vector<F>(size,\
    \ O::e());\n        for (int i = 0; i < n; i++) d[size + i] = v[i];\n        for\
    \ (int i = size - 1; i >= 1; i--) update(i);\n    }\n\n    void set(int p, S x)\
    \ {\n        assert(0 <= p && p < n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n        for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n    }\n\n    S get(int p) {\n        assert(0\
    \ <= p && p < n);\n        p += size;\n        for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n        return d[p];\n    }\n\n    S prod(int l, int r) {\n \
    \       assert(0 <= l && l <= r && r <= n);\n        if (l == r) return M::e();\n\
    \        l += size; r += size;\n        for (int i = log; i >= 1; i--) {\n   \
    \         if (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) <<\
    \ i) != r) push(r >> i);\n        }\n        S sml = M::e(), smr = M::e();\n \
    \       while (l < r) {\n            if (l & 1) sml = M::op(sml, d[l++]);\n  \
    \          if (r & 1) smr = M::op(d[--r], smr);\n            l >>= 1; r >>= 1;\n\
    \        }\n        return M::op(sml, smr);\n    }\n\n    S all_prod() { return\
    \ d[1]; }\n\n    void apply(int p, F f) {\n        assert(0 <= p && p < n);\n\
    \        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n  \
    \      d[p] = fn(f, d[p]);\n        for (int i = 1; i <= log; i++) update(p >>\
    \ i);\n    }\n    void apply(int l, int r, F f) {\n        assert(0 <= l && l\
    \ <= r && r <= n);\n        if (l == r) return;\n        l += size; r += size;\n\
    \        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
    \ l) push(l >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \        }\n        {\n            int l2 = l, r2 = r;\n            while (l <\
    \ r) {\n                if (l & 1) all_apply(l++, f);\n                if (r &\
    \ 1) all_apply(--r, f);\n                l >>= 1; r >>= 1;\n            }\n  \
    \          l = l2; r = r2;\n        }\n        for (int i = 1; i <= log; i++)\
    \ {\n            if (((l >> i) << i) != l) update(l >> i);\n            if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n  private:\n  \
    \  int n, size, log = 0;\n    vector<S> d;\n    vector<F> lz;\n\n    void update(int\
    \ k) { d[k] = M::op(d[2 * k], d[2 * k + 1]); }\n    void all_apply(int k, F f)\
    \ {\n        d[k] = fn(f, d[k]);\n        if (k < size) lz[k] = O::op(f, lz[k]);\n\
    \    }\n    void push(int k) {\n        all_apply(2 * k, lz[k]);\n        all_apply(2\
    \ * k + 1, lz[k]);\n        lz[k] = O::e();\n    }\n};\n"
  code: "template <class M, class O, auto fn> struct LazySegtree {\n    using S =\
    \ typename M::T;\n    using F = typename O::T;\n    static_assert(is_convertible_v<decltype(fn),\
    \ std::function<S(F, S)>>);\n\n  public:\n    LazySegtree() : LazySegtree(0) {}\n\
    \    LazySegtree(int n) : LazySegtree(std::vector<S>(n, M::e())) {}\n    LazySegtree(const\
    \ std::vector<S>& v) : n(int(v.size())) {\n        while ((1 << log) < n) log++;\n\
    \        size = 1 << log;\n        d = vector<S>(2 * size, M::e());\n        lz\
    \ = vector<F>(size, O::e());\n        for (int i = 0; i < n; i++) d[size + i]\
    \ = v[i];\n        for (int i = size - 1; i >= 1; i--) update(i);\n    }\n\n \
    \   void set(int p, S x) {\n        assert(0 <= p && p < n);\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n   \
    \     for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S get(int p)\
    \ {\n        assert(0 <= p && p < n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r)\
    \ return M::e();\n        l += size; r += size;\n        for (int i = log; i >=\
    \ 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n           \
    \ if (((r >> i) << i) != r) push(r >> i);\n        }\n        S sml = M::e(),\
    \ smr = M::e();\n        while (l < r) {\n            if (l & 1) sml = M::op(sml,\
    \ d[l++]);\n            if (r & 1) smr = M::op(d[--r], smr);\n            l >>=\
    \ 1; r >>= 1;\n        }\n        return M::op(sml, smr);\n    }\n\n    S all_prod()\
    \ { return d[1]; }\n\n    void apply(int p, F f) {\n        assert(0 <= p && p\
    \ < n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n        d[p] = fn(f, d[p]);\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n    void apply(int l, int r, F f) {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        if (l == r) return;\n        l += size; r += size;\n\
    \        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
    \ l) push(l >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \        }\n        {\n            int l2 = l, r2 = r;\n            while (l <\
    \ r) {\n                if (l & 1) all_apply(l++, f);\n                if (r &\
    \ 1) all_apply(--r, f);\n                l >>= 1; r >>= 1;\n            }\n  \
    \          l = l2; r = r2;\n        }\n        for (int i = 1; i <= log; i++)\
    \ {\n            if (((l >> i) << i) != l) update(l >> i);\n            if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n  private:\n  \
    \  int n, size, log = 0;\n    vector<S> d;\n    vector<F> lz;\n\n    void update(int\
    \ k) { d[k] = M::op(d[2 * k], d[2 * k + 1]); }\n    void all_apply(int k, F f)\
    \ {\n        d[k] = fn(f, d[k]);\n        if (k < size) lz[k] = O::op(f, lz[k]);\n\
    \    }\n    void push(int k) {\n        all_apply(2 * k, lz[k]);\n        all_apply(2\
    \ * k + 1, lz[k]);\n        lz[k] = O::e();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_structure/LazySegtree.hpp
  requiredBy: []
  timestamp: '2023-07-23 08:43:35+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/aoj-DSL-2-I.test.cpp
  - Test/aoj-DSL-2-H.test.cpp
documentation_of: Data_structure/LazySegtree.hpp
layout: document
title: LazySegtree
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

