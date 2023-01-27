---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Data_structure/CumulativeSum.hpp
    title: CumulativeSum
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"Test/yosupo-Static-Range-Sum.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
    \n\n#line 1 \"Data_structure/CumulativeSum.hpp\"\ntemplate<class T> struct CumlativeSum\
    \ {\n    int n;\n    vector<T> data; \n    bool builded = false;\n    CumlativeSum(int\
    \ n) : n(n), data(n + 1) {}\n    CumlativeSum(const vector<T> &v) : n(v.size()),\
    \ data(n + 1) {\n        for (int i = 0; i < n; i++) {\n            data[i + 1]\
    \ = v[i];\n        }\n    }\n\n    void build() {\n        for (int i = 0; i <\
    \ n; i++) {\n            data[i + 1] += data[i];\n        }\n        builded =\
    \ true;\n    }\n\n    T sum(int r) {\n        if (!builded) build();\n       \
    \ assert(0 <= r && r <= n);\n        return data[r];\n    }\n\n    T sum(int l,\
    \ int r) {\n        assert(0 <= l && l <= r && r <= n);\n        return sum(r)\
    \ - sum(l);\n    }\n\n};\n#line 7 \"Test/yosupo-Static-Range-Sum.test.cpp\"\n\n\
    int main() {\n\n    int N, Q; cin >> N >> Q;\n    vector<long long> A(N);\n  \
    \  for (auto &a : A) cin >> a;\n\n    CumulativeSum<long long> cum(A);\n\n   \
    \ while (Q--) {\n        int l, r; cin >> l >> r;\n        cout << cum.sum(l,\
    \ r) << endl;\n    }\n\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
    \n\n#include \"../Data_structure/CumulativeSum.hpp\"\n\nint main() {\n\n    int\
    \ N, Q; cin >> N >> Q;\n    vector<long long> A(N);\n    for (auto &a : A) cin\
    \ >> a;\n\n    CumulativeSum<long long> cum(A);\n\n    while (Q--) {\n       \
    \ int l, r; cin >> l >> r;\n        cout << cum.sum(l, r) << endl;\n    }\n\n}"
  dependsOn:
  - Data_structure/CumulativeSum.hpp
  isVerificationFile: true
  path: Test/yosupo-Static-Range-Sum.test.cpp
  requiredBy: []
  timestamp: '2023-01-27 17:34:49+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/yosupo-Static-Range-Sum.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-Static-Range-Sum.test.cpp
- /verify/Test/yosupo-Static-Range-Sum.test.cpp.html
title: Test/yosupo-Static-Range-Sum.test.cpp
---
