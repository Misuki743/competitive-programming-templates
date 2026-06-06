---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/polynomial_taylor_shift.test.cpp
    title: test/polynomial_taylor_shift.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/Taylor_shift.cpp\"\n//#include \"modint/Montgomery_modint.cpp\"\
    \n//#include \"poly/NTT.cpp\"\n//#include \"poly/FPS.cpp\"\n//#include \"combi/binom.cpp\"\
    \n\ntemplate<class Mint>\nFPS<Mint> Taylor_shift(FPS<Mint> f, Mint c) {\n  int\
    \ n = ssize(f);\n  binomial<Mint> bn(n);\n  FPS<Mint> a = f;\n  for(int i = 0;\
    \ i < n; i++)\n    a[i] *= bn.fac(i);\n  FPS<Mint> b(n);\n  Mint pre = 1;\n  for(int\
    \ i = 0; i < n; i++, pre *= c)\n    b[i] = pre * bn.faci(i);\n  ranges::reverse(b);\n\
    \  f = a * b;\n  f.erase(f.begin(), f.begin() + n - 1);\n  for(int i = 0; i <\
    \ n; i++)\n    f[i] *= bn.faci(i);\n  return f;\n}\n"
  code: "//#include \"modint/Montgomery_modint.cpp\"\n//#include \"poly/NTT.cpp\"\n\
    //#include \"poly/FPS.cpp\"\n//#include \"combi/binom.cpp\"\n\ntemplate<class\
    \ Mint>\nFPS<Mint> Taylor_shift(FPS<Mint> f, Mint c) {\n  int n = ssize(f);\n\
    \  binomial<Mint> bn(n);\n  FPS<Mint> a = f;\n  for(int i = 0; i < n; i++)\n \
    \   a[i] *= bn.fac(i);\n  FPS<Mint> b(n);\n  Mint pre = 1;\n  for(int i = 0; i\
    \ < n; i++, pre *= c)\n    b[i] = pre * bn.faci(i);\n  ranges::reverse(b);\n \
    \ f = a * b;\n  f.erase(f.begin(), f.begin() + n - 1);\n  for(int i = 0; i < n;\
    \ i++)\n    f[i] *= bn.faci(i);\n  return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/Taylor_shift.cpp
  requiredBy: []
  timestamp: '2026-06-07 01:41:25+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/polynomial_taylor_shift.test.cpp
documentation_of: poly/Taylor_shift.cpp
layout: document
redirect_from:
- /library/poly/Taylor_shift.cpp
- /library/poly/Taylor_shift.cpp.html
title: poly/Taylor_shift.cpp
---
