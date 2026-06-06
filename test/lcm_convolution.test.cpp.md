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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\n\n#include\
    \ \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\n#include\
    \ \"../numtheory/linear_sieve.cpp\"\n#include \"../numtheory/zeta_mobius_on_divisibility_lattice.cpp\"\
    \n#include \"../numtheory/lcm_convolution.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  linear_sieve<1'000'001> ls;\n\n  int n; cin >> n;\n  vector<mint>\
    \ a(n), b(n);\n  for(mint &x : a) cin >> x;\n  for(mint &x : b) cin >> x;\n  a.insert(a.begin(),\
    \ mint(0));\n  b.insert(b.begin(), mint(0));\n  auto c = lcm_convolution(ls, a,\
    \ b);\n  c.erase(c.begin());\n  cout << c << '\\n';\n\n  return 0;\n}\n\n"
  dependsOn: []
  isVerificationFile: true
  path: test/lcm_convolution.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/lcm_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/lcm_convolution.test.cpp
- /verify/test/lcm_convolution.test.cpp.html
title: test/lcm_convolution.test.cpp
---
