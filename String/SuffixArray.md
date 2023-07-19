---
title: SuffixArray
documentation_of: ./SuffixArray.hpp
---

## SuffixArray
```C++
vector<int> SuffixArray(string S)
```

$S$ について(空文字を含む)SuffixArrayを返す. 長さ $|S|+1$ の配列を返す. 

###### 計算量

- $O(|S|\log|S|)$


### SuffixArray とは？

接尾辞(先頭から $n \in \{0, \ldots, |S|\}$ 文字を取り除いた文字列)を，辞書順に並べたもの．

たとえば`suffixarray`について，
| $n$ | 接尾辞 |
|:---:|:---:|
| 0 | `suffixarray` |
| 1 | `uffixarray` |
| 2 | `ffixarray` |
| 3 | `fixarray` |
| 4 | `ixarray` |
| 5 | `xarray` |
| 6 | `array` |
| 7 | `rray` |
| 8 | `ray` |
| 9 | `ay` |
| 10 | `y` |
| 11 | ` ` |

である．これを接尾辞について辞書順に並び変えると，
| $n$ | 接尾辞 |
|:---:|:---:|
| 11 | ` ` |
| 6 | `array` |
| 9 | `ay` |
| 2 | `ffixarray` |
| 3 | `fixarray` |
| 4 | `ixarray` |
| 8 | `ray` |
| 7 | `rray` |
| 0 | `suffixarray` |
| 1 | `uffixarray` |
| 5 | `xarray` |
| 10 | `y` |

となるので，`suffixarray`のSuffixArrayは`{11, 6, 9, 2, 3, 4, 8, 7, 0, 1, 5, 10}`である．よってこれが返る．
