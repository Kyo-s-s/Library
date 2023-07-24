---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-Set-Xor-Min.test.cpp
    title: Test/yosupo-Set-Xor-Min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Data_structure/BinaryTrie.hpp\"\ntemplate<int length = 30>\
    \ struct BinaryTrie {\n    struct Node {\n        vector<int> next;\n        int\
    \ parent, val, cnt;\n        Node(int parent = -1, int val = -1) : parent(parent),\
    \ val(val), cnt(0) {\n            next = vector<int>(2, -1);\n        }\n    };\n\
    \    vector<Node> nodes;\n\n    BinaryTrie() {\n        nodes = { Node() };\n\
    \    }\n\n    int add_node(int parent, int val) {\n        nodes.push_back(Node(parent,\
    \ val));\n        return nodes.size() - 1;\n    }\n\n    int insert(unsigned long\
    \ long x) { return insert(bitset<length>(x)); }\n    int insert(const bitset<length>\
    \ &s) {\n        int now_node = 0;\n        nodes[now_node].cnt++;\n        for\
    \ (int i = length - 1; i >= 0; i--) {\n            int next = s[i];\n        \
    \    if (nodes[now_node].next[next] == -1) {\n                nodes[now_node].next[next]\
    \ = add_node(now_node, next);\n            }\n            now_node = nodes[now_node].next[next];\n\
    \            nodes[now_node].cnt++;\n        }\n        return now_node;\n   \
    \ }\n\n    void erase(unsigned long long x) { erase(bitset<length>(x)); }\n  \
    \  void erase(const bitset<length> &s) {\n        if (!find(s)) return;\n    \
    \    int now_node = 0;\n        nodes[now_node].cnt--;\n        for (int i = length\
    \ - 1; i >= 0; i--) {\n            int next = s[i];\n            now_node = nodes[now_node].next[next];\n\
    \            nodes[now_node].cnt--;\n        }\n    }\n\n\n    bool find(long\
    \ long x) { return find(bitset<length>(x)); }\n    bool find(const bitset<length>\
    \ &s) {\n        int now_node = 0;\n        if (nodes[now_node].cnt == 0) {\n\
    \            return false;\n        }\n        for (int i = length - 1; i >= 0;\
    \ i--) {\n            int next = s[i];\n            if (nodes[now_node].next[next]\
    \ == -1) {\n                return false;\n            }\n            now_node\
    \ = nodes[now_node].next[next];\n            if (nodes[now_node].cnt == 0) {\n\
    \                return false;\n            }\n        }\n        return true;\n\
    \    }\n\n    unsigned long long min_element(unsigned long long x = 0LL) {\n \
    \       return min_element(bitset<length>(x)).to_ullong();\n    }\n    bitset<length>\
    \ min_element(const bitset<length> &s = bitset<length>()) {\n        assert(nodes[0].cnt\
    \ > 0);\n        int now_node = 0;\n        bitset<length> ret;\n        for (int\
    \ i = length - 1; i >= 0; i--) {\n            int next = s[i];\n            if\
    \ (nodes[now_node].next[next] == -1 || nodes[nodes[now_node].next[next]].cnt ==\
    \ 0) {\n                next = 1 - next;\n            }\n            ret[i] =\
    \ next ^ s[i];\n            now_node = nodes[now_node].next[next];\n        }\n\
    \        return ret;\n    }\n};\n"
  code: "template<int length = 30> struct BinaryTrie {\n    struct Node {\n      \
    \  vector<int> next;\n        int parent, val, cnt;\n        Node(int parent =\
    \ -1, int val = -1) : parent(parent), val(val), cnt(0) {\n            next = vector<int>(2,\
    \ -1);\n        }\n    };\n    vector<Node> nodes;\n\n    BinaryTrie() {\n   \
    \     nodes = { Node() };\n    }\n\n    int add_node(int parent, int val) {\n\
    \        nodes.push_back(Node(parent, val));\n        return nodes.size() - 1;\n\
    \    }\n\n    int insert(unsigned long long x) { return insert(bitset<length>(x));\
    \ }\n    int insert(const bitset<length> &s) {\n        int now_node = 0;\n  \
    \      nodes[now_node].cnt++;\n        for (int i = length - 1; i >= 0; i--) {\n\
    \            int next = s[i];\n            if (nodes[now_node].next[next] == -1)\
    \ {\n                nodes[now_node].next[next] = add_node(now_node, next);\n\
    \            }\n            now_node = nodes[now_node].next[next];\n         \
    \   nodes[now_node].cnt++;\n        }\n        return now_node;\n    }\n\n   \
    \ void erase(unsigned long long x) { erase(bitset<length>(x)); }\n    void erase(const\
    \ bitset<length> &s) {\n        if (!find(s)) return;\n        int now_node =\
    \ 0;\n        nodes[now_node].cnt--;\n        for (int i = length - 1; i >= 0;\
    \ i--) {\n            int next = s[i];\n            now_node = nodes[now_node].next[next];\n\
    \            nodes[now_node].cnt--;\n        }\n    }\n\n\n    bool find(long\
    \ long x) { return find(bitset<length>(x)); }\n    bool find(const bitset<length>\
    \ &s) {\n        int now_node = 0;\n        if (nodes[now_node].cnt == 0) {\n\
    \            return false;\n        }\n        for (int i = length - 1; i >= 0;\
    \ i--) {\n            int next = s[i];\n            if (nodes[now_node].next[next]\
    \ == -1) {\n                return false;\n            }\n            now_node\
    \ = nodes[now_node].next[next];\n            if (nodes[now_node].cnt == 0) {\n\
    \                return false;\n            }\n        }\n        return true;\n\
    \    }\n\n    unsigned long long min_element(unsigned long long x = 0LL) {\n \
    \       return min_element(bitset<length>(x)).to_ullong();\n    }\n    bitset<length>\
    \ min_element(const bitset<length> &s = bitset<length>()) {\n        assert(nodes[0].cnt\
    \ > 0);\n        int now_node = 0;\n        bitset<length> ret;\n        for (int\
    \ i = length - 1; i >= 0; i--) {\n            int next = s[i];\n            if\
    \ (nodes[now_node].next[next] == -1 || nodes[nodes[now_node].next[next]].cnt ==\
    \ 0) {\n                next = 1 - next;\n            }\n            ret[i] =\
    \ next ^ s[i];\n            now_node = nodes[now_node].next[next];\n        }\n\
    \        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_structure/BinaryTrie.hpp
  requiredBy: []
  timestamp: '2023-07-24 07:10:25+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-Set-Xor-Min.test.cpp
documentation_of: Data_structure/BinaryTrie.hpp
layout: document
title: BinaryTrie
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
