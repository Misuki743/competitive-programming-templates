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
  bundledCode: "#line 1 \"new_poly/FPS.cpp\"\nnamespace FPS {\n  \n  template<class\
    \ T>\n  vc<T>& operator+=(vc<T> &a, const vc<T> b) {\n    if (size(a) < size(b))\
    \ a.resize(size(b), 0);\n    for(int i = 0; i < ssize(a); i++)\n      a[i] +=\
    \ b[i];\n    return a;\n  }\n\n  template<class T>\n  vc<T>& operator-=(vc<T>\
    \ &a, const vc<T> b) {\n    if (size(a) < size(b)) a.resize(size(b), 0);\n   \
    \ for(int i = 0; i < ssize(a); i++)\n      a[i] -= b[i];\n    return a;\n  }\n\
    \n  template<class Mint>\n  vc<Mint>& operator*=(vc<Mint> &a, const vc<Mint> b)\
    \ {\n    return a = convolution<Mint>(a, b);\n  }\n  \n  template<class T>\n \
    \ vc<T>& operator+=(vc<T> &a, const T b) {\n    for(int i = 0; i < ssize(a); i++)\n\
    \      a[i] += b;\n    return a;\n  }\n\n  template<class T>\n  vc<T>& operator-=(vc<T>\
    \ &a, const T b) {\n    for(int i = 0; i < ssize(a); i++)\n      a[i] -= b;\n\
    \    return a;\n  }\n\n  template<class T>\n  vc<T>& operator*=(vc<T> &a, const\
    \ T b) {\n    for(int i = 0; i < ssize(a); i++)\n      a[i] *= b;\n  }\n\n  template<class\
    \ T>\n  vc<T>& operator<<=(vc<T> &a, int s) {\n    a.insert(a.begin(), s, 0);\n\
    \    return a;\n  }\n\n  template<class T>\n  vc<T>& operator>>=(vc<T> &a, int\
    \ s) {\n    a.resize(ssize(a) - s);\n    return a;\n  }\n}\n\nusing namespace\
    \ FPS;\n"
  code: "namespace FPS {\n  \n  template<class T>\n  vc<T>& operator+=(vc<T> &a, const\
    \ vc<T> b) {\n    if (size(a) < size(b)) a.resize(size(b), 0);\n    for(int i\
    \ = 0; i < ssize(a); i++)\n      a[i] += b[i];\n    return a;\n  }\n\n  template<class\
    \ T>\n  vc<T>& operator-=(vc<T> &a, const vc<T> b) {\n    if (size(a) < size(b))\
    \ a.resize(size(b), 0);\n    for(int i = 0; i < ssize(a); i++)\n      a[i] -=\
    \ b[i];\n    return a;\n  }\n\n  template<class Mint>\n  vc<Mint>& operator*=(vc<Mint>\
    \ &a, const vc<Mint> b) {\n    return a = convolution<Mint>(a, b);\n  }\n  \n\
    \  template<class T>\n  vc<T>& operator+=(vc<T> &a, const T b) {\n    for(int\
    \ i = 0; i < ssize(a); i++)\n      a[i] += b;\n    return a;\n  }\n\n  template<class\
    \ T>\n  vc<T>& operator-=(vc<T> &a, const T b) {\n    for(int i = 0; i < ssize(a);\
    \ i++)\n      a[i] -= b;\n    return a;\n  }\n\n  template<class T>\n  vc<T>&\
    \ operator*=(vc<T> &a, const T b) {\n    for(int i = 0; i < ssize(a); i++)\n \
    \     a[i] *= b;\n  }\n\n  template<class T>\n  vc<T>& operator<<=(vc<T> &a, int\
    \ s) {\n    a.insert(a.begin(), s, 0);\n    return a;\n  }\n\n  template<class\
    \ T>\n  vc<T>& operator>>=(vc<T> &a, int s) {\n    a.resize(ssize(a) - s);\n \
    \   return a;\n  }\n}\n\nusing namespace FPS;\n"
  dependsOn: []
  isVerificationFile: false
  path: new_poly/FPS.cpp
  requiredBy: []
  timestamp: '2026-09-23 23:21:38+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: new_poly/FPS.cpp
layout: document
redirect_from:
- /library/new_poly/FPS.cpp
- /library/new_poly/FPS.cpp.html
title: new_poly/FPS.cpp
---
