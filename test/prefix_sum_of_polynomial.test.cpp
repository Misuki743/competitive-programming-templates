#define PROBLEM "https://judge.yosupo.jp/problem/prefix_sum_of_polynomial"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../poly/NTT.cpp"
#include "../poly/FPS.cpp"
#include "../combi/binomial.cpp"
#include "../combi/bernoulli_number.cpp"
#include "../poly/Taylor_shift.cpp"
#include "../poly/prefix_polynomial.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vc<mint> F(n);
  for(mint &x : F) cin >> x;
  cout << prefix_polynomial(F) << '\n';

  return 0;
}
