---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bernoulli_number.test.cpp
    title: test/bernoulli_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/prefix_sum_of_polynomial.test.cpp
    title: test/prefix_sum_of_polynomial.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"combi/bernoulli_number.cpp\"\n//#include<modint/Montgomery_modint.cpp>\n\
    //#include<poly/NTTmint.cpp>\n//#include<poly/FPS.cpp>\n\ntemplate<class Mint>\n\
    vc<Mint> bernoulli_number(int n) {\n  FPS<Mint> f(n + 1);\n  f[n] = Mint(1) /\
    \ factorial<Mint>(n);\n  for(int i = n - 1; i > 0; i--)\n    f[i] = f[i + 1] *\
    \ (i + 1);\n  f.erase(f.begin());\n  f = f.inv(n);\n  vc<Mint> v(n);\n  for(int\
    \ i = 0; i < n; i++)\n    v[i] = f[i] * factorial<Mint>(i);\n  return v;\n}\n"
  code: "//#include<modint/Montgomery_modint.cpp>\n//#include<poly/NTTmint.cpp>\n\
    //#include<poly/FPS.cpp>\n\ntemplate<class Mint>\nvc<Mint> bernoulli_number(int\
    \ n) {\n  FPS<Mint> f(n + 1);\n  f[n] = Mint(1) / factorial<Mint>(n);\n  for(int\
    \ i = n - 1; i > 0; i--)\n    f[i] = f[i + 1] * (i + 1);\n  f.erase(f.begin());\n\
    \  f = f.inv(n);\n  vc<Mint> v(n);\n  for(int i = 0; i < n; i++)\n    v[i] = f[i]\
    \ * factorial<Mint>(i);\n  return v;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/bernoulli_number.cpp
  requiredBy: []
  timestamp: '2026-09-03 22:17:13+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/prefix_sum_of_polynomial.test.cpp
  - test/bernoulli_number.test.cpp
documentation_of: combi/bernoulli_number.cpp
layout: document
redirect_from:
- /library/combi/bernoulli_number.cpp
- /library/combi/bernoulli_number.cpp.html
title: combi/bernoulli_number.cpp
---
