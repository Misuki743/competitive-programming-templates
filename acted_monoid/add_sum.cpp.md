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
  bundledCode: "#line 1 \"acted_monoid/add_sum.cpp\"\ntemplate<class U>\nstruct add_sum\
    \ {\n  using M = pair<U, int>;\n  static M Mid() { return make_pair(U(0), 0);\
    \ }\n  static M Mop(const M &a, const M &b) { return make_pair(a.first + b.first,\
    \ a.second + b.second); }\n  using T = U;\n  static T Tid() { return T(0); }\n\
    \  static T Top(const T &a, const T &b) { return a + b; }\n  static M act(const\
    \ M &a, const T &b) { return make_pair(a.first + a.second * b, a.second); }\n\
    };\n"
  code: "template<class U>\nstruct add_sum {\n  using M = pair<U, int>;\n  static\
    \ M Mid() { return make_pair(U(0), 0); }\n  static M Mop(const M &a, const M &b)\
    \ { return make_pair(a.first + b.first, a.second + b.second); }\n  using T = U;\n\
    \  static T Tid() { return T(0); }\n  static T Top(const T &a, const T &b) { return\
    \ a + b; }\n  static M act(const M &a, const T &b) { return make_pair(a.first\
    \ + a.second * b, a.second); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: acted_monoid/add_sum.cpp
  requiredBy: []
  timestamp: '2026-06-07 00:25:21+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: acted_monoid/add_sum.cpp
layout: document
redirect_from:
- /library/acted_monoid/add_sum.cpp
- /library/acted_monoid/add_sum.cpp.html
title: acted_monoid/add_sum.cpp
---
