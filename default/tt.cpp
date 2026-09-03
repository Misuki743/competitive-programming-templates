#include<bits/stdc++.h>
using namespace std;

#define int ll
#define pb push_back
#define eb emplace_back

using ll = long long;
using ull = unsigned long long;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<typename T> using vc = vector<T>;
template<typename T> using vvc = vc<vc<T>>;
template<typename T> using vvvc = vc<vvc<T>>;

using vi = vc<int>;
using vll = vc<ll>;
using vvi = vvc<int>;
using vvll = vvc<ll>;

template<typename T> using min_heap = priority_queue<T, vc<T>, greater<T>>;
template<typename T> using max_heap = priority_queue<T>;

namespace output {
  ostream& operator<<(ostream& os, __uint128_t x) {
    if (x == 0) {
      return os << "0";
    } else {
      string s;
      while(x)
        s += '0' + x % 10, x /= 10;
      ranges::reverse(s);
      return os << s;
    }
  }

  ostream& operator<<(ostream& os, __int128_t x) {
    if (x < 0)
      return os << "-" << -(__uint128_t)x;
    else
      return os << (__uint128_t)x;
  }

  template<size_t I = 0, typename... args>
  ostream& print_tuple(ostream& os, const tuple<args...> tu) {
    os << get<I>(tu);
    if constexpr (I + 1 != sizeof...(args)) {
      os << ' ';
      print_tuple<I + 1>(os, tu);
    }
    return os;
  }

  template<typename... args>
  ostream& operator<<(ostream& os, const tuple<args...> tu) {
    return print_tuple(os, tu);
  }

  template<class T1, class T2>
  ostream& operator<<(ostream& os, const pair<T1, T2> pr) {
    return os << pr.first << ' ' << pr.second;
  }

  template<class T>
  concept printable_range =
    ranges::input_range<T> &&
    !same_as<remove_cvref_t<T>, string> &&
    !same_as<remove_cvref_t<T>, string_view> &&
    !same_as<ranges::range_value_t<T>, char>;

  template<printable_range R>
  ostream& operator<<(ostream& os, R&& r) {
    for(bool first = true; auto &&x : r) {
      if (!first) os << ' ';
      first = false;
      os << x;
    }
    return os;
  }

#ifdef DEBUG
#define dbg(...) cerr << '(', _do(#__VA_ARGS__), cerr << ") = ", _do2(__VA_ARGS__)
  template<typename T> void _do(T &&x) { cerr << x; }
  template<typename T, typename ...S> void _do(T &&x, S&&...y) { cerr << x << ", "; _do(y...); }
  template<typename T> void _do2(T &&x) { cerr << x << endl; }
  template<typename T, typename ...S> void _do2(T &&x, S&&...y) { cerr << x << ", "; _do2(y...); }
#else
#define dbg(...)
#endif
}

using namespace output;

namespace algorithm_extend {

  template<typename R, typename F, typename... Args>
  concept R_invocable = requires(F&& f, Args&&... args) {
    { std::invoke(std::forward<F>(f), std::forward<Args>(args)...) } -> std::same_as<R>;
  };

  template<ranges::forward_range R, class T = ranges::range_value_t<R>, typename F>
  requires R_invocable<T, F, T, T>
  void psum(R &&v, F f) {
    if (!ranges::empty(v))
      for(T p = *v.begin(); T &x : v | views::drop(1))
        x = p = f(p, x);
  }

  template<ranges::forward_range R, class T = ranges::range_value_t<R>>
  void psum(R &&v) {
    if (!ranges::empty(v))
      for(T p = *v.begin(); T &x : v | views::drop(1))
        x = p = p + x;
  }

  template<ranges::random_access_range R>
  void unique(R &v) {
    ranges::sort(v);
    v.erase(ranges::unique(v).begin(), v.end());
  }

  template<ranges::random_access_range R, class T = ranges::range_value_t<R>>
  vc<T> inv_perm(const R &p) {
    vc<T> ret(p.begin(), p.end());
    for(int i = 0; i < ssize(p); i++)
      ret[p[i]] = i;
    return ret;
  }

  template<class T>
  vc<T> iota_vec(int n, T s = 0, T d = 1) {
    vc<T> v(n);
    for(int i = 0; i < n; i++)
      v[i] = i * d + s;
    return v;
  }

  template<ranges::random_access_range R, class F = identity>
  vi arg_sort(const R &v, F proj = {}) {
    vi id = iota_vec<int>(ssize(v));
    ranges::sort(id, {}, [&](int i) { return pair(proj(v[i]), i); });
    return id;
  }

