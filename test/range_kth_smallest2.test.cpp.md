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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../segtree/persistentSegmentTree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../default/t.cpp\"\n#include \"../misc/compression.cpp\"\n#include\
    \ \"../segtree/persistentSegmentTree.cpp\"\n\nint id() { return 0; }\nint op(const\
    \ int &a, const int &b) { return a + b; }\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<int> a(n);\n  for(int\
    \ &x : a)\n    cin >> x;\n\n  compression<int, true> xs(a);\n  persistentSegmentTree<int,\
    \ id, op> st(2 * n + n * (bit_width((unsigned)n) + 1));\n  vector<int> root(n\
    \ + 1);\n  root[0] = st.build(0, n);\n  for(int i = 1; i <= n; i++)\n    root[i]\
    \ = st.set(root[i - 1], 0, n, xs.ord[i - 1], 1);\n\n  while(q--) {\n    int l,\
    \ r, k; cin >> l >> r >> k;\n    int u = root[l], v = root[r];\n    int ql = 0,\
    \ qr = n;\n    while(ql + 1 < qr) {\n      int mid = (ql + qr) / 2;\n      if\
    \ (int cnt = st.data[st.lc[v]] - st.data[st.lc[u]]; cnt <= k)\n        k -= cnt,\
    \ u = st.rc[u], v = st.rc[v], ql = mid;\n      else\n        u = st.lc[u], v =\
    \ st.lc[v], qr = mid;\n    }\n    cout << xs.val[ql] << '\\n';\n  }\n\n  return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/range_kth_smallest2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/range_kth_smallest2.test.cpp
layout: document
redirect_from:
- /verify/test/range_kth_smallest2.test.cpp
- /verify/test/range_kth_smallest2.test.cpp.html
title: test/range_kth_smallest2.test.cpp
---
