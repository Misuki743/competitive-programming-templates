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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../ds/DSU/potential_DSU.cpp\"\n\nint main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  using M = array<mint, 4>;\n\
    \  potential_DSU dsu(n, M{1, 0, 0, 1},\n    [](M a, M b) { return M{a[0] * b[0]\
    \ + a[1] * b[2], a[0] * b[1] + a[1] * b[3],\n                            a[2]\
    \ * b[0] + a[3] * b[2], a[2] * b[1] + a[3] * b[3]}; },\n    [](M a) { return M{a[3],\
    \ -a[1], -a[2], a[0]}; }\n  );\n\n  while(q--) {\n    int op; cin >> op;\n   \
    \ if (op == 0) {\n      int u, v; cin >> u >> v;\n      M m;\n      for(mint &x\
    \ : m) cin >> x;\n      cout << dsu.merge(v, u, m) << '\\n';\n    } else {\n \
    \     int u, v; cin >> u >> v;\n      if (dsu.query(u) != dsu.query(v))\n    \
    \    cout << -1 << '\\n';\n      else\n        cout << dsu.query(v, u) << '\\\
    n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/unionfind_with_potential_non_commutative_group.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unionfind_with_potential_non_commutative_group.test.cpp
layout: document
redirect_from:
- /verify/test/unionfind_with_potential_non_commutative_group.test.cpp
- /verify/test/unionfind_with_potential_non_commutative_group.test.cpp.html
title: test/unionfind_with_potential_non_commutative_group.test.cpp
---
