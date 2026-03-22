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
  bundledCode: "#line 1 \"poly/interpolate_iota.cpp\"\ntemplate<class Mint>\nMint\
    \ interpolate_iota(vc<Mint> ys, Mint x) {\n  const int n = size(ys);\n  binomial<Mint>\
    \ bn(n);\n\n  vc<Mint> suf(n + 1, Mint(1));\n  for(int i = n - 1; i >= 0; i--)\n\
    \    suf[i] = suf[i + 1] * (x - i);\n\n  Mint ans = 0, pre = 1;\n  for(int i =\
    \ 0; i < n; i++) {\n    ans += ys[i] * pre * suf[i + 1] * bn.faci(i) *\n     \
    \      bn.faci(n - 1 - i) * Mint((n - 1 - i) % 2 == 1 ? -1 : 1);\n    pre *= (x\
    \ - i);\n  }\n\n  return ans;\n}\n"
  code: "template<class Mint>\nMint interpolate_iota(vc<Mint> ys, Mint x) {\n  const\
    \ int n = size(ys);\n  binomial<Mint> bn(n);\n\n  vc<Mint> suf(n + 1, Mint(1));\n\
    \  for(int i = n - 1; i >= 0; i--)\n    suf[i] = suf[i + 1] * (x - i);\n\n  Mint\
    \ ans = 0, pre = 1;\n  for(int i = 0; i < n; i++) {\n    ans += ys[i] * pre *\
    \ suf[i + 1] * bn.faci(i) *\n           bn.faci(n - 1 - i) * Mint((n - 1 - i)\
    \ % 2 == 1 ? -1 : 1);\n    pre *= (x - i);\n  }\n\n  return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/interpolate_iota.cpp
  requiredBy: []
  timestamp: '2026-03-22 16:32:23+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/interpolate_iota.cpp
layout: document
redirect_from:
- /library/poly/interpolate_iota.cpp
- /library/poly/interpolate_iota.cpp.html
title: poly/interpolate_iota.cpp
---
