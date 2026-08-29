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
  bundledCode: "#line 1 \"numtheory/quotient_floor.cpp\"\nstruct quotient_floor {\n\
    \  const ll n;\n  ll m, x, sz;\n  quotient_floor(ll _n) : n(_n) {\n    x = sqrtl(n);\n\
    \    while(x * (x + 1) <= n) x++;\n    m = n / x;\n    sz = (x - 1) + m;\n  }\n\
    \n  ll Q(ll i) { return i < m ? i + 1 : n / (m - i + x - 1); }\n  ll L(ll q) {\
    \ return n / (q + 1); }\n  ll R(ll q) { return n / q; }\n  ll id(ll q) { return\
    \ q <= m ? q - 1 : sz - n / q; };\n  ll size() { return sz; }\n  auto Qs() {\n\
    \    return views::iota(0ll, sz) | views::transform([&](ll i) { return Q(i); });\n\
    \  }\n};\n"
  code: "struct quotient_floor {\n  const ll n;\n  ll m, x, sz;\n  quotient_floor(ll\
    \ _n) : n(_n) {\n    x = sqrtl(n);\n    while(x * (x + 1) <= n) x++;\n    m =\
    \ n / x;\n    sz = (x - 1) + m;\n  }\n\n  ll Q(ll i) { return i < m ? i + 1 :\
    \ n / (m - i + x - 1); }\n  ll L(ll q) { return n / (q + 1); }\n  ll R(ll q) {\
    \ return n / q; }\n  ll id(ll q) { return q <= m ? q - 1 : sz - n / q; };\n  ll\
    \ size() { return sz; }\n  auto Qs() {\n    return views::iota(0ll, sz) | views::transform([&](ll\
    \ i) { return Q(i); });\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/quotient_floor.cpp
  requiredBy: []
  timestamp: '2026-08-29 09:56:45+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numtheory/quotient_floor.cpp
layout: document
redirect_from:
- /library/numtheory/quotient_floor.cpp
- /library/numtheory/quotient_floor.cpp.html
title: numtheory/quotient_floor.cpp
---
