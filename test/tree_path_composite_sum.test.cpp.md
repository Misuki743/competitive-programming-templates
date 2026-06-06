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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../tree/HLD.cpp\"\n#include \"../dp/rerooting_DP.cpp\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n; cin >> n;\n\
    \  vector<mint> a(n), b(n - 1), c(n - 1);\n  for(mint &x : a) cin >> x;\n  vc<pii>\
    \ e(n - 1);\n  for(int i = 0; i < n - 1; i++)\n    cin >> e[i].first >> e[i].second\
    \ >> b[i] >> c[i];\n\n  using V = array<mint, 2>;\n  using E = array<mint, 2>;\n\
    \  auto id = [&](int i) { return V{a[i], 1}; };\n  auto add_e = [&](const V &v,\
    \ int i) { return E{b[i] * v[0] + c[i] * v[1], v[1]}; };\n  auto ee = [&](const\
    \ E &l, const E &r) { return E{l[0] + r[0], l[1] + r[1]}; };\n  auto add_v = [&](const\
    \ E &e, int i) { return V{e[0] + a[i], e[1] + 1}; };\n\n  HLD hld(e);\n  for(int\
    \ v = 0; v < n; v++)\n    dbg(v, hld.parent_eid(v));\n  rerooting_DP<V, E> dp(hld,\
    \ id, ee, add_v, add_e);\n  for(int v = 0; v < n; v++)\n    cout << dp[v][0] <<\
    \ \" \\n\"[v + 1 == n];\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/tree_path_composite_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/tree_path_composite_sum.test.cpp
layout: document
redirect_from:
- /verify/test/tree_path_composite_sum.test.cpp
- /verify/test/tree_path_composite_sum.test.cpp.html
title: test/tree_path_composite_sum.test.cpp
---
