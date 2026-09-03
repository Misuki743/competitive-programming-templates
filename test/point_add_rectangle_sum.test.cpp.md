---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: ds/fenwick_tree_2D.cpp
    title: ds/fenwick_tree_2D.cpp
  - icon: ':x:'
    path: ds_problem/pointAddRectangleSum.cpp
    title: ds_problem/pointAddRectangleSum.cpp
  - icon: ':x:'
    path: misc/compression.cpp
    title: misc/compression.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/point_add_rectangle_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\n#line 1 \"default/t.cpp\"\
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
    \ f;\n  }\n}\n\nusing namespace algorithm_extend;\n\nnamespace Combinatorics {\n\
    \  template<class Mint>\n  Mint factorial(int n) {\n    static vc<Mint> dat;\n\
    \    if (n >= ssize(dat)) {\n      if (dat.empty()) dat.eb(1);\n      int size0\
    \ = ssize(dat);\n      dat.resize(min(Mint::get_mod(), bit_ceil((uint32_t)(n +\
    \ 1))));\n      for(int i = size0; i < ssize(dat); i++)\n        dat[i] = dat[i\
    \ - 1] * i;\n    }\n    return dat[n];\n  }\n\n  template<class Mint>\n  Mint\
    \ factorial_inv(int n) {\n    static vc<Mint> dat;\n    if (n >= ssize(dat)) {\n\
    \      int size0 = ssize(dat);\n      dat.resize(min(Mint::get_mod(), bit_ceil((uint32_t)(n\
    \ + 1))));\n      dat.back() = factorial<Mint>(ssize(dat) - 1).inverse();\n  \
    \    for(int i = ssize(dat) - 2; i >= size0; i--)\n        dat[i] = dat[i + 1]\
    \ * (i + 1);\n    }\n    return dat[n];\n  }\n\n  template<class Mint>\n  Mint\
    \ inverse(int n) {\n    return factorial_inv<Mint>(n) * factorial<Mint>(n - 1);\n\
    \  }\n\n  template<class Mint>\n  Mint binomial(int n, int k) {\n    if (0 <=\
    \ k and k <= n)\n      return factorial<Mint>(n) * factorial_inv<Mint>(k) * factorial_inv<Mint>(n\
    \ - k);\n    else\n      return Mint(0);\n  }\n\n  template<class Mint>\n  Mint\
    \ catalan(int n) {\n    return binomial<Mint>(2 * n, n) - binomial<Mint>(2 * n,\
    \ n + 1);\n  }\n\n  //number of up-down path with n (+1), m (-1) and never touch\
    \ y = -k\n  template<class Mint>\n  Mint excatalan(int n, int m, int k) {\n  \
    \  if (k > m) return binomial<Mint>(n + m, m);\n    else if (k > m - n) return\
    \ binomial<Mint>(n + m, m) - binomial<Mint>(n + m, m - k);\n    else return Mint(0);\n\
    \  }\n\n  template<class Mint>\n  auto binomial_functions() {\n    return tuple(\n\
    \      &factorial<Mint>,\n      &factorial_inv<Mint>,\n      &inverse<Mint>,\n\
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
    \ namespace sieve_of_Eratosthenes;\n#line 1 \"ds/fenwick_tree_2D.cpp\"\n//source:\
    \ KACTL\n\n/**\n * Author: Lukas Polacek\n * Date: 2009-10-30\n * License: CC0\n\
    \ * Source: folklore/TopCoder\n * Description: Computes partial sums a[0] + a[1]\
    \ + ... + a[pos - 1], and updates single elements a[i],\n * taking the difference\
    \ between the old and new value.\n * Time: Both operations are $O(\\log N)$.\n\
    \ * Status: Stress-tested\n */\ntemplate<class T>\nstruct FT {\n\tvector<T> s;\n\
    \tFT(int n) : s(n) {}\n\tvoid update(int pos, T dif) { // a[pos] += dif\n\t\t\
    for (; pos < ssize(s); pos |= pos + 1) s[pos] += dif;\n\t}\n\tT query(int pos)\
    \ { // sum of values in [0, pos)\n\t\tT res = 0;\n\t\tfor (; pos > 0; pos &= pos\
    \ - 1) res += s[pos-1];\n\t\treturn res;\n\t}\n\tint lower_bound(T sum) {// min\
    \ pos st sum of [0, pos] >= sum\n\t\t// Returns n if no sum is >= sum, or -1 if\
    \ empty sum is.\n\t\tif (sum <= 0) return -1;\n\t\tint pos = 0;\n\t\tfor (int\
    \ pw = 1 << 25; pw; pw >>= 1) {\n\t\t\tif (pos + pw <= ssize(s) && s[pos + pw-1]\
    \ < sum)\n\t\t\t\tpos += pw, sum -= s[pos-1];\n\t\t}\n\t\treturn pos;\n\t}\n};\n\
    \n/**\n * Author: Simon Lindholm\n * Date: 2017-05-11\n * License: CC0\n * Source:\
    \ folklore\n * Description: Computes sums a[i,j] for all i<I, j<J, and increases\
    \ single elements a[i,j].\n *  Requires that the elements to be updated are known\
    \ in advance (call fakeUpdate() before init()).\n * Time: $O(\\log^2 N)$. (Use\
    \ persistent segment trees for $O(\\log N)$.)\n * Status: stress-tested\n */\n\
    template<class T1, class T2>\nstruct FT2 {\n\tvector<vector<T1>> ys; vector<FT<T2>>\
    \ ft;\n\tFT2(int limx) : ys(limx) {}\n\tvoid fakeUpdate(int x, T1 y) {\n\t\tfor\
    \ (; x < ssize(ys); x |= x + 1) ys[x].push_back(y);\n\t}\n\tvoid init() {\n\t\t\
    for (vector<T1>& v : ys) ranges::sort(v), ft.emplace_back(ssize(v));\n\t}\n\t\
    int ind(int x, T1 y) {\n\t\treturn (int)(ranges::lower_bound(ys[x], y) - ys[x].begin());\
    \ }\n\tvoid update(int x, T1 y, T2 dif) {\n\t\tfor (; x < ssize(ys); x |= x +\
    \ 1)\n\t\t\tft[x].update(ind(x, y), dif);\n\t}\n\tT2 query(int x, T1 y) {\n\t\t\
    T2 sum = 0;\n\t\tfor (; x; x &= x - 1)\n\t\t\tsum += ft[x-1].query(ind(x-1, y));\n\
    \t\treturn sum;\n\t}\n};\n#line 1 \"misc/compression.cpp\"\ntemplate<class T,\
    \ bool duplicate = false>\nstruct compression {\n  vector<int> ord;\n  vector<T>\
    \ val;\n\n  compression(vector<T> &init) : val(init) { precompute(); }\n  compression(int\
    \ size = 0) { val.reserve(size); }\n\n  void precompute() {\n    vector<T> init\
    \ = val;\n    ord.resize(ssize(val));\n    ranges::sort(val);\n    if constexpr\
    \ (duplicate) {\n      vector<int> cnt(ssize(init));\n      iota(cnt.begin(),\
    \ cnt.end(), 0);\n      for(int i = 0; i < ssize(ord); i++)\n        ord[i] =\
    \ cnt[lower_bound(init[i])]++;\n    } else {\n      val.resize(unique(val.begin(),\
    \ val.end()) - val.begin());\n      for(int i = 0; i < ssize(ord); i++)\n    \
    \    ord[i] = lower_bound(init[i]);\n    }\n  }\n\n  int lower_bound(T x) { return\
    \ ranges::lower_bound(val, x) - val.begin(); }\n  int size() { return ssize(val);\
    \ }\n  template<ranges::range rng, class proj = identity>\n  void mapping(rng\
    \ &v, proj p = {}) { for(auto &x : v) p(x) = lower_bound(p(x)); }\n  template<ranges::range\
    \ rng, class proj = identity>\n  void insert(rng &v, proj p = {}) { for(auto &x\
    \ : v) val.emplace_back(p(x)); }\n};\n#line 1 \"ds_problem/pointAddRectangleSum.cpp\"\
    \n//#include<ds/fenwickTree2D.cpp>\n//#include<misc/compression.cpp>\n\ntemplate<class\
    \ T1, class T2>\nvector<T2> pointAddRectSum(vector<tuple<T1, T1, T2>> pt, vector<array<T1,\
    \ 4>> query, vector<int> updT) {\n  compression<T1> xs(ssize(pt));\n  xs.insert(pt,\
    \ [](auto &x) { return get<0>(x); });\n  xs.precompute();\n  xs.mapping(pt, [](auto\
    \ &x) -> T1& { return get<0>(x); });\n  xs.mapping(query, [](auto &x) -> T1& {\
    \ return x[0]; });\n  xs.mapping(query, [](auto &x) -> T1& { return x[1]; });\n\
    \n  FT2<T1, T2> bit(xs.size());\n  for(auto [x, y, __] : pt)\n    bit.fakeUpdate(x,\
    \ y);\n  bit.init();\n\n  vector<T2> ans(ssize(query));\n  for(int i = 0, ptr\
    \ = 0; auto [l, r, d, u] : query) {\n    while(ptr < ssize(pt) and updT[ptr] <=\
    \ i) {\n      auto [x, y, w] = pt[ptr++];\n      bit.update(x, y, w);\n    }\n\
    \    ans[i++] = bit.query(r, u) - bit.query(l, u) - bit.query(r, d) + bit.query(l,\
    \ d);\n  }\n  \n  return ans;\n}\n#line 7 \"test/point_add_rectangle_sum.test.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q;\
    \ cin >> n >> q;\n  vector<tuple<int, int, ll>> pt(n);\n  for(auto &[x, y, w]\
    \ : pt)\n    cin >> x >> y >> w;\n  vector<array<int, 4>> query;\n  vector<int>\
    \ updT(n);\n  while(q--) {\n    int t; cin >> t;\n    if (t == 0) {\n      int\
    \ x, y, w; cin >> x >> y >> w;\n      updT.emplace_back(ssize(query));\n     \
    \ pt.emplace_back(x, y, w);\n    } else if (t == 1) {\n      int l, r, d, u; cin\
    \ >> l >> d >> r >> u;\n      query.push_back({l, r, d, u});\n    }\n  }\n\n \
    \ for(ll x : pointAddRectSum<int, ll>(pt, query, updT))\n    cout << x << '\\\
    n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../ds/fenwick_tree_2D.cpp\"\n#include\
    \ \"../misc/compression.cpp\"\n#include \"../ds_problem/pointAddRectangleSum.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q;\
    \ cin >> n >> q;\n  vector<tuple<int, int, ll>> pt(n);\n  for(auto &[x, y, w]\
    \ : pt)\n    cin >> x >> y >> w;\n  vector<array<int, 4>> query;\n  vector<int>\
    \ updT(n);\n  while(q--) {\n    int t; cin >> t;\n    if (t == 0) {\n      int\
    \ x, y, w; cin >> x >> y >> w;\n      updT.emplace_back(ssize(query));\n     \
    \ pt.emplace_back(x, y, w);\n    } else if (t == 1) {\n      int l, r, d, u; cin\
    \ >> l >> d >> r >> u;\n      query.push_back({l, r, d, u});\n    }\n  }\n\n \
    \ for(ll x : pointAddRectSum<int, ll>(pt, query, updT))\n    cout << x << '\\\
    n';\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/fenwick_tree_2D.cpp
  - misc/compression.cpp
  - ds_problem/pointAddRectangleSum.cpp
  isVerificationFile: true
  path: test/point_add_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2026-09-03 10:52:15+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/point_add_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/point_add_rectangle_sum.test.cpp
- /verify/test/point_add_rectangle_sum.test.cpp.html
title: test/point_add_rectangle_sum.test.cpp
---
