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
  bundledCode: "#line 1 \"setfunc/dynamic_SOS.cpp\"\n//#include<enumerate/enumerate_bit.cpp>\n\
    \ntemplate<class T>\nstruct dynamic_SOS {\n  vc<T> f;\n  array<ull, 3> g;\n  dynamic_SOS(int\
    \ W, vc<pii> add = {}, vi get = {}) : f(1 << W) {\n    ll opt_cost = LLONG_MAX;\n\
    \    mt19937_64 rng(clock);\n    uniform_int_distribution<int> unif(0, 2);\n \
    \   for(int i = 0; i < 64; i++) {\n      array<ull, 3> g_tmp = {};\n      for(int\
    \ j = 0; j < W; j++)\n        g_tmp[unif(rng)] |= 1 << j;\n      ll cost = 0;\n\
    \      for(auto [l, u] : add)\n        cost += 1ll << (popcount((g_tmp[0] & ~u)\
    \ | (g_tmp[1] & l) | (g_tmp[2] & u & ~l)));\n      for(auto z : get)\n       \
    \ cost += 1ll << (popcount((z & g_tmp[0]) | (~z & g_tmp[1])));\n      if (chmin(opt_cost,\
    \ cost))\n        g = g_tmp;\n    }\n  }\n\n  void add(int l, int u, T x) {\n\
    \    ull tar = (g[0] & ~u) | (g[1] & l) | (g[2] & u & ~l);\n    ull inv = l |\
    \ (g[1] & u & ~l);\n    enumerate_subset(tar, [&](ull msk) {\n      f[msk ^ inv]\
    \ += (popcount((~u | l) & msk) % 2 == 1 ? -x : x);\n    });\n  };\n  T get(int\
    \ l) {\n    T s = 0;\n    ull tar = (l & g[0]) | (~l & g[1]);\n    enumerate_subset(tar,\
    \ [&](ull msk) {\n      s += f[msk ^ l];\n    });\n    return s;\n  };\n};\n"
  code: "//#include<enumerate/enumerate_bit.cpp>\n\ntemplate<class T>\nstruct dynamic_SOS\
    \ {\n  vc<T> f;\n  array<ull, 3> g;\n  dynamic_SOS(int W, vc<pii> add = {}, vi\
    \ get = {}) : f(1 << W) {\n    ll opt_cost = LLONG_MAX;\n    mt19937_64 rng(clock);\n\
    \    uniform_int_distribution<int> unif(0, 2);\n    for(int i = 0; i < 64; i++)\
    \ {\n      array<ull, 3> g_tmp = {};\n      for(int j = 0; j < W; j++)\n     \
    \   g_tmp[unif(rng)] |= 1 << j;\n      ll cost = 0;\n      for(auto [l, u] : add)\n\
    \        cost += 1ll << (popcount((g_tmp[0] & ~u) | (g_tmp[1] & l) | (g_tmp[2]\
    \ & u & ~l)));\n      for(auto z : get)\n        cost += 1ll << (popcount((z &\
    \ g_tmp[0]) | (~z & g_tmp[1])));\n      if (chmin(opt_cost, cost))\n        g\
    \ = g_tmp;\n    }\n  }\n\n  void add(int l, int u, T x) {\n    ull tar = (g[0]\
    \ & ~u) | (g[1] & l) | (g[2] & u & ~l);\n    ull inv = l | (g[1] & u & ~l);\n\
    \    enumerate_subset(tar, [&](ull msk) {\n      f[msk ^ inv] += (popcount((~u\
    \ | l) & msk) % 2 == 1 ? -x : x);\n    });\n  };\n  T get(int l) {\n    T s =\
    \ 0;\n    ull tar = (l & g[0]) | (~l & g[1]);\n    enumerate_subset(tar, [&](ull\
    \ msk) {\n      s += f[msk ^ l];\n    });\n    return s;\n  };\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/dynamic_SOS.cpp
  requiredBy: []
  timestamp: '2026-05-09 01:48:26+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/dynamic_SOS.cpp
layout: document
redirect_from:
- /library/setfunc/dynamic_SOS.cpp
- /library/setfunc/dynamic_SOS.cpp.html
title: setfunc/dynamic_SOS.cpp
---
