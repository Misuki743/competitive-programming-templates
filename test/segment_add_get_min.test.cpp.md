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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../segtree/lichaoSegmentTree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    \n#include \"../default/t.cpp\"\n#include \"../segtree/lichaoSegmentTree.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ q; cin >> n >> q;\n  vector<array<ll, 4>> c(n);\n  for(auto &[l, r, a, b] :\
    \ c)\n    cin >> l >> r >> a >> b;\n  vector<array<ll, 5>> query(q);\n  for(auto\
    \ &[t, x, y, z, w] : query) {\n    cin >> t;\n    if (t == 0)\n      cin >> x\
    \ >> y >> z >> w;\n    else\n      cin >> x;\n  }\n\n  vector<ll> xs;\n  for(auto\
    \ &[l, r, a, b] : c) {\n    xs.emplace_back(l);\n    xs.emplace_back(r);\n  }\n\
    \  for(auto &[t, x, y, z, w] : query) {\n    if (t == 0) {\n      xs.emplace_back(x);\n\
    \      xs.emplace_back(y);\n    } else {\n      xs.emplace_back(x);\n    }\n \
    \ }\n  ranges::sort(xs);\n  xs.resize(unique(xs.begin(), xs.end()) - xs.begin());\n\
    \  for(auto &[l, r, a, b] : c) {\n    l = ranges::lower_bound(xs, l) - xs.begin();\n\
    \    r = ranges::lower_bound(xs, r) - xs.begin();\n  }\n  for(auto &[t, x, y,\
    \ z, w] : query) {\n    if (t == 0) {\n      x = ranges::lower_bound(xs, x) -\
    \ xs.begin();\n      y = ranges::lower_bound(xs, y) - xs.begin();\n    } else\
    \ {\n      x = ranges::lower_bound(xs, x) - xs.begin();\n    }\n  }\n\n  lichaoSegmentTree<ll>\
    \ st(bit_ceil(xs.size()), xs);\n  for(auto &[l, r, a, b] : c)\n    st.insertRange(l,\
    \ r, a, b);\n  for(auto &[t, x, y, z, w] : query) {\n    if (t == 0) {\n     \
    \ st.insertRange(x, y, z, w);\n    } else {\n      if (ll ans = st.query(x); ans\
    \ == LLONG_MAX)\n        cout << \"INFINITY\\n\";\n      else\n        cout <<\
    \ ans << '\\n';\n    }\n      \n  }\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/segment_add_get_min.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/segment_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/segment_add_get_min.test.cpp
- /verify/test/segment_add_get_min.test.cpp.html
title: test/segment_add_get_min.test.cpp
---
