---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/stirling_number_of_the_second_kind_fixed_k.test.cpp
    title: test/stirling_number_of_the_second_kind_fixed_k.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"combi/stirling_second_kind_column.cpp\"\n//#include \"modint/MontgomeryModInt.cpp\"\
    \n//#include \"poly/NTTmint.cpp\"\n//#include \"poly/FPS.cpp\"\n\ntemplate<class\
    \ Mint>\nFPS<Mint> stirling_second_kind_column(int n, int k) {\n  vector<FPS<Mint>>\
    \ fs(k);\n  for(int i = 0; i < k; i++) fs[i] = {1, -(i + 1)};\n  auto F = FPS<Mint>::allProd(fs).inv(n\
    \ - k);\n  return F;\n}\n"
  code: "//#include \"modint/MontgomeryModInt.cpp\"\n//#include \"poly/NTTmint.cpp\"\
    \n//#include \"poly/FPS.cpp\"\n\ntemplate<class Mint>\nFPS<Mint> stirling_second_kind_column(int\
    \ n, int k) {\n  vector<FPS<Mint>> fs(k);\n  for(int i = 0; i < k; i++) fs[i]\
    \ = {1, -(i + 1)};\n  auto F = FPS<Mint>::allProd(fs).inv(n - k);\n  return F;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/stirling_second_kind_column.cpp
  requiredBy: []
  timestamp: '2026-06-06 23:34:13+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/stirling_number_of_the_second_kind_fixed_k.test.cpp
documentation_of: combi/stirling_second_kind_column.cpp
layout: document
redirect_from:
- /library/combi/stirling_second_kind_column.cpp
- /library/combi/stirling_second_kind_column.cpp.html
title: combi/stirling_second_kind_column.cpp
---
