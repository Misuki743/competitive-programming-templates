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
  bundledCode: "#line 1 \"acted_monoid/set_min.cpp\"\ntemplate<class U, U unused>\n\
    struct set_min {\n  using M = U;\n  static M Mid() { return numeric_limits<T>::max();\
    \ }\n  static M Mop(const M &a, const M &b) { return min(a, b); }\n  using T =\
    \ U;\n  static T Tid() { return unused; }\n  static T Top(const T &a, const T\
    \ &b) { return b == unused ? a : b; }\n  static M act(const M &a, const T &b)\
    \ { return b == unused ? a : b; }\n};\n"
  code: "template<class U, U unused>\nstruct set_min {\n  using M = U;\n  static M\
    \ Mid() { return numeric_limits<T>::max(); }\n  static M Mop(const M &a, const\
    \ M &b) { return min(a, b); }\n  using T = U;\n  static T Tid() { return unused;\
    \ }\n  static T Top(const T &a, const T &b) { return b == unused ? a : b; }\n\
    \  static M act(const M &a, const T &b) { return b == unused ? a : b; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: acted_monoid/set_min.cpp
  requiredBy: []
  timestamp: '2026-06-07 00:25:21+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: acted_monoid/set_min.cpp
layout: document
redirect_from:
- /library/acted_monoid/set_min.cpp
- /library/acted_monoid/set_min.cpp.html
title: acted_monoid/set_min.cpp
---
