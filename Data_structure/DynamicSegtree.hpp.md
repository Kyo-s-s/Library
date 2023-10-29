---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-Point-Add-Range-Sum(DynamicSegtree).test.cpp
    title: Test/yosupo-Point-Add-Range-Sum(DynamicSegtree).test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Data_structure/DynamicSegtree.hpp\"\ntemplate<class M> class\
    \ DynamicSegtree {\n  public:\n    using S = typename M::T;\n\n    DynamicSegtree()\
    \ : DynamicSegtree(LONG_LONG_MAX / 2) {}\n    DynamicSegtree(long long limit)\
    \ : limit(limit), root(nullptr) {}\n\n    void set(long long p, S x) {\n     \
    \   set(root, 0, limit, p, x);\n    }\n\n    S get(long long p) const {\n    \
    \    return get(root, 0, limit, p);\n    }\n\n    S prod(long long l, long long\
    \ r) const {\n        assert(l <= r);\n        return prod(root, 0, limit, l,\
    \ r);\n    }\n\n    S all_prod() const { return root ? root->product : M::e();\
    \ }\n\n    void reset(long long l, long long r) {\n        assert(l <= r);\n \
    \       return reset(root, 0, limit, l, r);\n    }\n\n  private:\n    struct node;\n\
    \    using node_ptr = std::unique_ptr<node>;\n\n    struct node {\n        long\
    \ long index;\n        S value, product;\n        node_ptr left, right;\n\n  \
    \      node(long long index, S value)\n            : index(index),\n         \
    \     value(value),\n              product(value),\n              left(nullptr),\n\
    \              right(nullptr) {}\n\n        void update() {\n            product\
    \ = M::op(M::op(left ? left->product : M::e(), value),\n                     \
    \    right ? right->product : M::e());\n        }\n    };\n\n    long long limit\
    \ = LONG_LONG_MAX / 2;\n    node_ptr root;\n\n    void set(node_ptr& t, long long\
    \ a, long long b, long long p, S x) const {\n        if (!t) {\n            t\
    \ = std::make_unique<node>(p, x);\n            return;\n        }\n        if\
    \ (t->index == p) {\n            t->value = x;\n            t->update();\n   \
    \         return;\n        }\n        long long c = (a + b) >> 1;\n        if\
    \ (p < c) {\n            if (t->index < p) std::swap(t->index, p), std::swap(t->value,\
    \ x);\n            set(t->left, a, c, p, x);\n        } else {\n            if\
    \ (p < t->index) std::swap(p, t->index), std::swap(x, t->value);\n           \
    \ set(t->right, c, b, p, x);\n        }\n        t->update();\n    }\n\n    S\
    \ get(const node_ptr& t, long long a, long long b, long long p) const {\n    \
    \    if (!t) return M::e();\n        if (t->index == p) return t->value;\n   \
    \     long long c = (a + b) >> 1;\n        if (p < c) return get(t->left, a, c,\
    \ p);\n        else return get(t->right, c, b, p);\n    }\n\n    S prod(const\
    \ node_ptr& t, long long a, long long b, long long l, long long r) const {\n \
    \       if (!t || b <= l || r <= a) return M::e();\n        if (l <= a && b <=\
    \ r) return t->product;\n        long long c = (a + b) >> 1;\n        S result\
    \ = prod(t->left, a, c, l, r);\n        if (l <= t->index && t->index < r) result\
    \ = M::op(result, t->value);\n        return M::op(result, prod(t->right, c, b,\
    \ l, r));\n    }\n\n    void reset(node_ptr& t, long long a, long long b, long\
    \ long l, long long r) const {\n        if (!t || b <= l || r <= a) return;\n\
    \        if (l <= a && b <= r) {\n            t.reset();\n            return;\n\
    \        }\n        long long c = (a + b) >> 1;\n        reset(t->left, a, c,\
    \ l, r);\n        reset(t->right, c, b, l, r);\n        t->update();\n    }\n\
    };\n"
  code: "template<class M> class DynamicSegtree {\n  public:\n    using S = typename\
    \ M::T;\n\n    DynamicSegtree() : DynamicSegtree(LONG_LONG_MAX / 2) {}\n    DynamicSegtree(long\
    \ long limit) : limit(limit), root(nullptr) {}\n\n    void set(long long p, S\
    \ x) {\n        set(root, 0, limit, p, x);\n    }\n\n    S get(long long p) const\
    \ {\n        return get(root, 0, limit, p);\n    }\n\n    S prod(long long l,\
    \ long long r) const {\n        assert(l <= r);\n        return prod(root, 0,\
    \ limit, l, r);\n    }\n\n    S all_prod() const { return root ? root->product\
    \ : M::e(); }\n\n    void reset(long long l, long long r) {\n        assert(l\
    \ <= r);\n        return reset(root, 0, limit, l, r);\n    }\n\n  private:\n \
    \   struct node;\n    using node_ptr = std::unique_ptr<node>;\n\n    struct node\
    \ {\n        long long index;\n        S value, product;\n        node_ptr left,\
    \ right;\n\n        node(long long index, S value)\n            : index(index),\n\
    \              value(value),\n              product(value),\n              left(nullptr),\n\
    \              right(nullptr) {}\n\n        void update() {\n            product\
    \ = M::op(M::op(left ? left->product : M::e(), value),\n                     \
    \    right ? right->product : M::e());\n        }\n    };\n\n    long long limit\
    \ = LONG_LONG_MAX / 2;\n    node_ptr root;\n\n    void set(node_ptr& t, long long\
    \ a, long long b, long long p, S x) const {\n        if (!t) {\n            t\
    \ = std::make_unique<node>(p, x);\n            return;\n        }\n        if\
    \ (t->index == p) {\n            t->value = x;\n            t->update();\n   \
    \         return;\n        }\n        long long c = (a + b) >> 1;\n        if\
    \ (p < c) {\n            if (t->index < p) std::swap(t->index, p), std::swap(t->value,\
    \ x);\n            set(t->left, a, c, p, x);\n        } else {\n            if\
    \ (p < t->index) std::swap(p, t->index), std::swap(x, t->value);\n           \
    \ set(t->right, c, b, p, x);\n        }\n        t->update();\n    }\n\n    S\
    \ get(const node_ptr& t, long long a, long long b, long long p) const {\n    \
    \    if (!t) return M::e();\n        if (t->index == p) return t->value;\n   \
    \     long long c = (a + b) >> 1;\n        if (p < c) return get(t->left, a, c,\
    \ p);\n        else return get(t->right, c, b, p);\n    }\n\n    S prod(const\
    \ node_ptr& t, long long a, long long b, long long l, long long r) const {\n \
    \       if (!t || b <= l || r <= a) return M::e();\n        if (l <= a && b <=\
    \ r) return t->product;\n        long long c = (a + b) >> 1;\n        S result\
    \ = prod(t->left, a, c, l, r);\n        if (l <= t->index && t->index < r) result\
    \ = M::op(result, t->value);\n        return M::op(result, prod(t->right, c, b,\
    \ l, r));\n    }\n\n    void reset(node_ptr& t, long long a, long long b, long\
    \ long l, long long r) const {\n        if (!t || b <= l || r <= a) return;\n\
    \        if (l <= a && b <= r) {\n            t.reset();\n            return;\n\
    \        }\n        long long c = (a + b) >> 1;\n        reset(t->left, a, c,\
    \ l, r);\n        reset(t->right, c, b, l, r);\n        t->update();\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_structure/DynamicSegtree.hpp
  requiredBy: []
  timestamp: '2023-07-08 16:35:01+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-Point-Add-Range-Sum(DynamicSegtree).test.cpp
documentation_of: Data_structure/DynamicSegtree.hpp
layout: document
title: DynamicSegtree
---

動的セグメント木 モノイドを渡す

## コンストラクタ
```cpp
(1) DynamicSegtree<Monoid> seg
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