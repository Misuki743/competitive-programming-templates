---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/counting_eulerian_circuits.test.cpp
    title: test/counting_eulerian_circuits.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"combi/count_eulerian_circuit.cpp\"\n//#include \"modint/Montgomery_modint.cpp\"\
    \n//#include \"linalg/matrixMint.cpp\"\n//#include \"combi/countSpanningForest.cpp\"\
    \n//#include \"combi/binom.cpp\"\n\ntemplate<class Mint>\nMint count_eulerian_circuit(vector<array<int,\
    \ 2>> e, int n) {\n  vector<int> deg(n);\n  vector<vector<int>> g(n);\n  for(auto\
    \ [u, v] : e) {\n    deg[v]++;\n    g[u].emplace_back(v);\n  }\n\n  for(int v\
    \ = 0; v < n; v++)\n    if (deg[v] != ssize(g[v]))\n      return Mint(0);\n\n\
    \  vector<bool> vis(n, false);\n  auto dfs = [&](int v, auto &&self) -> void {\n\
    \    vis[v] = true;\n    for(int x : g[v])\n      if (!vis[x])\n        self(x,\
    \ self);\n  };\n\n  int s = 0;\n  while(s < n and deg[s] == 0) s++;\n  s %= n;\n\
    \  dfs(s, dfs);\n\n  vector<int> r(1, s);\n  for(int v = 0; v < n; v++) if (!vis[v])\
    \ {\n    if (deg[v] != 0) return Mint(0);\n    else r.emplace_back(v);\n  }\n\n\
    \  vector<tuple<int, int, Mint>> ep(ssize(e));\n  for(int i = 0; auto [u, v] :\
    \ e)\n    ep[i++] = {u, v, Mint(1)};\n  \n  Mint c = 1;\n  binomial<Mint> bn(ssize(e));\n\
    \  for(int v = 0; v < n; v++)\n    c *= bn.fac(max(deg[v] - 1, 0));\n\n  return\
    \ c * count_spanning_forest<Mint, true>(ep, n, r);\n}\n"
  code: "//#include \"modint/Montgomery_modint.cpp\"\n//#include \"linalg/matrixMint.cpp\"\
    \n//#include \"combi/countSpanningForest.cpp\"\n//#include \"combi/binom.cpp\"\
    \n\ntemplate<class Mint>\nMint count_eulerian_circuit(vector<array<int, 2>> e,\
    \ int n) {\n  vector<int> deg(n);\n  vector<vector<int>> g(n);\n  for(auto [u,\
    \ v] : e) {\n    deg[v]++;\n    g[u].emplace_back(v);\n  }\n\n  for(int v = 0;\
    \ v < n; v++)\n    if (deg[v] != ssize(g[v]))\n      return Mint(0);\n\n  vector<bool>\
    \ vis(n, false);\n  auto dfs = [&](int v, auto &&self) -> void {\n    vis[v] =\
    \ true;\n    for(int x : g[v])\n      if (!vis[x])\n        self(x, self);\n \
    \ };\n\n  int s = 0;\n  while(s < n and deg[s] == 0) s++;\n  s %= n;\n  dfs(s,\
    \ dfs);\n\n  vector<int> r(1, s);\n  for(int v = 0; v < n; v++) if (!vis[v]) {\n\
    \    if (deg[v] != 0) return Mint(0);\n    else r.emplace_back(v);\n  }\n\n  vector<tuple<int,\
    \ int, Mint>> ep(ssize(e));\n  for(int i = 0; auto [u, v] : e)\n    ep[i++] =\
    \ {u, v, Mint(1)};\n  \n  Mint c = 1;\n  binomial<Mint> bn(ssize(e));\n  for(int\
    \ v = 0; v < n; v++)\n    c *= bn.fac(max(deg[v] - 1, 0));\n\n  return c * count_spanning_forest<Mint,\
    \ true>(ep, n, r);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/count_eulerian_circuit.cpp
  requiredBy: []
  timestamp: '2026-06-07 01:41:25+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/counting_eulerian_circuits.test.cpp
documentation_of: combi/count_eulerian_circuit.cpp
layout: document
redirect_from:
- /library/combi/count_eulerian_circuit.cpp
- /library/combi/count_eulerian_circuit.cpp.html
title: combi/count_eulerian_circuit.cpp
---
