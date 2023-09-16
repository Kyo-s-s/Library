---
title: Dinic
documentation_of: ./Dinic.hpp
---

## コンストラクタ

```cpp
Dinic<Cap> dinic(int N)
```

- $N$頂点のグラフを作成する．何も辺が存在しない．
- `Cap` は `long long` もしくは `int` であること．


## add_edge

```cpp
int add_edge(int from, int to, Cap cap)
```

- `from`から`to`へ容量`cap`の辺を追加する。
- 以降、追加した辺の本数を $M$ とする。
- 追加した辺の番号を返す。

##### 制約

- $0 \leq from, to < N$
- $0 \leq cap$

##### 計算量

- (ならし？) $O(1)$


## flow

```cpp
(1) Cap flow(int s, int t)
(2) Cap flow(int s, int t, Cap flow_limit)
```

- (1): `s` から `t` まで、上限なしの最大流を求める。
- (2): `s` から `t` まで、流量の上限を `flow_limit` とした最大流を求める。

##### 制約

- $0 \leq s, t < N$
- $s \neq t$
- (2): $0 \leq flow\_limit$

##### 計算量

- $O(\min(N^{\frac{2}{3}}M, M^{\frac{3}{2}}))$ (辺の容量がすべて $1$ の場合)
- $O(N^2M)$


## min_cut

```cpp
vector<bool> min_cut(int s)
```

- `max_flow(s, t)` を呼んだ後に呼ぶことを想定。頂点 $s$ から到達可能な頂点を `true` とした `vector` を返す。

##### 制約

- $0 \leq s < N$

##### 計算量

- $O(N + M)$


## get_flow

```cpp
Cap get_flow(int idx)
```

- `max_flow(s, t)` を呼んだ後に呼ぶことを想定。頂点 `from` から頂点 `to` へ流れた流量を返す。
- `idx` は追加された辺の番号である。

##### 制約

- $0 \leq from, to < N$

##### 計算量

- $O(1)$

## change_edge

```cpp
void change_edge(int idx, Cap new_cap, Cap new_flow)
```

- `idx` 番目の辺の容量を `new_cap` に変更し、流量を `new_flow` に変更する。

##### 制約

- $0 \leq idx < M$

##### 計算量

- $O(1)$
