#define PROBLEM "https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series_large"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../poly/NTT.cpp"
#include "../poly/FPS.cpp"
#include "../poly/power_projection.cpp"
#include "../poly/compositional_inverse.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  fps f(n);
  for(mint &x : f)
    cin >> x;
  cout << compositional_inverse(f, n) << '\n';

  return 0;
}
