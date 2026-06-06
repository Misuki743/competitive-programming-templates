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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../actedmonoid/add_min.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_add_range_min\"\n\
    \n#include \"../default/t.cpp\"\n#include \"../segtree/lazy_segment_tree.cpp\"\
    \n#include \"../segtree/acted_monoid_segment_tree.cpp\"\n#include \"../actedmonoid/add_min.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q;\
    \ cin >> n >> q;\n  vector<ll> a(n);\n  for(ll &x : a) cin >> x;\n  acted_monoid_segment_tree<add_min<ll>>\
    \ st(a);\n\n  while(q--) {\n    int op, l, r; cin >> op >> l >> r;\n    if (op\
    \ == 0) {\n      int x; cin >> x;\n      st.modify(l, r, x);\n    } else {\n \
    \     cout << st.query(l, r) << '\\n';\n    }\n  }\n\n  return 0;\n}\n\n"
  dependsOn: []
  isVerificationFile: true
  path: test/range_add_range_min.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/range_add_range_min.test.cpp
layout: document
redirect_from:
- /verify/test/range_add_range_min.test.cpp
- /verify/test/range_add_range_min.test.cpp.html
title: test/range_add_range_min.test.cpp
---
