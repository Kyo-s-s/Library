---
title: Enumeration
documentation_of: ./Enumeration.hpp
---

組み合わせ `Modint`を乗せる想定

## コンストラクタ

```cpp
Enumeration<T> enu
```
`fact`, `finv`, `inv`配列を作成. 

##### 計算量

- $O(1)$

## fact

```cpp
enu.fact(int n)
```
$n!$を求める.

##### 計算量

- `update`されていない場合、`n`まで`update`を行う。
- それ以降は$O(1)$

## finv

```cpp
enu.finv(int n)
```
$(n!)^{-1}$を求める.

##### 計算量

- `update`されていない場合, `n`まで`update`を行う.
- それ以降は$O(1)$

## inv

```cpp
enu.inv(int n)
```
$n^{-1}$を求める.

##### 計算量

- `update`されていない場合, `n`まで`update`を行う.
- それ以降は$O(1)$

## nPk

```cpp
enu.nPk(int n, int k)
```
${}_nP_k$を求める. $k < 0$または$n < k$の場合, $0$を返す.

##### 計算量

- `update`されていない場合, `n`まで`update`を行う.
- それ以降は$O(1)$

## nCk

```cpp
enu.nCk(int n, int k)
```
${}_nC_k$を求める. $k < 0$または$n < k$の場合, $0$を返す.

##### 計算量

- `update`されていない場合, `n`まで`update`を行う.
- それ以降は$O(1)$

## nHk

```cpp
enu.nHk(int n, int k)
```
${}_nH_k$を求める. $k < 0$または$n < 0$の場合, $0$を返す.

##### 計算量

- `update`されていない場合, `n+k-1`まで`update`を行う.
- それ以降は$O(1)$