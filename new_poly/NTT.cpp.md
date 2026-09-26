---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution_1e9+7_2.test.cpp
    title: test/convolution_1e9+7_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution_2.test.cpp
    title: test/convolution_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"new_poly/NTT.cpp\"\nnamespace NTT {\n  template<class Mint>\n\
    \  void DFT(vc<Mint> &a, bool inv) {\n    static array<Mint, 30> w, w_inv;\n\n\
    \    if (w[0] == 0) {\n      int mod = Mint::get_mod();\n      Mint r = 2;\n \
    \     while(r.pow((mod - 1) / 2) == 1) r += 1;\n      for(int i = 0; i < 30; i++)\n\
    \        w[i] = -(r.pow((mod - 1) >> (i + 2))), w_inv[i] = 1 / w[i];\n    }\n\n\
    \    int n = ssize(a);\n    if (!inv) {\n      for(int m = n; m >>= 1; ) {\n \
    \       Mint ww = 1;\n        for(int s = 0, l = 0; s < n; s += 2 * m) {\n   \
    \       for(int i = s, j = s + m; i < s + m; i++, j++) {\n            Mint x =\
    \ a[i], y = a[j] * ww;\n            a[i] = x + y, a[j] = x - y;\n          }\n\
    \          ww *= w[__builtin_ctz(++l)];\n        }\n      }\n    } else {\n  \
    \    for(int m = 1; m < n; m *= 2) {\n        Mint ww = 1;\n        for(int s\
    \ = 0, l = 0; s < n; s += 2 * m) {\n          for(int i = s, j = s + m; i < s\
    \ + m; i++, j++) {\n            Mint x = a[i], y = a[j];\n            a[i] = x\
    \ + y, a[j] = (x - y) * ww;\n          }\n          ww *= w_inv[__builtin_ctz(++l)];\n\
    \        }\n      }\n      for(Mint i = Mint(n).inverse(); Mint &x : a) x *= i;\n\
    \    }\n  }\n\n  template<bool neg_b = false, class Mint>\n  vc<Mint> convolution(vc<Mint>\
    \ a, vc<Mint> b) {\n    if (empty(a) or empty(b)) return {};\n    int sz = ssize(a)\
    \ + ssize(b) - 1;\n    int n = bit_ceil(sz * 1ull);\n\n    a.resize(n, 0), DFT(a,\
    \ false);\n    b.resize(n, 0);\n    if constexpr (neg_b)\n      ranges::reverse(b\
    \ | views::drop(1));\n    DFT(b, false);\n\n    for(int i = 0; i < n; i++)\n \
    \     a[i] *= b[i];\n\n    DFT(a, true);\n    if constexpr (!neg_b)\n      a.resize(sz);\n\
    \n    return a;\n  }\n\n  template<class Mint>\n  vc<Mint> full_pow(vc<Mint> a,\
    \ int e) {\n    if (e == 0) return vc<Mint>(1, 1);\n\n    int sz = (ssize(a) -\
    \ 1) * e + 1;\n    a.resize(bit_ceil(sz * 1ull));\n    DFT(a, 0);\n    for(Mint\
    \ &x : a) x = x.pow(e);\n    DFT(a, 1);\n    a.resize(sz);\n\n    return a;\n\
    \  }\n\n  template<class T1, class T2>\n  vc<T1> vec_conversion(vc<T2> &a) {\n\
    \    vc<T1> r(size(a));\n    for(int i = 0; i < ssize(a); i++) {\n      if constexpr\
    \ (is_integral_v<T2>)\n        r[i] = a[i];\n      else\n        r[i] = a[i].get();\n\
    \    }\n    return r;\n  }\n\n  using Mint0 = Montgomery_modint<998'244'353>;\n\
    \  using Mint1 = Montgomery_modint<469'762'049>;\n  using Mint2 = Montgomery_modint<167'772'161>;\n\
    \n  //(T1 = mint): n * mod^2 < prod of mods(~= 5e26) should hold\n  //(T1 = ll):\
    \ result should be within long long\n  template<class T1, class T2>\n  vc<T1>\
    \ convolution_CRT(vc<T2> a, vc<T2> b) {\n    if (empty(a) or empty(b)) return\
    \ {};\n\n    auto x = convolution(vec_conversion<Mint0>(a),\n                \
    \         vec_conversion<Mint0>(b));\n    auto y = convolution(vec_conversion<Mint1>(a),\n\
    \                         vec_conversion<Mint1>(b));\n    auto z = convolution(vec_conversion<Mint2>(a),\n\
    \                         vec_conversion<Mint2>(b));\n\n    static constexpr uint32_t\
    \ mod0 = 998'244'353, mod1 = 469'762'049;\n    static const Mint1 im0 = 1 / Mint1(mod0);\n\
    \    static const Mint2 im1 = 1 / Mint2(mod1), im0m1 = im1 / mod0;\n    static\
    \ const T1 m0 = mod0, m0m1 = m0 * mod1;\n\n    vc<T1> r(size(x));\n    for(int\
    \ i = 0; i < ssize(x); i++) {\n      int y0 = x[i].get();\n      int y1 = (im0\
    \ * (y[i] - y0)).get();\n      int y2 = (im0m1 * (z[i] - y0) - im1 * y1).get();\n\
    \      r[i] = y0 + m0 * y1 + m0m1 * y2;\n    }\n\n    return r;\n  }\n\n  template<class\
    \ T1, class T2>\n  vc<T1> full_pow_CRT(vc<T2> a, int e) {\n    if (e == 0) return\
    \ vc<T1>(1, 1);\n\n    auto x = full_pow(vec_conversion<Mint0>(a), 2);\n    auto\
    \ y = full_pow(vec_conversion<Mint1>(a), 2);\n    auto z = full_pow(vec_conversion<Mint2>(a),\
    \ 2);\n\n    static constexpr uint32_t mod0 = 998'244'353, mod1 = 469'762'049;\n\
    \    static const Mint1 im0 = 1 / Mint1(mod0);\n    static const Mint2 im1 = 1\
    \ / Mint2(mod1), im0m1 = im1 / mod0;\n    static const T1 m0 = mod0, m0m1 = m0\
    \ * mod1;\n\n    vc<T1> r(size(x));\n    for(int i = 0; i < ssize(x); i++) {\n\
    \      int y0 = x[i].get();\n      int y1 = (im0 * (y[i] - y0)).get();\n     \
    \ int y2 = (im0m1 * (z[i] - y0) - im1 * y1).get();\n      r[i] = y0 + m0 * y1\
    \ + m0m1 * y2;\n    }\n\n    return r;\n  }\n}\n\nusing namespace NTT;\n"
  code: "namespace NTT {\n  template<class Mint>\n  void DFT(vc<Mint> &a, bool inv)\
    \ {\n    static array<Mint, 30> w, w_inv;\n\n    if (w[0] == 0) {\n      int mod\
    \ = Mint::get_mod();\n      Mint r = 2;\n      while(r.pow((mod - 1) / 2) == 1)\
    \ r += 1;\n      for(int i = 0; i < 30; i++)\n        w[i] = -(r.pow((mod - 1)\
    \ >> (i + 2))), w_inv[i] = 1 / w[i];\n    }\n\n    int n = ssize(a);\n    if (!inv)\
    \ {\n      for(int m = n; m >>= 1; ) {\n        Mint ww = 1;\n        for(int\
    \ s = 0, l = 0; s < n; s += 2 * m) {\n          for(int i = s, j = s + m; i <\
    \ s + m; i++, j++) {\n            Mint x = a[i], y = a[j] * ww;\n            a[i]\
    \ = x + y, a[j] = x - y;\n          }\n          ww *= w[__builtin_ctz(++l)];\n\
    \        }\n      }\n    } else {\n      for(int m = 1; m < n; m *= 2) {\n   \
    \     Mint ww = 1;\n        for(int s = 0, l = 0; s < n; s += 2 * m) {\n     \
    \     for(int i = s, j = s + m; i < s + m; i++, j++) {\n            Mint x = a[i],\
    \ y = a[j];\n            a[i] = x + y, a[j] = (x - y) * ww;\n          }\n   \
    \       ww *= w_inv[__builtin_ctz(++l)];\n        }\n      }\n      for(Mint i\
    \ = Mint(n).inverse(); Mint &x : a) x *= i;\n    }\n  }\n\n  template<bool neg_b\
    \ = false, class Mint>\n  vc<Mint> convolution(vc<Mint> a, vc<Mint> b) {\n   \
    \ if (empty(a) or empty(b)) return {};\n    int sz = ssize(a) + ssize(b) - 1;\n\
    \    int n = bit_ceil(sz * 1ull);\n\n    a.resize(n, 0), DFT(a, false);\n    b.resize(n,\
    \ 0);\n    if constexpr (neg_b)\n      ranges::reverse(b | views::drop(1));\n\
    \    DFT(b, false);\n\n    for(int i = 0; i < n; i++)\n      a[i] *= b[i];\n\n\
    \    DFT(a, true);\n    if constexpr (!neg_b)\n      a.resize(sz);\n\n    return\
    \ a;\n  }\n\n  template<class Mint>\n  vc<Mint> full_pow(vc<Mint> a, int e) {\n\
    \    if (e == 0) return vc<Mint>(1, 1);\n\n    int sz = (ssize(a) - 1) * e + 1;\n\
    \    a.resize(bit_ceil(sz * 1ull));\n    DFT(a, 0);\n    for(Mint &x : a) x =\
    \ x.pow(e);\n    DFT(a, 1);\n    a.resize(sz);\n\n    return a;\n  }\n\n  template<class\
    \ T1, class T2>\n  vc<T1> vec_conversion(vc<T2> &a) {\n    vc<T1> r(size(a));\n\
    \    for(int i = 0; i < ssize(a); i++) {\n      if constexpr (is_integral_v<T2>)\n\
    \        r[i] = a[i];\n      else\n        r[i] = a[i].get();\n    }\n    return\
    \ r;\n  }\n\n  using Mint0 = Montgomery_modint<998'244'353>;\n  using Mint1 =\
    \ Montgomery_modint<469'762'049>;\n  using Mint2 = Montgomery_modint<167'772'161>;\n\
    \n  //(T1 = mint): n * mod^2 < prod of mods(~= 5e26) should hold\n  //(T1 = ll):\
    \ result should be within long long\n  template<class T1, class T2>\n  vc<T1>\
    \ convolution_CRT(vc<T2> a, vc<T2> b) {\n    if (empty(a) or empty(b)) return\
    \ {};\n\n    auto x = convolution(vec_conversion<Mint0>(a),\n                \
    \         vec_conversion<Mint0>(b));\n    auto y = convolution(vec_conversion<Mint1>(a),\n\
    \                         vec_conversion<Mint1>(b));\n    auto z = convolution(vec_conversion<Mint2>(a),\n\
    \                         vec_conversion<Mint2>(b));\n\n    static constexpr uint32_t\
    \ mod0 = 998'244'353, mod1 = 469'762'049;\n    static const Mint1 im0 = 1 / Mint1(mod0);\n\
    \    static const Mint2 im1 = 1 / Mint2(mod1), im0m1 = im1 / mod0;\n    static\
    \ const T1 m0 = mod0, m0m1 = m0 * mod1;\n\n    vc<T1> r(size(x));\n    for(int\
    \ i = 0; i < ssize(x); i++) {\n      int y0 = x[i].get();\n      int y1 = (im0\
    \ * (y[i] - y0)).get();\n      int y2 = (im0m1 * (z[i] - y0) - im1 * y1).get();\n\
    \      r[i] = y0 + m0 * y1 + m0m1 * y2;\n    }\n\n    return r;\n  }\n\n  template<class\
    \ T1, class T2>\n  vc<T1> full_pow_CRT(vc<T2> a, int e) {\n    if (e == 0) return\
    \ vc<T1>(1, 1);\n\n    auto x = full_pow(vec_conversion<Mint0>(a), 2);\n    auto\
    \ y = full_pow(vec_conversion<Mint1>(a), 2);\n    auto z = full_pow(vec_conversion<Mint2>(a),\
    \ 2);\n\n    static constexpr uint32_t mod0 = 998'244'353, mod1 = 469'762'049;\n\
    \    static const Mint1 im0 = 1 / Mint1(mod0);\n    static const Mint2 im1 = 1\
    \ / Mint2(mod1), im0m1 = im1 / mod0;\n    static const T1 m0 = mod0, m0m1 = m0\
    \ * mod1;\n\n    vc<T1> r(size(x));\n    for(int i = 0; i < ssize(x); i++) {\n\
    \      int y0 = x[i].get();\n      int y1 = (im0 * (y[i] - y0)).get();\n     \
    \ int y2 = (im0m1 * (z[i] - y0) - im1 * y1).get();\n      r[i] = y0 + m0 * y1\
    \ + m0m1 * y2;\n    }\n\n    return r;\n  }\n}\n\nusing namespace NTT;\n"
  dependsOn: []
  isVerificationFile: false
  path: new_poly/NTT.cpp
  requiredBy: []
  timestamp: '2026-09-26 13:58:48+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution_2.test.cpp
  - test/convolution_1e9+7_2.test.cpp
documentation_of: new_poly/NTT.cpp
layout: document
redirect_from:
- /library/new_poly/NTT.cpp
- /library/new_poly/NTT.cpp.html
title: new_poly/NTT.cpp
---
