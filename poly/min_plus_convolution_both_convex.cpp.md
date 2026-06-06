---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/min_plus_convolution_convex_convex.test.cpp
    title: test/min_plus_convolution_convex_convex.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/min_plus_convolution_both_convex.cpp\"\n//both a and\
    \ b are convex, i.e. f(i+2) - f(i+1) >= f(i+1) - f(i)\ntemplate<class T>\nvc<T>\
    \ min_plus_convolution(vc<T> a, vc<T> b) {\n  vc<T> c(ssize(a) + ssize(b) - 1);\n\
    \  adjacent_difference(a.begin(), a.end(), a.begin());\n  adjacent_difference(b.begin(),\
    \ b.end(), b.begin());\n  c[0] = a[0] + b[0];\n  merge(a.begin() + 1, a.end(),\
    \ b.begin() + 1, b.end(), c.begin() + 1);\n  pSum(c);\n  return c;\n}\n"
  code: "//both a and b are convex, i.e. f(i+2) - f(i+1) >= f(i+1) - f(i)\ntemplate<class\
    \ T>\nvc<T> min_plus_convolution(vc<T> a, vc<T> b) {\n  vc<T> c(ssize(a) + ssize(b)\
    \ - 1);\n  adjacent_difference(a.begin(), a.end(), a.begin());\n  adjacent_difference(b.begin(),\
    \ b.end(), b.begin());\n  c[0] = a[0] + b[0];\n  merge(a.begin() + 1, a.end(),\
    \ b.begin() + 1, b.end(), c.begin() + 1);\n  pSum(c);\n  return c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/min_plus_convolution_both_convex.cpp
  requiredBy: []
  timestamp: '2026-05-07 13:54:37+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/min_plus_convolution_convex_convex.test.cpp
documentation_of: poly/min_plus_convolution_both_convex.cpp
layout: document
redirect_from:
- /library/poly/min_plus_convolution_both_convex.cpp
- /library/poly/min_plus_convolution_both_convex.cpp.html
title: poly/min_plus_convolution_both_convex.cpp
---
