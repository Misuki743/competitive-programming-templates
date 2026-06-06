---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/bernoulli_number.test.cpp
    title: test/bernoulli_number.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"combi/bernoulli_number.cpp\"\n//#include<modint/MontgomeryModInt.cpp>\n\
    //#include<poly/NTTmint.cpp>\n//#include<poly/FPS.cpp>\n\ntemplate<class Mint>\n\
    FPS<Mint> bernoulli_number(int n) {\n  fps fac(n + 2);\n  fac[0] = 1;\n  for(int\
    \ i = 1; i <= n + 1; i++)\n    fac[i] = fac[i - 1] * i;\n  fps f(n + 2);\n  f[n\
    \ + 1] = Mint(1) / fac[n + 1];\n  for(int i = n; i > 0; i--)\n    f[i] = f[i +\
    \ 1] * (i + 1);\n  f.erase(f.begin());\n  f = f.inv(n + 1);\n  for(int i = 0;\
    \ i <= n; i++)\n    f[i] *= fac[i];\n  return f;\n}\n"
  code: "//#include<modint/MontgomeryModInt.cpp>\n//#include<poly/NTTmint.cpp>\n//#include<poly/FPS.cpp>\n\
    \ntemplate<class Mint>\nFPS<Mint> bernoulli_number(int n) {\n  fps fac(n + 2);\n\
    \  fac[0] = 1;\n  for(int i = 1; i <= n + 1; i++)\n    fac[i] = fac[i - 1] * i;\n\
    \  fps f(n + 2);\n  f[n + 1] = Mint(1) / fac[n + 1];\n  for(int i = n; i > 0;\
    \ i--)\n    f[i] = f[i + 1] * (i + 1);\n  f.erase(f.begin());\n  f = f.inv(n +\
    \ 1);\n  for(int i = 0; i <= n; i++)\n    f[i] *= fac[i];\n  return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/bernoulli_number.cpp
  requiredBy: []
  timestamp: '2026-06-06 23:34:13+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/bernoulli_number.test.cpp
documentation_of: combi/bernoulli_number.cpp
layout: document
redirect_from:
- /library/combi/bernoulli_number.cpp
- /library/combi/bernoulli_number.cpp.html
title: combi/bernoulli_number.cpp
---
