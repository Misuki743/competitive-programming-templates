---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bell_number.test.cpp
    title: test/bell_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/binomial_coefficient_prime_mod.test.cpp
    title: test/binomial_coefficient_prime_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/counting_eulerian_circuits.test.cpp
    title: test/counting_eulerian_circuits.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/exp_of_formal_power_series_sparse.test.cpp
    title: test/exp_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/inv_of_formal_power_series_sparse.test.cpp
    title: test/inv_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/log_of_formal_power_series_sparse.test.cpp
    title: test/log_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial_taylor_shift.test.cpp
    title: test/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/pow_of_formal_power_series_sparse.test.cpp
    title: test/pow_of_formal_power_series_sparse.test.cpp
  - icon: ':x:'
    path: test/sqrt_of_formal_power_series_sparse.test.cpp
    title: test/sqrt_of_formal_power_series_sparse.test.cpp
  - icon: ':x:'
    path: test/stirling_number_of_the_second_kind.test.cpp
    title: test/stirling_number_of_the_second_kind.test.cpp
  - icon: ':x:'
    path: test/yuki_2544.test.cpp
    title: test/yuki_2544.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"combi/binomial.cpp\"\n//#include<modint/Montgomery_modint.cpp>\n\
    \ntemplate<class Mint>\nMint factorial(int n) {\n  static vc<Mint> dat;\n  if\
    \ (n >= ssize(dat)) {\n    if (dat.empty()) dat.eb(1);\n    int size0 = ssize(dat);\n\
    \    dat.resize(min(Mint::get_mod(), bit_ceil((uint32_t)(n + 1))));\n    for(int\
    \ i = size0; i < ssize(dat); i++)\n      dat[i] = dat[i - 1] * i;\n  }\n  return\
    \ dat[n];\n}\n\ntemplate<class Mint>\nMint factorial_inv(int n) {\n  static vc<Mint>\
    \ dat;\n  if (n >= ssize(dat)) {\n    int size0 = ssize(dat);\n    dat.resize(min(Mint::get_mod(),\
    \ bit_ceil((uint32_t)(n + 1))));\n    dat.back() = factorial<Mint>(ssize(dat)\
    \ - 1).inverse();\n    for(int i = ssize(dat) - 2; i >= size0; i--)\n      dat[i]\
    \ = dat[i + 1] * (i + 1);\n  }\n  return dat[n];\n}\n\ntemplate<class Mint>\n\
    Mint inverse(int n) {\n  return factorial_inv<Mint>(n) * factorial<Mint>(n - 1);\n\
    }\n\ntemplate<class Mint>\nMint binomial(int n, int k) {\n  if (0 <= k and k <=\
    \ n)\n    return factorial<Mint>(n) * factorial_inv<Mint>(k) * factorial_inv<Mint>(n\
    \ - k);\n  else\n    return Mint(0);\n}\n\ntemplate<class Mint>\nMint catalan(int\
    \ n) {\n  return binomial<Mint>(2 * n, n) - binomial<Mint>(2 * n, n + 1);\n}\n\
    \n//number of up-down path with n (+1), m (-1) and never touch y = -k\ntemplate<class\
    \ Mint>\nMint excatalan(int n, int m, int k) {\n  if (k > m) return binomial<Mint>(n\
    \ + m, m);\n  else if (k > m - n) return binomial<Mint>(n + m, m) - binomial<Mint>(n\
    \ + m, m - k);\n  else return Mint(0);\n}\n\ntemplate<class Mint>\nauto binomial_functions()\
    \ {\n  return tuple(\n    &factorial<Mint>,\n    &factorial_inv<Mint>,\n    &inverse<Mint>,\n\
    \    &binomial<Mint>,\n    &catalan<Mint>,\n    &excatalan<Mint>\n  );\n}\n\n\
    //auto [fac, faci, inv, binom, cat, excat] = binomial_functions<mint>();\n"
  code: "//#include<modint/Montgomery_modint.cpp>\n\ntemplate<class Mint>\nMint factorial(int\
    \ n) {\n  static vc<Mint> dat;\n  if (n >= ssize(dat)) {\n    if (dat.empty())\
    \ dat.eb(1);\n    int size0 = ssize(dat);\n    dat.resize(min(Mint::get_mod(),\
    \ bit_ceil((uint32_t)(n + 1))));\n    for(int i = size0; i < ssize(dat); i++)\n\
    \      dat[i] = dat[i - 1] * i;\n  }\n  return dat[n];\n}\n\ntemplate<class Mint>\n\
    Mint factorial_inv(int n) {\n  static vc<Mint> dat;\n  if (n >= ssize(dat)) {\n\
    \    int size0 = ssize(dat);\n    dat.resize(min(Mint::get_mod(), bit_ceil((uint32_t)(n\
    \ + 1))));\n    dat.back() = factorial<Mint>(ssize(dat) - 1).inverse();\n    for(int\
    \ i = ssize(dat) - 2; i >= size0; i--)\n      dat[i] = dat[i + 1] * (i + 1);\n\
    \  }\n  return dat[n];\n}\n\ntemplate<class Mint>\nMint inverse(int n) {\n  return\
    \ factorial_inv<Mint>(n) * factorial<Mint>(n - 1);\n}\n\ntemplate<class Mint>\n\
    Mint binomial(int n, int k) {\n  if (0 <= k and k <= n)\n    return factorial<Mint>(n)\
    \ * factorial_inv<Mint>(k) * factorial_inv<Mint>(n - k);\n  else\n    return Mint(0);\n\
    }\n\ntemplate<class Mint>\nMint catalan(int n) {\n  return binomial<Mint>(2 *\
    \ n, n) - binomial<Mint>(2 * n, n + 1);\n}\n\n//number of up-down path with n\
    \ (+1), m (-1) and never touch y = -k\ntemplate<class Mint>\nMint excatalan(int\
    \ n, int m, int k) {\n  if (k > m) return binomial<Mint>(n + m, m);\n  else if\
    \ (k > m - n) return binomial<Mint>(n + m, m) - binomial<Mint>(n + m, m - k);\n\
    \  else return Mint(0);\n}\n\ntemplate<class Mint>\nauto binomial_functions()\
    \ {\n  return tuple(\n    &factorial<Mint>,\n    &factorial_inv<Mint>,\n    &inverse<Mint>,\n\
    \    &binomial<Mint>,\n    &catalan<Mint>,\n    &excatalan<Mint>\n  );\n}\n\n\
    //auto [fac, faci, inv, binom, cat, excat] = binomial_functions<mint>();\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/binomial.cpp
  requiredBy: []
  timestamp: '2026-07-15 10:56:37+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/pow_of_formal_power_series_sparse.test.cpp
  - test/binomial_coefficient_prime_mod.test.cpp
  - test/inv_of_formal_power_series_sparse.test.cpp
  - test/stirling_number_of_the_second_kind.test.cpp
  - test/yuki_2544.test.cpp
  - test/sqrt_of_formal_power_series_sparse.test.cpp
  - test/counting_eulerian_circuits.test.cpp
  - test/polynomial_taylor_shift.test.cpp
  - test/bell_number.test.cpp
  - test/exp_of_formal_power_series_sparse.test.cpp
  - test/log_of_formal_power_series_sparse.test.cpp
documentation_of: combi/binomial.cpp
layout: document
redirect_from:
- /library/combi/binomial.cpp
- /library/combi/binomial.cpp.html
title: combi/binomial.cpp
---
