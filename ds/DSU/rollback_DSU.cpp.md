---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/persistent_unionfind.test.cpp
    title: test/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/DSU/rollback_DSU.cpp\"\ntemplate<class T = int, typename\
    \ F = void*>\nstruct rollback_DSU {\n  vi sz_par;\n  vc<pii> his;\n  int nxt;\n\
    \n  vc<T> data;\n  vc<T> data_his;\n  F op;\n\n  rollback_DSU(int n) requires\
    \ same_as<F, void*> : sz_par(n, -1), his(2 * (n - 1)), nxt(0) {}\n\n  rollback_DSU(vc<T>\
    \ init, F f) requires R_invocable<void, F, T&, T&> &&\n    (!R_invocable<void,\
    \ F, T, T&>) && (!R_invocable<void, F, T&, T>)\n    : sz_par(ssize(init), -1),\
    \ his(2 * (ssize(init) - 1)), nxt(0), data(init), data_his(ssize(init) - 1), op(f)\
    \ {}\n\n  int query(int v) {\n    int r = v;\n    while(sz_par[r] >= 0) r = sz_par[r];\n\
    \    return r;\n  }\n\n  bool merge(int v1, int v2) {\n    int b1 = query(v1),\
    \ b2 = query(v2);\n\n    if (b1 == b2)\n      return false;\n\n    if (-sz_par[b1]\
    \ > -sz_par[b2])\n      swap(b1, b2);\n\n    his[nxt] = pair(b2, sz_par[b2]);\n\
    \    his[nxt + 1] = pair(b1, sz_par[b1]);\n    sz_par[b2] += sz_par[b1];\n   \
    \ sz_par[b1] = b2;\n    if constexpr (!same_as<F, void*>) {\n      data_his[nxt\
    \ / 2] = data[b2];\n      op(data[b2], data[b1]);\n    }\n    nxt += 2;\n\n  \
    \  return true;\n  }\n\n  int time() { return nxt; }\n  int size(int v) { return\
    \ -sz_par[query(v)]; }\n\n  void rollback(int t) {\n    chmin(t, nxt);\n    for(int\
    \ j = nxt - 1; j >= t; j--) {\n      auto [i, x] = his[j];\n      sz_par[i] =\
    \ x;\n      if constexpr (!same_as<F, void*>) {\n        if (j % 2 == 0)\n   \
    \       data[i] = data_his[j / 2];\n      }\n    }\n    nxt = t;\n  }\n  T& get(int\
    \ v) requires (!same_as<F, void*>) {\n    return data[query(v)];\n  }\n};\n"
  code: "template<class T = int, typename F = void*>\nstruct rollback_DSU {\n  vi\
    \ sz_par;\n  vc<pii> his;\n  int nxt;\n\n  vc<T> data;\n  vc<T> data_his;\n  F\
    \ op;\n\n  rollback_DSU(int n) requires same_as<F, void*> : sz_par(n, -1), his(2\
    \ * (n - 1)), nxt(0) {}\n\n  rollback_DSU(vc<T> init, F f) requires R_invocable<void,\
    \ F, T&, T&> &&\n    (!R_invocable<void, F, T, T&>) && (!R_invocable<void, F,\
    \ T&, T>)\n    : sz_par(ssize(init), -1), his(2 * (ssize(init) - 1)), nxt(0),\
    \ data(init), data_his(ssize(init) - 1), op(f) {}\n\n  int query(int v) {\n  \
    \  int r = v;\n    while(sz_par[r] >= 0) r = sz_par[r];\n    return r;\n  }\n\n\
    \  bool merge(int v1, int v2) {\n    int b1 = query(v1), b2 = query(v2);\n\n \
    \   if (b1 == b2)\n      return false;\n\n    if (-sz_par[b1] > -sz_par[b2])\n\
    \      swap(b1, b2);\n\n    his[nxt] = pair(b2, sz_par[b2]);\n    his[nxt + 1]\
    \ = pair(b1, sz_par[b1]);\n    sz_par[b2] += sz_par[b1];\n    sz_par[b1] = b2;\n\
    \    if constexpr (!same_as<F, void*>) {\n      data_his[nxt / 2] = data[b2];\n\
    \      op(data[b2], data[b1]);\n    }\n    nxt += 2;\n\n    return true;\n  }\n\
    \n  int time() { return nxt; }\n  int size(int v) { return -sz_par[query(v)];\
    \ }\n\n  void rollback(int t) {\n    chmin(t, nxt);\n    for(int j = nxt - 1;\
    \ j >= t; j--) {\n      auto [i, x] = his[j];\n      sz_par[i] = x;\n      if\
    \ constexpr (!same_as<F, void*>) {\n        if (j % 2 == 0)\n          data[i]\
    \ = data_his[j / 2];\n      }\n    }\n    nxt = t;\n  }\n  T& get(int v) requires\
    \ (!same_as<F, void*>) {\n    return data[query(v)];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/DSU/rollback_DSU.cpp
  requiredBy: []
  timestamp: '2026-06-09 17:13:39+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/persistent_unionfind.test.cpp
documentation_of: ds/DSU/rollback_DSU.cpp
layout: document
redirect_from:
- /library/ds/DSU/rollback_DSU.cpp
- /library/ds/DSU/rollback_DSU.cpp.html
title: ds/DSU/rollback_DSU.cpp
---
