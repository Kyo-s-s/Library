---
title: UnionFind
documentation_of: ./UnionFind.hpp
---

## コンストラクタ
```cpp
UnionFind uf(int N);
```

- $N$ 頂点の UnionFind を構築する

## merge
```cpp
int uf.merge(int a, int b);
```

- $a$ と $b$ を結合する
- 結合後の根が返る 

##### 制約

- $0 \leq x, y < N$

##### 計算量

- ならし $O(\alpha(N))$


## leader
```cpp
int uf.leader(a)
```

- $a$ の根を返す

##### 制約

- $0 \leq a < N$

##### 計算量

- ならし $O(\alpha(N))$


## same
```cpp
bool uf.same(int a, int b);
```

##### 制約

- $0 \leq a, b < N$

##### 計算量

- ならし $O(\alpha(N))$


## size
```cpp
int uf.size(int a);
```

- $a$ が属するグループのサイズを返す

##### 制約

- $0 \leq a < N$

##### 計算量

- ならし $O(\alpha(N))$


## count
```cpp
int uf.count();
```

- グループの数を返す

##### 計算量

- $O(1)$


## groups
```cpp
vector<vector<int>> uf.groups();
```

- グループごとに分けた vector を返す

##### 計算量

- $O(N)$
