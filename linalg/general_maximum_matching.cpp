template<class Mint>
int general_maximum_matching(int n, vc<pii> e) {
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> unif(0, Mint::get_mod());

  matrix<Mint> M(n, n);
  for(auto [u, v] : e) {
    if (u > v) swap(u, v);
    if (u == v) continue;
    mint w = unif(rng);
    M[u][v] = w, M[v][u] = -w;
  }

  return M.rank() / 2;
}
