#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include "../default/t.cpp"
#include "../modint/Montgomery_modint.cpp"
#include "../poly/NTT.cpp"
#include "../poly/FPS.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  fps c(n);
  vector<mint> p(m);
  for(mint &x : c)
    cin >> x;
  for(mint &x : p)
    cin >> x;

  cout << c.multieval(p) << '\n';

  return 0;
}
