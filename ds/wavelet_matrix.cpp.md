---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/point_add_rectangle_sum2.test.cpp
    title: test/point_add_rectangle_sum2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/range_kth_smallest3.test.cpp
    title: test/range_kth_smallest3.test.cpp
  - icon: ':x:'
    path: test/rectangle_sum2.test.cpp
    title: test/rectangle_sum2.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/wavelet_matrix.cpp\"\ntemplate<class T, int H>\nstruct\
    \ wavelet_matrix {\n  using u32 = uint32_t;\n  struct bitvec {\n    static constexpr\
    \ u32 W = 64;\n    int cnt_0 = 0, sz;\n    vc<ull> bit_vec;\n    vi ps;\n\n  \
    \  bitvec(u32 _sz) : sz(_sz), bit_vec(sz / W + 1), ps(sz / W + 1) {}\n    void\
    \ set(u32 i) { bit_vec[i / W] |= 1LL << (i % W); }\n    u32 get(u32 i) { return\
    \ bit_vec[i / W] >> (i % W) & 1; }\n    void build() {\n      for(int i = 1; i\
    \ < ssize(ps); i++)\n        ps[i] = ps[i - 1] + popcount(bit_vec[i - 1]);\n \
    \     cnt_0 = rank_0(sz);\n    }\n    int rank_1(u32 i) { return ps[i / W] + popcount(bit_vec[i\
    \ / W] & ((1LL << i) - 1)); }\n    int rank_0(u32 i) { return i - rank_1(i); }\n\
    \  };\n\n  vc<bitvec> mat;\n  vvi perms; //(H + 1) permutations\n\n  //prepare\
    \ (H + 1) x size(init) array to maintain extra datas.\n  wavelet_matrix(vc<T>\
    \ init, bool keep = false) : mat(H, bitvec(size(init))) {\n    vi perm(size(init));\n\
    \    iota(perm.begin(), perm.end(), 0);\n    if (keep) perms.eb(perm);\n    for(int\
    \ bit = H; auto &v : mat | views::reverse) {\n      bit--;\n      for(int i =\
    \ 0; i < ssize(init); i++)\n        if (init[perm[i]] >> bit & 1)\n          v.set(i);\n\
    \      v.build();\n      vi nxt(size(init));\n      array<int, 2> p = {0, v.cnt_0};\n\
    \      for(int i = 0; i < ssize(init); i++)\n        nxt[p[v.get(i)]++] = perm[i];\n\
    \      perm.swap(nxt);\n      if (keep) perms.eb(perm);\n    }\n    if (keep)\
    \ ranges::reverse(perms);\n  }\n\n  pii next_range(int i, int l, int r, bool right)\
    \ {\n    auto &v = mat[i];\n    if (right)\n      return pii(v.cnt_0 + v.rank_1(l),\
    \ v.cnt_0 + v.rank_1(r));\n    else\n      return pii(v.rank_0(l), v.rank_0(r));\n\
    \  }\n\n  T kth(int l, int r, int k) {\n    T ans = 0;\n    for(int i = H - 1;\
    \ i >= 0; i--) {\n      if (auto [l0, r0] = next_range(i, l, r, 0); r0 - l0 <=\
    \ k) {\n        ans |= T(1) << i, k -= r0 - l0;\n        tie(l, r) = next_range(i,\
    \ l, r, 1);\n      } else {\n        tie(l, r) = tie(l0, r0);\n      }\n    }\n\
    \    return ans;\n  }\n\n  //F(i, l, r)\n  template<typename F> requires R_invocable<void,\
    \ F, int, int, int>\n  void rect_query(int L, int R, T D, T U, F f) {\n    auto\
    \ dfs = [&](int i, T ql, T qr, int l, int r, T d, T u, auto &self) {\n      if\
    \ (l == r or d == u) return;\n      if (d == ql and u == qr) {\n        f(i +\
    \ 1, l, r);\n        return;\n      }\n\n      T mid = (ql + qr) / 2;\n      if\
    \ (u <= mid) {\n        tie(l, r) = next_range(i, l, r, 0);\n        self(i -\
    \ 1, ql, mid, l, r, d, u, self);\n      } else if (mid <= d) {\n        tie(l,\
    \ r) = next_range(i, l, r, 1);\n        self(i - 1, mid, qr, l, r, d, u, self);\n\
    \      } else {\n        auto [l0, r0] = next_range(i, l, r, 0);\n        self(i\
    \ - 1, ql, mid, l0, r0, d, mid, self);\n        auto [l1, r1] = next_range(i,\
    \ l, r, 1);\n        self(i - 1, mid, qr, l1, r1, mid, u, self);\n      }\n  \
    \  };\n\n    dfs(H - 1, T(0), T(1) << H, L, R, D, U, dfs);\n  }\n\n  vvi inv_perms;\n\
    \n  //F(i, j)\n  template<typename F> requires R_invocable<void, F, int, int>\n\
    \  void point_update(int x, F f) {\n    if (inv_perms.empty()) {\n      inv_perms\
    \ = perms;\n      for(auto &p : inv_perms)\n        p = invPerm(p);\n    }\n\n\
    \    for(int i = 0; i <= H; i++)\n      f(i, inv_perms[i][x]);\n  }\n};\n"
  code: "template<class T, int H>\nstruct wavelet_matrix {\n  using u32 = uint32_t;\n\
    \  struct bitvec {\n    static constexpr u32 W = 64;\n    int cnt_0 = 0, sz;\n\
    \    vc<ull> bit_vec;\n    vi ps;\n\n    bitvec(u32 _sz) : sz(_sz), bit_vec(sz\
    \ / W + 1), ps(sz / W + 1) {}\n    void set(u32 i) { bit_vec[i / W] |= 1LL <<\
    \ (i % W); }\n    u32 get(u32 i) { return bit_vec[i / W] >> (i % W) & 1; }\n \
    \   void build() {\n      for(int i = 1; i < ssize(ps); i++)\n        ps[i] =\
    \ ps[i - 1] + popcount(bit_vec[i - 1]);\n      cnt_0 = rank_0(sz);\n    }\n  \
    \  int rank_1(u32 i) { return ps[i / W] + popcount(bit_vec[i / W] & ((1LL << i)\
    \ - 1)); }\n    int rank_0(u32 i) { return i - rank_1(i); }\n  };\n\n  vc<bitvec>\
    \ mat;\n  vvi perms; //(H + 1) permutations\n\n  //prepare (H + 1) x size(init)\
    \ array to maintain extra datas.\n  wavelet_matrix(vc<T> init, bool keep = false)\
    \ : mat(H, bitvec(size(init))) {\n    vi perm(size(init));\n    iota(perm.begin(),\
    \ perm.end(), 0);\n    if (keep) perms.eb(perm);\n    for(int bit = H; auto &v\
    \ : mat | views::reverse) {\n      bit--;\n      for(int i = 0; i < ssize(init);\
    \ i++)\n        if (init[perm[i]] >> bit & 1)\n          v.set(i);\n      v.build();\n\
    \      vi nxt(size(init));\n      array<int, 2> p = {0, v.cnt_0};\n      for(int\
    \ i = 0; i < ssize(init); i++)\n        nxt[p[v.get(i)]++] = perm[i];\n      perm.swap(nxt);\n\
    \      if (keep) perms.eb(perm);\n    }\n    if (keep) ranges::reverse(perms);\n\
    \  }\n\n  pii next_range(int i, int l, int r, bool right) {\n    auto &v = mat[i];\n\
    \    if (right)\n      return pii(v.cnt_0 + v.rank_1(l), v.cnt_0 + v.rank_1(r));\n\
    \    else\n      return pii(v.rank_0(l), v.rank_0(r));\n  }\n\n  T kth(int l,\
    \ int r, int k) {\n    T ans = 0;\n    for(int i = H - 1; i >= 0; i--) {\n   \
    \   if (auto [l0, r0] = next_range(i, l, r, 0); r0 - l0 <= k) {\n        ans |=\
    \ T(1) << i, k -= r0 - l0;\n        tie(l, r) = next_range(i, l, r, 1);\n    \
    \  } else {\n        tie(l, r) = tie(l0, r0);\n      }\n    }\n    return ans;\n\
    \  }\n\n  //F(i, l, r)\n  template<typename F> requires R_invocable<void, F, int,\
    \ int, int>\n  void rect_query(int L, int R, T D, T U, F f) {\n    auto dfs =\
    \ [&](int i, T ql, T qr, int l, int r, T d, T u, auto &self) {\n      if (l ==\
    \ r or d == u) return;\n      if (d == ql and u == qr) {\n        f(i + 1, l,\
    \ r);\n        return;\n      }\n\n      T mid = (ql + qr) / 2;\n      if (u <=\
    \ mid) {\n        tie(l, r) = next_range(i, l, r, 0);\n        self(i - 1, ql,\
    \ mid, l, r, d, u, self);\n      } else if (mid <= d) {\n        tie(l, r) = next_range(i,\
    \ l, r, 1);\n        self(i - 1, mid, qr, l, r, d, u, self);\n      } else {\n\
    \        auto [l0, r0] = next_range(i, l, r, 0);\n        self(i - 1, ql, mid,\
    \ l0, r0, d, mid, self);\n        auto [l1, r1] = next_range(i, l, r, 1);\n  \
    \      self(i - 1, mid, qr, l1, r1, mid, u, self);\n      }\n    };\n\n    dfs(H\
    \ - 1, T(0), T(1) << H, L, R, D, U, dfs);\n  }\n\n  vvi inv_perms;\n\n  //F(i,\
    \ j)\n  template<typename F> requires R_invocable<void, F, int, int>\n  void point_update(int\
    \ x, F f) {\n    if (inv_perms.empty()) {\n      inv_perms = perms;\n      for(auto\
    \ &p : inv_perms)\n        p = invPerm(p);\n    }\n\n    for(int i = 0; i <= H;\
    \ i++)\n      f(i, inv_perms[i][x]);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/wavelet_matrix.cpp
  requiredBy: []
  timestamp: '2026-04-19 19:02:40+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/point_add_rectangle_sum2.test.cpp
  - test/range_kth_smallest3.test.cpp
  - test/rectangle_sum2.test.cpp
documentation_of: ds/wavelet_matrix.cpp
layout: document
redirect_from:
- /library/ds/wavelet_matrix.cpp
- /library/ds/wavelet_matrix.cpp.html
title: ds/wavelet_matrix.cpp
---
