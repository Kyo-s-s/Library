---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/aoj-DPL-5-B.test.cpp
    title: Test/aoj-DPL-5-B.test.cpp
  - icon: ':x:'
    path: Test/aoj-DPL-5-G.test.cpp
    title: Test/aoj-DPL-5-G.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Enumeration.hpp\"\ntemplate<class T> struct Enumeration{\n\
    \  public:\n    Enumeration(int sz = 0) { update(sz); }\n\n    T fact(int k) {\n\
    \        update(k);\n        return _fact[k];\n    }\n\n    T finv(int k) {\n\
    \        update(k);\n        return _finv[k];\n    }\n\n    T inv(int k) {\n \
    \       update(k);\n        return _inv[k];\n    }\n\n    T nPk(int n, int k)\
    \ {\n        if(k < 0 || n < k) return 0;\n        return fact(n) * finv(n - k);\n\
    \    }\n\n    T nCk(int n, int k) {\n        if(k < 0 || n < k) return 0;\n  \
    \      return fact(n) * finv(k) * finv(n - k);\n    }\n\n    T nHk(int n, int\
    \ k) {\n        if(n < 0 || k < 0) return 0;\n        if(n == 0) return 1;\n \
    \       else return nCk(n + k - 1, k);\n    }\n\n    T Catalan(int n){\n     \
    \   return nCk(2*n, n) - nCk(2*n, n-1);\n    }\n\n  private:\n    vector<T> _fact,\
    \ _finv, _inv;\n\n    void update(int sz) {\n        if(_fact.size() < sz + 1){\n\
    \            int pre_sz = max(1, (int)_fact.size());\n            _fact.resize(sz\
    \ + 1, T(1));\n            _finv.resize(sz + 1, T(1));\n            _inv.resize(sz\
    \ + 1, T(1));\n            for(int i = pre_sz; i <= (int)sz; i++) {\n        \
    \        _fact[i] = _fact[i - 1] * T(i);\n            }\n            _finv[sz]\
    \ = T(1) / _fact[sz];\n            for(int i = (int)sz - 1; i >= pre_sz; i--)\
    \ {\n                _finv[i] = _finv[i + 1] * T(i + 1);\n            }\n    \
    \        for(int i = pre_sz; i <= (int)sz; i++) {\n                _inv[i] = _finv[i]\
    \ * _fact[i - 1];\n            }\n        }\n    }\n\n};\n"
  code: "template<class T> struct Enumeration{\n  public:\n    Enumeration(int sz\
    \ = 0) { update(sz); }\n\n    T fact(int k) {\n        update(k);\n        return\
    \ _fact[k];\n    }\n\n    T finv(int k) {\n        update(k);\n        return\
    \ _finv[k];\n    }\n\n    T inv(int k) {\n        update(k);\n        return _inv[k];\n\
    \    }\n\n    T nPk(int n, int k) {\n        if(k < 0 || n < k) return 0;\n  \
    \      return fact(n) * finv(n - k);\n    }\n\n    T nCk(int n, int k) {\n   \
    \     if(k < 0 || n < k) return 0;\n        return fact(n) * finv(k) * finv(n\
    \ - k);\n    }\n\n    T nHk(int n, int k) {\n        if(n < 0 || k < 0) return\
    \ 0;\n        if(n == 0) return 1;\n        else return nCk(n + k - 1, k);\n \
    \   }\n\n    T Catalan(int n){\n        return nCk(2*n, n) - nCk(2*n, n-1);\n\
    \    }\n\n  private:\n    vector<T> _fact, _finv, _inv;\n\n    void update(int\
    \ sz) {\n        if(_fact.size() < sz + 1){\n            int pre_sz = max(1, (int)_fact.size());\n\
    \            _fact.resize(sz + 1, T(1));\n            _finv.resize(sz + 1, T(1));\n\
    \            _inv.resize(sz + 1, T(1));\n            for(int i = pre_sz; i <=\
    \ (int)sz; i++) {\n                _fact[i] = _fact[i - 1] * T(i);\n         \
    \   }\n            _finv[sz] = T(1) / _fact[sz];\n            for(int i = (int)sz\
    \ - 1; i >= pre_sz; i--) {\n                _finv[i] = _finv[i + 1] * T(i + 1);\n\
    \            }\n            for(int i = pre_sz; i <= (int)sz; i++) {\n       \
    \         _inv[i] = _finv[i] * _fact[i - 1];\n            }\n        }\n    }\n\
    \n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Enumeration.hpp
  requiredBy: []
  timestamp: '2022-07-30 23:47:06+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Test/aoj-DPL-5-B.test.cpp
  - Test/aoj-DPL-5-G.test.cpp
documentation_of: Math/Enumeration.hpp
layout: document
title: Enumeration
---

組み合わせ `Modint`を乗せる想定

## コンストラクタ

```cpp
Enumeration<Mint> enu;
```
`fact`, `finv`, `inv`配列を作成. 

##### 計算量
- $O(1)$

## fact

```cpp
Mint enu.fact(int n)
```
$n!$を求める.

##### 計算量
- `update`されていない場合、`n`まで`update`を行う。
- それ以降は$O(1)$

## finv

```cpp
Mint enu.finv(int n)
```
$(n!)^{-1}$を求める.

##### 計算量
- `update`されていない場合, `n`まで`update`を行う.
- それ以降は$O(1)$

## inv

```cpp
Mint enu.inv(int n)
```
$n^{-1}$を求める.

##### 計算量
- `update`されていない場合, `n`まで`update`を行う.
- それ以降は$O(1)$

## nPk

```cpp
Mint enu.nPk(int n, int k)
```
${}_nP_k$を求める. $k < 0$または$n < k$の場合, $0$を返す.

##### 計算量
- `update`されていない場合, `n`まで`update`を行う.
- それ以降は$O(1)$

## nCk

```cpp
Mint enu.nCk(int n, int k)
```
${}_nC_k$を求める. $k < 0$または$n < k$の場合, $0$を返す.

##### 計算量
- `update`されていない場合, `n`まで`update`を行う.
- それ以降は$O(1)$

## nHk

```cpp
Mint enu.nHk(int n, int k)
```
${}_nH_k$を求める. $k < 0$または$n < 0$の場合, $0$を返す.

##### 計算量
- `update`されていない場合, `n+k-1`まで`update`を行う.
- それ以降は$O(1)$

## Catalan

```cpp
Mint enu.Catalan(int n)
```
カタラン数${}_{2n}C_n-{}_{2n}C_{n-1}$ を計算する．これは，$n$個の`()`の正しい括弧列の個数に一致する。
本質は$c_n+1 = \sum_{i=0}^{n} c_i c_{n-i}$ この漸化式を解いたものがカタラン数となる。

##### 計算量
- `update`されていない場合, `2n`まで`update`を行う.
- それ以降は$O(1)$