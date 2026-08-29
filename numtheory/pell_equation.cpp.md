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
  bundledCode: "#line 1 \"numtheory/pell_equation.cpp\"\nvi continuous_fraction_of_sqrt(int\
    \ n) {\n  int a = 1, b = n, c = 0;\n  vi v;\n  while(ssize(v) <= 1 or (ull)v.back()\
    \ != 2 * kth_root(n, 2)) {\n    int m = (kth_root(b, 2) + c) / a;\n    v.eb(m);\n\
    \    c -= m * a;\n\n    int A = (b - c * c) / a, C = -c;\n    a = A, c = C;\n\
    \  }\n\n  return v;\n}\n\npair<__int128, __int128> expand(vi v) {\n  __int128\
    \ u = 1, d = v.back();\n  __int128 v0 = v[0];\n  v.erase(v.begin());\n  for(__int128\
    \ x : v | views::reverse | views::drop(1)) {\n    u += x * d;\n    swap(u, d);\n\
    \    __int128 g = gcd(u, d);\n    u /= g, d /= g;\n  }\n  u += d * v0;\n  __int128\
    \ g = gcd(u, d);\n  u /= g, d /= g;\n  return {u, d};\n}\n\n//x^2 - dy^2 = 1\n\
    pair<__int128, __int128> pell_equation_fundamental(int d) {\n  if (int s = kth_root(d,\
    \ 2); s * s == d)\n    return pii(-1, -1);\n\n  auto v = continuous_fraction_of_sqrt(d);\n\
    \  if (ssize(v) % 2 == 0)\n    for(int i = 1, n = ssize(v); i < n; i++)\n    \
    \  v.eb(v[i]);\n  v.pop_back();\n\n  return expand(v);\n}\n"
  code: "vi continuous_fraction_of_sqrt(int n) {\n  int a = 1, b = n, c = 0;\n  vi\
    \ v;\n  while(ssize(v) <= 1 or (ull)v.back() != 2 * kth_root(n, 2)) {\n    int\
    \ m = (kth_root(b, 2) + c) / a;\n    v.eb(m);\n    c -= m * a;\n\n    int A =\
    \ (b - c * c) / a, C = -c;\n    a = A, c = C;\n  }\n\n  return v;\n}\n\npair<__int128,\
    \ __int128> expand(vi v) {\n  __int128 u = 1, d = v.back();\n  __int128 v0 = v[0];\n\
    \  v.erase(v.begin());\n  for(__int128 x : v | views::reverse | views::drop(1))\
    \ {\n    u += x * d;\n    swap(u, d);\n    __int128 g = gcd(u, d);\n    u /= g,\
    \ d /= g;\n  }\n  u += d * v0;\n  __int128 g = gcd(u, d);\n  u /= g, d /= g;\n\
    \  return {u, d};\n}\n\n//x^2 - dy^2 = 1\npair<__int128, __int128> pell_equation_fundamental(int\
    \ d) {\n  if (int s = kth_root(d, 2); s * s == d)\n    return pii(-1, -1);\n\n\
    \  auto v = continuous_fraction_of_sqrt(d);\n  if (ssize(v) % 2 == 0)\n    for(int\
    \ i = 1, n = ssize(v); i < n; i++)\n      v.eb(v[i]);\n  v.pop_back();\n\n  return\
    \ expand(v);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/pell_equation.cpp
  requiredBy: []
  timestamp: '2026-08-29 09:56:45+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numtheory/pell_equation.cpp
layout: document
redirect_from:
- /library/numtheory/pell_equation.cpp
- /library/numtheory/pell_equation.cpp.html
title: numtheory/pell_equation.cpp
---
