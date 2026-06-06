#define PROBLEM "https://judge.yosupo.jp/problem/bernoulli_number"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../poly/NTT.cpp"
#include "../poly/FPS.cpp"
#include "../combi/bernoulli_number.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  cout << bernoulli_number<mint>(n) << '\n';

  return 0;
}
