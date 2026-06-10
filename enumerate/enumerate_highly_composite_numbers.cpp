template<typename F>
requires invocable<F, ll, vector<pair<int, int>>>
void enumerate_highly_composite_numbers(ll U, F f) {
  prime_table<64> pt;

  auto dfs = [&](ll prod, vc<pii> fac, auto &self) -> void {
    f(prod, fac);

    int p = pt.prime_array()[ssize(fac)];
    int lim = fac.empty() ? INT_MAX : fac.back().second;
    fac.eb(p, 0);
    while((__int128)prod * p < U and fac.back().second < lim) {
      fac.back().second += 1, prod *= p;
      self(prod, fac, self);
    }
  };
  dfs(1, {}, dfs);
}
