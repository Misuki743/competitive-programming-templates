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
  bundledCode: "#line 1 \"poly/composite.cpp\"\n//7sec on N = 2^17\ntemplate<class\
    \ Mint>\nvc<FPS<Mint>> inner(FPS<Mint> g, vc<FPS<Mint>> Q, int n, int k) {\n \
    \ if (n == 0) {\n    FPS<Mint> h = g * Q[0].inv(ssize(Q[0])).rev();\n    vc<FPS<Mint>>\
    \ P(n + 1, FPS<Mint>(k + 1));\n    for(int i = 0; i < ssize(g); i++)\n      P[0][i]\
    \ = h[i + ssize(Q[0]) - 1];\n    return P;\n  }\n  auto R = Q;\n  for(int i =\
    \ 1; i <= n; i += 2)\n    for(mint &x : R[i])\n      x = -x;\n  auto T = convolution_2d(Q,\
    \ R);\n  vc V(n / 2 + 1, FPS<Mint>(k * 2 + 1));\n  for(int i = 0; i <= n / 2;\
    \ i++) V[i] = T[i * 2];\n  auto U = inner(g, V, n / 2, k * 2);\n  vc S(n * 2 +\
    \ 1, FPS<Mint>(k * 2 + 1));\n  for(int i = 0; i <= n / 2; i++) S[i * 2 + n % 2]\
    \ = U[i];\n  vc revR(n + 1, FPS<Mint>(k + 1));\n  for(int i = 0; i <= n; i++)\
    \ revR[i] = R[n - i].rev();\n  auto Pshift = convolution_2d(S, revR);\n  vc P(n\
    \ + 1, FPS<Mint>(k + 1));\n  for(int i = 0; i <= n; i++)\n    for(int j = 0; j\
    \ <= k; j++)\n      P[i][j] = Pshift[i + n][j + k];\n  return P;\n}\n\n//calculate\
    \ g(f(x)) mod x^{n + 1}, assume [x^0]f(x) = 0.\ntemplate<class Mint>\nFPS<Mint>\
    \ composite(FPS<Mint> f, FPS<Mint> g) {\n  assert(ssize(f) == ssize(g));\n  int\
    \ n = ssize(f) - 1, k = 1;\n  vc Q(n + 1, FPS<Mint>(k + 1));\n  Q[0][0] = 1;\n\
    \  for(int i = 0; i < n + 1; i++) Q[i][1] = -f[i];\n  auto P = inner(g, Q, n,\
    \ k);\n  FPS<Mint> h(n + 1);\n  for(int i = 0; i <= n; i++) h[i] = P[i][0];\n\
    \  return h.rev();\n}\n"
  code: "//7sec on N = 2^17\ntemplate<class Mint>\nvc<FPS<Mint>> inner(FPS<Mint> g,\
    \ vc<FPS<Mint>> Q, int n, int k) {\n  if (n == 0) {\n    FPS<Mint> h = g * Q[0].inv(ssize(Q[0])).rev();\n\
    \    vc<FPS<Mint>> P(n + 1, FPS<Mint>(k + 1));\n    for(int i = 0; i < ssize(g);\
    \ i++)\n      P[0][i] = h[i + ssize(Q[0]) - 1];\n    return P;\n  }\n  auto R\
    \ = Q;\n  for(int i = 1; i <= n; i += 2)\n    for(mint &x : R[i])\n      x = -x;\n\
    \  auto T = convolution_2d(Q, R);\n  vc V(n / 2 + 1, FPS<Mint>(k * 2 + 1));\n\
    \  for(int i = 0; i <= n / 2; i++) V[i] = T[i * 2];\n  auto U = inner(g, V, n\
    \ / 2, k * 2);\n  vc S(n * 2 + 1, FPS<Mint>(k * 2 + 1));\n  for(int i = 0; i <=\
    \ n / 2; i++) S[i * 2 + n % 2] = U[i];\n  vc revR(n + 1, FPS<Mint>(k + 1));\n\
    \  for(int i = 0; i <= n; i++) revR[i] = R[n - i].rev();\n  auto Pshift = convolution_2d(S,\
    \ revR);\n  vc P(n + 1, FPS<Mint>(k + 1));\n  for(int i = 0; i <= n; i++)\n  \
    \  for(int j = 0; j <= k; j++)\n      P[i][j] = Pshift[i + n][j + k];\n  return\
    \ P;\n}\n\n//calculate g(f(x)) mod x^{n + 1}, assume [x^0]f(x) = 0.\ntemplate<class\
    \ Mint>\nFPS<Mint> composite(FPS<Mint> f, FPS<Mint> g) {\n  assert(ssize(f) ==\
    \ ssize(g));\n  int n = ssize(f) - 1, k = 1;\n  vc Q(n + 1, FPS<Mint>(k + 1));\n\
    \  Q[0][0] = 1;\n  for(int i = 0; i < n + 1; i++) Q[i][1] = -f[i];\n  auto P =\
    \ inner(g, Q, n, k);\n  FPS<Mint> h(n + 1);\n  for(int i = 0; i <= n; i++) h[i]\
    \ = P[i][0];\n  return h.rev();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/composite.cpp
  requiredBy: []
  timestamp: '2026-03-22 16:32:23+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/composite.cpp
layout: document
redirect_from:
- /library/poly/composite.cpp
- /library/poly/composite.cpp.html
title: poly/composite.cpp
---
