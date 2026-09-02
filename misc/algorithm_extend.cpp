namespace algorithm_extend {

  template<typename R, typename F, typename... Args>
  concept R_invocable = requires(F&& f, Args&&... args) {
    { std::invoke(std::forward<F>(f), std::forward<Args>(args)...) } -> std::same_as<R>;
  };

  template<ranges::forward_range R, class T = ranges::range_value_t<R>, typename F>
  requires R_invocable<T, F, T, T>
  void psum(R &&v, F f) {
    if (!v.empty())
      for(T p = *v.begin(); T &x : v | views::drop(1))
        x = p = f(p, x);
  }

  template<ranges::forward_range R, class T = ranges::range_value_t<R>>
  void psum(R &&v) {
    if (!v.empty())
      for(T p = *v.begin(); T &x : v | views::drop(1))
        x = p = p + x;
  }

  template<ranges::forward_range R>
  void unique(R &v) {
    ranges::sort(v);
    v.erase(ranges::unique(v).begin(), v.end());
  }

  template<ranges::random_access_range R>
  R inv_perm(const R &p) {
    R ret = p;
    for(int i = 0; i < ssize(p); i++)
      ret[p[i]] = i;
    return ret;
  }

  template<ranges::random_access_range R, class F = identity>
  vi arg_sort(const R &v, F proj = {}) {
    vi id(size(v));
    iota(id.begin(), id.end(), 0);
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

  template<integral T>
  vc<T> iota_vec(int n, T s = 0, T d = 1) {
    vc<T> v(n);
    for(int i = 0; i < n; i++)
      v[i] = i * d + s;
    return v;
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

  template<signed_integral T> T floor_div(T a, T b) { return a / b - (a % b < 0); }
  template<signed_integral T> T  ceil_div(T a, T b) { return a / b + (a % b > 0); }

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
  ll inversion_count(R v) {
    ll f = 0;
    auto tmp = v;
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
