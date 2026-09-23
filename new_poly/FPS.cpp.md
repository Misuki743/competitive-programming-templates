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
    \ {\n    return a = convolution(a, b);\n  }\n  \n  template<class T>\n  vc<T>&\
    \ operator+=(vc<T> &a, const T b) {\n    for(int i = 0; i < ssize(a); i++)\n \
    \     a[i] += b;\n    return a;\n  }\n\n  template<class T>\n  vc<T>& operator-=(vc<T>\
    \ &a, const T b) {\n    for(int i = 0; i < ssize(a); i++)\n      a[i] -= b;\n\
    \    return a;\n  }\n\n  template<class T>\n  vc<T>& operator*=(vc<T> &a, const\
    \ T b) {\n    for(int i = 0; i < ssize(a); i++)\n      a[i] *= b;\n    return\
    \ a;\n  }\n\n  template<class T>\n  vc<T>& operator<<=(vc<T> &a, int s) {\n  \
    \  a.insert(a.begin(), s, 0);\n    return a;\n  }\n\n  template<class T>\n  vc<T>&\
    \ operator>>=(vc<T> &a, int s) {\n    assert(s <= ssize(a));\n    a.erase(a.begin(),\
    \ a.begin() + s);\n    return a;\n  }\n\n  template<class T>\n  vc<T> operator+(vc<T>\
    \ a, vc<T> b) { return a += b; }\n  template<class T>\n  vc<T> operator-(vc<T>\
    \ a, vc<T> b) { return a -= b; }\n  template<class Mint>\n  vc<Mint> operator*(vc<Mint>\
    \ a, vc<Mint> b) { return a *= b; }\n  template<class T>\n  vc<T> operator*(vc<T>\
    \ a, T b) { return a *= b; }\n\n  template<class Mint>\n  vc<Mint> derivative(vc<Mint>\
    \ a) {\n    a >>= 1;\n    for(int i = 0; i < ssize(a); i++)\n      a[i] *= i +\
    \ 1;\n    return a;\n  }\n\n  template<class Mint>\n  vc<Mint> integral(vc<Mint>\
    \ a) {\n    a <<= 1;\n    for(int i = 1; i < ssize(a); i++)\n      a[i] *= inverse<Mint>(i);\n\
    \    return a;\n  }\n\n  template<class Mint>\n  vc<Mint> inv(vc<Mint> &a, int\
    \ k = -1) {\n    assert(!empty(a) and a[0] != 0);\n    if (k == -1) k = ssize(a);\n\
    \    vc<Mint> b(1, a[0].inverse());\n    for(int i = 1; (1 << (i - 1)) < k; i++)\
    \ {\n      vc<Mint> c(1 << (i + 1));\n      ranges::copy(a | views::take(1 <<\
    \ i), c.begin());\n      DFT(c, 0);\n\n      b.resize(1 << (i + 1));\n      auto\
    \ d = b * Mint(2);\n      DFT(b, 0);\n\n      for(int j = 0; j < ssize(b); j++)\n\
    \        b[j] *= b[j] * c[j];\n      DFT(b, 1);\n\n      b = d - b;\n      b.resize(1\
    \ << i);\n    }\n    b.resize(k);\n    return b;\n  }\n\n  template<class Mint>\n\
    \  vc<Mint> log(vc<Mint> a, int k = -1) {\n    assert(!empty(a) and a[0] == 1);\n\
    \    if (k == -1) k = ssize(a);\n    vc<Mint> b = inv(a, k);\n    a = derivative(a)\
    \ * b;\n    a.resize(k - 1);\n    return integral(a);\n  }\n\n  template<class\
    \ Mint>\n  vc<Mint> exp(vc<Mint> a, int k = -1) {\n    assert(!empty(a) and a[0]\
    \ == 0);\n    if (k == -1) k = ssize(a);\n    vc<Mint> b(1, 1);\n    for(int i\
    \ = 1; (1 << (i - 1)) < k; i++) {\n      vc<Mint> c(1 << i);\n      ranges::copy(a\
    \ | views::take(1 << i), c.begin());\n      b = b * (vc<Mint>(1, 1) + c - log(b,\
    \ 1 << i));\n      b.resize(1 << i);\n    }\n    b.resize(k);\n    return b;\n\
    \  }\n}\n\nusing namespace FPS;\n"
  code: "namespace FPS {\n  \n  template<class T>\n  vc<T>& operator+=(vc<T> &a, const\
    \ vc<T> b) {\n    if (size(a) < size(b)) a.resize(size(b), 0);\n    for(int i\
    \ = 0; i < ssize(a); i++)\n      a[i] += b[i];\n    return a;\n  }\n\n  template<class\
    \ T>\n  vc<T>& operator-=(vc<T> &a, const vc<T> b) {\n    if (size(a) < size(b))\
    \ a.resize(size(b), 0);\n    for(int i = 0; i < ssize(a); i++)\n      a[i] -=\
    \ b[i];\n    return a;\n  }\n\n  template<class Mint>\n  vc<Mint>& operator*=(vc<Mint>\
    \ &a, const vc<Mint> b) {\n    return a = convolution(a, b);\n  }\n  \n  template<class\
    \ T>\n  vc<T>& operator+=(vc<T> &a, const T b) {\n    for(int i = 0; i < ssize(a);\
    \ i++)\n      a[i] += b;\n    return a;\n  }\n\n  template<class T>\n  vc<T>&\
    \ operator-=(vc<T> &a, const T b) {\n    for(int i = 0; i < ssize(a); i++)\n \
    \     a[i] -= b;\n    return a;\n  }\n\n  template<class T>\n  vc<T>& operator*=(vc<T>\
    \ &a, const T b) {\n    for(int i = 0; i < ssize(a); i++)\n      a[i] *= b;\n\
    \    return a;\n  }\n\n  template<class T>\n  vc<T>& operator<<=(vc<T> &a, int\
    \ s) {\n    a.insert(a.begin(), s, 0);\n    return a;\n  }\n\n  template<class\
    \ T>\n  vc<T>& operator>>=(vc<T> &a, int s) {\n    assert(s <= ssize(a));\n  \
    \  a.erase(a.begin(), a.begin() + s);\n    return a;\n  }\n\n  template<class\
    \ T>\n  vc<T> operator+(vc<T> a, vc<T> b) { return a += b; }\n  template<class\
    \ T>\n  vc<T> operator-(vc<T> a, vc<T> b) { return a -= b; }\n  template<class\
    \ Mint>\n  vc<Mint> operator*(vc<Mint> a, vc<Mint> b) { return a *= b; }\n  template<class\
    \ T>\n  vc<T> operator*(vc<T> a, T b) { return a *= b; }\n\n  template<class Mint>\n\
    \  vc<Mint> derivative(vc<Mint> a) {\n    a >>= 1;\n    for(int i = 0; i < ssize(a);\
    \ i++)\n      a[i] *= i + 1;\n    return a;\n  }\n\n  template<class Mint>\n \
    \ vc<Mint> integral(vc<Mint> a) {\n    a <<= 1;\n    for(int i = 1; i < ssize(a);\
    \ i++)\n      a[i] *= inverse<Mint>(i);\n    return a;\n  }\n\n  template<class\
    \ Mint>\n  vc<Mint> inv(vc<Mint> &a, int k = -1) {\n    assert(!empty(a) and a[0]\
    \ != 0);\n    if (k == -1) k = ssize(a);\n    vc<Mint> b(1, a[0].inverse());\n\
    \    for(int i = 1; (1 << (i - 1)) < k; i++) {\n      vc<Mint> c(1 << (i + 1));\n\
    \      ranges::copy(a | views::take(1 << i), c.begin());\n      DFT(c, 0);\n\n\
    \      b.resize(1 << (i + 1));\n      auto d = b * Mint(2);\n      DFT(b, 0);\n\
    \n      for(int j = 0; j < ssize(b); j++)\n        b[j] *= b[j] * c[j];\n    \
    \  DFT(b, 1);\n\n      b = d - b;\n      b.resize(1 << i);\n    }\n    b.resize(k);\n\
    \    return b;\n  }\n\n  template<class Mint>\n  vc<Mint> log(vc<Mint> a, int\
    \ k = -1) {\n    assert(!empty(a) and a[0] == 1);\n    if (k == -1) k = ssize(a);\n\
    \    vc<Mint> b = inv(a, k);\n    a = derivative(a) * b;\n    a.resize(k - 1);\n\
    \    return integral(a);\n  }\n\n  template<class Mint>\n  vc<Mint> exp(vc<Mint>\
    \ a, int k = -1) {\n    assert(!empty(a) and a[0] == 0);\n    if (k == -1) k =\
    \ ssize(a);\n    vc<Mint> b(1, 1);\n    for(int i = 1; (1 << (i - 1)) < k; i++)\
    \ {\n      vc<Mint> c(1 << i);\n      ranges::copy(a | views::take(1 << i), c.begin());\n\
    \      b = b * (vc<Mint>(1, 1) + c - log(b, 1 << i));\n      b.resize(1 << i);\n\
    \    }\n    b.resize(k);\n    return b;\n  }\n}\n\nusing namespace FPS;\n"
  dependsOn: []
  isVerificationFile: false
  path: new_poly/FPS.cpp
  requiredBy: []
  timestamp: '2026-09-24 00:49:28+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: new_poly/FPS.cpp
layout: document
redirect_from:
- /library/new_poly/FPS.cpp
- /library/new_poly/FPS.cpp.html
title: new_poly/FPS.cpp
---