  template<ranges::random_access_range R, class F = identity>
  vc<pii> equal_subarrays(const R &v, F proj = {}) {
    vc<pii> lr;
    for(int i = 0, j = 0; i < ssize(v); i = j) {
      while(j < ssize(v) and proj(v[i]) == proj(v[j])) j++;
      lr.eb(i, j);
    }
    return lr;
  }

  template<ranges::random_access_range R>
  R compress(R &v) {
    R val = v;
    unique(val);
    for(auto &x : v)
      x = ranges::lower_bound(val, x) - val.begin();
    return val;
  }

  template<ranges::random_access_range R>
  R compress_stable(R &v) {
    R val = v;
    ranges::sort(val);
    vi pos = iota_vec<int>(ssize(v));
    for(auto &x : v)
      x = pos[ranges::lower_bound(val, x) - val.begin()]++;
    return val;
  }

  template<integral T>
  void set_bit(T &msk, int bit, bool x) {
    if (x) msk |= T(1) << bit;
    else msk &= ~(T(1) << bit);
  }
  template<integral T> void flip_bit(T &msk, int bit) { msk ^= T(1) << bit; }
  template<integral T> bool get_bit(T msk, int bit) { return msk >> bit & T(1); }

  template<integral T> T floor_div(T a, T b) { return a / b - (a % b < 0); }
  template<integral T> T  ceil_div(T a, T b) { return a / b + (a % b > 0); }

  ull kth_root(ull a, int k) {
    if (a == 0) return 0ull;
    if (k >= 64) return 1ull;
    if (k == 1) return a;
    if (k == 2) {
      ull b = sqrtl(a);
      while((__int128)(b + 1) * (b + 1) <= a) b++;
      while((__int128)b * b > a) b--;
      return b;
    }
    if (k == 3) {
      ull b = cbrtl(a);
      while((__int128)(b + 1) * (b + 1) * (b + 1) <= a) b++;
      while((__int128)b * b * b > a) b--;
      return b;
    }
    ull b = powl(a, 1.0L / k);
    auto pw = [](ull a, int k) {
      __int128 b = 1;
      for(int i = 0; i < k; i++) b *= a;
      return b;
    };
    while(pw(b + 1, k) <= a) b++;
    while(pw(b, k) > a) b--;
    return b;
  }

  template<class T> bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
  template<class T> bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

  template<integral T>
  T binpow(T a, ull k) {
    T b = 1;
    while(k) {
      if (k & 1) b *= a;
      a *= a, k >>= 1;
    }
    return b;
  }

  template<ranges::random_access_range R>
  ll inversion_count(const R &r) {
    ll f = 0;
    vc<ranges::range_value_t<R>> v(r.begin(), r.end()), tmp(r.begin(), r.end());
    auto dc = [&](int l, int r, auto &self) -> void {
      if (l + 1 >= r) return;
      int mid = (l + r) / 2;
      self(l, mid, self);
      self(mid, r, self);
      {
        int i = l, j = mid, k = l;
        while(i < mid and j < r) {
          if (v[i] <= v[j]) tmp[k++] = v[i++];
          else tmp[k++] = v[j++], f += mid - i;
        }
        while(i < mid) tmp[k++] = v[i++];
        while(j < r) tmp[k++] = v[j++];
      }
      for(int i = l; i < r; i++)
        v[i] = tmp[i];
    };

    dc(0, ssize(v), dc);

    return f;
  }
}

using namespace algorithm_extend;

namespace Combinatorics {
  template<class Mint>
  Mint factorial(int n) {
    static vc<Mint> dat;
    if (n >= ssize(dat)) {
      if (dat.empty()) dat.eb(1);
      int size0 = ssize(dat);
      dat.resize(min(Mint::get_mod(), bit_ceil((uint32_t)(n + 1))));
      for(int i = size0; i < ssize(dat); i++)
        dat[i] = dat[i - 1] * i;
    }
    return dat[n];
  }

  template<class Mint>
  Mint factorial_inv(int n) {
    static vc<Mint> dat;
    if (n >= ssize(dat)) {
      int size0 = ssize(dat);
      dat.resize(min(Mint::get_mod(), bit_ceil((uint32_t)(n + 1))));
      dat.back() = factorial<Mint>(ssize(dat) - 1).inverse();
      for(int i = ssize(dat) - 2; i >= size0; i--)
        dat[i] = dat[i + 1] * (i + 1);
    }
    return dat[n];
  }

  template<class Mint>
  Mint inverse(int n) {
    return factorial_inv<Mint>(n) * factorial<Mint>(n - 1);
  }

