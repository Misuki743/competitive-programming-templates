---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: enumerate/enumerate_bit.cpp
    title: enumerate/enumerate_bit.cpp
  - icon: ':x:'
    path: enumerate/enumerate_twelvefold.cpp
    title: enumerate/enumerate_twelvefold.cpp
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
  bundledCode: "#line 1 \"test/mytest_enumerate_twelvefold.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"default/t.cpp\"\n#include<bits/stdc++.h>\n\
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
    \  void psum(R &&v, F f) {\n    if (!ranges::empty(v))\n      for(T p = *v.begin();\
    \ T &x : v | views::drop(1))\n        x = p = f(p, x);\n  }\n\n  template<ranges::forward_range\
    \ R, class T = ranges::range_value_t<R>>\n  void psum(R &&v) {\n    if (!ranges::empty(v))\n\
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
    \ algorithm_extend;\n#line 1 \"enumerate/enumerate_bit.cpp\"\n\ntemplate<typename\
    \ F, typename INT>\nrequires invocable<F, INT>\nvoid enumerate_subset(INT msk,\
    \ F f) {\n  for(INT x = msk; x > 0; x = (x - 1) & msk)\n    f(x);\n  f(0);\n}\n\
    #line 1 \"enumerate/enumerate_twelvefold.cpp\"\n//#include \"enumerate/bit.cpp\"\
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
    \  p.pop_back();\n      }\n    }\n  };\n  dfs(n, dfs);\n}\n#line 6 \"test/mytest_enumerate_twelvefold.test.cpp\"\
    \n\nvoid a_plus_b() {\n  int a, b; cin >> a >> b;\n  cout << a + b << '\\n';\n\
    }\n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  { //[0..n-1]^k\n\
    \    for(int n = 0; n <= 7; n++) {\n      int cnt = 1;\n      for(int k = 0; k\
    \ <= 7; k++, cnt *= n) {\n        vector<vector<int>> S;\n        enumerate_cartesian_power(n,\
    \ k, [&](vector<int> a) {\n          assert(ssize(a) == k);\n          assert(a.empty()\
    \ or ranges::min(a) >= 0);\n          assert(a.empty() or ranges::max(a) < n);\n\
    \          S.push_back(std::move(a));\n        });\n        assert(cnt == ssize(S));\n\
    \        unique(S);\n        assert(cnt == ssize(S));\n      }\n    }\n  }\n\n\
    \  { //permutation\n    int cnt = 1;\n    for(int n = 0; n <= 9; cnt *= ++n) {\n\
    \      vector<vector<int>> S;\n      enumerate_permutation(n, [&](vector<int>\
    \ p) {\n        assert(ssize(p) == n);\n        S.push_back(p);\n        ranges::sort(p);\n\
    \        for(int i = 0; i < n; i++)\n          assert(p[i] == i);\n      });\n\
    \      assert(cnt == ssize(S));\n      unique(S);\n      assert(cnt == ssize(S));\n\
    \    }\n  }\n\n  { //combination\n    int C[17][17] = {};\n    for(int i = 0;\
    \ i < 17; i++)\n      C[i][0] = C[i][i] = 1;\n    for(int i = 2; i < 17; i++)\n\
    \      for(int j = 1; j < i; j++)\n        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];\n\
    \n    for(int n = 0; n < 17; n++) {\n      for(int k = 0; k < 17; k++) {\n   \
    \     vector<vector<int>> S;\n        enumerate_combination(n, k, [&](vector<int>\
    \ a) {\n          assert(ssize(a) == k);\n          assert(a.empty() or ranges::min(a)\
    \ >= 0);\n          assert(a.empty() or ranges::max(a) < n);\n          S.push_back(a);\n\
    \          unique(a);\n          assert(ssize(a) == k);\n        });\n       \
    \ assert(ssize(S) == C[n][k]);\n        unique(S);\n        assert(ssize(S) ==\
    \ C[n][k]);\n      }\n    }\n  }\n\n  { //set partition\n    int bell[12] = {1,\
    \ 1, 2, 5, 15, 52, 203, 877, 4140, 21147, 115975, 678570};\n    for(int n = 0;\
    \ n < 12; n++) {\n      vector<vector<int>> S;\n      enumerate_set_partition(n,\
    \ [&](vector<int> p) {\n        ranges::sort(p);\n        int msk = 0;\n     \
    \   for(int x : p) {\n          assert((x | ((1 << n) - 1)) == (1 << n) - 1);\n\
    \          assert(x > 0);\n          assert((msk & x) == 0);\n          msk |=\
    \ x;\n        }\n        assert(msk == (1 << n) - 1);\n        S.push_back(std::move(p));\n\
    \      });\n      assert(ssize(S) == bell[n]);\n      unique(S);\n      assert(ssize(S)\
    \ == bell[n]);\n    }\n  }\n\n  { //f[0] + f[1] + ... + f[n - 1] = sum, f[i] >=\
    \ 0\n    int C[17][17] = {};\n    for(int i = 0; i < 17; i++)\n      C[i][0] =\
    \ C[i][i] = 1;\n    for(int i = 2; i < 17; i++)\n      for(int j = 1; j < i; j++)\n\
    \        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];\n\n    for(int n = 0; n < 17;\
    \ n++) {\n      for(int sum = 0; n - 1 + sum < 17; sum++) {\n        vector<vector<int>>\
    \ S;\n        enumerate_multisubset(n, sum, [&](vector<int> f) {\n          assert(ssize(f)\
    \ == n);\n          assert(f.empty() or ranges::min(f) >= 0);\n          assert(accumulate(f.begin(),\
    \ f.end(), 0) == sum);\n          S.emplace_back(f);\n        });\n        if\
    \ (n == 0)\n          assert(ssize(S) == (sum == 0));\n        else\n        \
    \  assert(ssize(S) == C[n - 1 + sum][sum]);\n        unique(S);\n        if (n\
    \ == 0)\n          assert(ssize(S) == (sum == 0));\n        else\n          assert(ssize(S)\
    \ == C[n - 1 + sum][sum]);\n      }\n    }\n  }\n\n  { //integer partition\n \
    \   int part[50] = {1, 1, 2, 3, 5, 7, 11, 15, 22, 30, 42, 56, 77, 101, 135, 176,\
    \ 231, 297, 385, 490, 627, 792, 1002, 1255, 1575, 1958, 2436, 3010, 3718, 4565,\
    \ 5604, 6842, 8349, 10143, 12310, 14883, 17977, 21637, 26015, 31185, 37338, 44583,\
    \ 53174, 63261, 75175, 89134, 105558, 124754, 147273, 173525};\n    for(int n\
    \ = 0; n < 50; n++) {\n      vector<vector<int>> S;\n      enumerate_integer_partition(n,\
    \ [&](vector<int> p) {\n        assert(p.empty() or ranges::min(p) > 0);\n   \
    \     assert(ranges::is_sorted(p | views::reverse));\n        assert(accumulate(p.begin(),\
    \ p.end(), 0) == n);\n        S.emplace_back(std::move(p));\n      });\n     \
    \ assert(ssize(S) == part[n]);\n      unique(S);\n      assert(ssize(S) == part[n]);\n\
    \    }\n  }\n\n  a_plus_b();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../default/t.cpp\"\n#include \"../enumerate/enumerate_bit.cpp\"\n#include \"../enumerate/enumerate_twelvefold.cpp\"\
    \n\nvoid a_plus_b() {\n  int a, b; cin >> a >> b;\n  cout << a + b << '\\n';\n\
    }\n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  { //[0..n-1]^k\n\
    \    for(int n = 0; n <= 7; n++) {\n      int cnt = 1;\n      for(int k = 0; k\
    \ <= 7; k++, cnt *= n) {\n        vector<vector<int>> S;\n        enumerate_cartesian_power(n,\
    \ k, [&](vector<int> a) {\n          assert(ssize(a) == k);\n          assert(a.empty()\
    \ or ranges::min(a) >= 0);\n          assert(a.empty() or ranges::max(a) < n);\n\
    \          S.push_back(std::move(a));\n        });\n        assert(cnt == ssize(S));\n\
    \        unique(S);\n        assert(cnt == ssize(S));\n      }\n    }\n  }\n\n\
    \  { //permutation\n    int cnt = 1;\n    for(int n = 0; n <= 9; cnt *= ++n) {\n\
    \      vector<vector<int>> S;\n      enumerate_permutation(n, [&](vector<int>\
    \ p) {\n        assert(ssize(p) == n);\n        S.push_back(p);\n        ranges::sort(p);\n\
    \        for(int i = 0; i < n; i++)\n          assert(p[i] == i);\n      });\n\
    \      assert(cnt == ssize(S));\n      unique(S);\n      assert(cnt == ssize(S));\n\
    \    }\n  }\n\n  { //combination\n    int C[17][17] = {};\n    for(int i = 0;\
    \ i < 17; i++)\n      C[i][0] = C[i][i] = 1;\n    for(int i = 2; i < 17; i++)\n\
    \      for(int j = 1; j < i; j++)\n        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];\n\
    \n    for(int n = 0; n < 17; n++) {\n      for(int k = 0; k < 17; k++) {\n   \
    \     vector<vector<int>> S;\n        enumerate_combination(n, k, [&](vector<int>\
    \ a) {\n          assert(ssize(a) == k);\n          assert(a.empty() or ranges::min(a)\
    \ >= 0);\n          assert(a.empty() or ranges::max(a) < n);\n          S.push_back(a);\n\
    \          unique(a);\n          assert(ssize(a) == k);\n        });\n       \
    \ assert(ssize(S) == C[n][k]);\n        unique(S);\n        assert(ssize(S) ==\
    \ C[n][k]);\n      }\n    }\n  }\n\n  { //set partition\n    int bell[12] = {1,\
    \ 1, 2, 5, 15, 52, 203, 877, 4140, 21147, 115975, 678570};\n    for(int n = 0;\
    \ n < 12; n++) {\n      vector<vector<int>> S;\n      enumerate_set_partition(n,\
    \ [&](vector<int> p) {\n        ranges::sort(p);\n        int msk = 0;\n     \
    \   for(int x : p) {\n          assert((x | ((1 << n) - 1)) == (1 << n) - 1);\n\
    \          assert(x > 0);\n          assert((msk & x) == 0);\n          msk |=\
    \ x;\n        }\n        assert(msk == (1 << n) - 1);\n        S.push_back(std::move(p));\n\
    \      });\n      assert(ssize(S) == bell[n]);\n      unique(S);\n      assert(ssize(S)\
    \ == bell[n]);\n    }\n  }\n\n  { //f[0] + f[1] + ... + f[n - 1] = sum, f[i] >=\
    \ 0\n    int C[17][17] = {};\n    for(int i = 0; i < 17; i++)\n      C[i][0] =\
    \ C[i][i] = 1;\n    for(int i = 2; i < 17; i++)\n      for(int j = 1; j < i; j++)\n\
    \        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];\n\n    for(int n = 0; n < 17;\
    \ n++) {\n      for(int sum = 0; n - 1 + sum < 17; sum++) {\n        vector<vector<int>>\
    \ S;\n        enumerate_multisubset(n, sum, [&](vector<int> f) {\n          assert(ssize(f)\
    \ == n);\n          assert(f.empty() or ranges::min(f) >= 0);\n          assert(accumulate(f.begin(),\
    \ f.end(), 0) == sum);\n          S.emplace_back(f);\n        });\n        if\
    \ (n == 0)\n          assert(ssize(S) == (sum == 0));\n        else\n        \
    \  assert(ssize(S) == C[n - 1 + sum][sum]);\n        unique(S);\n        if (n\
    \ == 0)\n          assert(ssize(S) == (sum == 0));\n        else\n          assert(ssize(S)\
    \ == C[n - 1 + sum][sum]);\n      }\n    }\n  }\n\n  { //integer partition\n \
    \   int part[50] = {1, 1, 2, 3, 5, 7, 11, 15, 22, 30, 42, 56, 77, 101, 135, 176,\
    \ 231, 297, 385, 490, 627, 792, 1002, 1255, 1575, 1958, 2436, 3010, 3718, 4565,\
    \ 5604, 6842, 8349, 10143, 12310, 14883, 17977, 21637, 26015, 31185, 37338, 44583,\
    \ 53174, 63261, 75175, 89134, 105558, 124754, 147273, 173525};\n    for(int n\
    \ = 0; n < 50; n++) {\n      vector<vector<int>> S;\n      enumerate_integer_partition(n,\
    \ [&](vector<int> p) {\n        assert(p.empty() or ranges::min(p) > 0);\n   \
    \     assert(ranges::is_sorted(p | views::reverse));\n        assert(accumulate(p.begin(),\
    \ p.end(), 0) == n);\n        S.emplace_back(std::move(p));\n      });\n     \
    \ assert(ssize(S) == part[n]);\n      unique(S);\n      assert(ssize(S) == part[n]);\n\
    \    }\n  }\n\n  a_plus_b();\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - enumerate/enumerate_bit.cpp
  - enumerate/enumerate_twelvefold.cpp
  isVerificationFile: true
  path: test/mytest_enumerate_twelvefold.test.cpp
  requiredBy: []
  timestamp: '2026-09-02 22:57:23+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest_enumerate_twelvefold.test.cpp
layout: document
redirect_from:
- /verify/test/mytest_enumerate_twelvefold.test.cpp
- /verify/test/mytest_enumerate_twelvefold.test.cpp.html
title: test/mytest_enumerate_twelvefold.test.cpp
---
