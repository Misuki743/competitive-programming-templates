ll phi(ll n) {
  auto pf = factor(n);
  unique(pf);
  for(ll p : pf)
    n -= n / p;
  return n;
}

ll tetration(ll a, ll b, ll m) {
  static const ll a2[] = {1, 2, 4, 16, 1 << 16};

  if (m == 1) return 0;
  if (b == 0) return 1;
  if (b == 1) return a % m;
  if (b == 2) return modpow(a, a, m);
  if (a == 0) return ~b & 1;
  if (a == 1) return 1;
  if (a == 2 and b < 5) return a2[b] % m;

  if (gcd(a, m) == 1) return modpow(a, tetration(a, b - 1, phi(m)), m);

  ll g = 1, x;
  while((x = gcd(g * a, m)) != g) g = x;

  return modpow(a, tetration(a, b - 1, phi(m / g)), m / g) * inv(g, m / g) % (m / g) * g;
}
