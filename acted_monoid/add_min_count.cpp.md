---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/area_of_union_of_rectangles.test.cpp
    title: test/area_of_union_of_rectangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"acted_monoid/add_min_count.cpp\"\ntemplate<class U>\nstruct\
    \ add_min_count {\n  using M = pair<U, int>;\n  static M Mid() { return make_pair(numeric_limits<U>::max(),\
    \ 0); }\n  static M Mop(const M &a, const M &b) { return a.first == b.first ?\
    \ make_pair(a.first, a.second + b.second) : min(a, b); }\n  using T = U;\n  static\
    \ T Tid() { return T(0); }\n  static T Top(const T &a, const T &b) { return a\
    \ + b; }\n  static M act(const M &a, const T &b) { return make_pair(a.first +\
    \ b, a.second); }\n};\n"
  code: "template<class U>\nstruct add_min_count {\n  using M = pair<U, int>;\n  static\
    \ M Mid() { return make_pair(numeric_limits<U>::max(), 0); }\n  static M Mop(const\
    \ M &a, const M &b) { return a.first == b.first ? make_pair(a.first, a.second\
    \ + b.second) : min(a, b); }\n  using T = U;\n  static T Tid() { return T(0);\
    \ }\n  static T Top(const T &a, const T &b) { return a + b; }\n  static M act(const\
    \ M &a, const T &b) { return make_pair(a.first + b, a.second); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: acted_monoid/add_min_count.cpp
  requiredBy: []
  timestamp: '2026-06-07 00:25:21+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/area_of_union_of_rectangles.test.cpp
documentation_of: acted_monoid/add_min_count.cpp
layout: document
redirect_from:
- /library/acted_monoid/add_min_count.cpp
- /library/acted_monoid/add_min_count.cpp.html
title: acted_monoid/add_min_count.cpp
---
