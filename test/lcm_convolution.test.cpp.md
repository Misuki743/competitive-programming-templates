---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':question:'
    path: modint/Montgomery_modint.cpp
    title: modint/Montgomery_modint.cpp
  - icon: ':heavy_check_mark:'
    path: numtheory/lcm_convolution.cpp
    title: numtheory/lcm_convolution.cpp
  - icon: ':question:'
    path: numtheory/linear_sieve.cpp
    title: numtheory/linear_sieve.cpp
  - icon: ':heavy_check_mark:'
    path: numtheory/zeta_mobius_on_divisibility_lattice.cpp
    title: numtheory/zeta_mobius_on_divisibility_lattice.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lcm_convolution
    links:
    - https://judge.yosupo.jp/problem/lcm_convolution
  bundledCode: "#line 1 \"test/lcm_convolution.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\
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
    \ algorithm_extend;\n#line 1 \"modint/Montgomery_modint.cpp\"\n//reference: https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
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
    \ = Montgomery_modint<998'244'353>;\n#line 1 \"numtheory/linear_sieve.cpp\"\n\
    template<int32_t C>\nclass linear_sieve {\n\n  static inline array<int, C> mpf\
    \ = {};\n  static inline vi prime;\n  static inline bool init = false;\n\n  static\
    \ void initialize() {\n    if (init) return;\n    init = true;\n    if (C > 2)\n\
    \      iota(mpf.begin() + 2, mpf.end(), 2);\n    for(int i = 2; i < C; i++) {\n\
    \      if (mpf[i] == i)\n        prime.emplace_back(i);\n      for(int64_t p :\
    \ prime) {\n        if (p > mpf[i] or p * i >= C)\n          break;\n        mpf[p\
    \ * i] = p;\n      }\n    }\n  }\n\n  public:\n\n  static vc<pii> prime_factorize(int\
    \ x) {\n    initialize();\n    vc<pii> r;\n    while(mpf[x]) {\n      r.emplace_back(mpf[x],\
    \ 0);\n      while(x % r.back().first == 0)\n        x /= r.back().first, r.back().second++;\n\
    \    }\n    return r;\n  }\n\n  static vi prime_factor(int x) {\n    initialize();\n\
    \    vi r;\n    while(mpf[x]) {\n      r.emplace_back(mpf[x]);\n      while(x\
    \ % r.back() == 0)\n        x /= r.back();\n    }\n    return r;\n  }\n\n  static\
    \ vi divisor(int x, bool sorted = true) {\n    initialize();\n    vi divisor =\
    \ {1};\n    for(auto [p, f] : prime_factorize(x)) {\n      vi nxt;\n      nxt.reserve(ssize(divisor)\
    \ * (f + 1));\n      for(int64_t i = 0, q = 1; i <= f; i++, q *= p)\n        for(int\
    \ d : divisor)\n          nxt.emplace_back(d * q);\n      divisor.swap(nxt);\n\
    \    }\n    if (sorted)\n      ranges::sort(divisor);\n    return divisor;\n \
    \ }\n\n  static const vi& prime_array() {\n    initialize();\n    return prime;\n\
    \  }\n  static const array<int, C>& mpf_array() {\n    initialize();\n    return\
    \ mpf;\n  }\n\n  static auto functions() {\n    return tuple(\n      &prime_factorize,\n\
    \      &prime_factor,\n      [](int x, bool sorted = true) { return divisor(x,\
    \ sorted); },\n      &prime_array,\n      &mpf_array\n    );\n  }\n};\n\n//auto\
    \ [prime_factorize, prime_factor, divisor, prime_array, mpf_array] = linear_sieve<>::functions();\n\
    #line 1 \"numtheory/zeta_mobius_on_divisibility_lattice.cpp\"\n//#include \"numtheory/linear_sieve\"\
    \n\ntemplate<class T, int32_t C>\nvector<T> zeta_transform_on_divisor(vector<T>\
    \ f) {\n  assert(ssize(f) <= C);\n  for(int64_t p : linear_sieve<C>::prime_array())\
    \ {\n    if (p >= ssize(f)) break;\n    for(int i = 1; i * p < ssize(f); i++)\n\
    \      f[i * p] += f[i];\n  }\n  return f;\n}\n\ntemplate<class T, int32_t C>\n\
    vector<T> mobius_transform_on_divisor(vector<T> f) {\n  assert(ssize(f) <= C);\n\
    \  for(int64_t p : linear_sieve<C>::prime_array()) {\n    if (p >= ssize(f)) break;\n\
    \    for(int i = (ssize(f) - 1) / p; i > 0; i--)\n      f[i * p] -= f[i];\n  }\n\
    \  return f;\n}\n\ntemplate<class T, int32_t C>\nvector<T> zeta_transform_on_multiple(vector<T>\
    \ f) {\n  assert(ssize(f) <= C);\n  for(int64_t p : linear_sieve<C>::prime_array())\
    \ {\n    if (p >= ssize(f)) break;\n    for(int i = (ssize(f) - 1) / p; i > 0;\
    \ i--)\n      f[i] += f[i * p];\n  }\n  return f;\n}\n\ntemplate<class T, int32_t\
    \ C>\nvector<T> mobius_transform_on_multiple(vector<T> f) {\n  assert(ssize(f)\
    \ <= C);\n  for(int64_t p : linear_sieve<C>::prime_array()) {\n    if (p >= ssize(f))\
    \ break;\n    for(int i = 1; i * p < ssize(f); i++)\n      f[i] -= f[i * p];\n\
    \  }\n  return f;\n}\n#line 1 \"numtheory/lcm_convolution.cpp\"\n//#include \"\
    numtheory/linear_sieve.cpp\"\n//#include \"numtheory/zeta_mobius_on_divisibility_lattice.cpp\"\
    \n\ntemplate<class T, int32_t C>\nvector<T> lcm_convolution(vector<T> a, vector<T>\
    \ b) {\n  assert(ssize(a) == ssize(b));\n  a = zeta_transform_on_divisor<T, C>(a);\n\
    \  b = zeta_transform_on_divisor<T, C>(b);\n  for(int i = 0; i < ssize(a); i++)\n\
    \    a[i] *= b[i];\n  return mobius_transform_on_divisor<T, C>(a);\n}\n#line 8\
    \ \"test/lcm_convolution.test.cpp\"\n\nint main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n; cin >> n;\n  vector<mint> a(n), b(n);\n  for(mint\
    \ &x : a) cin >> x;\n  for(mint &x : b) cin >> x;\n  a.insert(a.begin(), mint(0));\n\
    \  b.insert(b.begin(), mint(0));\n  auto c = lcm_convolution<mint, 1'000'001>(a,\
    \ b);\n  c.erase(c.begin());\n  cout << c << '\\n';\n\n  return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\n\n#include\
    \ \"../default/t.cpp\"\n#include \"../modint/Montgomery_modint.cpp\"\n#include\
    \ \"../numtheory/linear_sieve.cpp\"\n#include \"../numtheory/zeta_mobius_on_divisibility_lattice.cpp\"\
    \n#include \"../numtheory/lcm_convolution.cpp\"\n\nint main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n; cin >> n;\n  vector<mint> a(n), b(n);\n  for(mint\
    \ &x : a) cin >> x;\n  for(mint &x : b) cin >> x;\n  a.insert(a.begin(), mint(0));\n\
    \  b.insert(b.begin(), mint(0));\n  auto c = lcm_convolution<mint, 1'000'001>(a,\
    \ b);\n  c.erase(c.begin());\n  cout << c << '\\n';\n\n  return 0;\n}\n\n"
  dependsOn:
  - default/t.cpp
  - modint/Montgomery_modint.cpp
  - numtheory/linear_sieve.cpp
  - numtheory/zeta_mobius_on_divisibility_lattice.cpp
  - numtheory/lcm_convolution.cpp
  isVerificationFile: true
  path: test/lcm_convolution.test.cpp
  requiredBy: []
  timestamp: '2026-09-02 20:44:03+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/lcm_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/lcm_convolution.test.cpp
- /verify/test/lcm_convolution.test.cpp.html
title: test/lcm_convolution.test.cpp
---
