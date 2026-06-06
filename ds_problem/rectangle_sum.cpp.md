---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/rectangle_sum.test.cpp
    title: test/rectangle_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds_problem/rectangle_sum.cpp\"\n//#include<ds/fenwick_tree.cpp>\n\
    \ntemplate<integral coord, integral weight>\nvc<weight> rectangle_sum(vc<tuple<coord,\
    \ coord, weight>> pt, vc<array<coord, 4>> query) {\n  vc<coord> ys;\n  for(auto\
    \ &[_, y, __] : pt) ys.eb(y);\n  Unique(ys);\n\n  for(auto &[l, d, r, u] : query)\
    \ {\n    d = ranges::lower_bound(ys, d) - ys.begin();\n    u = ranges::lower_bound(ys,\
    \ u) - ys.begin();\n  }\n\n  for(auto &[x, y, w] : pt)\n    y = ranges::lower_bound(ys,\
    \ y) - ys.begin();\n  ranges::sort(pt, {}, [](auto &x) { return get<0>(x); });\n\
    \n  struct event { int qid, left; };\n  vc<event> es(2 * ssize(query));\n  for(int\
    \ i = 0; i < ssize(query); i++)\n    es[i << 1] = event{i, 0}, es[i << 1 | 1]\
    \ = event{i, 1};\n  ranges::sort(es, {}, [&](event &e) { return query[e.qid][e.left\
    \ ? 0 : 2]; });\n\n  fenwick_tree<weight> ft(size(ys));\n  vc<weight> ans(size(query));\n\
    \  for(int i = 0; auto [qid, left] : es) {\n    auto [l, d, r, u] = query[qid];\n\
    \    while(i < ssize(pt) and get<0>(pt[i]) < query[qid][left ? 0 : 2]) {\n   \
    \   auto [x, y, w] = pt[i++];\n      ft.add(y, w);\n    }\n    ans[qid] += ft.query(d,\
    \ u) * (left ? -1 : 1);\n  }\n\n  return ans;\n}\n"
  code: "//#include<ds/fenwick_tree.cpp>\n\ntemplate<integral coord, integral weight>\n\
    vc<weight> rectangle_sum(vc<tuple<coord, coord, weight>> pt, vc<array<coord, 4>>\
    \ query) {\n  vc<coord> ys;\n  for(auto &[_, y, __] : pt) ys.eb(y);\n  Unique(ys);\n\
    \n  for(auto &[l, d, r, u] : query) {\n    d = ranges::lower_bound(ys, d) - ys.begin();\n\
    \    u = ranges::lower_bound(ys, u) - ys.begin();\n  }\n\n  for(auto &[x, y, w]\
    \ : pt)\n    y = ranges::lower_bound(ys, y) - ys.begin();\n  ranges::sort(pt,\
    \ {}, [](auto &x) { return get<0>(x); });\n\n  struct event { int qid, left; };\n\
    \  vc<event> es(2 * ssize(query));\n  for(int i = 0; i < ssize(query); i++)\n\
    \    es[i << 1] = event{i, 0}, es[i << 1 | 1] = event{i, 1};\n  ranges::sort(es,\
    \ {}, [&](event &e) { return query[e.qid][e.left ? 0 : 2]; });\n\n  fenwick_tree<weight>\
    \ ft(size(ys));\n  vc<weight> ans(size(query));\n  for(int i = 0; auto [qid, left]\
    \ : es) {\n    auto [l, d, r, u] = query[qid];\n    while(i < ssize(pt) and get<0>(pt[i])\
    \ < query[qid][left ? 0 : 2]) {\n      auto [x, y, w] = pt[i++];\n      ft.add(y,\
    \ w);\n    }\n    ans[qid] += ft.query(d, u) * (left ? -1 : 1);\n  }\n\n  return\
    \ ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ds_problem/rectangle_sum.cpp
  requiredBy: []
  timestamp: '2026-06-07 03:13:20+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/rectangle_sum.test.cpp
documentation_of: ds_problem/rectangle_sum.cpp
layout: document
redirect_from:
- /library/ds_problem/rectangle_sum.cpp
- /library/ds_problem/rectangle_sum.cpp.html
title: ds_problem/rectangle_sum.cpp
---
