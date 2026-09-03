//Given a multiplicative function f s.t.
//- F(n), f(p^e) can be calculated quickly
//- f(p) = f'(p) for all p
//
//Return F'_p(n) for all n in Q_N
template<class T, typename F1, typename F2>
requires R_invocable<T, F1, ll> && R_invocable<T, F2, ll, ll, ll>
vc<T> Lucy_DP(ll N, F1 F, F2 f) {
  ll x = sqrtl(N);
  while(x * (x + 1) <= N) x++;
  ll m = N / x;

  auto id = [&](ll n) { return n <= m ? n - 1 : m + x - 1 - N / n; };
  vc<T> dp;
  vll qs;
  dp.reserve(m + x - 1), qs.reserve(m + x - 1);
  for(ll i = 1; i < m; i++) dp.eb(F(i)), qs.eb(i);
  for(ll i = x; i >= 1; i--) dp.eb(F(N / i)), qs.eb(N / i);

  for(ll p = 2; p * p <= N; p++) if (mpf(p) == p) {
    for(ll i = m + x - 2; i >= 0 and qs[i] >= p * p; i--)
      dp[i] += f(p, 1, p) * (dp[p - 2] - dp[id(qs[i] / p)]);
    /* for the case where f is not completely multiplicative (when would this be useful?)
    ll i = m + x - 2;
    while(i > 0 and qs[i - 1] >= p * p) i--;
    for(; i < m + x - 1; i++) {
      for(ll q = p, e = 1; q * (ull)p <= qs[i]; q *= p, e++) {
        dp[i] -= f(p, e + 1, q * p);
        dp[i] += f(p, e, q) * (dp[p - 1] - dp[id(qs[i] / q)]);
      }
    }
    */
  }

  return dp;
}

template<class T, typename F1>
requires R_invocable<T, F1, ll, ll, ll> 
vc<T> inverse_Lucy_DP(ll N, vc<T> Fp, F1 f) {
  ll x = sqrtl(N);
  while(x * (x + 1) <= N) x++;
  ll m = N / x;

  auto id = [&](ll n) { return n <= m ? n - 1 : m + x - 1 - N / n; };
  vll qs;
  qs.reserve(m + x - 1);
  for(ll i = 1; i < m; i++) qs.eb(i);
  for(ll i = x; i >= 1; i--) qs.eb(N / i);

  for(ll p = m; p > 1; p--) if (mpf(p) == p) {
    for(ll i = m + x - 2; i >= 0 and qs[i] >= p * p; i--)
      for(ll e = 1, q = p; q * (ull)p <= qs[i]; q *= p, e++)
        Fp[i] += f(p, e, q) * (Fp[id(qs[i] / q)] - Fp[p - 1]) + f(p, e + 1, q * p);
  }

  return Fp;
}
