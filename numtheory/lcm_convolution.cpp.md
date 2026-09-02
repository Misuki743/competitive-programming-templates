---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lcm_convolution.test.cpp
    title: test/lcm_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/lcm_convolution.cpp\"\n//#include \"numtheory/linear_sieve.cpp\"\
    \n//#include \"numtheory/zeta_mobius_on_divisibility_lattice.cpp\"\n\ntemplate<class\
    \ T, int32_t C>\nvector<T> lcm_convolution(vector<T> a, vector<T> b) {\n  assert(ssize(a)\
    \ == ssize(b));\n  a = zeta_transform_on_divisor<T, C>(a);\n  b = zeta_transform_on_divisor<T,\
    \ C>(b);\n  for(int i = 0; i < ssize(a); i++)\n    a[i] *= b[i];\n  return mobius_transform_on_divisor<T,\
    \ C>(a);\n}\n"
  code: "//#include \"numtheory/linear_sieve.cpp\"\n//#include \"numtheory/zeta_mobius_on_divisibility_lattice.cpp\"\
    \n\ntemplate<class T, int32_t C>\nvector<T> lcm_convolution(vector<T> a, vector<T>\
    \ b) {\n  assert(ssize(a) == ssize(b));\n  a = zeta_transform_on_divisor<T, C>(a);\n\
    \  b = zeta_transform_on_divisor<T, C>(b);\n  for(int i = 0; i < ssize(a); i++)\n\
    \    a[i] *= b[i];\n  return mobius_transform_on_divisor<T, C>(a);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/lcm_convolution.cpp
  requiredBy: []
  timestamp: '2026-07-15 01:16:31+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lcm_convolution.test.cpp
documentation_of: numtheory/lcm_convolution.cpp
layout: document
redirect_from:
- /library/numtheory/lcm_convolution.cpp
- /library/numtheory/lcm_convolution.cpp.html
title: numtheory/lcm_convolution.cpp
---
