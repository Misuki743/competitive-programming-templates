#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_multiplicative_function"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../numtheory/Lucy_DP.cpp"

using Mint = Montgomery_modint<469'762'049>;

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    ll N, a, b; cin >> N >> a >> b;
    auto Fp = Lucy_DP<Mint>(N, [](ll x) { return Mint(x) * (x + 1) * ((Mint::get_mod() + 1) / 2) - 1; }, [](ll, ll, ll q) { return Mint(q); });
    auto Fp2 = Lucy_DP<Mint>(N, [](ll x) { return Mint(x) - 1; }, [](ll, ll, ll) { return Mint(1); });
    for(int i = 0; i < ssize(Fp); i++)
      Fp[i] = a * Fp2[i] + b * Fp[i];

    cout << 1 + inverse_Lucy_DP<Mint>(N, Fp, [&](ll p, ll e, ll) -> Mint { return Mint(a) * e + Mint(b) * p; }).back() << '\n';
  }

  return 0;
}
