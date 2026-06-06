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
  bundledCode: "#line 1 \"misc/sharp_P_subset_sum.cpp\"\n//#include<modint/MontgomeryModInt>\n\
    //#include<poly/NTTmint>\n//#include<poly/FPS>\n\ntemplate<class Mint>\nFPS<Mint>\
    \ sharp_P_subset_sum(vector<int> w, int C) {\n  vector<int> freq(C + 1);\n  for(int\
    \ x : w)\n    if (x <= C)\n      freq[x]++;\n\n  vector<Mint> Inv(C + 1);\n  Inv[1]\
    \ = 1;\n  for(int i = 2; i < ssize(Inv); i++)\n    Inv[i] = (Mint::get_mod() -\
    \ Mint::get_mod() / i) * Inv[Mint::get_mod() % i];\n\n  FPS<Mint> f(C + 1);\n\
    \  for(int i = 1; i <= C; i++)\n    for(int j = 1; j * i <= C; j++)\n      f[j\
    \ * i] += freq[i] * Inv[j] * (j % 2 == 0 ? -1 : 1);\n\n  return f.exp(C + 1);\n\
    }\n"
  code: "//#include<modint/MontgomeryModInt>\n//#include<poly/NTTmint>\n//#include<poly/FPS>\n\
    \ntemplate<class Mint>\nFPS<Mint> sharp_P_subset_sum(vector<int> w, int C) {\n\
    \  vector<int> freq(C + 1);\n  for(int x : w)\n    if (x <= C)\n      freq[x]++;\n\
    \n  vector<Mint> Inv(C + 1);\n  Inv[1] = 1;\n  for(int i = 2; i < ssize(Inv);\
    \ i++)\n    Inv[i] = (Mint::get_mod() - Mint::get_mod() / i) * Inv[Mint::get_mod()\
    \ % i];\n\n  FPS<Mint> f(C + 1);\n  for(int i = 1; i <= C; i++)\n    for(int j\
    \ = 1; j * i <= C; j++)\n      f[j * i] += freq[i] * Inv[j] * (j % 2 == 0 ? -1\
    \ : 1);\n\n  return f.exp(C + 1);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/sharp_P_subset_sum.cpp
  requiredBy: []
  timestamp: '2026-06-06 23:34:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/sharp_P_subset_sum.cpp
layout: document
redirect_from:
- /library/misc/sharp_P_subset_sum.cpp
- /library/misc/sharp_P_subset_sum.cpp.html
title: misc/sharp_P_subset_sum.cpp
---
