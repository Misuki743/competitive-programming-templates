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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../ds/fenwickTree2D.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../ds/fenwickTree2D.cpp\"\n#include\
    \ \"../misc/compression.cpp\"\n#include \"../ds_problem/pointAddRectangleSum.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ q; cin >> n >> q;\n  vector<tuple<int, int, ll>> pt(n);\n  for(auto &[x, y,\
    \ w] : pt)\n    cin >> x >> y >> w;\n  vector<array<int, 4>> query;\n  vector<int>\
    \ updT(n);\n  while(q--) {\n    int t; cin >> t;\n    if (t == 0) {\n      int\
    \ x, y, w; cin >> x >> y >> w;\n      updT.emplace_back(ssize(query));\n     \
    \ pt.emplace_back(x, y, w);\n    } else if (t == 1) {\n      int l, r, d, u; cin\
    \ >> l >> d >> r >> u;\n      query.push_back({l, r, d, u});\n    }\n  }\n\n \
    \ for(ll x : pointAddRectSum<int, ll>(pt, query, updT))\n    cout << x << '\\\
    n';\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/point_add_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/point_add_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/point_add_rectangle_sum.test.cpp
- /verify/test/point_add_rectangle_sum.test.cpp.html
title: test/point_add_rectangle_sum.test.cpp
---
