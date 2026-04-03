//#include "numtheory/factorize_pollard_rho.cpp"
//#include "numtheory/primitive_root.cpp"

//min of mod of linear come from maspy's library
//link: https://maspypy.github.io/library/mod/min_of_linear.hpp
//      https://maspypy.github.io/library/mod/min_of_linear_segments.hpp

/*
ax + b (x>=0) が最小となるところの情報を返す。
prefix min を更新する x 全体が、等差数列の和集合。次を返す。
・等差数列の境界となる x_0, x_1, ..., x_n
・各境界の間での交差 dx_0, ..., dx_{n-1}
*/
pair<vc<ll>, vc<ll>> min_of_linear_segments(ll a, ll b, ll mod) {
  assert(0 <= a && a < mod);
  assert(0 <= b && b < mod);
  vc<ll> X = {0};
  vc<ll> DX;
  ll g = gcd(a, mod);
  a /= g, b /= g, mod /= g;
  // p/q <= (mod-a)/mod <= r/s
  ll p = 0, q = 1, r = 1, s = 1;
  ll det_l = mod - a, det_r = a;
  ll x = 0, y = b;

  while (y) {
    // upd r/s
    ll k = det_r / det_l;
    det_r %= det_l;
    if (det_r == 0) {
      --k;
      det_r = det_l;
    }
    r += k * p;
    s += k * q;
    while (1) {
      ll k = max(0ll, ceilDiv(det_l - y, det_r));
      if (det_l - k * det_r <= 0) break;
      det_l -= k * det_r;
      p += k * r;
      q += k * s;
      // p/q <= a/mod
      // (aq - pmod) = det_l を y から引く
      k = y / det_l;
      y -= k * det_l;
      x += q * k;
      X.eb(x);
      DX.eb(q);
    }
    k = det_l / det_r;
    det_l -= k * det_r;
    p += k * r;
    q += k * s;
    assert(min({p, q, r, s}) >= 0);
  }
  return {X, DX};
}

// min_{x in [L, R)} (ax+b mod)
using i128 = __int128;
pair<i128, ll> min_of_linear(i128 L, i128 R, ll a, ll b, ll mod) {
  i128 n = R - L;
  b = (b + a * L) % mod;
  if (b < 0) b += mod;
  auto [X, DX] = min_of_linear_segments(a, b, mod);
  ll x = 0;
  for (int i = 0; i < int(X.size()) - 1; ++i) {
    ll xl = X[i], xr = X[i + 1];
    if (xr < n) {
      x = xr;
      continue;
    }
    x = xl + (n - 1 - x) / DX[i] * DX[i];
    break;
  }
  ll y = (i128(a) * x + b) % mod;
  return {L + x, y};
}
//

struct Gauss_int { ll a, b; };
Gauss_int operator+(Gauss_int x, Gauss_int y) { return {x.a + y.a, x.b + y.b}; }
Gauss_int operator-(Gauss_int x, Gauss_int y) { return {x.a - y.a, x.b - y.b}; }
Gauss_int operator*(Gauss_int x, Gauss_int y) { return {x.a * y.a - x.b * y.b, x.b * y.a + x.a * y.b}; }

vc<pii> two_square_sum(ll n) {
  if (n == 0) return {pii(0, 0)};
  auto D = factor(n);
  ranges::sort(D);

  vc<Gauss_int> sol;
  sol.pb({-1, 0});
  sol.pb({0, -1});
  sol.pb({1, 0});
  sol.pb({0, 1});
  for(auto [l, r] : equal_subarrays(D)) {
    ll p = D[l];
    int e = r - l;
    if (p == 2) {
      Gauss_int y{1, 0};
      for(int i = 0; i < e; i++)
        y = y * Gauss_int{1, 1};
      for(auto &x : sol)
        x = x * y;
    } else if (p % 4 == 1) {
      ll i = modpow(primitiveRoot(p), (p - 1) / 4, p);

      ll d;
      {
        ll U = sqrtl(p);
        while(U * U < p) U++;
        auto [d1, mn1] = min_of_linear(1, U, i, 0, p);
        auto [d2, mn2] = min_of_linear(1, U, p - i, 0, p);
        d = mn1 < U ? d1 : d2;
      }

      vc<Gauss_int> pw(e + 1);
      pw[0] = {1, 0};
      pw[1] = {(ll)((i128)(d) * i % p), d};
      for(int j = 1; j <= e; j++)
        pw[j] = pw[j - 1] * pw[1];

      vc<Gauss_int> nxt;
      for(auto x : sol) {
        for(int j = 0; j <= e; j++) {
          auto y = pw[j];
          auto z = pw[e - j];
          swap(z.a, z.b);
          nxt.pb(x * y * z);
        }
      }

      sol.swap(nxt);

    } else if (e % 2 == 0) {
      ll q = 1;
      for(int i = 0; i < e / 2; i++)
        q *= p;
      for(auto &x : sol)
        x = x * Gauss_int{q, 0};
    } else {
      return {};
    }
  }

  vc<pii> res;
  for(auto [a, b] : sol)
    if (min(a, b) >= 0)
      res.eb(a, b);
  return res;
}
