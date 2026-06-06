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
  bundledCode: "#line 1 \"combi/binomial.cpp\"\n//#include<modint/MontgomeryModInt.cpp>\n\
    \ntemplate<class Mint>\nstruct binomial {\n  vector<Mint> _fac, _facInv;\n  binomial(int\
    \ size) : _fac(size), _facInv(size) {\n    assert(size <= (int)Mint::get_mod());\n\
    \    _fac[0] = 1;\n    for(int i = 1; i < size; i++)\n      _fac[i] = _fac[i -\
    \ 1] * i;\n    if (size > 0)\n      _facInv.back() = 1 / _fac.back();\n    for(int\
    \ i = size - 2; i >= 0; i--)\n      _facInv[i] = _facInv[i + 1] * (i + 1);\n \
    \ }\n\n  Mint fac(int i) { return i < 0 ? 0 : _fac[i]; }\n  Mint faci(int i) {\
    \ return i < 0 ? 0 : _facInv[i]; }\n  Mint inv(int i) { return _facInv[i] * _fac[i\
    \ - 1]; }\n  Mint binom(int n, int r) { return r < 0 or n < r ? 0 : fac(n) * faci(r)\
    \ * faci(n - r); }\n  Mint catalan(int i) { return binom(2 * i, i) - binom(2 *\
    \ i, i + 1); }\n  Mint excatalan(int n, int m, int k) { //(+1) * n, (-1) * m,\
    \ prefix sum > -k\n    if (k > m) return binom(n + m, m);\n    else if (k > m\
    \ - n) return binom(n + m, m) - binom(n + m, m - k);\n    else return Mint(0);\n\
    \  }\n};\n"
  code: "//#include<modint/MontgomeryModInt.cpp>\n\ntemplate<class Mint>\nstruct binomial\
    \ {\n  vector<Mint> _fac, _facInv;\n  binomial(int size) : _fac(size), _facInv(size)\
    \ {\n    assert(size <= (int)Mint::get_mod());\n    _fac[0] = 1;\n    for(int\
    \ i = 1; i < size; i++)\n      _fac[i] = _fac[i - 1] * i;\n    if (size > 0)\n\
    \      _facInv.back() = 1 / _fac.back();\n    for(int i = size - 2; i >= 0; i--)\n\
    \      _facInv[i] = _facInv[i + 1] * (i + 1);\n  }\n\n  Mint fac(int i) { return\
    \ i < 0 ? 0 : _fac[i]; }\n  Mint faci(int i) { return i < 0 ? 0 : _facInv[i];\
    \ }\n  Mint inv(int i) { return _facInv[i] * _fac[i - 1]; }\n  Mint binom(int\
    \ n, int r) { return r < 0 or n < r ? 0 : fac(n) * faci(r) * faci(n - r); }\n\
    \  Mint catalan(int i) { return binom(2 * i, i) - binom(2 * i, i + 1); }\n  Mint\
    \ excatalan(int n, int m, int k) { //(+1) * n, (-1) * m, prefix sum > -k\n   \
    \ if (k > m) return binom(n + m, m);\n    else if (k > m - n) return binom(n +\
    \ m, m) - binom(n + m, m - k);\n    else return Mint(0);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/binomial.cpp
  requiredBy: []
  timestamp: '2026-06-06 23:34:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: combi/binomial.cpp
layout: document
redirect_from:
- /library/combi/binomial.cpp
- /library/combi/binomial.cpp.html
title: combi/binomial.cpp
---
