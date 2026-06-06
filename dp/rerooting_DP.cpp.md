---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree_path_composite_sum.test.cpp
    title: test/tree_path_composite_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/rerooting_DP.cpp\"\ntemplate<class V, class E>\nstruct\
    \ rerooting_DP {\n  HLD &tree;\n  vc<V> dp_down, dp_up, dp_full;\n\n  template<typename\
    \ ID, typename EE, typename ADD_V, typename ADD_E>\n  requires\n  R_invocable<V,\
    \ ID,    int             > &&\n  R_invocable<E, EE,    const E, const E> &&\n\
    \  R_invocable<V, ADD_V, const E, int    > &&\n  R_invocable<E, ADD_E, const V,\
    \ int    >\n  rerooting_DP(HLD &_tree, ID id, EE ee, ADD_V add_v, ADD_E add_e)\
    \ : tree(_tree) {\n    const int n = tree.n;\n    dp_down = dp_up = dp_full =\
    \ vc<V>(n);\n\n    vc<V> data(n);\n    for(int v = 0; v < n; v++) data[v] = id(v);\n\
    \    auto dfs = [&](int v, auto &self) -> void {\n      E prod;\n      bool leaf\
    \ = 1;\n      for(int x : tree.childs(v)) {\n        self(x, self);\n        if\
    \ (leaf) prod = add_e(data[x], tree.parent_eid(x)), leaf = 0;\n        else prod\
    \ = ee(prod, add_e(data[x], tree.parent_eid(x)));\n      }\n      if (!leaf) data[v]\
    \ = add_v(prod, v);\n    };\n    \n    dfs(tree.root, dfs);\n\n    auto dfs2 =\
    \ [&](int v, auto &self) -> void {\n      const int deg = ssize(tree.childs(v))\
    \ + (v != tree.root);\n      vc<E> pre(deg), suf(deg);\n      if (v != tree.root)\
    \ {\n        dp_up[v] = data[tree.parent(v)];\n        pre.back() = suf.back()\
    \ = add_e(data[tree.parent(v)], tree.parent_eid(v));\n      }\n      for(int i\
    \ = 0; int x : tree.childs(v)) {\n        dp_down[x] = data[x];\n        pre[i]\
    \ = suf[i] = add_e(data[x], tree.parent_eid(x)), i++;\n      }\n      pSum(pre,\
    \ ee), pSum(suf | views::reverse, ee);\n      V tmp = data[v];\n      dp_full[v]\
    \ = data[v] = (deg ? add_v(suf[0], v) : id(v));\n      for(int i = -1; int x :\
    \ tree.childs(v)) {\n        i++;\n        bool leaf = 1;\n        E prod;\n \
    \       if (i) prod = pre[i - 1], leaf = 0;\n        if (i + 1 < deg) prod = (leaf\
    \ ? suf[i + 1] : ee(prod, suf[i + 1])), leaf = 0;\n        V tmp2 = data[v];\n\
    \        data[v] = (leaf ? id(v) : add_v(prod, v));\n        self(x, self);\n\
    \        data[v] = tmp2;\n      }\n      data[v] = tmp;\n    };\n\n    dfs2(tree.root,\
    \ dfs2);\n  }\n\n  V operator[](int v) { return dp_full[v]; }\n  V get(int v,\
    \ int r) { return tree.in_subtree_of(v, r) ? dp_down[v] : dp_up[tree.kth(v, r,\
    \ 1)]; }\n};\n"
  code: "template<class V, class E>\nstruct rerooting_DP {\n  HLD &tree;\n  vc<V>\
    \ dp_down, dp_up, dp_full;\n\n  template<typename ID, typename EE, typename ADD_V,\
    \ typename ADD_E>\n  requires\n  R_invocable<V, ID,    int             > &&\n\
    \  R_invocable<E, EE,    const E, const E> &&\n  R_invocable<V, ADD_V, const E,\
    \ int    > &&\n  R_invocable<E, ADD_E, const V, int    >\n  rerooting_DP(HLD &_tree,\
    \ ID id, EE ee, ADD_V add_v, ADD_E add_e) : tree(_tree) {\n    const int n = tree.n;\n\
    \    dp_down = dp_up = dp_full = vc<V>(n);\n\n    vc<V> data(n);\n    for(int\
    \ v = 0; v < n; v++) data[v] = id(v);\n    auto dfs = [&](int v, auto &self) ->\
    \ void {\n      E prod;\n      bool leaf = 1;\n      for(int x : tree.childs(v))\
    \ {\n        self(x, self);\n        if (leaf) prod = add_e(data[x], tree.parent_eid(x)),\
    \ leaf = 0;\n        else prod = ee(prod, add_e(data[x], tree.parent_eid(x)));\n\
    \      }\n      if (!leaf) data[v] = add_v(prod, v);\n    };\n    \n    dfs(tree.root,\
    \ dfs);\n\n    auto dfs2 = [&](int v, auto &self) -> void {\n      const int deg\
    \ = ssize(tree.childs(v)) + (v != tree.root);\n      vc<E> pre(deg), suf(deg);\n\
    \      if (v != tree.root) {\n        dp_up[v] = data[tree.parent(v)];\n     \
    \   pre.back() = suf.back() = add_e(data[tree.parent(v)], tree.parent_eid(v));\n\
    \      }\n      for(int i = 0; int x : tree.childs(v)) {\n        dp_down[x] =\
    \ data[x];\n        pre[i] = suf[i] = add_e(data[x], tree.parent_eid(x)), i++;\n\
    \      }\n      pSum(pre, ee), pSum(suf | views::reverse, ee);\n      V tmp =\
    \ data[v];\n      dp_full[v] = data[v] = (deg ? add_v(suf[0], v) : id(v));\n \
    \     for(int i = -1; int x : tree.childs(v)) {\n        i++;\n        bool leaf\
    \ = 1;\n        E prod;\n        if (i) prod = pre[i - 1], leaf = 0;\n       \
    \ if (i + 1 < deg) prod = (leaf ? suf[i + 1] : ee(prod, suf[i + 1])), leaf = 0;\n\
    \        V tmp2 = data[v];\n        data[v] = (leaf ? id(v) : add_v(prod, v));\n\
    \        self(x, self);\n        data[v] = tmp2;\n      }\n      data[v] = tmp;\n\
    \    };\n\n    dfs2(tree.root, dfs2);\n  }\n\n  V operator[](int v) { return dp_full[v];\
    \ }\n  V get(int v, int r) { return tree.in_subtree_of(v, r) ? dp_down[v] : dp_up[tree.kth(v,\
    \ r, 1)]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/rerooting_DP.cpp
  requiredBy: []
  timestamp: '2026-03-22 17:48:48+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree_path_composite_sum.test.cpp
documentation_of: dp/rerooting_DP.cpp
layout: document
redirect_from:
- /library/dp/rerooting_DP.cpp
- /library/dp/rerooting_DP.cpp.html
title: dp/rerooting_DP.cpp
---
