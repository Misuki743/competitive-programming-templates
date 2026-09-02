---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: enumerate/enumerate_bit.cpp
    title: enumerate/enumerate_bit.cpp
  - icon: ':heavy_check_mark:'
    path: enumerate/enumerate_label_tree.cpp
    title: enumerate/enumerate_label_tree.cpp
  - icon: ':heavy_check_mark:'
    path: enumerate/enumerate_twelvefold.cpp
    title: enumerate/enumerate_twelvefold.cpp
  - icon: ':heavy_check_mark:'
    path: enumerate/enumerate_unlabel_rooted_tree.cpp
    title: enumerate/enumerate_unlabel_rooted_tree.cpp
  - icon: ':heavy_check_mark:'
    path: tree/prufer_recover.cpp
    title: tree/prufer_recover.cpp
  - icon: ':heavy_check_mark:'
    path: tree/tree.cpp
    title: tree/tree.cpp
  - icon: ':heavy_check_mark:'
    path: tree/tree_diameter.cpp
    title: tree/tree_diameter.cpp
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
  bundledCode: "#line 1 \"test/mytest_tree_diameter.test.cpp\"\n#define PROBLEM \"\
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
    \ algorithm_extend;\n#line 1 \"tree/prufer_recover.cpp\"\n//empty vector would\
    \ be assumed to be n = 2\nvc<pii> prufer_recover(vi prufer_code) {\n  const int\
    \ n = ssize(prufer_code) + 2;\n  assert(prufer_code.empty() or (ranges::min(prufer_code)\
    \ >= 0 and ranges::max(prufer_code) < n));\n  vi d(n, 1);\n  for(int x : prufer_code)\
    \ d[x]++;\n  min_heap<int> leaf;\n  for(int v = 0; v < n; v++)\n    if (d[v] ==\
    \ 1)\n      leaf.emplace(v);\n  vc<pii> edges;\n  for(int x : prufer_code) {\n\
    \    int v = leaf.top(); leaf.pop();\n    edges.emplace_back(v, x);\n    if (--d[x]\
    \ == 1)\n      leaf.emplace(x);\n  }\n  int v = leaf.top(); leaf.pop();\n  edges.emplace_back(v,\
    \ leaf.top());\n  return edges;\n}\n#line 1 \"enumerate/enumerate_bit.cpp\"\n\n\
    template<typename F, typename INT>\nrequires invocable<F, INT>\nvoid enumerate_subset(INT\
    \ msk, F f) {\n  for(INT x = msk; x > 0; x = (x - 1) & msk)\n    f(x);\n  f(0);\n\
    }\n#line 1 \"enumerate/enumerate_twelvefold.cpp\"\n//#include \"enumerate/bit.cpp\"\
    \n\n//n^k\ntemplate<typename F>\nrequires invocable<F, vector<int>>\nvoid enumerate_cartesian_power(int\
    \ n, int k, F f) {\n  assert(min(n, k) >= 0);\n  vector<int> p(k);\n  auto dfs\
    \ = [&](int i, auto &self) -> void {\n    if (i == k) {\n      f(p);\n    } else\
    \ {\n      for(int x = 0; x < n; x++) {\n        p[i] = x;\n        self(i + 1,\
    \ self);\n      }\n    }\n  };\n  dfs(0, dfs);\n}\n\n//factorial:\n//[1, 2, 6,\
    \ 24, 120,\n// 720, 5040, 40320, 362880, 3628800,\n// 39916800, 479001600, 6227020800,\
    \ 87178291200, 1307674368000]\ntemplate<typename F>\nrequires invocable<F, vector<int>>\n\
    void enumerate_permutation(int n, F f) {\n  assert(n >= 0);\n  vector<int> p(n);\n\
    \  iota(p.begin(), p.end(), 0);\n  do { f(p); } while(next_permutation(p.begin(),\
    \ p.end()));\n}\n\n//binom(n, k)\ntemplate<typename F>\nrequires invocable<F,\
    \ vector<int>>\nvoid enumerate_combination(int n, int k, F f) {\n  assert(min(n,\
    \ k) >= 0);\n  vector<int> p;\n  auto dfs = [&](auto &self) -> void {\n    if\
    \ (ssize(p) == k) {\n      f(p);\n    } else {\n      for(int x = (p.empty() ?\
    \ 0 : p.back() + 1); x + k - ssize(p) <= n; x++) {\n        p.emplace_back(x);\n\
    \        self(self);\n        p.pop_back();\n      }\n    }\n  };\n  dfs(dfs);\n\
    }\n\n//Bell's number:\n//[1, 2, 5, 15, 52,\n// 203, 877, 4140, 21147, 115975,\n\
    // 678570, 4213597, 27644437, 190899322, 1382958545]\ntemplate<typename F>\nrequires\
    \ invocable<F, vector<int>>\nvoid enumerate_set_partition(int n, F f) {\n  assert(n\
    \ >= 0);\n  vector<int> p;\n  int msk = (1 << n) - 1;\n  auto dfs = [&](auto &self)\
    \ -> void {\n    if (msk == 0) {\n      f(p);\n    } else {\n      int x = msk\
    \ & (-msk);\n      msk ^= x;\n      enumerate_subset(msk, [&](int sub) {\n   \
    \     p.emplace_back(sub | x);\n        msk ^= sub;\n        self(self);\n   \
    \     msk ^= sub;\n        p.pop_back();\n      });\n      msk ^= x;\n    }\n\
    \  };\n  dfs(dfs);\n}\n\n//f[0] + f[1] + ... + f[n - 1] = sum, f[i] >= 0\n//binom(sum\
    \ + (n - 1), sum)\ntemplate<typename F>\nrequires invocable<F, vector<int>>\n\
    void enumerate_multisubset(int n, int sum, F f) {\n  assert(min(n, sum) >= 0);\n\
    \  vector<int> p(n);\n  auto dfs = [&](int i, auto &self) -> void {\n    if (i\
    \ == n) {\n      if (sum == 0) f(p);\n    } else {\n      for(int x = sum; x >=\
    \ 0; x--) {\n        p[i] = x, sum -= x;\n        self(i + 1, self);\n       \
    \ sum += x;\n      }\n    }\n  };\n  dfs(0, dfs);\n}\n\n//partition number:\n\
    //n = 10: 42\n//n = 20: 627\n//n = 30: 5604\n//n = 40: 37338\n//n = 50: 204226\n\
    //n = 60: 966467\n//n = 70: 4087968\n//n = 80: 15796476\n//n = 90: 56634173\n\
    //n = 100: 190569292\ntemplate<typename F>\nrequires invocable<F, vector<int>>\n\
    void enumerate_integer_partition(int n, F f) {\n  assert(n >= 0);\n  vector<int>\
    \ p;\n  auto dfs = [&](int s, auto &self) -> void {\n    if (s == 0) {\n     \
    \ f(p);\n    } else {\n      for(int x = (p.empty() ? s : min(p.back(), s)); x\
    \ > 0; x--) {\n        p.emplace_back(x);\n        self(s - x, self);\n      \
    \  p.pop_back();\n      }\n    }\n  };\n  dfs(n, dfs);\n}\n#line 1 \"enumerate/enumerate_label_tree.cpp\"\
    \n//#include \"tree/prufer_recover.cpp\"\n//#include \"enumerate/enumerate_bit.cpp\"\
    \n//#include \"enumerate/enumerate_twelvefold.cpp\"\n\ntemplate<typename F>\n\
    requires invocable<F, vector<vector<int>>>\nvoid enumerate_label_tree(int n, F\
    \ f) {\n  assert(n > 0);\n  if (n == 1) {\n    f(vector<vector<int>>(1));\n  }\
    \ else {\n    enumerate_cartesian_power(n, n - 2, [n, f](vector<int> a) {\n  \
    \    vvi g(n);\n      for(auto [u, v] : prufer_recover(a))\n        g[u].eb(v),\
    \ g[v].eb(u);\n      f(g);\n    });\n  }\n}\n#line 1 \"enumerate/enumerate_unlabel_rooted_tree.cpp\"\
    \n//number of unlabel rooted tree (1-based)\n//1, 1, 2, 4, 9,\n//20, 48, 115,\
    \ 286, 719,\n//1842, 4766, 12486, 32973, 87811,\n//235381, 634847, 1721159, 4688676,\
    \ 12826228,\n//35221832, 97055181, 268282855, 743724984, 2067174645\n\n//root\
    \ is 0\ntemplate<typename F>\nrequires invocable<F, vector<vector<int>>>\nvoid\
    \ enumerate_unlabel_rooted_tree(int n, F f) {\n  const int LIM = 25;\n  assert(0\
    \ < n and n <= LIM);\n\n  vector hash(1, array<int, LIM>{-1});\n  array<int, LIM\
    \ + 2> st;\n  fill(st.begin(), st.end(), INT_MAX);\n  st[0] = -1, st[1] = 0;\n\
    \n  auto size = [&](int id) {\n    int r = 1;\n    while(st[r] <= id) r++;\n \
    \   return r - 1;\n  };\n\n  for(int m = 2; m <= n; m++) {\n    st[m] = ssize(hash);\n\
    \    array<int, LIM> h;\n    int nxt = 0;\n    auto dfs = [&](int pre_id, int\
    \ sum, auto &self) -> void {\n      if (sum == 0) {\n        h[nxt++] = -1;\n\
    \        hash.emplace_back(h);\n        nxt--;\n      } else {\n        for(int\
    \ x = min(pre_id, st[sum + 1] - 1); x >= 0; x--) {\n          h[nxt++] = x;\n\
    \          self(x, sum - size(x), self);\n          nxt--;\n        }\n      }\n\
    \    };\n    dfs(INT_MAX, m - 1, dfs);\n  }\n  st[n + 1] = ssize(hash);\n\n  for(int\
    \ id = st[n]; id < st[n + 1]; id++) {\n    vector<vector<int>> g(n);\n    int\
    \ nxt = 0;\n    auto dfs = [&](int v, int id, auto &self) -> void {\n      if\
    \ (id == 0) return;\n      for(int i = 0; hash[id][i] != -1; i++) {\n        g[v].emplace_back(nxt),\
    \ g[nxt].emplace_back(v);\n        self(nxt++, hash[id][i], self);\n      }\n\
    \    };\n    dfs(nxt++, id, dfs);\n    f(g);\n  }\n}\n#line 1 \"tree/tree.cpp\"\
    \nclass tree {\n  using i32 = int32_t;\n\n  vc<i32> ord;\n\n  public:\n\n  int\
    \ n, root;\n  vc<int> p, sz, dep, jp;\n\n  tree(vc<pii> e, int _root = 0) : n(size(e)\
    \ + 1), root(_root) {\n    vc<i32> d(n), adj(n);\n    for(auto [u, v] : e)\n \
    \     d[u]++, d[v]++, adj[u] ^= v, adj[v] ^= u;\n    d[root] = 0;\n    calc(d,\
    \ adj);\n  }\n\n  tree(vi pa) : n(size(pa)) {\n    root = ranges::find(pa, -1)\
    \ - pa.begin();\n    vc<i32> d(n), adj(n);\n    for(int v = 0; v < n; v++)\n \
    \     if (pa[v] != -1)\n        d[v]++, d[pa[v]]++, adj[v] ^= pa[v], adj[pa[v]]\
    \ ^= v;\n    d[root] = 0;\n    calc(d, adj);\n  }\n\n  void calc(vc<i32> d, vc<i32>\
    \ adj) {\n    sz = vi(n, 1);\n    p = dep = jp = vi(n);\n\n    ord.reserve(n -\
    \ 1);\n    for(int i = 0; i < n; i++) {\n      int v = i;\n      while(d[v] ==\
    \ 1) {\n        ord.emplace_back(v);\n        p[v] = adj[v], sz[p[v]] += sz[v];\n\
    \        d[v] = 0, d[p[v]]--, adj[p[v]] ^= v;\n        v = p[v];\n      }\n  \
    \  }\n\n    assert(ssize(ord) == n - 1);\n\n    p[root] = jp[root] = root;\n \
    \   for(i32 v : ord | views::reverse) {\n      dep[v] = dep[p[v]] + 1;\n     \
    \ if (dep[p[v]] + dep[jp[jp[p[v]]]] == 2 * dep[jp[p[v]]])\n        jp[v] = jp[jp[p[v]]];\n\
    \      else\n        jp[v] = p[v];\n    }\n  }\n\n  int jump(int v, int k) {\n\
    \    k = min(k, dep[v]);\n    while(k) {\n      if (int d = dep[v] - dep[jp[v]];\
    \ d <= k)\n        v = jp[v], k -= d;\n      else\n        v = p[v], k -= 1;\n\
    \    }\n    return v;\n  }\n\n  int lca(int u, int v) {\n    if (dep[u] < dep[v])\n\
    \      swap(u, v);\n    u = jump(u, dep[u] - dep[v]);\n    if (u == v) return\
    \ u;\n    while(p[u] != p[v]) {\n      if (jp[u] != jp[v]) u = jp[u], v = jp[v];\n\
    \      else u = p[u], v = p[v];\n    }\n    return p[u];\n  }\n\n  int kth(int\
    \ s, int t, int k) {\n    int m = lca(s, t);\n    if (dep[s] + dep[t] - 2 * dep[m]\
    \ < k)\n      return -1;\n    else if (dep[s] - dep[m] >= k)\n      return jump(s,\
    \ k);\n    else\n      return jump(t, dep[s] + dep[t] - 2 * dep[m] - k);\n  }\n\
    \n  int dis(int u, int v) {\n    return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n\
    \  }\n\n  int median(int u, int v, int w) {\n    return lca(u, v) ^ lca(u, w)\
    \ ^ lca(v, w);\n  }\n\n  auto centroid() {\n    array<int, 2> r = {-1, -1};\n\
    \    vector<bool> ok(n, true);\n    for(int v = 0; v < n; v++) {\n      if (2\
    \ * (n - sz[v]) > n)\n        ok[v] = false;\n      if (v != root and 2 * sz[v]\
    \ > n)\n        ok[p[v]] = false;\n    }\n    for(int v = 0; v < n; v++)\n   \
    \   if (ok[v])\n        r[1] = v, swap(r[0], r[1]);\n    return r;\n  }\n};\n\
    #line 1 \"tree/tree_diameter.cpp\"\n//#include \"graph/tree.cpp\"\n\nauto tree_diameter(vc<pii>\
    \ e) {\n  auto d0 = tree(e).dep;\n  int u = max_element(d0.begin(), d0.end())\
    \ - d0.begin();\n  tree t(e, u);\n  int v = max_element(t.dep.begin(), t.dep.end())\
    \ - t.dep.begin();\n  vi path = {v};\n  for(int i = t.dep[v]; i > 0; i--)\n  \
    \  path.emplace_back(t.p[path.back()]);\n  return pair((int)(ssize(path) - 1),\
    \ path);\n}\n#line 11 \"test/mytest_tree_diameter.test.cpp\"\n\nvoid check(vector<vector<int>>\
    \ g) {\n  const int n = ssize(g);\n  vi dep;\n  auto dfs = [&](int v, int p, auto\
    \ &self) -> void {\n    for(int x : g[v]) {\n      if (x == p) continue;\n   \
    \   dep[x] = dep[v] + 1;\n      self(x, v, self);\n    }\n  };\n\n  int diameter\
    \ = -1;\n  for(int r = 0; r < n; r++) {\n    vi(n, INT_MAX).swap(dep);\n    dep[r]\
    \ = 0;\n    dfs(r, -1, dfs);\n    chmax(diameter, ranges::max(dep));\n  }\n\n\
    \  vc<pii> e;\n  for(int u = 0; u < n; u++)\n    for(int v : g[u])\n      if (u\
    \ < v)\n        e.emplace_back(u, v);\n\n  set<pii> s;\n  for(auto [u, v] : e)\n\
    \    s.emplace(u, v), s.emplace(v, u);\n\n  auto [diameter_2, path] = tree_diameter(e);\n\
    \n  assert(diameter == diameter_2);\n  assert(ssize(path) == diameter + 1);\n\
    \  for(int i = 1; i < ssize(path); i++)\n    assert(s.contains(pair(path[i - 1],\
    \ path[i])));\n  unique(path);\n  assert(ssize(path) == diameter + 1);\n}\n\n\
    auto random_relabel(vector<vector<int>> g) {\n  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \  const int n = ssize(g);\n  vector<int> p(n);\n  iota(p.begin(), p.end(), 0);\n\
    \  shuffle(p.begin(), p.end(), rng);\n  vector<vector<int>> g2(n);\n  for(int\
    \ u = 0; u < n; u++)\n    for(int v : g[u])\n      g2[p[u]].eb(p[v]);\n  return\
    \ g2;\n}\n\nvoid a_plus_b() {\n  int a, b; cin >> a >> b;\n  cout << a + b <<\
    \ '\\n';\n}\n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n\
    \  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\n  for(int\
    \ n = 1; n <= 7; n++) {\n    enumerate_label_tree(n, [&](vector<vector<int>> g)\
    \ {\n      check(g);\n    });\n  }\n\n  for(int n = 1; n <= 15; n++) {\n    enumerate_unlabel_rooted_tree(n,\
    \ [&](vector<vector<int>> g) {\n      check(g);\n      check(random_relabel(g));\n\
    \    });\n  }\n\n  //path\n  for(int n = 1; n <= 100; n++) {\n    vector<vector<int>>\
    \ g(n);\n    for(int i = 1; i < n; i++)\n      g[i].emplace_back(i - 1), g[i -\
    \ 1].emplace_back(i);\n    check(g);\n    check(random_relabel(g));\n  }\n\n \
    \ //star\n  for(int n = 2; n <= 100; n++) {\n    for(int root : {0, n / 2, n -\
    \ 1}) {\n      vector<vector<int>> g(n);\n      for(int i = 0; i < n; i++)\n \
    \       if (i != root)\n          g[root].emplace_back(i), g[i].emplace_back(root);\n\
    \      check(g);\n    }\n  }\n\n  //almost path\n  for(int tc = 0; tc < 30; tc++)\
    \ {\n    int n = 500;\n    vector<vector<int>> g(n);\n    for(int v = 1; v < n;\
    \ v++) {\n      int x = rng() % min(v, 5);\n      g[v].emplace_back(x), g[x].emplace_back(v);\n\
    \    }\n    check(g);\n    check(random_relabel(g));\n  }\n\n  a_plus_b();\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../default/t.cpp\"\n#include \"../tree/prufer_recover.cpp\"\n#include \"../enumerate/enumerate_bit.cpp\"\
    \n#include \"../enumerate/enumerate_twelvefold.cpp\"\n#include \"../enumerate/enumerate_label_tree.cpp\"\
    \n#include \"../enumerate/enumerate_unlabel_rooted_tree.cpp\"\n#include \"../tree/tree.cpp\"\
    \n#include \"../tree/tree_diameter.cpp\"\n\nvoid check(vector<vector<int>> g)\
    \ {\n  const int n = ssize(g);\n  vi dep;\n  auto dfs = [&](int v, int p, auto\
    \ &self) -> void {\n    for(int x : g[v]) {\n      if (x == p) continue;\n   \
    \   dep[x] = dep[v] + 1;\n      self(x, v, self);\n    }\n  };\n\n  int diameter\
    \ = -1;\n  for(int r = 0; r < n; r++) {\n    vi(n, INT_MAX).swap(dep);\n    dep[r]\
    \ = 0;\n    dfs(r, -1, dfs);\n    chmax(diameter, ranges::max(dep));\n  }\n\n\
    \  vc<pii> e;\n  for(int u = 0; u < n; u++)\n    for(int v : g[u])\n      if (u\
    \ < v)\n        e.emplace_back(u, v);\n\n  set<pii> s;\n  for(auto [u, v] : e)\n\
    \    s.emplace(u, v), s.emplace(v, u);\n\n  auto [diameter_2, path] = tree_diameter(e);\n\
    \n  assert(diameter == diameter_2);\n  assert(ssize(path) == diameter + 1);\n\
    \  for(int i = 1; i < ssize(path); i++)\n    assert(s.contains(pair(path[i - 1],\
    \ path[i])));\n  unique(path);\n  assert(ssize(path) == diameter + 1);\n}\n\n\
    auto random_relabel(vector<vector<int>> g) {\n  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \  const int n = ssize(g);\n  vector<int> p(n);\n  iota(p.begin(), p.end(), 0);\n\
    \  shuffle(p.begin(), p.end(), rng);\n  vector<vector<int>> g2(n);\n  for(int\
    \ u = 0; u < n; u++)\n    for(int v : g[u])\n      g2[p[u]].eb(p[v]);\n  return\
    \ g2;\n}\n\nvoid a_plus_b() {\n  int a, b; cin >> a >> b;\n  cout << a + b <<\
    \ '\\n';\n}\n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n\
    \  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\n  for(int\
    \ n = 1; n <= 7; n++) {\n    enumerate_label_tree(n, [&](vector<vector<int>> g)\
    \ {\n      check(g);\n    });\n  }\n\n  for(int n = 1; n <= 15; n++) {\n    enumerate_unlabel_rooted_tree(n,\
    \ [&](vector<vector<int>> g) {\n      check(g);\n      check(random_relabel(g));\n\
    \    });\n  }\n\n  //path\n  for(int n = 1; n <= 100; n++) {\n    vector<vector<int>>\
    \ g(n);\n    for(int i = 1; i < n; i++)\n      g[i].emplace_back(i - 1), g[i -\
    \ 1].emplace_back(i);\n    check(g);\n    check(random_relabel(g));\n  }\n\n \
    \ //star\n  for(int n = 2; n <= 100; n++) {\n    for(int root : {0, n / 2, n -\
    \ 1}) {\n      vector<vector<int>> g(n);\n      for(int i = 0; i < n; i++)\n \
    \       if (i != root)\n          g[root].emplace_back(i), g[i].emplace_back(root);\n\
    \      check(g);\n    }\n  }\n\n  //almost path\n  for(int tc = 0; tc < 30; tc++)\
    \ {\n    int n = 500;\n    vector<vector<int>> g(n);\n    for(int v = 1; v < n;\
    \ v++) {\n      int x = rng() % min(v, 5);\n      g[v].emplace_back(x), g[x].emplace_back(v);\n\
    \    }\n    check(g);\n    check(random_relabel(g));\n  }\n\n  a_plus_b();\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - tree/prufer_recover.cpp
  - enumerate/enumerate_bit.cpp
  - enumerate/enumerate_twelvefold.cpp
  - enumerate/enumerate_label_tree.cpp
  - enumerate/enumerate_unlabel_rooted_tree.cpp
  - tree/tree.cpp
  - tree/tree_diameter.cpp
  isVerificationFile: true
  path: test/mytest_tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2026-09-02 20:44:03+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest_tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/test/mytest_tree_diameter.test.cpp
- /verify/test/mytest_tree_diameter.test.cpp.html
title: test/mytest_tree_diameter.test.cpp
---
