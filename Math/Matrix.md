---
title: Matrix
documentation_of: ./Matrix.hpp
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
