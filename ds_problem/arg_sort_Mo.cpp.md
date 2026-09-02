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
  bundledCode: "#line 1 \"ds_problem/arg_sort_Mo.cpp\"\ntemplate<integral T>\nauto\
    \ arg_sort_Mo(vc<pair<T, T>> &v) {\n  int n = 1;\n  for(auto &[x, y] : v) chmax(n,\
    \ max(x, y));\n  int b = ceil_div(n, (int)kth_root(ssize(v) + 1, 2));\n  return\
    \ pair(\n    arg_sort(v, [b](const pii &pr) {\n      auto [x, y] = pr;\n     \
    \ return pii(x / b, x / b % 2 == 0 ? y : -y);\n    }), b);\n}\n"
  code: "template<integral T>\nauto arg_sort_Mo(vc<pair<T, T>> &v) {\n  int n = 1;\n\
    \  for(auto &[x, y] : v) chmax(n, max(x, y));\n  int b = ceil_div(n, (int)kth_root(ssize(v)\
    \ + 1, 2));\n  return pair(\n    arg_sort(v, [b](const pii &pr) {\n      auto\
    \ [x, y] = pr;\n      return pii(x / b, x / b % 2 == 0 ? y : -y);\n    }), b);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: ds_problem/arg_sort_Mo.cpp
  requiredBy: []
  timestamp: '2026-09-02 22:20:49+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds_problem/arg_sort_Mo.cpp
layout: document
redirect_from:
- /library/ds_problem/arg_sort_Mo.cpp
- /library/ds_problem/arg_sort_Mo.cpp.html
title: ds_problem/arg_sort_Mo.cpp
---
