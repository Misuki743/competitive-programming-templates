---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: ds/fenwick_tree.cpp
    title: ds/fenwick_tree.cpp
  - icon: ':x:'
    path: tree/HLD.cpp
    title: tree/HLD.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/vertex_add_path_sum.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#line 1 \"default/t.cpp\"\
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
    \ F, T, T>\n  void psum(R &v, F f) {\n    if (!ranges::empty(v))\n      for(T\
    \ p = *v.begin(); T &x : v | views::drop(1))\n        x = p = f(p, x);\n  }\n\n\
    \  template<ranges::forward_range R, class T = ranges::range_value_t<R>>\n  void\
    \ psum(R &v) {\n    if (!ranges::empty(v))\n      for(T p = *v.begin(); T &x :\
    \ v | views::drop(1))\n        x = p = p + x;\n  }\n\n  template<ranges::random_access_range\
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
    \ f;\n  }\n}\n\nusing namespace algorithm_extend;\n#line 1 \"tree/HLD.cpp\"\n\
    struct HLD {\n  int n, root;\n  vi dep, sz, p, head, tin, tout, inv_tin, child_list,\
    \ c, v_to_e;\n  vc<int32_t> lb;\n\n  inline int head_parent(int v) const { return\
    \ p[head[v]]; }\n\n  HLD(vc<pii> e, int _root = 0) : root(_root) { precompute(e);\
    \ }\n  HLD(vi _p) {\n    vc<pii> e;\n    root = -1;\n    for(int v = 0; v < ssize(_p);\
    \ v++) {\n      if (_p[v] == -1 or _p[v] == v)\n        root = v;\n      else\n\
    \        e.eb(v, _p[v]);\n    }\n    assert(root != -1);\n    precompute(e);\n\
    \  }\n\n  void precompute(vc<pii> &e) {\n    n = ssize(e) + 1;\n\n    dep = p\
    \ = head = tin = tout = v_to_e = vi(n);\n    sz = vi(n, 1);\n\n    vi mx_child_sz(n,\
    \ -1);\n    {\n      vi d(n);\n      for(auto [u, v] : e)\n        p[u] ^= v,\
    \ p[v] ^= u, d[u]++, d[v]++;\n      d[root] = 0;\n      for(int i = 0; i < n;\
    \ i++) {\n        int v = i;\n        while(d[v] == 1) {\n          d[v] = 0,\
    \ d[p[v]]--, p[p[v]] ^= v;\n          sz[p[v]] += sz[v];\n          chmax(mx_child_sz[p[v]],\
    \ sz[v]);\n          v = p[v];\n        }\n      }\n      p[root] = root;\n  \
    \  }\n\n    vi ord(n);\n    {\n      vi f(n + 2);\n      for(int x : sz) f[x +\
    \ 1]++;\n      psum(f);\n      for(int v = 0; v < n; v++)\n        ord[n - 1 -\
    \ (f[sz[v]]++)] = v;\n    }\n\n    {\n      head[root] = root, tout[root] = n;\n\
    \n      vi add(n, 1);\n      for(int v : ord | views::drop(1)) {\n        dep[v]\
    \ = dep[p[v]] + 1;\n        tin[v] = tin[p[v]] + add[p[v]];\n        add[p[v]]\
    \ += sz[v];\n        tout[v] = tin[v] + sz[v];\n        if (mx_child_sz[p[v]]\
    \ == sz[v])\n          mx_child_sz[p[v]] = 0, head[v] = head[p[v]];\n        else\n\
    \          head[v] = v;\n      }\n    }\n\n    inv_tin = inv_perm(tin);\n\n  \
    \  lb = vc<int32_t>(n + 1);\n    child_list = vi(n + 1);\n    for(int v = 0; v\
    \ < n; v++)\n      if (v != root)\n        lb[p[v]]++;\n    psum(lb);\n    for(int\
    \ v = 0; v < n; v++)\n      if (v != root and head[v] == v)\n        child_list[--lb[p[v]]]\
    \ = v;\n    for(int v = 0; v < n; v++)\n      if (v != root and head[v] != v)\n\
    \        child_list[--lb[p[v]]] = v;\n\n    v_to_e[root] = -1;\n    for(int i\
    \ = 0; auto [u, v] : e) {\n      if (dep[u] > dep[v]) swap(u, v);\n      v_to_e[v]\
    \ = i++;\n    }\n  }\n\n  auto query_path(int u, int v, bool edge = false) {\n\
    \    vc<pii> lr;\n    while(head[u] != head[v]) {\n      if (dep[head[u]] > dep[head[v]])\n\
    \        swap(u, v);\n      lr.emplace_back(tin[head[v]], tin[v] + 1);\n     \
    \ v = head_parent(v);\n    }\n\n    if (tin[u] > tin[v]) swap(u, v);\n    if (tin[u]\
    \ + edge <= tin[v])\n      lr.emplace_back(tin[u] + edge, tin[v] + 1);\n\n   \
    \ return lr;\n  }\n\n  //l < r: op(l, op(l + 1, ...))\n  //l > r: op(r - 1, op(r\
    \ - 2, ...))\n  auto query_path_non_commutative(int u, int v, bool edge = false)\
    \ {\n    vc<pii> lr1, lr2;\n    while(head[u] != head[v]) {\n      if (dep[head[u]]\
    \ > dep[head[v]]) {\n        lr1.emplace_back(tin[u] + 1, tin[head[u]]);\n   \
    \     u = head_parent(u);\n      } else {\n        lr2.emplace_back(tin[head[v]],\
    \ tin[v] + 1);\n        v = head_parent(v);\n      }\n    }\n\n    if (tin[u]\
    \ + edge <= tin[v])\n      lr2.emplace_back(tin[u] + edge, tin[v] + 1);\n    else\
    \ if (tin[v] + edge <= tin[u])\n      lr1.emplace_back(tin[u] + 1, tin[v] + edge);\n\
    \n    lr1.insert(end(lr1), lr2.rbegin(), lr2.rend());\n\n    return lr1;\n  }\n\
    \n  auto query_subtree(int v) { return pii(tin[v], tout[v]); }\n\n  int query_point(int\
    \ v) { return tin[v]; }\n\n  int lca(int u, int v) {\n    while(head[u] != head[v])\
    \ {\n      if (dep[head[u]] > dep[head[v]])\n        swap(u, v);\n      v = head_parent(v);\n\
    \    }\n    return tin[u] < tin[v] ? u : v;\n  }\n\n  int dis(int u, int v) {\n\
    \    return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n  }\n\n  int kth(int s, int\
    \ t, int k) {\n    int l = lca(s, t);\n    if (int d = dep[s] + dep[t] - 2 * dep[l];\
    \ k > d)\n      return -1;\n    else if (k > dep[s] - dep[l])\n      k = d - k,\
    \ swap(s, t);\n    while(k > dep[s] - dep[head[s]]) {\n      k -= dep[s] - dep[head[s]]\
    \ + 1;\n      s = head_parent(s);\n    }\n    return inv_tin[tin[s] - k];\n  }\n\
    \n  int median(int u, int v, int w) {\n    return lca(u, v) ^ lca(u, w) ^ lca(v,\
    \ w);\n  }\n\n  template<class M>\n  vc<M> reorder_init(vc<M> init) {\n    assert(ssize(init)\
    \ == ssize(dep));\n    auto r = init;\n    for(int i = 0; i < ssize(init); i++)\n\
    \      r[tin[i]] = init[i];\n    return r;\n  }\n\n  const span<int> childs(int\
    \ v) {\n    return span(child_list.begin() + lb[v], lb[v + 1] - lb[v]);\n  }\n\
    \  const span<int> light_childs(int v) {\n    return span(child_list.begin() +\
    \ lb[v] + 1, max(lb[v + 1] - lb[v] - 1, 0));\n  }\n  inline int heavy_child(int\
    \ v) {\n    return lb[v] == lb[v + 1] ? -1 : child_list[lb[v]];\n  }\n  inline\
    \ int parent(int v) {\n    return p[v];\n  }\n\n  inline int depth(int v) { return\
    \ dep[v]; }\n  inline int size(int v) { return sz[v]; }\n  inline int degree(int\
    \ v) { return lb[v + 1] - lb[v] + (v != root); }\n  bool in_subtree_of(int a,\
    \ int b) { return tin[b] <= tin[a] and tout[a] <= tout[b]; }\n  const span<int>\
    \ centroid() {\n    if (c.empty()) {\n      vc<bool> ok(n, true);\n      for(int\
    \ v = 0; v < n; v++) {\n        if (2 * (n - sz[v]) > n)\n          ok[v] = false;\n\
    \        if (v != root and 2 * sz[v] > n)\n          ok[p[v]] = false;\n     \
    \ }\n      for(int v = 0; v < n; v++)\n        if (ok[v])\n          c.eb(v);\n\
    \    }\n    return c;\n  }\n\n  inline int parent_eid(int v) { return v_to_e[v];\
    \ }\n};\n#line 1 \"ds/fenwick_tree.cpp\"\ntemplate<class T>\nstruct fenwick_tree\
    \ {\n  const int size;\n  vector<T> data;\n\n  fenwick_tree(int _size) : size(_size\
    \ + 1), data(_size + 1) {}\n  fenwick_tree(vector<T> init) : size(ssize(init)\
    \ + 1), data(ssize(init) + 1) {\n    partial_sum(init.begin(), init.end(), data.begin()\
    \ + 1);\n    for(int i = size - 1; i > 0; i--)\n      data[i] -= data[i - (i &\
    \ (-i))];\n  }\n\n  void add(int i, T d) {\n    for(i += 1; i < size; i += i &\
    \ (-i))\n      data[i] += d;\n  }\n\n  T query(int i) {\n    T res = T(0);\n \
    \   for(i += 1; i > 0; i -= i & (-i))\n      res += data[i];\n    return res;\n\
    \  }\n\n  T query(int l, int r) { //query [l, r)\n    return query(r - 1) - query(l\
    \ - 1);\n  }\n};\n#line 6 \"test/vertex_add_path_sum.test.cpp\"\n\nint main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin >> n >>\
    \ q;\n  vll a(n);\n  for(ll &x : a) cin >> x;\n  vc<pii> e(n - 1);\n  for(auto\
    \ &[u, v] : e)\n    cin >> u >> v;\n\n  HLD hld(std::move(e));\n  fenwick_tree\
    \ ft(hld.reorder_init(a));\n  while(q--) {\n    int op; cin >> op;\n    if (op\
    \ == 0) {\n      int p, x; cin >> p >> x;\n      ft.add(hld.query_point(p), x);\n\
    \    } else {\n      int u, v; cin >> u >> v;\n      ll sum = 0;\n      for(auto\
    \ [l, r] : hld.query_path(u, v))\n        sum += ft.query(l, r);\n      cout <<\
    \ sum << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../default/t.cpp\"\n#include \"../tree/HLD.cpp\"\n#include \"../ds/fenwick_tree.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q;\
    \ cin >> n >> q;\n  vll a(n);\n  for(ll &x : a) cin >> x;\n  vc<pii> e(n - 1);\n\
    \  for(auto &[u, v] : e)\n    cin >> u >> v;\n\n  HLD hld(std::move(e));\n  fenwick_tree\
    \ ft(hld.reorder_init(a));\n  while(q--) {\n    int op; cin >> op;\n    if (op\
    \ == 0) {\n      int p, x; cin >> p >> x;\n      ft.add(hld.query_point(p), x);\n\
    \    } else {\n      int u, v; cin >> u >> v;\n      ll sum = 0;\n      for(auto\
    \ [l, r] : hld.query_path(u, v))\n        sum += ft.query(l, r);\n      cout <<\
    \ sum << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - tree/HLD.cpp
  - ds/fenwick_tree.cpp
  isVerificationFile: true
  path: test/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2026-09-02 20:44:03+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_add_path_sum.test.cpp
- /verify/test/vertex_add_path_sum.test.cpp.html
title: test/vertex_add_path_sum.test.cpp
---
