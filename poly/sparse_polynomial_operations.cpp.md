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
  bundledCode: "#line 1 \"poly/sparse_polynomial_operations.cpp\"\n//#include<poly/FPS.cpp>\n\
    //#include<poly/NTTmint.cpp>\n//#include<modint/MontgomeryModInt.cpp>\n//#include<combi/binom.cpp>\n\
    //#include<numtheory/sqrtMod.cpp>\n\nnamespace sparse_polynomial_operations {\n\
    \  template<class Mint>\n  vector<pair<int, Mint>> sparsify(FPS<Mint> f) {\n \
    \   vector<pair<int, Mint>> g;\n    for(int i = 0; i < ssize(f); i++)\n      if\
    \ (f[i] != 0)\n        g.emplace_back(i, f[i]);\n    return g;\n  }\n  template<class\
    \ Mint>\n  FPS<Mint> sparseInv(FPS<Mint> f, int k) {\n    assert(f[0] != 0);\n\
    \    FPS<Mint> g(k);\n    Mint inv = 1 / f[0];\n    g[0] = 1;\n    auto fs = sparsify(f);\n\
    \    for(int i = 0; i < k; i++) {\n      for(auto [j, val] : fs | views::drop(1))\n\
    \        if (j <= i)\n          g[i] -= g[i - j] * val;\n      g[i] *= inv;\n\
    \    }\n    return g;\n  }\n  template<class Mint>\n  FPS<Mint> sparseExp(FPS<Mint>\
    \ f, int k) {\n    assert(f[0] == 0);\n    binomial<Mint> bn(k);\n    FPS<Mint>\
    \ g(k);\n    g[0] = 1;\n    auto fs = sparsify(f);\n    for(auto &[i, val] : fs)\
    \ val *= i--;\n    for(int i = 0; i < k - 1; i++) {\n      for(auto [j, val] :\
    \ fs)\n        if (j <= i)\n          g[i + 1] += g[i - j] * val;\n      g[i +\
    \ 1] *= bn.inv(i + 1);\n    }\n    return g;\n  }\n  template<class Mint>\n  FPS<Mint>\
    \ sparseLog(FPS<Mint> f, int k) {\n    assert(f[0] == 1);\n    auto invf = sparseInv(f,\
    \ k);\n    auto fs = sparsify(f.derivative());\n    FPS<Mint> g(k - 1);\n    for(int\
    \ i = 0; i < k - 1; i++)\n      for(auto [j, val] : fs)\n        if (j <= i)\n\
    \          g[i] += invf[i - j] * val;\n    return g.integral();\n  }\n  template<class\
    \ Mint>\n  FPS<Mint> sparsePow(FPS<Mint> f, ll idx, int k) {\n    if (idx == 0)\
    \ {\n      FPS<Mint> g(k);\n      g[0] = 1;\n      return g;\n    } else if (f[0]\
    \ == 0) {\n      for(int i = 0; i < ssize(f) and i * idx < k; i++) {\n       \
    \ if (f[i] != 0) {\n          FPS<Mint> g = sparsePow<Mint>({f.begin() + i, f.end()},\
    \ idx, k - i * idx);\n          g.resize(k);\n          for(int j = k - 1; j >=\
    \ i * idx; j--)\n            swap(g[j], g[j - i * idx]);\n          return g;\n\
    \        }\n      }\n      return FPS<Mint>(k);\n    } else {\n      Mint inv\
    \ = 1 / f[0];\n      vector<Mint> g(k), gd(k - 1);\n      binomial<Mint> bn(k);\n\
    \      g[0] = f[0].pow(idx);\n      auto fs = sparsify(f);\n      auto fds = fs;\n\
    \      fds.erase(fds.begin());\n      for(auto &[i, val] : fds) val *= i--;\n\
    \      for(int i = 0; i < k - 1; i++) {\n        for(auto [j, val] : fds)\n  \
    \        if (j <= i)\n            gd[i] += g[i - j] * val;\n        gd[i] *= idx;\n\
    \        for(auto [j, val] : fs)\n          if (0 < j and j <= i)\n          \
    \  gd[i] -= gd[i - j] * val;\n        gd[i] *= inv;\n        g[i + 1] = gd[i]\
    \ * bn.inv(i + 1);\n      }\n      return g;\n    }\n  }\n  template<class Mint>\n\
    \  FPS<Mint> sparseSqrt(FPS<Mint> f, int k) {\n    if (f[0] == 0) {\n      for(int\
    \ i = 0; i < ssize(f) and i < 2 * k; i++) {\n        if (f[i] != 0) {\n      \
    \    if (i & 1) return FPS<Mint>();\n          FPS<Mint> g = sparseSqrt<Mint>({f.begin()\
    \ + i, f.end()}, k - i / 2);\n          if (g.empty()) return g;\n          g.resize(k);\n\
    \          for(int j = k - 1; j >= i / 2; j--)\n            swap(g[j], g[j - i\
    \ / 2]);\n          return g;\n        }\n      }\n      return FPS<Mint>(k);\n\
    \    } else {\n      Mint inv = 1 / f[0];\n      vector<Mint> g(k), gd(k - 1);\n\
    \      binomial<Mint> bn(k);\n      if (ll x = sqrt(f[0].get(), Mint::get_mod());\
    \ x == -1)\n        return FPS<Mint>();\n      else\n        g[0] = x;\n     \
    \ auto fs = sparsify(f);\n      auto fds = fs;\n      fds.erase(fds.begin());\n\
    \      for(auto &[i, val] : fds) val *= i--;\n      Mint half = Mint(1) / 2;\n\
    \      for(int i = 0; i < k - 1; i++) {\n        for(auto [j, val] : fds)\n  \
    \        if (j <= i)\n            gd[i] += g[i - j] * val;\n        gd[i] *= half;\n\
    \        for(auto [j, val] : fs)\n          if (0 < j and j <= i)\n          \
    \  gd[i] -= gd[i - j] * val;\n        gd[i] *= inv;\n        g[i + 1] = gd[i]\
    \ * bn.inv(i + 1);\n      }\n      return g;\n    }\n  }\n}\n\nusing namespace\
    \ sparse_polynomial_operations;\n"
  code: "//#include<poly/FPS.cpp>\n//#include<poly/NTTmint.cpp>\n//#include<modint/MontgomeryModInt.cpp>\n\
    //#include<combi/binom.cpp>\n//#include<numtheory/sqrtMod.cpp>\n\nnamespace sparse_polynomial_operations\
    \ {\n  template<class Mint>\n  vector<pair<int, Mint>> sparsify(FPS<Mint> f) {\n\
    \    vector<pair<int, Mint>> g;\n    for(int i = 0; i < ssize(f); i++)\n     \
    \ if (f[i] != 0)\n        g.emplace_back(i, f[i]);\n    return g;\n  }\n  template<class\
    \ Mint>\n  FPS<Mint> sparseInv(FPS<Mint> f, int k) {\n    assert(f[0] != 0);\n\
    \    FPS<Mint> g(k);\n    Mint inv = 1 / f[0];\n    g[0] = 1;\n    auto fs = sparsify(f);\n\
    \    for(int i = 0; i < k; i++) {\n      for(auto [j, val] : fs | views::drop(1))\n\
    \        if (j <= i)\n          g[i] -= g[i - j] * val;\n      g[i] *= inv;\n\
    \    }\n    return g;\n  }\n  template<class Mint>\n  FPS<Mint> sparseExp(FPS<Mint>\
    \ f, int k) {\n    assert(f[0] == 0);\n    binomial<Mint> bn(k);\n    FPS<Mint>\
    \ g(k);\n    g[0] = 1;\n    auto fs = sparsify(f);\n    for(auto &[i, val] : fs)\
    \ val *= i--;\n    for(int i = 0; i < k - 1; i++) {\n      for(auto [j, val] :\
    \ fs)\n        if (j <= i)\n          g[i + 1] += g[i - j] * val;\n      g[i +\
    \ 1] *= bn.inv(i + 1);\n    }\n    return g;\n  }\n  template<class Mint>\n  FPS<Mint>\
    \ sparseLog(FPS<Mint> f, int k) {\n    assert(f[0] == 1);\n    auto invf = sparseInv(f,\
    \ k);\n    auto fs = sparsify(f.derivative());\n    FPS<Mint> g(k - 1);\n    for(int\
    \ i = 0; i < k - 1; i++)\n      for(auto [j, val] : fs)\n        if (j <= i)\n\
    \          g[i] += invf[i - j] * val;\n    return g.integral();\n  }\n  template<class\
    \ Mint>\n  FPS<Mint> sparsePow(FPS<Mint> f, ll idx, int k) {\n    if (idx == 0)\
    \ {\n      FPS<Mint> g(k);\n      g[0] = 1;\n      return g;\n    } else if (f[0]\
    \ == 0) {\n      for(int i = 0; i < ssize(f) and i * idx < k; i++) {\n       \
    \ if (f[i] != 0) {\n          FPS<Mint> g = sparsePow<Mint>({f.begin() + i, f.end()},\
    \ idx, k - i * idx);\n          g.resize(k);\n          for(int j = k - 1; j >=\
    \ i * idx; j--)\n            swap(g[j], g[j - i * idx]);\n          return g;\n\
    \        }\n      }\n      return FPS<Mint>(k);\n    } else {\n      Mint inv\
    \ = 1 / f[0];\n      vector<Mint> g(k), gd(k - 1);\n      binomial<Mint> bn(k);\n\
    \      g[0] = f[0].pow(idx);\n      auto fs = sparsify(f);\n      auto fds = fs;\n\
    \      fds.erase(fds.begin());\n      for(auto &[i, val] : fds) val *= i--;\n\
    \      for(int i = 0; i < k - 1; i++) {\n        for(auto [j, val] : fds)\n  \
    \        if (j <= i)\n            gd[i] += g[i - j] * val;\n        gd[i] *= idx;\n\
    \        for(auto [j, val] : fs)\n          if (0 < j and j <= i)\n          \
    \  gd[i] -= gd[i - j] * val;\n        gd[i] *= inv;\n        g[i + 1] = gd[i]\
    \ * bn.inv(i + 1);\n      }\n      return g;\n    }\n  }\n  template<class Mint>\n\
    \  FPS<Mint> sparseSqrt(FPS<Mint> f, int k) {\n    if (f[0] == 0) {\n      for(int\
    \ i = 0; i < ssize(f) and i < 2 * k; i++) {\n        if (f[i] != 0) {\n      \
    \    if (i & 1) return FPS<Mint>();\n          FPS<Mint> g = sparseSqrt<Mint>({f.begin()\
    \ + i, f.end()}, k - i / 2);\n          if (g.empty()) return g;\n          g.resize(k);\n\
    \          for(int j = k - 1; j >= i / 2; j--)\n            swap(g[j], g[j - i\
    \ / 2]);\n          return g;\n        }\n      }\n      return FPS<Mint>(k);\n\
    \    } else {\n      Mint inv = 1 / f[0];\n      vector<Mint> g(k), gd(k - 1);\n\
    \      binomial<Mint> bn(k);\n      if (ll x = sqrt(f[0].get(), Mint::get_mod());\
    \ x == -1)\n        return FPS<Mint>();\n      else\n        g[0] = x;\n     \
    \ auto fs = sparsify(f);\n      auto fds = fs;\n      fds.erase(fds.begin());\n\
    \      for(auto &[i, val] : fds) val *= i--;\n      Mint half = Mint(1) / 2;\n\
    \      for(int i = 0; i < k - 1; i++) {\n        for(auto [j, val] : fds)\n  \
    \        if (j <= i)\n            gd[i] += g[i - j] * val;\n        gd[i] *= half;\n\
    \        for(auto [j, val] : fs)\n          if (0 < j and j <= i)\n          \
    \  gd[i] -= gd[i - j] * val;\n        gd[i] *= inv;\n        g[i + 1] = gd[i]\
    \ * bn.inv(i + 1);\n      }\n      return g;\n    }\n  }\n}\n\nusing namespace\
    \ sparse_polynomial_operations;\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/sparse_polynomial_operations.cpp
  requiredBy: []
  timestamp: '2026-06-06 23:34:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/sparse_polynomial_operations.cpp
layout: document
redirect_from:
- /library/poly/sparse_polynomial_operations.cpp
- /library/poly/sparse_polynomial_operations.cpp.html
title: poly/sparse_polynomial_operations.cpp
---
