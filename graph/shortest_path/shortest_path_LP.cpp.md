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
  bundledCode: "#line 1 \"graph/shortest_path/shortest_path_LP.cpp\"\ntemplate<integral\
    \ T>\nstruct shortest_path_LP {\n  const T INF = numeric_limits<T>::max() >> 2;\n\
    \  vc<tuple<int, int, T>> e;\n  vi x;\n\n  shortest_path_LP(int n) : x(n, INF)\
    \ {}\n\n  void var_max(int i, T mx) { chmin(x[i], mx); }\n  void dif_max(int i,\
    \ int j, T d) { e.eb(j, i, d); }\n  void dif_min(int i, int j, T d) { e.eb(i,\
    \ j, -d); }\n  void dif_min_max(int i, int j, T d, T u) {\n    dif_min(i, j, d);\n\
    \    dif_max(i, j, u);\n  }\n\n  bool solve() {\n    bool relax = true;\n    for(int\
    \ iter = 0; iter < ssize(x) and relax; iter++) {\n      relax = false;\n     \
    \ for(auto [i, j, w] : e)\n        if (chmin(x[j], x[i] + w))\n          relax\
    \ = true;\n      if (iter + 1 == ssize(x) and relax)\n        return false;\n\
    \    }\n    return true;\n  }\n};\n"
  code: "template<integral T>\nstruct shortest_path_LP {\n  const T INF = numeric_limits<T>::max()\
    \ >> 2;\n  vc<tuple<int, int, T>> e;\n  vi x;\n\n  shortest_path_LP(int n) : x(n,\
    \ INF) {}\n\n  void var_max(int i, T mx) { chmin(x[i], mx); }\n  void dif_max(int\
    \ i, int j, T d) { e.eb(j, i, d); }\n  void dif_min(int i, int j, T d) { e.eb(i,\
    \ j, -d); }\n  void dif_min_max(int i, int j, T d, T u) {\n    dif_min(i, j, d);\n\
    \    dif_max(i, j, u);\n  }\n\n  bool solve() {\n    bool relax = true;\n    for(int\
    \ iter = 0; iter < ssize(x) and relax; iter++) {\n      relax = false;\n     \
    \ for(auto [i, j, w] : e)\n        if (chmin(x[j], x[i] + w))\n          relax\
    \ = true;\n      if (iter + 1 == ssize(x) and relax)\n        return false;\n\
    \    }\n    return true;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/shortest_path_LP.cpp
  requiredBy: []
  timestamp: '2026-05-01 21:43:21+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shortest_path/shortest_path_LP.cpp
layout: document
redirect_from:
- /library/graph/shortest_path/shortest_path_LP.cpp
- /library/graph/shortest_path/shortest_path_LP.cpp.html
title: graph/shortest_path/shortest_path_LP.cpp
---
