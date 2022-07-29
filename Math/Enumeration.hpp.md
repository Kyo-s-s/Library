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
  bundledCode: "#line 1 \"Math/Enumeration.hpp\"\ntemplate<class T> struct Enumeration{\n\
    \  public:\n    Enumeration(int sz = 0) { update(sz); }\n\n    T fact(int k) {\n\
    \        update(k);\n        return _fact[k];\n    }\n\n    T finv(int k) {\n\
    \        update(k);\n        return _finv[k];\n    }\n\n    T inv(int k) {\n \
    \       update(k);\n        return _inv[k];\n    }\n\n    T nPk(int n, int k)\
    \ {\n        if(k < 0 || n < k) return 0;\n        return fact(n) * finv(n - k);\n\
    \    }\n\n    T nCk(int n, int k) {\n        if(k < 0 || n < k) return 0;\n  \
    \      return fact(n) * finv(k) * finv(n - k);\n    }\n\n    T nHk(int n, int\
    \ k) {\n        if(n < 0 || k < 0) return 0;\n        if(n == 0) return 1;\n \
    \       else return nCk(n + k - 1, k);\n    }\n\n  private:\n    vector<T> _fact,\
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
    \   }\n\n  private:\n    vector<T> _fact, _finv, _inv;\n\n    void update(int\
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
  timestamp: '2022-07-29 22:39:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Enumeration.hpp
layout: document
title: Enumeration
---

## Enumeration

hogehoge

`Enumeration enum`

```cpp
int main(){
    cout << "Hello" << endl;
}
```