---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"Test/yosupo-Z-Algorithm.test.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n\n// #include \"../String/Zalgorithm.hpp\"\n\nint main() {\n\n    string S;\n\
    \    cin >> S;\n    vector<int> Z = Zalgorithm(S);\n    for(int i = 0; i < (int)(Z.size());\
    \ i++) {\n        cout << Z[i] << \" \";\n    }\n    cout << endl;\n\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n\n// #include \"../String/Zalgorithm.hpp\"\n\nint main() {\n\n    string S;\n\
    \    cin >> S;\n    vector<int> Z = Zalgorithm(S);\n    for(int i = 0; i < (int)(Z.size());\
    \ i++) {\n        cout << Z[i] << \" \";\n    }\n    cout << endl;\n\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Test/yosupo-Z-Algorithm.test.cpp
  requiredBy: []
  timestamp: '2023-07-12 13:25:29+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/yosupo-Z-Algorithm.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-Z-Algorithm.test.cpp
- /verify/Test/yosupo-Z-Algorithm.test.cpp.html
title: Test/yosupo-Z-Algorithm.test.cpp
---
