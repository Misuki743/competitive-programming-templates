---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.5/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.5/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.5/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.14.5/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../actedmonoid/affine_sum.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/Montgomery_modint.cpp\"\
    \n#include \"../segtree/segment_tree.cpp\"\n#include \"../actedmonoid/affine_sum.cpp\"\
    \n#include \"../tree/HLD.cpp\"\n\nusing am = affine_sum<mint>;\n\nam::T R_Top(const\
    \ am::T &a, const am::T &b) { return am::T{a[0] * b[0], b[1] * a[0] + a[1]}; }\n\
    \nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin\
    \ >> n >> q;\n  vc<array<mint, 2>> init(n);\n  for(auto &[a, b] : init)\n    cin\
    \ >> a >> b;\n  vc<pii> e(n - 1);\n  for(auto &[u, v] : e)\n    cin >> u >> v;\n\
    \n  HLD hld(std::move(e));\n  init = hld.reorder_init(std::move(init));\n  segment_tree<am::T,\
    \ am::Tid, R_Top> st_rev(init);\n  segment_tree<am::T, am::Tid, am::Top> st(init);\n\
    \  while(q--) {\n    int op; cin >> op;\n    if (op == 0) {\n      int p, c, d;\
    \ cin >> p >> c >> d;\n      st.set(hld.query_point(p), am::M{c, d});\n      st_rev.set(hld.query_point(p),\
    \ am::M{c, d});\n    } else {\n      int u, v, x; cin >> u >> v >> x;\n      am::T\
    \ prod = am::T{1, 0};\n      for(auto [l, r] : hld.query_path_non_commutative(u,\
    \ v)) {\n        if (l < r) prod = am::Top(prod, st.query(l, r));\n        else\
    \ prod = am::Top(prod, st_rev.query(r, l));\n      }\n      cout << prod[0] *\
    \ x + prod[1] << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_set_path_composite.test.cpp
- /verify/test/vertex_set_path_composite.test.cpp.html
title: test/vertex_set_path_composite.test.cpp
---
