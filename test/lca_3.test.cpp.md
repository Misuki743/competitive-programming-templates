---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/RMQ.cpp
    title: ds/RMQ.cpp
  - icon: ':heavy_check_mark:'
    path: tree/LCA.cpp
    title: tree/LCA.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/lca_3.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
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
    \ namespace sieve_of_Eratosthenes;\n#line 1 \"ds/RMQ.cpp\"\ntemplate<class T>\n\
    struct RMQ {\n  uint64_t size;\n  vector<T> base;\n  vector<vector<T>> table;\n\
    \  vector<uint32_t> msk;\n\n  static const int lgw = 5;\n  static const int w\
    \ = 1 << lgw;\n  RMQ(vector<T> _base) : size(ssize(_base)), base(_base), msk(size)\
    \ {\n    msk.back() = 1;\n    for(int i = size - 2; i >= 0; i--) {\n      msk[i]\
    \ = msk[i + 1] << 1;\n      while(msk[i] != 0 and base[i + countr_zero(msk[i])]\
    \ >= base[i])\n        msk[i] ^= 1u << countr_zero(msk[i]);\n      msk[i] |= 1u;\n\
    \    }\n\n    table = vector(bit_width(size >> lgw), vector<T>(size >> lgw));\n\
    \    if (!table.empty())\n      for(uint64_t i = 0; i + w <= size; i += w)\n \
    \       table[0][i >> lgw] = base[i + bit_width(msk[i]) - 1];\n    for(int i =\
    \ 1; i < ssize(table); i++)\n      for(uint64_t j = 0; j < (size >> lgw); j++)\n\
    \        if (j + (1 << (i - 1)) < (size >> lgw))\n          table[i][j] = min(table[i\
    \ - 1][j], table[i - 1][j + (1 << (i - 1))]);\n        else\n          table[i][j]\
    \ = table[i - 1][j];\n  }\n\n  T query(int l, int r) {\n    if (l >= r) {\n  \
    \    return numeric_limits<T>::max();\n    } else if (r - l <= w) {\n      return\
    \ base[l + bit_width(msk[l] & (~0u >> (w - (r - l)))) - 1];\n    } else {\n  \
    \    T ret = min(query(l, l + w), query(r - w, r));\n      l = (l + w) >> lgw,\
    \ r >>= lgw;\n      if (l == r) return ret;\n      int range = bit_width((unsigned)(r\
    \ - l)) - 1;\n      return min({ret, table[range][l], table[range][r - (1 << range)]});\n\
    \    }\n  }\n};\n#line 1 \"tree/LCA.cpp\"\n//#include \"ds/RMQ.cpp\"\n\nstruct\
    \ LCA {\n  vi dep, tin, tout, mp;\n  RMQ<int> rmq;\n\n  LCA(vc<pii> e, int root\
    \ = 0) : rmq(precomp(e, root)) {}\n\n  vi precomp(vc<pii> &e, int root) {\n  \
    \  const int n = ssize(e) + 1;\n\n    dep = tin = tout = mp = vi(n);\n\n    vi\
    \ sz(n, 1), p(n), ord;\n    {\n      vi d(n);\n      for(auto &[u, v] : e)\n \
    \       p[u] ^= v, p[v] ^= u, d[u]++, d[v]++;\n\n      d[root] = 0;\n      ord.reserve(n\
    \ - 1);\n      for(int i = 0; i < n; i++) {\n        int v = i;\n        while(d[v]\
    \ == 1) {\n          ord.emplace_back(v);\n          sz[p[v]] += sz[v];\n    \
    \      d[v] = 0, d[p[v]]--, p[p[v]] ^= v;\n          v = p[v];\n        }\n  \
    \    }\n      p[root] = root;\n    }\n\n    vi dfn(n);\n    {\n      vi nxt(n,\
    \ 1);\n      for(int v : ord | views::reverse) {\n        dfn[v] = nxt[p[v]],\
    \ nxt[p[v]] += sz[v];\n        nxt[v] = dfn[v] + 1;\n        dep[v] = dep[p[v]]\
    \ + 1;\n      }\n      vi().swap(ord);\n      vi().swap(sz);\n    }\n\n    vi\
    \ init(2 * n - 1);\n    {\n      vi dfn_ord = inv_perm(std::move(dfn));\n\n  \
    \    int nxt = 0, pre = root;\n      for(int v : dfn_ord) {\n        while(pre\
    \ != p[v]) {\n          pre = p[pre], tout[pre] = nxt;\n          init[nxt++]\
    \ = pre;\n        }\n        tin[v] = tout[v] = nxt;\n        init[nxt++] = pre\
    \ = v;\n      }\n\n      while(pre != root) {\n        pre = p[pre], tout[pre]\
    \ = nxt;\n        init[nxt++] = pre;\n      }\n    }\n\n    {\n      vi f(n);\n\
    \      for(int x : dep) f[x]++;\n      psum(f);\n\n      vi rank(n);\n      for(int\
    \ v = 0; v < n; v++) {\n        rank[v] = --f[dep[v]];\n        mp[rank[v]] =\
    \ v;\n      }\n      for(int &v : init) v = rank[v];\n    }\n\n    return init;\n\
    \  }\n\n  int lca(int u, int v) {\n    if (tin[u] > tin[v]) swap(u, v);\n    return\
    \ mp[rmq.query(tin[u], tout[v] + 1)];\n  }\n\n  int dis(int u, int v) {\n    return\
    \ dep[u] + dep[v] - 2 * dep[lca(u, v)];\n  }\n\n  bool is_ancestor_of(int u, int\
    \ v) {\n    return tin[u] <= tin[v] and tout[v] <= tout[u];\n  }\n};\n#line 6\
    \ \"test/lca_3.test.cpp\"\n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\
    \n  int n, q; cin >> n >> q;\n  vc<pii> e(n - 1);\n  for(int v = 1; auto &[x,\
    \ y] : e) {\n    x = v++;\n    cin >> y;\n  }\n\n  LCA lc(e, 0);\n\n  while(q--)\
    \ {\n    int u, v; cin >> u >> v;\n    cout << lc.lca(u, v) << '\\n';\n  }\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../default/t.cpp\"\
    \n#include \"../ds/RMQ.cpp\"\n#include \"../tree/LCA.cpp\"\n\nint main() {\n \
    \ ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n\
    \  vc<pii> e(n - 1);\n  for(int v = 1; auto &[x, y] : e) {\n    x = v++;\n   \
    \ cin >> y;\n  }\n\n  LCA lc(e, 0);\n\n  while(q--) {\n    int u, v; cin >> u\
    \ >> v;\n    cout << lc.lca(u, v) << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/RMQ.cpp
  - tree/LCA.cpp
  isVerificationFile: true
  path: test/lca_3.test.cpp
  requiredBy: []
  timestamp: '2026-09-03 11:20:30+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/lca_3.test.cpp
layout: document
redirect_from:
- /verify/test/lca_3.test.cpp
- /verify/test/lca_3.test.cpp.html
title: test/lca_3.test.cpp
---
