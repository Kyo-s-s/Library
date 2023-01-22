---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_structure/Segtree.hpp
    title: Segtree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"Test/yosupo-Point-Add-Range-Sum.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n\n#line 1 \"Data_structure/Segtree.hpp\"\ntemplate<class M> struct Segtree {\n\
    \  public:\n    using S = typename M::T;\n\n    Segtree() : Segtree(0) {}\n  \
    \  Segtree(int n) : Segtree(vector<S> (n, M::e())) {}\n    Segtree(const vector<S>\
    \ &v) : n(int(v.size())) { \n        while((1 << log) < n) log++;\n        size\
    \ = 1 << log;\n        d = vector<S> (2 * size, M::e());\n        for(int i =\
    \ 0; i < n; i++) d[size + i] = v[i];\n        for(int i = size- 1; i >= 1; i--)\
    \ update(i);\n    }\n\n    void set(int p, S x){\n        assert(0 <= p && p <\
    \ n);\n        p += size;\n        d[p] = x;\n        for(int i = 1; i <= log;\
    \ i++) update(p >> i);\n    }\n\n    S get(int p){\n        assert(0 <= p && p\
    \ < n);\n        return d[p + size];\n    }\n\n    S prod(int l, int r){\n   \
    \     assert(0 <= l && l <= r && r <= n);\n        S sml = M::e(), smr = M::e();\n\
    \        l += size; r += size;\n        while(l < r){\n            if(l & 1) sml\
    \ = M::op(sml, d[l++]);\n            if(r & 1) smr = M::op(d[--r], smr);\n   \
    \         l >>= 1; r >>= 1;\n        }\n        return M::op(sml, smr);\n    }\n\
    \n    S all_prod(){ return d[1]; }\n\n\n  private:\n    int n, size, log = 0;\n\
    \    vector<S> d;\n    void update(int k){ d[k] = M::op(d[k * 2], d[k * 2 + 1]);\
    \ }\n\n};\n#line 7 \"Test/yosupo-Point-Add-Range-Sum.test.cpp\"\n\nstruct Monoid\
    \ {\n    using T = long long;\n    static T op(T a, T b) {\n        return a +\
    \ b;\n    }\n    static T e() {\n        return 0;\n    }\n};\n\nint main() {\n\
    \    \n    int N, Q; cin >> N >> Q;\n    vector<long long> A(N);\n    for (auto\
    \ &a : A) cin >> a;\n    Segtree<Monoid> seg(A);\n\n\n    while (Q--) {\n    \
    \    int t; cin >> t;\n        if (t == 0) {\n            int p; cin >> p;\n \
    \           long long x; cin >> x;\n            seg.set(p, seg.get(p) + x);\n\
    \        } else {\n            int l, r; cin >> l >> r;\n            cout << seg.prod(l,\
    \ r) << endl;\n        }\n    }\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n\n#include \"../Data_structure/Segtree.hpp\"\n\nstruct Monoid {\n    using T\
    \ = long long;\n    static T op(T a, T b) {\n        return a + b;\n    }\n  \
    \  static T e() {\n        return 0;\n    }\n};\n\nint main() {\n    \n    int\
    \ N, Q; cin >> N >> Q;\n    vector<long long> A(N);\n    for (auto &a : A) cin\
    \ >> a;\n    Segtree<Monoid> seg(A);\n\n\n    while (Q--) {\n        int t; cin\
    \ >> t;\n        if (t == 0) {\n            int p; cin >> p;\n            long\
    \ long x; cin >> x;\n            seg.set(p, seg.get(p) + x);\n        } else {\n\
    \            int l, r; cin >> l >> r;\n            cout << seg.prod(l, r) << endl;\n\
    \        }\n    }\n}\n"
  dependsOn:
  - Data_structure/Segtree.hpp
  isVerificationFile: true
  path: Test/yosupo-Point-Add-Range-Sum.test.cpp
  requiredBy: []
  timestamp: '2023-01-22 14:41:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-Point-Add-Range-Sum.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-Point-Add-Range-Sum.test.cpp
- /verify/Test/yosupo-Point-Add-Range-Sum.test.cpp.html
title: Test/yosupo-Point-Add-Range-Sum.test.cpp
---
