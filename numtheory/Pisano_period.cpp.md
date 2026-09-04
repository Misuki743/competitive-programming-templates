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
  bundledCode: "#line 1 \"numtheory/Pisano_period.cpp\"\nint Pisano_period(int p)\
    \ {\n  if (p == 2) return 3;\n  if (p == 5) return 20;\n  mint::set_mod(p);\n\
    \  matrix<mint> M(2, 2);\n  M[0][0] = M[0][1] = M[1][0] = 1;\n\n  int period =\
    \ (p % 5 == 1 or p % 5 == 4) ? p - 1 : 2 * (p + 1);\n  factorize(period, [&](int\
    \ q, int) {\n    while(period % q == 0 and M.pow(period / q) == matrix<mint>::I(2))\n\
    \    period /= q;\n  });\n\n  return period;\n}\n"
  code: "int Pisano_period(int p) {\n  if (p == 2) return 3;\n  if (p == 5) return\
    \ 20;\n  mint::set_mod(p);\n  matrix<mint> M(2, 2);\n  M[0][0] = M[0][1] = M[1][0]\
    \ = 1;\n\n  int period = (p % 5 == 1 or p % 5 == 4) ? p - 1 : 2 * (p + 1);\n \
    \ factorize(period, [&](int q, int) {\n    while(period % q == 0 and M.pow(period\
    \ / q) == matrix<mint>::I(2))\n    period /= q;\n  });\n\n  return period;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/Pisano_period.cpp
  requiredBy: []
  timestamp: '2026-09-04 17:39:10+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numtheory/Pisano_period.cpp
layout: document
redirect_from:
- /library/numtheory/Pisano_period.cpp
- /library/numtheory/Pisano_period.cpp.html
title: numtheory/Pisano_period.cpp
---
