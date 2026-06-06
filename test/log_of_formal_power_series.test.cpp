#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../poly/NTT.cpp"
#include "../poly/FPS.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  fps f(n);
  for(mint &x : f)
    cin >> x;

  cout << f.log(n) << '\n';

  return 0;
}