  template<class Mint>
  Mint binomial(int n, int k) {
    if (0 <= k and k <= n)
      return factorial<Mint>(n) * factorial_inv<Mint>(k) * factorial_inv<Mint>(n - k);
    else
      return Mint(0);
  }

  template<class Mint>
  Mint catalan(int n) {
    return binomial<Mint>(2 * n, n) - binomial<Mint>(2 * n, n + 1);
  }

  //number of up-down path with n (+1), m (-1) and never touch y = -k
  template<class Mint>
  Mint excatalan(int n, int m, int k) {
    if (k > m) return binomial<Mint>(n + m, m);
    else if (k > m - n) return binomial<Mint>(n + m, m) - binomial<Mint>(n + m, m - k);
    else return Mint(0);
  }

  template<class Mint>
  auto binomial_functions() {
    return tuple(
      &factorial<Mint>,
      &factorial_inv<Mint>,
      &inverse<Mint>,
      &binomial<Mint>,
      &catalan<Mint>,
      &excatalan<Mint>
    );
  }
}

using namespace Combinatorics;

namespace sieve_of_Eratosthenes {

  int _C = 5;
  vc<int32_t> _mpf, _prime = {2, 3};

  //n % 6 == 1 or 5
  int _id(int n) {
    return (n - 2) / 6 * 2 + (n % 6 == 1);
  }

  int _first_valid(int n) {
    static int d[6] = {1, 0, 3, 2, 1, 0};
    return n + d[n % 6];
  }

  int _next_valid(int n) {
    static int d[6] = {1, 4, 3, 2, 1, 2};
    return n + d[n % 6];
  }

  void sieve(int n) {
    assert(n <= (1 << 30));
    _C = _first_valid(_C);
    n = _first_valid(bit_ceil(n * 1ull));
    if (n <= _C) return;
    _mpf.resize(_id(n));
    for(int i = _C, d = _next_valid(_C) - _C; i < n; i += d, d = 6 - d)
      _mpf[_id(i)] = i;
    for(int i = 5, d = 2; i * i < n; i += d, d = 6 - d) if (_mpf[_id(i)] == i) {
      int k = _first_valid(max(i, ceil_div(_C, i)));
      for(int j = i * k, e = _next_valid(k) - k; j < n; j += i * e, e = 6 - e)
        _mpf[_id(j)] = min<int32_t>(_mpf[_id(j)], i);
    }
    _C = n;
  }

  int mpf(int n) {
    if (n == 1) return 0;
    if (n % 2 == 0) return 2;
    if (n % 3 == 0) return 3;
    if (n >= _C) sieve(n);
    return _mpf[_id(n)];
  }

  template<typename F>
  requires invocable<F, int, int>
  void factorize(int n, F f) {
    if (n >= _C) sieve(n);
    if (n % 2 == 0) f(2, countr_zero(n * 1ull)), n >>= countr_zero(n * 1ull);
    if (n % 3 == 0) {
      int e = 0;
      while(n % 3 == 0) n /= 3, e++;
      f(3, e);
    }
    while(n > 1) {
      int p = mpf(n), e = 0;
      while(n % p == 0) n /= p, e++;
      f(p, e);
    }
  }

  vi divisor(int n) {
    static array<int, 1 << 12> buf;
    if (n >= _C) sieve(n);
    vi v = {1};
    factorize(n, [&v](int p, int e) {
      int old_size = ssize(v);
      v.resize(old_size * (e + 1));
      for(int i = old_size; i < ssize(v); i++)
        v[i] = v[i - old_size] * p;
      for(int d = old_size; d < ssize(v); d <<= 1) {
        for(int i = 0; i + d < ssize(v); i += 2 * d) {
          merge(v.begin() + i, v.begin() + i + d, v.begin() + i + d, v.begin() + min(i + 2 * d, (int)size(v)), buf.begin());
          copy(buf.begin(), buf.begin() + min(2 * d, (int)size(v) - i), v.begin() + i);
        }
      }
    });
    return v;
  }

  template<typename F>
  requires invocable<F, int>
  void primes(int m, F f) {
    if (_next_valid(_prime.back()) < m) {
      if (m > _C) sieve(m);
      int s = _next_valid(_prime.back());
      for(int i = s, d = _next_valid(s) - s; i < m; i += d, d = 6 - d)
        if (_mpf[_id(i)] == i)
          _prime.eb(i);
    }
    for(int i = 0; i < ssize(_prime) and _prime[i] < m; i++)
      f(_prime[i]);
  }
}

using namespace sieve_of_Eratosthenes;

