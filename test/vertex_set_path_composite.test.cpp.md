---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: acted_monoid/affine_sum.cpp
    title: acted_monoid/affine_sum.cpp
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':question:'
    path: modint/Montgomery_modint.cpp
    title: modint/Montgomery_modint.cpp
  - icon: ':question:'
    path: segtree/segment_tree.cpp
    title: segtree/segment_tree.cpp
  - icon: ':question:'
    path: tree/HLD.cpp
    title: tree/HLD.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/vertex_set_path_composite.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\n\n#line 1 \"\
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
    \ f;\n  }\n}\n\nusing namespace algorithm_extend;\n\nnamespace sieve_of_Eratosthenes\
    \ {\n\n  int _C = 5;\n  vc<int32_t> _mpf, _prime = {2, 3};\n\n  //n % 6 == 1 or\
    \ 5\n  int _id(int n) {\n    return (n - 2) / 6 * 2 + (n % 6 == 1);\n  }\n\n \
    \ int _first_valid(int n) {\n    static int d[6] = {1, 0, 3, 2, 1, 0};\n    return\
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
    \ namespace sieve_of_Eratosthenes;\n#line 1 \"modint/Montgomery_modint.cpp\"\n\
    //reference: https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
    //note: mod should be an odd prime less than 2^30.\n\ntemplate<uint32_t mod>\n\
    struct Montgomery_modint {\n  using mint = Montgomery_modint;\n  using i32 = int32_t;\n\
    \  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static constexpr u32 get_r()\
    \ {\n    u32 res = 1, base = mod;\n    for(i32 i = 0; i < 31; i++)\n      res\
    \ *= base, base *= base;\n    return -res;\n  }\n\n  static constexpr u32 get_mod()\
    \ {\n    return mod;\n  }\n\n  static constexpr u32 n2 = -u64(mod) % mod; //2^64\
    \ % mod\n  static constexpr u32 r = get_r(); //-P^{-1} % 2^32\n\n  u32 a;\n\n\
    \  static u32 reduce(const u64 &b) {\n    return (b + u64(u32(b) * r) * mod) >>\
    \ 32;\n  }\n\n  static u32 transform(const u64 &b) {\n    return reduce(u64(b)\
    \ * n2);\n  }\n\n  Montgomery_modint() : a(0) {}\n  Montgomery_modint(const int64_t\
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
    \ is;\n  }\n};\n\n//using mint = Montgomery_modint<1'000'000'007>;\nusing mint\
    \ = Montgomery_modint<998'244'353>;\n#line 1 \"segtree/segment_tree.cpp\"\ntemplate<class\
    \ M, M(*id)(), M(*op)(const M&, const M&)>\nstruct segment_tree {\n  int size;\n\
    \  vector<M> data;\n\n  segment_tree(int _size) : size(_size), data(2 * size,\
    \ id()) {}\n  segment_tree(vector<M> init) : size(ssize(init)), data(2 * size,\
    \ id()) {\n    ranges::copy(init, data.begin() + size);\n    for(int i = size\
    \ - 1; i > 0; i--)\n      data[i] = op(data[i << 1], data[i << 1 | 1]);\n  }\n\
    \n  void set(int i, M x) {\n    data[i += size] = x;\n    while(i >>= 1)\n   \
    \   data[i] = op(data[i << 1], data[i << 1 | 1]);\n  }\n\n  M get(int i) { return\
    \ data[i + size]; }\n\n  M query(int l, int r) {\n    M L = id(), R = id();\n\
    \    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) L\
    \ = op(L, data[l++]);\n      if (r & 1) R = op(data[--r], R);\n    }\n    return\
    \ op(L, R);\n  }\n\n  //return first j in [i, size) s.t. f(op([l, j])) is true,\n\
    \  //assume f(id()) is false.\n  int first_true(int i, function<bool(const M&)>\
    \ f) {\n    vector<int> idL, idR;\n    for(int l = i + size, r = size << 1; l\
    \ < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n      if\
    \ (r & 1) idR.emplace_back(--r);\n    }\n    idL.insert(idL.end(), idR.rbegin(),\
    \ idR.rend());\n    M pre = id();\n    int v = -1;\n    for(int j : idL) {\n \
    \     if (f(op(pre, data[j]))) {\n        v = j;\n        break;\n      } else\
    \ {\n        pre = op(pre, data[j]);\n      }\n    }\n    if (v == -1) return\
    \ size;\n    while(v < size) {\n      if (f(op(pre, data[v << 1])))\n        v\
    \ = v << 1;\n      else\n        pre = op(pre, data[v << 1]), v = v << 1 | 1;\n\
    \    }\n    return v - size;\n  }\n\n  int last_true(int i, function<bool(const\
    \ M&)> f) {\n    vector<int> idL, idR;\n    for(int l = size, r = (i + 1) + size;\
    \ l < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n      if\
    \ (r & 1) idR.emplace_back(--r);\n    }\n    idR.insert(idR.end(), idL.rbegin(),\
    \ idL.rend());\n    M suf = id();\n    int v = -1;\n    for(int j : idR) {\n \
    \     if (f(op(data[j], suf))) {\n        v = j;\n        break;\n      } else\
    \ {\n        suf = op(data[j], suf);\n      }\n    }\n    if (v == -1) return\
    \ -1;\n    while(v < size) {\n      if (f(op(data[v << 1 | 1], suf)))\n      \
    \  v = v << 1 | 1;\n      else\n        suf = op(data[v << 1 | 1], suf), v = v\
    \ << 1;\n    }\n    return v - size;\n  }\n};\n#line 1 \"acted_monoid/affine_sum.cpp\"\
    \ntemplate<class U>\nstruct affine_sum {\n  using M = array<U, 2>;\n  static M\
    \ Mid() { return M{0, 0}; }\n  static M Mop(const M &a, const M &b) { return {a[0]\
    \ + b[0], a[1] + b[1]}; }\n  using T = array<U, 2>;\n  static T Tid() { return\
    \ T{1, 0}; }\n  static T Top(const T &a, const T &b) { return T{a[0] * b[0], a[1]\
    \ * b[0] + b[1]}; }\n  static M act(const M &a, const T &b) { return {a[0] * b[0]\
    \ + a[1] * b[1], a[1]}; }\n};\n#line 1 \"tree/HLD.cpp\"\nstruct HLD {\n  int n,\
    \ root;\n  vi dep, sz, p, head, tin, tout, inv_tin, child_list, c, v_to_e;\n \
    \ vc<int32_t> lb;\n\n  inline int head_parent(int v) const { return p[head[v]];\
    \ }\n\n  HLD(vc<pii> e, int _root = 0) : root(_root) { precompute(e); }\n  HLD(vi\
    \ _p) {\n    vc<pii> e;\n    root = -1;\n    for(int v = 0; v < ssize(_p); v++)\
    \ {\n      if (_p[v] == -1 or _p[v] == v)\n        root = v;\n      else\n   \
    \     e.eb(v, _p[v]);\n    }\n    assert(root != -1);\n    precompute(e);\n  }\n\
    \n  void precompute(vc<pii> &e) {\n    n = ssize(e) + 1;\n\n    dep = p = head\
    \ = tin = tout = v_to_e = vi(n);\n    sz = vi(n, 1);\n\n    vi mx_child_sz(n,\
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
    \ }\n};\n#line 8 \"test/vertex_set_path_composite.test.cpp\"\n\nusing am = affine_sum<mint>;\n\
    \nam::T R_Top(const am::T &a, const am::T &b) { return am::T{a[0] * b[0], b[1]\
    \ * a[0] + a[1]}; }\n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\
    \n  int n, q; cin >> n >> q;\n  vc<array<mint, 2>> init(n);\n  for(auto &[a, b]\
    \ : init)\n    cin >> a >> b;\n  vc<pii> e(n - 1);\n  for(auto &[u, v] : e)\n\
    \    cin >> u >> v;\n\n  HLD hld(std::move(e));\n  init = hld.reorder_init(std::move(init));\n\
    \  segment_tree<am::T, am::Tid, R_Top> st_rev(init);\n  segment_tree<am::T, am::Tid,\
    \ am::Top> st(init);\n  while(q--) {\n    int op; cin >> op;\n    if (op == 0)\
    \ {\n      int p, c, d; cin >> p >> c >> d;\n      st.set(hld.query_point(p),\
    \ am::M{c, d});\n      st_rev.set(hld.query_point(p), am::M{c, d});\n    } else\
    \ {\n      int u, v, x; cin >> u >> v >> x;\n      am::T prod = am::T{1, 0};\n\
    \      for(auto [l, r] : hld.query_path_non_commutative(u, v)) {\n        if (l\
    \ < r) prod = am::Top(prod, st.query(l, r));\n        else prod = am::Top(prod,\
    \ st_rev.query(r, l));\n      }\n      cout << prod[0] * x + prod[1] << '\\n';\n\
    \    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/Montgomery_modint.cpp\"\
    \n#include \"../segtree/segment_tree.cpp\"\n#include \"../acted_monoid/affine_sum.cpp\"\
    \n#include \"../tree/HLD.cpp\"\n\nusing am = affine_sum<mint>;\n\nam::T R_Top(const\
    \ am::T &a, const am::T &b) { return am::T{a[0] * b[0], b[1] * a[0] + a[1]}; }\n\
    \nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin\
    \ >> n >> q;\n  vc<array<mint, 2>> init(n);\n  for(auto &[a, b] : init)\n    cin\
    \ >> a >> b;\n  vc<pii> e(n - 1);\n  for(auto &[u, v] : e)\n    cin >> u >> v;\n\
    \n  HLD hld(std::move(e));\n  init = hld.reorder_init(std::move(init));\n  segment_tree<am::T,\
    \ am::Tid, R_Top> st_rev(init);\n  segment_tree<am::T, am::Tid, am::Top> st(init);\n\
    \  while(q--) {\n    int op; cin >> op;\n    if (op == 0) {\n      int p, c, d;\
    \ cin >> p >> c >> d;\n      st.set(hld.query_point(p), am::M{c, d});\n      st_rev.set(hld.query_point(p),\
    \ am::M{c, d});\n    } else {\n      int u, v, x; cin >> u >> v >> x;\n      am::T\
    \ prod = am::T{1, 0};\n      for(auto [l, r] : hld.query_path_non_commutative(u,\
    \ v)) {\n        if (l < r) prod = am::Top(prod, st.query(l, r));\n        else\
    \ prod = am::Top(prod, st_rev.query(r, l));\n      }\n      cout << prod[0] *\
    \ x + prod[1] << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/Montgomery_modint.cpp
  - segtree/segment_tree.cpp
  - acted_monoid/affine_sum.cpp
  - tree/HLD.cpp
  isVerificationFile: true
  path: test/vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2026-09-03 11:20:30+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_set_path_composite.test.cpp
- /verify/test/vertex_set_path_composite.test.cpp.html
title: test/vertex_set_path_composite.test.cpp
---
