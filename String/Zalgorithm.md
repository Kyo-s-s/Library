---
title: Zalgorithm
documentation_of: ./Zalgorithm.hpp
---

## Zalgorithm
```C++
(1) vector<int> Zalgorithm(string S)
(2) vector<int> Zalgorithm(vector<T> S)
```

入力の長さを $n$ として, 長さ $n$ の配列を返す. $i$番目の要素は`s[0..n)`と`s[i..n)`の最長共通接頭辞.

###### 計算量

- $O(|S|)$

