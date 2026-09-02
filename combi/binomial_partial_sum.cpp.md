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
  bundledCode: "#line 1 \"combi/binomial_partial_sum.cpp\"\n//sum(binom(n, i)) for\
    \ i <= m\ntemplate<class Mint>\nclass binomial_partial_sum {\n  int _n, _m;\n\
    \  Mint ans = 0, i2 = Mint(2).inverse();\n\n  public:\n\n  binomial_partial_sum(int\
    \ n, int m) : _n(n), _m(m) {\n    for(int i = 0; i <= m; i++)\n      ans += binomial<Mint>(n,\
    \ i);\n  }\n\n  Mint query(int n, int m) {\n    while(_m < m) ans += binomial<Mint>(_n,\
    \ ++_m);\n    while(_m > m) ans -= binomial<Mint>(_n, _m--);\n    while(_n < n)\
    \ ans += ans - binomial<Mint>(_n++, _m);\n    while(_n > n) ans = (ans + binomial<Mint>(--_n,\
    \ _m)) * i2;\n    return ans;\n  }\n};\n"
  code: "//sum(binom(n, i)) for i <= m\ntemplate<class Mint>\nclass binomial_partial_sum\
    \ {\n  int _n, _m;\n  Mint ans = 0, i2 = Mint(2).inverse();\n\n  public:\n\n \
    \ binomial_partial_sum(int n, int m) : _n(n), _m(m) {\n    for(int i = 0; i <=\
    \ m; i++)\n      ans += binomial<Mint>(n, i);\n  }\n\n  Mint query(int n, int\
    \ m) {\n    while(_m < m) ans += binomial<Mint>(_n, ++_m);\n    while(_m > m)\
    \ ans -= binomial<Mint>(_n, _m--);\n    while(_n < n) ans += ans - binomial<Mint>(_n++,\
    \ _m);\n    while(_n > n) ans = (ans + binomial<Mint>(--_n, _m)) * i2;\n    return\
    \ ans;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/binomial_partial_sum.cpp
  requiredBy: []
  timestamp: '2026-09-02 22:20:49+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: combi/binomial_partial_sum.cpp
layout: document
redirect_from:
- /library/combi/binomial_partial_sum.cpp
- /library/combi/binomial_partial_sum.cpp.html
title: combi/binomial_partial_sum.cpp
---
