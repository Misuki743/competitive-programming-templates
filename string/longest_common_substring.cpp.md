---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/longest_common_substring.test.cpp
    title: test/longest_common_substring.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/longest_common_substring.cpp\"\n//#include<string/suffixArray.cpp>\n\
    \narray<int, 4> longest_common_substring(string s, string t) {\n  t = s + '#'\
    \ + t;\n  auto sa = suffix_array(t);\n  auto lcp = lcp_array(t, sa);\n  array<int,\
    \ 4> res = {};\n  for(int i = 0; i < ssize(lcp); i++) {\n    if (lcp[i] <= res[1]\
    \ - res[0]) continue;\n    if (sa[i] < ssize(s) and sa[i + 1] > ssize(s))\n  \
    \    res = {sa[i], sa[i] + lcp[i], sa[i + 1] - (int)(ssize(s) + 1), sa[i + 1]\
    \ - (int)(ssize(s) + 1) + lcp[i]};\n    else if (sa[i] > ssize(s) and sa[i + 1]\
    \ < ssize(s))\n      res = {sa[i + 1], sa[i + 1] + lcp[i], sa[i] - (int)(ssize(s)\
    \ + 1), sa[i] - (int)(ssize(s) + 1) + lcp[i]};\n  }\n  return res;\n}\n"
  code: "//#include<string/suffixArray.cpp>\n\narray<int, 4> longest_common_substring(string\
    \ s, string t) {\n  t = s + '#' + t;\n  auto sa = suffix_array(t);\n  auto lcp\
    \ = lcp_array(t, sa);\n  array<int, 4> res = {};\n  for(int i = 0; i < ssize(lcp);\
    \ i++) {\n    if (lcp[i] <= res[1] - res[0]) continue;\n    if (sa[i] < ssize(s)\
    \ and sa[i + 1] > ssize(s))\n      res = {sa[i], sa[i] + lcp[i], sa[i + 1] - (int)(ssize(s)\
    \ + 1), sa[i + 1] - (int)(ssize(s) + 1) + lcp[i]};\n    else if (sa[i] > ssize(s)\
    \ and sa[i + 1] < ssize(s))\n      res = {sa[i + 1], sa[i + 1] + lcp[i], sa[i]\
    \ - (int)(ssize(s) + 1), sa[i] - (int)(ssize(s) + 1) + lcp[i]};\n  }\n  return\
    \ res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/longest_common_substring.cpp
  requiredBy: []
  timestamp: '2026-06-06 23:34:13+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/longest_common_substring.test.cpp
documentation_of: string/longest_common_substring.cpp
layout: document
redirect_from:
- /library/string/longest_common_substring.cpp
- /library/string/longest_common_substring.cpp.html
title: string/longest_common_substring.cpp
---
