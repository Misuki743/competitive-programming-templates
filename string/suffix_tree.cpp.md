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
  bundledCode: "#line 1 \"string/suffix_tree.cpp\"\n//#include \"string/suffixArray.cpp\"\
    \n\n//0 is root, substring presented by v is\n//s[suf_id[v] + dep[p[v]], suf_id[v]\
    \ + dep[v])\nauto suffix_tree(vi SA, vi LCP) {\n  const int n = ssize(SA);\n\n\
    \  LCP.eb(0);\n\n  vi st = {0}, suf_id = {0}, dep = {0}, freq = {0};\n  vi lcp_st\
    \ = {-1};\n  vvi g(1);\n  int nxt = 1;\n  for(int i = 0; i < n; i++) {\n    g.eb();\n\
    \    st.eb(nxt++);\n    suf_id.eb(SA[i]);\n    dep.eb(n - SA[i]);\n    freq.eb(-i);\n\
    \n    int last_pop = -1;\n    while(dep[st.back()] > LCP[i]) {\n      int j =\
    \ st.back(); st.pop_back();\n      freq[j] += i + 1;\n      if (last_pop != -1)\n\
    \        g[j].eb(last_pop);\n      last_pop = j;\n    }\n    while(lcp_st.back()\
    \ != -1 and LCP[lcp_st.back()] >= LCP[i])\n      lcp_st.pop_back();\n    if (dep[st.back()]\
    \ != LCP[i]) {\n      g.eb();\n      st.eb(nxt++);\n      suf_id.eb(SA[i]);\n\
    \      dep.eb(LCP[i]);\n      freq.eb(-(lcp_st.back() + 1));\n    }\n    lcp_st.eb(i);\n\
    \    if (last_pop != -1)\n      g[st.back()].eb(last_pop);\n  }\n\n  return tuple(g,\
    \ suf_id, dep, freq);\n}\n"
  code: "//#include \"string/suffixArray.cpp\"\n\n//0 is root, substring presented\
    \ by v is\n//s[suf_id[v] + dep[p[v]], suf_id[v] + dep[v])\nauto suffix_tree(vi\
    \ SA, vi LCP) {\n  const int n = ssize(SA);\n\n  LCP.eb(0);\n\n  vi st = {0},\
    \ suf_id = {0}, dep = {0}, freq = {0};\n  vi lcp_st = {-1};\n  vvi g(1);\n  int\
    \ nxt = 1;\n  for(int i = 0; i < n; i++) {\n    g.eb();\n    st.eb(nxt++);\n \
    \   suf_id.eb(SA[i]);\n    dep.eb(n - SA[i]);\n    freq.eb(-i);\n\n    int last_pop\
    \ = -1;\n    while(dep[st.back()] > LCP[i]) {\n      int j = st.back(); st.pop_back();\n\
    \      freq[j] += i + 1;\n      if (last_pop != -1)\n        g[j].eb(last_pop);\n\
    \      last_pop = j;\n    }\n    while(lcp_st.back() != -1 and LCP[lcp_st.back()]\
    \ >= LCP[i])\n      lcp_st.pop_back();\n    if (dep[st.back()] != LCP[i]) {\n\
    \      g.eb();\n      st.eb(nxt++);\n      suf_id.eb(SA[i]);\n      dep.eb(LCP[i]);\n\
    \      freq.eb(-(lcp_st.back() + 1));\n    }\n    lcp_st.eb(i);\n    if (last_pop\
    \ != -1)\n      g[st.back()].eb(last_pop);\n  }\n\n  return tuple(g, suf_id, dep,\
    \ freq);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix_tree.cpp
  requiredBy: []
  timestamp: '2026-03-22 16:32:23+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/suffix_tree.cpp
layout: document
redirect_from:
- /library/string/suffix_tree.cpp
- /library/string/suffix_tree.cpp.html
title: string/suffix_tree.cpp
---
