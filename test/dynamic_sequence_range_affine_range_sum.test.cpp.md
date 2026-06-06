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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../ds/treap.cpp\"\n#include \"../actedmonoid/actedMonoid_affineSum.cpp\"\
    \n\nusing am = actedMonoid_affineSum<mint>;\nusing Treap = treap<am::M, am::Mid,\
    \ am::Mop, am::T, am::Tid, am::Top, am::act>;\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<array<mint, 2>> a(n,\
    \ {0, 1});\n  for(auto &[x, _] : a)\n    cin >> x;\n\n  Treap::node* tr = Treap::build(a);\n\
    \n  while(q--) {\n    int t; cin >> t;\n    if (t == 0) {\n      int i, x; cin\
    \ >> i >> x;\n      Treap::insert(tr, i, {x, 1});\n    } else if (t == 1) {\n\
    \      int i; cin >> i;\n      Treap::erase(tr, i);\n    } else if (t == 2) {\n\
    \      int l, r; cin >> l >> r;\n      Treap::modify(tr, l, r, am::Tid(), true);\n\
    \    } else if (t == 3) {\n      int l, r, b, c; cin >> l >> r >> b >> c;\n  \
    \    Treap::modify(tr, l, r, {b, c});\n    } else if (t == 4) {\n      int l,\
    \ r; cin >> l >> r;\n      cout << Treap::query(tr, l, r)[0] << '\\n';\n    }\n\
    \  }\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/dynamic_sequence_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/dynamic_sequence_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_sequence_range_affine_range_sum.test.cpp
- /verify/test/dynamic_sequence_range_affine_range_sum.test.cpp.html
title: test/dynamic_sequence_range_affine_range_sum.test.cpp
---
