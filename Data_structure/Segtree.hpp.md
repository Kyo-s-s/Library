---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Data_structure/Segtree.hpp\"\ntemplate<class M> struct Segtree\
    \ {\n  public:\n    using S = typename M::T;\n\n    Segtree() : Segtree(0) {}\n\
    \    Segtree(int n) : Segtree(n, vector<S> (n, M::e())) {}\n    Segtree(vector<S>\
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
    \ }\n\n};\n"
  code: "template<class M> struct Segtree {\n  public:\n    using S = typename M::T;\n\
    \n    Segtree() : Segtree(0) {}\n    Segtree(int n) : Segtree(n, vector<S> (n,\
    \ M::e())) {}\n    Segtree(vector<S> &v) : n(int(v.size())) { \n        while((1\
    \ << log) < n) log++;\n        size = 1 << log;\n        d = vector<S> (2 * size,\
    \ M::e());\n        for(int i = 0; i < n; i++) d[size + i] = v[i];\n        for(int\
    \ i = size- 1; i >= 1; i--) update(i);\n    }\n\n    void set(int p, S x){\n \
    \       assert(0 <= p && p < n);\n        p += size;\n        d[p] = x;\n    \
    \    for(int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S get(int p){\n\
    \        assert(0 <= p && p < n);\n        return d[p + size];\n    }\n\n    S\
    \ prod(int l, int r){\n        assert(0 <= l && l <= r && r <= n);\n        S\
    \ sml = M::e(), smr = M::e();\n        l += size; r += size;\n        while(l\
    \ < r){\n            if(l & 1) sml = M::op(sml, d[l++]);\n            if(r & 1)\
    \ smr = M::op(d[--r], smr);\n            l >>= 1; r >>= 1;\n        }\n      \
    \  return M::op(sml, smr);\n    }\n\n    S all_prod(){ return d[1]; }\n\n\n  private:\n\
    \    int n, size, log = 0;\n    vector<S> d;\n    void update(int k){ d[k] = M::op(d[k\
    \ * 2], d[k * 2 + 1]); }\n\n};"
  dependsOn: []
  isVerificationFile: false
  path: Data_structure/Segtree.hpp
  requiredBy: []
  timestamp: '2022-08-06 23:50:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_structure/Segtree.hpp
layout: document
redirect_from:
- /library/Data_structure/Segtree.hpp
- /library/Data_structure/Segtree.hpp.html
title: Data_structure/Segtree.hpp
---
