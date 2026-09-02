---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/counting_primes.test.cpp
    title: test/counting_primes.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/prime_counting.cpp\"\nll prime_counting(ll N)\
    \ {\n  ll x = sqrtl(N);\n  while(x * (x + 1) <= N) x++;\n  ll m = N / x;\n\n \
    \ vll qs;\n  qs.reserve(m + x - 1);\n  for(ll i = 1; i < m; i++) qs.eb(i);\n \
    \ for(ll i = x; i >= 1; i--) qs.eb(N / i);\n\n  auto id = [&](ll n) { return n\
    \ <= m ? n - 1 : m + x - 1 - N / n; };\n  vll dp = qs;\n  for(ll &y : dp) y--;\n\
    \n  for(ll p = 2; p * p <= N; p++) if (dp[p - 1] > dp[p - 2]) {\n    ll pi = dp[p\
    \ - 2];\n    for(ll i = m + x - 2; i >= 0 and qs[i] >= p * p; i--)\n      dp[i]\
    \ += pi - dp[id(qs[i] / p)];\n  }\n\n  return dp.back();\n}\n"
  code: "ll prime_counting(ll N) {\n  ll x = sqrtl(N);\n  while(x * (x + 1) <= N)\
    \ x++;\n  ll m = N / x;\n\n  vll qs;\n  qs.reserve(m + x - 1);\n  for(ll i = 1;\
    \ i < m; i++) qs.eb(i);\n  for(ll i = x; i >= 1; i--) qs.eb(N / i);\n\n  auto\
    \ id = [&](ll n) { return n <= m ? n - 1 : m + x - 1 - N / n; };\n  vll dp = qs;\n\
    \  for(ll &y : dp) y--;\n\n  for(ll p = 2; p * p <= N; p++) if (dp[p - 1] > dp[p\
    \ - 2]) {\n    ll pi = dp[p - 2];\n    for(ll i = m + x - 2; i >= 0 and qs[i]\
    \ >= p * p; i--)\n      dp[i] += pi - dp[id(qs[i] / p)];\n  }\n\n  return dp.back();\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/prime_counting.cpp
  requiredBy: []
  timestamp: '2026-07-26 01:44:55+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/counting_primes.test.cpp
documentation_of: numtheory/prime_counting.cpp
layout: document
redirect_from:
- /library/numtheory/prime_counting.cpp
- /library/numtheory/prime_counting.cpp.html
title: numtheory/prime_counting.cpp
---
