#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include "../default/t.cpp"
#include "../modint/dynamic_modint.cpp"
#include "../combi/binomial.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int t, p; cin >> t >> p;
  mint::set_mod(p);
  while(t--) {
    int n, k; cin >> n >> k;
    cout << binomial<mint>(n, k) << '\n';
  }

  return 0;
}
