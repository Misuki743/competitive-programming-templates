---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: test/point_set_tree_path_composite_sum_fixed_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/dynamic_tree_DP.cpp\"\n//#include \"ds/staticTopTree.cpp\"\
    \ntemplate<class M, M(*rake)(const M&, const M&), M(*compress)(const M&, const\
    \ M&)>\nstruct dynamic_tree_DP {\n  vector<M> dp;\n  static_top_tree stt;\n\n\
    \  void pull(int v) {\n    if (stt.rake[v]) dp[v] = rake(dp[stt.lc[v]], dp[stt.rc[v]]);\n\
    \    else dp[v] = compress(dp[stt.lc[v]], dp[stt.rc[v]]);\n  }\n\n  dynamic_tree_DP(vector<vector<int>>\
    \ &g, vector<M> &init)\n    : dp(2 * ssize(g) - 1), stt(g) {\n    for(int i =\
    \ 0; i < ssize(g); i++)\n      dp[i] = init[i];\n    for(int i = ssize(g); i <\
    \ 2 * ssize(g) - 1; i++)\n      pull(i);\n  }\n\n  void set(int v, M x) {\n  \
    \  dp[v] = x;\n    while((v = stt.pa[v]) != -1) pull(v);\n  }\n\n  M query() {\
    \ return dp.back(); }\n};\n"
  code: "//#include \"ds/staticTopTree.cpp\"\ntemplate<class M, M(*rake)(const M&,\
    \ const M&), M(*compress)(const M&, const M&)>\nstruct dynamic_tree_DP {\n  vector<M>\
    \ dp;\n  static_top_tree stt;\n\n  void pull(int v) {\n    if (stt.rake[v]) dp[v]\
    \ = rake(dp[stt.lc[v]], dp[stt.rc[v]]);\n    else dp[v] = compress(dp[stt.lc[v]],\
    \ dp[stt.rc[v]]);\n  }\n\n  dynamic_tree_DP(vector<vector<int>> &g, vector<M>\
    \ &init)\n    : dp(2 * ssize(g) - 1), stt(g) {\n    for(int i = 0; i < ssize(g);\
    \ i++)\n      dp[i] = init[i];\n    for(int i = ssize(g); i < 2 * ssize(g) - 1;\
    \ i++)\n      pull(i);\n  }\n\n  void set(int v, M x) {\n    dp[v] = x;\n    while((v\
    \ = stt.pa[v]) != -1) pull(v);\n  }\n\n  M query() { return dp.back(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/dynamic_tree_DP.cpp
  requiredBy: []
  timestamp: '2026-06-06 23:34:13+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/point_set_tree_path_composite_sum_fixed_root.test.cpp
documentation_of: dp/dynamic_tree_DP.cpp
layout: document
redirect_from:
- /library/dp/dynamic_tree_DP.cpp
- /library/dp/dynamic_tree_DP.cpp.html
title: dp/dynamic_tree_DP.cpp
---
