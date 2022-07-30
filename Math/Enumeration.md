---
title: Enumeration
documentation_of: ./Enumeration.hpp
---

組み合わせ `Modint`を乗せる想定

## コンストラクタ

```cpp
Enumeration<Mint> enu;
```
`fact`, `finv`, `inv`配列を作成. 

##### 計算量
- $O(1)$

## fact

```cpp
Mint enu.fact(int n)
```
$n!$を求める.

##### 計算量
- `update`されていない場合、`n`まで`update`を行う。
- それ以降は$O(1)$

## finv

```cpp
Mint enu.finv(int n)
```
$(n!)^{-1}$を求める.

##### 計算量
- `update`されていない場合, `n`まで`update`を行う.
- それ以降は$O(1)$

## inv

```cpp
Mint enu.inv(int n)
```
$n^{-1}$を求める.

##### 計算量
- `update`されていない場合, `n`まで`update`を行う.
- それ以降は$O(1)$

## nPk

```cpp
Mint enu.nPk(int n, int k)
```
${}_nP_k$を求める. $k < 0$または$n < k$の場合, $0$を返す.

##### 計算量
- `update`されていない場合, `n`まで`update`を行う.
- それ以降は$O(1)$

## nCk

```cpp
Mint enu.nCk(int n, int k)
```
${}_nC_k$を求める. $k < 0$または$n < k$の場合, $0$を返す.

##### 計算量
- `update`されていない場合, `n`まで`update`を行う.
- それ以降は$O(1)$

## nHk

```cpp
Mint enu.nHk(int n, int k)
```
${}_nH_k$を求める. $k < 0$または$n < 0$の場合, $0$を返す.

##### 計算量
- `update`されていない場合, `n+k-1`まで`update`を行う.
- それ以降は$O(1)$

## Catalan

```cpp
Mint enu.Catalan(int n)
```
カタラン数${}_{2n}C_n - {}_{2n}C_{n-1}$を計算する．これは，$n$個の`()`の正しい括弧列の個数に一致する。

##### 計算量
- `update`されていない場合, `2n`まで`update`を行う.
- それ以降は$O(1)$