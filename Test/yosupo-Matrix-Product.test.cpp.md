---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Matrix.hpp
    title: Matrix
  - icon: ':heavy_check_mark:'
    path: Math/Modint.hpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"Test/yosupo-Matrix-Product.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\
    \n\n#line 1 \"Math/Matrix.hpp\"\ntemplate<class T> struct Matrix {\n    int n,\
    \ m;\n    vector<vector<T>> M;\n\n    Matrix() : n(0), m(0) { init(); }\n    Matrix(int\
    \ _n, int _m) : n(_n), m(_m) { init(); }\n    Matrix(int _n) : n(_n), m(_n) {\
    \ init(); }\n\n    void init() {\n        M.resize(n, vector<T>(m));\n    }\n\n\
    \    inline const vector<T> &operator[](int k) const { return (M.at(k)); }\n \
    \   inline vector<T> &operator[](int k) { return (M.at(k)); }\n\n    static Matrix\
    \ I(int n) {\n        Matrix mat(n);\n        for(int i = 0; i < n; i++) mat[i][i]\
    \ = 1;\n        return (mat);\n    }\n\n    Matrix operator+=(const Matrix &B)\
    \ {\n        assert(n == B.n && m == B.m);\n        for(int i = 0; i < n; i++)\
    \ for(int j = 0; j < m; j++) (*this)[i][j] += B[i][j];\n        return (*this);\n\
    \    }\n\n    Matrix operator-=(const Matrix &B) {\n        assert(n == B.n &&\
    \ m == B.m);\n        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) (*this)[i][j]\
    \ -= B[i][j];\n        return (*this);\n    }\n\n    Matrix operator*=(const Matrix\
    \ &B) {\n        assert(m == B.n);\n        m = B.m;\n        vector<vector<T>>\
    \ C(n, vector<T>(B.m, 0));\n        for(int i = 0; i < n; i++) for(int j = 0;\
    \ j < B.m; j++) for(int k = 0; k < B.n; k++) C[i][j] += (*this)[i][k] * B[k][j];\n\
    \        M.swap(C);\n        return (*this);\n    }\n\n    Matrix pow(long long\
    \ k) {\n        assert(n == m);\n        Matrix B = Matrix::I(n);\n        while(k\
    \ > 0) {\n            if(k & 1) B *= *this;\n            *this *= *this;\n   \
    \         k >>= 1LL;\n        }\n        return B;\n    }\n\n    Matrix operator+(const\
    \ Matrix &B) const { return (Matrix(*this) +=B); }\n    Matrix operator-(const\
    \ Matrix &B) const { return (Matrix(*this) -=B); }\n    Matrix operator*(const\
    \ Matrix &B) const { return (Matrix(*this) *=B); }\n\n    friend ostream &operator<<(ostream\
    \ &os, Matrix &p) {\n        for(int i = 0; i < p.n; i++) {\n            os <<\
    \ \"[\";\n            for(int j = 0; j < p.m; j++){\n                os << p[i][j]\
    \ << (j == p.m - 1 ? \"]\\n\" : \", \");\n            }\n        }\n        return\
    \ (os);\n    }\n};\n#line 1 \"Math/Modint.hpp\"\ntemplate<int m> struct StaticModint{\n\
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
    using Modint1000000007 = StaticModint<1000000007>;\n\nusing Mint = Modint998244353;\n\
    #line 8 \"Test/yosupo-Matrix-Product.test.cpp\"\n\nint main() {\n\n    int N,\
    \ M, K; cin >> N >> M >> K;\n    Matrix<Modint998244353> A(N, M), B(M, K);\n\n\
    \    for (int i = 0; i < N; i++) {\n        for (int j = 0; j < M; j++) {\n  \
    \          long long a; cin >> a;\n            A[i][j] = a;\n        }\n    }\n\
    \n    for (int i = 0; i < M; i++) {\n        for (int j = 0; j < K; j++) {\n \
    \           long long b; cin >> b;\n            B[i][j] = b;\n        }\n    }\n\
    \n    Matrix<Modint998244353> C = A * B;\n    for (int i = 0; i < N; i++) {\n\
    \        for (int j = 0; j < K; j++) {\n            cout << C[i][j] << \" \\n\"\
    [j == K - 1];\n        }\n    }\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\
    \n\n#include \"../Math/Matrix.hpp\"\n#include \"../Math/Modint.hpp\"\n\nint main()\
    \ {\n\n    int N, M, K; cin >> N >> M >> K;\n    Matrix<Modint998244353> A(N,\
    \ M), B(M, K);\n\n    for (int i = 0; i < N; i++) {\n        for (int j = 0; j\
    \ < M; j++) {\n            long long a; cin >> a;\n            A[i][j] = a;\n\
    \        }\n    }\n\n    for (int i = 0; i < M; i++) {\n        for (int j = 0;\
    \ j < K; j++) {\n            long long b; cin >> b;\n            B[i][j] = b;\n\
    \        }\n    }\n\n    Matrix<Modint998244353> C = A * B;\n    for (int i =\
    \ 0; i < N; i++) {\n        for (int j = 0; j < K; j++) {\n            cout <<\
    \ C[i][j] << \" \\n\"[j == K - 1];\n        }\n    }\n}\n"
  dependsOn:
  - Math/Matrix.hpp
  - Math/Modint.hpp
  isVerificationFile: true
  path: Test/yosupo-Matrix-Product.test.cpp
  requiredBy: []
  timestamp: '2023-05-05 08:35:42+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-Matrix-Product.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-Matrix-Product.test.cpp
- /verify/Test/yosupo-Matrix-Product.test.cpp.html
title: Test/yosupo-Matrix-Product.test.cpp
---
