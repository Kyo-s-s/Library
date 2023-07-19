---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-Z-Algorithm.test.cpp
    title: Test/yosupo-Z-Algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/Zalgorithm.hpp\"\nvector<int> Zalgorithm(const string\
    \ &S) {\n    vector<int> Z(S.size());\n    Z[0] = (int)S.size();\n    int i =\
    \ 1, j = 0;\n    while(i < S.size()) {\n        while(i + j < (int)(S.size())\
    \ && S[j] == S[i + j]) j++;\n        Z[i] = j;\n\n        if(j == 0) {\n     \
    \       i++;\n            continue;\n        }\n\n        int k = 1;\n       \
    \ while(k < j && k + Z[k] < j) {\n            Z[i + k] = Z[k];\n            k++;\n\
    \        }\n        i += k;\n        j -= k;\n    }\n    return Z;\n}\n\ntemplate<class\
    \ T>\nvector<int> Zalgorithm(const vector<T> &S) {\n    vector<int> Z(S.size());\n\
    \    Z[0] = (int)S.size();\n    int i = 1, j = 0;\n    while(i < S.size()) {\n\
    \        while(i + j < (int)(S.size()) && S[j] == S[i + j]) j++;\n        Z[i]\
    \ = j;\n\n        if(j == 0) {\n            i++;\n            continue;\n    \
    \    }\n\n        int k = 1;\n        while(k < j && k + Z[k] < j) {\n       \
    \     Z[i + k] = Z[k];\n            k++;\n        }\n        i += k;\n       \
    \ j -= k;\n    }\n    return Z;\n}\n"
  code: "vector<int> Zalgorithm(const string &S) {\n    vector<int> Z(S.size());\n\
    \    Z[0] = (int)S.size();\n    int i = 1, j = 0;\n    while(i < S.size()) {\n\
    \        while(i + j < (int)(S.size()) && S[j] == S[i + j]) j++;\n        Z[i]\
    \ = j;\n\n        if(j == 0) {\n            i++;\n            continue;\n    \
    \    }\n\n        int k = 1;\n        while(k < j && k + Z[k] < j) {\n       \
    \     Z[i + k] = Z[k];\n            k++;\n        }\n        i += k;\n       \
    \ j -= k;\n    }\n    return Z;\n}\n\ntemplate<class T>\nvector<int> Zalgorithm(const\
    \ vector<T> &S) {\n    vector<int> Z(S.size());\n    Z[0] = (int)S.size();\n \
    \   int i = 1, j = 0;\n    while(i < S.size()) {\n        while(i + j < (int)(S.size())\
    \ && S[j] == S[i + j]) j++;\n        Z[i] = j;\n\n        if(j == 0) {\n     \
    \       i++;\n            continue;\n        }\n\n        int k = 1;\n       \
    \ while(k < j && k + Z[k] < j) {\n            Z[i + k] = Z[k];\n            k++;\n\
    \        }\n        i += k;\n        j -= k;\n    }\n    return Z;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: String/Zalgorithm.hpp
  requiredBy: []
  timestamp: '2023-07-12 13:20:16+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-Z-Algorithm.test.cpp
documentation_of: String/Zalgorithm.hpp
layout: document
title: Zalgorithm
---

## Zalgorithm
```C++
(1) vector<int> Zalgorithm(string S)
(2) vector<int> Zalgorithm(vector<T> S)
```

$S$ の長さを $N$ として, 長さ $N$ の配列を返す. $i$番目の要素は`s[0..N)`と`s[i..N)`の最長共通接頭辞.

###### 計算量

- $O(N)$

