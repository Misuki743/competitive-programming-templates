#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series_sparse"

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
  fps f(n);
  for(int i = 0; i < k; i++) {
    int j, val; cin >> j >> val;
    f[j] = val;
  }

  auto g = sparseSqrt(f, n);
  if (g.empty())
    cout << -1 << '\n';
  else
    cout << g << '\n';


  return 0;
}
