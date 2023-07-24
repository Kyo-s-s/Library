---
title: BinaryTrie
documentation_of: ./BinaryTrie.hpp
---

BinaryTrie 
非負整数を扱うMultiSet

集合 $S$ について、
- `insert(x)`: $S$ に $x$ を追加する
- `erase(x)`: $S$ から $x$ を削除する
- `find(x)`: $S$ に $x$ が含まれるか判定する (TODO) これはcountにして個数を返したほうがうれしい？
- `min_element()`: $S$ の最小値を返す
- `min_element(x)`: $\min_{s \in S} (s \oplus x)$ ($\oplus$ はXOR) を返す
- (TODO) `kth_element(k)`: $S$ の $k$ 番目に小さい値を返す

## コンストラクタ
```cpp
BinaryTrie<int length = 30> trie()
```

- 空の集合で初期化
- `length`は必要なビット数 内部的には`bitset`で管理してるので、大きくてもOK

##### 計算量
- $O(1)$

# insert
```cpp
(1) int trie.insert(unsigned long long x)
(2) int trie.insert(const bitset<length> s)
```

- (1): $S$ に $x$ を追加する
- (2): $S$ に $s$ を追加する
- 返り値は $x$ (もしくは$s$) の葉の頂点番号

##### 制約
- (1): $0 \leq x < 2^{length}$

##### 計算量
- $O(length)$


## erase
```cpp
(1) void trie.erase(unsigned long long x)
(2) void trie.erase(const bitset<length> s)
```

- (1): $S$ から $x$ を削除する
- (2): $S$ から $s$ を削除する

##### 制約
- (1): $0 \leq x < 2^{length}$

##### 計算量
- $O(length)$

## find
```cpp
bool trie.find(unsigned long long x)
bool trie.find(const bitset<length> s)
```

- (1): $S$ に $x$ が含まれるか判定する
- (2): $S$ に $s$ が含まれるか判定する

##### 制約
- (1): $0 \leq x < 2^{length}$

##### 計算量
- $O(length)$


## min_element
```cpp
(1) unsigned long long trie.min_element()
(2) unsigned long long trie.min_element(unsigned long long x)
(3) bitset<length> trie.min_element(const bitset<length> s)
```

- (1): $S$ の最小値を返す
- (2): $\min_{s \in S} (s \oplus x)$ ($\oplus$ はXOR) を返す
- (3): $\min_{s \in S} (s \oplus s)$ ($\oplus$ はXOR) を返す

##### 計算量
- $O(length)$
