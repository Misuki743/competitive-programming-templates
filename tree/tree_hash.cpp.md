---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/rooted_tree_isomorphism_classification.test.cpp
    title: test/rooted_tree_isomorphism_classification.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/tree_hash.cpp\"\ntemplate<bool ordered = false>\nauto\
    \ tree_hash(vvi &g, int root = 0) {\n  int nxt = 0;\n  static map<vi, int> seq_to_id;\n\
    \  vi subtree_id(size(g));\n  auto dfs = [&](int v, int p, auto self) -> int {\n\
    \    vi seq;\n    seq.reserve(ssize(g[v]));\n    for(int x : g[v]) if (x != p)\n\
    \      seq.emplace_back(self(x, v, self));\n    if constexpr (!ordered)\n    \
    \  ranges::sort(seq);\n    auto [ite, insert] = seq_to_id.emplace(seq, nxt);\n\
    \    if (insert) nxt++;\n    return subtree_id[v] = ite -> second;\n  };\n\n \
    \ dfs(root, -1, dfs);\n\n  return pair(nxt, subtree_id);\n}\n"
  code: "template<bool ordered = false>\nauto tree_hash(vvi &g, int root = 0) {\n\
    \  int nxt = 0;\n  static map<vi, int> seq_to_id;\n  vi subtree_id(size(g));\n\
    \  auto dfs = [&](int v, int p, auto self) -> int {\n    vi seq;\n    seq.reserve(ssize(g[v]));\n\
    \    for(int x : g[v]) if (x != p)\n      seq.emplace_back(self(x, v, self));\n\
    \    if constexpr (!ordered)\n      ranges::sort(seq);\n    auto [ite, insert]\
    \ = seq_to_id.emplace(seq, nxt);\n    if (insert) nxt++;\n    return subtree_id[v]\
    \ = ite -> second;\n  };\n\n  dfs(root, -1, dfs);\n\n  return pair(nxt, subtree_id);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/tree_hash.cpp
  requiredBy: []
  timestamp: '2026-03-22 16:32:23+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/rooted_tree_isomorphism_classification.test.cpp
documentation_of: tree/tree_hash.cpp
layout: document
redirect_from:
- /library/tree/tree_hash.cpp
- /library/tree/tree_hash.cpp.html
title: tree/tree_hash.cpp
---
