#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../combi/binomial.cpp"
#include "../poly/NTT.cpp"
#include "../poly/FPS.cpp"
#include "../poly/Taylor_shift.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, c; cin >> n >> c;
  fps a(n);
  for(mint &x : a)
    cin >> x;
  cout << Taylor_shift(a, mint(c)) << '\n';

  return 0;
}
