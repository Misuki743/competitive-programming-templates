---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: enumerate/enumerate_highly_composite_numbers.cpp
    title: enumerate/enumerate_highly_composite_numbers.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest_enumerate_highly_composite_numbers.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"default/t.cpp\"\
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
    \ namespace sieve_of_Eratosthenes;\n#line 1 \"enumerate/enumerate_highly_composite_numbers.cpp\"\
    \ntemplate<typename F>\nrequires invocable<F, ll, vector<pair<int, int>>>\nvoid\
    \ enumerate_highly_composite_numbers(ll U, F f) {\n  static vi ps;\n  if (ps.empty())\n\
    \    primes(64, [](int p) { ps.eb(p); });\n\n  auto dfs = [&](ll prod, vc<pii>\
    \ pfs, auto &self) -> void {\n    f(prod, pfs);\n\n    int p = ps[ssize(pfs)];\n\
    \    int lim = pfs.empty() ? INT_MAX : pfs.back().second;\n    pfs.eb(p, 0);\n\
    \    while((__int128)prod * p < U and pfs.back().second < lim) {\n      pfs.back().second\
    \ += 1, prod *= p;\n      self(prod, pfs, self);\n    }\n  };\n  dfs(1, {}, dfs);\n\
    }\n#line 5 \"test/mytest_enumerate_highly_composite_numbers.test.cpp\"\n\nvoid\
    \ a_plus_b() {\n  int a, b; cin >> a >> b;\n  cout << a + b << '\\n';\n}\n\nvll\
    \ table = {\n//(n, tau(n))\n1L, 1L, \n2L, 2L, \n4L, 3L, \n6L, 4L, \n12L, 6L, \n\
    24L, 8L, \n36L, 9L, \n48L, 10L, \n60L, 12L, \n120L, 16L, \n180L, 18L, \n240L,\
    \ 20L, \n360L, 24L, \n720L, 30L, \n840L, 32L, \n1'260L, 36L, \n1'680L, 40L, \n\
    2'520L, 48L, \n5'040L, 60L, \n7'560L, 64L, \n10'080L, 72L, \n15'120L, 80L, \n\
    20'160L, 84L, \n25'200L, 90L, \n27'720L, 96L, \n45'360L, 100L, \n50'400L, 108L,\
    \ \n55'440L, 120L, \n83'160L, 128L, \n110'880L, 144L, \n166'320L, 160L, \n221'760L,\
    \ 168L, \n277'200L, 180L, \n332'640L, 192L, \n498'960L, 200L, \n554'400L, 216L,\
    \ \n665'280L, 224L, \n720'720L, 240L, \n1'081'080L, 256L, \n1'441'440L, 288L,\
    \ \n2'162'160L, 320L, \n2'882'880L, 336L, \n3'603'600L, 360L, \n4'324'320L, 384L,\
    \ \n6'486'480L, 400L, \n7'207'200L, 432L, \n8'648'640L, 448L, \n10'810'800L, 480L,\
    \ \n14'414'400L, 504L, \n17'297'280L, 512L, \n21'621'600L, 576L, \n32'432'400L,\
    \ 600L, \n36'756'720L, 640L, \n43'243'200L, 672L, \n61'261'200L, 720L, \n73'513'440L,\
    \ 768L, \n110'270'160L, 800L, \n122'522'400L, 864L, \n147'026'880L, 896L, \n183'783'600L,\
    \ 960L, \n245'044'800L, 1'008L, \n294'053'760L, 1'024L, \n367'567'200L, 1'152L,\
    \ \n551'350'800L, 1'200L, \n698'377'680L, 1'280L, \n735'134'400L, 1'344L, \n1'102'701'600L,\
    \ 1'440L, \n1'396'755'360L, 1'536L, \n2'095'133'040L, 1'600L, \n2'205'403'200L,\
    \ 1'680L, \n2'327'925'600L, 1'728L, \n2'793'510'720L, 1'792L, \n3'491'888'400L,\
    \ 1'920L, \n4'655'851'200L, 2'016L, \n5'587'021'440L, 2'048L, \n6'983'776'800L,\
    \ 2'304L, \n10'475'665'200L, 2'400L, \n13'967'553'600L, 2'688L, \n20'951'330'400L,\
    \ 2'880L, \n27'935'107'200L, 3'072L, \n41'902'660'800L, 3'360L, \n48'886'437'600L,\
    \ 3'456L, \n64'250'746'560L, 3'584L, \n73'329'656'400L, 3'600L, \n80'313'433'200L,\
    \ 3'840L, \n97'772'875'200L, 4'032L, \n128'501'493'120L, 4'096L, \n146'659'312'800L,\
    \ 4'320L, \n160'626'866'400L, 4'608L, \n240'940'299'600L, 4'800L, \n293'318'625'600L,\
    \ 5'040L, \n321'253'732'800L, 5'376L, \n481'880'599'200L, 5'760L, \n642'507'465'600L,\
    \ 6'144L, \n963'761'198'400L, 6'720L, \n1'124'388'064'800L, 6'912L, \n1'606'268'664'000L,\
    \ 7'168L, \n1'686'582'097'200L, 7'200L, \n1'927'522'396'800L, 7'680L, \n2'248'776'129'600L,\
    \ 8'064L, \n3'212'537'328'000L, 8'192L, \n3'373'164'194'400L, 8'640L, \n4'497'552'259'200L,\
    \ 9'216L, \n6'746'328'388'800L, 10'080L, \n8'995'104'518'400L, 10'368L, \n9'316'358'251'200L,\
    \ 10'752L, \n13'492'656'777'600L, 11'520L, \n18'632'716'502'400L, 12'288L, \n\
    26'985'313'555'200L, 12'960L, \n27'949'074'753'600L, 13'440L, \n32'607'253'879'200L,\
    \ 13'824L, \n46'581'791'256'000L, 14'336L, \n48'910'880'818'800L, 14'400L, \n\
    55'898'149'507'200L, 15'360L, \n65'214'507'758'400L, 16'128L, \n93'163'582'512'000L,\
    \ 16'384L, \n97'821'761'637'600L, 17'280L, \n130'429'015'516'800L, 18'432L, \n\
    195'643'523'275'200L, 20'160L, \n260'858'031'033'600L, 20'736L, \n288'807'105'787'200L,\
    \ 21'504L, \n391'287'046'550'400L, 23'040L, \n577'614'211'574'400L, 24'576L, \n\
    782'574'093'100'800L, 25'920L, \n866'421'317'361'600L, 26'880L, \n1'010'824'870'255'200L,\
    \ 27'648L, \n1'444'035'528'936'000L, 28'672L, \n1'516'237'305'382'800L, 28'800L,\
    \ \n1'732'842'634'723'200L, 30'720L, \n2'021'649'740'510'400L, 32'256L, \n2'888'071'057'872'000L,\
    \ 32'768L, \n3'032'474'610'765'600L, 34'560L, \n4'043'299'481'020'800L, 36'864L,\
    \ \n6'064'949'221'531'200L, 40'320L, \n8'086'598'962'041'600L, 41'472L, \n10'108'248'702'552'000L,\
    \ 43'008L, \n12'129'898'443'062'400L, 46'080L, \n18'194'847'664'593'600L, 48'384L,\
    \ \n20'216'497'405'104'000L, 49'152L, \n24'259'796'886'124'800L, 51'840L, \n30'324'746'107'656'000L,\
    \ 53'760L, \n36'389'695'329'187'200L, 55'296L, \n48'519'593'772'249'600L, 57'600L,\
    \ \n60'649'492'215'312'000L, 61'440L, \n72'779'390'658'374'400L, 62'208L, \n74'801'040'398'884'800L,\
    \ 64'512L, \n106'858'629'141'264'000L, 65'536L, \n112'201'560'598'327'200L, 69'120L,\
    \ \n149'602'080'797'769'600L, 73'728L, \n224'403'121'196'654'400L, 80'640L, \n\
    299'204'161'595'539'200L, 82'944L, \n374'005'201'994'424'000L, 86'016L, \n448'806'242'393'308'800L,\
    \ 92'160L, \n673'209'363'589'963'200L, 96'768L, \n748'010'403'988'848'000L, 98'304L,\
    \ \n897'612'484'786'617'600L, 103'680L\n};\n\nint main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  for(int i = 0; i < ssize(table); i += 2) {\n    pll sol(-1,\
    \ -1);\n    enumerate_highly_composite_numbers(table[i] + 1, [&](ll n, vc<pii>\
    \ fac) {\n      ll prod = 1;\n      for(auto [_, e] : fac)\n        prod *= e\
    \ + 1;\n      chmax(sol, pll(prod, -n));\n    });\n    assert(sol == pll(table[i\
    \ + 1], -table[i]));\n  }\n\n  a_plus_b();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../default/t.cpp\"\n#include \"../enumerate/enumerate_highly_composite_numbers.cpp\"\
    \n\nvoid a_plus_b() {\n  int a, b; cin >> a >> b;\n  cout << a + b << '\\n';\n\
    }\n\nvll table = {\n//(n, tau(n))\n1L, 1L, \n2L, 2L, \n4L, 3L, \n6L, 4L, \n12L,\
    \ 6L, \n24L, 8L, \n36L, 9L, \n48L, 10L, \n60L, 12L, \n120L, 16L, \n180L, 18L,\
    \ \n240L, 20L, \n360L, 24L, \n720L, 30L, \n840L, 32L, \n1'260L, 36L, \n1'680L,\
    \ 40L, \n2'520L, 48L, \n5'040L, 60L, \n7'560L, 64L, \n10'080L, 72L, \n15'120L,\
    \ 80L, \n20'160L, 84L, \n25'200L, 90L, \n27'720L, 96L, \n45'360L, 100L, \n50'400L,\
    \ 108L, \n55'440L, 120L, \n83'160L, 128L, \n110'880L, 144L, \n166'320L, 160L,\
    \ \n221'760L, 168L, \n277'200L, 180L, \n332'640L, 192L, \n498'960L, 200L, \n554'400L,\
    \ 216L, \n665'280L, 224L, \n720'720L, 240L, \n1'081'080L, 256L, \n1'441'440L,\
    \ 288L, \n2'162'160L, 320L, \n2'882'880L, 336L, \n3'603'600L, 360L, \n4'324'320L,\
    \ 384L, \n6'486'480L, 400L, \n7'207'200L, 432L, \n8'648'640L, 448L, \n10'810'800L,\
    \ 480L, \n14'414'400L, 504L, \n17'297'280L, 512L, \n21'621'600L, 576L, \n32'432'400L,\
    \ 600L, \n36'756'720L, 640L, \n43'243'200L, 672L, \n61'261'200L, 720L, \n73'513'440L,\
    \ 768L, \n110'270'160L, 800L, \n122'522'400L, 864L, \n147'026'880L, 896L, \n183'783'600L,\
    \ 960L, \n245'044'800L, 1'008L, \n294'053'760L, 1'024L, \n367'567'200L, 1'152L,\
    \ \n551'350'800L, 1'200L, \n698'377'680L, 1'280L, \n735'134'400L, 1'344L, \n1'102'701'600L,\
    \ 1'440L, \n1'396'755'360L, 1'536L, \n2'095'133'040L, 1'600L, \n2'205'403'200L,\
    \ 1'680L, \n2'327'925'600L, 1'728L, \n2'793'510'720L, 1'792L, \n3'491'888'400L,\
    \ 1'920L, \n4'655'851'200L, 2'016L, \n5'587'021'440L, 2'048L, \n6'983'776'800L,\
    \ 2'304L, \n10'475'665'200L, 2'400L, \n13'967'553'600L, 2'688L, \n20'951'330'400L,\
    \ 2'880L, \n27'935'107'200L, 3'072L, \n41'902'660'800L, 3'360L, \n48'886'437'600L,\
    \ 3'456L, \n64'250'746'560L, 3'584L, \n73'329'656'400L, 3'600L, \n80'313'433'200L,\
    \ 3'840L, \n97'772'875'200L, 4'032L, \n128'501'493'120L, 4'096L, \n146'659'312'800L,\
    \ 4'320L, \n160'626'866'400L, 4'608L, \n240'940'299'600L, 4'800L, \n293'318'625'600L,\
    \ 5'040L, \n321'253'732'800L, 5'376L, \n481'880'599'200L, 5'760L, \n642'507'465'600L,\
    \ 6'144L, \n963'761'198'400L, 6'720L, \n1'124'388'064'800L, 6'912L, \n1'606'268'664'000L,\
    \ 7'168L, \n1'686'582'097'200L, 7'200L, \n1'927'522'396'800L, 7'680L, \n2'248'776'129'600L,\
    \ 8'064L, \n3'212'537'328'000L, 8'192L, \n3'373'164'194'400L, 8'640L, \n4'497'552'259'200L,\
    \ 9'216L, \n6'746'328'388'800L, 10'080L, \n8'995'104'518'400L, 10'368L, \n9'316'358'251'200L,\
    \ 10'752L, \n13'492'656'777'600L, 11'520L, \n18'632'716'502'400L, 12'288L, \n\
    26'985'313'555'200L, 12'960L, \n27'949'074'753'600L, 13'440L, \n32'607'253'879'200L,\
    \ 13'824L, \n46'581'791'256'000L, 14'336L, \n48'910'880'818'800L, 14'400L, \n\
    55'898'149'507'200L, 15'360L, \n65'214'507'758'400L, 16'128L, \n93'163'582'512'000L,\
    \ 16'384L, \n97'821'761'637'600L, 17'280L, \n130'429'015'516'800L, 18'432L, \n\
    195'643'523'275'200L, 20'160L, \n260'858'031'033'600L, 20'736L, \n288'807'105'787'200L,\
    \ 21'504L, \n391'287'046'550'400L, 23'040L, \n577'614'211'574'400L, 24'576L, \n\
    782'574'093'100'800L, 25'920L, \n866'421'317'361'600L, 26'880L, \n1'010'824'870'255'200L,\
    \ 27'648L, \n1'444'035'528'936'000L, 28'672L, \n1'516'237'305'382'800L, 28'800L,\
    \ \n1'732'842'634'723'200L, 30'720L, \n2'021'649'740'510'400L, 32'256L, \n2'888'071'057'872'000L,\
    \ 32'768L, \n3'032'474'610'765'600L, 34'560L, \n4'043'299'481'020'800L, 36'864L,\
    \ \n6'064'949'221'531'200L, 40'320L, \n8'086'598'962'041'600L, 41'472L, \n10'108'248'702'552'000L,\
    \ 43'008L, \n12'129'898'443'062'400L, 46'080L, \n18'194'847'664'593'600L, 48'384L,\
    \ \n20'216'497'405'104'000L, 49'152L, \n24'259'796'886'124'800L, 51'840L, \n30'324'746'107'656'000L,\
    \ 53'760L, \n36'389'695'329'187'200L, 55'296L, \n48'519'593'772'249'600L, 57'600L,\
    \ \n60'649'492'215'312'000L, 61'440L, \n72'779'390'658'374'400L, 62'208L, \n74'801'040'398'884'800L,\
    \ 64'512L, \n106'858'629'141'264'000L, 65'536L, \n112'201'560'598'327'200L, 69'120L,\
    \ \n149'602'080'797'769'600L, 73'728L, \n224'403'121'196'654'400L, 80'640L, \n\
    299'204'161'595'539'200L, 82'944L, \n374'005'201'994'424'000L, 86'016L, \n448'806'242'393'308'800L,\
    \ 92'160L, \n673'209'363'589'963'200L, 96'768L, \n748'010'403'988'848'000L, 98'304L,\
    \ \n897'612'484'786'617'600L, 103'680L\n};\n\nint main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  for(int i = 0; i < ssize(table); i += 2) {\n    pll sol(-1,\
    \ -1);\n    enumerate_highly_composite_numbers(table[i] + 1, [&](ll n, vc<pii>\
    \ fac) {\n      ll prod = 1;\n      for(auto [_, e] : fac)\n        prod *= e\
    \ + 1;\n      chmax(sol, pll(prod, -n));\n    });\n    assert(sol == pll(table[i\
    \ + 1], -table[i]));\n  }\n\n  a_plus_b();\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - enumerate/enumerate_highly_composite_numbers.cpp
  isVerificationFile: true
  path: test/mytest_enumerate_highly_composite_numbers.test.cpp
  requiredBy: []
  timestamp: '2026-09-03 11:20:30+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest_enumerate_highly_composite_numbers.test.cpp
layout: document
redirect_from:
- /verify/test/mytest_enumerate_highly_composite_numbers.test.cpp
- /verify/test/mytest_enumerate_highly_composite_numbers.test.cpp.html
title: test/mytest_enumerate_highly_composite_numbers.test.cpp
---
