#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../poly/NTT.cpp"
#include "../poly/FPS.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vector<mint> xs(n), ys(n);
  for(mint &x : xs)
    cin >> x;
  for(mint &y : ys)
    cin >> y;

  cout << fps::interpolate(xs, ys) << '\n';

  return 0;
}
