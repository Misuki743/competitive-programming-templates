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
  bundledCode: "#line 1 \"string/palindromic_tree.cpp\"\ntemplate<unsigned sigma =\
    \ 26, char base = 'a'>\nstruct palindromic_tree {\n  vector<int> len, link;\n\
    \  vector<ll> freq;\n  vector<array<int, sigma>> go;\n\n  palindromicTree(string\
    \ s) {\n    array<int, sigma> unit;\n    fill(unit.begin(), unit.end(), -1);\n\
    \    len = link = {-1, 0}, go = {unit, unit}, freq = {0, 0};\n\n    for(int i\
    \ = 0, v = 0; i < ssize(s); i++) {\n      while(len[v] == i or s[i - len[v] -\
    \ 1] != s[i])\n        v = link[v];\n      if (go[v][s[i] - base] == -1) {\n \
    \       go[v][s[i] - base] = ssize(len);\n        len.emplace_back(len[v] + 2);\n\
    \        freq.emplace_back();\n        go.emplace_back(unit);\n        int u =\
    \ link[v];\n        while(u != -1 and s[i - len[u] - 1] != s[i])\n          u\
    \ = link[u];\n        link.emplace_back(u == -1 ? 1 : go[u][s[i] - base]);\n \
    \     }\n      v = go[v][s[i] - base], freq[v]++;\n    }\n\n    for(int i = ssize(len)\
    \ - 1; i > 0; i--)\n      freq[link[i]] += freq[i];\n    freq[0] = freq[1] = 0;\n\
    \  }\n};\n"
  code: "template<unsigned sigma = 26, char base = 'a'>\nstruct palindromic_tree {\n\
    \  vector<int> len, link;\n  vector<ll> freq;\n  vector<array<int, sigma>> go;\n\
    \n  palindromicTree(string s) {\n    array<int, sigma> unit;\n    fill(unit.begin(),\
    \ unit.end(), -1);\n    len = link = {-1, 0}, go = {unit, unit}, freq = {0, 0};\n\
    \n    for(int i = 0, v = 0; i < ssize(s); i++) {\n      while(len[v] == i or s[i\
    \ - len[v] - 1] != s[i])\n        v = link[v];\n      if (go[v][s[i] - base] ==\
    \ -1) {\n        go[v][s[i] - base] = ssize(len);\n        len.emplace_back(len[v]\
    \ + 2);\n        freq.emplace_back();\n        go.emplace_back(unit);\n      \
    \  int u = link[v];\n        while(u != -1 and s[i - len[u] - 1] != s[i])\n  \
    \        u = link[u];\n        link.emplace_back(u == -1 ? 1 : go[u][s[i] - base]);\n\
    \      }\n      v = go[v][s[i] - base], freq[v]++;\n    }\n\n    for(int i = ssize(len)\
    \ - 1; i > 0; i--)\n      freq[link[i]] += freq[i];\n    freq[0] = freq[1] = 0;\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/palindromic_tree.cpp
  requiredBy: []
  timestamp: '2026-06-06 23:34:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/palindromic_tree.cpp
layout: document
redirect_from:
- /library/string/palindromic_tree.cpp
- /library/string/palindromic_tree.cpp.html
title: string/palindromic_tree.cpp
---
