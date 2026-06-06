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
  bundledCode: "#line 1 \"poly/semi_online_convolution.cpp\"\n//#include<modint/MontgomeryModInt.cpp>\n\
    //#include<poly/NTTmint.cpp>\n//#include<poly/FPS.cpp>\n\ntemplate<class Mint>\n\
    FPS<Mint> semi_online_convolution(FPS<Mint> f, FPS<Mint> g) {\n  auto calc = [&](int\
    \ l, int r, auto self) -> void {\n    if (l + 1 >= r) return;\n    int mid = (l\
    \ + r) / 2;\n    self(l, mid, self);\n    {\n      FPS<Mint> ff(f.begin() + l,\
    \ f.begin() + mid);\n      FPS<Mint> gg(g.begin(), g.begin() + min(r - l, (int)g.size()));\n\
    \      auto h = ff * gg;\n      for(int i = mid - l; i < ssize(h) and i + l <\
    \ r; i++)\n        f[i + l] += h[i];\n    }\n    self(mid, r, self);\n  };\n\n\
    \  calc(0, ssize(f), calc);\n\n  return f;\n}\n"
  code: "//#include<modint/MontgomeryModInt.cpp>\n//#include<poly/NTTmint.cpp>\n//#include<poly/FPS.cpp>\n\
    \ntemplate<class Mint>\nFPS<Mint> semi_online_convolution(FPS<Mint> f, FPS<Mint>\
    \ g) {\n  auto calc = [&](int l, int r, auto self) -> void {\n    if (l + 1 >=\
    \ r) return;\n    int mid = (l + r) / 2;\n    self(l, mid, self);\n    {\n   \
    \   FPS<Mint> ff(f.begin() + l, f.begin() + mid);\n      FPS<Mint> gg(g.begin(),\
    \ g.begin() + min(r - l, (int)g.size()));\n      auto h = ff * gg;\n      for(int\
    \ i = mid - l; i < ssize(h) and i + l < r; i++)\n        f[i + l] += h[i];\n \
    \   }\n    self(mid, r, self);\n  };\n\n  calc(0, ssize(f), calc);\n\n  return\
    \ f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/semi_online_convolution.cpp
  requiredBy: []
  timestamp: '2026-06-06 23:34:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/semi_online_convolution.cpp
layout: document
redirect_from:
- /library/poly/semi_online_convolution.cpp
- /library/poly/semi_online_convolution.cpp.html
title: poly/semi_online_convolution.cpp
---
