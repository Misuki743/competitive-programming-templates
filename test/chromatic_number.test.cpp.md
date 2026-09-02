---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combi/chromatic_number.cpp
    title: combi/chromatic_number.cpp
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: modint/dynamic_Montgomery_modint.cpp
    title: modint/dynamic_Montgomery_modint.cpp
  - icon: ':question:'
    path: numtheory/factorize_pollard_rho.cpp
    title: numtheory/factorize_pollard_rho.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/chromatic_number
    links:
    - https://judge.yosupo.jp/problem/chromatic_number
  bundledCode: "#line 1 \"test/chromatic_number.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\
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
    \  void psum(R &&v, F f) {\n    if (!v.empty())\n      for(T p = *v.begin(); T\
    \ &x : v | views::drop(1))\n        x = p = f(p, x);\n  }\n\n  template<ranges::forward_range\
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
    \  }\n}\n\nusing namespace algorithm_extend;\n#line 1 \"modint/dynamic_Montgomery_modint.cpp\"\
    \n//reference: https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
    //note: mod should be an odd prime less than 2^30.\n\ntemplate<uint32_t ver>\n\
    struct dynamic_Montgomery_modint {\n  using mint = dynamic_Montgomery_modint;\n\
    \  using i32 = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n\
    \  static u32 mod, n2, r;\n\n  static constexpr u32 get_r() {\n    u32 res = 1,\
    \ base = mod;\n    for(i32 i = 0; i < 31; i++)\n      res *= base, base *= base;\n\
    \    return -res;\n  }\n\n  static constexpr u32 get_mod() {\n    return mod;\n\
    \  }\n\n  static void set_mod(u32 _mod) {\n    mod = _mod;\n    n2 = -u64(mod)\
    \ % mod;\n    r = get_r();\n  }\n\n  u32 a;\n\n  static u32 reduce(const u64 &b)\
    \ {\n    return (b + u64(u32(b) * r) * mod) >> 32;\n  }\n\n  static u32 transform(const\
    \ u64 &b) {\n    return reduce(u64(b) * n2);\n  }\n\n  dynamic_Montgomery_modint()\
    \ : a(0) {}\n  dynamic_Montgomery_modint(const int64_t &b) \n    : a(transform(b\
    \ % mod + mod)) {}\n\n  mint pow(u64 k) const {\n    mint res(1), base(*this);\n\
    \    while(k) {\n      if (k & 1) \n        res *= base;\n      base *= base,\
    \ k >>= 1;\n    }\n    return res;\n  }\n\n  mint inverse() const { return (*this).pow(mod\
    \ - 2); }\n\n  u32 get() const {\n    u32 res = reduce(a);\n    return res >=\
    \ mod ? res - mod : res;\n  }\n\n  mint& operator+=(const mint &b) {\n    if (i32(a\
    \ += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  mint& operator-=(const\
    \ mint &b) {\n    if (i32(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n\
    \n  mint& operator*=(const mint &b) {\n    a = reduce(u64(a) * b.a);\n    return\
    \ *this;\n  }\n\n  mint& operator/=(const mint &b) {\n    a = reduce(u64(a) *\
    \ b.inverse().a);\n    return *this;\n  }\n\n  mint operator-() { return mint()\
    \ - mint(*this); }\n  bool operator==(mint b) const {\n    return (a >= mod ?\
    \ a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n  bool operator!=(mint\
    \ b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod :\
    \ b.a);\n  }\n\n  friend mint operator+(mint c, mint d) { return c += d; }\n \
    \ friend mint operator-(mint c, mint d) { return c -= d; }\n  friend mint operator*(mint\
    \ c, mint d) { return c *= d; }\n  friend mint operator/(mint c, mint d) { return\
    \ c /= d; }\n\n  friend ostream& operator<<(ostream& os, const mint& b) {\n  \
    \  return os << b.get();\n  }\n  friend istream& operator>>(istream& is, mint&\
    \ b) {\n    int64_t val;\n    is >> val;\n    b = mint(val);\n    return is;\n\
    \  }\n};\n\nusing mint = dynamic_Montgomery_modint<0>;\ntemplate<> uint32_t mint::mod\
    \ = 0;\ntemplate<> uint32_t mint::n2 = 0;\ntemplate<> uint32_t mint::r = 0;\n\
    #line 1 \"numtheory/factorize_pollard_rho.cpp\"\n//source: KACTL(https://github.com/kth-competitive-programming/kactl)\n\
    \null modmul(ull a, ull b, ull M) {\n  return (__int128)a * b % M;\n}\n\null modpow(ull\
    \ b, ull e, ull mod) {\n\tull ans = 1;\n\tfor (; e; b = modmul(b, b, mod), e /=\
    \ 2)\n\t\tif (e & 1) ans = modmul(ans, b, mod);\n\treturn ans;\n}\n\nbool isPrime(ull\
    \ n) {\n\tif (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n\tull A[] = {2, 325,\
    \ 9375, 28178, 450775, 9780504, 1795265022},\n\t    s = __builtin_ctzll(n-1),\
    \ d = n >> s;\n\tfor (ull a : A) {   // ^ count trailing zeroes\n\t\tull p = modpow(a%n,\
    \ d, n), i = s;\n\t\twhile (p != 1 && p != n - 1 && a % n && i--)\n\t\t\tp = modmul(p,\
    \ p, n);\n\t\tif (p != n-1 && i != s) return 0;\n\t}\n\treturn 1;\n}\n\null pollard(ull\
    \ n) {\n  static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \  uniform_int_distribution<ull> unif(0, n - 1);\n  ull c = 1;\n\tauto f = [n,\
    \ &c](ull x) { return modmul(x, x, n) + c % n; };\n\tull x = 0, y = 0, t = 30,\
    \ prd = 2, i = 1, q;\n\twhile (t++ % 40 || __gcd(prd, n) == 1) {\n\t\tif (x ==\
    \ y) c = unif(rng), x = ++i, y = f(x);\n\t\tif ((q = modmul(prd, max(x,y) - min(x,y),\
    \ n))) prd = q;\n\t\tx = f(x), y = f(f(y));\n\t}\n\treturn __gcd(prd, n);\n}\n\
    \nvector<ull> factor(ull n) {\n\tif (n == 1) return {};\n\tif (isPrime(n)) return\
    \ {n};\n\tull x = pollard(n);\n\tauto l = factor(x), r = factor(n / x);\n\tl.insert(l.end(),\
    \ r.begin(), r.end());\n\treturn l;\n}\n#line 1 \"combi/chromatic_number.cpp\"\
    \n//#include \"modint/dynamic_Montgomery_modint.cpp\"\n//#include \"numtheory/factorize_pollard_rho.cpp\"\
    \n\ntemplate<> uint32_t dynamic_Montgomery_modint<123>::mod = 0;\ntemplate<> uint32_t\
    \ dynamic_Montgomery_modint<123>::n2 = 0;\ntemplate<> uint32_t dynamic_Montgomery_modint<123>::r\
    \ = 0;\nint chromatic_number(vector<vector<bool>> g) {\n  const int n = ssize(g);\n\
    \n  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n  uniform_int_distribution<int>\
    \ unif(1 << 29, 1 << 30);\n  int p = 4;\n  while(!isPrime(p)) p = unif(rng);\n\
    \  using Mint = dynamic_Montgomery_modint<123>;\n  Mint::set_mod(p);\n\n  vector<Mint>\
    \ I(1 << n);\n  I[0] = 1;\n  for(unsigned msk = 1; msk < (1 << n); msk++) {\n\
    \    int v = countr_zero(bit_floor(msk));\n    I[msk] = I[msk ^ (1 << v)];\n \
    \   unsigned msk2 = msk ^ (1 << v);\n    for(int x = 0; x < n; x++)\n      if\
    \ (g[v][x] and (msk2 >> x & 1))\n        msk2 ^= 1 << x;\n    I[msk] += I[msk2];\n\
    \  }\n\n  auto check = [&](int c) {\n    if (c == n) return true;\n    Mint cnt\
    \ = 0;\n    for(unsigned msk = 0; msk < (1 << n); msk++)\n      cnt += I[msk].pow(c)\
    \ * (popcount(msk ^ ((1 << n) - 1)) % 2 == 1 ? -1 : 1);\n    return cnt != 0;\n\
    \  };\n\n  int c = 1;\n  while(!check(c)) c++;\n\n  return c;\n}\n#line 7 \"test/chromatic_number.test.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, m;\
    \ cin >> n >> m;\n  vector g(n, vector<bool>(n, false));\n  for(int i = 0; i <\
    \ m; i++) {\n    int u, v; cin >> u >> v;\n    g[u][v] = g[v][u] = true;\n  }\n\
    \n  cout << chromatic_number(g) << '\\n';\n\n  return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\n\n\
    #include \"../default/t.cpp\"\n#include \"modint/dynamic_Montgomery_modint.cpp\"\
    \n#include \"numtheory/factorize_pollard_rho.cpp\"\n#include \"combi/chromatic_number.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, m;\
    \ cin >> n >> m;\n  vector g(n, vector<bool>(n, false));\n  for(int i = 0; i <\
    \ m; i++) {\n    int u, v; cin >> u >> v;\n    g[u][v] = g[v][u] = true;\n  }\n\
    \n  cout << chromatic_number(g) << '\\n';\n\n  return 0;\n}\n\n"
  dependsOn:
  - default/t.cpp
  - modint/dynamic_Montgomery_modint.cpp
  - numtheory/factorize_pollard_rho.cpp
  - combi/chromatic_number.cpp
  isVerificationFile: true
  path: test/chromatic_number.test.cpp
  requiredBy: []
  timestamp: '2026-09-02 17:47:14+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/chromatic_number.test.cpp
layout: document
redirect_from:
- /verify/test/chromatic_number.test.cpp
- /verify/test/chromatic_number.test.cpp.html
title: test/chromatic_number.test.cpp
---
