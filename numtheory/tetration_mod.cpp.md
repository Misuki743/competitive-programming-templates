---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tetration_mod.test.cpp
    title: test/tetration_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/tetration_mod.cpp\"\nll phi(ll n) {\n  auto pf\
    \ = factor(n);\n  unique(pf);\n  for(ll p : pf)\n    n -= n / p;\n  return n;\n\
    }\n\nll tetration(ll a, ll b, ll m) {\n  static const ll a2[] = {1, 2, 4, 16,\
    \ 1 << 16};\n\n  if (m == 1) return 0;\n  if (b == 0) return 1;\n  if (b == 1)\
    \ return a % m;\n  if (b == 2) return modpow(a, a, m);\n  if (a == 0) return ~b\
    \ & 1;\n  if (a == 1) return 1;\n  if (a == 2 and b < 5) return a2[b] % m;\n\n\
    \  if (gcd(a, m) == 1) return modpow(a, tetration(a, b - 1, phi(m)), m);\n\n \
    \ ll g = 1, x;\n  while((x = gcd(g * a, m)) != g) g = x;\n\n  return modpow(a,\
    \ tetration(a, b - 1, phi(m / g)), m / g) * inv(g, m / g) % (m / g) * g;\n}\n"
  code: "ll phi(ll n) {\n  auto pf = factor(n);\n  unique(pf);\n  for(ll p : pf)\n\
    \    n -= n / p;\n  return n;\n}\n\nll tetration(ll a, ll b, ll m) {\n  static\
    \ const ll a2[] = {1, 2, 4, 16, 1 << 16};\n\n  if (m == 1) return 0;\n  if (b\
    \ == 0) return 1;\n  if (b == 1) return a % m;\n  if (b == 2) return modpow(a,\
    \ a, m);\n  if (a == 0) return ~b & 1;\n  if (a == 1) return 1;\n  if (a == 2\
    \ and b < 5) return a2[b] % m;\n\n  if (gcd(a, m) == 1) return modpow(a, tetration(a,\
    \ b - 1, phi(m)), m);\n\n  ll g = 1, x;\n  while((x = gcd(g * a, m)) != g) g =\
    \ x;\n\n  return modpow(a, tetration(a, b - 1, phi(m / g)), m / g) * inv(g, m\
    \ / g) % (m / g) * g;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/tetration_mod.cpp
  requiredBy: []
  timestamp: '2026-09-02 17:47:14+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tetration_mod.test.cpp
documentation_of: numtheory/tetration_mod.cpp
layout: document
redirect_from:
- /library/numtheory/tetration_mod.cpp
- /library/numtheory/tetration_mod.cpp.html
title: numtheory/tetration_mod.cpp
---
