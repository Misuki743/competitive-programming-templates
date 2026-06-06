---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/static_range_count_distinct.test.cpp
    title: test/static_range_count_distinct.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds_problem/range_count_distinct.cpp\"\n//#include<ds/fenwick_tree.cpp>\n\
    \ntemplate<integral T>\nvi range_count_distinct(vc<T> a, vc<pii> query) {\n  vc<T>\
    \ b = a;\n  Unique(b);\n  for(T &x : a)\n    x = ranges::lower_bound(b, x) - b.begin();\n\
    \n  dbg(a);\n\n  vi ans(size(query)), pos(size(b), -1);\n  dbg(ssize(pos));\n\
    \  fenwick_tree<int> ft(ssize(a));\n  for(int j = 0; int i : argSort(query, [](pii\
    \ &p) { return p.second; })) {\n    auto [l, r] = query[i];\n    while(j < r)\
    \ {\n      if (pos[a[j]] != -1)\n        ft.add(pos[a[j]], -1);\n      ft.add(j,\
    \ 1);\n      pos[a[j]] = j, j++;\n    }\n    ans[i] = ft.query(l, r);\n  }\n\n\
    \  return ans;\n}\n"
  code: "//#include<ds/fenwick_tree.cpp>\n\ntemplate<integral T>\nvi range_count_distinct(vc<T>\
    \ a, vc<pii> query) {\n  vc<T> b = a;\n  Unique(b);\n  for(T &x : a)\n    x =\
    \ ranges::lower_bound(b, x) - b.begin();\n\n  dbg(a);\n\n  vi ans(size(query)),\
    \ pos(size(b), -1);\n  dbg(ssize(pos));\n  fenwick_tree<int> ft(ssize(a));\n \
    \ for(int j = 0; int i : argSort(query, [](pii &p) { return p.second; })) {\n\
    \    auto [l, r] = query[i];\n    while(j < r) {\n      if (pos[a[j]] != -1)\n\
    \        ft.add(pos[a[j]], -1);\n      ft.add(j, 1);\n      pos[a[j]] = j, j++;\n\
    \    }\n    ans[i] = ft.query(l, r);\n  }\n\n  return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ds_problem/range_count_distinct.cpp
  requiredBy: []
  timestamp: '2026-06-07 01:25:54+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/static_range_count_distinct.test.cpp
documentation_of: ds_problem/range_count_distinct.cpp
layout: document
redirect_from:
- /library/ds_problem/range_count_distinct.cpp
- /library/ds_problem/range_count_distinct.cpp.html
title: ds_problem/range_count_distinct.cpp
---
