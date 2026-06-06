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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../ds/fenwickTree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../ds/fenwickTree.cpp\"\n#include\
    \ \"../ds/wavelet_matrix.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vc<tuple<int, int, int>> xyw(n);\n\
    \  for(auto &[x, y, w] : xyw) \n    cin >> x >> y >> w;\n  vc<array<int, 5>> qry(q);\n\
    \  for(auto &[op, x, y, z, w] : qry) {\n    cin >> op >> x >> y >> z;\n    if\
    \ (op == 0) {\n      xyw.eb(x, y, z);\n    } else {\n      cin >> w;\n    }\n\
    \  }\n\n  vi xs, ys;\n  for(auto [x, y, w] : xyw)\n    xs.eb(x), ys.eb(y);\n \
    \ ranges::sort(xs), ranges::sort(ys);\n\n  vi tx(size(xyw)), ty(size(xyw));\n\
    \  for(auto &[x, y, w] : xyw) {\n    int xi = ranges::lower_bound(xs, x) - xs.begin();\n\
    \    x = xi + tx[xi]++;\n    y = ranges::lower_bound(ys, y) - ys.begin();\n  }\n\
    \n  vi a(size(xyw)), z(size(xyw));\n  for(int i = 0; auto [x, y, w] : xyw)\n \
    \   a[x] = y, z[x] = (i++ < n ? w : 0);\n\n  wavelet_matrix<int, 19> WM(a, 1);\n\
    \  vc<fenwickTree<ll>> ft;\n  for(auto &p : WM.perms) {\n    vll init(size(xyw));\n\
    \    for(int j = 0; j < size(xyw); j++)\n      init[j] = z[p[j]];\n    ft.eb(init);\n\
    \  }\n\n  for(auto [op, x, y, z, w] : qry) {\n    if (op == 0) {\n      auto [X,\
    \ Y, W] = xyw[n++];\n      WM.point_update(X, [&](int i, int j) {\n        ft[i].add(j,\
    \ W);\n      });\n    } else {\n      x = ranges::lower_bound(xs, x) - xs.begin();\n\
    \      z = ranges::lower_bound(xs, z) - xs.begin();\n      y = ranges::lower_bound(ys,\
    \ y) - ys.begin();\n      w = ranges::lower_bound(ys, w) - ys.begin();\n\n   \
    \   ll ans = 0;\n      WM.rect_query(x, z, y, w, [&](int I, int L, int R) {\n\
    \        dbg(I, L, R);\n        ans += ft[I].query(L, R);\n      });\n      cout\
    \ << ans << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/point_add_rectangle_sum2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/point_add_rectangle_sum2.test.cpp
layout: document
redirect_from:
- /verify/test/point_add_rectangle_sum2.test.cpp
- /verify/test/point_add_rectangle_sum2.test.cpp.html
title: test/point_add_rectangle_sum2.test.cpp
---
