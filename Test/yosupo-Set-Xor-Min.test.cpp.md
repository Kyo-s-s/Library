---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_structure/BinaryTrie.hpp
    title: BinaryTrie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"Test/yosupo-Set-Xor-Min.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\
    \n\n#line 1 \"Data_structure/BinaryTrie.hpp\"\ntemplate<int length = 30> struct\
    \ BinaryTrie {\n    struct Node {\n        vector<int> next;\n        int parent,\
    \ val, cnt;\n        Node(int parent = -1, int val = -1) : parent(parent), val(val),\
    \ cnt(0) {\n            next = vector<int>(2, -1);\n        }\n    };\n    vector<Node>\
    \ nodes;\n\n    BinaryTrie() {\n        nodes = { Node() };\n    }\n\n    int\
    \ add_node(int parent, int val) {\n        nodes.push_back(Node(parent, val));\n\
    \        return nodes.size() - 1;\n    }\n\n    int insert(unsigned long long\
    \ x) { return insert(bitset<length>(x)); }\n    int insert(const bitset<length>\
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
    \        return ret;\n    }\n};\n#line 7 \"Test/yosupo-Set-Xor-Min.test.cpp\"\n\
    \nint main() {\n\n    int Q; cin >> Q;\n    BinaryTrie<30> trie;\n\n    while\
    \ (Q--) {\n        int t; cin >> t;\n        if (t == 0) {\n            long long\
    \ x; cin >> x;\n            if (!trie.find(x)) {\n                trie.insert(x);\n\
    \            }\n        }\n        if (t == 1) {\n            long long x; cin\
    \ >> x;\n            trie.erase(x);\n        }\n        if (t == 2) {\n      \
    \      long long x; cin >> x;\n            cout << trie.min_element(x) << endl;\n\
    \        }\n    }\n\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\
    \n\n#include \"../Data_structure/BinaryTrie.hpp\"\n\nint main() {\n\n    int Q;\
    \ cin >> Q;\n    BinaryTrie<30> trie;\n\n    while (Q--) {\n        int t; cin\
    \ >> t;\n        if (t == 0) {\n            long long x; cin >> x;\n         \
    \   if (!trie.find(x)) {\n                trie.insert(x);\n            }\n   \
    \     }\n        if (t == 1) {\n            long long x; cin >> x;\n         \
    \   trie.erase(x);\n        }\n        if (t == 2) {\n            long long x;\
    \ cin >> x;\n            cout << trie.min_element(x) << endl;\n        }\n   \
    \ }\n\n}"
  dependsOn:
  - Data_structure/BinaryTrie.hpp
  isVerificationFile: true
  path: Test/yosupo-Set-Xor-Min.test.cpp
  requiredBy: []
  timestamp: '2023-07-24 07:10:25+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-Set-Xor-Min.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-Set-Xor-Min.test.cpp
- /verify/Test/yosupo-Set-Xor-Min.test.cpp.html
title: Test/yosupo-Set-Xor-Min.test.cpp
---
