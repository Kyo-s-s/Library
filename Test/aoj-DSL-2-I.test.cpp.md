---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_structure/LazySegtree.hpp
    title: Data_structure/LazySegtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_I
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_I
  bundledCode: "#line 1 \"Test/aoj-DSL-2-I.test.cpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_I\"\
    \n\n#line 1 \"Data_structure/LazySegtree.hpp\"\ntemplate <class M, class O, auto\
    \ fn> struct LazySegtree {\n    using S = typename M::T;\n    using F = typename\
    \ O::T;\n    static_assert(is_convertible_v<decltype(fn), std::function<S(F, S)>>);\n\
    \n  public:\n    LazySegtree() : LazySegtree(0) {}\n    LazySegtree(int n) : LazySegtree(std::vector<S>(n,\
    \ M::e())) {}\n    LazySegtree(const std::vector<S>& v) : n(int(v.size())) {\n\
    \        while ((1 << log) < n) log++;\n        size = 1 << log;\n        d =\
    \ vector<S>(2 * size, M::e());\n        lz = vector<F>(size, O::e());\n      \
    \  for (int i = 0; i < n; i++) d[size + i] = v[i];\n        for (int i = size\
    \ - 1; i >= 1; i--) update(i);\n    }\n\n    void set(int p, S x) {\n        assert(0\
    \ <= p && p < n);\n        p += size;\n        for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n\n    S get(int p) {\n        assert(0 <= p && p < n);\n    \
    \    p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n      \
    \  return d[p];\n    }\n\n    S prod(int l, int r) {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        if (l == r) return M::e();\n        l += size; r\
    \ += size;\n        for (int i = log; i >= 1; i--) {\n            if (((l >> i)\
    \ << i) != l) push(l >> i);\n            if (((r >> i) << i) != r) push(r >> i);\n\
    \        }\n        S sml = M::e(), smr = M::e();\n        while (l < r) {\n \
    \           if (l & 1) sml = M::op(sml, d[l++]);\n            if (r & 1) smr =\
    \ M::op(d[--r], smr);\n            l >>= 1; r >>= 1;\n        }\n        return\
    \ M::op(sml, smr);\n    }\n\n    S all_prod() { return d[1]; }\n\n    void apply(int\
    \ p, F f) {\n        assert(0 <= p && p < n);\n        p += size;\n        for\
    \ (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = fn(f, d[p]);\n    \
    \    for (int i = 1; i <= log; i++) update(p >> i);\n    }\n    void apply(int\
    \ l, int r, F f) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l\
    \ == r) return;\n        l += size; r += size;\n        for (int i = log; i >=\
    \ 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n           \
    \ if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n        {\n      \
    \      int l2 = l, r2 = r;\n            while (l < r) {\n                if (l\
    \ & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r, f);\n   \
    \             l >>= 1; r >>= 1;\n            }\n            l = l2; r = r2;\n\
    \        }\n        for (int i = 1; i <= log; i++) {\n            if (((l >> i)\
    \ << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n\n  private:\n    int n, size, log = 0;\n   \
    \ vector<S> d;\n    vector<F> lz;\n\n    void update(int k) { d[k] = M::op(d[2\
    \ * k], d[2 * k + 1]); }\n    void all_apply(int k, F f) {\n        d[k] = fn(f,\
    \ d[k]);\n        if (k < size) lz[k] = O::op(f, lz[k]);\n    }\n    void push(int\
    \ k) {\n        all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n\
    \        lz[k] = O::e();\n    }\n};\n#line 7 \"Test/aoj-DSL-2-I.test.cpp\"\n\n\
    struct M {\n    struct T {\n        long long value, width;\n        T(long long\
    \ v) : T(v, 1) {}\n        T(long long v, long long w) : value(v), width(w) {}\n\
    \    };\n    static T op(T a, T b) { return T(a.value + b.value, a.width + b.width);\
    \ }\n    static T e() { return T(0, 0); }\n};\n\nstruct O {\n    using T = long\
    \ long;\n    static T op(T f, T g) {\n        return (f == e() ? g : f);\n   \
    \ }\n    static T e() { return 1LL << 58; }\n};\n\nM::T fn(O::T f, M::T x) {\n\
    \    if (f == O::e()) return x;\n    return M::T(f * x.width, x.width);\n}\n\n\
    \nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<M::T> v(N, M::T(0,\
    \ 1));\n    LazySegtree<M, O, fn> seg(v);\n\n    while(Q--){\n        int u;\n\
    \        cin >> u;\n        if(u == 0){\n            int s, t, x;\n          \
    \  cin >> s >> t >> x;\n            seg.apply(s, t + 1, x);\n        }else{\n\
    \            int s, t;\n            cin >> s >> t;\n            cout << seg.prod(s,\
    \ t + 1).value << endl;\n        }\n    }\n}\n\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_I\"\
    \n\n#include \"../Data_structure/LazySegtree.hpp\"\n\nstruct M {\n    struct T\
    \ {\n        long long value, width;\n        T(long long v) : T(v, 1) {}\n  \
    \      T(long long v, long long w) : value(v), width(w) {}\n    };\n    static\
    \ T op(T a, T b) { return T(a.value + b.value, a.width + b.width); }\n    static\
    \ T e() { return T(0, 0); }\n};\n\nstruct O {\n    using T = long long;\n    static\
    \ T op(T f, T g) {\n        return (f == e() ? g : f);\n    }\n    static T e()\
    \ { return 1LL << 58; }\n};\n\nM::T fn(O::T f, M::T x) {\n    if (f == O::e())\
    \ return x;\n    return M::T(f * x.width, x.width);\n}\n\n\nint main() {\n   \
    \ int N, Q;\n    cin >> N >> Q;\n    vector<M::T> v(N, M::T(0, 1));\n    LazySegtree<M,\
    \ O, fn> seg(v);\n\n    while(Q--){\n        int u;\n        cin >> u;\n     \
    \   if(u == 0){\n            int s, t, x;\n            cin >> s >> t >> x;\n \
    \           seg.apply(s, t + 1, x);\n        }else{\n            int s, t;\n \
    \           cin >> s >> t;\n            cout << seg.prod(s, t + 1).value << endl;\n\
    \        }\n    }\n}\n\n"
  dependsOn:
  - Data_structure/LazySegtree.hpp
  isVerificationFile: true
  path: Test/aoj-DSL-2-I.test.cpp
  requiredBy: []
  timestamp: '2023-07-23 08:43:35+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/aoj-DSL-2-I.test.cpp
layout: document
redirect_from:
- /verify/Test/aoj-DSL-2-I.test.cpp
- /verify/Test/aoj-DSL-2-I.test.cpp.html
title: Test/aoj-DSL-2-I.test.cpp
---
