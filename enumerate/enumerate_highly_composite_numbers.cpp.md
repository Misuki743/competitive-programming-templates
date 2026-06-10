---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest_enumerate_highly_composite_numbers.test.cpp
    title: test/mytest_enumerate_highly_composite_numbers.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/enumerate_highly_composite_numbers.cpp\"\ntemplate<typename\
    \ F>\nrequires invocable<F, ll, vector<pair<int, int>>>\nvoid enumerate_highly_composite_numbers(ll\
    \ U, F f) {\n  prime_table<64> pt;\n\n  auto dfs = [&](ll prod, vc<pii> fac, auto\
    \ &self) -> void {\n    f(prod, fac);\n\n    int p = pt.prime_array()[ssize(fac)];\n\
    \    int lim = fac.empty() ? INT_MAX : fac.back().second;\n    fac.eb(p, 0);\n\
    \    while((__int128)prod * p < U and fac.back().second < lim) {\n      fac.back().second\
    \ += 1, prod *= p;\n      self(prod, fac, self);\n    }\n  };\n  dfs(1, {}, dfs);\n\
    }\n"
  code: "template<typename F>\nrequires invocable<F, ll, vector<pair<int, int>>>\n\
    void enumerate_highly_composite_numbers(ll U, F f) {\n  prime_table<64> pt;\n\n\
    \  auto dfs = [&](ll prod, vc<pii> fac, auto &self) -> void {\n    f(prod, fac);\n\
    \n    int p = pt.prime_array()[ssize(fac)];\n    int lim = fac.empty() ? INT_MAX\
    \ : fac.back().second;\n    fac.eb(p, 0);\n    while((__int128)prod * p < U and\
    \ fac.back().second < lim) {\n      fac.back().second += 1, prod *= p;\n     \
    \ self(prod, fac, self);\n    }\n  };\n  dfs(1, {}, dfs);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/enumerate_highly_composite_numbers.cpp
  requiredBy: []
  timestamp: '2026-06-10 20:53:28+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest_enumerate_highly_composite_numbers.test.cpp
documentation_of: enumerate/enumerate_highly_composite_numbers.cpp
layout: document
redirect_from:
- /library/enumerate/enumerate_highly_composite_numbers.cpp
- /library/enumerate/enumerate_highly_composite_numbers.cpp.html
title: enumerate/enumerate_highly_composite_numbers.cpp
---
