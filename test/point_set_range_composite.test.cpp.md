---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':question:'
    path: modint/Montgomery_modint.cpp
    title: modint/Montgomery_modint.cpp
  - icon: ':question:'
    path: segtree/segment_tree.cpp
    title: segtree/segment_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/point_set_range_composite.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n\n#line 1 \"\
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
    \ = Montgomery_modint<998'244'353>;\n#line 1 \"segtree/segment_tree.cpp\"\ntemplate<class\
    \ M, M(*id)(), M(*op)(const M&, const M&)>\nstruct segment_tree {\n  int size;\n\
    \  vector<M> data;\n\n  segment_tree(int _size) : size(_size), data(2 * size,\
    \ id()) {}\n  segment_tree(vector<M> init) : size(ssize(init)), data(2 * size,\
    \ id()) {\n    ranges::copy(init, data.begin() + size);\n    for(int i = size\
    \ - 1; i > 0; i--)\n      data[i] = op(data[i << 1], data[i << 1 | 1]);\n  }\n\
    \n  void set(int i, M x) {\n    data[i += size] = x;\n    while(i >>= 1)\n   \
    \   data[i] = op(data[i << 1], data[i << 1 | 1]);\n  }\n\n  M get(int i) { return\
    \ data[i + size]; }\n\n  M query(int l, int r) {\n    M L = id(), R = id();\n\
    \    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) L\
    \ = op(L, data[l++]);\n      if (r & 1) R = op(data[--r], R);\n    }\n    return\
    \ op(L, R);\n  }\n\n  //return first j in [i, size) s.t. f(op([l, j])) is true,\n\
    \  //assume f(id()) is false.\n  int first_true(int i, function<bool(const M&)>\
    \ f) {\n    vector<int> idL, idR;\n    for(int l = i + size, r = size << 1; l\
    \ < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n      if\
    \ (r & 1) idR.emplace_back(--r);\n    }\n    idL.insert(idL.end(), idR.rbegin(),\
    \ idR.rend());\n    M pre = id();\n    int v = -1;\n    for(int j : idL) {\n \
    \     if (f(op(pre, data[j]))) {\n        v = j;\n        break;\n      } else\
    \ {\n        pre = op(pre, data[j]);\n      }\n    }\n    if (v == -1) return\
    \ size;\n    while(v < size) {\n      if (f(op(pre, data[v << 1])))\n        v\
    \ = v << 1;\n      else\n        pre = op(pre, data[v << 1]), v = v << 1 | 1;\n\
    \    }\n    return v - size;\n  }\n\n  int last_true(int i, function<bool(const\
    \ M&)> f) {\n    vector<int> idL, idR;\n    for(int l = size, r = (i + 1) + size;\
    \ l < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n      if\
    \ (r & 1) idR.emplace_back(--r);\n    }\n    idR.insert(idR.end(), idL.rbegin(),\
    \ idL.rend());\n    M suf = id();\n    int v = -1;\n    for(int j : idR) {\n \
    \     if (f(op(data[j], suf))) {\n        v = j;\n        break;\n      } else\
    \ {\n        suf = op(data[j], suf);\n      }\n    }\n    if (v == -1) return\
    \ -1;\n    while(v < size) {\n      if (f(op(data[v << 1 | 1], suf)))\n      \
    \  v = v << 1 | 1;\n      else\n        suf = op(data[v << 1 | 1], suf), v = v\
    \ << 1;\n    }\n    return v - size;\n  }\n};\n#line 6 \"test/point_set_range_composite.test.cpp\"\
    \n\nusing line = array<mint, 2>;\nline unit() { return line{1, 0}; }\nline ope(const\
    \ line &l, const line &r) {\n  return {l[0] * r[0], l[1] * r[0] + r[1]};\n}\n\n\
    int main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin\
    \ >> n >> q;\n  vector<line> a(n);\n  for(auto &[c, d] : a)\n    cin >> c >> d;\n\
    \n  segment_tree<line, unit, ope> st(a);\n  while(q--) {\n    int t, x, y, z;\
    \ cin >> t >> x >> y >> z;\n    if (t == 0) {\n      st.set(x, line{y, z});\n\
    \    } else {\n      line l = st.query(x, y);\n      cout << l[0] * z + l[1] <<\
    \ '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/Montgomery_modint.cpp\"\
    \n#include \"../segtree/segment_tree.cpp\"\n\nusing line = array<mint, 2>;\nline\
    \ unit() { return line{1, 0}; }\nline ope(const line &l, const line &r) {\n  return\
    \ {l[0] * r[0], l[1] * r[0] + r[1]};\n}\n\nint main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<line> a(n);\n  for(auto\
    \ &[c, d] : a)\n    cin >> c >> d;\n\n  segment_tree<line, unit, ope> st(a);\n\
    \  while(q--) {\n    int t, x, y, z; cin >> t >> x >> y >> z;\n    if (t == 0)\
    \ {\n      st.set(x, line{y, z});\n    } else {\n      line l = st.query(x, y);\n\
    \      cout << l[0] * z + l[1] << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/Montgomery_modint.cpp
  - segtree/segment_tree.cpp
  isVerificationFile: true
  path: test/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2026-09-02 17:22:39+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/point_set_range_composite.test.cpp
- /verify/test/point_set_range_composite.test.cpp.html
title: test/point_set_range_composite.test.cpp
---
