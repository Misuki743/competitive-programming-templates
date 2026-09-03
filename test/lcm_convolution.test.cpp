#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../numtheory/zeta.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vc<mint> a(n + 1), b(n + 1);
  for(mint &x : a | views::drop(1)) cin >> x;
  for(mint &x : b | views::drop(1)) cin >> x;
  cout << (lcm_convolution(a, b) | views::drop(1)) << '\n';

  return 0;
}

