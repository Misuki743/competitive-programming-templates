---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest_mu_vec.test.cpp
    title: test/mytest_mu_vec.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/mu_vec.cpp\"\ntemplate<class T>\nvc<T> mu_vec(int\
    \ n) {\n  vc<T> mu(n);\n  if (n > 1) mu[1] = 1;\n  for(int i = 2; i < n; i++)\
    \ {\n    int MPF = mpf(i);\n    mu[i] = MPF == mpf(i / MPF) ? T(0) : -mu[i / MPF];\n\
    \  }\n  return mu;\n}\n"
  code: "template<class T>\nvc<T> mu_vec(int n) {\n  vc<T> mu(n);\n  if (n > 1) mu[1]\
    \ = 1;\n  for(int i = 2; i < n; i++) {\n    int MPF = mpf(i);\n    mu[i] = MPF\
    \ == mpf(i / MPF) ? T(0) : -mu[i / MPF];\n  }\n  return mu;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/mu_vec.cpp
  requiredBy: []
  timestamp: '2026-09-03 11:05:21+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest_mu_vec.test.cpp
documentation_of: numtheory/mu_vec.cpp
layout: document
redirect_from:
- /library/numtheory/mu_vec.cpp
- /library/numtheory/mu_vec.cpp.html
title: numtheory/mu_vec.cpp
---
