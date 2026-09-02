---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: numtheory/sieve_of_Eratosthenes.cpp
    title: numtheory/sieve_of_Eratosthenes.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest_sieve_of_Eratosthenes.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"default/t.cpp\"\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n\
    #include <climits>\n#include <cmath>\n#include <complex>\n#include <cstdarg>\n\
    #include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n\
    #include <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n\
    #include <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n\
    #include <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include\
    \ <ostream>\n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <streambuf>\n#include <string>\n#include <tuple>\n\
    #include <type_traits>\n#include <variant>\n#include <bit>\n#include <compare>\n\
    #include <concepts>\n#include <numbers>\n#include <ranges>\n#include <span>\n\n\
    #define INT128_MAX (__int128)(((unsigned __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__)\
    \ - 1)) - 1)\n#define INT128_MIN (-INT128_MAX - 1)\n\n#define pb push_back\n#define\
    \ eb emplace_back\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
    \nusing namespace std;\n\ntemplate<size_t I = 0, typename... args>\nostream& print_tuple(ostream&\
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
    \ T b) { return a < b ? a = b, 1 : 0; }\n\n#line 1 \"numtheory/sieve_of_Eratosthenes.cpp\"\
    \nnamespace sieve_of_Eratosthenes {\n\n  int _C = 5;\n  vc<int32_t> _mpf, _prime\
    \ = {2, 3};\n\n  //n % 6 == 1 or 5\n  int _id(int n) {\n    return (n - 2) / 6\
    \ * 2 + (n % 6 == 1);\n  }\n\n  int _first_valid(int n) {\n    static int d[6]\
    \ = {1, 0, 3, 2, 1, 0};\n    return n + d[n % 6];\n  }\n\n  int _next_valid(int\
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
    \ F>\n  requires invocable<F, int>\n  void primes(int m, F f) {\n    if (_prime.back()\
    \ < m) {\n      if (m > _C) sieve(m);\n      int s = _next_valid(_prime.back());\n\
    \      for(int i = s, d = _next_valid(s) - s; i < m; i += d, d = 6 - d)\n    \
    \    if (_mpf[_id(i)] == i)\n          _prime.eb(i);\n    }\n    for(int p : _prime)\
    \ {\n      if (p >= m) break;\n      f(p);\n    }\n  }\n}\n#line 5 \"test/mytest_sieve_of_Eratosthenes.test.cpp\"\
    \n\nvc<pii> prime_factorize(int x) {\n  vc<pii> v;\n  int x0 = x;\n  for(int d\
    \ = 2; d <= x0; d++) {\n    if (x % d == 0) {\n      int f = 0;\n      while(x\
    \ % d == 0)\n        x /= d, f++;\n      v.emplace_back(d, f);\n    }\n  }\n \
    \ return v;\n}\n\nvi prime_factor(int x) {\n  vi v;\n  int x0 = x;\n  for(int\
    \ d = 2; d <= x0; d++) {\n    if (x % d == 0) {\n      while(x % d == 0)\n   \
    \     x /= d;\n      v.eb(d);\n    }\n  }\n  return v;\n}\n\nvi divisor(int x)\
    \ {\n  vi v;\n  for(int d = 1; d <= x; d++)\n    if (x % d == 0)\n      v.eb(d);\n\
    \  return v;\n}\n\nint mpf[1 << 10];\n\ntemplate<int32_t sz = 64>\nvoid check_small()\
    \ {\n  if (sz == 0) return;\n  check_small<max(sz - 1, 0)>();\n  for(int i = 1;\
    \ i < sz; i++)\n    assert(mpf[i] == sieve_of_Eratosthenes::mpf(i));\n  for(int\
    \ i = 1; i < sz; i++) {\n    vc<pii> pf;\n    sieve_of_Eratosthenes::factorize(i,\
    \ [&](int p, int e) { pf.eb(p, e); });\n    assert(pf == prime_factorize(i));\n\
    \    assert(sieve_of_Eratosthenes::divisor(i) == divisor(i));\n  }\n}\n\ntemplate<int32_t\
    \ sz = (1 << 10)>\nvoid check_power() {\n  if (sz == 0) return;\n  check_power<max(sz\
    \ >> 1, 0)>();\n  for(int i = 1; i < sz; i++)\n    assert(mpf[i] == sieve_of_Eratosthenes::mpf(i));\n\
    \  for(int i = 1; i < sz; i++) {\n    vc<pii> pf;\n    sieve_of_Eratosthenes::factorize(i,\
    \ [&](int p, int e) { pf.eb(p, e); });\n    assert(pf == prime_factorize(i));\n\
    \    assert(sieve_of_Eratosthenes::divisor(i) == divisor(i));\n  }\n}\n\nvoid\
    \ a_plus_b() {\n  int x, y; cin >> x >> y;\n  cout << x + y << '\\n';\n}\n\nint\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  for(int x = 2;\
    \ x < (1 << 10); x++)\n    mpf[x] = prime_factor(x)[0];\n\n  check_small();\n\
    \  check_power();\n  a_plus_b();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../default/t.cpp\"\n#include \"../numtheory/sieve_of_Eratosthenes.cpp\"\n\nvc<pii>\
    \ prime_factorize(int x) {\n  vc<pii> v;\n  int x0 = x;\n  for(int d = 2; d <=\
    \ x0; d++) {\n    if (x % d == 0) {\n      int f = 0;\n      while(x % d == 0)\n\
    \        x /= d, f++;\n      v.emplace_back(d, f);\n    }\n  }\n  return v;\n\
    }\n\nvi prime_factor(int x) {\n  vi v;\n  int x0 = x;\n  for(int d = 2; d <= x0;\
    \ d++) {\n    if (x % d == 0) {\n      while(x % d == 0)\n        x /= d;\n  \
    \    v.eb(d);\n    }\n  }\n  return v;\n}\n\nvi divisor(int x) {\n  vi v;\n  for(int\
    \ d = 1; d <= x; d++)\n    if (x % d == 0)\n      v.eb(d);\n  return v;\n}\n\n\
    int mpf[1 << 10];\n\ntemplate<int32_t sz = 64>\nvoid check_small() {\n  if (sz\
    \ == 0) return;\n  check_small<max(sz - 1, 0)>();\n  for(int i = 1; i < sz; i++)\n\
    \    assert(mpf[i] == sieve_of_Eratosthenes::mpf(i));\n  for(int i = 1; i < sz;\
    \ i++) {\n    vc<pii> pf;\n    sieve_of_Eratosthenes::factorize(i, [&](int p,\
    \ int e) { pf.eb(p, e); });\n    assert(pf == prime_factorize(i));\n    assert(sieve_of_Eratosthenes::divisor(i)\
    \ == divisor(i));\n  }\n}\n\ntemplate<int32_t sz = (1 << 10)>\nvoid check_power()\
    \ {\n  if (sz == 0) return;\n  check_power<max(sz >> 1, 0)>();\n  for(int i =\
    \ 1; i < sz; i++)\n    assert(mpf[i] == sieve_of_Eratosthenes::mpf(i));\n  for(int\
    \ i = 1; i < sz; i++) {\n    vc<pii> pf;\n    sieve_of_Eratosthenes::factorize(i,\
    \ [&](int p, int e) { pf.eb(p, e); });\n    assert(pf == prime_factorize(i));\n\
    \    assert(sieve_of_Eratosthenes::divisor(i) == divisor(i));\n  }\n}\n\nvoid\
    \ a_plus_b() {\n  int x, y; cin >> x >> y;\n  cout << x + y << '\\n';\n}\n\nint\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  for(int x = 2;\
    \ x < (1 << 10); x++)\n    mpf[x] = prime_factor(x)[0];\n\n  check_small();\n\
    \  check_power();\n  a_plus_b();\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - numtheory/sieve_of_Eratosthenes.cpp
  isVerificationFile: true
  path: test/mytest_sieve_of_Eratosthenes.test.cpp
  requiredBy: []
  timestamp: '2026-09-02 17:05:06+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest_sieve_of_Eratosthenes.test.cpp
layout: document
redirect_from:
- /verify/test/mytest_sieve_of_Eratosthenes.test.cpp
- /verify/test/mytest_sieve_of_Eratosthenes.test.cpp.html
title: test/mytest_sieve_of_Eratosthenes.test.cpp
---
