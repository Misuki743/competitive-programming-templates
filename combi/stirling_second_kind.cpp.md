---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/stirling_number_of_the_second_kind.test.cpp
    title: test/stirling_number_of_the_second_kind.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"combi/stirling_second_kind.cpp\"\n//#include \"modint/MontgomeryModInt.cpp\"\
    \n//#include \"poly/NTTmint.cpp\"\n//#include \"poly/FPS.cpp\"\n//#include \"\
    combi/binom.cpp\"\n\ntemplate<class Mint>\nFPS<Mint> stirling_second_kind(int\
    \ n) {\n  binomial<Mint> bn(n + 1);\n  FPS<Mint> f(n + 1), g(n + 1);\n  for(int\
    \ i = 0; i <= n; i++) {\n    f[i] = bn.faci(i) * (i % 2 == 1 ? -1 : 1);\n    g[i]\
    \ = bn.faci(i) * mint(i).pow(n);\n  }\n  auto h = f * g;\n  h.resize(n + 1);\n\
    \  return h;\n}\n"
  code: "//#include \"modint/MontgomeryModInt.cpp\"\n//#include \"poly/NTTmint.cpp\"\
    \n//#include \"poly/FPS.cpp\"\n//#include \"combi/binom.cpp\"\n\ntemplate<class\
    \ Mint>\nFPS<Mint> stirling_second_kind(int n) {\n  binomial<Mint> bn(n + 1);\n\
    \  FPS<Mint> f(n + 1), g(n + 1);\n  for(int i = 0; i <= n; i++) {\n    f[i] =\
    \ bn.faci(i) * (i % 2 == 1 ? -1 : 1);\n    g[i] = bn.faci(i) * mint(i).pow(n);\n\
    \  }\n  auto h = f * g;\n  h.resize(n + 1);\n  return h;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/stirling_second_kind.cpp
  requiredBy: []
  timestamp: '2026-06-06 23:34:13+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/stirling_number_of_the_second_kind.test.cpp
documentation_of: combi/stirling_second_kind.cpp
layout: document
redirect_from:
- /library/combi/stirling_second_kind.cpp
- /library/combi/stirling_second_kind.cpp.html
title: combi/stirling_second_kind.cpp
---
