---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mul_modp_convolution.test.cpp
    title: test/mul_modp_convolution.test.cpp
  - icon: ':x:'
    path: test/yuki_2613.test.cpp
    title: test/yuki_2613.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/convolution_multiplicative.cpp\"\n//#include \"poly/NTT.cpp\"\
    \n//#include \"modint/Montgomery_modint.cpp\"\n\nstruct convolution_multiplicative\
    \ {\n  const int P, root;\n  vector<int> powR, logR;\n\n  int primitive_root(int\
    \ p) {\n    vector<int> pf;\n    {\n      int tmp = p - 1;\n      for(int i =\
    \ 2; i * i <= (p - 1); i++) {\n        if (tmp % i != 0) continue;\n        pf.emplace_back(i);\n\
    \        while(tmp % i == 0) tmp /= i;\n      }\n      if (tmp != 1)\n       \
    \ pf.emplace_back(tmp);\n    }\n\n    auto modpow = [p](ll a, int x) -> int {\n\
    \      if (x == 0) return 1;\n      if (a == 0) return 0;\n      ll b = 1;\n \
    \     while(x) {\n        if (x & 1) b = b * a % p;\n        a = a * a % p, x\
    \ >>= 1;\n      }\n      return b;\n    };\n\n    for(int r = 1; ; r++) {\n  \
    \    bool is_root = true;\n      for(int d : pf) {\n        if (modpow(r, (p -\
    \ 1) / d) == 1) {\n          is_root = false;\n          break;\n        }\n \
    \     }\n      if (is_root)\n        return r;\n    }\n  }\n\n  convolution_multiplicative(int\
    \ _P) : P(_P), root(primitive_root(_P)), powR(P - 1), logR(P, -1) {\n    for(int\
    \ i = 0, tmp = 1; i < P - 1; i++, tmp = (ll)tmp * root % P)\n      powR[i] = tmp,\
    \ logR[tmp] = i;\n  }\n\n  template<class Mint>\n  vector<Mint> transform(vector<Mint>\
    \ &f) {\n    assert(ssize(f) == P);\n    vector<Mint> g(P - 1);\n    for(int i\
    \ = 1; i < P; i++)\n      g[logR[i]] = f[i];\n    return g;\n  }\n\n  template<class\
    \ Mint>\n  vector<Mint> inverse_transform(vector<Mint> &f) {\n    assert(ssize(f)\
    \ == P - 1);\n    vector<Mint> g(P);\n    for(int i = 0; i < P - 1; i++)\n   \
    \   g[powR[i]] = f[i];\n    return g;\n  }\n\n  template<class Mint>\n  vector<Mint>\
    \ conv(vector<Mint> a, vector<Mint> b, vector<Mint>(*conv)(vector<Mint>, vector<Mint>))\
    \ {\n    Mint zero = accumulate(a.begin(), a.end(), Mint(0)) * b[0] + accumulate(b.begin()\
    \ + 1, b.end(), Mint(0)) * a[0];\n    a = transform(a), b = transform(b);\n  \
    \  a = conv(a, b);\n    for(int i = P - 1; i < 2 * P - 3; i++)\n      a[i - (P\
    \ - 1)] += a[i];\n    a.resize(P - 1);\n    a = inverse_transform(a);\n    a[0]\
    \ = zero;\n    return a;\n  }\n};\n"
  code: "//#include \"poly/NTT.cpp\"\n//#include \"modint/Montgomery_modint.cpp\"\n\
    \nstruct convolution_multiplicative {\n  const int P, root;\n  vector<int> powR,\
    \ logR;\n\n  int primitive_root(int p) {\n    vector<int> pf;\n    {\n      int\
    \ tmp = p - 1;\n      for(int i = 2; i * i <= (p - 1); i++) {\n        if (tmp\
    \ % i != 0) continue;\n        pf.emplace_back(i);\n        while(tmp % i == 0)\
    \ tmp /= i;\n      }\n      if (tmp != 1)\n        pf.emplace_back(tmp);\n   \
    \ }\n\n    auto modpow = [p](ll a, int x) -> int {\n      if (x == 0) return 1;\n\
    \      if (a == 0) return 0;\n      ll b = 1;\n      while(x) {\n        if (x\
    \ & 1) b = b * a % p;\n        a = a * a % p, x >>= 1;\n      }\n      return\
    \ b;\n    };\n\n    for(int r = 1; ; r++) {\n      bool is_root = true;\n    \
    \  for(int d : pf) {\n        if (modpow(r, (p - 1) / d) == 1) {\n          is_root\
    \ = false;\n          break;\n        }\n      }\n      if (is_root)\n       \
    \ return r;\n    }\n  }\n\n  convolution_multiplicative(int _P) : P(_P), root(primitive_root(_P)),\
    \ powR(P - 1), logR(P, -1) {\n    for(int i = 0, tmp = 1; i < P - 1; i++, tmp\
    \ = (ll)tmp * root % P)\n      powR[i] = tmp, logR[tmp] = i;\n  }\n\n  template<class\
    \ Mint>\n  vector<Mint> transform(vector<Mint> &f) {\n    assert(ssize(f) == P);\n\
    \    vector<Mint> g(P - 1);\n    for(int i = 1; i < P; i++)\n      g[logR[i]]\
    \ = f[i];\n    return g;\n  }\n\n  template<class Mint>\n  vector<Mint> inverse_transform(vector<Mint>\
    \ &f) {\n    assert(ssize(f) == P - 1);\n    vector<Mint> g(P);\n    for(int i\
    \ = 0; i < P - 1; i++)\n      g[powR[i]] = f[i];\n    return g;\n  }\n\n  template<class\
    \ Mint>\n  vector<Mint> conv(vector<Mint> a, vector<Mint> b, vector<Mint>(*conv)(vector<Mint>,\
    \ vector<Mint>)) {\n    Mint zero = accumulate(a.begin(), a.end(), Mint(0)) *\
    \ b[0] + accumulate(b.begin() + 1, b.end(), Mint(0)) * a[0];\n    a = transform(a),\
    \ b = transform(b);\n    a = conv(a, b);\n    for(int i = P - 1; i < 2 * P - 3;\
    \ i++)\n      a[i - (P - 1)] += a[i];\n    a.resize(P - 1);\n    a = inverse_transform(a);\n\
    \    a[0] = zero;\n    return a;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/convolution_multiplicative.cpp
  requiredBy: []
  timestamp: '2026-06-07 02:16:52+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mul_modp_convolution.test.cpp
  - test/yuki_2613.test.cpp
documentation_of: poly/convolution_multiplicative.cpp
layout: document
redirect_from:
- /library/poly/convolution_multiplicative.cpp
- /library/poly/convolution_multiplicative.cpp.html
title: poly/convolution_multiplicative.cpp
---
