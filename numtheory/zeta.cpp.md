---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/gcd_convolution.test.cpp
    title: test/gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lcm_convolution.test.cpp
    title: test/lcm_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/zeta.cpp\"\ntemplate<ranges::random_access_range\
    \ R>\nvoid zeta_divisor(R &v) {\n  primes(ssize(v), [&](int p) {\n    for(int\
    \ i = 1; i * p < ssize(v); i++)\n      v[i * p] += v[i];\n  });\n}\n\ntemplate<ranges::random_access_range\
    \ R>\nvoid mobius_divisor(R &v) {\n  primes(ssize(v), [&](int p) {\n    for(int\
    \ i = (ssize(v) - 1) / p; i > 0; i--)\n      v[i * p] -= v[i];\n  });\n}\n\ntemplate<class\
    \ T>\nvoid zeta_multiple(vc<T> &v) {\n  primes(ssize(v), [&](int p) {\n    for(int\
    \ i = (ssize(v) - 1) / p; i > 0; i--)\n      v[i] += v[i * p];\n  });\n}\n\ntemplate<class\
    \ T>\nvoid mobius_multiple(vc<T> &v) {\n  primes(ssize(v), [&](int p) {\n    for(int\
    \ i = 1; i * p < ssize(v); i++)\n      v[i] -= v[i * p];\n  });\n}\n\ntemplate<class\
    \ T>\nvc<T> lcm_convolution(vc<T> a, vc<T> b) {\n  assert(ssize(a) == ssize(b));\n\
    \  zeta_divisor(a), zeta_divisor(b);\n  for(int i = 0; i < ssize(a); i++)\n  \
    \  a[i] *= b[i];\n  mobius_divisor(a);\n  return a;\n}\n\ntemplate<class T>\n\
    vc<T> gcd_convolution(vc<T> a, vc<T> b) {\n  assert(ssize(a) == ssize(b));\n \
    \ zeta_multiple(a), zeta_multiple(b);\n  for(int i = 0; i < ssize(a); i++)\n \
    \   a[i] *= b[i];\n  mobius_multiple(a);\n  return a;\n}\n"
  code: "template<ranges::random_access_range R>\nvoid zeta_divisor(R &v) {\n  primes(ssize(v),\
    \ [&](int p) {\n    for(int i = 1; i * p < ssize(v); i++)\n      v[i * p] += v[i];\n\
    \  });\n}\n\ntemplate<ranges::random_access_range R>\nvoid mobius_divisor(R &v)\
    \ {\n  primes(ssize(v), [&](int p) {\n    for(int i = (ssize(v) - 1) / p; i >\
    \ 0; i--)\n      v[i * p] -= v[i];\n  });\n}\n\ntemplate<class T>\nvoid zeta_multiple(vc<T>\
    \ &v) {\n  primes(ssize(v), [&](int p) {\n    for(int i = (ssize(v) - 1) / p;\
    \ i > 0; i--)\n      v[i] += v[i * p];\n  });\n}\n\ntemplate<class T>\nvoid mobius_multiple(vc<T>\
    \ &v) {\n  primes(ssize(v), [&](int p) {\n    for(int i = 1; i * p < ssize(v);\
    \ i++)\n      v[i] -= v[i * p];\n  });\n}\n\ntemplate<class T>\nvc<T> lcm_convolution(vc<T>\
    \ a, vc<T> b) {\n  assert(ssize(a) == ssize(b));\n  zeta_divisor(a), zeta_divisor(b);\n\
    \  for(int i = 0; i < ssize(a); i++)\n    a[i] *= b[i];\n  mobius_divisor(a);\n\
    \  return a;\n}\n\ntemplate<class T>\nvc<T> gcd_convolution(vc<T> a, vc<T> b)\
    \ {\n  assert(ssize(a) == ssize(b));\n  zeta_multiple(a), zeta_multiple(b);\n\
    \  for(int i = 0; i < ssize(a); i++)\n    a[i] *= b[i];\n  mobius_multiple(a);\n\
    \  return a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/zeta.cpp
  requiredBy: []
  timestamp: '2026-09-03 10:52:15+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lcm_convolution.test.cpp
  - test/gcd_convolution.test.cpp
documentation_of: numtheory/zeta.cpp
layout: document
redirect_from:
- /library/numtheory/zeta.cpp
- /library/numtheory/zeta.cpp.html
title: numtheory/zeta.cpp
---
