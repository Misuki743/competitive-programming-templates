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
  bundledCode: "#line 1 \"actedmonoid/actedMonoid_affineSum.cpp\"\ntemplate<class\
    \ U>\nstruct actedMonoid_affineSum {\n  using M = array<U, 2>;\n  static M Mid()\
    \ { return M{0, 0}; }\n  static M Mop(const M &a, const M &b) { return {a[0] +\
    \ b[0], a[1] + b[1]}; }\n  using T = array<U, 2>;\n  static T Tid() { return T{1,\
    \ 0}; }\n  static T Top(const T &a, const T &b) { return T{a[0] * b[0], a[1] *\
    \ b[0] + b[1]}; }\n  static M act(const M &a, const T &b) { return {a[0] * b[0]\
    \ + a[1] * b[1], a[1]}; }\n};\n"
  code: "template<class U>\nstruct actedMonoid_affineSum {\n  using M = array<U, 2>;\n\
    \  static M Mid() { return M{0, 0}; }\n  static M Mop(const M &a, const M &b)\
    \ { return {a[0] + b[0], a[1] + b[1]}; }\n  using T = array<U, 2>;\n  static T\
    \ Tid() { return T{1, 0}; }\n  static T Top(const T &a, const T &b) { return T{a[0]\
    \ * b[0], a[1] * b[0] + b[1]}; }\n  static M act(const M &a, const T &b) { return\
    \ {a[0] * b[0] + a[1] * b[1], a[1]}; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: actedmonoid/actedMonoid_affineSum.cpp
  requiredBy: []
  timestamp: '2026-03-22 16:32:23+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: actedmonoid/actedMonoid_affineSum.cpp
layout: document
redirect_from:
- /library/actedmonoid/actedMonoid_affineSum.cpp
- /library/actedmonoid/actedMonoid_affineSum.cpp.html
title: actedmonoid/actedMonoid_affineSum.cpp
---
