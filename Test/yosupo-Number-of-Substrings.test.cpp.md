---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/LCPArray.hpp
    title: LCPArray
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
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"Test/yosupo-Number-of-Substrings.test.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\
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
    Test/yosupo-Number-of-Substrings.test.cpp\"\n\n#line 1 \"String/LCPArray.hpp\"\
    \nvector<int> LCPArray(const string& s, const vector<int>& sa) {\n    int n =\
    \ s.size();\n    vector<int> rank(n + 1);\n    for (int i = 0; i <= n; i++) {\n\
    \        rank[sa[i]] = i;\n    }\n    vector<int> lcp(n, 0);\n    int h = 0;\n\
    \    for (int i = 0; i < n; i++) {\n        int j = sa[rank[i] - 1];\n       \
    \ if (h > 0) h--;\n        for (; j + h < n && i + h < n; h++) {\n           \
    \ if (s[j + h] != s[i + h]) break;\n        }\n        lcp[rank[i] - 1] = h;\n\
    \    }\n    return lcp;\n}\n#line 9 \"Test/yosupo-Number-of-Substrings.test.cpp\"\
    \n\nint main() {\n\n    string S;\n    cin >> S;\n\n    vector<int> lcp = LCPArray(S,\
    \ SuffixArray(S));\n\n    long long ans = (long long)S.size() * (long long)(S.size()\
    \ + 1) / 2;\n    for (int v : lcp) {\n        ans -= v;\n    }\n\n    cout <<\
    \ ans << endl;\n\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\
    \n\n#include \"../String/SuffixArray.hpp\"\n\n#include \"../String/LCPArray.hpp\"\
    \n\nint main() {\n\n    string S;\n    cin >> S;\n\n    vector<int> lcp = LCPArray(S,\
    \ SuffixArray(S));\n\n    long long ans = (long long)S.size() * (long long)(S.size()\
    \ + 1) / 2;\n    for (int v : lcp) {\n        ans -= v;\n    }\n\n    cout <<\
    \ ans << endl;\n\n}\n"
  dependsOn:
  - String/SuffixArray.hpp
  - String/LCPArray.hpp
  isVerificationFile: true
  path: Test/yosupo-Number-of-Substrings.test.cpp
  requiredBy: []
  timestamp: '2023-07-19 16:58:05+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-Number-of-Substrings.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-Number-of-Substrings.test.cpp
- /verify/Test/yosupo-Number-of-Substrings.test.cpp.html
title: Test/yosupo-Number-of-Substrings.test.cpp
---
