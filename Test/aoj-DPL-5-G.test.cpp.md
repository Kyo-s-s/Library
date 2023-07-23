---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Math/Enumeration.hpp
    title: Enumeration
  - icon: ':question:'
    path: Math/Modint.hpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_G
  bundledCode: "#line 1 \"Test/aoj-DPL-5-G.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_G\"\
    \n\n#line 1 \"Math/Modint.hpp\"\ntemplate<int m> struct StaticModint{\n    using\
    \ mint = StaticModint;\n  public:\n    static constexpr int mod() { return m;\
    \ }\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n      \
    \  return x;\n    }\n\n    StaticModint() : _v(0) {}\n    template <class T>\n\
    \    StaticModint(T v) {\n        long long x = (long long)(v % (long long)(umod()));\n\
    \        if (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n\n \
    \   unsigned int val() const { return _v; }\n\n    mint& operator++() {\n    \
    \    _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n    }\n\
    \    mint& operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    mint operator++(int) {\n        mint result\
    \ = *this;\n        ++*this;\n        return result;\n    }\n    mint operator--(int)\
    \ {\n        mint result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    mint& operator+=(const mint& rhs) {\n        _v += rhs._v;\n   \
    \     if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    mint&\
    \ operator-=(const mint& rhs) {\n        _v -= rhs._v;\n        if (_v >= umod())\
    \ _v += umod();\n        return *this;\n    }\n    mint& operator*=(const mint&\
    \ rhs) {\n        unsigned long long z = _v;\n        z *= rhs._v;\n        _v\
    \ = (unsigned int)(z % umod());\n        return *this;\n    }\n    mint& operator/=(const\
    \ mint& rhs) { return *this = *this * rhs.inv(); }\n\n    mint operator+() const\
    \ { return *this; }\n    mint operator-() const { return mint() - *this; }\n\n\
    \    mint pow(long long n) const {\n        assert(0 <= n);\n        mint x =\
    \ *this, r = 1;\n        while (n) {\n            if (n & 1) r *= x;\n       \
    \     x *= x;\n            n >>= 1;\n        }\n        return r;\n    }\n   \
    \ mint inv() const {\n        assert(_v);\n        return pow(umod() - 2);\n \
    \   }\n\n    friend mint operator+(const mint& lhs, const mint& rhs) { return\
    \ mint(lhs) += rhs;}\n    friend mint operator-(const mint& lhs, const mint& rhs)\
    \ { return mint(lhs) -= rhs; }\n    friend mint operator*(const mint& lhs, const\
    \ mint& rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const mint&\
    \ lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }\n\n    friend ostream\
    \ &operator<<(ostream &os, mint x) {\n        os << x.val();\n        return (os);\n\
    \    }\n\n  private:\n    unsigned int _v;\n    static constexpr unsigned int\
    \ umod() { return m; }\n\n};\n\nusing Modint998244353 = StaticModint<998244353>;\n\
    using Modint1000000007 = StaticModint<1000000007>;\n\nusing Mint = Modint998244353;\n\
    #line 7 \"Test/aoj-DPL-5-G.test.cpp\"\n\n#line 1 \"Math/Enumeration.hpp\"\ntemplate<class\
    \ T> struct Enumeration{\n  public:\n    Enumeration(int sz = 0) { update(sz);\
    \ }\n\n    T fact(int k) {\n        update(k);\n        return _fact[k];\n   \
    \ }\n\n    T finv(int k) {\n        update(k);\n        return _finv[k];\n   \
    \ }\n\n    T inv(int k) {\n        update(k);\n        return _inv[k];\n    }\n\
    \n    T nPk(int n, int k) {\n        if(k < 0 || n < k) return 0;\n        return\
    \ fact(n) * finv(n - k);\n    }\n\n    T nCk(int n, int k) {\n        if(k < 0\
    \ || n < k) return 0;\n        return fact(n) * finv(k) * finv(n - k);\n    }\n\
    \n    T nHk(int n, int k) {\n        if(n < 0 || k < 0) return 0;\n        if(n\
    \ == 0) return 1;\n        else return nCk(n + k - 1, k);\n    }\n\n    T Catalan(int\
    \ n){\n        return nCk(2*n, n) - nCk(2*n, n-1);\n    }\n\n  private:\n    vector<T>\
    \ _fact, _finv, _inv;\n\n    void update(int sz) {\n        if(_fact.size() <\
    \ sz + 1){\n            int pre_sz = max(1, (int)_fact.size());\n            _fact.resize(sz\
    \ + 1, T(1));\n            _finv.resize(sz + 1, T(1));\n            _inv.resize(sz\
    \ + 1, T(1));\n            for(int i = pre_sz; i <= (int)sz; i++) {\n        \
    \        _fact[i] = _fact[i - 1] * T(i);\n            }\n            _finv[sz]\
    \ = T(1) / _fact[sz];\n            for(int i = (int)sz - 1; i >= pre_sz; i--)\
    \ {\n                _finv[i] = _finv[i + 1] * T(i + 1);\n            }\n    \
    \        for(int i = pre_sz; i <= (int)sz; i++) {\n                _inv[i] = _finv[i]\
    \ * _fact[i - 1];\n            }\n        }\n    }\n\n};\n#line 9 \"Test/aoj-DPL-5-G.test.cpp\"\
    \n\n\nint main() {\n\n    int N, K;\n    cin >> N >> K;\n\n    Enumeration<Modint1000000007>\
    \ enu;\n\n    cout << enu.nPk(K, N) << endl;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_G\"\
    \n\n#include \"../Math/Modint.hpp\"\n\n#include \"../Math/Enumeration.hpp\"\n\n\
    \nint main() {\n\n    int N, K;\n    cin >> N >> K;\n\n    Enumeration<Modint1000000007>\
    \ enu;\n\n    cout << enu.nPk(K, N) << endl;\n}\n"
  dependsOn:
  - Math/Modint.hpp
  - Math/Enumeration.hpp
  isVerificationFile: true
  path: Test/aoj-DPL-5-G.test.cpp
  requiredBy: []
  timestamp: '2023-07-23 03:18:56+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/aoj-DPL-5-G.test.cpp
layout: document
redirect_from:
- /verify/Test/aoj-DPL-5-G.test.cpp
- /verify/Test/aoj-DPL-5-G.test.cpp.html
title: Test/aoj-DPL-5-G.test.cpp
---
