---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: numtheory/factorize_pollard_rho.cpp
    title: numtheory/factorize_pollard_rho.cpp
  - icon: ':heavy_check_mark:'
    path: numtheory/primitive_root.cpp
    title: numtheory/primitive_root.cpp
  - icon: ':heavy_check_mark:'
    path: numtheory/two_square_sum.cpp
    title: numtheory/two_square_sum.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_square_sum
    links:
    - https://judge.yosupo.jp/problem/two_square_sum
  bundledCode: "#line 1 \"test/two_square_sum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_square_sum\"\
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
    \ T b) { return a < b ? a = b, 1 : 0; }\n\n#line 1 \"numtheory/factorize_pollard_rho.cpp\"\
    \n//source: KACTL(https://github.com/kth-competitive-programming/kactl)\n\null\
    \ modmul(ull a, ull b, ull M) {\n\tll ret = a * b - M * ull(1.L / M * a * b);\n\
    \treturn ret + M * (ret < 0) - M * (ret >= (ll)M);\n}\n\null modpow(ull b, ull\
    \ e, ull mod) {\n\tull ans = 1;\n\tfor (; e; b = modmul(b, b, mod), e /= 2)\n\t\
    \tif (e & 1) ans = modmul(ans, b, mod);\n\treturn ans;\n}\n\nbool isPrime(ull\
    \ n) {\n\tif (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n\tull A[] = {2, 325,\
    \ 9375, 28178, 450775, 9780504, 1795265022},\n\t    s = __builtin_ctzll(n-1),\
    \ d = n >> s;\n\tfor (ull a : A) {   // ^ count trailing zeroes\n\t\tull p = modpow(a%n,\
    \ d, n), i = s;\n\t\twhile (p != 1 && p != n - 1 && a % n && i--)\n\t\t\tp = modmul(p,\
    \ p, n);\n\t\tif (p != n-1 && i != s) return 0;\n\t}\n\treturn 1;\n}\n\null pollard(ull\
    \ n) {\n  static mt19937_64 rng(clock);\n  uniform_int_distribution<ull> unif(0,\
    \ n - 1);\n  ull c = 1;\n\tauto f = [n, &c](ull x) { return modmul(x, x, n) +\
    \ c % n; };\n\tull x = 0, y = 0, t = 30, prd = 2, i = 1, q;\n\twhile (t++ % 40\
    \ || __gcd(prd, n) == 1) {\n\t\tif (x == y) c = unif(rng), x = ++i, y = f(x);\n\
    \t\tif ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;\n\t\tx = f(x), y =\
    \ f(f(y));\n\t}\n\treturn __gcd(prd, n);\n}\n\nvector<ull> factor(ull n) {\n\t\
    if (n == 1) return {};\n\tif (isPrime(n)) return {n};\n\tull x = pollard(n);\n\
    \tauto l = factor(x), r = factor(n / x);\n\tl.insert(l.end(), r.begin(), r.end());\n\
    \treturn l;\n}\n#line 1 \"numtheory/primitive_root.cpp\"\n//#include \"numtheory/fastFactorize.cpp\"\
    \n\null primitiveRoot(ull p) {\n  auto fac = factor(p - 1);\n  ranges::sort(fac);\n\
    \  fac.resize(unique(fac.begin(), fac.end()) - fac.begin());\n  auto test = [p,\
    \ fac](ull x) {\n    for(ull d : fac)\n      if (modpow(x, (p - 1) / d, p) ==\
    \ 1)\n        return false;\n    return true;\n  };\n  static mt19937_64 rng(clock);\n\
    \  uniform_int_distribution<ull> unif(1, p - 1);\n  ull root;\n  while(!test(root\
    \ = unif(rng)));\n  return root;\n}\n#line 1 \"numtheory/two_square_sum.cpp\"\n\
    //#include \"numtheory/factorize_pollard_rho.cpp\"\n//#include \"numtheory/primitive_root.cpp\"\
    \n\n//min of mod of linear come from maspy's library\n//link: https://maspypy.github.io/library/mod/min_of_linear.hpp\n\
    //      https://maspypy.github.io/library/mod/min_of_linear_segments.hpp\n\n/*\n\
    ax + b (x>=0) \u304C\u6700\u5C0F\u3068\u306A\u308B\u3068\u3053\u308D\u306E\u60C5\
    \u5831\u3092\u8FD4\u3059\u3002\nprefix min \u3092\u66F4\u65B0\u3059\u308B x \u5168\
    \u4F53\u304C\u3001\u7B49\u5DEE\u6570\u5217\u306E\u548C\u96C6\u5408\u3002\u6B21\
    \u3092\u8FD4\u3059\u3002\n\u30FB\u7B49\u5DEE\u6570\u5217\u306E\u5883\u754C\u3068\
    \u306A\u308B x_0, x_1, ..., x_n\n\u30FB\u5404\u5883\u754C\u306E\u9593\u3067\u306E\
    \u4EA4\u5DEE dx_0, ..., dx_{n-1}\n*/\npair<vc<ll>, vc<ll>> min_of_linear_segments(ll\
    \ a, ll b, ll mod) {\n  assert(0 <= a && a < mod);\n  assert(0 <= b && b < mod);\n\
    \  vc<ll> X = {0};\n  vc<ll> DX;\n  ll g = gcd(a, mod);\n  a /= g, b /= g, mod\
    \ /= g;\n  // p/q <= (mod-a)/mod <= r/s\n  ll p = 0, q = 1, r = 1, s = 1;\n  ll\
    \ det_l = mod - a, det_r = a;\n  ll x = 0, y = b;\n\n  while (y) {\n    // upd\
    \ r/s\n    ll k = det_r / det_l;\n    det_r %= det_l;\n    if (det_r == 0) {\n\
    \      --k;\n      det_r = det_l;\n    }\n    r += k * p;\n    s += k * q;\n \
    \   while (1) {\n      ll k = max(0ll, ceilDiv(det_l - y, det_r));\n      if (det_l\
    \ - k * det_r <= 0) break;\n      det_l -= k * det_r;\n      p += k * r;\n   \
    \   q += k * s;\n      // p/q <= a/mod\n      // (aq - pmod) = det_l \u3092 y\
    \ \u304B\u3089\u5F15\u304F\n      k = y / det_l;\n      y -= k * det_l;\n    \
    \  x += q * k;\n      X.eb(x);\n      DX.eb(q);\n    }\n    k = det_l / det_r;\n\
    \    det_l -= k * det_r;\n    p += k * r;\n    q += k * s;\n    assert(min({p,\
    \ q, r, s}) >= 0);\n  }\n  return {X, DX};\n}\n\n// min_{x in [L, R)} (ax+b mod)\n\
    using i128 = __int128;\npair<i128, ll> min_of_linear(i128 L, i128 R, ll a, ll\
    \ b, ll mod) {\n  i128 n = R - L;\n  b = (b + a * L) % mod;\n  if (b < 0) b +=\
    \ mod;\n  auto [X, DX] = min_of_linear_segments(a, b, mod);\n  ll x = 0;\n  for\
    \ (int i = 0; i < int(X.size()) - 1; ++i) {\n    ll xl = X[i], xr = X[i + 1];\n\
    \    if (xr < n) {\n      x = xr;\n      continue;\n    }\n    x = xl + (n - 1\
    \ - x) / DX[i] * DX[i];\n    break;\n  }\n  ll y = (i128(a) * x + b) % mod;\n\
    \  return {L + x, y};\n}\n//\n\nstruct Gauss_int { ll a, b; };\nGauss_int operator+(Gauss_int\
    \ x, Gauss_int y) { return {x.a + y.a, x.b + y.b}; }\nGauss_int operator-(Gauss_int\
    \ x, Gauss_int y) { return {x.a - y.a, x.b - y.b}; }\nGauss_int operator*(Gauss_int\
    \ x, Gauss_int y) { return {x.a * y.a - x.b * y.b, x.b * y.a + x.a * y.b}; }\n\
    \nvc<pii> two_square_sum(ll n) {\n  if (n == 0) return {pii(0, 0)};\n  auto D\
    \ = factor(n);\n  ranges::sort(D);\n\n  vc<Gauss_int> sol;\n  sol.pb({-1, 0});\n\
    \  sol.pb({0, -1});\n  sol.pb({1, 0});\n  sol.pb({0, 1});\n  for(auto [l, r] :\
    \ equal_subarrays(D)) {\n    ll p = D[l];\n    int e = r - l;\n    if (p == 2)\
    \ {\n      Gauss_int y{1, 0};\n      for(int i = 0; i < e; i++)\n        y = y\
    \ * Gauss_int{1, 1};\n      for(auto &x : sol)\n        x = x * y;\n    } else\
    \ if (p % 4 == 1) {\n      ll i = modpow(primitiveRoot(p), (p - 1) / 4, p);\n\n\
    \      ll d;\n      {\n        ll U = sqrtl(p);\n        while(U * U < p) U++;\n\
    \        auto [d1, mn1] = min_of_linear(1, U, i, 0, p);\n        auto [d2, mn2]\
    \ = min_of_linear(1, U, p - i, 0, p);\n        d = mn1 < U ? d1 : d2;\n      }\n\
    \n      vc<Gauss_int> pw(e + 1);\n      pw[0] = {1, 0};\n      pw[1] = {(ll)((i128)(d)\
    \ * i % p), d};\n      for(int j = 1; j <= e; j++)\n        pw[j] = pw[j - 1]\
    \ * pw[1];\n\n      vc<Gauss_int> nxt;\n      for(auto x : sol) {\n        for(int\
    \ j = 0; j <= e; j++) {\n          auto y = pw[j];\n          auto z = pw[e -\
    \ j];\n          swap(z.a, z.b);\n          nxt.pb(x * y * z);\n        }\n  \
    \    }\n\n      sol.swap(nxt);\n\n    } else if (e % 2 == 0) {\n      ll q = 1;\n\
    \      for(int i = 0; i < e / 2; i++)\n        q *= p;\n      for(auto &x : sol)\n\
    \        x = x * Gauss_int{q, 0};\n    } else {\n      return {};\n    }\n  }\n\
    \n  vc<pii> res;\n  for(auto [a, b] : sol)\n    if (min(a, b) >= 0)\n      res.eb(a,\
    \ b);\n  return res;\n}\n#line 7 \"test/two_square_sum.test.cpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int q; cin >> q;\n  while(q--)\
    \ {\n    ll n; cin >> n;\n    auto sol = two_square_sum(n);\n    cout << size(sol)\
    \ << '\\n';\n    for(auto pr : sol)\n      cout << pr << '\\n';\n  }\n\n  return\
    \ 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_square_sum\"\n\n#include\
    \ \"../default/t.cpp\"\n#include \"../numtheory/factorize_pollard_rho.cpp\"\n\
    #include \"../numtheory/primitive_root.cpp\"\n#include \"../numtheory/two_square_sum.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int q;\
    \ cin >> q;\n  while(q--) {\n    ll n; cin >> n;\n    auto sol = two_square_sum(n);\n\
    \    cout << size(sol) << '\\n';\n    for(auto pr : sol)\n      cout << pr <<\
    \ '\\n';\n  }\n\n  return 0;\n}\n\n"
  dependsOn:
  - default/t.cpp
  - numtheory/factorize_pollard_rho.cpp
  - numtheory/primitive_root.cpp
  - numtheory/two_square_sum.cpp
  isVerificationFile: true
  path: test/two_square_sum.test.cpp
  requiredBy: []
  timestamp: '2026-04-03 23:26:29+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/two_square_sum.test.cpp
layout: document
redirect_from:
- /verify/test/two_square_sum.test.cpp
- /verify/test/two_square_sum.test.cpp.html
title: test/two_square_sum.test.cpp
---
