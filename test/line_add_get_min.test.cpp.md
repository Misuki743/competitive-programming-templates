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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include \"../default/t.cpp\"\n#include \"../segtree/lichaoSegmentTree.cpp\"\n\
    \nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q;\
    \ cin >> n >> q;\n  vector<array<ll, 2>> ab(n);\n  for(auto &[a, b] : ab)\n  \
    \  cin >> a >> b;\n  vector<array<ll, 3>> query(q);\n  for(auto &[t, a, b] : query)\
    \ {\n    cin >> t >> a;\n    if (t == 0)\n      cin >> b;\n  }\n\n  vector<ll>\
    \ pt;\n  for(auto [t, a, b] : query)\n    if (t == 1)\n      pt.emplace_back(a);\n\
    \n  ranges::sort(pt);\n  pt.resize(unique(pt.begin(), pt.end()) - pt.begin());\n\
    \  for(auto &[t, a, b] : query)\n    if (t == 1)\n      a = ranges::lower_bound(pt,\
    \ a) - pt.begin();\n\n  lichaoSegmentTree<ll> st(bit_ceil((unsigned)q), pt);\n\
    \  for(auto [a, b] : ab)\n    st.insert(1, a, b);\n  for(auto [t, a, b] : query)\
    \ {\n    if (t == 0)\n      st.insert(1, a, b);\n    else\n      cout << st.query(a)\
    \ << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/line_add_get_min.test.cpp
- /verify/test/line_add_get_min.test.cpp.html
title: test/line_add_get_min.test.cpp
---
