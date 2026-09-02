---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: ds/wavelet_matrix.cpp
    title: ds/wavelet_matrix.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/range_kth_smallest3.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#line 1 \"default/t.cpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define pb push_back\n#define\
    \ eb emplace_back\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ldb = long double;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\
    \ntemplate<typename T> using vc = vector<T>;\ntemplate<typename T> using vvc =\
    \ vc<vc<T>>;\ntemplate<typename T> using vvvc = vc<vvc<T>>;\n\nusing vi = vc<int>;\n\
    using vll = vc<ll>;\nusing vvi = vvc<int>;\nusing vvll = vvc<ll>;\n\ntemplate<typename\
    \ T> using min_heap = priority_queue<T, vc<T>, greater<T>>;\ntemplate<typename\
    \ T> using max_heap = priority_queue<T>;\n\nnamespace output {\n  ostream& operator<<(ostream&\
    \ os, __uint128_t x) {\n    if (x == 0) {\n      return os << \"0\";\n    } else\
    \ {\n      string s;\n      while(x)\n        s += '0' + x % 10, x /= 10;\n  \
    \    ranges::reverse(s);\n      return os << s;\n    }\n  }\n\n  ostream& operator<<(ostream&\
    \ os, __int128_t x) {\n    if (x < 0)\n      return os << \"-\" << -(__uint128_t)x;\n\
    \    else\n      return os << (__uint128_t)x;\n  }\n\n  template<size_t I = 0,\
    \ typename... args>\n  ostream& print_tuple(ostream& os, const tuple<args...>\
    \ tu) {\n    os << get<I>(tu);\n    if constexpr (I + 1 != sizeof...(args)) {\n\
    \      os << ' ';\n      print_tuple<I + 1>(os, tu);\n    }\n    return os;\n\
    \  }\n\n  template<typename... args>\n  ostream& operator<<(ostream& os, const\
    \ tuple<args...> tu) {\n    return print_tuple(os, tu);\n  }\n\n  template<class\
    \ T1, class T2>\n  ostream& operator<<(ostream& os, const pair<T1, T2> pr) {\n\
    \    return os << pr.first << ' ' << pr.second;\n  }\n\n  template<class T>\n\
    \  concept printable_range =\n    ranges::input_range<T> &&\n    !same_as<remove_cvref_t<T>,\
    \ string> &&\n    !same_as<remove_cvref_t<T>, string_view> &&\n    !same_as<ranges::range_value_t<T>,\
    \ char>;\n\n  template<printable_range R>\n  ostream& operator<<(ostream& os,\
    \ R&& r) {\n    for(bool first = true; auto &&x : r) {\n      if (!first) os <<\
    \ ' ';\n      first = false;\n      os << x;\n    }\n    return os;\n  }\n\n#ifdef\
    \ DEBUG\n#define dbg(...) cerr << '(', _do(#__VA_ARGS__), cerr << \") = \", _do2(__VA_ARGS__)\n\
    \  template<typename T> void _do(T &&x) { cerr << x; }\n  template<typename T,\
    \ typename ...S> void _do(T &&x, S&&...y) { cerr << x << \", \"; _do(y...); }\n\
    \  template<typename T> void _do2(T &&x) { cerr << x << endl; }\n  template<typename\
    \ T, typename ...S> void _do2(T &&x, S&&...y) { cerr << x << \", \"; _do2(y...);\
    \ }\n#else\n#define dbg(...)\n#endif\n}\n\nusing namespace output;\n\nnamespace\
    \ algorithm_extend {\n\n  template<typename R, typename F, typename... Args>\n\
    \  concept R_invocable = requires(F&& f, Args&&... args) {\n    { std::invoke(std::forward<F>(f),\
    \ std::forward<Args>(args)...) } -> std::same_as<R>;\n  };\n\n  template<ranges::forward_range\
    \ R, class T = ranges::range_value_t<R>, typename F>\n  requires R_invocable<T,\
    \ F, T, T>\n  void psum(R &&v, F f) {\n    if (!ranges::empty(v))\n      for(T\
    \ p = *v.begin(); T &x : v | views::drop(1))\n        x = p = f(p, x);\n  }\n\n\
    \  template<ranges::forward_range R, class T = ranges::range_value_t<R>>\n  void\
    \ psum(R &&v) {\n    if (!ranges::empty(v))\n      for(T p = *v.begin(); T &x\
    \ : v | views::drop(1))\n        x = p = p + x;\n  }\n\n  template<ranges::random_access_range\
    \ R>\n  void unique(R &v) {\n    ranges::sort(v);\n    v.erase(ranges::unique(v).begin(),\
    \ v.end());\n  }\n\n  template<ranges::random_access_range R>\n  R inv_perm(const\
    \ R &p) {\n    R ret = p;\n    for(int i = 0; i < ssize(p); i++)\n      ret[p[i]]\
    \ = i;\n    return ret;\n  }\n\n  template<integral T>\n  vc<T> iota_vec(int n,\
    \ T s = 0, T d = 1) {\n    vc<T> v(n);\n    for(int i = 0; i < n; i++)\n     \
    \ v[i] = i * d + s;\n    return v;\n  }\n\n  template<ranges::random_access_range\
    \ R, class F = identity>\n  vi arg_sort(const R &v, F proj = {}) {\n    vi id\
    \ = iota_vec<int>(ssize(v));\n    ranges::sort(id, {}, [&](int i) { return pair(proj(v[i]),\
    \ i); });\n    return id;\n  }\n\n  template<ranges::random_access_range R, class\
    \ F = identity>\n  vc<pii> equal_subarrays(const R &v, F proj = {}) {\n    vc<pii>\
    \ lr;\n    for(int i = 0, j = 0; i < ssize(v); i = j) {\n      while(j < ssize(v)\
    \ and proj(v[i]) == proj(v[j])) j++;\n      lr.eb(i, j);\n    }\n    return lr;\n\
    \  }\n\n  template<ranges::random_access_range R>\n  R compress(R &v) {\n    R\
    \ val = v;\n    unique(val);\n    for(auto &x : v)\n      x = ranges::lower_bound(val,\
    \ x) - val.begin();\n    return val;\n  }\n\n  template<ranges::random_access_range\
    \ R>\n  R compress_stable(R &v) {\n    R val = v;\n    ranges::sort(val);\n  \
    \  vi pos = iota_vec<int>(ssize(v));\n    for(auto &x : v)\n      x = pos[ranges::lower_bound(val,\
    \ x) - val.begin()]++;\n    return val;\n  }\n\n  template<integral T>\n  void\
    \ set_bit(T &msk, int bit, bool x) {\n    if (x) msk |= T(1) << bit;\n    else\
    \ msk &= ~(T(1) << bit);\n  }\n  template<integral T> void flip_bit(T &msk, int\
    \ bit) { msk ^= T(1) << bit; }\n  template<integral T> bool get_bit(T msk, int\
    \ bit) { return msk >> bit & T(1); }\n\n  template<integral T> T floor_div(T a,\
    \ T b) { return a / b - (a % b < 0); }\n  template<integral T> T  ceil_div(T a,\
    \ T b) { return a / b + (a % b > 0); }\n\n  ull kth_root(ull a, int k) {\n   \
    \ if (a == 0) return 0ull;\n    if (k >= 64) return 1ull;\n    if (k == 1) return\
    \ a;\n    if (k == 2) {\n      ull b = sqrtl(a);\n      while((__int128)(b + 1)\
    \ * (b + 1) <= a) b++;\n      while((__int128)b * b > a) b--;\n      return b;\n\
    \    }\n    if (k == 3) {\n      ull b = cbrtl(a);\n      while((__int128)(b +\
    \ 1) * (b + 1) * (b + 1) <= a) b++;\n      while((__int128)b * b * b > a) b--;\n\
    \      return b;\n    }\n    ull b = powl(a, 1.0L / k);\n    auto pw = [](ull\
    \ a, int k) {\n      __int128 b = 1;\n      for(int i = 0; i < k; i++) b *= a;\n\
    \      return b;\n    };\n    while(pw(b + 1, k) <= a) b++;\n    while(pw(b, k)\
    \ > a) b--;\n    return b;\n  }\n\n  template<class T> bool chmin(T &a, T b) {\
    \ return a > b ? a = b, 1 : 0; }\n  template<class T> bool chmax(T &a, T b) {\
    \ return a < b ? a = b, 1 : 0; }\n\n  template<integral T>\n  T binpow(T a, ull\
    \ k) {\n    T b = 1;\n    while(k) {\n      if (k & 1) b *= a;\n      a *= a,\
    \ k >>= 1;\n    }\n    return b;\n  }\n\n  template<ranges::random_access_range\
    \ R>\n  ll inversion_count(R v) {\n    ll f = 0;\n    auto tmp = v;\n    auto\
    \ dc = [&](int l, int r, auto &self) -> void {\n      if (l + 1 >= r) return;\n\
    \      int mid = (l + r) / 2;\n      self(l, mid, self);\n      self(mid, r, self);\n\
    \      {\n        int i = l, j = mid, k = l;\n        while(i < mid and j < r)\
    \ {\n          if (v[i] <= v[j]) tmp[k++] = v[i++];\n          else tmp[k++] =\
    \ v[j++], f += mid - i;\n        }\n        while(i < mid) tmp[k++] = v[i++];\n\
    \        while(j < r) tmp[k++] = v[j++];\n      }\n      for(int i = l; i < r;\
    \ i++)\n        v[i] = tmp[i];\n    };\n\n    dc(0, ssize(v), dc);\n\n    return\
    \ f;\n  }\n}\n\nusing namespace algorithm_extend;\n#line 1 \"ds/wavelet_matrix.cpp\"\
    \ntemplate<class T, int H>\nstruct wavelet_matrix {\n  using u32 = uint32_t;\n\
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
    \ &p : inv_perms)\n        p = inv_perm(p);\n    }\n\n    for(int i = 0; i <=\
    \ H; i++)\n      f(i, inv_perms[i][x]);\n  }\n};\n#line 5 \"test/range_kth_smallest3.test.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q;\
    \ cin >> n >> q;\n  vi a(n);\n  for(int &x : a) cin >> x;\n\n  wavelet_matrix<int,\
    \ 30> WM(a);\n\n  while(q--) {\n    int l, r, k; cin >> l >> r >> k;\n    cout\
    \ << WM.kth(l, r, k) << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../default/t.cpp\"\n#include \"../ds/wavelet_matrix.cpp\"\n\nint main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin >> n >>\
    \ q;\n  vi a(n);\n  for(int &x : a) cin >> x;\n\n  wavelet_matrix<int, 30> WM(a);\n\
    \n  while(q--) {\n    int l, r, k; cin >> l >> r >> k;\n    cout << WM.kth(l,\
    \ r, k) << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/wavelet_matrix.cpp
  isVerificationFile: true
  path: test/range_kth_smallest3.test.cpp
  requiredBy: []
  timestamp: '2026-09-02 22:57:23+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/range_kth_smallest3.test.cpp
layout: document
redirect_from:
- /verify/test/range_kth_smallest3.test.cpp
- /verify/test/range_kth_smallest3.test.cpp.html
title: test/range_kth_smallest3.test.cpp
---
