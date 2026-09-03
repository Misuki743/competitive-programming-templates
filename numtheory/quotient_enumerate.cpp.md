---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/enumerate_quotients.test.cpp
    title: test/enumerate_quotients.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/quotient_enumerate.cpp\"\ntemplate<typename F>\n\
    void quotient_floor_enumerate(ll n, F f) {\n  ll x = sqrtl(n);\n  while(x * (x\
    \ + 1) <= n) x++;\n  ll m = n / x;\n  for(ll i = 1; i < x; i++) {\n    ll q =\
    \ n / i;\n    f(q, n / (q + 1) + 1, n / q + 1);\n  }\n  for(ll q = m; q >= 1;\
    \ q--)\n    f(q, n / (q + 1) + 1, n / q + 1);\n}\n\ntemplate<typename F>\nvoid\
    \ quotient_ceil_enumerate(ll n, F f) {\n  ll x = sqrtl(n);\n  while(x * (x + 1)\
    \ <= n) x++;\n  ll m = (n + x - 1) / x;\n  for(ll i = 1; i < x; i++) {\n    ll\
    \ q = (n + i - 1) / i;\n    f(q, (n + q - 1) / q, (n + q - 2) / (q - 1));\n  }\n\
    \  for(ll q = m; q >= 2; q--)\n    f(q, (n + q - 1) / q, (n + q - 2) / (q - 1));\n\
    \  f(1, n, n + 1);\n}\n"
  code: "template<typename F>\nvoid quotient_floor_enumerate(ll n, F f) {\n  ll x\
    \ = sqrtl(n);\n  while(x * (x + 1) <= n) x++;\n  ll m = n / x;\n  for(ll i = 1;\
    \ i < x; i++) {\n    ll q = n / i;\n    f(q, n / (q + 1) + 1, n / q + 1);\n  }\n\
    \  for(ll q = m; q >= 1; q--)\n    f(q, n / (q + 1) + 1, n / q + 1);\n}\n\ntemplate<typename\
    \ F>\nvoid quotient_ceil_enumerate(ll n, F f) {\n  ll x = sqrtl(n);\n  while(x\
    \ * (x + 1) <= n) x++;\n  ll m = (n + x - 1) / x;\n  for(ll i = 1; i < x; i++)\
    \ {\n    ll q = (n + i - 1) / i;\n    f(q, (n + q - 1) / q, (n + q - 2) / (q -\
    \ 1));\n  }\n  for(ll q = m; q >= 2; q--)\n    f(q, (n + q - 1) / q, (n + q -\
    \ 2) / (q - 1));\n  f(1, n, n + 1);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/quotient_enumerate.cpp
  requiredBy: []
  timestamp: '2026-05-26 04:21:07+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/enumerate_quotients.test.cpp
documentation_of: numtheory/quotient_enumerate.cpp
layout: document
redirect_from:
- /library/numtheory/quotient_enumerate.cpp
- /library/numtheory/quotient_enumerate.cpp.html
title: numtheory/quotient_enumerate.cpp
---
