---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest_phi_vec.test.cpp
    title: test/mytest_phi_vec.test.cpp
  - icon: ':x:'
    path: test/sum_of_totient_function.test.cpp
    title: test/sum_of_totient_function.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/phi_vec.cpp\"\ntemplate<class T>\nvc<T> phi_vec(int\
    \ n) {\n  vc<T> phi(n);\n  if (n > 1) phi[1] = 1;\n  for(int i = 2; i < n; i++)\
    \ {\n    int MPF = mpf(i);\n    phi[i] = phi[i / MPF] * (MPF - (MPF != mpf(i /\
    \ MPF)));\n  }\n  return phi;\n}\n"
  code: "template<class T>\nvc<T> phi_vec(int n) {\n  vc<T> phi(n);\n  if (n > 1)\
    \ phi[1] = 1;\n  for(int i = 2; i < n; i++) {\n    int MPF = mpf(i);\n    phi[i]\
    \ = phi[i / MPF] * (MPF - (MPF != mpf(i / MPF)));\n  }\n  return phi;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/phi_vec.cpp
  requiredBy: []
  timestamp: '2026-09-03 11:26:39+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest_phi_vec.test.cpp
  - test/sum_of_totient_function.test.cpp
documentation_of: numtheory/phi_vec.cpp
layout: document
redirect_from:
- /library/numtheory/phi_vec.cpp
- /library/numtheory/phi_vec.cpp.html
title: numtheory/phi_vec.cpp
---
