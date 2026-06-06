---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/stirling_number_of_first_kind_small_p_large_n.test.cpp
    title: test/stirling_number_of_first_kind_small_p_large_n.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"combi/stirling_first_kind_mod_P.cpp\"\n//#include<modint/Montgomery_modint.cpp>\n\
    \ntemplate<class Mint>\nstruct stirling_first_kind_mod_P {\n  const int p;\n \
    \ vector<vector<Mint>> _s, _c;\n  stirling_first_kind_mod_P() : p(Mint::get_mod()),\n\
    \    _s(p, vector<Mint>(p)), _c(p, vector<Mint>(p)) {\n    for(int i = 0; i <\
    \ p; i++) {\n      for(int j = 1; j < i; j++)\n        _s[i][j] = _s[i - 1][j\
    \ - 1] + _s[i - 1][j] * -(i - 1);\n      _s[i][i] = 1;\n    }\n    for(int i =\
    \ 0; i < p; i++) {\n      _c[i][0] = 1;\n      for(int j = 1; j < i; j++)\n  \
    \      _c[i][j] = _c[i - 1][j - 1] + _c[i - 1][j];\n      _c[i][i] = 1;\n    }\n\
    \  }\n\n  Mint binom(int64_t n, int64_t k) {\n    if (k < 0 or n < k) return Mint(0);\n\
    \    Mint r = 1;\n    while(n)\n      r *= _c[n % p][k % p], n /= p, k /= p;\n\
    \    return r;\n  }\n\n  Mint s(int64_t n, int64_t k) {\n    int64_t i = n / p,\
    \ j = n % p;\n    int64_t b = ((k - i) % (p - 1) + (p - 1)) % (p - 1);\n    int64_t\
    \ a = (k - i - b) / (p - 1);\n    mint r = binom(i, a) * ((i - a) % 2 == 1 ? -1\
    \ : 1) * _s[j][b];\n    if (b == 0 and a > 0)\n      r += binom(i, a - 1) * ((i\
    \ - a + 1) % 2 == 1 ? -1 : 1) * _s[j][p - 1];\n    return r;\n  }\n};\n"
  code: "//#include<modint/Montgomery_modint.cpp>\n\ntemplate<class Mint>\nstruct\
    \ stirling_first_kind_mod_P {\n  const int p;\n  vector<vector<Mint>> _s, _c;\n\
    \  stirling_first_kind_mod_P() : p(Mint::get_mod()),\n    _s(p, vector<Mint>(p)),\
    \ _c(p, vector<Mint>(p)) {\n    for(int i = 0; i < p; i++) {\n      for(int j\
    \ = 1; j < i; j++)\n        _s[i][j] = _s[i - 1][j - 1] + _s[i - 1][j] * -(i -\
    \ 1);\n      _s[i][i] = 1;\n    }\n    for(int i = 0; i < p; i++) {\n      _c[i][0]\
    \ = 1;\n      for(int j = 1; j < i; j++)\n        _c[i][j] = _c[i - 1][j - 1]\
    \ + _c[i - 1][j];\n      _c[i][i] = 1;\n    }\n  }\n\n  Mint binom(int64_t n,\
    \ int64_t k) {\n    if (k < 0 or n < k) return Mint(0);\n    Mint r = 1;\n   \
    \ while(n)\n      r *= _c[n % p][k % p], n /= p, k /= p;\n    return r;\n  }\n\
    \n  Mint s(int64_t n, int64_t k) {\n    int64_t i = n / p, j = n % p;\n    int64_t\
    \ b = ((k - i) % (p - 1) + (p - 1)) % (p - 1);\n    int64_t a = (k - i - b) /\
    \ (p - 1);\n    mint r = binom(i, a) * ((i - a) % 2 == 1 ? -1 : 1) * _s[j][b];\n\
    \    if (b == 0 and a > 0)\n      r += binom(i, a - 1) * ((i - a + 1) % 2 == 1\
    \ ? -1 : 1) * _s[j][p - 1];\n    return r;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/stirling_first_kind_mod_P.cpp
  requiredBy: []
  timestamp: '2026-06-07 03:13:20+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/stirling_number_of_first_kind_small_p_large_n.test.cpp
documentation_of: combi/stirling_first_kind_mod_P.cpp
layout: document
redirect_from:
- /library/combi/stirling_first_kind_mod_P.cpp
- /library/combi/stirling_first_kind_mod_P.cpp.html
title: combi/stirling_first_kind_mod_P.cpp
---
