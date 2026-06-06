#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../poly/NTT.cpp"
#include "../poly/FPS.cpp"
#include "../combi/binomial.cpp"
#include "../numtheory/sqrt_mod.cpp"
#include "../poly/sparse_polynomial_operations.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, k; cin >> n >> k;
  ll m; cin >> m;
  fps f(n);
  for(int i = 0; i < k; i++) {
    int j, val; cin >> j >> val;
    f[j] = val;
  }

  cout << sparsePow(f, m, n) << '\n';

  return 0;
}
