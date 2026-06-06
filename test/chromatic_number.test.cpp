#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"

#include "../default/t.cpp"
#include "modint/dynamic_modint.cpp"
#include "numtheory/factorize_pollard_rho.cpp"
#include "combi/chromatic_number.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector g(n, vector<bool>(n, false));
  for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    g[u][v] = g[v][u] = true;
  }

  cout << chromatic_number<mint>(g) << '\n';

  return 0;
}