struct HLD {
  int n, root;
  vi dep, sz, p, head, tin, tout, inv_tin, child_list, c, v_to_e;
  vc<int32_t> lb;

  inline int head_parent(int v) const { return p[head[v]]; }

  HLD(vc<pii> e, int _root = 0) : root(_root) { precompute(e); }
  HLD(vi _p) {
    vc<pii> e;
    root = -1;
    for(int v = 0; v < ssize(_p); v++) {
      if (_p[v] == -1 or _p[v] == v)
        root = v;
      else
        e.eb(v, _p[v]);
    }
    assert(root != -1);
    precompute(e);
  }

  void precompute(vc<pii> &e) {
    n = ssize(e) + 1;

    dep = p = head = tin = tout = v_to_e = vi(n);
    sz = vi(n, 1);

    vi mx_child_sz(n, -1);
    {
      vi d(n);
      for(auto [u, v] : e)
        p[u] ^= v, p[v] ^= u, d[u]++, d[v]++;
      d[root] = 0;
      for(int i = 0; i < n; i++) {
        int v = i;
        while(d[v] == 1) {
          d[v] = 0, d[p[v]]--, p[p[v]] ^= v;
          sz[p[v]] += sz[v];
          chmax(mx_child_sz[p[v]], sz[v]);
          v = p[v];
        }
      }
      p[root] = root;
    }

    vi ord(n);
    {
      vi f(n + 2);
      for(int x : sz) f[x + 1]++;
      psum(f);
      for(int v = 0; v < n; v++)
        ord[n - 1 - (f[sz[v]]++)] = v;
    }

    {
      head[root] = root, tout[root] = n;

      vi add(n, 1);
      for(int v : ord | views::drop(1)) {
        dep[v] = dep[p[v]] + 1;
        tin[v] = tin[p[v]] + add[p[v]];
        add[p[v]] += sz[v];
        tout[v] = tin[v] + sz[v];
        if (mx_child_sz[p[v]] == sz[v])
          mx_child_sz[p[v]] = 0, head[v] = head[p[v]];
        else
          head[v] = v;
      }
    }

    inv_tin = inv_perm(tin);

    lb = vc<int32_t>(n + 1);
    child_list = vi(n + 1);
    for(int v = 0; v < n; v++)
      if (v != root)
        lb[p[v]]++;
    psum(lb);
    for(int v = 0; v < n; v++)
      if (v != root and head[v] == v)
        child_list[--lb[p[v]]] = v;
    for(int v = 0; v < n; v++)
      if (v != root and head[v] != v)
        child_list[--lb[p[v]]] = v;

    v_to_e[root] = -1;
    for(int i = 0; auto [u, v] : e) {
      if (dep[u] > dep[v]) swap(u, v);
      v_to_e[v] = i++;
    }
  }

  auto query_path(int u, int v, bool edge = false) {
    vc<pii> lr;
    while(head[u] != head[v]) {
      if (dep[head[u]] > dep[head[v]])
        swap(u, v);
      lr.emplace_back(tin[head[v]], tin[v] + 1);
      v = head_parent(v);
    }

    if (tin[u] > tin[v]) swap(u, v);
    if (tin[u] + edge <= tin[v])
      lr.emplace_back(tin[u] + edge, tin[v] + 1);

    return lr;
  }

  //l < r: op(l, op(l + 1, ...))
  //l > r: op(r - 1, op(r - 2, ...))
  auto query_path_non_commutative(int u, int v, bool edge = false) {
    vc<pii> lr1, lr2;
    while(head[u] != head[v]) {
      if (dep[head[u]] > dep[head[v]]) {
        lr1.emplace_back(tin[u] + 1, tin[head[u]]);
        u = head_parent(u);
      } else {
        lr2.emplace_back(tin[head[v]], tin[v] + 1);
        v = head_parent(v);
      }
    }

    if (tin[u] + edge <= tin[v])
      lr2.emplace_back(tin[u] + edge, tin[v] + 1);
    else if (tin[v] + edge <= tin[u])
      lr1.emplace_back(tin[u] + 1, tin[v] + edge);

    lr1.insert(end(lr1), lr2.rbegin(), lr2.rend());

    return lr1;
  }

  auto query_subtree(int v) { return pii(tin[v], tout[v]); }

  int query_point(int v) { return tin[v]; }

  int lca(int u, int v) {
    while(head[u] != head[v]) {
      if (dep[head[u]] > dep[head[v]])
        swap(u, v);
      v = head_parent(v);
    }
    return tin[u] < tin[v] ? u : v;
  }

