---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-Matrix-Product.test.cpp
    title: Test/yosupo-Matrix-Product.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Matrix.hpp\"\ntemplate<class T> struct Matrix {\n \
    \   int n, m;\n    vector<vector<T>> M;\n\n    Matrix() : n(0), m(0) { init();\
    \ }\n    Matrix(int _n, int _m) : n(_n), m(_m) { init(); }\n    Matrix(int _n)\
    \ : n(_n), m(_n) { init(); }\n\n    void init() {\n        M.resize(n, vector<T>(m));\n\
    \    }\n\n    inline const vector<T> &operator[](int k) const { return (M.at(k));\
    \ }\n    inline vector<T> &operator[](int k) { return (M.at(k)); }\n\n    static\
    \ Matrix I(int n) {\n        Matrix mat(n);\n        for(int i = 0; i < n; i++)\
    \ mat[i][i] = 1;\n        return (mat);\n    }\n\n    Matrix operator+=(const\
    \ Matrix &B) {\n        assert(n == B.n && m == B.m);\n        for(int i = 0;\
    \ i < n; i++) for(int j = 0; j < m; j++) (*this)[i][j] += B[i][j];\n        return\
    \ (*this);\n    }\n\n    Matrix operator-=(const Matrix &B) {\n        assert(n\
    \ == B.n && m == B.m);\n        for(int i = 0; i < n; i++) for(int j = 0; j <\
    \ m; j++) (*this)[i][j] -= B[i][j];\n        return (*this);\n    }\n\n    Matrix\
    \ operator*=(const Matrix &B) {\n        assert(m == B.n);\n        m = B.m;\n\
    \        vector<vector<T>> C(n, vector<T>(B.m, 0));\n        for(int i = 0; i\
    \ < n; i++) for(int j = 0; j < B.m; j++) for(int k = 0; k < B.n; k++) C[i][j]\
    \ += (*this)[i][k] * B[k][j];\n        M.swap(C);\n        return (*this);\n \
    \   }\n\n    Matrix pow(long long k) {\n        assert(n == m);\n        Matrix\
    \ B = Matrix::I(n);\n        while(k > 0) {\n            if(k & 1) B *= *this;\n\
    \            *this *= *this;\n            k >>= 1LL;\n        }\n        return\
    \ B;\n    }\n\n    Matrix operator+(const Matrix &B) const { return (Matrix(*this)\
    \ +=B); }\n    Matrix operator-(const Matrix &B) const { return (Matrix(*this)\
    \ -=B); }\n    Matrix operator*(const Matrix &B) const { return (Matrix(*this)\
    \ *=B); }\n\n    friend ostream &operator<<(ostream &os, Matrix &p) {\n      \
    \  for(int i = 0; i < p.n; i++) {\n            os << \"[\";\n            for(int\
    \ j = 0; j < p.m; j++){\n                os << p[i][j] << (j == p.m - 1 ? \"]\\\
    n\" : \", \");\n            }\n        }\n        return (os);\n    }\n};\n"
  code: "template<class T> struct Matrix {\n    int n, m;\n    vector<vector<T>> M;\n\
    \n    Matrix() : n(0), m(0) { init(); }\n    Matrix(int _n, int _m) : n(_n), m(_m)\
    \ { init(); }\n    Matrix(int _n) : n(_n), m(_n) { init(); }\n\n    void init()\
    \ {\n        M.resize(n, vector<T>(m));\n    }\n\n    inline const vector<T> &operator[](int\
    \ k) const { return (M.at(k)); }\n    inline vector<T> &operator[](int k) { return\
    \ (M.at(k)); }\n\n    static Matrix I(int n) {\n        Matrix mat(n);\n     \
    \   for(int i = 0; i < n; i++) mat[i][i] = 1;\n        return (mat);\n    }\n\n\
    \    Matrix operator+=(const Matrix &B) {\n        assert(n == B.n && m == B.m);\n\
    \        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) (*this)[i][j] +=\
    \ B[i][j];\n        return (*this);\n    }\n\n    Matrix operator-=(const Matrix\
    \ &B) {\n        assert(n == B.n && m == B.m);\n        for(int i = 0; i < n;\
    \ i++) for(int j = 0; j < m; j++) (*this)[i][j] -= B[i][j];\n        return (*this);\n\
    \    }\n\n    Matrix operator*=(const Matrix &B) {\n        assert(m == B.n);\n\
    \        m = B.m;\n        vector<vector<T>> C(n, vector<T>(B.m, 0));\n      \
    \  for(int i = 0; i < n; i++) for(int j = 0; j < B.m; j++) for(int k = 0; k <\
    \ B.n; k++) C[i][j] += (*this)[i][k] * B[k][j];\n        M.swap(C);\n        return\
    \ (*this);\n    }\n\n    Matrix pow(long long k) {\n        assert(n == m);\n\
    \        Matrix B = Matrix::I(n);\n        while(k > 0) {\n            if(k &\
    \ 1) B *= *this;\n            *this *= *this;\n            k >>= 1LL;\n      \
    \  }\n        return B;\n    }\n\n    Matrix operator+(const Matrix &B) const\
    \ { return (Matrix(*this) +=B); }\n    Matrix operator-(const Matrix &B) const\
    \ { return (Matrix(*this) -=B); }\n    Matrix operator*(const Matrix &B) const\
    \ { return (Matrix(*this) *=B); }\n\n    friend ostream &operator<<(ostream &os,\
    \ Matrix &p) {\n        for(int i = 0; i < p.n; i++) {\n            os << \"[\"\
    ;\n            for(int j = 0; j < p.m; j++){\n                os << p[i][j] <<\
    \ (j == p.m - 1 ? \"]\\n\" : \", \");\n            }\n        }\n        return\
    \ (os);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Matrix.hpp
  requiredBy: []
  timestamp: '2023-05-05 08:35:42+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-Matrix-Product.test.cpp
documentation_of: Math/Matrix.hpp
layout: document
title: Matrix
---

行列

## コンストラクタ
```cpp
(1) Matrix<T> m(int n, int m)
(2) Matrix<T> m(int n)
```

- (1): $n \times m$ 行列を生成する 
- (2): $n$ 次正方行列を生成する

これらは、 二次元配列のようにアクセスができる。

また、和、差、積とべき乗が行える。
和、差は $O(nm)$、積は$n \times m$ 行列と$m \times k$ 行列に対し $O(nmk)$ 、
べき乗は $O(n^2 \log k)$ かかる。
