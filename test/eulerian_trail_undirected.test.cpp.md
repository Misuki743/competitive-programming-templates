---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: graph/misc/eulerian_trail.cpp
    title: graph/misc/eulerian_trail.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/eulerian_trail_undirected
    links:
    - https://judge.yosupo.jp/problem/eulerian_trail_undirected
  bundledCode: "#line 1 \"test/eulerian_trail_undirected.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/eulerian_trail_undirected\"\n\n#line 1 \"\
    default/t.cpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define pb push_back\n\
    #define eb emplace_back\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
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
    \ f;\n  }\n}\n\nusing namespace algorithm_extend;\n#line 1 \"graph/misc/eulerian_trail.cpp\"\
    \ntemplate<bool directed = false, bool circuit = false>\narray<vector<int>, 2>\
    \ eulerian_trail(int n, vector<array<int, 2>> &e) {\n  vector<int> indeg(n), outdeg(n);\n\
    \  vector<vector<int>> g(n);\n  for(int i = 0; auto [u, v] : e) {\n    outdeg[u]\
    \ += 1, indeg[v] += 1;\n    if constexpr (!directed)\n      g[v].emplace_back(i);\n\
    \    g[u].emplace_back(i++);\n  }\n\n  int s = -1;\n  if constexpr (directed)\
    \ {\n    for(int v = 0; v < n; v++) {\n      if (abs(indeg[v] - outdeg[v]) >=\
    \ 2) return {};\n      if (outdeg[v] <= indeg[v]) continue;\n      if (s != -1)\
    \ return {};\n      s = v;\n    }\n  } else {\n    for(int v = 0, t = -1; v <\
    \ n; v++) {\n      if ((indeg[v] + outdeg[v]) % 2 == 0) continue;\n      if (s\
    \ != -1 and t != -1) return {};\n      if (s == -1) s = v;\n      else t = v;\n\
    \    }\n  }\n\n  if constexpr (circuit)\n    if (s != -1) \n      return {};\n\
    \n  if (s == -1)\n    for(int v = 0; v < n; v++)\n      if (indeg[v] | outdeg[v])\n\
    \        s = v;\n\n  if (s == -1)\n    s = 0;\n\n  vector<int> vid, eid, ptr(n);\n\
    \  vector<bool> visE(ssize(e), false);\n  auto dfs = [&](int v, auto self) ->\
    \ void {\n    for(int &i = ptr[v]; i < ssize(g[v]); i++) {\n      if (visE[g[v][i]])\
    \ continue;\n      int tmp = g[v][i];\n      int x = v ^ e[tmp][0] ^ e[tmp][1];\n\
    \      visE[tmp] = true;\n      self(x, self);\n      vid.emplace_back(x);\n \
    \     eid.emplace_back(tmp);\n    }\n  };\n\n  dfs(s, dfs);\n  vid.emplace_back(s);\n\
    \n  ranges::reverse(vid);\n  ranges::reverse(eid);\n\n  if (ssize(eid) != ssize(e))\n\
    \    return {};\n  else\n    return {vid, eid};\n}\n#line 5 \"test/eulerian_trail_undirected.test.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int t; cin\
    \ >> t;\n  while(t--) {\n    int n, m; cin >> n >> m;\n    vector<array<int, 2>>\
    \ e(m);\n    for(auto &[u, v] : e)\n      cin >> u >> v;\n    auto [vid, eid]\
    \ = eulerian_trail(n, e);\n    if (vid.empty()) {\n      cout << \"No\\n\"; \n\
    \    } else {\n      cout << \"Yes\\n\";\n      cout << vid << '\\n';\n      cout\
    \ << eid << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/eulerian_trail_undirected\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../graph/misc/eulerian_trail.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int t; cin\
    \ >> t;\n  while(t--) {\n    int n, m; cin >> n >> m;\n    vector<array<int, 2>>\
    \ e(m);\n    for(auto &[u, v] : e)\n      cin >> u >> v;\n    auto [vid, eid]\
    \ = eulerian_trail(n, e);\n    if (vid.empty()) {\n      cout << \"No\\n\"; \n\
    \    } else {\n      cout << \"Yes\\n\";\n      cout << vid << '\\n';\n      cout\
    \ << eid << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - graph/misc/eulerian_trail.cpp
  isVerificationFile: true
  path: test/eulerian_trail_undirected.test.cpp
  requiredBy: []
  timestamp: '2026-09-02 22:57:23+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/eulerian_trail_undirected.test.cpp
layout: document
redirect_from:
- /verify/test/eulerian_trail_undirected.test.cpp
- /verify/test/eulerian_trail_undirected.test.cpp.html
title: test/eulerian_trail_undirected.test.cpp
---
