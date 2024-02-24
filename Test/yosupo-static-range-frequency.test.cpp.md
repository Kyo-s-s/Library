---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_structure/MergeTree.hpp
    title: MergeTree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_frequency
    links:
    - https://judge.yosupo.jp/problem/static_range_frequency
  bundledCode: "#line 1 \"Test/yosupo-static-range-frequency.test.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n\n#include<Data_structure/MergeTree.hpp>\n\nusing T = unordered_map<int, int>;\n\
    \nstruct M {\n    using T = int;\n    static T op(T a, T b) { return a + b; }\n\
    \    static T e() { return 0; }\n};\n\nint main() {\n\n    int N, Q; cin >> N\
    \ >> Q;\n    vector<int> A(N);\n    for (auto &a : A) cin >> a;\n\n    auto f\
    \ = [&](int l, int r) -> T {\n        unordered_map<int, int> mp;\n        for\
    \ (int i = l; i < r; i++) mp[A[i]]++;\n        return mp;\n    };\n\n    MergeTree<T>\
    \ mt(N, f);\n\n    while (Q--) {\n        int l, r; cin >> l >> r;\n        int\
    \ x; cin >> x;\n\n        cout << mt.prod<M>(l, r, [&](const T &t) -> M::T {\n\
    \            return t.count(x) ? t.at(x) : 0;\n        }) << \"\\n\";\n    }\n\
    \n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n\n#include<Data_structure/MergeTree.hpp>\n\nusing T = unordered_map<int, int>;\n\
    \nstruct M {\n    using T = int;\n    static T op(T a, T b) { return a + b; }\n\
    \    static T e() { return 0; }\n};\n\nint main() {\n\n    int N, Q; cin >> N\
    \ >> Q;\n    vector<int> A(N);\n    for (auto &a : A) cin >> a;\n\n    auto f\
    \ = [&](int l, int r) -> T {\n        unordered_map<int, int> mp;\n        for\
    \ (int i = l; i < r; i++) mp[A[i]]++;\n        return mp;\n    };\n\n    MergeTree<T>\
    \ mt(N, f);\n\n    while (Q--) {\n        int l, r; cin >> l >> r;\n        int\
    \ x; cin >> x;\n\n        cout << mt.prod<M>(l, r, [&](const T &t) -> M::T {\n\
    \            return t.count(x) ? t.at(x) : 0;\n        }) << \"\\n\";\n    }\n\
    \n}\n"
  dependsOn:
  - Data_structure/MergeTree.hpp
  isVerificationFile: true
  path: Test/yosupo-static-range-frequency.test.cpp
  requiredBy: []
  timestamp: '2024-02-25 02:01:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-static-range-frequency.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-static-range-frequency.test.cpp
- /verify/Test/yosupo-static-range-frequency.test.cpp.html
title: Test/yosupo-static-range-frequency.test.cpp
---
