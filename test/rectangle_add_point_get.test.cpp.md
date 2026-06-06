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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_add_point_get\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../ds/fenwickTree2D.cpp\"\n#include\
    \ \"../misc/compression.cpp\"\n#include \"../ds_problem/rectangleAddPointGet.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ q; cin >> n >> q;\n  vector<tuple<int, int, int, int, ll>> rect(n);\n  for(auto\
    \ &[l, r, d, u, w] : rect)\n    cin >> l >> d >> r >> u >> w;\n  vector<array<int,\
    \ 2>> query;\n  vector<int> updT(n, 0);\n  while(q--) {\n    int op; cin >> op;\n\
    \    if (op == 0) {\n      int l, d, r, u; cin >> l >> d >> r >> u;\n      ll\
    \ w; cin >> w;\n      rect.emplace_back(l, r, d, u, w);\n      updT.emplace_back(ssize(query));\n\
    \    } else if (op == 1) {\n      int x, y; cin >> x >> y;\n      query.push_back({x,\
    \ y});\n    }\n  }\n\n  for(ll ans : rectAddPointGet<int, ll>(rect, query, updT))\n\
    \    cout << ans << '\\n';\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/rectangle_add_point_get.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/rectangle_add_point_get.test.cpp
layout: document
redirect_from:
- /verify/test/rectangle_add_point_get.test.cpp
- /verify/test/rectangle_add_point_get.test.cpp.html
title: test/rectangle_add_point_get.test.cpp
---
