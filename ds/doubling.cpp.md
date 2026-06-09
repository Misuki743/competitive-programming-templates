---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki_1097.test.cpp
    title: test/yuki_1097.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/doubling.cpp\"\ntemplate<class T = int, typename F =\
    \ void*>\nstruct doubling {\n  vvi jp;\n\n  vvc<T> data;\n  T id;\n  F op;\n\n\
    \  doubling(int LOG, vi to) : jp(LOG) {\n    jp[0].swap(to);\n    for(int i =\
    \ 1; i < LOG; i++) {\n      jp[i] = jp[i - 1];\n      for(int &k : jp[i])\n  \
    \      if (k != -1)\n          k = jp[i - 1][k];\n    }\n  }\n\n  doubling(int\
    \ LOG, vi to, vc<T> init, T _id, F f)\n  requires R_invocable<T, F, T, T>\n  :\
    \ jp(LOG), data(LOG), id(_id), op(f) {\n    jp[0].swap(to), data[0].swap(init);\n\
    \    for(int i = 1; i < LOG; i++) {\n      jp[i] = jp[i - 1], data[i] = data[i\
    \ - 1];\n      for(int j = -1; int &k : jp[i]) {\n        j++;\n        if (k\
    \ != -1) {\n          if (jp[i - 1][k] != -1)\n            data[i][j] = op(data[i][j],\
    \ data[i - 1][k]);\n          k = jp[i - 1][k];\n        }\n      }\n    }\n \
    \ }\n\n  int jump(int v, uint64_t k) {\n    for(; k > 0 and v != -1; k -= k &\
    \ (-k))\n      v = jp[countr_zero(k)][v];\n    return v;\n  }\n\n  pair<int, T>\
    \ jump(int v, uint64_t k)\n  requires (!same_as<F, void*>) {\n    T prod = id;\n\
    \    for(; k > 0 and v != -1; k -= k & (-k)) {\n      prod = op(prod, data[countr_zero(k)][v]);\n\
    \      v = jp[countr_zero(k)][v];\n    }\n    return pair(v, prod);\n  }\n\n \
    \ template<typename P>\n  requires R_invocable<bool, P, int>\n  int jump_while_true(int\
    \ v, P pred) {\n    if (!pred(v)) return v;\n    for(int i = ssize(jp) - 1; i\
    \ >= 0; i--) {\n      if (jp[i][v] == -1) continue;\n      if (pred(jp[i][v]))\n\
    \        v = jp[i][v];\n    }\n    return v;\n  }\n\n  template<typename P>\n\
    \  requires R_invocable<bool, P, int, T> && (!same_as<F, void*>)\n  pair<int,\
    \ T> jump_while_true(int v, P pred) {\n    T prod = id;\n    if (!pred(v, prod))\
    \ return pair(v, prod);\n    for(int i = ssize(jp) - 1; i >= 0; i--) {\n     \
    \ if (jp[i][v] == -1) continue;\n      if (T tmp = op(prod, data[i][v]); pred(jp[i][v],\
    \ tmp))\n        prod = tmp, v = jp[i][v];\n    }\n    return pair(v, prod);\n\
    \  }\n};\n"
  code: "template<class T = int, typename F = void*>\nstruct doubling {\n  vvi jp;\n\
    \n  vvc<T> data;\n  T id;\n  F op;\n\n  doubling(int LOG, vi to) : jp(LOG) {\n\
    \    jp[0].swap(to);\n    for(int i = 1; i < LOG; i++) {\n      jp[i] = jp[i -\
    \ 1];\n      for(int &k : jp[i])\n        if (k != -1)\n          k = jp[i - 1][k];\n\
    \    }\n  }\n\n  doubling(int LOG, vi to, vc<T> init, T _id, F f)\n  requires\
    \ R_invocable<T, F, T, T>\n  : jp(LOG), data(LOG), id(_id), op(f) {\n    jp[0].swap(to),\
    \ data[0].swap(init);\n    for(int i = 1; i < LOG; i++) {\n      jp[i] = jp[i\
    \ - 1], data[i] = data[i - 1];\n      for(int j = -1; int &k : jp[i]) {\n    \
    \    j++;\n        if (k != -1) {\n          if (jp[i - 1][k] != -1)\n       \
    \     data[i][j] = op(data[i][j], data[i - 1][k]);\n          k = jp[i - 1][k];\n\
    \        }\n      }\n    }\n  }\n\n  int jump(int v, uint64_t k) {\n    for(;\
    \ k > 0 and v != -1; k -= k & (-k))\n      v = jp[countr_zero(k)][v];\n    return\
    \ v;\n  }\n\n  pair<int, T> jump(int v, uint64_t k)\n  requires (!same_as<F, void*>)\
    \ {\n    T prod = id;\n    for(; k > 0 and v != -1; k -= k & (-k)) {\n      prod\
    \ = op(prod, data[countr_zero(k)][v]);\n      v = jp[countr_zero(k)][v];\n   \
    \ }\n    return pair(v, prod);\n  }\n\n  template<typename P>\n  requires R_invocable<bool,\
    \ P, int>\n  int jump_while_true(int v, P pred) {\n    if (!pred(v)) return v;\n\
    \    for(int i = ssize(jp) - 1; i >= 0; i--) {\n      if (jp[i][v] == -1) continue;\n\
    \      if (pred(jp[i][v]))\n        v = jp[i][v];\n    }\n    return v;\n  }\n\
    \n  template<typename P>\n  requires R_invocable<bool, P, int, T> && (!same_as<F,\
    \ void*>)\n  pair<int, T> jump_while_true(int v, P pred) {\n    T prod = id;\n\
    \    if (!pred(v, prod)) return pair(v, prod);\n    for(int i = ssize(jp) - 1;\
    \ i >= 0; i--) {\n      if (jp[i][v] == -1) continue;\n      if (T tmp = op(prod,\
    \ data[i][v]); pred(jp[i][v], tmp))\n        prod = tmp, v = jp[i][v];\n    }\n\
    \    return pair(v, prod);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/doubling.cpp
  requiredBy: []
  timestamp: '2026-06-09 21:54:42+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki_1097.test.cpp
documentation_of: ds/doubling.cpp
layout: document
title: ds/doubling.cpp
---

## constructor

`doubling(LOG, to)`: build a doulbing table with jump gap $2^i$ for all $0 \leq i < \text{LOG}$, all elements of $\text{to}$ should be integer between $-1$ and $\mid \text{to} \mid - 1$.

`doubling(LOG, to, init, id, f)`: build a doubling table with monoid(\text{id}, \text{f}) attached where $\text{init[v]}$ is the data attach on the edge from $\text{v}$ to $\text{to[v]}$

## functions

`jump(v, k)`: return the destination when jump from $v$ by $k$ steps. $-1$ if such destination does not exist

`jump(v, k)` (with monoid attached): also return the accumulated product of monoid along the jump trail

`jump_while_true(v, pred)`: return $u$ where $u$ is the last vertex such that $pred(u)$ is true. if $pred(v)$ is false, return $v$.

`jump_while_true(v, pred)` (with monoid attached): prediate also take the accumulated product along the path as argument. And return the accumulated product from $v$ to $u$.
