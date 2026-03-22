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
  bundledCode: "#line 1 \"numtheory/AP_sqrt_heuristic.cpp\"\n//decompose {Ax + B mod\
    \ M, 0 <= x < N} into O(sqrt(M)) APs\nauto AP_sqrt_heuristic(ll A, ll B, ll N,\
    \ ll M) {\n  assert(A < M and B < M and N <= M);\n  ll S = sqrtl(M);\n  while(S\
    \ * S <= M) S++;\n\n  struct AP { ll A, B, N; };\n  vc<AP> sol;\n  if (N <= S)\
    \ {\n    for(ll i = 0, y = B; i < N; i++, y = (y + A >= M ? y + A - M : y + A))\n\
    \      sol.eb(0, y, 1);\n    return sol;\n  }\n\n  auto get = [&](ll n) { return\
    \ (A * n + B) % M; };\n\n  vll id(S, -1);\n  for(ll j = 0, y = B; ; j++, y = (y\
    \ + A >= M ? y + A - M : y + A)) {\n    if (id[y / S] == -1) {\n      id[y / S]\
    \ = j;\n    } else {\n      ll D = j - id[y / S];\n      ll A2 = A * D % M;\n\
    \      if (A2 > M / 2) A2 -= M;\n      for(ll i = id[y / S]; i < j; i++) {\n \
    \       for(ll k = i, B2 = get(k); k < N; B2 = get(k)) {\n          ll NMX = ceilDiv(N\
    \ - k, D);\n          ll N2 = [&]() {\n            if (A2 > 0) return ceilDiv(M\
    \ - B2, A2);\n            else if (A2 < 0) return ceilDiv(-1ll - B2, A2);\n  \
    \          else return N;\n          }();\n          chmin(N2, NMX);\n       \
    \   sol.eb(A2, B2, N2);\n          k += N2 * D;\n        }\n      }\n      for(ll\
    \ i = 0, B2 = B; i < id[y / S]; i++, B2 = (B2 + A >= M ? B2 + A - M : B2 + A))\n\
    \        sol.eb(0, B2, 1);\n      break;\n    }\n  }\n\n  return sol;\n}\n"
  code: "//decompose {Ax + B mod M, 0 <= x < N} into O(sqrt(M)) APs\nauto AP_sqrt_heuristic(ll\
    \ A, ll B, ll N, ll M) {\n  assert(A < M and B < M and N <= M);\n  ll S = sqrtl(M);\n\
    \  while(S * S <= M) S++;\n\n  struct AP { ll A, B, N; };\n  vc<AP> sol;\n  if\
    \ (N <= S) {\n    for(ll i = 0, y = B; i < N; i++, y = (y + A >= M ? y + A - M\
    \ : y + A))\n      sol.eb(0, y, 1);\n    return sol;\n  }\n\n  auto get = [&](ll\
    \ n) { return (A * n + B) % M; };\n\n  vll id(S, -1);\n  for(ll j = 0, y = B;\
    \ ; j++, y = (y + A >= M ? y + A - M : y + A)) {\n    if (id[y / S] == -1) {\n\
    \      id[y / S] = j;\n    } else {\n      ll D = j - id[y / S];\n      ll A2\
    \ = A * D % M;\n      if (A2 > M / 2) A2 -= M;\n      for(ll i = id[y / S]; i\
    \ < j; i++) {\n        for(ll k = i, B2 = get(k); k < N; B2 = get(k)) {\n    \
    \      ll NMX = ceilDiv(N - k, D);\n          ll N2 = [&]() {\n            if\
    \ (A2 > 0) return ceilDiv(M - B2, A2);\n            else if (A2 < 0) return ceilDiv(-1ll\
    \ - B2, A2);\n            else return N;\n          }();\n          chmin(N2,\
    \ NMX);\n          sol.eb(A2, B2, N2);\n          k += N2 * D;\n        }\n  \
    \    }\n      for(ll i = 0, B2 = B; i < id[y / S]; i++, B2 = (B2 + A >= M ? B2\
    \ + A - M : B2 + A))\n        sol.eb(0, B2, 1);\n      break;\n    }\n  }\n\n\
    \  return sol;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/AP_sqrt_heuristic.cpp
  requiredBy: []
  timestamp: '2026-03-22 16:32:23+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numtheory/AP_sqrt_heuristic.cpp
layout: document
redirect_from:
- /library/numtheory/AP_sqrt_heuristic.cpp
- /library/numtheory/AP_sqrt_heuristic.cpp.html
title: numtheory/AP_sqrt_heuristic.cpp
---
