---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds_problem/rollback_MO.cpp\"\n//only for small data structure\n\
    //init(ql): init for (ql, 0)\ntemplate<class T, typename F, typename G, typename\
    \ H>\nrequires R_invocable<T, F, int> &&\n         R_invocable<void, G, T&, int,\
    \ int> && (!R_invocable<void, G, T, int, int>) &&\n         R_invocable<void,\
    \ H, T&, int, int> && (!R_invocable<void, H, T, int, int>)\nvc<T> rollback_MO(vc<pii>\
    \ qry, F init, G dec_l, H inc_r) {\n  int n = 1;\n  for(auto [l, r] : qry) chmax(n,\
    \ r);\n\n  const int B = ceilDiv(n, (int)(kth_root(ssize(qry), 2) + 1));\n\n \
    \ vc<T> sol(size(qry));\n  auto ord = argSort(qry, [B](auto pr) { return pii(pr.first\
    \ / B, pr.second); });\n  for(auto [l, r] : equal_subarrays(ord, [&](int i) {\
    \ return qry[i].first / B; })) {\n    int ql = (qry[ord[l]].first / B + 1) * B;\n\
    \    int qr = 0;\n    T ans = init(ql);\n    for(int i : views::counted(ord.begin()\
    \ + l, r - l)) {\n      while(qr < qry[i].second) inc_r(ans, ql, qr++);\n    \
    \  T tmp = ans;\n      for(int j = ql; j > qry[i].first; j--) dec_l(tmp, j, qr);\n\
    \      sol[i] = tmp;\n    }\n  }\n\n  return sol;\n}\n"
  code: "//only for small data structure\n//init(ql): init for (ql, 0)\ntemplate<class\
    \ T, typename F, typename G, typename H>\nrequires R_invocable<T, F, int> &&\n\
    \         R_invocable<void, G, T&, int, int> && (!R_invocable<void, G, T, int,\
    \ int>) &&\n         R_invocable<void, H, T&, int, int> && (!R_invocable<void,\
    \ H, T, int, int>)\nvc<T> rollback_MO(vc<pii> qry, F init, G dec_l, H inc_r) {\n\
    \  int n = 1;\n  for(auto [l, r] : qry) chmax(n, r);\n\n  const int B = ceilDiv(n,\
    \ (int)(kth_root(ssize(qry), 2) + 1));\n\n  vc<T> sol(size(qry));\n  auto ord\
    \ = argSort(qry, [B](auto pr) { return pii(pr.first / B, pr.second); });\n  for(auto\
    \ [l, r] : equal_subarrays(ord, [&](int i) { return qry[i].first / B; })) {\n\
    \    int ql = (qry[ord[l]].first / B + 1) * B;\n    int qr = 0;\n    T ans = init(ql);\n\
    \    for(int i : views::counted(ord.begin() + l, r - l)) {\n      while(qr < qry[i].second)\
    \ inc_r(ans, ql, qr++);\n      T tmp = ans;\n      for(int j = ql; j > qry[i].first;\
    \ j--) dec_l(tmp, j, qr);\n      sol[i] = tmp;\n    }\n  }\n\n  return sol;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: ds_problem/rollback_MO.cpp
  requiredBy: []
  timestamp: '2026-08-31 15:15:01+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds_problem/rollback_MO.cpp
layout: document
redirect_from:
- /library/ds_problem/rollback_MO.cpp
- /library/ds_problem/rollback_MO.cpp.html
title: ds_problem/rollback_MO.cpp
---
