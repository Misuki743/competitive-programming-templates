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
  bundledCode: "#line 1 \"string/KMP.cpp\"\ntemplate<class T>\nvi prefix_function(T\
    \ &s) {\n  vi pi(size(s));\n  pi[0] = -1;\n  for(int i = 1; i < ssize(s); i++)\
    \ {\n    int now = pi[i - 1];\n    while(now != -1 and s[i] != s[now + 1])\n \
    \     now = pi[now];\n    pi[i] = now + (s[now + 1] == s[i]);\n  }\n  return pi;\n\
    }\n\nint match(string &a, string &b) {\n  build(b);\n  int res = 0;\n  int now\
    \ = -1;\n  for(char X : a) {\n    while(now != -1 and X != b[now + 1])\n     \
    \ now = fail[now];\n    if (X == b[now + 1])\n      now++;\n    if (now + 1 ==\
    \ b.size())\n      res++, now = fail[now];\n  }\n\n  return res;\n}\n"
  code: "template<class T>\nvi prefix_function(T &s) {\n  vi pi(size(s));\n  pi[0]\
    \ = -1;\n  for(int i = 1; i < ssize(s); i++) {\n    int now = pi[i - 1];\n   \
    \ while(now != -1 and s[i] != s[now + 1])\n      now = pi[now];\n    pi[i] = now\
    \ + (s[now + 1] == s[i]);\n  }\n  return pi;\n}\n\nint match(string &a, string\
    \ &b) {\n  build(b);\n  int res = 0;\n  int now = -1;\n  for(char X : a) {\n \
    \   while(now != -1 and X != b[now + 1])\n      now = fail[now];\n    if (X ==\
    \ b[now + 1])\n      now++;\n    if (now + 1 == b.size())\n      res++, now =\
    \ fail[now];\n  }\n\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/KMP.cpp
  requiredBy: []
  timestamp: '2026-03-22 16:32:23+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/KMP.cpp
layout: document
redirect_from:
- /library/string/KMP.cpp
- /library/string/KMP.cpp.html
title: string/KMP.cpp
---
