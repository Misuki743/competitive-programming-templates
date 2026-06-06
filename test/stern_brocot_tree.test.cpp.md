---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: numtheory/Stern_Brocot_tree.cpp
    title: numtheory/Stern_Brocot_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/stern_brocot_tree
    links:
    - https://judge.yosupo.jp/problem/stern_brocot_tree
  bundledCode: "#line 1 \"test/stern_brocot_tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/stern_brocot_tree\"\
    \n\n#line 1 \"default/t.cpp\"\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cctype>\n#include <cfenv>\n#include\
    \ <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include <climits>\n#include\
    \ <cmath>\n#include <complex>\n#include <cstdarg>\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <initializer_list>\n\
    #include <iomanip>\n#include <ios>\n#include <iostream>\n#include <istream>\n\
    #include <iterator>\n#include <limits>\n#include <list>\n#include <map>\n#include\
    \ <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n\
    #include <random>\n#include <set>\n#include <sstream>\n#include <stack>\n#include\
    \ <streambuf>\n#include <string>\n#include <tuple>\n#include <type_traits>\n#include\
    \ <variant>\n#include <bit>\n#include <compare>\n#include <concepts>\n#include\
    \ <numbers>\n#include <ranges>\n#include <span>\n\n#define INT128_MAX (__int128)(((unsigned\
    \ __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN\
    \ (-INT128_MAX - 1)\n\n#define pb push_back\n#define eb emplace_back\n#define\
    \ clock chrono::steady_clock::now().time_since_epoch().count()\n\nusing namespace\
    \ std;\n\ntemplate<size_t I = 0, typename... args>\nostream& print_tuple(ostream&\
    \ os, const tuple<args...> tu) {\n  os << get<I>(tu);\n  if constexpr (I + 1 !=\
    \ sizeof...(args)) {\n    os << ' ';\n    print_tuple<I + 1>(os, tu);\n  }\n \
    \ return os;\n}\ntemplate<typename... args>\nostream& operator<<(ostream& os,\
    \ const tuple<args...> tu) {\n  return print_tuple(os, tu);\n}\ntemplate<class\
    \ T1, class T2>\nostream& operator<<(ostream& os, const pair<T1, T2> pr) {\n \
    \ return os << pr.first << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\n\
    ostream& operator<<(ostream& os, const array<T, N> &arr) {\n  for(size_t i = 0;\
    \ T x : arr) {\n    os << x;\n    if (++i != N) os << ' ';\n  }\n  return os;\n\
    }\ntemplate<class T>\nostream& operator<<(ostream& os, const vector<T> &vec) {\n\
    \  for(size_t i = 0; T x : vec) {\n    os << x;\n    if (++i != size(vec)) os\
    \ << ' ';\n  }\n  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const set<T> &s) {\n  for(size_t i = 0; T x : s) {\n    os << x;\n    if\
    \ (++i != size(s)) os << ' ';\n  }\n  return os;\n}\ntemplate<class T>\nostream&\
    \ operator<<(ostream& os, const multiset<T> &s) {\n  for(size_t i = 0; T x : s)\
    \ {\n    os << x;\n    if (++i != size(s)) os << ' ';\n  }\n  return os;\n}\n\
    template<class T1, class T2>\nostream& operator<<(ostream& os, const map<T1, T2>\
    \ &m) {\n  for(size_t i = 0; pair<T1, T2> x : m) {\n    os << x.first << \" :\
    \ \" << x.second;\n    if (++i != size(m)) os << \", \";\n  }\n  return os;\n\
    }\ntemplate<class T>\nostream& operator<<(ostream&os, span<T> &s) {\n  for(size_t\
    \ i = 0; T &x : s) {\n    os << x;\n    if (++i != size(s)) os << ' ';\n  }\n\
    \  return os;\n}\n\n#ifdef DEBUG\n#define dbg(...) cerr << '(', _do(#__VA_ARGS__),\
    \ cerr << \") = \", _do2(__VA_ARGS__)\ntemplate<typename T> void _do(T &&x) {\
    \ cerr << x; }\ntemplate<typename T, typename ...S> void _do(T &&x, S&&...y) {\
    \ cerr << x << \", \"; _do(y...); }\ntemplate<typename T> void _do2(T &&x) { cerr\
    \ << x << endl; }\ntemplate<typename T, typename ...S> void _do2(T &&x, S&&...y)\
    \ { cerr << x << \", \"; _do2(y...); }\n#else\n#define dbg(...)\n#endif\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ldb = long double;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n//#define double ldb\n\
    \ntemplate<typename T> using vc = vector<T>;\ntemplate<typename T> using vvc =\
    \ vc<vc<T>>;\ntemplate<typename T> using vvvc = vc<vvc<T>>;\n\nusing vi = vc<int>;\n\
    using vll = vc<ll>;\nusing vvi = vvc<int>;\nusing vvll = vvc<ll>;\n\ntemplate<typename\
    \ T> using min_heap = priority_queue<T, vc<T>, greater<T>>;\ntemplate<typename\
    \ T> using max_heap = priority_queue<T>;\n\ntemplate<typename R, typename F, typename...\
    \ Args>\nconcept R_invocable = requires(F&& f, Args&&... args) {\n  { std::invoke(std::forward<F>(f),\
    \ std::forward<Args>(args)...) } -> std::same_as<R>;\n};\ntemplate<ranges::forward_range\
    \ rng, class T = ranges::range_value_t<rng>, typename F>\nrequires R_invocable<T,\
    \ F, T, T>\nvoid pSum(rng &&v, F f) {\n  if (!v.empty())\n    for(T p = *v.begin();\
    \ T &x : v | views::drop(1))\n      x = p = f(p, x);\n}\ntemplate<ranges::forward_range\
    \ rng, class T = ranges::range_value_t<rng>>\nvoid pSum(rng &&v) {\n  if (!v.empty())\n\
    \    for(T p = *v.begin(); T &x : v | views::drop(1))\n      x = p = p + x;\n\
    }\n\ntemplate<ranges::forward_range rng>\nvoid Unique(rng &v) {\n  ranges::sort(v);\n\
    \  v.resize(unique(v.begin(), v.end()) - v.begin());\n}\n\ntemplate<ranges::random_access_range\
    \ rng>\nrng invPerm(rng p) {\n  rng ret = p;\n  for(int i = 0; i < ssize(p); i++)\n\
    \    ret[p[i]] = i;\n  return ret;\n}\n\ntemplate<ranges::random_access_range\
    \ rng>\nvi argSort(rng p) {\n  vi id(size(p));\n  iota(id.begin(), id.end(), 0);\n\
    \  ranges::sort(id, {}, [&](int i) { return pair(p[i], i); });\n  return id;\n\
    }\n\ntemplate<ranges::random_access_range rng, class T = ranges::range_value_t<rng>,\
    \ typename F>\nrequires invocable<F, T&>\nvi argSort(rng p, F proj) {\n  vi id(size(p));\n\
    \  iota(id.begin(), id.end(), 0);\n  ranges::sort(id, {}, [&](int i) { return\
    \ pair(proj(p[i]), i); });\n  return id;\n}\n\ntemplate<bool directed>\nvvi read_graph(int\
    \ n, int m, int base) {\n  vvi g(n);\n  for(int i = 0; i < m; i++) {\n    int\
    \ u, v; cin >> u >> v;\n    u -= base, v -= base;\n    g[u].emplace_back(v);\n\
    \    if constexpr (!directed)\n      g[v].emplace_back(u);\n  }\n  return g;\n\
    }\n\ntemplate<bool directed>\nvvi adjacency_list(int n, vc<pii> e, int base) {\n\
    \  vvi g(n);\n  for(auto [u, v] : e) {\n    u -= base, v -= base;\n    g[u].emplace_back(v);\n\
    \    if constexpr (!directed)\n      g[v].emplace_back(u);\n  }\n  return g;\n\
    }\n\ntemplate<class T>\nvc<pii> equal_subarrays(vc<T> &v) {\n  vc<pii> lr;\n \
    \ for(int i = 0, j = 0; i < ssize(v); i = j) {\n    while(j < ssize(v) and v[i]\
    \ == v[j]) j++;\n    lr.eb(i, j);\n  }\n  return lr;\n}\n\ntemplate<class T, typename\
    \ F>\nrequires invocable<F, T&>\nvc<pii> equal_subarrays(vc<T> &v, F proj) {\n\
    \  vc<pii> lr;\n  for(int i = 0, j = 0; i < ssize(v); i = j) {\n    while(j <\
    \ ssize(v) and proj(v[i]) == proj(v[j])) j++;\n    lr.eb(i, j);\n  }\n  return\
    \ lr;\n}\n\ntemplate<class T>\nvoid setBit(T &msk, int bit, bool x) { (msk &=\
    \ ~(T(1) << bit)) |= T(x) << bit; }\ntemplate<class T> void onBit(T &msk, int\
    \ bit) { setBit(msk, bit, true); }\ntemplate<class T> void offBit(T &msk, int\
    \ bit) { setBit(msk, bit, false); }\ntemplate<class T> void flipBit(T &msk, int\
    \ bit) { msk ^= T(1) << bit; }\ntemplate<class T> bool getBit(T msk, int bit)\
    \ { return msk >> bit & T(1); }\n\ntemplate<class T>\nT floorDiv(T a, T b) {\n\
    \  if (b < 0) a *= -1, b *= -1;\n  return a >= 0 ? a / b : (a - b + 1) / b;\n\
    }\ntemplate<class T>\nT ceilDiv(T a, T b) {\n  if (b < 0) a *= -1, b *= -1;\n\
    \  return a >= 0 ? (a + b - 1) / b : a / b;\n}\n\ntemplate<class T> bool chmin(T\
    \ &a, T b) { return a > b ? a = b, 1 : 0; }\ntemplate<class T> bool chmax(T &a,\
    \ T b) { return a < b ? a = b, 1 : 0; }\n\n#line 1 \"numtheory/Stern_Brocot_tree.cpp\"\
    \nnamespace Stern_Brocot_tree {\n  using i128 = __int128;\n  struct fraction {\n\
    \    ll u, d;\n    void reduce() {\n      ll g = gcd(u, d);\n      u /= g, d /=\
    \ g;\n    }\n  };\n  auto operator<=>(fraction a, fraction b) { return (i128)a.u\
    \ * b.d <=> (i128)a.d * b.u; }\n  bool operator==(fraction a, fraction b) { return\
    \ (i128)a.u * b.d == (i128)a.d * b.u; }\n  ostream& operator<<(ostream &os, fraction\
    \ f) { os << f.u << ' ' << f.d; return os; }\n\n  auto encode_path(fraction f)\
    \ {\n    f.reduce();\n\n    fraction l{0, 1}, m{1, 1}, r{1, 0};\n    vc<pair<char,\
    \ ll>> path;\n    while(f != m) {\n      if (f < m) {\n        ll x = ceilDiv((i128)f.d\
    \ * m.u - (i128)f.u * m.d, (i128)f.u * l.d - (i128)f.d * l.u);\n        r = fraction{l.u\
    \ * (x - 1) + m.u, l.d * (x - 1) + m.d};\n        path.eb('L', x);\n      } else\
    \ {\n        ll x = ceilDiv((i128)f.u * m.d - (i128)f.d * m.u, (i128)f.d * r.u\
    \ - (i128)f.u * r.d);\n        l = fraction{r.u * (x - 1) + m.u, r.d * (x - 1)\
    \ + m.d};\n        path.eb('R', x);\n      }\n      m = fraction{l.u + r.u, l.d\
    \ + r.d};\n    }\n    return path;\n  }\n\n  fraction decode_path(vc<pair<char,\
    \ ll>> path) {\n    fraction l{0, 1}, m{1, 1}, r{1, 0};\n    for(auto [c, x] :\
    \ path) {\n      if (c == 'L') r = fraction{l.u * (x - 1) + m.u, l.d * (x - 1)\
    \ + m.d};\n      else l = fraction{r.u * (x - 1) + m.u, r.d * (x - 1) + m.d};\n\
    \      m = fraction{l.u + r.u, l.d + r.d};\n    }\n    return m;\n  }\n\n  fraction\
    \ LCA(fraction a, fraction b) {\n    a.reduce(), b.reduce();\n    auto pa = encode_path(a);\n\
    \    auto pb = encode_path(b);\n    ranges::reverse(pa);\n    ranges::reverse(pb);\n\
    \    vc<pair<char, ll>> path;\n    while(!pa.empty() and !pb.empty() and pa.back()\
    \ == pb.back())\n      path.eb(pa.back()), pa.pop_back(), pb.pop_back();\n   \
    \ if (!pa.empty() and !pb.empty() and pa.back().first == pb.back().first)\n  \
    \    path.eb(pa.back().first, min(pa.back().second, pb.back().second));\n    return\
    \ decode_path(path);\n  }\n\n  fraction ancestor(ll k, fraction f) {\n    f.reduce();\n\
    \    auto path = encode_path(f);\n    for(int i = 0; i < ssize(path); i++) {\n\
    \      auto &[_, x] = path[i];\n      if (k <= x) {\n        chmin(x, k);\n  \
    \      return decode_path(vector(path.begin(), path.begin() + i + 1));\n     \
    \ }\n      k -= x;\n    }\n    return fraction{-1, 1};\n  }\n\n  auto range(fraction\
    \ f) {\n    f.reduce();\n\n    fraction l{0, 1}, m{1, 1}, r{1, 0};\n    vc<pair<char,\
    \ ll>> path;\n    while(f != m) {\n      if (f < m) {\n        ll x = ceilDiv((i128)f.d\
    \ * m.u - (i128)f.u * m.d, (i128)f.u * l.d - (i128)f.d * l.u);\n        r = fraction{l.u\
    \ * (x - 1) + m.u, l.d * (x - 1) + m.d};\n        path.eb('L', x);\n      } else\
    \ {\n        ll x = ceilDiv((i128)f.u * m.d - (i128)f.d * m.u, (i128)f.d * r.u\
    \ - (i128)f.u * r.d);\n        l = fraction{r.u * (x - 1) + m.u, r.d * (x - 1)\
    \ + m.d};\n        path.eb('R', x);\n      }\n      m = fraction{l.u + r.u, l.d\
    \ + r.d};\n    }\n    return pair(l, r);\n  }\n};\n\nusing namespace Stern_Brocot_tree;\n\
    #line 5 \"test/stern_brocot_tree.test.cpp\"\n\nint main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int t; cin >> t;\n  while(t--) {\n    string op; cin >>\
    \ op;\n    if (op == \"ENCODE_PATH\") {\n      ll a, b; cin >> a >> b;\n     \
    \ auto path = encode_path(fraction(a, b));\n      cout << ssize(path) << ' ';\n\
    \      for(auto [c, x] : path) cout << c << ' ' << x << ' ';\n      cout << '\\\
    n';\n    } else if (op == \"DECODE_PATH\") {\n      int k; cin >> k;\n      vc<pair<char,\
    \ ll>> path(k);\n      for(auto &[c, x] : path) cin >> c >> x;\n      cout <<\
    \ decode_path(path) << '\\n';\n    } else if (op == \"LCA\") {\n      ll a, b,\
    \ c, d; cin >> a >> b >> c >> d;\n      cout << LCA(fraction{a, b}, fraction{c,\
    \ d}) << '\\n';\n    } else if (op == \"ANCESTOR\") {\n      ll k, a, b; cin >>\
    \ k >> a >> b;\n      auto [u, d] = ancestor(k, fraction{a, b});\n      if (u\
    \ == -1) cout << -1 << '\\n';\n      else cout << u << ' ' << d << '\\n';\n  \
    \  } else if (op == \"RANGE\") {\n      ll a, b; cin >> a >> b;\n      cout <<\
    \ range(fraction{a, b}) << '\\n';\n    }\n  }\n\n  return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/stern_brocot_tree\"\n\n\
    #include \"../default/t.cpp\"\n#include \"../numtheory/Stern_Brocot_tree.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int t; cin\
    \ >> t;\n  while(t--) {\n    string op; cin >> op;\n    if (op == \"ENCODE_PATH\"\
    ) {\n      ll a, b; cin >> a >> b;\n      auto path = encode_path(fraction(a,\
    \ b));\n      cout << ssize(path) << ' ';\n      for(auto [c, x] : path) cout\
    \ << c << ' ' << x << ' ';\n      cout << '\\n';\n    } else if (op == \"DECODE_PATH\"\
    ) {\n      int k; cin >> k;\n      vc<pair<char, ll>> path(k);\n      for(auto\
    \ &[c, x] : path) cin >> c >> x;\n      cout << decode_path(path) << '\\n';\n\
    \    } else if (op == \"LCA\") {\n      ll a, b, c, d; cin >> a >> b >> c >> d;\n\
    \      cout << LCA(fraction{a, b}, fraction{c, d}) << '\\n';\n    } else if (op\
    \ == \"ANCESTOR\") {\n      ll k, a, b; cin >> k >> a >> b;\n      auto [u, d]\
    \ = ancestor(k, fraction{a, b});\n      if (u == -1) cout << -1 << '\\n';\n  \
    \    else cout << u << ' ' << d << '\\n';\n    } else if (op == \"RANGE\") {\n\
    \      ll a, b; cin >> a >> b;\n      cout << range(fraction{a, b}) << '\\n';\n\
    \    }\n  }\n\n  return 0;\n}\n\n"
  dependsOn:
  - default/t.cpp
  - numtheory/Stern_Brocot_tree.cpp
  isVerificationFile: true
  path: test/stern_brocot_tree.test.cpp
  requiredBy: []
  timestamp: '2026-04-03 02:38:47+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/stern_brocot_tree.test.cpp
layout: document
redirect_from:
- /verify/test/stern_brocot_tree.test.cpp
- /verify/test/stern_brocot_tree.test.cpp.html
title: test/stern_brocot_tree.test.cpp
---
