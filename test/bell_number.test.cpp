#define PROBLEM "https://judge.yosupo.jp/problem/bell_number"

#include "../default/t.cpp"
#include "modint/Montgomery_modint.cpp"
#include "poly/NTT.cpp"
#include "poly/FPS.cpp"
#include "combi/binomial.cpp"
#include "combi/bell_number.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  cout << bell_number<mint>(n + 1) << '\n';

  return 0;
}

