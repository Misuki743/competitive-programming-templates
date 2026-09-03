template<typename F>
requires invocable<F, ll, vector<pair<int, int>>>
void enumerate_highly_composite_numbers(ll U, F f) {
  static vi ps;
  if (ps.empty())
    primes(64, [](int p) { ps.eb(p); });

  auto dfs = [&](ll prod, vc<pii> pfs, auto &self) -> void {
    f(prod, pfs);

    int p = ps[ssize(pfs)];
    int lim = pfs.empty() ? INT_MAX : pfs.back().second;
    pfs.eb(p, 0);
    while((__int128)prod * p < U and pfs.back().second < lim) {
      pfs.back().second += 1, prod *= p;
      self(prod, pfs, self);
    }
  };
  dfs(1, {}, dfs);
}
