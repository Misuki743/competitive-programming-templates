//#include "ds/hash_table"
//#include "numtheory/exgcd"

ll discrete_logarithm(ll x, ll y, ll m) {
  if (gcd(x, m) != 1) {
    int C = bit_width((ull)m);
    ll prod = 1;
    for(int i = 0; i < C; i++) {
      if (prod == y) return i;
      (prod *= x) %= m;
    }
    ll g = gcd(prod, m);
    if (y % g != 0) return -1;
    ll ans = discrete_logarithm(x, y / g * inv(prod / g, m / g) % (m / g), m / g);
    if (ans == -1) return -1;
    else return ans + C;
  }

  auto binpow = [m](ll a, ll k) {
    ll b = 1;
    while(k) {
      if (k & 1) (b *= a) %= m;
      (a *= a) %= m, k >>= 1;
    }
    return b;
  };

  ll B = sqrtl(m);
  while(B * B < m) B++;

#ifdef DEBUG
  hash_table t;
#else
  hash_table t({}, {}, {}, {}, {bit_ceil((ull)(B + 1))});
#endif

  ll I = inv(x, m);
  for(ll i = B, prod = binpow(x, B); i >= 0; i--, (prod *= I) %= m)
    t[prod] = i;

  ll J = binpow(I, B);
  for(ll i = 0, prod = y; i < B; i++, (prod *= J) %= m)
    if (auto ite = t.find(prod); ite != t.end())
      return i * B + ite -> second;
  return -1;
}
