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
  bundledCode: "#line 1 \"setfunc/fast_zeta_transform.cpp\"\n//note: to change to\
    \ poset, flip the condition inside if statement. \n\ntemplate<class T>\nvoid fast_zeta_transform(vector<T>\
    \ &vec, bool inverse = false) {\n  for(int i = 0; (1 << i) < (int)vec.size();\
    \ i++)\n    for(int j = 0; j < (int)vec.size(); j++)\n      if (j >> i & 1)\n\
    \        vec[j] += (inverse ? -vec[j ^ (1 << i)] : vec[j ^ (1 << i)]);\n}\n"
  code: "//note: to change to poset, flip the condition inside if statement. \n\n\
    template<class T>\nvoid fast_zeta_transform(vector<T> &vec, bool inverse = false)\
    \ {\n  for(int i = 0; (1 << i) < (int)vec.size(); i++)\n    for(int j = 0; j <\
    \ (int)vec.size(); j++)\n      if (j >> i & 1)\n        vec[j] += (inverse ? -vec[j\
    \ ^ (1 << i)] : vec[j ^ (1 << i)]);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/fast_zeta_transform.cpp
  requiredBy: []
  timestamp: '2026-06-06 23:34:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/fast_zeta_transform.cpp
layout: document
redirect_from:
- /library/setfunc/fast_zeta_transform.cpp
- /library/setfunc/fast_zeta_transform.cpp.html
title: setfunc/fast_zeta_transform.cpp
---
