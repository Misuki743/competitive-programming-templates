---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: string/longest_common_substring.cpp
    title: string/longest_common_substring.cpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.cpp
    title: string/suffix_array.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/longest_common_substring
    links:
    - https://judge.yosupo.jp/problem/longest_common_substring
  bundledCode: "#line 1 \"test/longest_common_substring.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/longest_common_substring\"\n\n#line 1 \"default/t.cpp\"\
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
    \ namespace sieve_of_Eratosthenes;\n#line 1 \"string/suffix_array.cpp\"\n//source:\
    \ AtCoderLibrary(ACL)\n// usage: suffix_array(vector<> s)\n//        lcp_array(vector<>\
    \ s, vector<int> sa)\n\nstd::vector<int> sa_naive(const std::vector<int>& s) {\n\
    \    int n = int(s.size());\n    std::vector<int> sa(n);\n    std::iota(sa.begin(),\
    \ sa.end(), 0);\n    std::sort(sa.begin(), sa.end(), [&](int l, int r) {\n   \
    \     if (l == r) return false;\n        while (l < n && r < n) {\n          \
    \  if (s[l] != s[r]) return s[l] < s[r];\n            l++;\n            r++;\n\
    \        }\n        return l == n;\n    });\n    return sa;\n}\n\nstd::vector<int>\
    \ sa_doubling(const std::vector<int>& s) {\n    int n = int(s.size());\n    std::vector<int>\
    \ sa(n), rnk = s, tmp(n);\n    std::iota(sa.begin(), sa.end(), 0);\n    for (int\
    \ k = 1; k < n; k *= 2) {\n        auto cmp = [&](int x, int y) {\n          \
    \  if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];\n            int rx = x + k <\
    \ n ? rnk[x + k] : -1;\n            int ry = y + k < n ? rnk[y + k] : -1;\n  \
    \          return rx < ry;\n        };\n        std::sort(sa.begin(), sa.end(),\
    \ cmp);\n        tmp[sa[0]] = 0;\n        for (int i = 1; i < n; i++) {\n    \
    \        tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);\n    \
    \    }\n        std::swap(tmp, rnk);\n    }\n    return sa;\n}\n\n// SA-IS, linear-time\
    \ suffix array construction\n// Reference:\n// G. Nong, S. Zhang, and W. H. Chan,\n\
    // Two Efficient Algorithms for Linear Time Suffix Array Construction\ntemplate\
    \ <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>\nstd::vector<int> sa_is(const\
    \ std::vector<int>& s, int upper) {\n    int n = int(s.size());\n    if (n ==\
    \ 0) return {};\n    if (n == 1) return {0};\n    if (n == 2) {\n        if (s[0]\
    \ < s[1]) {\n            return {0, 1};\n        } else {\n            return\
    \ {1, 0};\n        }\n    }\n    if (n < THRESHOLD_NAIVE) {\n        return sa_naive(s);\n\
    \    }\n    if (n < THRESHOLD_DOUBLING) {\n        return sa_doubling(s);\n  \
    \  }\n\n    std::vector<int> sa(n);\n    std::vector<bool> ls(n);\n    for (int\
    \ i = n - 2; i >= 0; i--) {\n        ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] :\
    \ (s[i] < s[i + 1]);\n    }\n    std::vector<int> sum_l(upper + 1), sum_s(upper\
    \ + 1);\n    for (int i = 0; i < n; i++) {\n        if (!ls[i]) {\n          \
    \  sum_s[s[i]]++;\n        } else {\n            sum_l[s[i] + 1]++;\n        }\n\
    \    }\n    for (int i = 0; i <= upper; i++) {\n        sum_s[i] += sum_l[i];\n\
    \        if (i < upper) sum_l[i + 1] += sum_s[i];\n    }\n\n    auto induce =\
    \ [&](const std::vector<int>& lms) {\n        std::fill(sa.begin(), sa.end(),\
    \ -1);\n        std::vector<int> buf(upper + 1);\n        std::copy(sum_s.begin(),\
    \ sum_s.end(), buf.begin());\n        for (auto d : lms) {\n            if (d\
    \ == n) continue;\n            sa[buf[s[d]]++] = d;\n        }\n        std::copy(sum_l.begin(),\
    \ sum_l.end(), buf.begin());\n        sa[buf[s[n - 1]]++] = n - 1;\n        for\
    \ (int i = 0; i < n; i++) {\n            int v = sa[i];\n            if (v >=\
    \ 1 && !ls[v - 1]) {\n                sa[buf[s[v - 1]]++] = v - 1;\n         \
    \   }\n        }\n        std::copy(sum_l.begin(), sum_l.end(), buf.begin());\n\
    \        for (int i = n - 1; i >= 0; i--) {\n            int v = sa[i];\n    \
    \        if (v >= 1 && ls[v - 1]) {\n                sa[--buf[s[v - 1] + 1]] =\
    \ v - 1;\n            }\n        }\n    };\n\n    std::vector<int> lms_map(n +\
    \ 1, -1);\n    int m = 0;\n    for (int i = 1; i < n; i++) {\n        if (!ls[i\
    \ - 1] && ls[i]) {\n            lms_map[i] = m++;\n        }\n    }\n    std::vector<int>\
    \ lms;\n    lms.reserve(m);\n    for (int i = 1; i < n; i++) {\n        if (!ls[i\
    \ - 1] && ls[i]) {\n            lms.push_back(i);\n        }\n    }\n\n    induce(lms);\n\
    \n    if (m) {\n        std::vector<int> sorted_lms;\n        sorted_lms.reserve(m);\n\
    \        for (int v : sa) {\n            if (lms_map[v] != -1) sorted_lms.push_back(v);\n\
    \        }\n        std::vector<int> rec_s(m);\n        int rec_upper = 0;\n \
    \       rec_s[lms_map[sorted_lms[0]]] = 0;\n        for (int i = 1; i < m; i++)\
    \ {\n            int l = sorted_lms[i - 1], r = sorted_lms[i];\n            int\
    \ end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;\n            int end_r\
    \ = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;\n            bool same = true;\n\
    \            if (end_l - l != end_r - r) {\n                same = false;\n  \
    \          } else {\n                while (l < end_l) {\n                   \
    \ if (s[l] != s[r]) {\n                        break;\n                    }\n\
    \                    l++;\n                    r++;\n                }\n     \
    \           if (l == n || s[l] != s[r]) same = false;\n            }\n       \
    \     if (!same) rec_upper++;\n            rec_s[lms_map[sorted_lms[i]]] = rec_upper;\n\
    \        }\n\n        auto rec_sa =\n            sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s,\
    \ rec_upper);\n\n        for (int i = 0; i < m; i++) {\n            sorted_lms[i]\
    \ = lms[rec_sa[i]];\n        }\n        induce(sorted_lms);\n    }\n    return\
    \ sa;\n}\n\nstd::vector<int> suffix_array(const std::vector<int>& s, int upper)\
    \ {\n    assert(0 <= upper);\n    for (int d : s) {\n        assert(0 <= d &&\
    \ d <= upper);\n    }\n    auto sa = sa_is(s, upper);\n    return sa;\n}\n\ntemplate\
    \ <class T> std::vector<int> suffix_array(const std::vector<T>& s) {\n    int\
    \ n = int(s.size());\n    std::vector<int> idx(n);\n    iota(idx.begin(), idx.end(),\
    \ 0);\n    sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r];\
    \ });\n    std::vector<int> s2(n);\n    int now = 0;\n    for (int i = 0; i <\
    \ n; i++) {\n        if (i && s[idx[i - 1]] != s[idx[i]]) now++;\n        s2[idx[i]]\
    \ = now;\n    }\n    return sa_is(s2, now);\n}\n\nstd::vector<int> suffix_array(const\
    \ std::string& s) {\n    int n = int(s.size());\n    std::vector<int> s2(n);\n\
    \    for (int i = 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n    return sa_is(s2,\
    \ 255);\n}\n\n// Reference:\n// T. Kasai, G. Lee, H. Arimura, S. Arikawa, and\
    \ K. Park,\n// Linear-Time Longest-Common-Prefix Computation in Suffix Arrays\
    \ and Its\n// Applications\ntemplate <class T>\nstd::vector<int> lcp_array(const\
    \ std::vector<T>& s,\n                           const std::vector<int>& sa) {\n\
    \    int n = int(s.size());\n    assert(n >= 1);\n    std::vector<int> rnk(n);\n\
    \    for (int i = 0; i < n; i++) {\n        rnk[sa[i]] = i;\n    }\n    std::vector<int>\
    \ lcp(n - 1);\n    int h = 0;\n    for (int i = 0; i < n; i++) {\n        if (h\
    \ > 0) h--;\n        if (rnk[i] == 0) continue;\n        int j = sa[rnk[i] - 1];\n\
    \        for (; j + h < n && i + h < n; h++) {\n            if (s[j + h] != s[i\
    \ + h]) break;\n        }\n        lcp[rnk[i] - 1] = h;\n    }\n    return lcp;\n\
    }\n\nstd::vector<int> lcp_array(const std::string& s, const std::vector<int>&\
    \ sa) {\n    int n = int(s.size());\n    std::vector<int> s2(n);\n    for (int\
    \ i = 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n    return lcp_array(s2,\
    \ sa);\n}\n#line 1 \"string/longest_common_substring.cpp\"\n//#include<string/suffixArray.cpp>\n\
    \narray<int, 4> longest_common_substring(string s, string t) {\n  t = s + '#'\
    \ + t;\n  auto sa = suffix_array(t);\n  auto lcp = lcp_array(t, sa);\n  array<int,\
    \ 4> res = {};\n  for(int i = 0; i < ssize(lcp); i++) {\n    if (lcp[i] <= res[1]\
    \ - res[0]) continue;\n    if (sa[i] < ssize(s) and sa[i + 1] > ssize(s))\n  \
    \    res = {sa[i], sa[i] + lcp[i], sa[i + 1] - (int)(ssize(s) + 1), sa[i + 1]\
    \ - (int)(ssize(s) + 1) + lcp[i]};\n    else if (sa[i] > ssize(s) and sa[i + 1]\
    \ < ssize(s))\n      res = {sa[i + 1], sa[i + 1] + lcp[i], sa[i] - (int)(ssize(s)\
    \ + 1), sa[i] - (int)(ssize(s) + 1) + lcp[i]};\n  }\n  return res;\n}\n#line 6\
    \ \"test/longest_common_substring.test.cpp\"\n\nint main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  string s, t; cin >> s >> t;\n  cout << longest_common_substring(s,\
    \ t) << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_common_substring\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../string/suffix_array.cpp\"\n#include\
    \ \"../string/longest_common_substring.cpp\"\n\nint main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  string s, t; cin >> s >> t;\n  cout << longest_common_substring(s,\
    \ t) << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - string/suffix_array.cpp
  - string/longest_common_substring.cpp
  isVerificationFile: true
  path: test/longest_common_substring.test.cpp
  requiredBy: []
  timestamp: '2026-09-03 11:20:30+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/longest_common_substring.test.cpp
layout: document
redirect_from:
- /verify/test/longest_common_substring.test.cpp
- /verify/test/longest_common_substring.test.cpp.html
title: test/longest_common_substring.test.cpp
---
