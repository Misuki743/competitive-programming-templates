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
  bundledCode: "#line 1 \"linalg/characteristic_polynomial.cpp\"\ntemplate<class Mint>\n\
    array<Mint, 2> operator+(array<Mint, 2> a, array<Mint, 2> b) {\n  return {a[0]\
    \ + b[0], a[1] + b[1]};\n}\ntemplate<class Mint>\narray<Mint, 2> operator-(array<Mint,\
    \ 2> a, array<Mint, 2> b) {\n  return {a[0] - b[0], a[1] - b[1]};\n}\ntemplate<class\
    \ Mint>\narray<Mint, 2> operator*(Mint m, array<Mint, 2> b) {\n  return {m * b[0],\
    \ m * b[1]};\n}\n\ntemplate<class Mint>\nvc<Mint> characteristic_polynomial(vvc<Mint>\
    \ M) {\n  if (M.empty()) return {1};\n  assert(size(M) == size(M[0]));\n  const\
    \ int N = size(M);\n\n  vc P(N, vc<array<Mint, 2>>(N));\n  for(int i = 0; i <\
    \ N; i++)\n    for(int j = 0; j < N; j++)\n      P[i][j] = {-M[i][j], i == j};\n\
    \n  //reduce to lower Hessenberg Matrix\n  for(int r = 0; r < N - 2; r++) {\n\
    \    const int c = r + 1;\n    int i = c;\n    while(i < N and P[r][i][0] == 0)\
    \ i++;\n    if (i == N) continue;\n    if (i > c) {\n      P[i].swap(P[c]);\n\
    \      for(int j = 0; j < N; j++)\n        swap(P[j][i], P[j][c]);\n    }\n  \
    \  Mint inv = P[r][c][0].inverse();\n    for(int j = c + 1; j < N; j++) {\n  \
    \    Mint R = -inv * P[r][j][0];\n      for(int k = 0; k < N; k++)\n        P[k][j]\
    \ = P[k][j] + R * P[k][c];\n    }\n\n    for(int j = r + 2; j < N; j++) {\n  \
    \    Mint R = -P[r + 1][j][1];\n      for(int k = 0; k < N; k++)\n        P[r\
    \ + 1][k] = P[r + 1][k] + R * P[j][k];\n    }\n  }\n\n  auto add = [&](vector<Mint>\
    \ a, vector<Mint> b) {\n    if (ssize(a) < ssize(b)) a.resize(size(b));\n    for(int\
    \ i = 0; i < ssize(b); i++)\n      a[i] += b[i];\n    return a;\n  };\n  auto\
    \ mul = [&](vector<Mint> &a, array<Mint, 2> b) {\n    vector<Mint> c(ssize(a)\
    \ + 1);\n    for(int i = 0; i < ssize(a); i++) {\n      c[i] += a[i] * b[0];\n\
    \      c[i + 1] += a[i] * b[1];\n    }\n    return c;\n  };\n  auto neg = [&](array<Mint,\
    \ 2> a) { return array<Mint, 2>{-a[0], -a[1]}; };\n\n  //DP\n  vc dp(1, vc<Mint>{1});\n\
    \  for(int i = 0; i < N - 1; i++) {\n    vc<vc<Mint>> nxt(i + 2);\n    for(int\
    \ j = 0; j < ssize(dp); j++) {\n      nxt[j] = add(nxt[j], mul(dp[j], P[i][i +\
    \ 1]));\n      nxt[i + 1] = add(nxt[i + 1], mul(dp[j], (i - j) % 2 ? neg(P[i][j])\
    \ : P[i][j]));\n    }\n    dp.swap(nxt);\n  }\n\n  vc<Mint> C = {0};\n  for(int\
    \ j = 0; j < N; j++)\n    C = add(C, mul(dp[j], (N - 1 - j) % 2 ? neg(P[N - 1][j])\
    \ : P[N - 1][j]));\n\n  return C;\n}\n"
  code: "template<class Mint>\narray<Mint, 2> operator+(array<Mint, 2> a, array<Mint,\
    \ 2> b) {\n  return {a[0] + b[0], a[1] + b[1]};\n}\ntemplate<class Mint>\narray<Mint,\
    \ 2> operator-(array<Mint, 2> a, array<Mint, 2> b) {\n  return {a[0] - b[0], a[1]\
    \ - b[1]};\n}\ntemplate<class Mint>\narray<Mint, 2> operator*(Mint m, array<Mint,\
    \ 2> b) {\n  return {m * b[0], m * b[1]};\n}\n\ntemplate<class Mint>\nvc<Mint>\
    \ characteristic_polynomial(vvc<Mint> M) {\n  if (M.empty()) return {1};\n  assert(size(M)\
    \ == size(M[0]));\n  const int N = size(M);\n\n  vc P(N, vc<array<Mint, 2>>(N));\n\
    \  for(int i = 0; i < N; i++)\n    for(int j = 0; j < N; j++)\n      P[i][j] =\
    \ {-M[i][j], i == j};\n\n  //reduce to lower Hessenberg Matrix\n  for(int r =\
    \ 0; r < N - 2; r++) {\n    const int c = r + 1;\n    int i = c;\n    while(i\
    \ < N and P[r][i][0] == 0) i++;\n    if (i == N) continue;\n    if (i > c) {\n\
    \      P[i].swap(P[c]);\n      for(int j = 0; j < N; j++)\n        swap(P[j][i],\
    \ P[j][c]);\n    }\n    Mint inv = P[r][c][0].inverse();\n    for(int j = c +\
    \ 1; j < N; j++) {\n      Mint R = -inv * P[r][j][0];\n      for(int k = 0; k\
    \ < N; k++)\n        P[k][j] = P[k][j] + R * P[k][c];\n    }\n\n    for(int j\
    \ = r + 2; j < N; j++) {\n      Mint R = -P[r + 1][j][1];\n      for(int k = 0;\
    \ k < N; k++)\n        P[r + 1][k] = P[r + 1][k] + R * P[j][k];\n    }\n  }\n\n\
    \  auto add = [&](vector<Mint> a, vector<Mint> b) {\n    if (ssize(a) < ssize(b))\
    \ a.resize(size(b));\n    for(int i = 0; i < ssize(b); i++)\n      a[i] += b[i];\n\
    \    return a;\n  };\n  auto mul = [&](vector<Mint> &a, array<Mint, 2> b) {\n\
    \    vector<Mint> c(ssize(a) + 1);\n    for(int i = 0; i < ssize(a); i++) {\n\
    \      c[i] += a[i] * b[0];\n      c[i + 1] += a[i] * b[1];\n    }\n    return\
    \ c;\n  };\n  auto neg = [&](array<Mint, 2> a) { return array<Mint, 2>{-a[0],\
    \ -a[1]}; };\n\n  //DP\n  vc dp(1, vc<Mint>{1});\n  for(int i = 0; i < N - 1;\
    \ i++) {\n    vc<vc<Mint>> nxt(i + 2);\n    for(int j = 0; j < ssize(dp); j++)\
    \ {\n      nxt[j] = add(nxt[j], mul(dp[j], P[i][i + 1]));\n      nxt[i + 1] =\
    \ add(nxt[i + 1], mul(dp[j], (i - j) % 2 ? neg(P[i][j]) : P[i][j]));\n    }\n\
    \    dp.swap(nxt);\n  }\n\n  vc<Mint> C = {0};\n  for(int j = 0; j < N; j++)\n\
    \    C = add(C, mul(dp[j], (N - 1 - j) % 2 ? neg(P[N - 1][j]) : P[N - 1][j]));\n\
    \n  return C;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/characteristic_polynomial.cpp
  requiredBy: []
  timestamp: '2026-03-22 16:32:23+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/characteristic_polynomial.cpp
layout: document
redirect_from:
- /library/linalg/characteristic_polynomial.cpp
- /library/linalg/characteristic_polynomial.cpp.html
title: linalg/characteristic_polynomial.cpp
---
