---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/rolling_hash.cpp\"\ntemplate<class Mint, int cnt>\n\
    struct rolling_hash {\n  int sz;\n  vector<vector<Mint>> powr;\n  rolling_hash(int\
    \ mxLen) : sz(mxLen + 1), powr(cnt, vector<Mint>(mxLen + 1)) {\n    mt19937 rng(clock);\n\
    \    uniform_int_distribution<int> unif(0, Mint::get_mod() - 1);\n    for(int\
    \ i = 0; i < cnt; i++) {\n      powr[i][0] = 1, powr[i][1] = unif(rng);\n    \
    \  for(int j = 2; j < sz; j++)\n        powr[i][j] = powr[i][j - 1] * powr[i][1];\n\
    \    }\n  }\n\n  //pad a zero before first char\n  vector<vector<Mint>> prefix_hash(string\
    \ s) {\n    vector h(cnt, vector<Mint>(ssize(s) + 1));\n    for(int i = 0; i <\
    \ cnt; i++)\n      for(int j = 0; j < ssize(s); j++)\n        h[i][j + 1] = h[i][j]\
    \ * powr[i][1] + Mint(s[j]);\n    return h;\n  }\n\n  //return hash of [l, r),\
    \ 0-based\n  array<Mint, cnt> substring_hash(vector<vector<Mint>> &h, int l, int\
    \ r) {\n    array<Mint, cnt> ret;\n    for(int i = 0; i < cnt; i++)\n      ret[i]\
    \ = h[i][r] - h[i][l] * powr[i][r - l];\n    return ret;\n  }\n};\n"
  code: "template<class Mint, int cnt>\nstruct rolling_hash {\n  int sz;\n  vector<vector<Mint>>\
    \ powr;\n  rolling_hash(int mxLen) : sz(mxLen + 1), powr(cnt, vector<Mint>(mxLen\
    \ + 1)) {\n    mt19937 rng(clock);\n    uniform_int_distribution<int> unif(0,\
    \ Mint::get_mod() - 1);\n    for(int i = 0; i < cnt; i++) {\n      powr[i][0]\
    \ = 1, powr[i][1] = unif(rng);\n      for(int j = 2; j < sz; j++)\n        powr[i][j]\
    \ = powr[i][j - 1] * powr[i][1];\n    }\n  }\n\n  //pad a zero before first char\n\
    \  vector<vector<Mint>> prefix_hash(string s) {\n    vector h(cnt, vector<Mint>(ssize(s)\
    \ + 1));\n    for(int i = 0; i < cnt; i++)\n      for(int j = 0; j < ssize(s);\
    \ j++)\n        h[i][j + 1] = h[i][j] * powr[i][1] + Mint(s[j]);\n    return h;\n\
    \  }\n\n  //return hash of [l, r), 0-based\n  array<Mint, cnt> substring_hash(vector<vector<Mint>>\
    \ &h, int l, int r) {\n    array<Mint, cnt> ret;\n    for(int i = 0; i < cnt;\
    \ i++)\n      ret[i] = h[i][r] - h[i][l] * powr[i][r - l];\n    return ret;\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.cpp
  requiredBy: []
  timestamp: '2026-06-06 23:34:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling_hash.cpp
layout: document
redirect_from:
- /library/string/rolling_hash.cpp
- /library/string/rolling_hash.cpp.html
title: string/rolling_hash.cpp
---
