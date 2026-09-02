---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combi/stirling_first_kind_mod_P.cpp
    title: combi/stirling_first_kind_mod_P.cpp
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: modint/dynamic_modint.cpp
    title: modint/dynamic_modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_small_p_large_n
    links:
    - https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_small_p_large_n
  bundledCode: "#line 1 \"test/stirling_number_of_first_kind_small_p_large_n.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_small_p_large_n\"\
    \n\n#line 1 \"default/t.cpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    \n#define pb push_back\n#define eb emplace_back\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing ldb = long double;\nusing pii = pair<int, int>;\n\
    using pll = pair<ll, ll>;\n\ntemplate<typename T> using vc = vector<T>;\ntemplate<typename\
    \ T> using vvc = vc<vc<T>>;\ntemplate<typename T> using vvvc = vc<vvc<T>>;\n\n\
    using vi = vc<int>;\nusing vll = vc<ll>;\nusing vvi = vvc<int>;\nusing vvll =\
    \ vvc<ll>;\n\ntemplate<typename T> using min_heap = priority_queue<T, vc<T>, greater<T>>;\n\
    template<typename T> using max_heap = priority_queue<T>;\n\nnamespace output {\n\
    \  ostream& operator<<(ostream& os, __uint128_t x) {\n    if (x == 0) {\n    \
    \  return os << \"0\";\n    } else {\n      string s;\n      while(x)\n      \
    \  s += '0' + x % 10, x /= 10;\n      ranges::reverse(s);\n      return os <<\
    \ s;\n    }\n  }\n\n  ostream& operator<<(ostream& os, __int128_t x) {\n    if\
    \ (x < 0)\n      return os << \"-\" << -(__uint128_t)x;\n    else\n      return\
    \ os << (__uint128_t)x;\n  }\n\n  template<size_t I = 0, typename... args>\n \
    \ ostream& print_tuple(ostream& os, const tuple<args...> tu) {\n    os << get<I>(tu);\n\
    \    if constexpr (I + 1 != sizeof...(args)) {\n      os << ' ';\n      print_tuple<I\
    \ + 1>(os, tu);\n    }\n    return os;\n  }\n\n  template<typename... args>\n\
    \  ostream& operator<<(ostream& os, const tuple<args...> tu) {\n    return print_tuple(os,\
    \ tu);\n  }\n\n  template<class T1, class T2>\n  ostream& operator<<(ostream&\
    \ os, const pair<T1, T2> pr) {\n    return os << pr.first << ' ' << pr.second;\n\
    \  }\n\n  template<class T>\n  concept printable_range =\n    ranges::input_range<T>\
    \ &&\n    !same_as<remove_cvref_t<T>, string> &&\n    !same_as<remove_cvref_t<T>,\
    \ string_view> &&\n    !same_as<ranges::range_value_t<T>, char>;\n\n  template<printable_range\
    \ R>\n  ostream& operator<<(ostream& os, R&& r) {\n    for(bool first = true;\
    \ auto &&x : r) {\n      if (!first) os << ' ';\n      first = false;\n      os\
    \ << x;\n    }\n    return os;\n  }\n\n#ifdef DEBUG\n#define dbg(...) cerr <<\
    \ '(', _do(#__VA_ARGS__), cerr << \") = \", _do2(__VA_ARGS__)\n  template<typename\
    \ T> void _do(T &&x) { cerr << x; }\n  template<typename T, typename ...S> void\
    \ _do(T &&x, S&&...y) { cerr << x << \", \"; _do(y...); }\n  template<typename\
    \ T> void _do2(T &&x) { cerr << x << endl; }\n  template<typename T, typename\
    \ ...S> void _do2(T &&x, S&&...y) { cerr << x << \", \"; _do2(y...); }\n#else\n\
    #define dbg(...)\n#endif\n}\n\nusing namespace output;\n\nnamespace algorithm_extend\
    \ {\n\n  template<typename R, typename F, typename... Args>\n  concept R_invocable\
    \ = requires(F&& f, Args&&... args) {\n    { std::invoke(std::forward<F>(f), std::forward<Args>(args)...)\
    \ } -> std::same_as<R>;\n  };\n\n  template<ranges::forward_range R, class T =\
    \ ranges::range_value_t<R>, typename F>\n  requires R_invocable<T, F, T, T>\n\
    \  void psum(R &v, F f) {\n    if (!ranges::empty(v))\n      for(T p = *v.begin();\
    \ T &x : v | views::drop(1))\n        x = p = f(p, x);\n  }\n\n  template<ranges::forward_range\
    \ R, class T = ranges::range_value_t<R>>\n  void psum(R &v) {\n    if (!ranges::empty(v))\n\
    \      for(T p = *v.begin(); T &x : v | views::drop(1))\n        x = p = p + x;\n\
    \  }\n\n  template<ranges::random_access_range R>\n  void unique(R &v) {\n   \
    \ ranges::sort(v);\n    v.erase(ranges::unique(v).begin(), v.end());\n  }\n\n\
    \  template<ranges::random_access_range R>\n  R inv_perm(const R &p) {\n    R\
    \ ret = p;\n    for(int i = 0; i < ssize(p); i++)\n      ret[p[i]] = i;\n    return\
    \ ret;\n  }\n\n  template<integral T>\n  vc<T> iota_vec(int n, T s = 0, T d =\
    \ 1) {\n    vc<T> v(n);\n    for(int i = 0; i < n; i++)\n      v[i] = i * d +\
    \ s;\n    return v;\n  }\n\n  template<ranges::random_access_range R, class F\
    \ = identity>\n  vi arg_sort(const R &v, F proj = {}) {\n    vi id = iota_vec<int>(ssize(v));\n\
    \    ranges::sort(id, {}, [&](int i) { return pair(proj(v[i]), i); });\n    return\
    \ id;\n  }\n\n  template<ranges::random_access_range R, class F = identity>\n\
    \  vc<pii> equal_subarrays(const R &v, F proj = {}) {\n    vc<pii> lr;\n    for(int\
    \ i = 0, j = 0; i < ssize(v); i = j) {\n      while(j < ssize(v) and proj(v[i])\
    \ == proj(v[j])) j++;\n      lr.eb(i, j);\n    }\n    return lr;\n  }\n\n  template<ranges::random_access_range\
    \ R>\n  R compress(R &v) {\n    R val = v;\n    unique(val);\n    for(auto &x\
    \ : v)\n      x = ranges::lower_bound(val, x) - val.begin();\n    return val;\n\
    \  }\n\n  template<ranges::random_access_range R>\n  R compress_stable(R &v) {\n\
    \    R val = v;\n    ranges::sort(val);\n    vi pos = iota_vec<int>(ssize(v));\n\
    \    for(auto &x : v)\n      x = pos[ranges::lower_bound(val, x) - val.begin()]++;\n\
    \    return val;\n  }\n\n  template<integral T>\n  void set_bit(T &msk, int bit,\
    \ bool x) {\n    if (x) msk |= T(1) << bit;\n    else msk &= ~(T(1) << bit);\n\
    \  }\n  template<integral T> void flip_bit(T &msk, int bit) { msk ^= T(1) << bit;\
    \ }\n  template<integral T> bool get_bit(T msk, int bit) { return msk >> bit &\
    \ T(1); }\n\n  template<integral T> T floor_div(T a, T b) { return a / b - (a\
    \ % b < 0); }\n  template<integral T> T  ceil_div(T a, T b) { return a / b + (a\
    \ % b > 0); }\n\n  ull kth_root(ull a, int k) {\n    if (a == 0) return 0ull;\n\
    \    if (k >= 64) return 1ull;\n    if (k == 1) return a;\n    if (k == 2) {\n\
    \      ull b = sqrtl(a);\n      while((__int128)(b + 1) * (b + 1) <= a) b++;\n\
    \      while((__int128)b * b > a) b--;\n      return b;\n    }\n    if (k == 3)\
    \ {\n      ull b = cbrtl(a);\n      while((__int128)(b + 1) * (b + 1) * (b + 1)\
    \ <= a) b++;\n      while((__int128)b * b * b > a) b--;\n      return b;\n   \
    \ }\n    ull b = powl(a, 1.0L / k);\n    auto pw = [](ull a, int k) {\n      __int128\
    \ b = 1;\n      for(int i = 0; i < k; i++) b *= a;\n      return b;\n    };\n\
    \    while(pw(b + 1, k) <= a) b++;\n    while(pw(b, k) > a) b--;\n    return b;\n\
    \  }\n\n  template<class T> bool chmin(T &a, T b) { return a > b ? a = b, 1 :\
    \ 0; }\n  template<class T> bool chmax(T &a, T b) { return a < b ? a = b, 1 :\
    \ 0; }\n\n  template<integral T>\n  T binpow(T a, ull k) {\n    T b = 1;\n   \
    \ while(k) {\n      if (k & 1) b *= a;\n      a *= a, k >>= 1;\n    }\n    return\
    \ b;\n  }\n\n  template<ranges::random_access_range R>\n  ll inversion_count(R\
    \ v) {\n    ll f = 0;\n    auto tmp = v;\n    auto dc = [&](int l, int r, auto\
    \ &self) -> void {\n      if (l + 1 >= r) return;\n      int mid = (l + r) / 2;\n\
    \      self(l, mid, self);\n      self(mid, r, self);\n      {\n        int i\
    \ = l, j = mid, k = l;\n        while(i < mid and j < r) {\n          if (v[i]\
    \ <= v[j]) tmp[k++] = v[i++];\n          else tmp[k++] = v[j++], f += mid - i;\n\
    \        }\n        while(i < mid) tmp[k++] = v[i++];\n        while(j < r) tmp[k++]\
    \ = v[j++];\n      }\n      for(int i = l; i < r; i++)\n        v[i] = tmp[i];\n\
    \    };\n\n    dc(0, ssize(v), dc);\n\n    return f;\n  }\n}\n\nusing namespace\
    \ algorithm_extend;\n#line 1 \"modint/dynamic_modint.cpp\"\ntemplate<uint32_t\
    \ ver>\nstruct dynamic_modint {\n  using mint = dynamic_modint;\n  using u32 =\
    \ uint32_t;\n  using u64 = uint64_t;\n\n  static u32 mod;\n\n  static constexpr\
    \ u32 get_mod() { return mod; }\n  static void set_mod(u32 _mod) { mod = _mod;\
    \ }\n\n  dynamic_modint() : a(0) {}\n  dynamic_modint(const int64_t &b) : a((b\
    \ % mod + mod) % mod) {}\n\n  u32 a;\n\n  mint pow(u64 k) const {\n    mint res(1),\
    \ base(*this);\n    while(k) {\n      if (k & 1)\n        res *= base;\n     \
    \ base *= base, k >>= 1;\n    }\n    return res;\n  }\n\n  mint inverse() const\
    \ { return (*this).pow(mod - 2); }\n  u32 get() const { return a; }\n\n  mint&\
    \ norm() {\n    a = (a >= mod ? a - mod : a < 0 ? a + mod : a);\n    return *this;\n\
    \  }\n\n  mint& operator+=(mint b) {\n    a += b.a;\n    return (*this).norm();\n\
    \  }\n  mint& operator-=(mint b) {\n    if (b.a > a) a = a + mod - b.a;\n    else\
    \ a -= b.a;\n    return (*this).norm();\n  }\n  mint& operator*=(mint b) {\n \
    \   a = (u64(a) * b.a) % mod;\n    return *this;\n  }\n  mint& operator/=(mint\
    \ b) {\n    a = (u64(a) * b.inverse().a) % mod;\n    return *this;\n  }\n\n  mint\
    \ operator-() { return mint() - mint(*this); }\n  bool operator==(mint b) { return\
    \ a == b.a; }\n  bool operator!=(mint b) { return a != b.a; }\n  \n  friend mint\
    \ operator+(mint c, mint d) { return c += d; }\n  friend mint operator-(mint c,\
    \ mint d) { return c -= d; }\n  friend mint operator*(mint c, mint d) { return\
    \ c *= d; }\n  friend mint operator/(mint c, mint d) { return c /= d; }\n\n  friend\
    \ ostream& operator<<(ostream& os, const mint& b) {\n    return os << b.a;\n \
    \ }\n  friend istream& operator>>(istream& is, mint& b) {\n    int64_t val;\n\
    \    is >> val;\n    b = mint(val);\n    return is;\n  }\n};\n\ntemplate<> uint32_t\
    \ dynamic_modint<0>::mod = 2;\nusing mint = dynamic_modint<0>;\n#line 1 \"combi/stirling_first_kind_mod_P.cpp\"\
    \n//#include<modint/Montgomery_modint.cpp>\n\ntemplate<class Mint>\nstruct stirling_first_kind_mod_P\
    \ {\n  const int p;\n  vector<vector<Mint>> _s, _c;\n  stirling_first_kind_mod_P()\
    \ : p(Mint::get_mod()),\n    _s(p, vector<Mint>(p)), _c(p, vector<Mint>(p)) {\n\
    \    for(int i = 0; i < p; i++) {\n      for(int j = 1; j < i; j++)\n        _s[i][j]\
    \ = _s[i - 1][j - 1] + _s[i - 1][j] * -(i - 1);\n      _s[i][i] = 1;\n    }\n\
    \    for(int i = 0; i < p; i++) {\n      _c[i][0] = 1;\n      for(int j = 1; j\
    \ < i; j++)\n        _c[i][j] = _c[i - 1][j - 1] + _c[i - 1][j];\n      _c[i][i]\
    \ = 1;\n    }\n  }\n\n  Mint binom(int64_t n, int64_t k) {\n    if (k < 0 or n\
    \ < k) return Mint(0);\n    Mint r = 1;\n    while(n)\n      r *= _c[n % p][k\
    \ % p], n /= p, k /= p;\n    return r;\n  }\n\n  Mint s(int64_t n, int64_t k)\
    \ {\n    int64_t i = n / p, j = n % p;\n    int64_t b = ((k - i) % (p - 1) + (p\
    \ - 1)) % (p - 1);\n    int64_t a = (k - i - b) / (p - 1);\n    mint r = binom(i,\
    \ a) * ((i - a) % 2 == 1 ? -1 : 1) * _s[j][b];\n    if (b == 0 and a > 0)\n  \
    \    r += binom(i, a - 1) * ((i - a + 1) % 2 == 1 ? -1 : 1) * _s[j][p - 1];\n\
    \    return r;\n  }\n};\n#line 6 \"test/stirling_number_of_first_kind_small_p_large_n.test.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int t, p;\
    \ cin >> t >> p;\n  mint::set_mod(p);\n  stirling_first_kind_mod_P<mint> stir;\n\
    \  while(t--) {\n    ll n, k; cin >> n >> k;\n    cout << stir.s(n, k) << '\\\
    n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_small_p_large_n\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/dynamic_modint.cpp\"\n\
    #include \"../combi/stirling_first_kind_mod_P.cpp\"\n\nint main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int t, p; cin >> t >> p;\n  mint::set_mod(p);\n  stirling_first_kind_mod_P<mint>\
    \ stir;\n  while(t--) {\n    ll n, k; cin >> n >> k;\n    cout << stir.s(n, k)\
    \ << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/dynamic_modint.cpp
  - combi/stirling_first_kind_mod_P.cpp
  isVerificationFile: true
  path: test/stirling_number_of_first_kind_small_p_large_n.test.cpp
  requiredBy: []
  timestamp: '2026-09-02 20:44:03+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/stirling_number_of_first_kind_small_p_large_n.test.cpp
layout: document
redirect_from:
- /verify/test/stirling_number_of_first_kind_small_p_large_n.test.cpp
- /verify/test/stirling_number_of_first_kind_small_p_large_n.test.cpp.html
title: test/stirling_number_of_first_kind_small_p_large_n.test.cpp
---
