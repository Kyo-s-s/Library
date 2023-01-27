---
title: CumulativeSum
documentation_of: ./CumulativeSum.hpp
---

累積和

## コンストラクタ
```cpp
CumulativeSum<T> cum(vector<T> v)
```
- `v`の内容で初期化

##### 計算量
- $O(N)$

## sum
```cpp
(1) T cum.sum(int r)
(2) T cum.sum(int l, int r)
```
- (1): `a[0] + ... + a[r-1]`を返す
- (2): `a[l] + ... + a[r-1]`を返す

##### 制約
- (1): $0 \leq r \leq N$
- (2): $0 \leq l \leq r \leq N$

##### 計算量
- $O(1)$

