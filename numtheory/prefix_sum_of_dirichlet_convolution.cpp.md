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
  bundledCode: "#line 1 \"numtheory/prefix_sum_of_dirichlet_convolution.cpp\"\ntemplate<class\
    \ T, typename F1, typename F2>\nrequires R_invocable<T, F1, ll> && R_invocable<T,\
    \ F2, ll>\nT prefix_sum_of_dirichlet_convolution(ll N, F1 F, F2 G) {\n  ll x =\
    \ sqrtl(N);\n  while(x * (x + 1) <= N) x++;\n  ll m = N / x;\n\n  T Fp = 0, ans\
    \ = 0, tmp;\n  for(ll q = 1; q < m; q++) {\n    tmp = F(q);\n    ans += T(tmp\
    \ - Fp) * G(N / q);\n    Fp = tmp;\n  }\n  for(ll i = x; i >= 1; i--) {\n    tmp\
    \ = F(N / i);\n    ans += T(tmp - Fp) * G(N / (N / i));\n    Fp = tmp;\n  }\n\n\
    \  return ans;\n}\n"
  code: "template<class T, typename F1, typename F2>\nrequires R_invocable<T, F1,\
    \ ll> && R_invocable<T, F2, ll>\nT prefix_sum_of_dirichlet_convolution(ll N, F1\
    \ F, F2 G) {\n  ll x = sqrtl(N);\n  while(x * (x + 1) <= N) x++;\n  ll m = N /\
    \ x;\n\n  T Fp = 0, ans = 0, tmp;\n  for(ll q = 1; q < m; q++) {\n    tmp = F(q);\n\
    \    ans += T(tmp - Fp) * G(N / q);\n    Fp = tmp;\n  }\n  for(ll i = x; i >=\
    \ 1; i--) {\n    tmp = F(N / i);\n    ans += T(tmp - Fp) * G(N / (N / i));\n \
    \   Fp = tmp;\n  }\n\n  return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/prefix_sum_of_dirichlet_convolution.cpp
  requiredBy: []
  timestamp: '2026-07-24 22:33:41+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numtheory/prefix_sum_of_dirichlet_convolution.cpp
layout: document
redirect_from:
- /library/numtheory/prefix_sum_of_dirichlet_convolution.cpp
- /library/numtheory/prefix_sum_of_dirichlet_convolution.cpp.html
title: numtheory/prefix_sum_of_dirichlet_convolution.cpp
---
