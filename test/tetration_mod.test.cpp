#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"

#include "../default/t.cpp"
#include "../numtheory/factorize_pollard_rho.cpp"
#include "../numtheory/exgcd.cpp"
#include "../numtheory/tetration_mod.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    ll a, b, m; cin >> a >> b >> m;
    cout << tetration(a, b, m) << '\n';
  }

  return 0;
}
