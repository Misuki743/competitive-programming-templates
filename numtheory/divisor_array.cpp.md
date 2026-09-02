---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest_divisor_array.test.cpp
    title: test/mytest_divisor_array.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/divisor_array.cpp\"\ntemplate<int32_t C>\nclass\
    \ divisor_array {\n  using i32 = int32_t;\n\n  static inline array<i32, C + 1>\
    \ s = {};\n  static inline vector<i32> d;\n  static inline bool init = false;\n\
    \n  public: \n\n  static void initialize() {\n    if (init) return;\n    init\
    \ = true;\n    for(int i = 1; i < C; i++)\n      for(int j = i; j < C; j += i)\n\
    \        s[j]++;\n    for(int i = 1; i <= C; i++)\n      s[i] += s[i - 1];\n \
    \   d.resize(s[C]);\n    for(int i = C - 1; i >= 1; i--)\n      for(int j = i;\
    \ j < C; j += i)\n        d[--s[j]] = i;\n  }\n\n  static span<const i32> divisor(int\
    \ x) {\n    initialize();\n    return span(d.begin() + s[x], d.begin() + s[x +\
    \ 1]);\n  }\n};\n\n//auto divisor = &divisor_array<>::divisor;\n"
  code: "template<int32_t C>\nclass divisor_array {\n  using i32 = int32_t;\n\n  static\
    \ inline array<i32, C + 1> s = {};\n  static inline vector<i32> d;\n  static inline\
    \ bool init = false;\n\n  public: \n\n  static void initialize() {\n    if (init)\
    \ return;\n    init = true;\n    for(int i = 1; i < C; i++)\n      for(int j =\
    \ i; j < C; j += i)\n        s[j]++;\n    for(int i = 1; i <= C; i++)\n      s[i]\
    \ += s[i - 1];\n    d.resize(s[C]);\n    for(int i = C - 1; i >= 1; i--)\n   \
    \   for(int j = i; j < C; j += i)\n        d[--s[j]] = i;\n  }\n\n  static span<const\
    \ i32> divisor(int x) {\n    initialize();\n    return span(d.begin() + s[x],\
    \ d.begin() + s[x + 1]);\n  }\n};\n\n//auto divisor = &divisor_array<>::divisor;\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/divisor_array.cpp
  requiredBy: []
  timestamp: '2026-07-15 01:05:29+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest_divisor_array.test.cpp
documentation_of: numtheory/divisor_array.cpp
layout: document
redirect_from:
- /library/numtheory/divisor_array.cpp
- /library/numtheory/divisor_array.cpp.html
title: numtheory/divisor_array.cpp
---
