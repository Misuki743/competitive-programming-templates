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
  bundledCode: "#line 1 \"misc/array_utility.cpp\"\ntemplate<class T, size_t N>\n\
    array<T, N>& operator+=(array<T, N> &a, const array<T, N> &b) {\n  for(size_t\
    \ i = 0; i < N; i++) \n    a[i] += b[i];\n  return a;\n}\ntemplate<class T, size_t\
    \ N>\narray<T, N>& operator-=(array<T, N> &a, const array<T, N> &b) {\n  for(size_t\
    \ i = 0; i < N; i++) \n    a[i] -= b[i];\n  return a;\n}\ntemplate<class T, size_t\
    \ N>\narray<T, N> operator+(array<T, N> a, array<T, N> b) { return a += b; }\n\
    template<class T, size_t N>\narray<T, N> operator-(array<T, N> a, array<T, N>\
    \ b) { return a -= b; }\n"
  code: "template<class T, size_t N>\narray<T, N>& operator+=(array<T, N> &a, const\
    \ array<T, N> &b) {\n  for(size_t i = 0; i < N; i++) \n    a[i] += b[i];\n  return\
    \ a;\n}\ntemplate<class T, size_t N>\narray<T, N>& operator-=(array<T, N> &a,\
    \ const array<T, N> &b) {\n  for(size_t i = 0; i < N; i++) \n    a[i] -= b[i];\n\
    \  return a;\n}\ntemplate<class T, size_t N>\narray<T, N> operator+(array<T, N>\
    \ a, array<T, N> b) { return a += b; }\ntemplate<class T, size_t N>\narray<T,\
    \ N> operator-(array<T, N> a, array<T, N> b) { return a -= b; }\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/array_utility.cpp
  requiredBy: []
  timestamp: '2026-06-06 23:34:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/array_utility.cpp
layout: document
redirect_from:
- /library/misc/array_utility.cpp
- /library/misc/array_utility.cpp.html
title: misc/array_utility.cpp
---
