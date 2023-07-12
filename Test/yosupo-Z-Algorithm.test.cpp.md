---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/Zalgorithm.hpp
    title: Zalgorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"Test/yosupo-Z-Algorithm.test.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n\n#line 1 \"String/Zalgorithm.hpp\"\nvector<int> Zalgorithm(const string &S)\
    \ {\n    vector<int> Z(S.size());\n    Z[0] = (int)S.size();\n    int i = 1, j\
    \ = 0;\n    while(i < S.size()) {\n        while(i + j < (int)(S.size()) && S[j]\
    \ == S[i + j]) j++;\n        Z[i] = j;\n\n        if(j == 0) {\n            i++;\n\
    \            continue;\n        }\n\n        int k = 1;\n        while(k < j &&\
    \ k + Z[k] < j) {\n            Z[i + k] = Z[k];\n            k++;\n        }\n\
    \        i += k;\n        j -= k;\n    }\n    return Z;\n}\n\ntemplate<class T>\n\
    vector<int> Zalgorithm(const vector<T> &S) {\n    vector<int> Z(S.size());\n \
    \   Z[0] = (int)S.size();\n    int i = 1, j = 0;\n    while(i < S.size()) {\n\
    \        while(i + j < (int)(S.size()) && S[j] == S[i + j]) j++;\n        Z[i]\
    \ = j;\n\n        if(j == 0) {\n            i++;\n            continue;\n    \
    \    }\n\n        int k = 1;\n        while(k < j && k + Z[k] < j) {\n       \
    \     Z[i + k] = Z[k];\n            k++;\n        }\n        i += k;\n       \
    \ j -= k;\n    }\n    return Z;\n}\n#line 7 \"Test/yosupo-Z-Algorithm.test.cpp\"\
    \n\nint main() {\n\n    string S;\n    cin >> S;\n    vector<int> Z = Zalgorithm(S);\n\
    \    for(int i = 0; i < (int)(Z.size()); i++) {\n        cout << Z[i] << \" \"\
    ;\n    }\n    cout << endl;\n\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n\n#include \"../String/Zalgorithm.hpp\"\n\nint main() {\n\n    string S;\n \
    \   cin >> S;\n    vector<int> Z = Zalgorithm(S);\n    for(int i = 0; i < (int)(Z.size());\
    \ i++) {\n        cout << Z[i] << \" \";\n    }\n    cout << endl;\n\n}\n"
  dependsOn:
  - String/Zalgorithm.hpp
  isVerificationFile: true
  path: Test/yosupo-Z-Algorithm.test.cpp
  requiredBy: []
  timestamp: '2023-07-12 13:28:30+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-Z-Algorithm.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-Z-Algorithm.test.cpp
- /verify/Test/yosupo-Z-Algorithm.test.cpp.html
title: Test/yosupo-Z-Algorithm.test.cpp
---