  int dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
  }

  int kth(int s, int t, int k) {
    int l = lca(s, t);
    if (int d = dep[s] + dep[t] - 2 * dep[l]; k > d)
      return -1;
    else if (k > dep[s] - dep[l])
      k = d - k, swap(s, t);
    while(k > dep[s] - dep[head[s]]) {
      k -= dep[s] - dep[head[s]] + 1;
      s = head_parent(s);
    }
    return inv_tin[tin[s] - k];
  }

  int median(int u, int v, int w) {
    return lca(u, v) ^ lca(u, w) ^ lca(v, w);
  }

  template<class M>
  vc<M> reorder_init(vc<M> init) {
    assert(ssize(init) == ssize(dep));
    auto r = init;
    for(int i = 0; i < ssize(init); i++)
      r[tin[i]] = init[i];
    return r;
  }

  const span<int> childs(int v) {
    return span(child_list.begin() + lb[v], lb[v + 1] - lb[v]);
  }
  const span<int> light_childs(int v) {
    return span(child_list.begin() + lb[v] + 1, max(lb[v + 1] - lb[v] - 1, 0));
  }
  inline int heavy_child(int v) {
    return lb[v] == lb[v + 1] ? -1 : child_list[lb[v]];
  }
  inline int parent(int v) {
    return p[v];
  }

  inline int depth(int v) { return dep[v]; }
  inline int size(int v) { return sz[v]; }
  bool in_subtree_of(int a, int b) { return tin[b] <= tin[a] and tout[a] <= tout[b]; }
  const span<int> centroid() {
    if (c.empty()) {
      vc<bool> ok(n, true);
      for(int v = 0; v < n; v++) {
        if (2 * (n - sz[v]) > n)
          ok[v] = false;
        if (v != root and 2 * sz[v] > n)
          ok[p[v]] = false;
      }
      for(int v = 0; v < n; v++)
        if (ok[v])
          c.eb(v);
    }
    return c;
  }

  inline int parent_eid(int v) { return v_to_e[v]; }
};

template<uint32_t mod>
struct Montgomery_modint {
  using mint = Montgomery_modint;
  using i32 = int32_t;
  using u32 = uint32_t;
  using u64 = uint64_t;

  static constexpr u32 get_r() {
    u32 res = 1, base = mod;
    for(i32 i = 0; i < 31; i++)
      res *= base, base *= base;
    return -res;
  }

  static constexpr u32 get_mod() {
    return mod;
  }

  static constexpr u32 n2 = -u64(mod) % mod; //2^64 % mod
  static constexpr u32 r = get_r(); //-P^{-1} % 2^32

  u32 a;

  static u32 reduce(const u64 &b) {
    return (b + u64(u32(b) * r) * mod) >> 32;
  }

  static u32 transform(const u64 &b) {
    return reduce(u64(b) * n2);
  }

  Montgomery_modint() : a(0) {}
  Montgomery_modint(const int64_t &b) 
    : a(transform(b % mod + mod)) {}

  mint pow(u64 k) const {
    mint res(1), base(*this);
    while(k) {
      if (k & 1) 
        res *= base;
      base *= base, k >>= 1;
    }
    return res;
  }

  mint inverse() const { return (*this).pow(mod - 2); }

  u32 get() const {
    u32 res = reduce(a);
    return res >= mod ? res - mod : res;
  }

  mint& operator+=(const mint &b) {
    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }

  mint& operator-=(const mint &b) {
    if (i32(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }

  mint& operator*=(const mint &b) {
    a = reduce(u64(a) * b.a);
    return *this;
  }

  mint& operator/=(const mint &b) {
    a = reduce(u64(a) * b.inverse().a);
    return *this;
  }

  mint operator-() { return mint() - mint(*this); }
  bool operator==(mint b) const {
    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
  }
  bool operator!=(mint b) const {
    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
  }

  friend mint operator+(mint c, mint d) { return c += d; }
  friend mint operator-(mint c, mint d) { return c -= d; }
  friend mint operator*(mint c, mint d) { return c *= d; }
  friend mint operator/(mint c, mint d) { return c /= d; }

  friend ostream& operator<<(ostream& os, const mint& b) {
    return os << b.get();
  }
  friend istream& operator>>(istream& is, mint& b) {
    int64_t val;
    is >> val;
    b = mint(val);
    return is;
  }
};

//using mint = Montgomery_modint<1'000'000'007>;
using mint = Montgomery_modint<998'244'353>;
auto [fac, faci, modinv, binom, cat, excat] = binomial_functions<mint>();

int32_t main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  

  return 0;
}
