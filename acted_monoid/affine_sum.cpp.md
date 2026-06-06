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
  bundledCode: "#line 1 \"acted_monoid/affine_sum.cpp\"\ntemplate<class U>\nstruct\
    \ affine_sum {\n  using M = array<U, 2>;\n  static M Mid() { return M{0, 0}; }\n\
    \  static M Mop(const M &a, const M &b) { return {a[0] + b[0], a[1] + b[1]}; }\n\
    \  using T = array<U, 2>;\n  static T Tid() { return T{1, 0}; }\n  static T Top(const\
    \ T &a, const T &b) { return T{a[0] * b[0], a[1] * b[0] + b[1]}; }\n  static M\
    \ act(const M &a, const T &b) { return {a[0] * b[0] + a[1] * b[1], a[1]}; }\n\
    };\n"
  code: "template<class U>\nstruct affine_sum {\n  using M = array<U, 2>;\n  static\
    \ M Mid() { return M{0, 0}; }\n  static M Mop(const M &a, const M &b) { return\
    \ {a[0] + b[0], a[1] + b[1]}; }\n  using T = array<U, 2>;\n  static T Tid() {\
    \ return T{1, 0}; }\n  static T Top(const T &a, const T &b) { return T{a[0] *\
    \ b[0], a[1] * b[0] + b[1]}; }\n  static M act(const M &a, const T &b) { return\
    \ {a[0] * b[0] + a[1] * b[1], a[1]}; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: acted_monoid/affine_sum.cpp
  requiredBy: []
  timestamp: '2026-06-07 00:25:21+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: acted_monoid/affine_sum.cpp
layout: document
redirect_from:
- /library/acted_monoid/affine_sum.cpp
- /library/acted_monoid/affine_sum.cpp.html
title: acted_monoid/affine_sum.cpp
---
