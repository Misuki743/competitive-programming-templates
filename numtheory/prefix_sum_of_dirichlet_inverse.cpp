//f * g = h, G(x), H(x) can be computed fast, find F(N)
template<class T, typename F1, typename F2, typename F3 = void*>
requires R_invocable<T, F1, ll> && R_invocable<T, F2, ll>
vc<T> prefix_sum_of_dirichlet_inverse(ll N, F1 G, F2 H, F3 F_lazy = (void*)0) {
  ll x = sqrtl(N);
  while(x * (x + 1) <= N) x++;
  ll m = N / x;

  vll qs;
  qs.reserve(m + x - 1);
  for(ll i = 1; i < m; i++) qs.eb(i);
  for(ll i = x; i >= 1; i--) qs.eb(N / i);
  auto id = [&](ll n) { return n <= m ? n - 1 : ssize(qs) - (N / n); };

  vc<T> F(m + x - 1);

  T G1_inv;
  if constexpr (!is_integral_v<T>) G1_inv = G(1).inverse();

  for(ll i = 0; i < ssize(qs); i++) {
    ll Q = qs[i];

    if constexpr (!same_as<F3, void*>) {
      if (Q < ssize(F_lazy)) {
        F[i] = F_lazy[Q];
        continue;
      }
    }

    F[i] = H(Q);
    ll x2 = sqrtl(Q);
    while(x2 * (x2 + 1) <= Q) x2++;
    ll m2 = Q / x2;
    for(ll j = 1; j < m2; j++)
      F[i] -= F[id(j)] * (G(Q / j) - G(Q / (j + 1)));
    for(ll j = x2; j > 1; j--)
      F[i] -= F[id(Q / j)] * (G(Q / (Q / j)) - G(Q / (Q / j + 1)));

    if constexpr (is_integral_v<T>) F[i] /= G(1);
    else F[i] *= G1_inv;
  }

  return F;
}
