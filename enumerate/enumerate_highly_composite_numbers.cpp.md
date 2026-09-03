---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest_enumerate_highly_composite_numbers.test.cpp
    title: test/mytest_enumerate_highly_composite_numbers.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/enumerate_highly_composite_numbers.cpp\"\ntemplate<typename\
    \ F>\nrequires invocable<F, ll, vector<pair<int, int>>>\nvoid enumerate_highly_composite_numbers(ll\
    \ U, F f) {\n  static vi ps;\n  if (ps.empty())\n    primes(64, [](int p) { ps.eb(p);\
    \ });\n\n  auto dfs = [&](ll prod, vc<pii> pfs, auto &self) -> void {\n    f(prod,\
    \ pfs);\n\n    int p = ps[ssize(pfs)];\n    int lim = pfs.empty() ? INT_MAX :\
    \ pfs.back().second;\n    pfs.eb(p, 0);\n    while((__int128)prod * p < U and\
    \ pfs.back().second < lim) {\n      pfs.back().second += 1, prod *= p;\n     \
    \ self(prod, pfs, self);\n    }\n  };\n  dfs(1, {}, dfs);\n}\n"
  code: "template<typename F>\nrequires invocable<F, ll, vector<pair<int, int>>>\n\
    void enumerate_highly_composite_numbers(ll U, F f) {\n  static vi ps;\n  if (ps.empty())\n\
    \    primes(64, [](int p) { ps.eb(p); });\n\n  auto dfs = [&](ll prod, vc<pii>\
    \ pfs, auto &self) -> void {\n    f(prod, pfs);\n\n    int p = ps[ssize(pfs)];\n\
    \    int lim = pfs.empty() ? INT_MAX : pfs.back().second;\n    pfs.eb(p, 0);\n\
    \    while((__int128)prod * p < U and pfs.back().second < lim) {\n      pfs.back().second\
    \ += 1, prod *= p;\n      self(prod, pfs, self);\n    }\n  };\n  dfs(1, {}, dfs);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/enumerate_highly_composite_numbers.cpp
  requiredBy: []
  timestamp: '2026-09-03 11:20:30+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest_enumerate_highly_composite_numbers.test.cpp
documentation_of: enumerate/enumerate_highly_composite_numbers.cpp
layout: document
redirect_from:
- /library/enumerate/enumerate_highly_composite_numbers.cpp
- /library/enumerate/enumerate_highly_composite_numbers.cpp.html
title: enumerate/enumerate_highly_composite_numbers.cpp
---
