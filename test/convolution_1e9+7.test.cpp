#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../poly/NTT.cpp"
#include "../poly/convolution_arbitrary_mod.cpp"

using Mint = MontgomeryModInt<1'000'000'007>;

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<Mint> a(n), b(m);
  for(Mint &x : a)
    cin >> x;
  for(Mint &x : b)
    cin >> x;

  cout << convolution_arbitrary_mod(a, b) << '\n';

  return 0;
}
