---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/gcd_convolution.test.cpp
    title: test/gcd_convolution.test.cpp
  - icon: ':x:'
    path: test/lcm_convolution.test.cpp
    title: test/lcm_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest_linear_sieve.test.cpp
    title: test/mytest_linear_sieve.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest_mu_array.test.cpp
    title: test/mytest_mu_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest_phi_array.test.cpp
    title: test/mytest_phi_array.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/linear_sieve.cpp\"\ntemplate<int32_t C>\nclass\
    \ linear_sieve {\n\n  static inline array<int, C> mpf = {};\n  static inline vi\
    \ prime;\n  static inline bool init = false;\n\n  static void initialize() {\n\
    \    if (init) return;\n    init = true;\n    if (C > 2)\n      iota(mpf.begin()\
    \ + 2, mpf.end(), 2);\n    for(int i = 2; i < C; i++) {\n      if (mpf[i] == i)\n\
    \        prime.emplace_back(i);\n      for(int64_t p : prime) {\n        if (p\
    \ > mpf[i] or p * i >= C)\n          break;\n        mpf[p * i] = p;\n      }\n\
    \    }\n  }\n\n  public:\n\n  static vc<pii> prime_factorize(int x) {\n    initialize();\n\
    \    vc<pii> r;\n    while(mpf[x]) {\n      r.emplace_back(mpf[x], 0);\n     \
    \ while(x % r.back().first == 0)\n        x /= r.back().first, r.back().second++;\n\
    \    }\n    return r;\n  }\n\n  static vi prime_factor(int x) {\n    initialize();\n\
    \    vi r;\n    while(mpf[x]) {\n      r.emplace_back(mpf[x]);\n      while(x\
    \ % r.back() == 0)\n        x /= r.back();\n    }\n    return r;\n  }\n\n  static\
    \ vi divisor(int x, bool sorted = true) {\n    initialize();\n    vi divisor =\
    \ {1};\n    for(auto [p, f] : prime_factorize(x)) {\n      vi nxt;\n      nxt.reserve(ssize(divisor)\
    \ * (f + 1));\n      for(int64_t i = 0, q = 1; i <= f; i++, q *= p)\n        for(int\
    \ d : divisor)\n          nxt.emplace_back(d * q);\n      divisor.swap(nxt);\n\
    \    }\n    if (sorted)\n      ranges::sort(divisor);\n    return divisor;\n \
    \ }\n\n  static const vi& prime_array() {\n    initialize();\n    return prime;\n\
    \  }\n  static const array<int, C>& mpf_array() {\n    initialize();\n    return\
    \ mpf;\n  }\n\n  static auto functions() {\n    return tuple(\n      &prime_factorize,\n\
    \      &prime_factor,\n      [](int x, bool sorted = true) { return divisor(x,\
    \ sorted); },\n      &prime_array,\n      &mpf_array\n    );\n  }\n};\n\n//auto\
    \ [prime_factorize, prime_factor, divisor, prime_array, mpf_array] = linear_sieve<>::functions();\n"
  code: "template<int32_t C>\nclass linear_sieve {\n\n  static inline array<int, C>\
    \ mpf = {};\n  static inline vi prime;\n  static inline bool init = false;\n\n\
    \  static void initialize() {\n    if (init) return;\n    init = true;\n    if\
    \ (C > 2)\n      iota(mpf.begin() + 2, mpf.end(), 2);\n    for(int i = 2; i <\
    \ C; i++) {\n      if (mpf[i] == i)\n        prime.emplace_back(i);\n      for(int64_t\
    \ p : prime) {\n        if (p > mpf[i] or p * i >= C)\n          break;\n    \
    \    mpf[p * i] = p;\n      }\n    }\n  }\n\n  public:\n\n  static vc<pii> prime_factorize(int\
    \ x) {\n    initialize();\n    vc<pii> r;\n    while(mpf[x]) {\n      r.emplace_back(mpf[x],\
    \ 0);\n      while(x % r.back().first == 0)\n        x /= r.back().first, r.back().second++;\n\
    \    }\n    return r;\n  }\n\n  static vi prime_factor(int x) {\n    initialize();\n\
    \    vi r;\n    while(mpf[x]) {\n      r.emplace_back(mpf[x]);\n      while(x\
    \ % r.back() == 0)\n        x /= r.back();\n    }\n    return r;\n  }\n\n  static\
    \ vi divisor(int x, bool sorted = true) {\n    initialize();\n    vi divisor =\
    \ {1};\n    for(auto [p, f] : prime_factorize(x)) {\n      vi nxt;\n      nxt.reserve(ssize(divisor)\
    \ * (f + 1));\n      for(int64_t i = 0, q = 1; i <= f; i++, q *= p)\n        for(int\
    \ d : divisor)\n          nxt.emplace_back(d * q);\n      divisor.swap(nxt);\n\
    \    }\n    if (sorted)\n      ranges::sort(divisor);\n    return divisor;\n \
    \ }\n\n  static const vi& prime_array() {\n    initialize();\n    return prime;\n\
    \  }\n  static const array<int, C>& mpf_array() {\n    initialize();\n    return\
    \ mpf;\n  }\n\n  static auto functions() {\n    return tuple(\n      &prime_factorize,\n\
    \      &prime_factor,\n      [](int x, bool sorted = true) { return divisor(x,\
    \ sorted); },\n      &prime_array,\n      &mpf_array\n    );\n  }\n};\n\n//auto\
    \ [prime_factorize, prime_factor, divisor, prime_array, mpf_array] = linear_sieve<>::functions();\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/linear_sieve.cpp
  requiredBy: []
  timestamp: '2026-07-15 01:05:29+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest_phi_array.test.cpp
  - test/mytest_mu_array.test.cpp
  - test/mytest_linear_sieve.test.cpp
  - test/gcd_convolution.test.cpp
  - test/lcm_convolution.test.cpp
documentation_of: numtheory/linear_sieve.cpp
layout: document
redirect_from:
- /library/numtheory/linear_sieve.cpp
- /library/numtheory/linear_sieve.cpp.html
title: numtheory/linear_sieve.cpp
---
