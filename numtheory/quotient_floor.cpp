struct quotient_floor {
  const ll n;
  ll m, x, sz;
  quotient_floor(ll _n) : n(_n) {
    x = sqrtl(n);
    while(x * (x + 1) <= n) x++;
    m = n / x;
    sz = (x - 1) + m;
  }

  ll Q(ll i) { return i < m ? i + 1 : n / (m - i + x - 1); }
  ll L(ll q) { return n / (q + 1); }
  ll R(ll q) { return n / q; }
  ll id(ll q) { return q <= m ? q - 1 : sz - n / q; };
  ll size() { return sz; }
  auto Qs() {
    return views::iota(0ll, sz) | views::transform([&](ll i) { return Q(i); });
  }
};
