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
  bundledCode: "#line 1 \"ds/dynamic_kth.cpp\"\ntemplate<class T>\nstruct dynamic_kth\
    \ {\n  multiset<T> D, U;\n  T Dsum = 0, Usum = 0;\n  void slide(int k) { //make\
    \ |D| = k\n    while(ssize(D) > k) {\n      T x = *D.rbegin();\n      Usum +=\
    \ x, Dsum -= x;\n      U.insert(x);\n      D.erase(prev(D.end()));\n    }\n  \
    \  while(ssize(D) < k and !U.empty()) {\n      T x = *U.begin();\n      Dsum +=\
    \ x, Usum -= x;\n      D.insert(x);\n      U.erase(U.begin());\n    }\n  }\n \
    \ void insert(T x) {\n    if ((U.empty() and (D.empty() or x > *D.rbegin())) or\
    \ (!U.empty() and x >= *U.begin()))\n      U.insert(x), Usum += x;\n    else\n\
    \      D.insert(x), Dsum += x;\n  }\n  void erase(T x) {\n    if (auto ite = U.find(x);\
    \ ite != U.end())\n      U.erase(ite), Usum -= x;\n    else if (auto ite2 = D.find(x);\
    \ ite2 != D.end())\n      D.erase(ite2), Dsum -= x;\n  }\n  T kth(int k) { slide(k);\
    \ assert(!U.empty()); return *U.begin(); }\n  T min() { return D.empty() ? *U.begin()\
    \ : *D.begin(); }\n  T max() { return U.empty() ? *D.rbegin() : *U.rbegin(); }\n\
    \  uint64_t size() { return ssize(D) + ssize(U); }\n};\n"
  code: "template<class T>\nstruct dynamic_kth {\n  multiset<T> D, U;\n  T Dsum =\
    \ 0, Usum = 0;\n  void slide(int k) { //make |D| = k\n    while(ssize(D) > k)\
    \ {\n      T x = *D.rbegin();\n      Usum += x, Dsum -= x;\n      U.insert(x);\n\
    \      D.erase(prev(D.end()));\n    }\n    while(ssize(D) < k and !U.empty())\
    \ {\n      T x = *U.begin();\n      Dsum += x, Usum -= x;\n      D.insert(x);\n\
    \      U.erase(U.begin());\n    }\n  }\n  void insert(T x) {\n    if ((U.empty()\
    \ and (D.empty() or x > *D.rbegin())) or (!U.empty() and x >= *U.begin()))\n \
    \     U.insert(x), Usum += x;\n    else\n      D.insert(x), Dsum += x;\n  }\n\
    \  void erase(T x) {\n    if (auto ite = U.find(x); ite != U.end())\n      U.erase(ite),\
    \ Usum -= x;\n    else if (auto ite2 = D.find(x); ite2 != D.end())\n      D.erase(ite2),\
    \ Dsum -= x;\n  }\n  T kth(int k) { slide(k); assert(!U.empty()); return *U.begin();\
    \ }\n  T min() { return D.empty() ? *U.begin() : *D.begin(); }\n  T max() { return\
    \ U.empty() ? *D.rbegin() : *U.rbegin(); }\n  uint64_t size() { return ssize(D)\
    \ + ssize(U); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/dynamic_kth.cpp
  requiredBy: []
  timestamp: '2026-03-22 18:39:18+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/dynamic_kth.cpp
layout: document
redirect_from:
- /library/ds/dynamic_kth.cpp
- /library/ds/dynamic_kth.cpp.html
title: ds/dynamic_kth.cpp
---
