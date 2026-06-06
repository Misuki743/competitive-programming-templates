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
  bundledCode: "#line 1 \"poly/compositional_inverse.cpp\"\n//#include \"modint/MontgomeryModInt.cpp\"\
    \n//#include \"poly/NTTmint.cpp\"\n//#include \"poly/FPS.cpp\"\n//#include \"\
    poly/kthTermOfPowers.cpp\"\n\ntemplate<class Mint>\nFPS<Mint> compositional_inverse(FPS<Mint>\
    \ f, int k) {\n  assert(ssize(f) >= 2 and f[0] == 0 and f[1] != 0);\n  mint c\
    \ = f[1];\n  mint invc = 1 / c;\n  for(mint &x : f)\n    x *= invc;\n  k -= 1;\n\
    \  f = kthTermOfPowers(k, k + 1, f);\n  for(int i = 1; i <= k; i++)\n    f[i]\
    \ *= mint(k) / i;\n  ranges::reverse(f);\n  f = f.log(k + 1);\n  mint inv = 1\
    \ / mint(-k);\n  for(mint &x : f) x *= inv;\n  f = f.exp(k + 1);\n  f.insert(f.begin(),\
    \ Mint(0));\n  f.pop_back();\n  for(mint buf = 1; mint &x : f)\n    x *= buf,\
    \ buf *= invc;\n  return f;\n}\n"
  code: "//#include \"modint/MontgomeryModInt.cpp\"\n//#include \"poly/NTTmint.cpp\"\
    \n//#include \"poly/FPS.cpp\"\n//#include \"poly/kthTermOfPowers.cpp\"\n\ntemplate<class\
    \ Mint>\nFPS<Mint> compositional_inverse(FPS<Mint> f, int k) {\n  assert(ssize(f)\
    \ >= 2 and f[0] == 0 and f[1] != 0);\n  mint c = f[1];\n  mint invc = 1 / c;\n\
    \  for(mint &x : f)\n    x *= invc;\n  k -= 1;\n  f = kthTermOfPowers(k, k + 1,\
    \ f);\n  for(int i = 1; i <= k; i++)\n    f[i] *= mint(k) / i;\n  ranges::reverse(f);\n\
    \  f = f.log(k + 1);\n  mint inv = 1 / mint(-k);\n  for(mint &x : f) x *= inv;\n\
    \  f = f.exp(k + 1);\n  f.insert(f.begin(), Mint(0));\n  f.pop_back();\n  for(mint\
    \ buf = 1; mint &x : f)\n    x *= buf, buf *= invc;\n  return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/compositional_inverse.cpp
  requiredBy: []
  timestamp: '2026-06-06 23:34:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/compositional_inverse.cpp
layout: document
redirect_from:
- /library/poly/compositional_inverse.cpp
- /library/poly/compositional_inverse.cpp.html
title: poly/compositional_inverse.cpp
---
