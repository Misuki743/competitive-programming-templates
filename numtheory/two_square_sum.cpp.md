---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/two_square_sum.test.cpp
    title: test/two_square_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://maspypy.github.io/library/mod/min_of_linear.hpp
    - https://maspypy.github.io/library/mod/min_of_linear_segments.hpp
  bundledCode: "#line 1 \"numtheory/two_square_sum.cpp\"\n//#include \"numtheory/factorize_pollard_rho.cpp\"\
    \n//#include \"numtheory/primitive_root.cpp\"\n//min of mod of linear come from\
    \ maspy's library\n//link: https://maspypy.github.io/library/mod/min_of_linear.hpp\n\
    //      https://maspypy.github.io/library/mod/min_of_linear_segments.hpp\n\n/*\n\
    ax + b (x>=0) \u304C\u6700\u5C0F\u3068\u306A\u308B\u3068\u3053\u308D\u306E\u60C5\
    \u5831\u3092\u8FD4\u3059\u3002\nprefix min \u3092\u66F4\u65B0\u3059\u308B x \u5168\
    \u4F53\u304C\u3001\u7B49\u5DEE\u6570\u5217\u306E\u548C\u96C6\u5408\u3002\u6B21\
    \u3092\u8FD4\u3059\u3002\n\u30FB\u7B49\u5DEE\u6570\u5217\u306E\u5883\u754C\u3068\
    \u306A\u308B x_0, x_1, ..., x_n\n\u30FB\u5404\u5883\u754C\u306E\u9593\u3067\u306E\
    \u4EA4\u5DEE dx_0, ..., dx_{n-1}\n*/\npair<vc<ll>, vc<ll>> min_of_linear_segments(ll\
    \ a, ll b, ll mod) {\n  assert(0 <= a && a < mod);\n  assert(0 <= b && b < mod);\n\
    \  vc<ll> X = {0};\n  vc<ll> DX;\n  ll g = gcd(a, mod);\n  a /= g, b /= g, mod\
    \ /= g;\n  // p/q <= (mod-a)/mod <= r/s\n  ll p = 0, q = 1, r = 1, s = 1;\n  ll\
    \ det_l = mod - a, det_r = a;\n  ll x = 0, y = b;\n\n  while (y) {\n    // upd\
    \ r/s\n    ll k = det_r / det_l;\n    det_r %= det_l;\n    if (det_r == 0) {\n\
    \      --k;\n      det_r = det_l;\n    }\n    r += k * p;\n    s += k * q;\n \
    \   while (1) {\n      ll k = max(0ll, ceilDiv(det_l - y, det_r));\n      if (det_l\
    \ - k * det_r <= 0) break;\n      det_l -= k * det_r;\n      p += k * r;\n   \
    \   q += k * s;\n      // p/q <= a/mod\n      // (aq - pmod) = det_l \u3092 y\
    \ \u304B\u3089\u5F15\u304F\n      k = y / det_l;\n      y -= k * det_l;\n    \
    \  x += q * k;\n      X.eb(x);\n      DX.eb(q);\n    }\n    k = det_l / det_r;\n\
    \    det_l -= k * det_r;\n    p += k * r;\n    q += k * s;\n    assert(min({p,\
    \ q, r, s}) >= 0);\n  }\n  return {X, DX};\n}\n\n// min_{x in [L, R)} (ax+b mod)\n\
    using i128 = __int128;\npair<i128, ll> min_of_linear(i128 L, i128 R, ll a, ll\
    \ b, ll mod) {\n  i128 n = R - L;\n  b = (b + a * L) % mod;\n  if (b < 0) b +=\
    \ mod;\n  auto [X, DX] = min_of_linear_segments(a, b, mod);\n  ll x = 0;\n  for\
    \ (int i = 0; i < int(X.size()) - 1; ++i) {\n    ll xl = X[i], xr = X[i + 1];\n\
    \    if (xr < n) {\n      x = xr;\n      continue;\n    }\n    x = xl + (n - 1\
    \ - x) / DX[i] * DX[i];\n    break;\n  }\n  ll y = (i128(a) * x + b) % mod;\n\
    \  return {L + x, y};\n}\n//\n\nstruct Gauss_int { ll a, b; };\nGauss_int operator+(Gauss_int\
    \ x, Gauss_int y) { return {x.a + y.a, x.b + y.b}; }\nGauss_int operator-(Gauss_int\
    \ x, Gauss_int y) { return {x.a - y.a, x.b - y.b}; }\nGauss_int operator*(Gauss_int\
    \ x, Gauss_int y) { return {x.a * y.a - x.b * y.b, x.b * y.a + x.a * y.b}; }\n\
    \nvc<pii> two_square_sum(ll n) {\n  if (n == 0) return {pii(0, 0)};\n  auto D\
    \ = factor(n);\n  ranges::sort(D);\n\n  vc<Gauss_int> sol;\n  sol.pb({-1, 0});\n\
    \  sol.pb({0, -1});\n  sol.pb({1, 0});\n  sol.pb({0, 1});\n  for(auto [l, r] :\
    \ equal_subarrays(D)) {\n    ll p = D[l];\n    int e = r - l;\n    if (p == 2)\
    \ {\n      Gauss_int y{1, 0};\n      for(int i = 0; i < e; i++)\n        y = y\
    \ * Gauss_int{1, 1};\n      for(auto &x : sol)\n        x = x * y;\n    } else\
    \ if (p % 4 == 1) {\n      ll i = modpow(primitiveRoot(p), (p - 1) / 4, p);\n\n\
    \      ll d;\n      {\n        ll U = sqrtl(p);\n        while(U * U < p) U++;\n\
    \        auto [d1, mn1] = min_of_linear(1, U, i, 0, p);\n        auto [d2, mn2]\
    \ = min_of_linear(1, U, p - i, 0, p);\n        d = mn1 < U ? d1 : d2;\n      }\n\
    \n      vc<Gauss_int> pw(e + 1);\n      pw[0] = {1, 0};\n      pw[1] = {(ll)((i128)(d)\
    \ * i % p), d};\n      for(int j = 1; j <= e; j++)\n        pw[j] = pw[j - 1]\
    \ * pw[1];\n\n      vc<Gauss_int> nxt;\n      for(auto x : sol) {\n        for(int\
    \ j = 0; j <= e; j++) {\n          auto y = pw[j];\n          auto z = pw[e -\
    \ j];\n          swap(z.a, z.b);\n          nxt.pb(x * y * z);\n        }\n  \
    \    }\n\n      sol.swap(nxt);\n\n    } else if (e % 2 == 0) {\n      ll q = 1;\n\
    \      for(int i = 0; i < e / 2; i++)\n        q *= p;\n      for(auto &x : sol)\n\
    \        x = x * Gauss_int{q, 0};\n    } else {\n      return {};\n    }\n  }\n\
    \n  vc<pii> res;\n  for(auto [a, b] : sol)\n    if (min(a, b) >= 0)\n      res.eb(a,\
    \ b);\n  return res;\n}\n"
  code: "//#include \"numtheory/factorize_pollard_rho.cpp\"\n//#include \"numtheory/primitive_root.cpp\"\
    \n//min of mod of linear come from maspy's library\n//link: https://maspypy.github.io/library/mod/min_of_linear.hpp\n\
    //      https://maspypy.github.io/library/mod/min_of_linear_segments.hpp\n\n/*\n\
    ax + b (x>=0) \u304C\u6700\u5C0F\u3068\u306A\u308B\u3068\u3053\u308D\u306E\u60C5\
    \u5831\u3092\u8FD4\u3059\u3002\nprefix min \u3092\u66F4\u65B0\u3059\u308B x \u5168\
    \u4F53\u304C\u3001\u7B49\u5DEE\u6570\u5217\u306E\u548C\u96C6\u5408\u3002\u6B21\
    \u3092\u8FD4\u3059\u3002\n\u30FB\u7B49\u5DEE\u6570\u5217\u306E\u5883\u754C\u3068\
    \u306A\u308B x_0, x_1, ..., x_n\n\u30FB\u5404\u5883\u754C\u306E\u9593\u3067\u306E\
    \u4EA4\u5DEE dx_0, ..., dx_{n-1}\n*/\npair<vc<ll>, vc<ll>> min_of_linear_segments(ll\
    \ a, ll b, ll mod) {\n  assert(0 <= a && a < mod);\n  assert(0 <= b && b < mod);\n\
    \  vc<ll> X = {0};\n  vc<ll> DX;\n  ll g = gcd(a, mod);\n  a /= g, b /= g, mod\
    \ /= g;\n  // p/q <= (mod-a)/mod <= r/s\n  ll p = 0, q = 1, r = 1, s = 1;\n  ll\
    \ det_l = mod - a, det_r = a;\n  ll x = 0, y = b;\n\n  while (y) {\n    // upd\
    \ r/s\n    ll k = det_r / det_l;\n    det_r %= det_l;\n    if (det_r == 0) {\n\
    \      --k;\n      det_r = det_l;\n    }\n    r += k * p;\n    s += k * q;\n \
    \   while (1) {\n      ll k = max(0ll, ceilDiv(det_l - y, det_r));\n      if (det_l\
    \ - k * det_r <= 0) break;\n      det_l -= k * det_r;\n      p += k * r;\n   \
    \   q += k * s;\n      // p/q <= a/mod\n      // (aq - pmod) = det_l \u3092 y\
    \ \u304B\u3089\u5F15\u304F\n      k = y / det_l;\n      y -= k * det_l;\n    \
    \  x += q * k;\n      X.eb(x);\n      DX.eb(q);\n    }\n    k = det_l / det_r;\n\
    \    det_l -= k * det_r;\n    p += k * r;\n    q += k * s;\n    assert(min({p,\
    \ q, r, s}) >= 0);\n  }\n  return {X, DX};\n}\n\n// min_{x in [L, R)} (ax+b mod)\n\
    using i128 = __int128;\npair<i128, ll> min_of_linear(i128 L, i128 R, ll a, ll\
    \ b, ll mod) {\n  i128 n = R - L;\n  b = (b + a * L) % mod;\n  if (b < 0) b +=\
    \ mod;\n  auto [X, DX] = min_of_linear_segments(a, b, mod);\n  ll x = 0;\n  for\
    \ (int i = 0; i < int(X.size()) - 1; ++i) {\n    ll xl = X[i], xr = X[i + 1];\n\
    \    if (xr < n) {\n      x = xr;\n      continue;\n    }\n    x = xl + (n - 1\
    \ - x) / DX[i] * DX[i];\n    break;\n  }\n  ll y = (i128(a) * x + b) % mod;\n\
    \  return {L + x, y};\n}\n//\n\nstruct Gauss_int { ll a, b; };\nGauss_int operator+(Gauss_int\
    \ x, Gauss_int y) { return {x.a + y.a, x.b + y.b}; }\nGauss_int operator-(Gauss_int\
    \ x, Gauss_int y) { return {x.a - y.a, x.b - y.b}; }\nGauss_int operator*(Gauss_int\
    \ x, Gauss_int y) { return {x.a * y.a - x.b * y.b, x.b * y.a + x.a * y.b}; }\n\
    \nvc<pii> two_square_sum(ll n) {\n  if (n == 0) return {pii(0, 0)};\n  auto D\
    \ = factor(n);\n  ranges::sort(D);\n\n  vc<Gauss_int> sol;\n  sol.pb({-1, 0});\n\
    \  sol.pb({0, -1});\n  sol.pb({1, 0});\n  sol.pb({0, 1});\n  for(auto [l, r] :\
    \ equal_subarrays(D)) {\n    ll p = D[l];\n    int e = r - l;\n    if (p == 2)\
    \ {\n      Gauss_int y{1, 0};\n      for(int i = 0; i < e; i++)\n        y = y\
    \ * Gauss_int{1, 1};\n      for(auto &x : sol)\n        x = x * y;\n    } else\
    \ if (p % 4 == 1) {\n      ll i = modpow(primitiveRoot(p), (p - 1) / 4, p);\n\n\
    \      ll d;\n      {\n        ll U = sqrtl(p);\n        while(U * U < p) U++;\n\
    \        auto [d1, mn1] = min_of_linear(1, U, i, 0, p);\n        auto [d2, mn2]\
    \ = min_of_linear(1, U, p - i, 0, p);\n        d = mn1 < U ? d1 : d2;\n      }\n\
    \n      vc<Gauss_int> pw(e + 1);\n      pw[0] = {1, 0};\n      pw[1] = {(ll)((i128)(d)\
    \ * i % p), d};\n      for(int j = 1; j <= e; j++)\n        pw[j] = pw[j - 1]\
    \ * pw[1];\n\n      vc<Gauss_int> nxt;\n      for(auto x : sol) {\n        for(int\
    \ j = 0; j <= e; j++) {\n          auto y = pw[j];\n          auto z = pw[e -\
    \ j];\n          swap(z.a, z.b);\n          nxt.pb(x * y * z);\n        }\n  \
    \    }\n\n      sol.swap(nxt);\n\n    } else if (e % 2 == 0) {\n      ll q = 1;\n\
    \      for(int i = 0; i < e / 2; i++)\n        q *= p;\n      for(auto &x : sol)\n\
    \        x = x * Gauss_int{q, 0};\n    } else {\n      return {};\n    }\n  }\n\
    \n  vc<pii> res;\n  for(auto [a, b] : sol)\n    if (min(a, b) >= 0)\n      res.eb(a,\
    \ b);\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/two_square_sum.cpp
  requiredBy: []
  timestamp: '2026-04-03 17:54:56+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/two_square_sum.test.cpp
documentation_of: numtheory/two_square_sum.cpp
layout: document
redirect_from:
- /library/numtheory/two_square_sum.cpp
- /library/numtheory/two_square_sum.cpp.html
title: numtheory/two_square_sum.cpp
---
