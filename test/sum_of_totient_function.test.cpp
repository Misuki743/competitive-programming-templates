#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../numtheory/linear_sieve.cpp"
#include "../numtheory/phi_array.cpp"
#include "../numtheory/prefix_sum_of_dirichlet_inverse.cpp"

auto F_small = phi_array<mint, 8'000'000>();

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  pSum(F_small);

  ll N; cin >> N;
  cout << prefix_sum_of_dirichlet_inverse<mint>(N, [](ll x) { return mint(x); }, [](ll x) { return x % 2 == 1 ? (x + 1) / 2 * mint(x) : x / 2 * mint(x + 1); }, F_small).back() << '\n';

  return 0;
}
