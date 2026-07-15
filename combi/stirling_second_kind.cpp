//#include "modint/Montgomery_modint.cpp"
//#include "poly/NTTmint.cpp"
//#include "poly/FPS.cpp"
//#include "combi/binom.cpp"

template<class Mint>
FPS<Mint> stirling_second_kind(int n) {
  FPS<Mint> f(n + 1), g(n + 1);
  for(int i = 0; i <= n; i++) {
    f[i] = factorial_inv<Mint>(i) * (i % 2 == 1 ? -1 : 1);
    g[i] = factorial_inv<Mint>(i) * Mint(i).pow(n);
  }
  auto h = f * g;
  h.resize(n + 1);
  return h;
}
