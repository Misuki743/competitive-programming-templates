---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/sum_of_multiplicative_function.test.cpp
    title: test/sum_of_multiplicative_function.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/Lucy_DP.cpp\"\n//Given a multiplicative function\
    \ f s.t.\n//- F(n), f(p^e) can be calculated quickly\n//- f(p) = f'(p) for all\
    \ p\n//\n//Return F'_p(n) for all n in Q_N\ntemplate<class T, typename F1, typename\
    \ F2>\nrequires R_invocable<T, F1, ll> && R_invocable<T, F2, ll, ll, ll>\nvc<T>\
    \ Lucy_DP(ll N, F1 F, F2 f) {\n  ll x = sqrtl(N);\n  while(x * (x + 1) <= N) x++;\n\
    \  ll m = N / x;\n\n  auto id = [&](ll n) { return n <= m ? n - 1 : m + x - 1\
    \ - N / n; };\n  vc<T> dp;\n  vll qs;\n  dp.reserve(m + x - 1), qs.reserve(m +\
    \ x - 1);\n  for(ll i = 1; i < m; i++) dp.eb(F(i)), qs.eb(i);\n  for(ll i = x;\
    \ i >= 1; i--) dp.eb(F(N / i)), qs.eb(N / i);\n\n  for(ll p = 2; p * p <= N; p++)\
    \ if (mpf(p) == p) {\n    for(ll i = m + x - 2; i >= 0 and qs[i] >= p * p; i--)\n\
    \      dp[i] += f(p, 1, p) * (dp[p - 2] - dp[id(qs[i] / p)]);\n    /* for the\
    \ case where f is not completely multiplicative (when would this be useful?)\n\
    \    ll i = m + x - 2;\n    while(i > 0 and qs[i - 1] >= p * p) i--;\n    for(;\
    \ i < m + x - 1; i++) {\n      for(ll q = p, e = 1; q * (ull)p <= qs[i]; q *=\
    \ p, e++) {\n        dp[i] -= f(p, e + 1, q * p);\n        dp[i] += f(p, e, q)\
    \ * (dp[p - 1] - dp[id(qs[i] / q)]);\n      }\n    }\n    */\n  }\n\n  return\
    \ dp;\n}\n\ntemplate<class T, typename F1>\nrequires R_invocable<T, F1, ll, ll,\
    \ ll> \nvc<T> inverse_Lucy_DP(ll N, vc<T> Fp, F1 f) {\n  ll x = sqrtl(N);\n  while(x\
    \ * (x + 1) <= N) x++;\n  ll m = N / x;\n\n  auto id = [&](ll n) { return n <=\
    \ m ? n - 1 : m + x - 1 - N / n; };\n  vll qs;\n  qs.reserve(m + x - 1);\n  for(ll\
    \ i = 1; i < m; i++) qs.eb(i);\n  for(ll i = x; i >= 1; i--) qs.eb(N / i);\n\n\
    \  for(ll p = m; p > 1; p--) if (mpf(p) == p) {\n    for(ll i = m + x - 2; i >=\
    \ 0 and qs[i] >= p * p; i--)\n      for(ll e = 1, q = p; q * (ull)p <= qs[i];\
    \ q *= p, e++)\n        Fp[i] += f(p, e, q) * (Fp[id(qs[i] / q)] - Fp[p - 1])\
    \ + f(p, e + 1, q * p);\n  }\n\n  return Fp;\n}\n"
  code: "//Given a multiplicative function f s.t.\n//- F(n), f(p^e) can be calculated\
    \ quickly\n//- f(p) = f'(p) for all p\n//\n//Return F'_p(n) for all n in Q_N\n\
    template<class T, typename F1, typename F2>\nrequires R_invocable<T, F1, ll> &&\
    \ R_invocable<T, F2, ll, ll, ll>\nvc<T> Lucy_DP(ll N, F1 F, F2 f) {\n  ll x =\
    \ sqrtl(N);\n  while(x * (x + 1) <= N) x++;\n  ll m = N / x;\n\n  auto id = [&](ll\
    \ n) { return n <= m ? n - 1 : m + x - 1 - N / n; };\n  vc<T> dp;\n  vll qs;\n\
    \  dp.reserve(m + x - 1), qs.reserve(m + x - 1);\n  for(ll i = 1; i < m; i++)\
    \ dp.eb(F(i)), qs.eb(i);\n  for(ll i = x; i >= 1; i--) dp.eb(F(N / i)), qs.eb(N\
    \ / i);\n\n  for(ll p = 2; p * p <= N; p++) if (mpf(p) == p) {\n    for(ll i =\
    \ m + x - 2; i >= 0 and qs[i] >= p * p; i--)\n      dp[i] += f(p, 1, p) * (dp[p\
    \ - 2] - dp[id(qs[i] / p)]);\n    /* for the case where f is not completely multiplicative\
    \ (when would this be useful?)\n    ll i = m + x - 2;\n    while(i > 0 and qs[i\
    \ - 1] >= p * p) i--;\n    for(; i < m + x - 1; i++) {\n      for(ll q = p, e\
    \ = 1; q * (ull)p <= qs[i]; q *= p, e++) {\n        dp[i] -= f(p, e + 1, q * p);\n\
    \        dp[i] += f(p, e, q) * (dp[p - 1] - dp[id(qs[i] / q)]);\n      }\n   \
    \ }\n    */\n  }\n\n  return dp;\n}\n\ntemplate<class T, typename F1>\nrequires\
    \ R_invocable<T, F1, ll, ll, ll> \nvc<T> inverse_Lucy_DP(ll N, vc<T> Fp, F1 f)\
    \ {\n  ll x = sqrtl(N);\n  while(x * (x + 1) <= N) x++;\n  ll m = N / x;\n\n \
    \ auto id = [&](ll n) { return n <= m ? n - 1 : m + x - 1 - N / n; };\n  vll qs;\n\
    \  qs.reserve(m + x - 1);\n  for(ll i = 1; i < m; i++) qs.eb(i);\n  for(ll i =\
    \ x; i >= 1; i--) qs.eb(N / i);\n\n  for(ll p = m; p > 1; p--) if (mpf(p) == p)\
    \ {\n    for(ll i = m + x - 2; i >= 0 and qs[i] >= p * p; i--)\n      for(ll e\
    \ = 1, q = p; q * (ull)p <= qs[i]; q *= p, e++)\n        Fp[i] += f(p, e, q) *\
    \ (Fp[id(qs[i] / q)] - Fp[p - 1]) + f(p, e + 1, q * p);\n  }\n\n  return Fp;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/Lucy_DP.cpp
  requiredBy: []
  timestamp: '2026-09-03 11:20:30+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/sum_of_multiplicative_function.test.cpp
documentation_of: numtheory/Lucy_DP.cpp
layout: document
redirect_from:
- /library/numtheory/Lucy_DP.cpp
- /library/numtheory/Lucy_DP.cpp.html
title: numtheory/Lucy_DP.cpp
---
