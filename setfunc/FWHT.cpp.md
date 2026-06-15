---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bitwise_xor_convolution.test.cpp
    title: test/bitwise_xor_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"setfunc/FWHT.cpp\"\ntemplate<class Mint>\nvoid FWHT(vector<Mint>\
    \ &a, bool inverse) {\n  for(int n = ssize(a), step = 1; step < n; step <<= 1)\n\
    \    for(int i = 0; i < n; i += step << 1)\n      for(int j = i; j < i + step;\
    \ j++)\n        tie(a[j], a[j + step]) = pair(a[j] + a[j + step], a[j] - a[j +\
    \ step]);\n  if (inverse) {\n    Mint I = Mint(1) / Mint(ssize(a));\n    for(Mint\
    \ &x : a) x *= I;\n  }\n}\n"
  code: "template<class Mint>\nvoid FWHT(vector<Mint> &a, bool inverse) {\n  for(int\
    \ n = ssize(a), step = 1; step < n; step <<= 1)\n    for(int i = 0; i < n; i +=\
    \ step << 1)\n      for(int j = i; j < i + step; j++)\n        tie(a[j], a[j +\
    \ step]) = pair(a[j] + a[j + step], a[j] - a[j + step]);\n  if (inverse) {\n \
    \   Mint I = Mint(1) / Mint(ssize(a));\n    for(Mint &x : a) x *= I;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/FWHT.cpp
  requiredBy: []
  timestamp: '2026-06-15 20:55:33+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/bitwise_xor_convolution.test.cpp
documentation_of: setfunc/FWHT.cpp
layout: document
redirect_from:
- /library/setfunc/FWHT.cpp
- /library/setfunc/FWHT.cpp.html
title: setfunc/FWHT.cpp
---
