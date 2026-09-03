---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: ds/fenwick_tree.cpp
    title: ds/fenwick_tree.cpp
  - icon: ':question:'
    path: ds/hash_table.cpp
    title: ds/hash_table.cpp
  - icon: ':question:'
    path: tree/centroid_tree.cpp
    title: tree/centroid_tree.cpp
  - icon: ':question:'
    path: tree/tree.cpp
    title: tree/tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree
    links:
    - https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree
  bundledCode: "#line 1 \"test/vertex_get_range_contour_add_on_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree\"\
    \n\n#include <bits/extc++.h>\n#line 2 \"default/t.cpp\"\nusing namespace std;\n\
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
    \ namespace sieve_of_Eratosthenes;\n#line 1 \"ds/hash_table.cpp\"\n//source: https://codeforces.com/blog/entry/62393\n\
    //#ifndef DEBUG\n//#include<ext/pb_ds/assoc_container.hpp>\n//#include<ext/pb_ds/tree_policy.hpp>\n\
    //#endif\n\nstruct custom_hash {\n    static uint64_t splitmix64(uint64_t x) {\n\
    \        x += 0x9e3779b97f4a7c15;\n        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n\
    \    }\n\n    size_t operator()(uint64_t x) const {\n        static const uint64_t\
    \ FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n   \
    \     return splitmix64(x + FIXED_RANDOM);\n    }\n};\n\nusing namespace __gnu_pbds;\n\
    \n//gp_hash_table<ll, ll, custom_hash> m({}, {}, {}, {}, {1 << 16});\n\n#ifdef\
    \ DEBUG\nusing hash_table = unordered_map<ll, ll>;\n#else\nusing hash_table =\
    \ gp_hash_table<ll, ll, custom_hash>;\n#endif\n#line 1 \"ds/fenwick_tree.cpp\"\
    \ntemplate<class T>\nstruct fenwick_tree {\n  const int size;\n  vector<T> data;\n\
    \n  fenwick_tree(int _size) : size(_size + 1), data(_size + 1) {}\n  fenwick_tree(vector<T>\
    \ init) : size(ssize(init) + 1), data(ssize(init) + 1) {\n    partial_sum(init.begin(),\
    \ init.end(), data.begin() + 1);\n    for(int i = size - 1; i > 0; i--)\n    \
    \  data[i] -= data[i - (i & (-i))];\n  }\n\n  void add(int i, T d) {\n    for(i\
    \ += 1; i < size; i += i & (-i))\n      data[i] += d;\n  }\n\n  T query(int i)\
    \ {\n    T res = T(0);\n    for(i += 1; i > 0; i -= i & (-i))\n      res += data[i];\n\
    \    return res;\n  }\n\n  T query(int l, int r) { //query [l, r)\n    return\
    \ query(r - 1) - query(l - 1);\n  }\n};\n#line 1 \"tree/tree.cpp\"\nclass tree\
    \ {\n  using i32 = int32_t;\n\n  vc<i32> ord;\n\n  public:\n\n  int n, root;\n\
    \  vc<int> p, sz, dep, jp;\n\n  tree(vc<pii> e, int _root = 0) : n(size(e) + 1),\
    \ root(_root) {\n    vc<i32> d(n), adj(n);\n    for(auto [u, v] : e)\n      d[u]++,\
    \ d[v]++, adj[u] ^= v, adj[v] ^= u;\n    d[root] = 0;\n    calc(d, adj);\n  }\n\
    \n  tree(vi pa) : n(size(pa)) {\n    root = ranges::find(pa, -1) - pa.begin();\n\
    \    vc<i32> d(n), adj(n);\n    for(int v = 0; v < n; v++)\n      if (pa[v] !=\
    \ -1)\n        d[v]++, d[pa[v]]++, adj[v] ^= pa[v], adj[pa[v]] ^= v;\n    d[root]\
    \ = 0;\n    calc(d, adj);\n  }\n\n  void calc(vc<i32> d, vc<i32> adj) {\n    sz\
    \ = vi(n, 1);\n    p = dep = jp = vi(n);\n\n    ord.reserve(n - 1);\n    for(int\
    \ i = 0; i < n; i++) {\n      int v = i;\n      while(d[v] == 1) {\n        ord.emplace_back(v);\n\
    \        p[v] = adj[v], sz[p[v]] += sz[v];\n        d[v] = 0, d[p[v]]--, adj[p[v]]\
    \ ^= v;\n        v = p[v];\n      }\n    }\n\n    assert(ssize(ord) == n - 1);\n\
    \n    p[root] = jp[root] = root;\n    for(i32 v : ord | views::reverse) {\n  \
    \    dep[v] = dep[p[v]] + 1;\n      if (dep[p[v]] + dep[jp[jp[p[v]]]] == 2 * dep[jp[p[v]]])\n\
    \        jp[v] = jp[jp[p[v]]];\n      else\n        jp[v] = p[v];\n    }\n  }\n\
    \n  int jump(int v, int k) {\n    k = min(k, dep[v]);\n    while(k) {\n      if\
    \ (int d = dep[v] - dep[jp[v]]; d <= k)\n        v = jp[v], k -= d;\n      else\n\
    \        v = p[v], k -= 1;\n    }\n    return v;\n  }\n\n  int lca(int u, int\
    \ v) {\n    if (dep[u] < dep[v])\n      swap(u, v);\n    u = jump(u, dep[u] -\
    \ dep[v]);\n    if (u == v) return u;\n    while(p[u] != p[v]) {\n      if (jp[u]\
    \ != jp[v]) u = jp[u], v = jp[v];\n      else u = p[u], v = p[v];\n    }\n   \
    \ return p[u];\n  }\n\n  int kth(int s, int t, int k) {\n    int m = lca(s, t);\n\
    \    if (dep[s] + dep[t] - 2 * dep[m] < k)\n      return -1;\n    else if (dep[s]\
    \ - dep[m] >= k)\n      return jump(s, k);\n    else\n      return jump(t, dep[s]\
    \ + dep[t] - 2 * dep[m] - k);\n  }\n\n  int dis(int u, int v) {\n    return dep[u]\
    \ + dep[v] - 2 * dep[lca(u, v)];\n  }\n\n  int median(int u, int v, int w) {\n\
    \    return lca(u, v) ^ lca(u, w) ^ lca(v, w);\n  }\n\n  auto centroid() {\n \
    \   array<int, 2> r = {-1, -1};\n    vector<bool> ok(n, true);\n    for(int v\
    \ = 0; v < n; v++) {\n      if (2 * (n - sz[v]) > n)\n        ok[v] = false;\n\
    \      if (v != root and 2 * sz[v] > n)\n        ok[p[v]] = false;\n    }\n  \
    \  for(int v = 0; v < n; v++)\n      if (ok[v])\n        r[1] = v, swap(r[0],\
    \ r[1]);\n    return r;\n  }\n};\n#line 1 \"tree/centroid_tree.cpp\"\nauto centroid_tree(vvi\
    \ &g) {\n  int n = ssize(g);\n  vvi tr(n);\n  vi sz(n);\n  vc<bool> block(n, false);\n\
    \n  auto calc = [&](int v, int p, auto &self) -> void {\n    sz[v] = 1;\n    for(int\
    \ x : g[v]) {\n      if (x == p or block[x]) continue;\n      self(x, v, self);\n\
    \      sz[v] += sz[x];\n    }\n  };\n\n  auto dfs = [&](int v, auto &self) ->\
    \ int {\n    calc(v, -1, calc);\n\n    int c = v, p = -1;\n    bool move;\n  \
    \  do {\n      move = false;\n      for(int x : g[c]) {\n        if (x == p or\
    \ block[x] or 2 * sz[x] <= sz[v]) continue;\n        move = true, p = c, c = x;\n\
    \        break;\n      }\n    } while(move);\n\n    block[c] = true;\n    for(int\
    \ x : g[c]) {\n      if (block[x]) continue;\n      x = self(x, self);\n     \
    \ tr[c].emplace_back(x);\n      tr[x].emplace_back(c);\n    }\n\n    return c;\n\
    \  };\n\n  int root = dfs(0, dfs);\n\n  return pair(tr, root);\n}\n#line 9 \"\
    test/vertex_get_range_contour_add_on_tree.test.cpp\"\n\nint main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<int> a(n);\n  for(int\
    \ &x : a)\n    cin >> x;\n  vector<pii> e(n - 1);\n  for(auto &[u, v] : e)\n \
    \   cin >> u >> v;\n  vector<vector<int>> g(n);\n  for(auto [u, v] : e) {\n  \
    \  g[u].emplace_back(v);\n    g[v].emplace_back(u);\n  }\n\n  auto [g2, r] = centroid_tree(g);\n\
    \n  vector<int> p(n, -1);\n  auto dfs = [&](int v, auto self) -> void {\n    for(int\
    \ x : g2[v]) {\n      if (x == p[v]) continue;\n      p[x] = v;\n      self(x,\
    \ self);\n    }\n  };\n  dfs(r, dfs);\n\n  gp_hash_table<ll, int, custom_hash>\
    \ toId({}, {}, {}, {}, {1 << 19});\n  vector<vector<array<int, 2>>> cand(2 * n);\n\
    \  vector<int> base(2 * n);\n  vector<ll> init;\n  init.reserve(1 << 19);\n  ::tree\
    \ tr(e);\n  for(int s = 0; s < n; s++) {\n    auto dfs = [&](int v, auto self)\
    \ -> void {\n      cand[s].push_back({tr.dis(s, v), v});\n      if (p[s] != -1)\n\
    \        cand[s + n].push_back({tr.dis(p[s], v), v});\n      for(int x : g2[v])\
    \ {\n        if (x == p[v]) continue;\n        self(x, self);\n      }\n    };\n\
    \    dfs(s, dfs);\n    for(int d : {0, n}) {\n      base[s + d] = ssize(init);\n\
    \      ranges::sort(cand[s + d]);\n      for(auto [_, v] : cand[s + d]) {\n  \
    \      toId[(ll)v << 32 | (s + d)] = ssize(init);\n        init.emplace_back(a[v]);\n\
    \      }\n    }\n  }\n\n  adjacent_difference(init.begin(), init.end(), init.begin());\n\
    \  fenwick_tree<ll> ft(init);\n  auto modify = [&](int v, int l, int r, int d)\
    \ {\n    int ql = base[v] + (ranges::lower_bound(cand[v], array<int, 2>{l, -1})\
    \ - cand[v].begin());\n    int qr = base[v] + (ranges::lower_bound(cand[v], array<int,\
    \ 2>{r, -1}) - cand[v].begin());\n    ft.add(ql, d), ft.add(qr, -d);\n  };\n\n\
    \  while(q--) {\n    int op; cin >> op;\n    if (op == 0) {\n      int x, l, r,\
    \ d; cin >> x >> l >> r >> d;\n      int v = x, pv = -1;\n      while(v != -1)\
    \ {\n        int di = tr.dis(v, x);\n        modify(v, l - di, r - di, d);\n \
    \       if (pv != -1) {\n          modify(pv + n, l - di, r - di, d);\n      \
    \  }\n        pv = v, v = p[v];\n      }\n    } else {\n      int x; cin >> x;\n\
    \      int v = x, pv = -1;\n      ll ans = 0;\n      while(v != -1) {\n      \
    \  ans += ft.query(toId[(ll)x << 32 | v]);\n        if (pv != -1)\n          ans\
    \ -= ft.query(toId[(ll)x << 32 | (pv + n)]);\n        pv = v, v = p[v];\n    \
    \  }\n      cout << ans << '\\n';\n    }\n  }\n\n  return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree\"\
    \n\n#include <bits/extc++.h>\n#include \"../default/t.cpp\"\n#include \"../ds/hash_table.cpp\"\
    \n#include \"../ds/fenwick_tree.cpp\"\n#include \"../tree/tree.cpp\"\n#include\
    \ \"../tree/centroid_tree.cpp\"\n\nint main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<int> a(n);\n  for(int\
    \ &x : a)\n    cin >> x;\n  vector<pii> e(n - 1);\n  for(auto &[u, v] : e)\n \
    \   cin >> u >> v;\n  vector<vector<int>> g(n);\n  for(auto [u, v] : e) {\n  \
    \  g[u].emplace_back(v);\n    g[v].emplace_back(u);\n  }\n\n  auto [g2, r] = centroid_tree(g);\n\
    \n  vector<int> p(n, -1);\n  auto dfs = [&](int v, auto self) -> void {\n    for(int\
    \ x : g2[v]) {\n      if (x == p[v]) continue;\n      p[x] = v;\n      self(x,\
    \ self);\n    }\n  };\n  dfs(r, dfs);\n\n  gp_hash_table<ll, int, custom_hash>\
    \ toId({}, {}, {}, {}, {1 << 19});\n  vector<vector<array<int, 2>>> cand(2 * n);\n\
    \  vector<int> base(2 * n);\n  vector<ll> init;\n  init.reserve(1 << 19);\n  ::tree\
    \ tr(e);\n  for(int s = 0; s < n; s++) {\n    auto dfs = [&](int v, auto self)\
    \ -> void {\n      cand[s].push_back({tr.dis(s, v), v});\n      if (p[s] != -1)\n\
    \        cand[s + n].push_back({tr.dis(p[s], v), v});\n      for(int x : g2[v])\
    \ {\n        if (x == p[v]) continue;\n        self(x, self);\n      }\n    };\n\
    \    dfs(s, dfs);\n    for(int d : {0, n}) {\n      base[s + d] = ssize(init);\n\
    \      ranges::sort(cand[s + d]);\n      for(auto [_, v] : cand[s + d]) {\n  \
    \      toId[(ll)v << 32 | (s + d)] = ssize(init);\n        init.emplace_back(a[v]);\n\
    \      }\n    }\n  }\n\n  adjacent_difference(init.begin(), init.end(), init.begin());\n\
    \  fenwick_tree<ll> ft(init);\n  auto modify = [&](int v, int l, int r, int d)\
    \ {\n    int ql = base[v] + (ranges::lower_bound(cand[v], array<int, 2>{l, -1})\
    \ - cand[v].begin());\n    int qr = base[v] + (ranges::lower_bound(cand[v], array<int,\
    \ 2>{r, -1}) - cand[v].begin());\n    ft.add(ql, d), ft.add(qr, -d);\n  };\n\n\
    \  while(q--) {\n    int op; cin >> op;\n    if (op == 0) {\n      int x, l, r,\
    \ d; cin >> x >> l >> r >> d;\n      int v = x, pv = -1;\n      while(v != -1)\
    \ {\n        int di = tr.dis(v, x);\n        modify(v, l - di, r - di, d);\n \
    \       if (pv != -1) {\n          modify(pv + n, l - di, r - di, d);\n      \
    \  }\n        pv = v, v = p[v];\n      }\n    } else {\n      int x; cin >> x;\n\
    \      int v = x, pv = -1;\n      ll ans = 0;\n      while(v != -1) {\n      \
    \  ans += ft.query(toId[(ll)x << 32 | v]);\n        if (pv != -1)\n          ans\
    \ -= ft.query(toId[(ll)x << 32 | (pv + n)]);\n        pv = v, v = p[v];\n    \
    \  }\n      cout << ans << '\\n';\n    }\n  }\n\n  return 0;\n}\n\n"
  dependsOn:
  - default/t.cpp
  - ds/hash_table.cpp
  - ds/fenwick_tree.cpp
  - tree/tree.cpp
  - tree/centroid_tree.cpp
  isVerificationFile: true
  path: test/vertex_get_range_contour_add_on_tree.test.cpp
  requiredBy: []
  timestamp: '2026-09-03 11:20:30+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/vertex_get_range_contour_add_on_tree.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_get_range_contour_add_on_tree.test.cpp
- /verify/test/vertex_get_range_contour_add_on_tree.test.cpp.html
title: test/vertex_get_range_contour_add_on_tree.test.cpp
---
