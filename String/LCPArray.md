---
title: LCPArray
documentation_of: ./LCPArray.hpp
---

## LCPArray
```C++
vector<int> LCPArray(string S, vector<int> sa)
```

$S$ の長さを $N$ として, 長さ $N$ の配列を返す. $i$番目の要素は`sa[i]`と`sa[i+1]`の最長共通接頭辞．

###### 制約

- `sa` は $S$ のSuffixArray(空文字を含む)．

###### 計算量

- $O(N)$