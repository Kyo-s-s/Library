---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-Number-of-Substrings.test.cpp
    title: Test/yosupo-Number-of-Substrings.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/LCPArray.hpp\"\nvector<int> LCPArray(const string&\
    \ s, const vector<int>& sa) {\n    int n = s.size();\n    vector<int> rank(n +\
    \ 1);\n    for (int i = 0; i <= n; i++) {\n        rank[sa[i]] = i;\n    }\n \
    \   vector<int> lcp(n, 0);\n    int h = 0;\n    for (int i = 0; i < n; i++) {\n\
    \        int j = sa[rank[i] - 1];\n        if (h > 0) h--;\n        for (; j +\
    \ h < n && i + h < n; h++) {\n            if (s[j + h] != s[i + h]) break;\n \
    \       }\n        lcp[rank[i] - 1] = h;\n    }\n    return lcp;\n}\n"
  code: "vector<int> LCPArray(const string& s, const vector<int>& sa) {\n    int n\
    \ = s.size();\n    vector<int> rank(n + 1);\n    for (int i = 0; i <= n; i++)\
    \ {\n        rank[sa[i]] = i;\n    }\n    vector<int> lcp(n, 0);\n    int h =\
    \ 0;\n    for (int i = 0; i < n; i++) {\n        int j = sa[rank[i] - 1];\n  \
    \      if (h > 0) h--;\n        for (; j + h < n && i + h < n; h++) {\n      \
    \      if (s[j + h] != s[i + h]) break;\n        }\n        lcp[rank[i] - 1] =\
    \ h;\n    }\n    return lcp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: String/LCPArray.hpp
  requiredBy: []
  timestamp: '2023-07-19 16:58:05+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-Number-of-Substrings.test.cpp
documentation_of: String/LCPArray.hpp
layout: document
title: LCPArray
---

## LCPArray
```C++
vector<int> LCPArray(string S, vector<int> sa)
```

$S$ の長さを $N$ として, 長さ $N$ の配列を返す. $i$番目の要素は`sa[i]`と`sa[i+1]`の最長共通接頭辞．

###### 制約

- `sa` は $S$ のSuffixArray(空文字を含む)．

###### 計算量

- $O(N)$