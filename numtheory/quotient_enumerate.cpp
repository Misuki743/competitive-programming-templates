template<typename F>
void quotient_floor_enumerate(ll n, F f) {
  ll x = sqrtl(n);
  while(x * (x + 1) <= n) x++;
  ll m = n / x;
  for(ll i = 1; i < x; i++) {
    ll q = n / i;
    f(q, n / (q + 1) + 1, n / q + 1);
  }
  for(ll q = m; q >= 1; q--)
    f(q, n / (q + 1) + 1, n / q + 1);
}

template<typename F>
void quotient_ceil_enumerate(ll n, F f) {
  ll x = sqrtl(n);
  while(x * (x + 1) <= n) x++;
  ll m = (n + x - 1) / x;
  for(ll i = 1; i < x; i++) {
    ll q = (n + i - 1) / i;
    f(q, (n + q - 1) / q, (n + q - 2) / (q - 1));
  }
  for(ll q = m; q >= 2; q--)
    f(q, (n + q - 1) / q, (n + q - 2) / (q - 1));
  f(1, n, n + 1);
}
