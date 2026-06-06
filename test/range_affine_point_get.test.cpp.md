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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../modint/MontgomeryModInt.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../segtree/dualSegmentTree.cpp\"\n\nmint Mid() { return mint(0);\
    \ }\narray<mint, 2> Tid() { return {1, 0}; }\narray<mint, 2> op(const array<mint,\
    \ 2> &l, const array<mint, 2> &r) { return {l[0] * r[0], l[1] * r[0] + r[1]};\
    \ }\nmint act(const mint &l, const array<mint, 2> &r) { return r[0] * l + r[1];\
    \ }\n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int\
    \ n, q; cin >> n >> q;\n  vector<mint> a(n);\n  for(mint &x : a)\n    cin >> x;\n\
    \n  dualSegmentTree<mint, Mid, array<mint, 2>, Tid, op, act> st(a);\n  while(q--)\
    \ {\n    int t; cin >> t;\n    if (t == 0) {\n      int l, r, b, c; cin >> l >>\
    \ r >> b >> c;\n      st.modify(l, r, {b, c});\n    } else {\n      int i; cin\
    \ >> i;\n      cout << st.get(i) << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/range_affine_point_get.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/range_affine_point_get.test.cpp
layout: document
redirect_from:
- /verify/test/range_affine_point_get.test.cpp
- /verify/test/range_affine_point_get.test.cpp.html
title: test/range_affine_point_get.test.cpp
---
