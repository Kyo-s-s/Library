---
title: Tree
documentation_of: ./Tree.hpp
---

## コンストラクタ

```cpp
(1) Tree tree(int N);
(2) Tree<T> tree(int N);
```

- (1): $N$頂点の重みなし木を作る
- (2): $N$頂点の型`T`の重み付き木を作る



##  add_edge

```cpp
(1) void tree.add_edge(int u, int v)
(2) void tree.add_edge(int u, int v, T w)
```

- (1): $u, v$に重み$1$(=重みなし)の辺を追加する
- (2): $u, v$に重み$w$の辺を追加する

##### 制約

- $0 \leq u, v < N,~u \neq v$

##### 計算量

- $O(1)$



## calc_dist

```cpp
vector<T> tree.calc_dist(int root = 0)
```

- `root`から各頂点の距離が入った配列を返す。`dist[i]` = `root`から$i$までの距離 である。

##### 制約

- $0 \leq root < N$

##### 計算量

- $O(N)$



## diameter

```cpp
tuple<T, int, int> tree.diameter()
```

- 与えられた木の直径、端の2頂点を返す。第1引数が直径、第2, 3引数が端の頂点

##### 計算量

- $O(N)$



## lca_build

```cpp
void tree.lca_build(int root = 0)
```

- 根を`root`として、LCAの構築を行う。

##### 制約

- $0 \leq root < N$

##### 計算量

- $O(N \log N)$



## lca

```cpp
int tree.lca(int u, int v)
```

- 頂点$u, v$のLCAを求める。`lca_build`が行われていなかった場合、`root = 0`として`lca_build`が行われる。

##### 制約

- $0 \leq u, v < N$

##### 計算量

- $O(\log N)$



## dist

```cpp
T tree.dist(int u, int v)
```

- 頂点$u, v$間の距離を求める。`lca_build`が行われていなかった場合、`root = 0`として`lca_build`が行われる。

##### 制約

- $0 \leq u, v < N$

##### 計算量

- $O(\log N)$



