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
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-Matrix-Product.test.cpp
    title: Test/yosupo-Matrix-Product.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Modint.hpp\"\ntemplate<int m> struct StaticModint{\n\
    \    using mint = StaticModint;\n  public:\n    static constexpr int mod() { return\
    \ m; }\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n   \
    \     return x;\n    }\n\n    StaticModint() : _v(0) {}\n    template <class T>\n\
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
    using Modint1000000007 = StaticModint<1000000007>;\n\nusing Mint = Modint998244353;\n"
  code: "template<int m> struct StaticModint{\n    using mint = StaticModint;\n  public:\n\
    \    static constexpr int mod() { return m; }\n    static mint raw(int v) {\n\
    \        mint x;\n        x._v = v;\n        return x;\n    }\n\n    StaticModint()\
    \ : _v(0) {}\n    template <class T>\n    StaticModint(T v) {\n        long long\
    \ x = (long long)(v % (long long)(umod()));\n        if (x < 0) x += umod();\n\
    \        _v = (unsigned int)(x);\n    }\n\n    unsigned int val() const { return\
    \ _v; }\n\n    mint& operator++() {\n        _v++;\n        if (_v == umod())\
    \ _v = 0;\n        return *this;\n    }\n    mint& operator--() {\n        if\
    \ (_v == 0) _v = umod();\n        _v--;\n        return *this;\n    }\n    mint\
    \ operator++(int) {\n        mint result = *this;\n        ++*this;\n        return\
    \ result;\n    }\n    mint operator--(int) {\n        mint result = *this;\n \
    \       --*this;\n        return result;\n    }\n\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return *this;\n\
    \    }\n    mint& operator*=(const mint& rhs) {\n        unsigned long long z\
    \ = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n    \
    \    return *this;\n    }\n    mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n    mint operator+() const { return *this; }\n   \
    \ mint operator-() const { return mint() - *this; }\n\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const {\n \
    \       assert(_v);\n        return pow(umod() - 2);\n    }\n\n    friend mint\
    \ operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs;}\n  \
    \  friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs)\
    \ -= rhs; }\n    friend mint operator*(const mint& lhs, const mint& rhs) { return\
    \ mint(lhs) *= rhs; }\n    friend mint operator/(const mint& lhs, const mint&\
    \ rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const mint& lhs,\
    \ const mint& rhs) { return lhs._v == rhs._v; }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }\n\n    friend ostream\
    \ &operator<<(ostream &os, mint x) {\n        os << x.val();\n        return (os);\n\
    \    }\n\n  private:\n    unsigned int _v;\n    static constexpr unsigned int\
    \ umod() { return m; }\n\n};\n\nusing Modint998244353 = StaticModint<998244353>;\n\
    using Modint1000000007 = StaticModint<1000000007>;\n\nusing Mint = Modint998244353;\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Modint.hpp
  requiredBy: []
  timestamp: '2022-08-21 11:18:02+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Test/yosupo-Matrix-Product.test.cpp
  - Test/aoj-DPL-5-B.test.cpp
  - Test/aoj-DPL-5-G.test.cpp
documentation_of: Math/Modint.hpp
layout: document
title: Modint
---

ACLのModintに出力をつけただけ
Modは素数でないとダメ(今後ちゃんとかきなおすかも)

