---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/matrix_rank_mod_2.test.cpp
    title: test/matrix_rank_mod_2.test.cpp
  - icon: ':x:'
    path: test/yuki_2895_2.test.cpp
    title: test/yuki_2895_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/xor_basis_bitset.cpp\"\ntemplate<int W>\nstruct xor_basis\
    \ {\n  int nxt = 0;\n  bitset<W> *B[W] = {}, *ids[W] = {};\n\n  pair<bool, bitset<W>>\
    \ insert(bitset<W> x) {\n    bitset<W> v = {};\n    for(int i = 0; i < W; i++)\
    \ {\n      if (x[i]) {\n        if (!B[i]) {\n          v[nxt++] = true;\n   \
    \       B[i] = new bitset<W>(x);\n          ids[i] = new bitset<W>(v);\n     \
    \     return pair(true, bitset<W>(0));\n        }\n        x ^= *B[i], v ^= *ids[i];\n\
    \      }\n    }\n    return pair(false, v);\n  }\n\n  pair<bool, bitset<W>> query(bitset<W>\
    \ x) {\n    bitset<W> v = {};\n    for(int i = 0; i < W; i++)\n      if (B[i]\
    \ and x[i])\n        x ^= *B[i], v ^= *ids[i];\n    return pair(x.none(), x.none()\
    \ ? v : bitset<W>(0));\n  }\n};\n"
  code: "template<int W>\nstruct xor_basis {\n  int nxt = 0;\n  bitset<W> *B[W] =\
    \ {}, *ids[W] = {};\n\n  pair<bool, bitset<W>> insert(bitset<W> x) {\n    bitset<W>\
    \ v = {};\n    for(int i = 0; i < W; i++) {\n      if (x[i]) {\n        if (!B[i])\
    \ {\n          v[nxt++] = true;\n          B[i] = new bitset<W>(x);\n        \
    \  ids[i] = new bitset<W>(v);\n          return pair(true, bitset<W>(0));\n  \
    \      }\n        x ^= *B[i], v ^= *ids[i];\n      }\n    }\n    return pair(false,\
    \ v);\n  }\n\n  pair<bool, bitset<W>> query(bitset<W> x) {\n    bitset<W> v =\
    \ {};\n    for(int i = 0; i < W; i++)\n      if (B[i] and x[i])\n        x ^=\
    \ *B[i], v ^= *ids[i];\n    return pair(x.none(), x.none() ? v : bitset<W>(0));\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/xor_basis_bitset.cpp
  requiredBy: []
  timestamp: '2026-03-22 16:32:23+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/matrix_rank_mod_2.test.cpp
  - test/yuki_2895_2.test.cpp
documentation_of: linalg/xor_basis_bitset.cpp
layout: document
redirect_from:
- /library/linalg/xor_basis_bitset.cpp
- /library/linalg/xor_basis_bitset.cpp.html
title: linalg/xor_basis_bitset.cpp
---
