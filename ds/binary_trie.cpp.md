---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/set_xor_min.test.cpp
    title: test/set_xor_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/binary_trie.cpp\"\ntemplate<int W, bool duplicate = false>\n\
    struct binary_trie {\n  vc<array<int32_t, 2>> nxt;\n  vi cnt;\n\n  binary_trie(int\
    \ size = 1) : nxt(1, {-1, -1}), cnt(1) {\n    nxt.reserve(size), cnt.reserve(size);\n\
    \  }\n\n  int count(ull x) {\n    int v = 0;\n    for(int i = W - 1; i >= 0; i--)\
    \ {\n      v = nxt[v][x >> i & 1];\n      if (v == -1) return 0;\n    }\n    return\
    \ cnt[v];\n  }\n\n  void insert(ull x) {\n    if constexpr (!duplicate)\n    \
    \  if (count(x))\n        return;\n    int v = 0;\n    cnt[0]++;\n    for(int\
    \ i = W - 1; i >= 0; i--) {\n      if (nxt[v][x >> i & 1] == -1) {\n        nxt[v][x\
    \ >> i & 1] = ssize(nxt);\n        nxt.pb({-1, -1}), cnt.eb();\n      }\n    \
    \  v = nxt[v][x >> i & 1], cnt[v]++;\n    }\n  }\n\n  void erase(ull x) {\n  \
    \  if (!count(x)) return;\n    int v = 0;\n    cnt[0]--;\n    for(int i = W -\
    \ 1; i >= 0; i--)\n      v = nxt[v][x >> i & 1], cnt[v]--;\n  }\n\n  ull query_min(ull\
    \ XOR = 0ull) {\n    assert(cnt[0] > 0);\n    ull ans = 0;\n    for(int i = W\
    \ - 1, v = 0; i >= 0; i--) {\n      ull to = XOR >> i & 1;\n      if (nxt[v][to]\
    \ != -1 and cnt[nxt[v][to]] > 0)\n        v = nxt[v][to];\n      else\n      \
    \  ans |= 1ull << i, v = nxt[v][to ^ 1];\n    }\n    return ans;\n  }\n\n  ull\
    \ kth(int k, ull XOR = 0ull) {\n    assert(cnt[0] > k);\n    ull ans = 0;\n  \
    \  for(int i = W - 1, v = 0; i >= 0; i--) {\n      ull to = XOR >> i & 1;\n  \
    \    if (nxt[v][to] != -1 and cnt[nxt[v][to]] <= k)\n         k -= cnt[nxt[v][to]],\
    \ to ^= 1;\n      else if (nxt[v][to] == -1)\n        to ^= 1;\n      v = nxt[v][to],\
    \ ans |= to << i;\n    }\n    return ans ^ XOR;\n  }\n};\n"
  code: "template<int W, bool duplicate = false>\nstruct binary_trie {\n  vc<array<int32_t,\
    \ 2>> nxt;\n  vi cnt;\n\n  binary_trie(int size = 1) : nxt(1, {-1, -1}), cnt(1)\
    \ {\n    nxt.reserve(size), cnt.reserve(size);\n  }\n\n  int count(ull x) {\n\
    \    int v = 0;\n    for(int i = W - 1; i >= 0; i--) {\n      v = nxt[v][x >>\
    \ i & 1];\n      if (v == -1) return 0;\n    }\n    return cnt[v];\n  }\n\n  void\
    \ insert(ull x) {\n    if constexpr (!duplicate)\n      if (count(x))\n      \
    \  return;\n    int v = 0;\n    cnt[0]++;\n    for(int i = W - 1; i >= 0; i--)\
    \ {\n      if (nxt[v][x >> i & 1] == -1) {\n        nxt[v][x >> i & 1] = ssize(nxt);\n\
    \        nxt.pb({-1, -1}), cnt.eb();\n      }\n      v = nxt[v][x >> i & 1], cnt[v]++;\n\
    \    }\n  }\n\n  void erase(ull x) {\n    if (!count(x)) return;\n    int v =\
    \ 0;\n    cnt[0]--;\n    for(int i = W - 1; i >= 0; i--)\n      v = nxt[v][x >>\
    \ i & 1], cnt[v]--;\n  }\n\n  ull query_min(ull XOR = 0ull) {\n    assert(cnt[0]\
    \ > 0);\n    ull ans = 0;\n    for(int i = W - 1, v = 0; i >= 0; i--) {\n    \
    \  ull to = XOR >> i & 1;\n      if (nxt[v][to] != -1 and cnt[nxt[v][to]] > 0)\n\
    \        v = nxt[v][to];\n      else\n        ans |= 1ull << i, v = nxt[v][to\
    \ ^ 1];\n    }\n    return ans;\n  }\n\n  ull kth(int k, ull XOR = 0ull) {\n \
    \   assert(cnt[0] > k);\n    ull ans = 0;\n    for(int i = W - 1, v = 0; i >=\
    \ 0; i--) {\n      ull to = XOR >> i & 1;\n      if (nxt[v][to] != -1 and cnt[nxt[v][to]]\
    \ <= k)\n         k -= cnt[nxt[v][to]], to ^= 1;\n      else if (nxt[v][to] ==\
    \ -1)\n        to ^= 1;\n      v = nxt[v][to], ans |= to << i;\n    }\n    return\
    \ ans ^ XOR;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/binary_trie.cpp
  requiredBy: []
  timestamp: '2026-09-26 15:33:30+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/set_xor_min.test.cpp
documentation_of: ds/binary_trie.cpp
layout: document
redirect_from:
- /library/ds/binary_trie.cpp
- /library/ds/binary_trie.cpp.html
title: ds/binary_trie.cpp
---
