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
  bundledCode: "#line 1 \"ds_problem/inversion_count.cpp\"\ntemplate<ranges::random_access_range\
    \ rng, class T = ranges::range_value_t<rng>>\nll inversion_count(rng R) {\n  if\
    \ (R.empty()) return 0;\n  ll f = 0;\n\n  vc<T> tmp(ssize(R));\n  auto dc = [&](int\
    \ l, int r, auto &self) -> void {\n    if (l + 1 == r) return;\n    int mid =\
    \ (l + r) / 2;\n    self(l, mid, self);\n    self(mid, r, self);\n    {\n    \
    \  int i = l, j = mid, k = l;\n      while(i < mid and j < r) {\n        if (R[i]\
    \ <= R[j]) tmp[k++] = R[i++];\n        else tmp[k++] = R[j++], f += mid - i;\n\
    \      }\n      while(i < mid) tmp[k++] = R[i++];\n      while(j < r) tmp[k++]\
    \ = R[j++];\n    }\n    for(int i = l; i < r; i++)\n      R[i] = tmp[i];\n  };\n\
    \n  dc(0, ssize(R), dc);\n\n  return f;\n}\n"
  code: "template<ranges::random_access_range rng, class T = ranges::range_value_t<rng>>\n\
    ll inversion_count(rng R) {\n  if (R.empty()) return 0;\n  ll f = 0;\n\n  vc<T>\
    \ tmp(ssize(R));\n  auto dc = [&](int l, int r, auto &self) -> void {\n    if\
    \ (l + 1 == r) return;\n    int mid = (l + r) / 2;\n    self(l, mid, self);\n\
    \    self(mid, r, self);\n    {\n      int i = l, j = mid, k = l;\n      while(i\
    \ < mid and j < r) {\n        if (R[i] <= R[j]) tmp[k++] = R[i++];\n        else\
    \ tmp[k++] = R[j++], f += mid - i;\n      }\n      while(i < mid) tmp[k++] = R[i++];\n\
    \      while(j < r) tmp[k++] = R[j++];\n    }\n    for(int i = l; i < r; i++)\n\
    \      R[i] = tmp[i];\n  };\n\n  dc(0, ssize(R), dc);\n\n  return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ds_problem/inversion_count.cpp
  requiredBy: []
  timestamp: '2026-08-31 15:15:01+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds_problem/inversion_count.cpp
layout: document
redirect_from:
- /library/ds_problem/inversion_count.cpp
- /library/ds_problem/inversion_count.cpp.html
title: ds_problem/inversion_count.cpp
---
