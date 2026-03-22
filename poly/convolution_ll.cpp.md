---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/frequency_table_of_tree_distance.test.cpp
    title: test/frequency_table_of_tree_distance.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/convolution_ll.cpp\"\n//the result should not exceed\
    \ long long\nvll convolution_ll(vll a, vll b) {\n  assert(ssize(a) + ssize(b)\
    \ - 1 <= (1 << 23));\n  using Mint0 = MontgomeryModInt<998244353>;\n  using Mint1\
    \ = MontgomeryModInt<469762049>;\n  using Mint2 = MontgomeryModInt<167772161>;\n\
    \  NTT<23, 119, 3, Mint0> ntt0;\n  NTT<26, 7, 3, Mint1> ntt1;\n  NTT<25, 5, 3,\
    \ Mint2> ntt2;\n  vector<Mint0> a0(size(a)), b0(size(b));\n  vector<Mint1> a1(size(a)),\
    \ b1(size(b));\n  vector<Mint2> a2(size(a)), b2(size(b));\n  for(int i = 0; i\
    \ < ssize(a); i++)\n    a0[i] = a[i], a1[i] = a[i], a2[i] = a[i];\n  for(int i\
    \ = 0; i < ssize(b); i++)\n    b0[i] = b[i], b1[i] = b[i], b2[i] = b[i];\n  vector<Mint0>\
    \ x = ntt0.conv(a0, b0);\n  vector<Mint1> y = ntt1.conv(a1, b1);\n  vector<Mint2>\
    \ z = ntt2.conv(a2, b2);\n  vll res(size(x));\n  constexpr uint32_t mod0 = ntt0.get_mod(),\
    \ mod1 = ntt1.get_mod();\n  static const Mint1 im0 = 1 / Mint1(mod0);\n  static\
    \ const Mint2 im1 = 1 / Mint2(mod1), im0m1 = im1 / mod0;\n  static const ll m0\
    \ = mod0, m0m1 = m0 * mod1;\n  for(int i = 0; i < ssize(x); i++) {\n    int y0\
    \ = x[i].get();\n    int y1 = (im0 * (y[i] - y0)).get();\n    int y2 = (im0m1\
    \ * (z[i] - y0) - im1 * y1).get();\n    res[i] = y0 + m0 * y1 + m0m1 * y2;\n \
    \ }\n\n  return res;\n}\n\nvll convolution_self_ll(vll a) {\n  assert(2 * ssize(a)\
    \ - 1 <= (1 << 23));\n  using Mint0 = MontgomeryModInt<998244353>;\n  using Mint1\
    \ = MontgomeryModInt<469762049>;\n  using Mint2 = MontgomeryModInt<167772161>;\n\
    \  NTT<23, 119, 3, Mint0> ntt0;\n  NTT<26, 7, 3, Mint1> ntt1;\n  NTT<25, 5, 3,\
    \ Mint2> ntt2;\n  const int sz = bit_ceil((ull)(2 * ssize(a) - 1));\n  vector<Mint0>\
    \ a0(sz);\n  vector<Mint1> a1(sz);\n  vector<Mint2> a2(sz);\n  for(int i = 0;\
    \ i < ssize(a); i++)\n    a0[i] = a[i], a1[i] = a[i], a2[i] = a[i];\n  ntt0.ntt(a0,\
    \ false);\n  ntt1.ntt(a1, false);\n  ntt2.ntt(a2, false);\n  for(int i = 0; i\
    \ < sz; i++)\n    a0[i] *= a0[i], a1[i] *= a1[i], a2[i] *= a2[i];\n  ntt0.ntt(a0,\
    \ true);\n  ntt1.ntt(a1, true);\n  ntt2.ntt(a2, true);\n  vll res(sz);\n  constexpr\
    \ uint32_t mod0 = ntt0.get_mod(), mod1 = ntt1.get_mod();\n  static const Mint1\
    \ im0 = 1 / Mint1(mod0);\n  static const Mint2 im1 = 1 / Mint2(mod1), im0m1 =\
    \ im1 / mod0;\n  static const ll m0 = mod0, m0m1 = m0 * mod1;\n  for(int i = 0;\
    \ i < sz; i++) {\n    int y0 = a0[i].get();\n    int y1 = (im0 * (a1[i] - y0)).get();\n\
    \    int y2 = (im0m1 * (a2[i] - y0) - im1 * y1).get();\n    res[i] = y0 + m0 *\
    \ y1 + m0m1 * y2;\n  }\n\n  return res;\n}\n\n"
  code: "//the result should not exceed long long\nvll convolution_ll(vll a, vll b)\
    \ {\n  assert(ssize(a) + ssize(b) - 1 <= (1 << 23));\n  using Mint0 = MontgomeryModInt<998244353>;\n\
    \  using Mint1 = MontgomeryModInt<469762049>;\n  using Mint2 = MontgomeryModInt<167772161>;\n\
    \  NTT<23, 119, 3, Mint0> ntt0;\n  NTT<26, 7, 3, Mint1> ntt1;\n  NTT<25, 5, 3,\
    \ Mint2> ntt2;\n  vector<Mint0> a0(size(a)), b0(size(b));\n  vector<Mint1> a1(size(a)),\
    \ b1(size(b));\n  vector<Mint2> a2(size(a)), b2(size(b));\n  for(int i = 0; i\
    \ < ssize(a); i++)\n    a0[i] = a[i], a1[i] = a[i], a2[i] = a[i];\n  for(int i\
    \ = 0; i < ssize(b); i++)\n    b0[i] = b[i], b1[i] = b[i], b2[i] = b[i];\n  vector<Mint0>\
    \ x = ntt0.conv(a0, b0);\n  vector<Mint1> y = ntt1.conv(a1, b1);\n  vector<Mint2>\
    \ z = ntt2.conv(a2, b2);\n  vll res(size(x));\n  constexpr uint32_t mod0 = ntt0.get_mod(),\
    \ mod1 = ntt1.get_mod();\n  static const Mint1 im0 = 1 / Mint1(mod0);\n  static\
    \ const Mint2 im1 = 1 / Mint2(mod1), im0m1 = im1 / mod0;\n  static const ll m0\
    \ = mod0, m0m1 = m0 * mod1;\n  for(int i = 0; i < ssize(x); i++) {\n    int y0\
    \ = x[i].get();\n    int y1 = (im0 * (y[i] - y0)).get();\n    int y2 = (im0m1\
    \ * (z[i] - y0) - im1 * y1).get();\n    res[i] = y0 + m0 * y1 + m0m1 * y2;\n \
    \ }\n\n  return res;\n}\n\nvll convolution_self_ll(vll a) {\n  assert(2 * ssize(a)\
    \ - 1 <= (1 << 23));\n  using Mint0 = MontgomeryModInt<998244353>;\n  using Mint1\
    \ = MontgomeryModInt<469762049>;\n  using Mint2 = MontgomeryModInt<167772161>;\n\
    \  NTT<23, 119, 3, Mint0> ntt0;\n  NTT<26, 7, 3, Mint1> ntt1;\n  NTT<25, 5, 3,\
    \ Mint2> ntt2;\n  const int sz = bit_ceil((ull)(2 * ssize(a) - 1));\n  vector<Mint0>\
    \ a0(sz);\n  vector<Mint1> a1(sz);\n  vector<Mint2> a2(sz);\n  for(int i = 0;\
    \ i < ssize(a); i++)\n    a0[i] = a[i], a1[i] = a[i], a2[i] = a[i];\n  ntt0.ntt(a0,\
    \ false);\n  ntt1.ntt(a1, false);\n  ntt2.ntt(a2, false);\n  for(int i = 0; i\
    \ < sz; i++)\n    a0[i] *= a0[i], a1[i] *= a1[i], a2[i] *= a2[i];\n  ntt0.ntt(a0,\
    \ true);\n  ntt1.ntt(a1, true);\n  ntt2.ntt(a2, true);\n  vll res(sz);\n  constexpr\
    \ uint32_t mod0 = ntt0.get_mod(), mod1 = ntt1.get_mod();\n  static const Mint1\
    \ im0 = 1 / Mint1(mod0);\n  static const Mint2 im1 = 1 / Mint2(mod1), im0m1 =\
    \ im1 / mod0;\n  static const ll m0 = mod0, m0m1 = m0 * mod1;\n  for(int i = 0;\
    \ i < sz; i++) {\n    int y0 = a0[i].get();\n    int y1 = (im0 * (a1[i] - y0)).get();\n\
    \    int y2 = (im0m1 * (a2[i] - y0) - im1 * y1).get();\n    res[i] = y0 + m0 *\
    \ y1 + m0m1 * y2;\n  }\n\n  return res;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/convolution_ll.cpp
  requiredBy: []
  timestamp: '2026-03-22 16:32:23+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/frequency_table_of_tree_distance.test.cpp
documentation_of: poly/convolution_ll.cpp
layout: document
redirect_from:
- /library/poly/convolution_ll.cpp
- /library/poly/convolution_ll.cpp.html
title: poly/convolution_ll.cpp
---
