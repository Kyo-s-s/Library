---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_structure/DynamicSegtree.hpp
    title: DynamicSegtree
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
  bundledCode: "#line 1 \"Test/yosupo-Point-Add-Range-Sum(DynamicSegtree).test.cpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n\n#line 1 \"Data_structure/DynamicSegtree.hpp\"\ntemplate<class M> class DynamicSegtree\
    \ {\n  public:\n    using S = typename M::T;\n\n    DynamicSegtree() : DynamicSegtree(LONG_LONG_MAX\
    \ / 2) {}\n    DynamicSegtree(long long limit) : limit(limit), root(nullptr) {}\n\
    \n    void set(long long p, S x) {\n        set(root, 0, limit, p, x);\n    }\n\
    \n    S get(long long p) const {\n        return get(root, 0, limit, p);\n   \
    \ }\n\n    S prod(long long l, long long r) const {\n        assert(l <= r);\n\
    \        return prod(root, 0, limit, l, r);\n    }\n\n    S all_prod() const {\
    \ return root ? root->product : M::e(); }\n\n    void reset(long long l, long\
    \ long r) {\n        assert(l <= r);\n        return reset(root, 0, limit, l,\
    \ r);\n    }\n\n  private:\n    struct node;\n    using node_ptr = std::unique_ptr<node>;\n\
    \n    struct node {\n        long long index;\n        S value, product;\n   \
    \     node_ptr left, right;\n\n        node(long long index, S value)\n      \
    \      : index(index),\n              value(value),\n              product(value),\n\
    \              left(nullptr),\n              right(nullptr) {}\n\n        void\
    \ update() {\n            product = M::op(M::op(left ? left->product : M::e(),\
    \ value),\n                         right ? right->product : M::e());\n      \
    \  }\n    };\n\n    long long limit = LONG_LONG_MAX / 2;\n    node_ptr root;\n\
    \n    void set(node_ptr& t, long long a, long long b, long long p, S x) const\
    \ {\n        if (!t) {\n            t = std::make_unique<node>(p, x);\n      \
    \      return;\n        }\n        if (t->index == p) {\n            t->value\
    \ = x;\n            t->update();\n            return;\n        }\n        long\
    \ long c = (a + b) >> 1;\n        if (p < c) {\n            if (t->index < p)\
    \ std::swap(t->index, p), std::swap(t->value, x);\n            set(t->left, a,\
    \ c, p, x);\n        } else {\n            if (p < t->index) std::swap(p, t->index),\
    \ std::swap(x, t->value);\n            set(t->right, c, b, p, x);\n        }\n\
    \        t->update();\n    }\n\n    S get(const node_ptr& t, long long a, long\
    \ long b, long long p) const {\n        if (!t) return M::e();\n        if (t->index\
    \ == p) return t->value;\n        long long c = (a + b) >> 1;\n        if (p <\
    \ c) return get(t->left, a, c, p);\n        else return get(t->right, c, b, p);\n\
    \    }\n\n    S prod(const node_ptr& t, long long a, long long b, long long l,\
    \ long long r) const {\n        if (!t || b <= l || r <= a) return M::e();\n \
    \       if (l <= a && b <= r) return t->product;\n        long long c = (a + b)\
    \ >> 1;\n        S result = prod(t->left, a, c, l, r);\n        if (l <= t->index\
    \ && t->index < r) result = M::op(result, t->value);\n        return M::op(result,\
    \ prod(t->right, c, b, l, r));\n    }\n\n    void reset(node_ptr& t, long long\
    \ a, long long b, long long l, long long r) const {\n        if (!t || b <= l\
    \ || r <= a) return;\n        if (l <= a && b <= r) {\n            t.reset();\n\
    \            return;\n        }\n        long long c = (a + b) >> 1;\n       \
    \ reset(t->left, a, c, l, r);\n        reset(t->right, c, b, l, r);\n        t->update();\n\
    \    }\n};\n#line 7 \"Test/yosupo-Point-Add-Range-Sum(DynamicSegtree).test.cpp\"\
    \n\nstruct Monoid {\n    using T = long long;\n    static T op(T a, T b) {\n \
    \       return a + b;\n    }\n    static T e() {\n        return 0;\n    }\n};\n\
    \nint main() {\n    \n    DynamicSegtree<Monoid> seg;\n    int N, Q; cin >> N\
    \ >> Q;\n    for (int i = 0; i < N; i++) {\n        long long a; cin >> a;\n \
    \       seg.set(i, a);\n    }\n\n    while (Q--) {\n        int t; cin >> t;\n\
    \        if (t == 0) {\n            int p; cin >> p;\n            long long x;\
    \ cin >> x;\n            seg.set(p, seg.get(p) + x);\n        } else {\n     \
    \       int l, r; cin >> l >> r;\n            cout << seg.prod(l, r) << endl;\n\
    \        }\n    }\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n\n#include \"../Data_structure/DynamicSegtree.hpp\"\n\nstruct Monoid {\n   \
    \ using T = long long;\n    static T op(T a, T b) {\n        return a + b;\n \
    \   }\n    static T e() {\n        return 0;\n    }\n};\n\nint main() {\n    \n\
    \    DynamicSegtree<Monoid> seg;\n    int N, Q; cin >> N >> Q;\n    for (int i\
    \ = 0; i < N; i++) {\n        long long a; cin >> a;\n        seg.set(i, a);\n\
    \    }\n\n    while (Q--) {\n        int t; cin >> t;\n        if (t == 0) {\n\
    \            int p; cin >> p;\n            long long x; cin >> x;\n          \
    \  seg.set(p, seg.get(p) + x);\n        } else {\n            int l, r; cin >>\
    \ l >> r;\n            cout << seg.prod(l, r) << endl;\n        }\n    }\n}\n"
  dependsOn:
  - Data_structure/DynamicSegtree.hpp
  isVerificationFile: true
  path: Test/yosupo-Point-Add-Range-Sum(DynamicSegtree).test.cpp
  requiredBy: []
  timestamp: '2023-07-08 16:35:01+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-Point-Add-Range-Sum(DynamicSegtree).test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-Point-Add-Range-Sum(DynamicSegtree).test.cpp
- /verify/Test/yosupo-Point-Add-Range-Sum(DynamicSegtree).test.cpp.html
title: Test/yosupo-Point-Add-Range-Sum(DynamicSegtree).test.cpp
---
