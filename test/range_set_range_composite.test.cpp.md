---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: acted_monoid/affine_sum.cpp
    title: acted_monoid/affine_sum.cpp
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':question:'
    path: modint/Montgomery_modint.cpp
    title: modint/Montgomery_modint.cpp
  - icon: ':x:'
    path: segtree/range_set_segment_tree.cpp
    title: segtree/range_set_segment_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/range_set_range_composite
  bundledCode: "#line 1 \"test/range_set_range_composite.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_set_range_composite\"\n\n#line 1 \"\
    default/t.cpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define pb push_back\n\
    #define eb emplace_back\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
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
    \ F, T, T>\n  void psum(R &&v, F f) {\n    if (!v.empty())\n      for(T p = *v.begin();\
    \ T &x : v | views::drop(1))\n        x = p = f(p, x);\n  }\n\n  template<ranges::forward_range\
    \ R, class T = ranges::range_value_t<R>>\n  void psum(R &&v) {\n    if (!v.empty())\n\
    \      for(T p = *v.begin(); T &x : v | views::drop(1))\n        x = p = p + x;\n\
    \  }\n\n  template<ranges::forward_range R>\n  void unique(R &v) {\n    ranges::sort(v);\n\
    \    v.erase(ranges::unique(v).begin(), v.end());\n  }\n\n  template<ranges::random_access_range\
    \ R>\n  R inv_perm(const R &p) {\n    R ret = p;\n    for(int i = 0; i < ssize(p);\
    \ i++)\n      ret[p[i]] = i;\n    return ret;\n  }\n\n  template<ranges::random_access_range\
    \ R, class F = identity>\n  vi arg_sort(const R &v, F proj = {}) {\n    vi id(size(v));\n\
    \    iota(id.begin(), id.end(), 0);\n    ranges::sort(id, {}, [&](int i) { return\
    \ pair(proj(v[i]), i); });\n    return id;\n  }\n\n  template<ranges::random_access_range\
    \ R, class F = identity>\n  vc<pii> equal_subarrays(const R &v, F proj = {}) {\n\
    \    vc<pii> lr;\n    for(int i = 0, j = 0; i < ssize(v); i = j) {\n      while(j\
    \ < ssize(v) and proj(v[i]) == proj(v[j])) j++;\n      lr.eb(i, j);\n    }\n \
    \   return lr;\n  }\n\n  template<integral T>\n  vc<T> iota_vec(int n, T s = 0,\
    \ T d = 1) {\n    vc<T> v(n);\n    for(int i = 0; i < n; i++)\n      v[i] = i\
    \ * d + s;\n    return v;\n  }\n\n  template<ranges::random_access_range R>\n\
    \  R compress(R &v) {\n    R val = v;\n    unique(val);\n    for(auto &x : v)\n\
    \      x = ranges::lower_bound(val, x) - val.begin();\n    return val;\n  }\n\n\
    \  template<ranges::random_access_range R>\n  R compress_stable(R &v) {\n    R\
    \ val = v;\n    ranges::sort(val);\n    vi pos = iota_vec<int>(ssize(v));\n  \
    \  for(auto &x : v)\n      x = pos[ranges::lower_bound(val, x) - val.begin()]++;\n\
    \    return val;\n  }\n\n  template<integral T>\n  void set_bit(T &msk, int bit,\
    \ bool x) {\n    if (x) msk |= T(1) << bit;\n    else msk &= ~(T(1) << bit);\n\
    \  }\n  template<integral T> void flip_bit(T &msk, int bit) { msk ^= T(1) << bit;\
    \ }\n  template<integral T> bool get_bit(T msk, int bit) { return msk >> bit &\
    \ T(1); }\n\n  template<signed_integral T> T floor_div(T a, T b) { return a /\
    \ b - (a % b < 0); }\n  template<signed_integral T> T  ceil_div(T a, T b) { return\
    \ a / b + (a % b > 0); }\n\n  ull kth_root(ull a, int k) {\n    if (a == 0) return\
    \ 0ull;\n    if (k >= 64) return 1ull;\n    if (k == 1) return a;\n    if (k ==\
    \ 2) {\n      ull b = sqrtl(a);\n      while((__int128)(b + 1) * (b + 1) <= a)\
    \ b++;\n      while((__int128)b * b > a) b--;\n      return b;\n    }\n    if\
    \ (k == 3) {\n      ull b = cbrtl(a);\n      while((__int128)(b + 1) * (b + 1)\
    \ * (b + 1) <= a) b++;\n      while((__int128)b * b * b > a) b--;\n      return\
    \ b;\n    }\n    ull b = powl(a, 1.0L / k);\n    auto pw = [](ull a, int k) {\n\
    \      __int128 b = 1;\n      for(int i = 0; i < k; i++) b *= a;\n      return\
    \ b;\n    };\n    while(pw(b + 1, k) <= a) b++;\n    while(pw(b, k) > a) b--;\n\
    \    return b;\n  }\n\n  template<class T> bool chmin(T &a, T b) { return a >\
    \ b ? a = b, 1 : 0; }\n  template<class T> bool chmax(T &a, T b) { return a <\
    \ b ? a = b, 1 : 0; }\n\n  template<integral T>\n  T binpow(T a, ull k) {\n  \
    \  T b = 1;\n    while(k) {\n      if (k & 1) b *= a;\n      a *= a, k >>= 1;\n\
    \    }\n    return b;\n  }\n\n  template<ranges::random_access_range R>\n  ll\
    \ inversion_count(R v) {\n    ll f = 0;\n    auto tmp = v;\n    auto dc = [&](int\
    \ l, int r, auto &self) -> void {\n      if (l + 1 >= r) return;\n      int mid\
    \ = (l + r) / 2;\n      self(l, mid, self);\n      self(mid, r, self);\n     \
    \ {\n        int i = l, j = mid, k = l;\n        while(i < mid and j < r) {\n\
    \          if (v[i] <= v[j]) tmp[k++] = v[i++];\n          else tmp[k++] = v[j++],\
    \ f += mid - i;\n        }\n        while(i < mid) tmp[k++] = v[i++];\n      \
    \  while(j < r) tmp[k++] = v[j++];\n      }\n      for(int i = l; i < r; i++)\n\
    \        v[i] = tmp[i];\n    };\n\n    dc(0, ssize(v), dc);\n\n    return f;\n\
    \  }\n}\n\nusing namespace algorithm_extend;\n#line 1 \"modint/Montgomery_modint.cpp\"\
    \n//reference: https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
    //note: mod should be an odd prime less than 2^30.\n\ntemplate<uint32_t mod>\n\
    struct Montgomery_modint {\n  using mint = Montgomery_modint;\n  using i32 = int32_t;\n\
    \  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static constexpr u32 get_r()\
    \ {\n    u32 res = 1, base = mod;\n    for(i32 i = 0; i < 31; i++)\n      res\
    \ *= base, base *= base;\n    return -res;\n  }\n\n  static constexpr u32 get_mod()\
    \ {\n    return mod;\n  }\n\n  static constexpr u32 n2 = -u64(mod) % mod; //2^64\
    \ % mod\n  static constexpr u32 r = get_r(); //-P^{-1} % 2^32\n\n  u32 a;\n\n\
    \  static u32 reduce(const u64 &b) {\n    return (b + u64(u32(b) * r) * mod) >>\
    \ 32;\n  }\n\n  static u32 transform(const u64 &b) {\n    return reduce(u64(b)\
    \ * n2);\n  }\n\n  Montgomery_modint() : a(0) {}\n  Montgomery_modint(const int64_t\
    \ &b) \n    : a(transform(b % mod + mod)) {}\n\n  mint pow(u64 k) const {\n  \
    \  mint res(1), base(*this);\n    while(k) {\n      if (k & 1) \n        res *=\
    \ base;\n      base *= base, k >>= 1;\n    }\n    return res;\n  }\n\n  mint inverse()\
    \ const { return (*this).pow(mod - 2); }\n\n  u32 get() const {\n    u32 res =\
    \ reduce(a);\n    return res >= mod ? res - mod : res;\n  }\n\n  mint& operator+=(const\
    \ mint &b) {\n    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n\
    \  }\n\n  mint& operator-=(const mint &b) {\n    if (i32(a -= b.a) < 0) a += 2\
    \ * mod;\n    return *this;\n  }\n\n  mint& operator*=(const mint &b) {\n    a\
    \ = reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  mint& operator/=(const\
    \ mint &b) {\n    a = reduce(u64(a) * b.inverse().a);\n    return *this;\n  }\n\
    \n  mint operator-() { return mint() - mint(*this); }\n  bool operator==(mint\
    \ b) const {\n    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod :\
    \ b.a);\n  }\n  bool operator!=(mint b) const {\n    return (a >= mod ? a - mod\
    \ : a) != (b.a >= mod ? b.a - mod : b.a);\n  }\n\n  friend mint operator+(mint\
    \ c, mint d) { return c += d; }\n  friend mint operator-(mint c, mint d) { return\
    \ c -= d; }\n  friend mint operator*(mint c, mint d) { return c *= d; }\n  friend\
    \ mint operator/(mint c, mint d) { return c /= d; }\n\n  friend ostream& operator<<(ostream&\
    \ os, const mint& b) {\n    return os << b.get();\n  }\n  friend istream& operator>>(istream&\
    \ is, mint& b) {\n    int64_t val;\n    is >> val;\n    b = mint(val);\n    return\
    \ is;\n  }\n};\n\n//using mint = Montgomery_modint<1'000'000'007>;\nusing mint\
    \ = Montgomery_modint<998'244'353>;\n#line 1 \"segtree/range_set_segment_tree.cpp\"\
    \ntemplate<class M, M(*id)(), M(*op)(const M&, const M&)>\nstruct range_set_segment_tree\
    \ {\n  vector<M> data, pre;\n  vector<int> tagId;\n  int size, nxt;\n\n  range_set_segment_tree(int\
    \ _size) : data(2 * _size, id()), pre(_size), tagId(_size, -1), size(_size), nxt(0)\
    \ {}\n\n  range_set_segment_tree(vector<M> init) : data(2 * ssize(init), id()),\
    \ pre(ssize(init)), tagId(ssize(init), -1), size(ssize(init)), nxt(0) {\n    copy(init.begin(),\
    \ init.end(), data.begin() + size);\n    for(int i = size - 1; i > 0; i--)\n \
    \     data[i] = op(data[i << 1], data[i << 1 | 1]);\n  }\n\n  void apply(int i,\
    \ int tId) {\n    data[i] = pre[tId];\n    if (i < size) tagId[i] = tId;\n  }\n\
    \n  void push(int i) {\n    for(int s = (int)bit_width((unsigned)i) - 1; s > 0;\
    \ s--) {\n      if (tagId[i >> s] != -1) {\n        apply(i >> (s - 1), tagId[i\
    \ >> s] - 1);\n        apply(i >> (s - 1) ^ 1, tagId[i >> s] - 1);\n        tagId[i\
    \ >> s] = -1;\n      }\n    }\n  }\n\n  void pull(int i) {\n    while(i >>= 1)\
    \ data[i] = op(data[i << 1], data[i << 1 | 1]);\n  }\n\n  int trunc(unsigned i)\
    \ { return i >> countr_zero(i); }\n\n  void set(int i, M x) {\n    push(i + size);\n\
    \    data[i + size] = x;\n    pull(i + size);\n  }\n\n  M get(int i) {\n    push(i\
    \ + size);\n    return data[i + size];\n  }\n\n  void set(int l, int r, M x) {\n\
    \    if (l >= r or x == id()) return;\n    if (nxt + bit_width((unsigned)size)\
    \ > size) {\n      for(int i = 1; i < size; i++) {\n        if (tagId[i] != -1)\
    \ {\n          apply(i << 1, tagId[i] - 1);\n          apply(i << 1 | 1, tagId[i]\
    \ - 1);\n          tagId[i] = -1;\n        }\n      }\n      nxt = 0;\n    }\n\
    \    for(int i = 0; i < bit_width((unsigned)size); i++, x = op(x, x))\n      pre[nxt++]\
    \ = x;\n    push(trunc(l += size)), push(trunc(r += size) - 1);\n    int l0 =\
    \ l, r0 = r;\n    for(int tId = nxt - (int)bit_width((unsigned)size); l < r; l\
    \ >>= 1, r >>= 1, tId++) {\n      if (l & 1) apply(l++, tId);\n      if (r & 1)\
    \ apply(--r, tId);\n    }\n    pull(trunc(l0)), pull(trunc(r0) - 1);\n  }\n\n\
    \  M query(int l, int r) {\n    if (l >= r) return id();\n    M L = id(), R =\
    \ id();\n    push(trunc(l += size)), push(trunc(r += size) - 1);\n    for(; l\
    \ < r; l >>= 1, r >>= 1) {\n      if (l & 1) L = op(L, data[l++]);\n      if (r\
    \ & 1) R = op(data[--r], R);\n    }\n    return op(L, R);\n  }\n};\n#line 1 \"\
    acted_monoid/affine_sum.cpp\"\ntemplate<class U>\nstruct affine_sum {\n  using\
    \ M = array<U, 2>;\n  static M Mid() { return M{0, 0}; }\n  static M Mop(const\
    \ M &a, const M &b) { return {a[0] + b[0], a[1] + b[1]}; }\n  using T = array<U,\
    \ 2>;\n  static T Tid() { return T{1, 0}; }\n  static T Top(const T &a, const\
    \ T &b) { return T{a[0] * b[0], a[1] * b[0] + b[1]}; }\n  static M act(const M\
    \ &a, const T &b) { return {a[0] * b[0] + a[1] * b[1], a[1]}; }\n};\n#line 7 \"\
    test/range_set_range_composite.test.cpp\"\n\nusing am = affine_sum<mint>;\n\n\
    int main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin\
    \ >> n >> q;\n  vector<am::T> ab(n);\n  for(auto &[a, b] : ab)\n    cin >> a >>\
    \ b;\n\n  range_set_segment_tree<am::T, am::Tid, am::Top> st(ab);\n  while(q--)\
    \ {\n    int t; cin >> t;\n    if (t == 0) {\n      int l, r, c, d; cin >> l >>\
    \ r >> c >> d;\n      st.set(l, r, am::T{c, d});\n    } else {\n      int l, r,\
    \ x; cin >> l >> r >> x;\n      cout << am::Top(am::T{0, x}, st.query(l, r))[1]\
    \ << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_set_range_composite\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/Montgomery_modint.cpp\"\
    \n#include \"../segtree/range_set_segment_tree.cpp\"\n#include \"../acted_monoid/affine_sum.cpp\"\
    \n\nusing am = affine_sum<mint>;\n\nint main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<am::T> ab(n);\n  for(auto\
    \ &[a, b] : ab)\n    cin >> a >> b;\n\n  range_set_segment_tree<am::T, am::Tid,\
    \ am::Top> st(ab);\n  while(q--) {\n    int t; cin >> t;\n    if (t == 0) {\n\
    \      int l, r, c, d; cin >> l >> r >> c >> d;\n      st.set(l, r, am::T{c, d});\n\
    \    } else {\n      int l, r, x; cin >> l >> r >> x;\n      cout << am::Top(am::T{0,\
    \ x}, st.query(l, r))[1] << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/Montgomery_modint.cpp
  - segtree/range_set_segment_tree.cpp
  - acted_monoid/affine_sum.cpp
  isVerificationFile: true
  path: test/range_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2026-09-02 17:22:39+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/range_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/range_set_range_composite.test.cpp
- /verify/test/range_set_range_composite.test.cpp.html
title: test/range_set_range_composite.test.cpp
---
