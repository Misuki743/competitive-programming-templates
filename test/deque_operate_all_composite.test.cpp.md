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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../ds/deque_aggregation.cpp\"\n\nusing M = array<mint, 2>;\nM op(const\
    \ M &m, const M &n) {\n  return M{m[0] * n[0], m[1] * n[0] + n[1]};\n}\nM id()\
    \ { return M{1, 0}; }\n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\
    \n  int q; cin >> q;\n  deque_aggregation<M, id, op> dq;\n  while(q--) {\n   \
    \ int op; cin >> op;\n    if (op == 0) {\n      int a, b; cin >> a >> b;\n   \
    \   dq.push_front(M{a, b});\n    } else if (op == 1) {\n      int a, b; cin >>\
    \ a >> b;\n      dq.push_back(M{a, b});\n    } else if (op == 2) {\n      dq.pop_front();\n\
    \    } else if (op == 3) {\n      dq.pop_back();\n    } else {\n      int x; cin\
    \ >> x;\n      auto [a, b] = dq.query();\n      cout << a * x + b << '\\n';\n\
    \    }\n  }\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/deque_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/deque_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/deque_operate_all_composite.test.cpp
- /verify/test/deque_operate_all_composite.test.cpp.html
title: test/deque_operate_all_composite.test.cpp
---
