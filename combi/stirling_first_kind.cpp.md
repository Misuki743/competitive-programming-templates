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
  bundledCode: "#line 1 \"combi/stirling_first_kind.cpp\"\n//#include<modint/MontgomeryModInt.cpp>\n\
    //#include<poly/NTTmint.cpp>\n//#include<poly/FPS.cpp>\n\ntemplate<class Mint>\n\
    FPS<Mint> stirling_first_kind(int n) {\n  vector<FPS<Mint>> fs(n, {0, 1});\n \
    \ for(int i = 0; i < n; i++)\n    fs[i][0] = -i;\n  return FPS<Mint>::allProd(fs);\n\
    }\n"
  code: "//#include<modint/MontgomeryModInt.cpp>\n//#include<poly/NTTmint.cpp>\n//#include<poly/FPS.cpp>\n\
    \ntemplate<class Mint>\nFPS<Mint> stirling_first_kind(int n) {\n  vector<FPS<Mint>>\
    \ fs(n, {0, 1});\n  for(int i = 0; i < n; i++)\n    fs[i][0] = -i;\n  return FPS<Mint>::allProd(fs);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/stirling_first_kind.cpp
  requiredBy: []
  timestamp: '2026-06-06 23:34:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: combi/stirling_first_kind.cpp
layout: document
redirect_from:
- /library/combi/stirling_first_kind.cpp
- /library/combi/stirling_first_kind.cpp.html
title: combi/stirling_first_kind.cpp
---
