---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds_problem/frequency_of_tree_distance.cpp
    title: ds_problem/frequency_of_tree_distance.cpp
  - icon: ':heavy_check_mark:'
    path: modint/MontgomeryModInt.cpp
    title: modint/MontgomeryModInt.cpp
  - icon: ':heavy_check_mark:'
    path: poly/NTTmint.cpp
    title: poly/NTTmint.cpp
  - icon: ':heavy_check_mark:'
    path: poly/convolution_ll.cpp
    title: poly/convolution_ll.cpp
  - icon: ':heavy_check_mark:'
    path: tree/centroid_tree.cpp
    title: tree/centroid_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"test/frequency_table_of_tree_distance.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
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
    \ T b) { return a < b ? a = b, 1 : 0; }\n\n#line 1 \"modint/MontgomeryModInt.cpp\"\
    \n//reference: https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
    //note: mod should be an odd prime less than 2^30.\n\ntemplate<uint32_t mod>\n\
    struct MontgomeryModInt {\n  using mint = MontgomeryModInt;\n  using i32 = int32_t;\n\
    \  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static constexpr u32 get_r()\
    \ {\n    u32 res = 1, base = mod;\n    for(i32 i = 0; i < 31; i++)\n      res\
    \ *= base, base *= base;\n    return -res;\n  }\n\n  static constexpr u32 get_mod()\
    \ {\n    return mod;\n  }\n\n  static constexpr u32 n2 = -u64(mod) % mod; //2^64\
    \ % mod\n  static constexpr u32 r = get_r(); //-P^{-1} % 2^32\n\n  u32 a;\n\n\
    \  static u32 reduce(const u64 &b) {\n    return (b + u64(u32(b) * r) * mod) >>\
    \ 32;\n  }\n\n  static u32 transform(const u64 &b) {\n    return reduce(u64(b)\
    \ * n2);\n  }\n\n  MontgomeryModInt() : a(0) {}\n  MontgomeryModInt(const int64_t\
    \ &b) \n    : a(transform(b % mod + mod)) {}\n\n  mint pow(u64 k) const {\n  \
    \  mint res(1), base(*this);\n    while(k) {\n      if (k & 1) \n        res *=\
    \ base;\n      base *= base, k >>= 1;\n    }\n    return res;\n  }\n\n  mint inverse()\
    \ const { return (*this).pow(mod - 2); }\n\n  u32 get() const {\n    u32 res =\
    \ reduce(a);\n    return res >= mod ? res - mod : res;\n  }\n\n  mint& operator+=(const\
    \ mint &b) {\n    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n\
    \  }\n\n  mint& operator-=(const mint &b) {\n    if (i32(a -= b.a) < 0) a += 2\
    \ * mod;\n    return *this;\n  }\n\n  mint& operator*=(const mint &b) {\n    a\
    \ = reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  mint& operator/=(const\
    \ mint &b) {\n    a = reduce(u64(a) * b.inverse().a);\n    return *this;\n  }\n\
    \n  mint operator-() { return mint() - mint(*this); }\n  bool operator==(mint\
    \ b) const {\n    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod :\
    \ b.a);\n  }\n  bool operator!=(mint b) const {\n    return (a >= mod ? a - mod\
    \ : a) != (b.a >= mod ? b.a - mod : b.a);\n  }\n\n  friend mint operator+(mint\
    \ c, mint d) { return c += d; }\n  friend mint operator-(mint c, mint d) { return\
    \ c -= d; }\n  friend mint operator*(mint c, mint d) { return c *= d; }\n  friend\
    \ mint operator/(mint c, mint d) { return c /= d; }\n\n  friend ostream& operator<<(ostream&\
    \ os, const mint& b) {\n    return os << b.get();\n  }\n  friend istream& operator>>(istream&\
    \ is, mint& b) {\n    int64_t val;\n    is >> val;\n    b = mint(val);\n    return\
    \ is;\n  }\n};\n\n//using mint = MontgomeryModInt<1'000'000'007>;\nusing mint\
    \ = MontgomeryModInt<998'244'353>;\n#line 1 \"poly/NTTmint.cpp\"\n//reference:\
    \ https://judge.yosupo.jp/submission/69896\n//remark: MOD = 2^K * C + 1, R is\
    \ a primitive root modulo MOD\n//remark: a.size() <= 2^K must be satisfied\n//some\
    \ common modulo: 998244353  = 2^23 * 119 + 1, R = 3\n//                    469762049\
    \  = 2^26 * 7   + 1, R = 3\n//                    1224736769 = 2^24 * 73  + 1,\
    \ R = 3\n\ntemplate<int32_t k = 23, int32_t c = 119, int32_t r = 3, class Mint\
    \ = MontgomeryModInt<998244353>>\nstruct NTT {\n\n  using u32 = uint32_t;\n  static\
    \ constexpr u32 mod = (1 << k) * c + 1;\n  static constexpr u32 get_mod() { return\
    \ mod; }\n\n  static void ntt(vector<Mint> &a, bool inverse) {\n    static array<Mint,\
    \ 30> w, w_inv;\n    if (w[0] == 0) {\n      Mint root = 2;\n      while(root.pow((mod\
    \ - 1) / 2) == 1) root += 1;\n      for(int i = 0; i < 30; i++)\n        w[i]\
    \ = -(root.pow((mod - 1) >> (i + 2))), w_inv[i] = 1 / w[i];\n    }\n    int n\
    \ = ssize(a);\n    if (not inverse) {\n      for(int m = n; m >>= 1; ) {\n   \
    \     Mint ww = 1;\n        for(int s = 0, l = 0; s < n; s += 2 * m) {\n     \
    \     for(int i = s, j = s + m; i < s + m; i++, j++) {\n            Mint x = a[i],\
    \ y = a[j] * ww;\n            a[i] = x + y, a[j] = x - y;\n          }\n     \
    \     ww *= w[__builtin_ctz(++l)];\n        }\n      }\n    } else {\n      for(int\
    \ m = 1; m < n; m *= 2) {\n        Mint ww = 1;\n        for(int s = 0, l = 0;\
    \ s < n; s += 2 * m) {\n          for(int i = s, j = s + m; i < s + m; i++, j++)\
    \ {\n            Mint x = a[i], y = a[j];\n            a[i] = x + y, a[j] = (x\
    \ - y) * ww;\n          }\n          ww *= w_inv[__builtin_ctz(++l)];\n      \
    \  }\n      }\n      Mint inv = 1 / Mint(n);\n      for(Mint &x : a) x *= inv;\n\
    \    }\n  }\n\n  static vector<Mint> conv(vector<Mint> a, vector<Mint> b) {\n\
    \    if (a.empty() or b.empty()) return {};\n    int sz = ssize(a) + ssize(b)\
    \ - 1;\n    int n = bit_ceil((u32)sz);\n\n    a.resize(n, 0);\n    ntt(a, false);\n\
    \    b.resize(n, 0);\n    ntt(b, false);\n\n    for(int i = 0; i < n; i++)\n \
    \     a[i] *= b[i];\n\n    ntt(a, true);\n\n    a.resize(sz);\n\n    return a;\n\
    \  }\n};\n#line 1 \"poly/convolution_ll.cpp\"\n//the result should not exceed\
    \ long long\nvll convolution_ll(vll a, vll b) {\n  assert(ssize(a) + ssize(b)\
    \ - 1 <= (1 << 23));\n  using Mint0 = MontgomeryModInt<998244353>;\n  using Mint1\
    \ = MontgomeryModInt<469762049>;\n  using Mint2 = MontgomeryModInt<167772161>;\n\
    \  NTT<23, 119, 3, Mint0> ntt0;\n  NTT<26, 7, 3, Mint1> ntt1;\n  NTT<25, 5, 3,\
    \ Mint2> ntt2;\n  vector<Mint0> a0(size(a)), b0(size(b));\n  vector<Mint1> a1(size(a)),\
    \ b1(size(b));\n  vector<Mint2> a2(size(a)), b2(size(b));\n  for(int i = 0; i\
    \ < ssize(a); i++)\n    a0[i] = a[i], a1[i] = a[i], a2[i] = a[i];\n  for(int i\
    \ = 0; i < ssize(b); i++)\n    b0[i] = b[i], b1[i] = b[i], b2[i] = b[i];\n  vector<Mint0>\
    \ x = ntt0.conv(a0, b0);\n  vector<Mint1> y = ntt1.conv(a1, b1);\n  vector<Mint2>\
    \ z = ntt2.conv(a2, b2);\n  vll res(size(x));\n  constexpr uint32_t mod0 = ntt0.get_mod(),\
    \ mod1 = ntt1.get_mod();\n  static const Mint1 im0 = 1 / Mint1(mod0);\n  static\
    \ const Mint2 im1 = 1 / Mint2(mod1), im0m1 = im1 / mod0;\n  static const ll m0\
    \ = mod0, m0m1 = m0 * mod1;\n  for(int i = 0; i < ssize(x); i++) {\n    int y0\
    \ = x[i].get();\n    int y1 = (im0 * (y[i] - y0)).get();\n    int y2 = (im0m1\
    \ * (z[i] - y0) - im1 * y1).get();\n    res[i] = y0 + m0 * y1 + m0m1 * y2;\n \
    \ }\n\n  return res;\n}\n\nvll convolution_self_ll(vll a) {\n  assert(2 * ssize(a)\
    \ - 1 <= (1 << 23));\n  using Mint0 = MontgomeryModInt<998244353>;\n  using Mint1\
    \ = MontgomeryModInt<469762049>;\n  using Mint2 = MontgomeryModInt<167772161>;\n\
    \  NTT<23, 119, 3, Mint0> ntt0;\n  NTT<26, 7, 3, Mint1> ntt1;\n  NTT<25, 5, 3,\
    \ Mint2> ntt2;\n  const int sz = bit_ceil((ull)(2 * ssize(a) - 1));\n  vector<Mint0>\
    \ a0(sz);\n  vector<Mint1> a1(sz);\n  vector<Mint2> a2(sz);\n  for(int i = 0;\
    \ i < ssize(a); i++)\n    a0[i] = a[i], a1[i] = a[i], a2[i] = a[i];\n  ntt0.ntt(a0,\
    \ false);\n  ntt1.ntt(a1, false);\n  ntt2.ntt(a2, false);\n  for(int i = 0; i\
    \ < sz; i++)\n    a0[i] *= a0[i], a1[i] *= a1[i], a2[i] *= a2[i];\n  ntt0.ntt(a0,\
    \ true);\n  ntt1.ntt(a1, true);\n  ntt2.ntt(a2, true);\n  vll res(sz);\n  constexpr\
    \ uint32_t mod0 = ntt0.get_mod(), mod1 = ntt1.get_mod();\n  static const Mint1\
    \ im0 = 1 / Mint1(mod0);\n  static const Mint2 im1 = 1 / Mint2(mod1), im0m1 =\
    \ im1 / mod0;\n  static const ll m0 = mod0, m0m1 = m0 * mod1;\n  for(int i = 0;\
    \ i < sz; i++) {\n    int y0 = a0[i].get();\n    int y1 = (im0 * (a1[i] - y0)).get();\n\
    \    int y2 = (im0m1 * (a2[i] - y0) - im1 * y1).get();\n    res[i] = y0 + m0 *\
    \ y1 + m0m1 * y2;\n  }\n\n  return res;\n}\n\n#line 1 \"tree/centroid_tree.cpp\"\
    \nauto centroid_tree(vvi &g) {\n  int n = ssize(g);\n  vvi tr(n);\n  vi sz(n);\n\
    \  vc<bool> block(n, false);\n\n  auto calc = [&](int v, int p, auto &self) ->\
    \ void {\n    sz[v] = 1;\n    for(int x : g[v]) {\n      if (x == p or block[x])\
    \ continue;\n      self(x, v, self);\n      sz[v] += sz[x];\n    }\n  };\n\n \
    \ auto dfs = [&](int v, auto &self) -> int {\n    calc(v, -1, calc);\n\n    int\
    \ c = v, p = -1;\n    bool move;\n    do {\n      move = false;\n      for(int\
    \ x : g[c]) {\n        if (x == p or block[x] or 2 * sz[x] <= sz[v]) continue;\n\
    \        move = true, p = c, c = x;\n        break;\n      }\n    } while(move);\n\
    \n    block[c] = true;\n    for(int x : g[c]) {\n      if (block[x]) continue;\n\
    \      x = self(x, self);\n      tr[c].emplace_back(x);\n      tr[x].emplace_back(c);\n\
    \    }\n\n    return c;\n  };\n\n  int root = dfs(0, dfs);\n\n  return pair(tr,\
    \ root);\n}\n#line 1 \"ds_problem/frequency_of_tree_distance.cpp\"\nvll frequency_of_tree_distance(vvi\
    \ g) {\n  const int n = ssize(g);\n\n  auto [T, R] = centroid_tree(g);\n  vector<bool>\
    \ vis(n, false);\n  auto calc = [&](int s, int d0) {\n    vll freq(1);\n    auto\
    \ dfs = [&](int v, int p, int d, auto &self) -> void {\n      if (ssize(freq)\
    \ <= d) freq.eb(0);\n      if (d > 0) freq[d] += 1;\n      for(int x : g[v])\n\
    \        if (x != p and !vis[x])\n          self(x, v, d + 1, self);\n    };\n\
    \    dfs(s, -1, d0, dfs);\n    return freq;\n  };\n\n  vll ans(n);\n  auto dfs\
    \ = [&](int v, int p, auto &self) -> void {\n    {\n      auto freq_all = calc(v,\
    \ 0);\n      freq_all[0] = 1;\n      auto F = convolution_self_ll(freq_all);\n\
    \      for(int i = 0; i < n and i < ssize(F); i++)\n        ans[i] += F[i];\n\
    \      vis[v] = true;\n      for(int x : g[v]) {\n        if (vis[x]) continue;\n\
    \        auto G = convolution_self_ll(calc(x, 1));\n        for(int i = 0; i <\
    \ n and i < ssize(G); i++)\n          ans[i] -= G[i];\n      }\n    }\n    for(int\
    \ x : T[v])\n      if (x != p)\n        self(x, v, self);\n  };\n  dfs(R, -1,\
    \ dfs);\n\n  ans.erase(ans.begin());\n  for(ll &x : ans) x /= 2;\n  return ans;\n\
    }\n#line 9 \"test/frequency_table_of_tree_distance.test.cpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n; cin >> n;\n  vector<vector<int>>\
    \ g(n);\n  for(int i = 1; i < n; i++) {\n    int u, v; cin >> u >> v;\n    g[u].emplace_back(v),\
    \ g[v].emplace_back(u);\n  }\n\n  cout << frequency_of_tree_distance(g) << '\\\
    n';\n\n  return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../poly/NTTmint.cpp\"\n#include \"../poly/convolution_ll.cpp\"\n\
    #include \"../tree/centroid_tree.cpp\"\n#include \"../ds_problem/frequency_of_tree_distance.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n;\
    \ cin >> n;\n  vector<vector<int>> g(n);\n  for(int i = 1; i < n; i++) {\n   \
    \ int u, v; cin >> u >> v;\n    g[u].emplace_back(v), g[v].emplace_back(u);\n\
    \  }\n\n  cout << frequency_of_tree_distance(g) << '\\n';\n\n  return 0;\n}\n\n"
  dependsOn:
  - default/t.cpp
  - modint/MontgomeryModInt.cpp
  - poly/NTTmint.cpp
  - poly/convolution_ll.cpp
  - tree/centroid_tree.cpp
  - ds_problem/frequency_of_tree_distance.cpp
  isVerificationFile: true
  path: test/frequency_table_of_tree_distance.test.cpp
  requiredBy: []
  timestamp: '2026-03-22 19:35:41+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/frequency_table_of_tree_distance.test.cpp
layout: document
redirect_from:
- /verify/test/frequency_table_of_tree_distance.test.cpp
- /verify/test/frequency_table_of_tree_distance.test.cpp.html
title: test/frequency_table_of_tree_distance.test.cpp
---
