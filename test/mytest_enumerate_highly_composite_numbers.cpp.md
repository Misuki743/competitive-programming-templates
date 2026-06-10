---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':warning:'
    path: enumerate/enumerate_highly_composite_numbers.cpp
    title: enumerate/enumerate_highly_composite_numbers.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest_enumerate_highly_composite_numbers.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"default/t.cpp\"\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include\
    \ <cinttypes>\n#include <climits>\n#include <cmath>\n#include <complex>\n#include\
    \ <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <initializer_list>\n#include <iomanip>\n#include <ios>\n\
    #include <iostream>\n#include <istream>\n#include <iterator>\n#include <limits>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n\
    #include <ostream>\n#include <queue>\n#include <random>\n#include <set>\n#include\
    \ <sstream>\n#include <stack>\n#include <streambuf>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <variant>\n#include <bit>\n#include\
    \ <compare>\n#include <concepts>\n#include <numbers>\n#include <ranges>\n#include\
    \ <span>\n\n#define INT128_MAX (__int128)(((unsigned __int128) 1 << ((sizeof(__int128)\
    \ * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN (-INT128_MAX - 1)\n\n#define\
    \ pb push_back\n#define eb emplace_back\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
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
    \ T b) { return a < b ? a = b, 1 : 0; }\n\n#line 1 \"enumerate/enumerate_highly_composite_numbers.cpp\"\
    \ntemplate<typename F>\nrequires invocable<F, ll, vector<pair<int, int>>>\nvoid\
    \ enumerate_highly_composite_numbers(ll U, F f) {\n  prime_table<64> pt;\n\n \
    \ auto dfs = [&](ll prod, vc<pii> fac, auto &self) -> void {\n    f(prod, fac);\n\
    \n    int p = pt.prime_array()[ssize(fac)];\n    int lim = fac.empty() ? INT_MAX\
    \ : fac.back().second;\n    fac.eb(p, 0);\n    while((__int128)prod * p < U and\
    \ fac.back().second < lim) {\n      fac.back().second += 1, prod *= p;\n     \
    \ self(prod, fac, self);\n    }\n  };\n  dfs(1, {}, dfs);\n}\n#line 5 \"test/mytest_enumerate_highly_composite_numbers.cpp\"\
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
    \ + 1], -table[i]));\n  }\n\n  return 0;\n}\n"
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
    \ + 1], -table[i]));\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - enumerate/enumerate_highly_composite_numbers.cpp
  isVerificationFile: false
  path: test/mytest_enumerate_highly_composite_numbers.cpp
  requiredBy: []
  timestamp: '2026-06-10 20:53:28+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/mytest_enumerate_highly_composite_numbers.cpp
layout: document
redirect_from:
- /library/test/mytest_enumerate_highly_composite_numbers.cpp
- /library/test/mytest_enumerate_highly_composite_numbers.cpp.html
title: test/mytest_enumerate_highly_composite_numbers.cpp
---
