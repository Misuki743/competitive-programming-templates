---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.7/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.7/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.7/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.14.7/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../numtheory/phi_array.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/Montgomery_modint.cpp\"\
    \n#include \"../numtheory/linear_sieve.cpp\"\n#include \"../numtheory/phi_array.cpp\"\
    \n#include \"../numtheory/prefix_sum_of_dirichlet_inverse.cpp\"\n\nauto F_small\
    \ = phi_array<mint, 8'000'000>();\n\nint main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  psum(F_small);\n\n  ll N; cin >> N;\n  cout << prefix_sum_of_dirichlet_inverse<mint>(N,\
    \ [](ll x) { return mint(x); }, [](ll x) { return x % 2 == 1 ? (x + 1) / 2 * mint(x)\
    \ : x / 2 * mint(x + 1); }, F_small).back() << '\\n';\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/sum_of_totient_function.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/sum_of_totient_function.test.cpp
layout: document
redirect_from:
- /verify/test/sum_of_totient_function.test.cpp
- /verify/test/sum_of_totient_function.test.cpp.html
title: test/sum_of_totient_function.test.cpp
---
