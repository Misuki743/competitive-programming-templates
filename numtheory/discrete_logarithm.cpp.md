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
  bundledCode: "#line 1 \"numtheory/discrete_logarithm.cpp\"\n//#include \"ds/hash_table\"\
    \n//#include \"numtheory/exgcd\"\n\nll discrete_logarithm(ll x, ll y, ll m) {\n\
    \  x %= m, y %= m;\n\n  if (gcd(x, m) != 1) {\n    int C = bit_width((ull)m);\n\
    \    ll prod = 1;\n    for(int i = 0; i < C; i++) {\n      if (prod == y) return\
    \ i;\n      (prod *= x) %= m;\n    }\n    ll g = gcd(prod, m);\n    if (y % g\
    \ != 0) return -1;\n    ll ans = discrete_logarithm(x, y / g * inv(prod / g, m\
    \ / g) % (m / g), m / g);\n    if (ans == -1) return -1;\n    else return ans\
    \ + C;\n  }\n\n  ll B = sqrtl(m);\n  while(B * B < m) B++;\n\n#ifdef DEBUG\n \
    \ hash_table t;\n#else\n  hash_table t({}, {}, {}, {}, {bit_ceil((ull)(B + 1))});\n\
    #endif\n\n  ll I = inv(x, m);\n  for(ll i = B, prod = binpow(x, B); i >= 0; i--,\
    \ (prod *= I) %= m)\n    t[prod] = i;\n\n  ll J = binpow(I, B);\n  for(ll i =\
    \ 0, prod = y; i < B; i++, (prod *= J) %= m)\n    if (auto ite = t.find(prod);\
    \ ite != t.end())\n      return i * B + ite -> second;\n  return -1;\n}\n"
  code: "//#include \"ds/hash_table\"\n//#include \"numtheory/exgcd\"\n\nll discrete_logarithm(ll\
    \ x, ll y, ll m) {\n  x %= m, y %= m;\n\n  if (gcd(x, m) != 1) {\n    int C =\
    \ bit_width((ull)m);\n    ll prod = 1;\n    for(int i = 0; i < C; i++) {\n   \
    \   if (prod == y) return i;\n      (prod *= x) %= m;\n    }\n    ll g = gcd(prod,\
    \ m);\n    if (y % g != 0) return -1;\n    ll ans = discrete_logarithm(x, y /\
    \ g * inv(prod / g, m / g) % (m / g), m / g);\n    if (ans == -1) return -1;\n\
    \    else return ans + C;\n  }\n\n  ll B = sqrtl(m);\n  while(B * B < m) B++;\n\
    \n#ifdef DEBUG\n  hash_table t;\n#else\n  hash_table t({}, {}, {}, {}, {bit_ceil((ull)(B\
    \ + 1))});\n#endif\n\n  ll I = inv(x, m);\n  for(ll i = B, prod = binpow(x, B);\
    \ i >= 0; i--, (prod *= I) %= m)\n    t[prod] = i;\n\n  ll J = binpow(I, B);\n\
    \  for(ll i = 0, prod = y; i < B; i++, (prod *= J) %= m)\n    if (auto ite = t.find(prod);\
    \ ite != t.end())\n      return i * B + ite -> second;\n  return -1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/discrete_logarithm.cpp
  requiredBy: []
  timestamp: '2026-09-02 17:05:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numtheory/discrete_logarithm.cpp
layout: document
redirect_from:
- /library/numtheory/discrete_logarithm.cpp
- /library/numtheory/discrete_logarithm.cpp.html
title: numtheory/discrete_logarithm.cpp
---
