---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-Suffix-Array.test.cpp
    title: Test/yosupo-Suffix-Array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/SuffixArray.hpp\"\nvector<int> SuffixArray(const\
    \ string& s) {\n    int n = s.size(), k;\n    vector<int> sa(n + 1);\n    vector<int>\
    \ rank(n + 1);\n    for (int i = 0; i <= n; i++) {\n        sa[i] = i;\n     \
    \   rank[i] = i < n ? (int)s[i] : -1;\n    }\n\n    auto compare = [&](int a,\
    \ int b) {\n        if (rank[a] != rank[b]) return rank[a] < rank[b];\n      \
    \  auto rank_ak = a + k <= n ? rank[a + k] : -1;\n        auto rank_bk = b + k\
    \ <= n ? rank[b + k] : -1;\n        return rank_ak < rank_bk;\n    };\n\n    for\
    \ (k = 1; k <= n; k *= 2) {\n        sort(sa.begin(), sa.end(), compare);\n  \
    \      vector<int> tmp(n + 1);\n        tmp[sa[0]] = 0;\n        for (int i =\
    \ 1; i <= n; i++) {\n            tmp[sa[i]] = tmp[sa[i - 1]] + (compare(sa[i -\
    \ 1], sa[i]) ? 1 : 0);\n        }\n        for (int i = 0; i <= n; i++) {\n  \
    \          rank[i] = tmp[i];\n        }\n    }\n    return sa;\n}\n"
  code: "vector<int> SuffixArray(const string& s) {\n    int n = s.size(), k;\n  \
    \  vector<int> sa(n + 1);\n    vector<int> rank(n + 1);\n    for (int i = 0; i\
    \ <= n; i++) {\n        sa[i] = i;\n        rank[i] = i < n ? (int)s[i] : -1;\n\
    \    }\n\n    auto compare = [&](int a, int b) {\n        if (rank[a] != rank[b])\
    \ return rank[a] < rank[b];\n        auto rank_ak = a + k <= n ? rank[a + k] :\
    \ -1;\n        auto rank_bk = b + k <= n ? rank[b + k] : -1;\n        return rank_ak\
    \ < rank_bk;\n    };\n\n    for (k = 1; k <= n; k *= 2) {\n        sort(sa.begin(),\
    \ sa.end(), compare);\n        vector<int> tmp(n + 1);\n        tmp[sa[0]] = 0;\n\
    \        for (int i = 1; i <= n; i++) {\n            tmp[sa[i]] = tmp[sa[i - 1]]\
    \ + (compare(sa[i - 1], sa[i]) ? 1 : 0);\n        }\n        for (int i = 0; i\
    \ <= n; i++) {\n            rank[i] = tmp[i];\n        }\n    }\n    return sa;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: String/SuffixArray.hpp
  requiredBy: []
  timestamp: '2023-07-19 13:59:31+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-Suffix-Array.test.cpp
documentation_of: String/SuffixArray.hpp
layout: document
title: SuffixArray
---

## SuffixArray
```C++
vector<int> SuffixArray(string S)
```

$S$ について(空文字を含む)SuffixArrayを返す. 
$S$ の長さを $N$ として、長さ $ N+1 $ の配列を返す. 

###### 計算量

- $ O( N \log N ) $


### SuffixArray とは？

接尾辞(先頭から $ n \in \{0, \ldots, N \} $ 文字を取り除いた文字列)を，辞書順に並べたもの．

たとえば`suffixarray`について，

| $n$ | 接尾辞 |
|:---:|---|
| 0 | `suffixarray` |
| 1 | `uffixarray` |
| 2 | `ffixarray` |
| 3 | `fixarray` |
| 4 | `ixarray` |
| 5 | `xarray` |
| 6 | `array` |
| 7 | `rray` |
| 8 | `ray` |
| 9 | `ay` |
| 10 | `y` |
| 11 | ` ` |

である．これを接尾辞について辞書順に並び変えると，

| $n$ | 接尾辞 |
|:---:|---|
| 11 | ` ` |
| 6 | `array` |
| 9 | `ay` |
| 2 | `ffixarray` |
| 3 | `fixarray` |
| 4 | `ixarray` |
| 8 | `ray` |
| 7 | `rray` |
| 0 | `suffixarray` |
| 1 | `uffixarray` |
| 5 | `xarray` |
| 10 | `y` |

となるので，`suffixarray`のSuffixArrayは`{11, 6, 9, 2, 3, 4, 8, 7, 0, 1, 5, 10}`である．よってこれが返る．
