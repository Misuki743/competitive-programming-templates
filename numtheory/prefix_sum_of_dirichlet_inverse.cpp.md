---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/sum_of_totient_function.test.cpp
    title: test/sum_of_totient_function.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/prefix_sum_of_dirichlet_inverse.cpp\"\n//f * g\
    \ = h, G(x), H(x) can be computed fast, find F(N)\ntemplate<class T, typename\
    \ F1, typename F2, typename F3 = void*>\nrequires R_invocable<T, F1, ll> && R_invocable<T,\
    \ F2, ll>\nvc<T> prefix_sum_of_dirichlet_inverse(ll N, F1 G, F2 H, F3 F_lazy =\
    \ (void*)0) {\n  ll x = sqrtl(N);\n  while(x * (x + 1) <= N) x++;\n  ll m = N\
    \ / x;\n\n  vll qs;\n  qs.reserve(m + x - 1);\n  for(ll i = 1; i < m; i++) qs.eb(i);\n\
    \  for(ll i = x; i >= 1; i--) qs.eb(N / i);\n  auto id = [&](ll n) { return n\
    \ <= m ? n - 1 : ssize(qs) - (N / n); };\n\n  vc<T> F(m + x - 1);\n\n  T G1_inv;\n\
    \  if constexpr (!is_integral_v<T>) G1_inv = G(1).inverse();\n\n  for(ll i = 0;\
    \ i < ssize(qs); i++) {\n    ll Q = qs[i];\n\n    if constexpr (!same_as<F3, void*>)\
    \ {\n      if (Q < ssize(F_lazy)) {\n        F[i] = F_lazy[Q];\n        continue;\n\
    \      }\n    }\n\n    F[i] = H(Q);\n    ll x2 = sqrtl(Q);\n    while(x2 * (x2\
    \ + 1) <= Q) x2++;\n    ll m2 = Q / x2;\n    for(ll j = 1; j < m2; j++)\n    \
    \  F[i] -= F[id(j)] * (G(Q / j) - G(Q / (j + 1)));\n    for(ll j = x2; j > 1;\
    \ j--)\n      F[i] -= F[id(Q / j)] * (G(Q / (Q / j)) - G(Q / (Q / j + 1)));\n\n\
    \    if constexpr (is_integral_v<T>) F[i] /= G(1);\n    else F[i] *= G1_inv;\n\
    \  }\n\n  return F;\n}\n"
  code: "//f * g = h, G(x), H(x) can be computed fast, find F(N)\ntemplate<class T,\
    \ typename F1, typename F2, typename F3 = void*>\nrequires R_invocable<T, F1,\
    \ ll> && R_invocable<T, F2, ll>\nvc<T> prefix_sum_of_dirichlet_inverse(ll N, F1\
    \ G, F2 H, F3 F_lazy = (void*)0) {\n  ll x = sqrtl(N);\n  while(x * (x + 1) <=\
    \ N) x++;\n  ll m = N / x;\n\n  vll qs;\n  qs.reserve(m + x - 1);\n  for(ll i\
    \ = 1; i < m; i++) qs.eb(i);\n  for(ll i = x; i >= 1; i--) qs.eb(N / i);\n  auto\
    \ id = [&](ll n) { return n <= m ? n - 1 : ssize(qs) - (N / n); };\n\n  vc<T>\
    \ F(m + x - 1);\n\n  T G1_inv;\n  if constexpr (!is_integral_v<T>) G1_inv = G(1).inverse();\n\
    \n  for(ll i = 0; i < ssize(qs); i++) {\n    ll Q = qs[i];\n\n    if constexpr\
    \ (!same_as<F3, void*>) {\n      if (Q < ssize(F_lazy)) {\n        F[i] = F_lazy[Q];\n\
    \        continue;\n      }\n    }\n\n    F[i] = H(Q);\n    ll x2 = sqrtl(Q);\n\
    \    while(x2 * (x2 + 1) <= Q) x2++;\n    ll m2 = Q / x2;\n    for(ll j = 1; j\
    \ < m2; j++)\n      F[i] -= F[id(j)] * (G(Q / j) - G(Q / (j + 1)));\n    for(ll\
    \ j = x2; j > 1; j--)\n      F[i] -= F[id(Q / j)] * (G(Q / (Q / j)) - G(Q / (Q\
    \ / j + 1)));\n\n    if constexpr (is_integral_v<T>) F[i] /= G(1);\n    else F[i]\
    \ *= G1_inv;\n  }\n\n  return F;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/prefix_sum_of_dirichlet_inverse.cpp
  requiredBy: []
  timestamp: '2026-07-24 17:13:45+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/sum_of_totient_function.test.cpp
documentation_of: numtheory/prefix_sum_of_dirichlet_inverse.cpp
layout: document
redirect_from:
- /library/numtheory/prefix_sum_of_dirichlet_inverse.cpp
- /library/numtheory/prefix_sum_of_dirichlet_inverse.cpp.html
title: numtheory/prefix_sum_of_dirichlet_inverse.cpp
---
