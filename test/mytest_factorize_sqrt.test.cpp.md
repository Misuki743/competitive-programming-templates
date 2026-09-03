---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: numtheory/factorize_pollard_rho.cpp
    title: numtheory/factorize_pollard_rho.cpp
  - icon: ':heavy_check_mark:'
    path: numtheory/factorize_sqrt.cpp
    title: numtheory/factorize_sqrt.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest_factorize_sqrt.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"default/t.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define pb push_back\n#define eb emplace_back\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ldb = long double;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate<typename T>\
    \ using vc = vector<T>;\ntemplate<typename T> using vvc = vc<vc<T>>;\ntemplate<typename\
    \ T> using vvvc = vc<vvc<T>>;\n\nusing vi = vc<int>;\nusing vll = vc<ll>;\nusing\
    \ vvi = vvc<int>;\nusing vvll = vvc<ll>;\n\ntemplate<typename T> using min_heap\
    \ = priority_queue<T, vc<T>, greater<T>>;\ntemplate<typename T> using max_heap\
    \ = priority_queue<T>;\n\nnamespace output {\n  ostream& operator<<(ostream& os,\
    \ __uint128_t x) {\n    if (x == 0) {\n      return os << \"0\";\n    } else {\n\
    \      string s;\n      while(x)\n        s += '0' + x % 10, x /= 10;\n      ranges::reverse(s);\n\
    \      return os << s;\n    }\n  }\n\n  ostream& operator<<(ostream& os, __int128_t\
    \ x) {\n    if (x < 0)\n      return os << \"-\" << -(__uint128_t)x;\n    else\n\
    \      return os << (__uint128_t)x;\n  }\n\n  template<size_t I = 0, typename...\
    \ args>\n  ostream& print_tuple(ostream& os, const tuple<args...> tu) {\n    os\
    \ << get<I>(tu);\n    if constexpr (I + 1 != sizeof...(args)) {\n      os << '\
    \ ';\n      print_tuple<I + 1>(os, tu);\n    }\n    return os;\n  }\n\n  template<typename...\
    \ args>\n  ostream& operator<<(ostream& os, const tuple<args...> tu) {\n    return\
    \ print_tuple(os, tu);\n  }\n\n  template<class T1, class T2>\n  ostream& operator<<(ostream&\
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
    \ algorithm_extend;\n\nnamespace sieve_of_Eratosthenes {\n\n  int _C = 5;\n  vc<int32_t>\
    \ _mpf, _prime = {2, 3};\n\n  //n % 6 == 1 or 5\n  int _id(int n) {\n    return\
    \ (n - 2) / 6 * 2 + (n % 6 == 1);\n  }\n\n  int _first_valid(int n) {\n    static\
    \ int d[6] = {1, 0, 3, 2, 1, 0};\n    return n + d[n % 6];\n  }\n\n  int _next_valid(int\
    \ n) {\n    static int d[6] = {1, 4, 3, 2, 1, 2};\n    return n + d[n % 6];\n\
    \  }\n\n  void sieve(int n) {\n    assert(n <= (1 << 30));\n    _C = _first_valid(_C);\n\
    \    n = _first_valid(bit_ceil(n * 1ull));\n    if (n <= _C) return;\n    _mpf.resize(_id(n));\n\
    \    for(int i = _C, d = _next_valid(_C) - _C; i < n; i += d, d = 6 - d)\n   \
    \   _mpf[_id(i)] = i;\n    for(int i = 5, d = 2; i * i < n; i += d, d = 6 - d)\
    \ if (_mpf[_id(i)] == i) {\n      int k = _first_valid(max(i, ceil_div(_C, i)));\n\
    \      for(int j = i * k, e = _next_valid(k) - k; j < n; j += i * e, e = 6 - e)\n\
    \        _mpf[_id(j)] = min<int32_t>(_mpf[_id(j)], i);\n    }\n    _C = n;\n \
    \ }\n\n  int mpf(int n) {\n    if (n == 1) return 0;\n    if (n % 2 == 0) return\
    \ 2;\n    if (n % 3 == 0) return 3;\n    if (n >= _C) sieve(n);\n    return _mpf[_id(n)];\n\
    \  }\n\n  template<typename F>\n  requires invocable<F, int, int>\n  void factorize(int\
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
    \ namespace sieve_of_Eratosthenes;\n#line 1 \"numtheory/factorize_sqrt.cpp\"\n\
    vc<pair<int64_t, int64_t>> prime_factorize_sqrt(int64_t x) {\n  using i64 = int64_t;\n\
    \  vc<pair<i64, i64>> res;\n  for(i64 d = 2; d * d <= x; d++) {\n    if (x % d\
    \ != 0) continue;\n    res.emplace_back(d, 0ll);\n    while(x % d == 0)\n    \
    \  x /= d, res.back().second++;\n  }\n  if (x != 1) res.emplace_back(x, 1);\n\
    \  return res;\n}\n\nvc<int64_t> prime_factor_sqrt(int64_t x) {\n  using i64 =\
    \ int64_t;\n  vc<i64> res;\n  for(i64 d = 2; d * d <= x; d++) {\n    if (x % d\
    \ != 0) continue;\n    res.emplace_back(d);\n    while(x % d == 0)\n      x /=\
    \ d;\n  }\n  if (x != 1) res.emplace_back(x);\n  return res;\n}\n\nvc<int64_t>\
    \ divisor_sqrt(int64_t x, bool sorted = true) {\n  using i64 = int64_t;\n  vc<i64>\
    \ divisor = {1};\n  for(auto [p, f] : prime_factorize_sqrt(x)) {\n    vc<i64>\
    \ nxt;\n    nxt.reserve(ssize(divisor) * (f + 1));\n    uint64_t q = 1;\n    for(int\
    \ i = 0; i <= f; i++, q *= p)\n      for(i64 d : divisor)\n        nxt.emplace_back(d\
    \ * q);\n    divisor.swap(nxt);\n  }\n  if (sorted)\n    ranges::sort(divisor);\n\
    \  return divisor;\n}\n#line 1 \"numtheory/factorize_pollard_rho.cpp\"\n//source:\
    \ KACTL(https://github.com/kth-competitive-programming/kactl)\n\null modmul(ull\
    \ a, ull b, ull M) {\n  return (__int128)a * b % M;\n}\n\null modpow(ull b, ull\
    \ e, ull mod) {\n\tull ans = 1;\n\tfor (; e; b = modmul(b, b, mod), e /= 2)\n\t\
    \tif (e & 1) ans = modmul(ans, b, mod);\n\treturn ans;\n}\n\nbool isPrime(ull\
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
    \ r.begin(), r.end());\n\treturn l;\n}\n#line 6 \"test/mytest_factorize_sqrt.test.cpp\"\
    \n\nvoid check(int64_t x) {\n  vc<int64_t> pf;\n  for(auto p : factor(x))\n  \
    \  pf.eb(p);\n  ranges::sort(pf);\n  vc<pair<int64_t, int64_t>> pf2;\n  for(int\
    \ i = 0, j = 0; i < ssize(pf); i = j) {\n    while(j < ssize(pf) and pf[i] ==\
    \ pf[j]) j++;\n    pf2.emplace_back(pf[i], j - i);\n  }\n  pf.resize(unique(pf.begin(),\
    \ pf.end()) - pf.begin());\n  vc<int64_t> divisor;\n  auto dfs = [&](int i, int64_t\
    \ prod, auto &self) -> void {\n    if (i == ssize(pf)) {\n      divisor.emplace_back(prod);\n\
    \      return;\n    }\n    for(int j = 0; j <= pf2[i].second; j++) {\n      if\
    \ (j) prod *= pf2[i].first;\n      self(i + 1, prod, self);\n    }\n  };\n  dfs(0,\
    \ 1, dfs);\n  ranges::sort(divisor);\n  \n  assert(pf2 == prime_factorize_sqrt(x));\n\
    \  assert(pf == prime_factor_sqrt(x));\n  assert(divisor == divisor_sqrt(x));\n\
    }\n\nvoid check_small() {\n  for(int64_t x = 1; x < (1 << 10); x++)\n    check(x);\n\
    }\n\nvoid check_large() {\n  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \  for(int64_t l = (1ll << 10); l < (1ll << 53); l <<= 1)\n    for(int i = 0;\
    \ i < 10; i++)\n      check(rng() % l + l);\n}\n\nvoid a_plus_b() {\n  int x,\
    \ y; cin >> x >> y;\n  cout << x + y << '\\n';\n}\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  check_small();\n  check_large();\n  a_plus_b();\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../default/t.cpp\"\n#include \"../numtheory/factorize_sqrt.cpp\"\n#include \"\
    ../numtheory/factorize_pollard_rho.cpp\"\n\nvoid check(int64_t x) {\n  vc<int64_t>\
    \ pf;\n  for(auto p : factor(x))\n    pf.eb(p);\n  ranges::sort(pf);\n  vc<pair<int64_t,\
    \ int64_t>> pf2;\n  for(int i = 0, j = 0; i < ssize(pf); i = j) {\n    while(j\
    \ < ssize(pf) and pf[i] == pf[j]) j++;\n    pf2.emplace_back(pf[i], j - i);\n\
    \  }\n  pf.resize(unique(pf.begin(), pf.end()) - pf.begin());\n  vc<int64_t> divisor;\n\
    \  auto dfs = [&](int i, int64_t prod, auto &self) -> void {\n    if (i == ssize(pf))\
    \ {\n      divisor.emplace_back(prod);\n      return;\n    }\n    for(int j =\
    \ 0; j <= pf2[i].second; j++) {\n      if (j) prod *= pf2[i].first;\n      self(i\
    \ + 1, prod, self);\n    }\n  };\n  dfs(0, 1, dfs);\n  ranges::sort(divisor);\n\
    \  \n  assert(pf2 == prime_factorize_sqrt(x));\n  assert(pf == prime_factor_sqrt(x));\n\
    \  assert(divisor == divisor_sqrt(x));\n}\n\nvoid check_small() {\n  for(int64_t\
    \ x = 1; x < (1 << 10); x++)\n    check(x);\n}\n\nvoid check_large() {\n  mt19937_64\
    \ rng(chrono::steady_clock::now().time_since_epoch().count());\n  for(int64_t\
    \ l = (1ll << 10); l < (1ll << 53); l <<= 1)\n    for(int i = 0; i < 10; i++)\n\
    \      check(rng() % l + l);\n}\n\nvoid a_plus_b() {\n  int x, y; cin >> x >>\
    \ y;\n  cout << x + y << '\\n';\n}\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  check_small();\n  check_large();\n  a_plus_b();\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - numtheory/factorize_sqrt.cpp
  - numtheory/factorize_pollard_rho.cpp
  isVerificationFile: true
  path: test/mytest_factorize_sqrt.test.cpp
  requiredBy: []
  timestamp: '2026-09-03 11:20:30+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest_factorize_sqrt.test.cpp
layout: document
redirect_from:
- /verify/test/mytest_factorize_sqrt.test.cpp
- /verify/test/mytest_factorize_sqrt.test.cpp.html
title: test/mytest_factorize_sqrt.test.cpp
---
