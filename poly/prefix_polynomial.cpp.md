---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/prefix_sum_of_polynomial.test.cpp
    title: test/prefix_sum_of_polynomial.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/prefix_polynomial.cpp\"\ntemplate<class Mint>\nvc<Mint>\
    \ prefix_polynomial(vc<Mint> F) {\n  const int n = ssize(F);\n  F.resize(bit_ceil(n\
    \ * 2u));\n  Mint f0 = F[0];\n\n  auto B = bernoulli_number<Mint>(n);\n  vc<Mint>\
    \ G(size(F));\n  for(int i = 0; i < n; i++) {\n    F[i] *= factorial<Mint>(i);\n\
    \    G[i] = (i % 2 == 1 ? -1 : 1) * factorial_inv<Mint>(i) * B[i];\n  }\n  reverse(G.begin()\
    \ + 1, G.end());\n  ntt.ntt(F, 0), ntt.ntt(G, 0);\n  for(int i = 0; i < ssize(F);\
    \ i++)\n    F[i] *= G[i];\n  ntt.ntt(F, 1);\n  F.back() = 0;\n  ranges::rotate(F,\
    \ prev(F.end()));\n  F.resize(n + 1);\n  for(int i = 0; i <= n; i++)\n    F[i]\
    \ *= factorial_inv<Mint>(i);\n  F = Taylor_shift<Mint>(F, -1);\n  F[0] += f0;\n\
    \n  return F;\n}\n"
  code: "template<class Mint>\nvc<Mint> prefix_polynomial(vc<Mint> F) {\n  const int\
    \ n = ssize(F);\n  F.resize(bit_ceil(n * 2u));\n  Mint f0 = F[0];\n\n  auto B\
    \ = bernoulli_number<Mint>(n);\n  vc<Mint> G(size(F));\n  for(int i = 0; i < n;\
    \ i++) {\n    F[i] *= factorial<Mint>(i);\n    G[i] = (i % 2 == 1 ? -1 : 1) *\
    \ factorial_inv<Mint>(i) * B[i];\n  }\n  reverse(G.begin() + 1, G.end());\n  ntt.ntt(F,\
    \ 0), ntt.ntt(G, 0);\n  for(int i = 0; i < ssize(F); i++)\n    F[i] *= G[i];\n\
    \  ntt.ntt(F, 1);\n  F.back() = 0;\n  ranges::rotate(F, prev(F.end()));\n  F.resize(n\
    \ + 1);\n  for(int i = 0; i <= n; i++)\n    F[i] *= factorial_inv<Mint>(i);\n\
    \  F = Taylor_shift<Mint>(F, -1);\n  F[0] += f0;\n\n  return F;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/prefix_polynomial.cpp
  requiredBy: []
  timestamp: '2026-09-03 22:17:13+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/prefix_sum_of_polynomial.test.cpp
documentation_of: poly/prefix_polynomial.cpp
layout: document
redirect_from:
- /library/poly/prefix_polynomial.cpp
- /library/poly/prefix_polynomial.cpp.html
title: poly/prefix_polynomial.cpp
---
