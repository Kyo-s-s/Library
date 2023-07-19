---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/SuffixArray.hpp
    title: SuffixArray
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"Test/yosupo-Suffix-Array.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\
    \n\n#line 1 \"String/SuffixArray.hpp\"\nvector<int> SuffixArray(const string&\
    \ s) {\n    int n = s.size(), k;\n    vector<int> sa(n + 1);\n    vector<int>\
    \ rank(n + 1);\n    for (int i = 0; i <= n; i++) {\n        sa[i] = i;\n     \
    \   rank[i] = i < n ? (int)s[i] : -1;\n    }\n\n    auto compare = [&](int a,\
    \ int b) {\n        if (rank[a] != rank[b]) return rank[a] < rank[b];\n      \
    \  auto rank_ak = a + k <= n ? rank[a + k] : -1;\n        auto rank_bk = b + k\
    \ <= n ? rank[b + k] : -1;\n        return rank_ak < rank_bk;\n    };\n\n    for\
    \ (k = 1; k <= n; k *= 2) {\n        sort(sa.begin(), sa.end(), compare);\n  \
    \      vector<int> tmp(n + 1);\n        tmp[sa[0]] = 0;\n        for (int i =\
    \ 1; i <= n; i++) {\n            tmp[sa[i]] = tmp[sa[i - 1]] + (compare(sa[i -\
    \ 1], sa[i]) ? 1 : 0);\n        }\n        for (int i = 0; i <= n; i++) {\n  \
    \          rank[i] = tmp[i];\n        }\n    }\n    return sa;\n}\n#line 7 \"\
    Test/yosupo-Suffix-Array.test.cpp\"\n\nint main() {\n\n    string S; cin >> S;\n\
    \    vector<int> sa = SuffixArray(S);\n    for (int i = 1; i < sa.size(); i++)\
    \ {\n        cout << sa[i] << \" \\n\"[i == sa.size() - 1];\n    }\n\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\
    \n\n#include \"../String/SuffixArray.hpp\"\n\nint main() {\n\n    string S; cin\
    \ >> S;\n    vector<int> sa = SuffixArray(S);\n    for (int i = 1; i < sa.size();\
    \ i++) {\n        cout << sa[i] << \" \\n\"[i == sa.size() - 1];\n    }\n\n}\n"
  dependsOn:
  - String/SuffixArray.hpp
  isVerificationFile: true
  path: Test/yosupo-Suffix-Array.test.cpp
  requiredBy: []
  timestamp: '2023-07-19 13:59:31+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-Suffix-Array.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-Suffix-Array.test.cpp
- /verify/Test/yosupo-Suffix-Array.test.cpp.html
title: Test/yosupo-Suffix-Array.test.cpp
---
