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
  bundledCode: "#line 1 \"poly/convolution_2d.cpp\"\ntemplate<class Mint>\nvc<FPS<Mint>>\
    \ convolution_2d(vc<FPS<Mint>> f, vc<FPS<Mint>> g) {\n  int n1 = size(f), m1 =\
    \ size(f[0]), n2 = size(g), m2 = size(g[0]);\n\n  int n = n1 + n2 - 1, m = m1\
    \ + m2 - 1;\n  auto flatten = [n, m](vc<FPS<Mint>> &f) {\n    FPS<Mint> g(n *\
    \ m);\n    for(int i = 0; i < ssize(f); i++)\n      for(int j = 0; j < ssize(f[i]);\
    \ j++)\n        g[i * m + j] = f[i][j];\n    return g;\n  };\n\n  auto hp = flatten(f)\
    \ * flatten(g);\n  vc h(n, FPS<Mint>(m));\n  for(int i = 0; i < n; i++)\n    for(int\
    \ j = 0; j < m; j++)\n      h[i][j] = hp[i * m + j];\n\n  return h;\n}\n"
  code: "template<class Mint>\nvc<FPS<Mint>> convolution_2d(vc<FPS<Mint>> f, vc<FPS<Mint>>\
    \ g) {\n  int n1 = size(f), m1 = size(f[0]), n2 = size(g), m2 = size(g[0]);\n\n\
    \  int n = n1 + n2 - 1, m = m1 + m2 - 1;\n  auto flatten = [n, m](vc<FPS<Mint>>\
    \ &f) {\n    FPS<Mint> g(n * m);\n    for(int i = 0; i < ssize(f); i++)\n    \
    \  for(int j = 0; j < ssize(f[i]); j++)\n        g[i * m + j] = f[i][j];\n   \
    \ return g;\n  };\n\n  auto hp = flatten(f) * flatten(g);\n  vc h(n, FPS<Mint>(m));\n\
    \  for(int i = 0; i < n; i++)\n    for(int j = 0; j < m; j++)\n      h[i][j] =\
    \ hp[i * m + j];\n\n  return h;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/convolution_2d.cpp
  requiredBy: []
  timestamp: '2026-03-22 16:32:23+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/convolution_2d.cpp
layout: document
redirect_from:
- /library/poly/convolution_2d.cpp
- /library/poly/convolution_2d.cpp.html
title: poly/convolution_2d.cpp
---
