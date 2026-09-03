---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: combi/binomial.cpp
    title: combi/binomial.cpp
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: modint/dynamic_modint.cpp
    title: modint/dynamic_modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"test/binomial_coefficient_prime_mod.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\n\
    \n#line 1 \"default/t.cpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define pb push_back\n#define eb emplace_back\n\nusing ll = long long;\nusing\
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
    \  void psum(R &&v, F f) {\n    if (!ranges::empty(v))\n      for(T p = *v.begin();\
    \ T &x : v | views::drop(1))\n        x = p = f(p, x);\n  }\n\n  template<ranges::forward_range\
    \ R, class T = ranges::range_value_t<R>>\n  void psum(R &&v) {\n    if (!ranges::empty(v))\n\
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
    \ algorithm_extend;\n\nnamespace Combinatorics {\n  template<class Mint>\n  Mint\
    \ factorial(int n) {\n    static vc<Mint> dat;\n    if (n >= ssize(dat)) {\n \
    \     if (dat.empty()) dat.eb(1);\n      int size0 = ssize(dat);\n      dat.resize(min(Mint::get_mod(),\
    \ bit_ceil((uint32_t)(n + 1))));\n      for(int i = size0; i < ssize(dat); i++)\n\
    \        dat[i] = dat[i - 1] * i;\n    }\n    return dat[n];\n  }\n\n  template<class\
    \ Mint>\n  Mint factorial_inv(int n) {\n    static vc<Mint> dat;\n    if (n >=\
    \ ssize(dat)) {\n      int size0 = ssize(dat);\n      dat.resize(min(Mint::get_mod(),\
    \ bit_ceil((uint32_t)(n + 1))));\n      dat.back() = factorial<Mint>(ssize(dat)\
    \ - 1).inverse();\n      for(int i = ssize(dat) - 2; i >= size0; i--)\n      \
    \  dat[i] = dat[i + 1] * (i + 1);\n    }\n    return dat[n];\n  }\n\n  template<class\
    \ Mint>\n  Mint inverse(int n) {\n    return factorial_inv<Mint>(n) * factorial<Mint>(n\
    \ - 1);\n  }\n\n  template<class Mint>\n  Mint binomial(int n, int k) {\n    if\
    \ (0 <= k and k <= n)\n      return factorial<Mint>(n) * factorial_inv<Mint>(k)\
    \ * factorial_inv<Mint>(n - k);\n    else\n      return Mint(0);\n  }\n\n  template<class\
    \ Mint>\n  Mint catalan(int n) {\n    return binomial<Mint>(2 * n, n) - binomial<Mint>(2\
    \ * n, n + 1);\n  }\n\n  //number of up-down path with n (+1), m (-1) and never\
    \ touch y = -k\n  template<class Mint>\n  Mint excatalan(int n, int m, int k)\
    \ {\n    if (k > m) return binomial<Mint>(n + m, m);\n    else if (k > m - n)\
    \ return binomial<Mint>(n + m, m) - binomial<Mint>(n + m, m - k);\n    else return\
    \ Mint(0);\n  }\n\n  template<class Mint>\n  auto binomial_functions() {\n   \
    \ return tuple(\n      &factorial<Mint>,\n      &factorial_inv<Mint>,\n      &inverse<Mint>,\n\
    \      &binomial<Mint>,\n      &catalan<Mint>,\n      &excatalan<Mint>\n    );\n\
    \  }\n}\n\nusing namespace Combinatorics;\n\nnamespace sieve_of_Eratosthenes {\n\
    \n  int _C = 5;\n  vc<int32_t> _mpf, _prime = {2, 3};\n\n  //n % 6 == 1 or 5\n\
    \  int _id(int n) {\n    return (n - 2) / 6 * 2 + (n % 6 == 1);\n  }\n\n  int\
    \ _first_valid(int n) {\n    static int d[6] = {1, 0, 3, 2, 1, 0};\n    return\
    \ n + d[n % 6];\n  }\n\n  int _next_valid(int n) {\n    static int d[6] = {1,\
    \ 4, 3, 2, 1, 2};\n    return n + d[n % 6];\n  }\n\n  void sieve(int n) {\n  \
    \  assert(n <= (1 << 30));\n    _C = _first_valid(_C);\n    n = _first_valid(bit_ceil(n\
    \ * 1ull));\n    if (n <= _C) return;\n    _mpf.resize(_id(n));\n    for(int i\
    \ = _C, d = _next_valid(_C) - _C; i < n; i += d, d = 6 - d)\n      _mpf[_id(i)]\
    \ = i;\n    for(int i = 5, d = 2; i * i < n; i += d, d = 6 - d) if (_mpf[_id(i)]\
    \ == i) {\n      int k = _first_valid(max(i, ceil_div(_C, i)));\n      for(int\
    \ j = i * k, e = _next_valid(k) - k; j < n; j += i * e, e = 6 - e)\n        _mpf[_id(j)]\
    \ = min<int32_t>(_mpf[_id(j)], i);\n    }\n    _C = n;\n  }\n\n  int mpf(int n)\
    \ {\n    if (n == 1) return 0;\n    if (n % 2 == 0) return 2;\n    if (n % 3 ==\
    \ 0) return 3;\n    if (n >= _C) sieve(n);\n    return _mpf[_id(n)];\n  }\n\n\
    \  template<typename F>\n  requires invocable<F, int, int>\n  void factorize(int\
    \ n, F f) {\n    if (n >= _C) sieve(n);\n    if (n % 2 == 0) f(2, countr_zero(n\
    \ * 1ull)), n >>= countr_zero(n * 1ull);\n    if (n % 3 == 0) {\n      int e =\
    \ 0;\n      while(n % 3 == 0) n /= 3, e++;\n      f(3, e);\n    }\n    while(n\
    \ > 1) {\n      int p = mpf(n), e = 0;\n      while(n % p == 0) n /= p, e++;\n\
    \      f(p, e);\n    }\n  }\n\n  vi divisor(int n) {\n    static array<int, 1\
    \ << 12> buf;\n    if (n >= _C) sieve(n);\n    vi v = {1};\n    factorize(n, [&v](int\
    \ p, int e) {\n      int old_size = ssize(v);\n      v.resize(old_size * (e +\
    \ 1));\n      for(int i = old_size; i < ssize(v); i++)\n        v[i] = v[i - old_size]\
    \ * p;\n      for(int d = old_size; d < ssize(v); d <<= 1) {\n        for(int\
    \ i = 0; i + d < ssize(v); i += 2 * d) {\n          merge(v.begin() + i, v.begin()\
    \ + i + d, v.begin() + i + d, v.begin() + min(i + 2 * d, (int)size(v)), buf.begin());\n\
    \          copy(buf.begin(), buf.begin() + min(2 * d, (int)size(v) - i), v.begin()\
    \ + i);\n        }\n      }\n    });\n    return v;\n  }\n\n  template<typename\
    \ F>\n  requires invocable<F, int>\n  void primes(int m, F f) {\n    if (_next_valid(_prime.back())\
    \ < m) {\n      if (m > _C) sieve(m);\n      int s = _next_valid(_prime.back());\n\
    \      for(int i = s, d = _next_valid(s) - s; i < m; i += d, d = 6 - d)\n    \
    \    if (_mpf[_id(i)] == i)\n          _prime.eb(i);\n    }\n    for(int i = 0;\
    \ i < ssize(_prime) and _prime[i] < m; i++)\n      f(_prime[i]);\n  }\n}\n\nusing\
    \ namespace sieve_of_Eratosthenes;\n#line 1 \"modint/dynamic_modint.cpp\"\ntemplate<uint32_t\
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
    \ dynamic_modint<0>::mod = 2;\nusing mint = dynamic_modint<0>;\n#line 1 \"combi/binomial.cpp\"\
    \ntemplate<class Mint>\nMint factorial(int n) {\n  static vc<Mint> dat;\n  if\
    \ (n >= ssize(dat)) {\n    if (dat.empty()) dat.eb(1);\n    int size0 = ssize(dat);\n\
    \    dat.resize(min(Mint::get_mod(), bit_ceil((uint32_t)(n + 1))));\n    for(int\
    \ i = size0; i < ssize(dat); i++)\n      dat[i] = dat[i - 1] * i;\n  }\n  return\
    \ dat[n];\n}\n\ntemplate<class Mint>\nMint factorial_inv(int n) {\n  static vc<Mint>\
    \ dat;\n  if (n >= ssize(dat)) {\n    int size0 = ssize(dat);\n    dat.resize(min(Mint::get_mod(),\
    \ bit_ceil((uint32_t)(n + 1))));\n    dat.back() = factorial<Mint>(ssize(dat)\
    \ - 1).inverse();\n    for(int i = ssize(dat) - 2; i >= size0; i--)\n      dat[i]\
    \ = dat[i + 1] * (i + 1);\n  }\n  return dat[n];\n}\n\ntemplate<class Mint>\n\
    Mint inverse(int n) {\n  return factorial_inv<Mint>(n) * factorial<Mint>(n - 1);\n\
    }\n\ntemplate<class Mint>\nMint binomial(int n, int k) {\n  if (0 <= k and k <=\
    \ n)\n    return factorial<Mint>(n) * factorial_inv<Mint>(k) * factorial_inv<Mint>(n\
    \ - k);\n  else\n    return Mint(0);\n}\n\ntemplate<class Mint>\nMint catalan(int\
    \ n) {\n  return binomial<Mint>(2 * n, n) - binomial<Mint>(2 * n, n + 1);\n}\n\
    \n//number of up-down path with n (+1), m (-1) and never touch y = -k\ntemplate<class\
    \ Mint>\nMint excatalan(int n, int m, int k) {\n  if (k > m) return binomial<Mint>(n\
    \ + m, m);\n  else if (k > m - n) return binomial<Mint>(n + m, m) - binomial<Mint>(n\
    \ + m, m - k);\n  else return Mint(0);\n}\n\ntemplate<class Mint>\nauto binomial_functions()\
    \ {\n  return tuple(\n    &factorial<Mint>,\n    &factorial_inv<Mint>,\n    &inverse<Mint>,\n\
    \    &binomial<Mint>,\n    &catalan<Mint>,\n    &excatalan<Mint>\n  );\n}\n\n\
    //auto [fac, faci, inv, binom, cat, excat] = binomial_functions<mint>();\n#line\
    \ 6 \"test/binomial_coefficient_prime_mod.test.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int t, p; cin >> t >> p;\n  mint::set_mod(p);\n  while(t--)\
    \ {\n    int n, k; cin >> n >> k;\n    cout << binomial<mint>(n, k) << '\\n';\n\
    \  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/dynamic_modint.cpp\"\n\
    #include \"../combi/binomial.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int t, p; cin >> t >> p;\n  mint::set_mod(p);\n  while(t--)\
    \ {\n    int n, k; cin >> n >> k;\n    cout << binomial<mint>(n, k) << '\\n';\n\
    \  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/dynamic_modint.cpp
  - combi/binomial.cpp
  isVerificationFile: true
  path: test/binomial_coefficient_prime_mod.test.cpp
  requiredBy: []
  timestamp: '2026-09-03 10:52:15+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/binomial_coefficient_prime_mod.test.cpp
layout: document
redirect_from:
- /verify/test/binomial_coefficient_prime_mod.test.cpp
- /verify/test/binomial_coefficient_prime_mod.test.cpp.html
title: test/binomial_coefficient_prime_mod.test.cpp
---
