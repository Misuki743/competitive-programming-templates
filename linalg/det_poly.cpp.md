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
  bundledCode: "#line 1 \"linalg/det_poly.cpp\"\n//compute det(M0 + M1x) with N/MOD\
    \ probability to fail\ntemplate<class Mint>\nauto det_poly(matrix<Mint> M0, matrix<Mint>\
    \ M1) {\n  const int N = ssize(M0);\n  assert(N > 0 and ssize(M1) == N and ssize(M0[0])\
    \ == N and ssize(M1[0]) == N);\n\n  mt19937_64 rng(clock);\n\n  Mint a = rng()\
    \ % Mint::get_mod();\n  for(int i = 0; i < N; i++)\n    for(int j = 0; j < N;\
    \ j++)\n      M0[i][j] += a * M1[i][j];\n  swap(M0, M1);\n\n  auto [ok, M1I] =\
    \ M1.inv();\n  if (!ok) return pair(false, vc<Mint>(N + 1, 0));\n\n  auto p =\
    \ characteristic_polynomial(-M1I * M0);\n  Mint inv_det = M1I.det().inverse();\n\
    \  for(Mint &x : p) x *= inv_det;\n\n  vc<Mint> q(N + 1);\n  for(int i = 0; i\
    \ < ssize(p); i++)\n    q[N - i] = p[i];\n\n  binomial<Mint> bn(N + 1);\n\n  vc<Mint>\
    \ r(N + 1);\n  for(int i = 0; i < ssize(q); i++) {\n    Mint mul = 1;\n    for(int\
    \ j = 0; j <= i; j++, mul *= -a)\n      r[i - j] += q[i] * mul * bn.binom(i, j);\n\
    \  }\n\n  return pair(true, r);\n}\n"
  code: "//compute det(M0 + M1x) with N/MOD probability to fail\ntemplate<class Mint>\n\
    auto det_poly(matrix<Mint> M0, matrix<Mint> M1) {\n  const int N = ssize(M0);\n\
    \  assert(N > 0 and ssize(M1) == N and ssize(M0[0]) == N and ssize(M1[0]) == N);\n\
    \n  mt19937_64 rng(clock);\n\n  Mint a = rng() % Mint::get_mod();\n  for(int i\
    \ = 0; i < N; i++)\n    for(int j = 0; j < N; j++)\n      M0[i][j] += a * M1[i][j];\n\
    \  swap(M0, M1);\n\n  auto [ok, M1I] = M1.inv();\n  if (!ok) return pair(false,\
    \ vc<Mint>(N + 1, 0));\n\n  auto p = characteristic_polynomial(-M1I * M0);\n \
    \ Mint inv_det = M1I.det().inverse();\n  for(Mint &x : p) x *= inv_det;\n\n  vc<Mint>\
    \ q(N + 1);\n  for(int i = 0; i < ssize(p); i++)\n    q[N - i] = p[i];\n\n  binomial<Mint>\
    \ bn(N + 1);\n\n  vc<Mint> r(N + 1);\n  for(int i = 0; i < ssize(q); i++) {\n\
    \    Mint mul = 1;\n    for(int j = 0; j <= i; j++, mul *= -a)\n      r[i - j]\
    \ += q[i] * mul * bn.binom(i, j);\n  }\n\n  return pair(true, r);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/det_poly.cpp
  requiredBy: []
  timestamp: '2026-03-22 16:32:23+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/det_poly.cpp
layout: document
redirect_from:
- /library/linalg/det_poly.cpp
- /library/linalg/det_poly.cpp.html
title: linalg/det_poly.cpp
---
