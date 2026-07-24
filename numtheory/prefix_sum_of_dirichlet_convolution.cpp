template<class T, typename F1, typename F2>
requires R_invocable<T, F1, ll> && R_invocable<T, F2, ll>
T prefix_sum_of_dirichlet_convolution(ll N, F1 F, F2 G) {
  ll x = sqrtl(N);
  while(x * (x + 1) <= N) x++;
  ll m = N / x;

  T Fp = 0, ans = 0, tmp;
  for(ll q = 1; q < m; q++) {
    tmp = F(q);
    ans += T(tmp - Fp) * G(N / q);
    Fp = tmp;
  }
  for(ll i = x; i >= 1; i--) {
    tmp = F(N / i);
    ans += T(tmp - Fp) * G(N / (N / i));
    Fp = tmp;
  }

  return ans;
}
