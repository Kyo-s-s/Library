---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-many-aplusb.test.cpp
    title: Test/yosupo-many-aplusb.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Template/Template.hpp\"\n#pragma region header\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n// #include <atcoder/all>\n// using namespace\
    \ atcoder;\n\n/* alias */\nusing ull = unsigned long long;\nusing ll = long long;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\nusing vi = vector<int>;\n\
    using vll = vector<long long>;\nusing vd = vector<double>;\nusing vs = vector<string>;\n\
    using vb = vector<bool>;\nusing vpii = vector<pair<int, int>>;\nusing vpll = vector<pair<ll,\
    \ ll>>;\nusing vvi = vector<vector<int>>;\nusing vvll = vector<vector<long long>>;\n\
    using vvd = vector<vector<double>>;\nusing vvs = vector<vector<string>>;\nusing\
    \ vvb = vector<vector<bool>>;\ntemplate<typename T> using min_priority_queue =\
    \ priority_queue<T, vector<T>, greater<T>>;\n\n/* define */\n#define MOD 998244353\n\
    // #define MOD 1000000007\n#define INF (1LL << 60)\n#define elif else if\n#define\
    \ pb push_back\n#define pf push_front\n#define fi first\n#define se second\n#define\
    \ all(obj) (obj).begin(), (obj).end()\n#define YESNO(bool) cout << (bool ? \"\
    YES\\n\" : \"NO\\n\")\n#define YesNo(bool) cout << (bool ? \"Yes\\n\" : \"No\\\
    n\")\n#define yesno(bool) cout << (bool ? \"yes\\n\" : \"no\\n\")\ntemplate<class\
    \ T> bool chmax(T &a, const T &b) {if(a<b){ a=b; return 1;} return 0;}\ntemplate<class\
    \ T> bool chmin(T &a, const T &b) {if(b<a){ a=b; return 1;} return 0;}\n#define\
    \ debug(x) cerr << #x << \":\" << x << \"\\n\";\n\n/* REP macro */\n#define reps(i,\
    \ a, n) for(ll i = (a); i < (n); i++)\n#define rep(i, n) reps(i, 0, (n))\n#define\
    \ rrep(i, n) reps(i, 1, (n + 1))\n#define repd(i, n) for(ll i = (n - 1); i >=\
    \ 0; i--)\n#define rrepd(i, n) for(ll i = (n); i >= 1; i--)\n#define fore(i, a)\
    \ for(auto &i: a)\n\n/* vector */\ntemplate<class T> T vmax(vector<T> &array){\
    \ T ret = array[0]; for(T a: array) chmax(ret, a); return ret; }\ntemplate<class\
    \ T> T vmin(vector<T> &array){ T ret = array[0]; for(T a: array) chmin(ret, a);\
    \ return ret; }\ntemplate<class T> T sum(vector<T> &array){ T ret = 0; for(T a:array)\
    \ ret += a; return ret; }\ntemplate<class T> void list_set(vector<T> &array){\
    \ sort(all(array)); array.erase(unique(all(array)),array.end()); }\ntemplate<class\
    \ T> int bisect_left(vector<T> &array, T key){ return lower_bound(all(array),key)\
    \ - array.begin(); }\ntemplate<class T> int bisect_right(vector<T> &array, T key){\
    \ return upper_bound(all(array),key) - array.begin(); }\n\n/* string */\nll string_to_ll(string\
    \ n){ ll ret = 0, k = 1; while(n.length() > 0){ ret += k * (n.back() - '0'); n.pop_back();\
    \ k *= 10; } return ret; }\nstring ll_to_string(ll n){ string ret = \"\"; while(n\
    \ > 0){ ret.pb((n % 10) + '0'); n /= 10; } reverse(all(ret)); return ret; }\n\n\
    struct popopo{ popopo(){ cin.tie(0); ios::sync_with_stdio(0); cout << fixed <<\
    \ setprecision(15); }; } popopoppo;\n\n// n = 1,...,N \u306B\u5BFE\u3057\u3066\
    \u3001n % A < B \u3092\u6E80\u305F\u3059\u3082\u306E\u306E\u6570 \nll Count_of_n_mod_A_less_than_B(ll\
    \ N, ll A, ll B){ return N / A * min(A, B) + min(N % A, B - 1); }\n\n\n/* IN/OUT\
    \ */\nint scan() { return getchar(); }\nvoid scan(int &a) { cin >> a; }\nvoid\
    \ scan(long long &a) { cin >> a; }\nvoid scan(char &a) { cin >> a; }\nvoid scan(double\
    \ &a) { cin >> a; }\nvoid scan(string &a) { cin >> a; }\ntemplate <class T, class\
    \ S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }\ntemplate <class\
    \ T> void scan(vector<T> &);\ntemplate <class T> void scan(vector<T> &a) { for(auto\
    \ &i : a) scan(i); }\n\nvoid IN(){}\ntemplate<class Head, class... Tail> void\
    \ IN(Head& head, Tail &...tail){ scan(head); IN(tail...); }\n\n#define INT(...)\
    \ int __VA_ARGS__; IN(__VA_ARGS__)\n#define LL(...) ll __VA_ARGS__; IN(__VA_ARGS__)\n\
    #define STR(...) string __VA_ARGS__; IN(__VA_ARGS__)\n#define VEC(type, name,\
    \ size) vector<type> name(size); IN(name)\n#define VECS(type, name, size) vector<type>\
    \ name(size + 1); for(int i = 1; i <= size; i++) scan(name[i])\n\nvoid OUT(){\
    \ cout << \"\\n\"; }\ntemplate<class T> void output(T a){ cout << a; }\ntemplate<class\
    \ T> void output(vector<T> v){ for(int i = 0; i < v.size(); i++) cout << v[i]\
    \ << (i == v.size() - 1 ? \"\" : \" \"); }\ntemplate<class Head, class... Tail>\
    \ void OUT(const Head &head, const Tail &...tail) { output(head); if(sizeof...(tail))\
    \ cout << \" \"; OUT(tail...); }\n\nvoid FLASH(){ cout << endl; }\ntemplate<class\
    \ Head, class... Tail> void FLASH(const Head  &head, const Tail &...tail) { output(head);\
    \ if(sizeof...(tail)) cout << \" \"; FLASH(tail...); }\n\n/* boost */\n// #include\
    \ <boost/multiprecision/cpp_dec_float.hpp>\n// #include <boost/multiprecision/cpp_int.hpp>\n\
    // namespace mp = boost::multiprecision;\n// // \u4EFB\u610F\u9577\u6574\u6570\
    \u578B\n// using Bint = mp::cpp_int;\n// // \u4EEE\u6570\u90E8\u304C10\u9032\u6570\
    \u30671024\u6841\u306E\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u578B(TLE\u3057\u305F\
    \u3089\u5C0F\u3055\u304F\u3059\u308B)\n// using Real = mp::number<mp::cpp_dec_float<1024>>;\n\
    \n#pragma endregion header    \n"
  code: "#pragma region header\n#include <bits/stdc++.h>\nusing namespace std;\n//\
    \ #include <atcoder/all>\n// using namespace atcoder;\n\n/* alias */\nusing ull\
    \ = unsigned long long;\nusing ll = long long;\nusing pii = pair<int, int>;\n\
    using pll = pair<ll, ll>;\nusing vi = vector<int>;\nusing vll = vector<long long>;\n\
    using vd = vector<double>;\nusing vs = vector<string>;\nusing vb = vector<bool>;\n\
    using vpii = vector<pair<int, int>>;\nusing vpll = vector<pair<ll, ll>>;\nusing\
    \ vvi = vector<vector<int>>;\nusing vvll = vector<vector<long long>>;\nusing vvd\
    \ = vector<vector<double>>;\nusing vvs = vector<vector<string>>;\nusing vvb =\
    \ vector<vector<bool>>;\ntemplate<typename T> using min_priority_queue = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n/* define */\n#define MOD 998244353\n// #define MOD\
    \ 1000000007\n#define INF (1LL << 60)\n#define elif else if\n#define pb push_back\n\
    #define pf push_front\n#define fi first\n#define se second\n#define all(obj) (obj).begin(),\
    \ (obj).end()\n#define YESNO(bool) cout << (bool ? \"YES\\n\" : \"NO\\n\")\n#define\
    \ YesNo(bool) cout << (bool ? \"Yes\\n\" : \"No\\n\")\n#define yesno(bool) cout\
    \ << (bool ? \"yes\\n\" : \"no\\n\")\ntemplate<class T> bool chmax(T &a, const\
    \ T &b) {if(a<b){ a=b; return 1;} return 0;}\ntemplate<class T> bool chmin(T &a,\
    \ const T &b) {if(b<a){ a=b; return 1;} return 0;}\n#define debug(x) cerr << #x\
    \ << \":\" << x << \"\\n\";\n\n/* REP macro */\n#define reps(i, a, n) for(ll i\
    \ = (a); i < (n); i++)\n#define rep(i, n) reps(i, 0, (n))\n#define rrep(i, n)\
    \ reps(i, 1, (n + 1))\n#define repd(i, n) for(ll i = (n - 1); i >= 0; i--)\n#define\
    \ rrepd(i, n) for(ll i = (n); i >= 1; i--)\n#define fore(i, a) for(auto &i: a)\n\
    \n/* vector */\ntemplate<class T> T vmax(vector<T> &array){ T ret = array[0];\
    \ for(T a: array) chmax(ret, a); return ret; }\ntemplate<class T> T vmin(vector<T>\
    \ &array){ T ret = array[0]; for(T a: array) chmin(ret, a); return ret; }\ntemplate<class\
    \ T> T sum(vector<T> &array){ T ret = 0; for(T a:array) ret += a; return ret;\
    \ }\ntemplate<class T> void list_set(vector<T> &array){ sort(all(array)); array.erase(unique(all(array)),array.end());\
    \ }\ntemplate<class T> int bisect_left(vector<T> &array, T key){ return lower_bound(all(array),key)\
    \ - array.begin(); }\ntemplate<class T> int bisect_right(vector<T> &array, T key){\
    \ return upper_bound(all(array),key) - array.begin(); }\n\n/* string */\nll string_to_ll(string\
    \ n){ ll ret = 0, k = 1; while(n.length() > 0){ ret += k * (n.back() - '0'); n.pop_back();\
    \ k *= 10; } return ret; }\nstring ll_to_string(ll n){ string ret = \"\"; while(n\
    \ > 0){ ret.pb((n % 10) + '0'); n /= 10; } reverse(all(ret)); return ret; }\n\n\
    struct popopo{ popopo(){ cin.tie(0); ios::sync_with_stdio(0); cout << fixed <<\
    \ setprecision(15); }; } popopoppo;\n\n// n = 1,...,N \u306B\u5BFE\u3057\u3066\
    \u3001n % A < B \u3092\u6E80\u305F\u3059\u3082\u306E\u306E\u6570 \nll Count_of_n_mod_A_less_than_B(ll\
    \ N, ll A, ll B){ return N / A * min(A, B) + min(N % A, B - 1); }\n\n\n/* IN/OUT\
    \ */\nint scan() { return getchar(); }\nvoid scan(int &a) { cin >> a; }\nvoid\
    \ scan(long long &a) { cin >> a; }\nvoid scan(char &a) { cin >> a; }\nvoid scan(double\
    \ &a) { cin >> a; }\nvoid scan(string &a) { cin >> a; }\ntemplate <class T, class\
    \ S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }\ntemplate <class\
    \ T> void scan(vector<T> &);\ntemplate <class T> void scan(vector<T> &a) { for(auto\
    \ &i : a) scan(i); }\n\nvoid IN(){}\ntemplate<class Head, class... Tail> void\
    \ IN(Head& head, Tail &...tail){ scan(head); IN(tail...); }\n\n#define INT(...)\
    \ int __VA_ARGS__; IN(__VA_ARGS__)\n#define LL(...) ll __VA_ARGS__; IN(__VA_ARGS__)\n\
    #define STR(...) string __VA_ARGS__; IN(__VA_ARGS__)\n#define VEC(type, name,\
    \ size) vector<type> name(size); IN(name)\n#define VECS(type, name, size) vector<type>\
    \ name(size + 1); for(int i = 1; i <= size; i++) scan(name[i])\n\nvoid OUT(){\
    \ cout << \"\\n\"; }\ntemplate<class T> void output(T a){ cout << a; }\ntemplate<class\
    \ T> void output(vector<T> v){ for(int i = 0; i < v.size(); i++) cout << v[i]\
    \ << (i == v.size() - 1 ? \"\" : \" \"); }\ntemplate<class Head, class... Tail>\
    \ void OUT(const Head &head, const Tail &...tail) { output(head); if(sizeof...(tail))\
    \ cout << \" \"; OUT(tail...); }\n\nvoid FLASH(){ cout << endl; }\ntemplate<class\
    \ Head, class... Tail> void FLASH(const Head  &head, const Tail &...tail) { output(head);\
    \ if(sizeof...(tail)) cout << \" \"; FLASH(tail...); }\n\n/* boost */\n// #include\
    \ <boost/multiprecision/cpp_dec_float.hpp>\n// #include <boost/multiprecision/cpp_int.hpp>\n\
    // namespace mp = boost::multiprecision;\n// // \u4EFB\u610F\u9577\u6574\u6570\
    \u578B\n// using Bint = mp::cpp_int;\n// // \u4EEE\u6570\u90E8\u304C10\u9032\u6570\
    \u30671024\u6841\u306E\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u578B(TLE\u3057\u305F\
    \u3089\u5C0F\u3055\u304F\u3059\u308B)\n// using Real = mp::number<mp::cpp_dec_float<1024>>;\n\
    \n#pragma endregion header    \n"
  dependsOn: []
  isVerificationFile: false
  path: Template/Template.hpp
  requiredBy: []
  timestamp: '2023-05-11 05:28:07+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-many-aplusb.test.cpp
documentation_of: Template/Template.hpp
layout: document
redirect_from:
- /library/Template/Template.hpp
- /library/Template/Template.hpp.html
title: Template/Template.hpp
---
