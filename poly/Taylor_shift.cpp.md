---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/polynomial_taylor_shift.test.cpp
    title: test/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/prefix_sum_of_polynomial.test.cpp
    title: test/prefix_sum_of_polynomial.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/Taylor_shift.cpp\"\n//#include \"modint/Montgomery_modint.cpp\"\
    \n//#include \"poly/NTT.cpp\"\n\ntemplate<class Mint>\nvc<Mint> Taylor_shift(vc<Mint>\
    \ f, Mint c) {\n  static NTT ntt;\n  int n = ssize(f);\n  vc<Mint> a = f;\n  for(int\
    \ i = 0; i < n; i++)\n    a[i] *= factorial<Mint>(i);\n  vc<Mint> b(n);\n  Mint\
    \ pre = 1;\n  for(int i = 0; i < n; i++, pre *= c)\n    b[i] = pre * factorial_inv<Mint>(i);\n\
    \  ranges::reverse(b);\n  f = ntt.conv(a, b);\n  f.erase(f.begin(), f.begin()\
    \ + n - 1);\n  for(int i = 0; i < n; i++)\n    f[i] *= factorial_inv<Mint>(i);\n\
    \  return f;\n}\n"
  code: "//#include \"modint/Montgomery_modint.cpp\"\n//#include \"poly/NTT.cpp\"\n\
    \ntemplate<class Mint>\nvc<Mint> Taylor_shift(vc<Mint> f, Mint c) {\n  static\
    \ NTT ntt;\n  int n = ssize(f);\n  vc<Mint> a = f;\n  for(int i = 0; i < n; i++)\n\
    \    a[i] *= factorial<Mint>(i);\n  vc<Mint> b(n);\n  Mint pre = 1;\n  for(int\
    \ i = 0; i < n; i++, pre *= c)\n    b[i] = pre * factorial_inv<Mint>(i);\n  ranges::reverse(b);\n\
    \  f = ntt.conv(a, b);\n  f.erase(f.begin(), f.begin() + n - 1);\n  for(int i\
    \ = 0; i < n; i++)\n    f[i] *= factorial_inv<Mint>(i);\n  return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/Taylor_shift.cpp
  requiredBy: []
  timestamp: '2026-09-03 22:17:13+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/prefix_sum_of_polynomial.test.cpp
  - test/polynomial_taylor_shift.test.cpp
documentation_of: poly/Taylor_shift.cpp
layout: document
redirect_from:
- /library/poly/Taylor_shift.cpp
- /library/poly/Taylor_shift.cpp.html
title: poly/Taylor_shift.cpp
---
