---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':question:'
    path: modint/Montgomery_modint.cpp
    title: modint/Montgomery_modint.cpp
  - icon: ':question:'
    path: poly/FPS.cpp
    title: poly/FPS.cpp
  - icon: ':question:'
    path: poly/NTT.cpp
    title: poly/NTT.cpp
  - icon: ':heavy_check_mark:'
    path: setfunc/fast_subset_transform.cpp
    title: setfunc/fast_subset_transform.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/subset_convolution
    links:
    - https://judge.yosupo.jp/problem/subset_convolution
  bundledCode: "#line 1 \"test/subset_convolution.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\
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
    \ algorithm_extend;\n#line 1 \"modint/Montgomery_modint.cpp\"\n//reference: https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
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
    \ = Montgomery_modint<998'244'353>;\n#line 1 \"poly/NTT.cpp\"\n//reference: https://judge.yosupo.jp/submission/69896\n\
    //remark: MOD = 2^K * C + 1, R is a primitive root modulo MOD\n//remark: a.size()\
    \ <= 2^K must be satisfied\n//some common modulo: 998244353  = 2^23 * 119 + 1,\
    \ R = 3\n//                    469762049  = 2^26 * 7   + 1, R = 3\n//        \
    \            1224736769 = 2^24 * 73  + 1, R = 3\n\ntemplate<int32_t k = 23, int32_t\
    \ c = 119, int32_t r = 3, class Mint = Montgomery_modint<998244353>>\nstruct NTT\
    \ {\n\n  using u32 = uint32_t;\n  static constexpr u32 mod = (1 << k) * c + 1;\n\
    \  static constexpr u32 get_mod() { return mod; }\n\n  static void ntt(vector<Mint>\
    \ &a, bool inverse) {\n    static array<Mint, 30> w, w_inv;\n    if (w[0] == 0)\
    \ {\n      Mint root = 2;\n      while(root.pow((mod - 1) / 2) == 1) root += 1;\n\
    \      for(int i = 0; i < 30; i++)\n        w[i] = -(root.pow((mod - 1) >> (i\
    \ + 2))), w_inv[i] = 1 / w[i];\n    }\n    int n = ssize(a);\n    if (not inverse)\
    \ {\n      for(int m = n; m >>= 1; ) {\n        Mint ww = 1;\n        for(int\
    \ s = 0, l = 0; s < n; s += 2 * m) {\n          for(int i = s, j = s + m; i <\
    \ s + m; i++, j++) {\n            Mint x = a[i], y = a[j] * ww;\n            a[i]\
    \ = x + y, a[j] = x - y;\n          }\n          ww *= w[__builtin_ctz(++l)];\n\
    \        }\n      }\n    } else {\n      for(int m = 1; m < n; m *= 2) {\n   \
    \     Mint ww = 1;\n        for(int s = 0, l = 0; s < n; s += 2 * m) {\n     \
    \     for(int i = s, j = s + m; i < s + m; i++, j++) {\n            Mint x = a[i],\
    \ y = a[j];\n            a[i] = x + y, a[j] = (x - y) * ww;\n          }\n   \
    \       ww *= w_inv[__builtin_ctz(++l)];\n        }\n      }\n      Mint inv =\
    \ 1 / Mint(n);\n      for(Mint &x : a) x *= inv;\n    }\n  }\n\n  static vector<Mint>\
    \ conv(vector<Mint> a, vector<Mint> b) {\n    if (a.empty() or b.empty()) return\
    \ {};\n    int sz = ssize(a) + ssize(b) - 1;\n    int n = bit_ceil((u32)sz);\n\
    \n    a.resize(n, 0);\n    ntt(a, false);\n    b.resize(n, 0);\n    ntt(b, false);\n\
    \n    for(int i = 0; i < n; i++)\n      a[i] *= b[i];\n\n    ntt(a, true);\n\n\
    \    a.resize(sz);\n\n    return a;\n  }\n};\n#line 1 \"poly/FPS.cpp\"\n//#include\
    \ \"modint/Montgomery_modint.cpp\"\n//#include \"poly/NTT.cpp\"\n\n//lagrange\
    \ inversion formula:\n//  let f(x) be composition inverse of g(x) (i.e. f(g(x))\
    \ = x) and [x^0]f(x) = [x^0]g(x) = 0, [x^1]f(x) != 0, [x^1]g(x) != 0, then\n//\
    \  [x^n]g(x)^k = k/n [x^{n - k}] (x / f(x))^n\n//  [x^n]g(x) = 1/n [x^{n - 1}]\
    \ (x / f(x))^n (for k = 1)\n\ntemplate<class Mint>\nstruct FPS : vector<Mint>\
    \ {\n\n  static function<void(vector<Mint>&, bool)> dft;\n  static function<vector<Mint>(vector<Mint>,\
    \ vector<Mint>)> conv;\n\n  FPS(vector<Mint> v) : vector<Mint>(v) {}\n\n  using\
    \ vector<Mint>::vector;\n  FPS& operator+=(FPS b) {\n    if (ssize(*this) < ssize(b))\
    \ this -> resize(ssize(b), 0);\n    for(int i = 0; i < ssize(b); i++)\n      (*this)[i]\
    \ += b[i];\n    return *this;\n  }\n\n  FPS& operator-=(FPS b) {\n    if (ssize(*this)\
    \ < ssize(b)) this -> resize(ssize(b), 0);\n    for(int i = 0; i < ssize(b); i++)\n\
    \      (*this)[i] -= b[i];\n    return *this;\n  }\n\n  FPS& operator*=(FPS b)\
    \ {\n    auto c = conv(*this, b);\n    this -> resize(size(c));\n    copy(c.begin(),\
    \ c.end(), this -> begin());\n    return *this;\n  }\n\n  FPS& operator*=(Mint\
    \ b) {\n    for(int i = 0; i < ssize(*this); i++)\n      (*this)[i] *= b;\n  \
    \  return *this;\n  }\n\n  FPS& operator/=(Mint b) {\n    b = Mint(1) / b;\n \
    \   for(int i = 0; i < ssize(*this); i++)\n      (*this)[i] *= b;\n    return\
    \ *this;\n  }\n\n  FPS& operator<<=(int x) {\n    this -> resize(ssize(*this)\
    \ + x, Mint(0));\n    ranges::rotate(*this, this -> end() - x);\n    return *this;\n\
    \  }\n\n  FPS& operator>>=(int x) {\n    if (x >= ssize(*this)) {\n      this\
    \ -> resize(1);\n      (*this)[0] = 0;\n    } else {\n      ranges::rotate(*this,\
    \ this -> begin() + x);\n      this -> resize(ssize(*this) - x);\n    }\n    return\
    \ *this;\n  }\n\n  FPS shrink() {\n    FPS F = *this;\n    int size = ssize(F);\n\
    \    while(size and F[size - 1] == 0) size -= 1;\n    F.resize(size);\n    return\
    \ F;\n  }\n\n  FPS rev() {\n    FPS F = *this;\n    reverse(F.begin(), F.end());\n\
    \    return F;\n  }\n\n  FPS integral() {\n    if (this -> empty()) return {0};\n\
    \    vector<Mint> Inv(ssize(*this) + 1);\n    Inv[1] = 1;\n    for(int i = 2;\
    \ i < ssize(Inv); i++)\n      Inv[i] = (Mint::get_mod() - Mint::get_mod() / i)\
    \ * Inv[Mint::get_mod() % i];\n    FPS Q(ssize(*this) + 1, 0);\n    for(int i\
    \ = 0; i < ssize(*this); i++)\n      Q[i + 1] = (*this)[i] * Inv[i + 1];\n   \
    \ return Q;\n  }\n\n  FPS derivative() {\n    assert(!this -> empty());\n    FPS\
    \ Q(ssize(*this) - 1);\n    for(int i = 1; i < ssize(*this); i++)\n      Q[i -\
    \ 1] = (*this)[i] * i;\n    return Q;\n  }\n\n  Mint eval(Mint x) {\n    Mint\
    \ base = 1, res = 0;\n    for(int i = 0; i < ssize(*this); i++, base *= x)\n \
    \     res += (*this)[i] * base;\n    return res;\n  }\n\n  FPS inv(int k) { //\
    \ 1 / FPS (mod x^k)\n    assert(!this -> empty() and (*this)[0] != 0);\n    FPS\
    \ Q(1, 1 / (*this)[0]);\n    for(int i = 1; (1 << (i - 1)) < k; i++) {\n     \
    \ FPS P = (*this);\n      P.resize(1 << i, 0);\n      Q = Q * (FPS(1, 2) - P *\
    \ Q);\n      Q.resize(1 << i, 0);\n    }\n    Q.resize(k);\n    return Q;\n  }\n\
    \n  array<FPS, 2> div(FPS G) {\n    FPS F = this -> shrink();\n    G = G.shrink();\n\
    \    assert(!G.empty());\n    if (ssize(G) > ssize(F))\n      return {{{}, F}};\n\
    \    int n = ssize(F) - ssize(G) + 1;\n    auto FR = F, GR = G;\n    ranges::reverse(FR);\n\
    \    ranges::reverse(GR);\n    FPS Q = FR * GR.inv(n);\n    Q.resize(n);\n   \
    \ ranges::reverse(Q);\n    return {Q, (F - G * Q).shrink()};\n  }\n\n  FPS log(int\
    \ k) {\n    assert(!this -> empty() and (*this)[0] == 1);\n    FPS Q = *this;\n\
    \    Q = (Q.derivative() * Q.inv(k));\n    Q.resize(k - 1);\n    return Q.integral();\n\
    \  }\n\n  FPS exp(int k) {\n    assert(!this -> empty() and (*this)[0] == 0);\n\
    \    FPS Q(1, 1);\n    for(int i = 1; (1 << (i - 1)) < k; i++) {\n      FPS P\
    \ = (*this);\n      P.resize(1 << i, 0);\n      Q = Q * (FPS(1, 1) + P - Q.log(1\
    \ << i));\n      Q.resize(1 << i, 0);\n    }\n    Q.resize(k);\n    return Q;\n\
    \  }\n\n  FPS pow(ll idx, int k) {\n    if (idx == 0) {\n      FPS res(k, 0);\n\
    \      res[0] = 1;\n      return res;\n    }\n    for(int i = 0; i < ssize(*this)\
    \ and i * idx < k; i++) {\n      if ((*this)[i] != 0) {\n        Mint Inv = 1\
    \ / (*this)[i];\n        FPS Q(ssize(*this) - i);\n        for(int j = i; j <\
    \ ssize(*this); j++)\n          Q[j - i] = (*this)[j] * Inv;\n        Q = (Q.log(k)\
    \ * idx).exp(k);\n        FPS Q2(k, 0);\n        Mint Pow = (*this)[i].pow(idx);\n\
    \        for(int j = 0; j + i * idx < k; j++)\n          Q2[j + i * idx] = Q[j]\
    \ * Pow;\n        return Q2;\n      }\n    } \n    return FPS(k, 0);\n  }\n\n\
    \  FPS pow(ll idx) {\n    int mxDeg = (ssize(*this) - 1) * idx;\n    FPS a = (*this);\n\
    \    a.resize(bit_ceil((unsigned)(mxDeg + 1)));\n    dft(a, false);\n    for(Mint\
    \ &x : a) x = x.pow(idx);\n    dft(a, true);\n    return FPS(a.begin(), a.begin()\
    \ + mxDeg + 1);\n  }\n\n  vector<Mint> multieval(vector<Mint> xs) {\n    int n\
    \ = ssize(xs);\n    vector<FPS> data(2 * n);\n    for(int i = 0; i < n; i++)\n\
    \      data[n + i] = {-xs[i], 1};\n    for(int i = n - 1; i > 0; i--)\n      data[i]\
    \ = data[i << 1] * data[i << 1 | 1];\n    data[1] = (this -> div(data[1]))[1];\n\
    \    for(int i = 1; i < n; i++) {\n      data[i << 1] = data[i].div(data[i <<\
    \ 1])[1];\n      data[i << 1 | 1] = data[i].div(data[i << 1 | 1])[1];\n    }\n\
    \    vector<Mint> res(n);\n    for(int i = 0; i < n; i++)\n      res[i] = data[n\
    \ + i].empty() ? 0 : data[n + i][0];\n    return res;\n  }\n\n  static vector<Mint>\
    \ interpolate(vector<Mint> xs, vector<Mint> ys) {\n    assert(ssize(xs) == ssize(ys));\n\
    \    int n = ssize(xs);\n    vector<FPS> data(2 * n), res(2 * n);\n    for(int\
    \ i = 0; i < n; i++)\n      data[n + i] = {-xs[i], 1};\n    for(int i = n - 1;\
    \ i > 0; i--)\n      data[i] = data[i << 1] * data[i << 1 | 1];\n    res[1] =\
    \ data[1].derivative().div(data[1])[1];\n    for(int i = 1; i < n; i++) {\n  \
    \    res[i << 1] = res[i].div(data[i << 1])[1];\n      res[i << 1 | 1] = res[i].div(data[i\
    \ << 1 | 1])[1];\n    }\n    for(int i = 0; i < n; i++)\n      res[n + i][0] =\
    \ ys[i] / res[n + i][0];\n    for(int i = n - 1; i > 0; i--)\n      res[i] = res[i\
    \ << 1] * data[i << 1 | 1] + res[i << 1 | 1] * data[i << 1];\n    return res[1];\n\
    \  }\n\n  static FPS allProd(vector<FPS> &fs) {\n    if (fs.empty()) return {1};\n\
    \    auto dfs = [&](int l, int r, auto &self) -> FPS {\n      if (l + 1 == r)\n\
    \        return fs[l];\n      else\n        return self(l, (l + r) / 2, self)\
    \ * self((l + r) / 2, r, self);\n    };\n    return dfs(0, ssize(fs), dfs);\n\
    \  }\n\n  static array<FPS, 2> fracSum(vector<array<FPS, 2>> &fs) {\n    if (fs.empty())\
    \ return {FPS{1}, {1}};\n    auto dfs = [&](int l, int r, auto &self) -> array<FPS,\
    \ 2> {\n      if (l + 1 == r)\n        return fs[l];\n      int mid = (l + r)\
    \ / 2;\n      auto L = self(l, mid, self), R = self(mid, r, self);\n      return\
    \ {FPS{L[0] * R[1] + L[1] * R[0]}, {L[1] * R[1]}};\n    };\n    return dfs(0,\
    \ ssize(fs), dfs);\n  }\n\n  friend FPS operator+(FPS a, FPS b) { return a +=\
    \ b; }\n  friend FPS operator-(FPS a, FPS b) { return a -= b; }\n  friend FPS\
    \ operator*(FPS a, FPS b) { return a *= b; }\n  friend FPS operator*(FPS a, Mint\
    \ b) { return a *= b; }\n  friend FPS operator/(FPS a, Mint b) { return a /= b;\
    \ }\n  friend FPS operator<<(FPS a, int x) { return a <<= x; }\n  friend FPS operator>>(FPS\
    \ a, int x) { return a >>= x; }\n};\n\nNTT ntt;\nusing fps = FPS<mint>;\ntemplate<>\n\
    function<vector<mint>(vector<mint>, vector<mint>)> fps::conv = ntt.conv;\ntemplate<>\n\
    function<void(vector<mint>&, bool)> fps::dft = ntt.ntt;\n#line 1 \"setfunc/fast_subset_transform.cpp\"\
    \n//#include<poly/FPS.cpp>\n\ntemplate<class FPS>\nvector<FPS> FST(FPS f) {\n\
    \  assert(popcount(f.size()) == 1);\n  int n = bit_width(f.size()) - 1;\n  vector<FPS>\
    \ fHat(1 << n, FPS(n + 1));\n  for(unsigned i = 0; i < (1 << n); i++)\n    fHat[i][popcount(i)]\
    \ = f[i];\n\n  for(int k = 0; k < n; k++)\n    for(int i = 0; i < (1 << n); i++)\n\
    \      if (!(i >> k & 1))\n        for(int j = 0; j <= n; j++)\n          fHat[i|1<<k][j]\
    \ += fHat[i][j];\n\n  return fHat;\n}\n\ntemplate<class FPS>\nFPS FSTinv(vector<FPS>\
    \ fHat) {\n  int n = bit_width(fHat.size()) - 1;\n  for(int k = 0; k < n; k++)\n\
    \    for(int i = 0; i < (1 << n); i++)\n      if (!(i >> k & 1))\n        for(int\
    \ j = 0; j <= n; j++)\n          fHat[i|1<<k][j] -= fHat[i][j];\n\n  FPS f(1 <<\
    \ n);\n  for(unsigned i = 0; i < (1 << n); i++)\n    f[i] = fHat[i][popcount(i)];\n\
    \n  return f;\n}\n\ntemplate<class FPS>\nFPS conv(FPS f, FPS g) {\n  assert(ssize(f)\
    \ == ssize(g));\n  auto fHat = FST(f), gHat = FST(g);\n  for(int i = 0; i < ssize(fHat);\
    \ i++) {\n    fHat[i] *= gHat[i];\n    fHat[i].resize(ssize(gHat[i]));\n  }\n\
    \  return FSTinv(fHat);\n}\n\n/* OMG this is so slowwwwwwwwwwwwwwwww\nFPS subsetPow(FPS\
    \ f, long long idx) {\n  int n = __lg(f.size());\n  vector<FPS> fHat = FST(f);\n\
    \  for(int i = 0; i < fHat.size(); i++)\n    fHat[i] = fHat[i].pow(idx, n + 1);\n\
    \  f = FSTinv(fHat);\n  return f;\n}\n*/\n#line 8 \"test/subset_convolution.test.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n; cin\
    \ >> n;\n  fps a(1 << n), b(1 << n);\n  for(mint &x : a)\n    cin >> x;\n  for(mint\
    \ &x : b)\n    cin >> x;\n\n  cout << conv(a, b) << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n\n\
    #include \"../default/t.cpp\"\n#include \"../modint/Montgomery_modint.cpp\"\n\
    #include \"../poly/NTT.cpp\"\n#include \"../poly/FPS.cpp\"\n#include \"../setfunc/fast_subset_transform.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n; cin\
    \ >> n;\n  fps a(1 << n), b(1 << n);\n  for(mint &x : a)\n    cin >> x;\n  for(mint\
    \ &x : b)\n    cin >> x;\n\n  cout << conv(a, b) << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/Montgomery_modint.cpp
  - poly/NTT.cpp
  - poly/FPS.cpp
  - setfunc/fast_subset_transform.cpp
  isVerificationFile: true
  path: test/subset_convolution.test.cpp
  requiredBy: []
  timestamp: '2026-09-02 20:44:03+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/subset_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/subset_convolution.test.cpp
- /verify/test/subset_convolution.test.cpp.html
title: test/subset_convolution.test.cpp
---
