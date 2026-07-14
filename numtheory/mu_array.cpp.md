---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest_mu_array.test.cpp
    title: test/mytest_mu_array.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/mu_array.cpp\"\ntemplate<class T, int32_t C>\n\
    array<T, C> mu_array() {\n  array<T, C> mu = {};\n  if (C > 1) mu[1] = T(1);\n\
    \  auto &mpf = linear_sieve<C>::mpf_array();\n  for(int i = 2; i < C; i++)\n \
    \   mu[i] = (mpf[i] == mpf[i / mpf[i]] ? T(0) : -mu[i / mpf[i]]);\n  return mu;\n\
    }\n"
  code: "template<class T, int32_t C>\narray<T, C> mu_array() {\n  array<T, C> mu\
    \ = {};\n  if (C > 1) mu[1] = T(1);\n  auto &mpf = linear_sieve<C>::mpf_array();\n\
    \  for(int i = 2; i < C; i++)\n    mu[i] = (mpf[i] == mpf[i / mpf[i]] ? T(0) :\
    \ -mu[i / mpf[i]]);\n  return mu;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/mu_array.cpp
  requiredBy: []
  timestamp: '2026-07-15 01:05:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest_mu_array.test.cpp
documentation_of: numtheory/mu_array.cpp
layout: document
redirect_from:
- /library/numtheory/mu_array.cpp
- /library/numtheory/mu_array.cpp.html
title: numtheory/mu_array.cpp
---
