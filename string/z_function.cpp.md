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
  bundledCode: "#line 1 \"string/z_function.cpp\"\ntemplate<class T>\nvector<int>\
    \ z_function(T &s) {\n  vector<int> z(ssize(s));\n  z[0] = ssize(s);\n  for(int\
    \ i = 1, l = 0, r = -1; i < ssize(s); i++) {\n    if (i <= r)\n      z[i] = min(r\
    \ - i + 1, z[i - l]);\n    while(i + z[i] < ssize(s) and s[i + z[i]] == s[z[i]])\n\
    \      l = i, r = i + z[i], z[i] += 1;\n  }\n  return z;\n}\n"
  code: "template<class T>\nvector<int> z_function(T &s) {\n  vector<int> z(ssize(s));\n\
    \  z[0] = ssize(s);\n  for(int i = 1, l = 0, r = -1; i < ssize(s); i++) {\n  \
    \  if (i <= r)\n      z[i] = min(r - i + 1, z[i - l]);\n    while(i + z[i] < ssize(s)\
    \ and s[i + z[i]] == s[z[i]])\n      l = i, r = i + z[i], z[i] += 1;\n  }\n  return\
    \ z;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/z_function.cpp
  requiredBy: []
  timestamp: '2026-06-06 23:34:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/z_function.cpp
layout: document
redirect_from:
- /library/string/z_function.cpp
- /library/string/z_function.cpp.html
title: string/z_function.cpp
---
