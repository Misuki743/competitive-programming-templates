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
  bundledCode: "#line 1 \"segtree/acted_monoid_segment_tree.cpp\"\n//#include<segtree/lazy_segment_tree.cpp>\n\
    \ntemplate<class AM>\nstruct acted_monoid_segment_tree : lazy_segment_tree<typename\
    \ AM::M, AM::Mid, AM::Mop, typename AM::T, AM::Tid, AM::Top, AM::act> {\n  using\
    \ base = lazy_segment_tree<typename AM::M, AM::Mid, AM::Mop, typename AM::T, AM::Tid,\
    \ AM::Top, AM::act>;\n  acted_monoid_segment_tree(vector<typename AM::M> init)\
    \ : base(init) {}\n  acted_monoid_segment_tree(int size) : base(size) {}\n};\n"
  code: "//#include<segtree/lazy_segment_tree.cpp>\n\ntemplate<class AM>\nstruct acted_monoid_segment_tree\
    \ : lazy_segment_tree<typename AM::M, AM::Mid, AM::Mop, typename AM::T, AM::Tid,\
    \ AM::Top, AM::act> {\n  using base = lazy_segment_tree<typename AM::M, AM::Mid,\
    \ AM::Mop, typename AM::T, AM::Tid, AM::Top, AM::act>;\n  acted_monoid_segment_tree(vector<typename\
    \ AM::M> init) : base(init) {}\n  acted_monoid_segment_tree(int size) : base(size)\
    \ {}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/acted_monoid_segment_tree.cpp
  requiredBy: []
  timestamp: '2026-06-07 00:25:21+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/area_of_union_of_rectangles.test.cpp
documentation_of: segtree/acted_monoid_segment_tree.cpp
layout: document
redirect_from:
- /library/segtree/acted_monoid_segment_tree.cpp
- /library/segtree/acted_monoid_segment_tree.cpp.html
title: segtree/acted_monoid_segment_tree.cpp
---
