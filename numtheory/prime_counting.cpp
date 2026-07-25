ll prime_counting(ll N) {
  ll x = sqrtl(N);
  while(x * (x + 1) <= N) x++;
  ll m = N / x;

  vll qs;
  qs.reserve(m + x - 1);
  for(ll i = 1; i < m; i++) qs.eb(i);
  for(ll i = x; i >= 1; i--) qs.eb(N / i);

  auto id = [&](ll n) { return n <= m ? n - 1 : m + x - 1 - N / n; };
  vll dp = qs;
  for(ll &y : dp) y--;

  for(ll p = 2; p * p <= N; p++) if (dp[p - 1] > dp[p - 2]) {
    ll pi = dp[p - 2];
    for(ll i = m + x - 2; i >= 0 and qs[i] >= p * p; i--)
      dp[i] += pi - dp[id(qs[i] / p)];
  }

  return dp.back();
}
